#!/usr/bin/env python

import cgi;
import xml.dom.minidom;
import fcntl;
import shutil;
import os;

import functions;

xmlEncoding = 'UTF-8';

#Getting the HTML form input data.
form = cgi.FieldStorage()

#Opening the xml file and locking it to prevent access from other processes.
xmlData = open(functions.PATIENTS_FILE_NAME, 'r+');
fcntl.flock(xmlData, fcntl.LOCK_EX);

#Opening the file used for backup and locking it.
bckData = open(functions.PATIENTS_FILE_NAME + '~', 'w');
fcntl.flock(bckData, fcntl.LOCK_EX);

#Generating the backup.
shutil.copyfileobj(xmlData, bckData);
bckData.close(); #Realeasing the backup file (unlock).

#Parsing the XML file
xmlData.seek(0); #Going to the beginning of the file
dom = xml.dom.minidom.parse(xmlData);

#Retrieving the correct user and checking birthday.
allPatients = dom.getElementsByTagName("doc")[0];
totalPatients = dom.getElementsByTagName("paciente").length;
if (totalPatients >= int(form['pacienteNumero'].value)):
  birthDay = dom.getElementsByTagName("paciente")[int(form['pacienteNumero'].value) -1].getElementsByTagName("diaNasc")[0].childNodes[0].data;
  birthMonth = dom.getElementsByTagName("paciente")[int(form['pacienteNumero'].value) -1].getElementsByTagName("mesNasc")[0].childNodes[0].data;
  birthYear = dom.getElementsByTagName("paciente")[int(form['pacienteNumero'].value) -1].getElementsByTagName("anoNasc")[0].childNodes[0].data;
  if ((birthDay == form['diaNasc'].value) and (birthMonth == form['mesNasc'].value) and (birthYear == form['anoNasc'].value)):
    allPatients.removeChild(allPatients.getElementsByTagName("paciente")[int(form['pacienteNumero'].value) -1]);
else:
  birthDay = birthMonth = birthYear = 0;
  
#Comparacao por nome tambem. Dando erro em paciente com acento!
#name = dom.getElementsByTagName("paciente")[int(form['pacienteNumero'].value) -1].getElementsByTagName("nome")[0].childNodes[0].data;
#if name == form['paciente'].value:
#  allPatients.removeChild(allPatients.getElementsByTagName("paciente")[int(form['pacienteNumero'].value) -1]);

#Saving the new data to the XML file.
xmlData.seek(0); #Going to the beginning of the file.
xmlData.write(dom.toxml(encoding = xmlEncoding));
xmlData.truncate();
xmlData.close(); #Releasing the file (calls also unlock).

print "Content-type: text/html\n\n"     # HTML is following

htmlPage = """
<html>
<head>
  <meta http-equiv="refresh" content="5; URL=busca.cgi?uid=%s" charset="UTF-8" />
  <title>Projeto Neural TB</title>
  <style type="text/css">
  </style>
</head>
<body bgcolor='#DDDDDD'>
"""% form['uid'].value

if ((birthDay == form['diaNasc'].value) and (birthMonth == form['mesNasc'].value) and (birthYear == form['anoNasc'].value)):
  htmlPage += "<div align=\"center\"><p><h3>Paciente removido com sucesso!</h3></p><p>Por favor aguarde. Voc&ecirc; ser&aacute; redirecionado para a p&aacute;gina de busca.</p></div>";
else:
  htmlPage += "<div align=\"center\"><p><h3>Paciente n&atilde;o encontrado!</h3></p><p>Verifique se o mesmo j&aacute; n&atilde;o foi removido.</p><p> Por favor aguarde. Voc&ecirc; ser&aacute; redirecionado para a p&aacute;gina de busca.</p></div>";

htmlPage += """
</body>
</html>
"""
print htmlPage;

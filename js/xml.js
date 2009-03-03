//Funções para carregar o arquivo XML a seguir exibi-lo de acordo com o arquivo XSL correspondente
//Funções retiradas e adaptadas do site http://www.w3schools.com

/* Arquivo para o projeto NeuralTB -->
<!-- Universidade Federal do Rio de Janeiro
     Escola Politecnica
     Departamento de Engenharia Eletronica e de Computacao
	
     Laboratorio de Processamento de Sinais
	
     Atualizacao: Laura de Oliveira Fernandes Moraes
     Ultima atualizacao: 12/02/2009 */

function loadXMLDoc(fname)
{
var xmlDoc;
// code for IE
if (window.ActiveXObject)
  {
  xmlDoc=new ActiveXObject("Microsoft.XMLDOM");
  }
// code for Mozilla, Firefox, Opera, etc.
else if (document.implementation 
&& document.implementation.createDocument)
  {
  xmlDoc=document.implementation.createDocument("","",null);
  }
else
  {
  alert('Your browser cannot handle this script');
  }
xmlDoc.async=false;
xmlDoc.load(fname);
return(xmlDoc);
}

function displayResult(id,xmlName,xslName)
{
xml=loadXMLDoc(xmlName);
xsl=loadXMLDoc(xslName);
// code for IE
if (window.ActiveXObject)
  {
  ex=xml.transformNode(xsl);
  document.getElementById(id).innerHTML=ex;
  }
// code for Mozilla, Firefox, Opera, etc.
else if (document.implementation 
&& document.implementation.createDocument)
  {
  xsltProcessor=new XSLTProcessor();
  xsltProcessor.importStylesheet(xsl);
  resultDocument = xsltProcessor.transformToFragment(xml,document);
  document.getElementById(id).appendChild(resultDocument);
  }
}

	function showXSL(linha, fname)
	{
		var xmlDoc=null;
		if (window.ActiveXObject)
		{// code for IE
			xmlDoc=new ActiveXObject("Microsoft.XMLDOM");
		}
		else if (document.implementation.createDocument)
		{// code for Mozilla, Firefox, Opera, etc.
			xmlDoc=document.implementation.createDocument("","",null);
		}
		else
		{
			alert('Your browser cannot handle this script');
		}
		if (xmlDoc!=null)
		{
		xmlDoc.async=false;
		if (fname == 1)
			xmlDoc.load("xml/pacientes.xml");
		else
			xmlDoc.load("../xml/pacientes.xml");

		var x=xmlDoc.getElementsByTagName("paciente");
		var codigo, cidade;
		
		codigo="<p align='center'> <a target='blank' href='../cgi-bin/imprimir.cgi?pid=";
		codigo+=linha;
		//codigo+=x[linha-1].getElementsByTagName("nome")[0].childNodes[0].nodeValue;
		codigo+="'>Versão para Impressão</a></p>";

		codigo+="<table width='600' align='center' cellspacing='1' cellpadding='0'>"

		//Nome
		codigo+="<tr class='nome'><td width='100' align='left'>Nome:</td><td>"
		codigo+=x[linha-1].getElementsByTagName("nome")[0].childNodes[0].nodeValue;
		codigo+="</td></tr>";

		//Cidade de Estudo
		codigo+="<tr class='forms'><td colspan='2'><h4>Entrevista</h4></td></tr>";
		codigo+="<tr class='par'><td>Cidade de Estudo:</td><td>";
		codigo+=cidade=x[linha-1].getElementsByTagName("cidade")[0].childNodes[0].nodeValue;

		//Tipo de Unidade de Saude
		codigo+="</td></tr><tr class='impar'><td>Tipo de Unidade de Saúde:</td><td>";
		if (cidade == "Curitiba/Paraná")
		codigo+=x[linha-1].getElementsByTagName("unidadeCurit")[0].childNodes[0].nodeValue;
		else
		codigo+=x[linha-1].getElementsByTagName("unidade")[0].childNodes[0].nodeValue;

		//Tipo de Participante
		codigo+="</td></tr><tr class='par'><td>Tipo de Participante:</td><td>";
		if (cidade == "Curitiba/Paraná")
		codigo+=x[linha-1].getElementsByTagName("tipoCurit")[0].childNodes[0].nodeValue;
		else
		codigo+=x[linha-1].getElementsByTagName("tipo")[0].childNodes[0].nodeValue;

		//Entrevistador
		codigo+="</td></tr><tr class='impar'><td>Entrevistador:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("entrevistador")[0].childNodes[0].nodeValue;

		//Categoria Profissional
		codigo+="</td></tr><tr class='par'><td>Categoria Profissional:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("categProf")[0].childNodes[0].nodeValue;

		//Data da Entrevista
		codigo+="</td></tr><tr class='impar'><td>Data da Entrevista:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("diaEntr")[0].childNodes[0].nodeValue + "/" + x[linha-1].getElementsByTagName("mesEntr")[0].childNodes[0].nodeValue + "/" + x[linha-1].getElementsByTagName("anoEntr")[0].childNodes[0].nodeValue;

		//Local da Entrevista
		codigo+="</td></tr><tr class='par'><td>Local da Entrevista:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("local")[0].childNodes[0].nodeValue;

		//Supervisor
		codigo+="</td></tr><tr class='impar'><td>Supervisor:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("supervisor")[0].childNodes[0].nodeValue;

		//Data
		codigo+="</td></tr><tr class='par'><td>Data da Entrevista:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("dia")[0].childNodes[0].nodeValue + "/" + x[linha-1].getElementsByTagName("mes")[0].childNodes[0].nodeValue + "/" + x[linha-1].getElementsByTagName("ano")[0].childNodes[0].nodeValue;

		//Horario do inicio da entrevista
		codigo+="</td></tr><tr class='impar'><td>Horário do início da entrevista:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("horaInicio")[0].childNodes[0].nodeValue + ":" + x[linha-1].getElementsByTagName("minutoInicio")[0].childNodes[0].nodeValue;

		//Endereço
		codigo+="<tr class='forms'><td colspan='2'><h4>1. Caracterização Socioeconômica / Sócio-demográfica / Hábitos de Vida</h4></td></tr>";
		codigo+="<tr class='par'><td colspan='2'>Endereço:</td></tr>";

		//Logradouro
		codigo+="<tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Logradouro:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("logradouro")[0].childNodes[0].nodeValue;

		//Numero
		codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Número:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("numero")[0].childNodes[0].nodeValue;

		//Complemento
		codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Complemento:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("complemento")[0].childNodes[0].nodeValue;

		//Municipio, estado
		codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Município/Estado:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("municipio")[0].childNodes[0].nodeValue + ", " + x[linha-1].getElementsByTagName("est")[0].childNodes[0].nodeValue

		//Bairro
		codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Bairro:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("bairro")[0].childNodes[0].nodeValue;

		//CEP
		codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - CEP:</td><td>";
		//if ( (x[linha-1].getElementsByTagName("cepchk")[0].childNodes[0].nodeValue) && (x[linha-1].getElementsByTagName("cepchk")) )
		if ( x[linha-1].getElementsByTagName("cepchk").length )
			codigo+=x[linha-1].getElementsByTagName("cepchk")[0].childNodes[0].nodeValue;
		else
			codigo+=x[linha-1].getElementsByTagName("cep")[0].childNodes[0].nodeValue;
		

		//Telefone
		codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Telefone:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("proprietarioTel")[0].childNodes[0].nodeValue;
			

		//Telefone para contato
		if( codigo+=x[linha-1].getElementsByTagName("proprietarioTel")[0].childNodes[0].nodeValue != "Não possui" )
		{
			codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Telefone para contato:</td><td>";
		//	codigo+="(" + x[linha-1].getElementsByTagName("ddd")[0].childNodes[0].nodeValue + ")" + x[linha-1].getElementsByTagName("telefone")[0].childNodes[0].nodeValue;
		codigo+="(21)" + "tel";
		}
		
		//Nome do contato
		if (x[linha-1].getElementsByTagName("proprietarioTel")[0].childNodes[0].nodeValue == "Contato")
		{
		codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Nome do contato:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("nomeContato")[0].childNodes[0].nodeValue;
		codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Vínculo com o contato:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("vinculoContato")[0].childNodes[0].nodeValue;
		}
		
		//Número do CAT-SUS
		if (cidade != "Curitiba/Paraná")
		{
		codigo+="</td></tr><tr class='impar'><td>Número do CAT-SUS:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("numfns")[0].childNodes[0].nodeValue;
		}
		
		//Data de nascimento
		codigo+="</td></tr><tr class='par'><td>Data de Nascimento:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("diaNasc")[0].childNodes[0].nodeValue + "/" + x[linha-1].getElementsByTagName("mesNasc")[0].childNodes[0].nodeValue + "/" + x[linha-1].getElementsByTagName("anoNasc")[0].childNodes[0].nodeValue;
		
		//Gênero
		codigo+="</td></tr><tr class='impar'><td>Gênero:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("sexo")[0].childNodes[0].nodeValue;
		
		//Cor da pele
		codigo+="</td></tr><tr class='par'><td>Cor da pele:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("cor")[0].childNodes[0].nodeValue;
		
		//Situação conjugal
		codigo+="</td></tr><tr class='impar'><td>Situação conjugal:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("estciv")[0].childNodes[0].nodeValue;
		
		//Naturalidade
		codigo+="</td></tr><tr class='par'><td>Naturalidade:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("natmun")[0].childNodes[0].nodeValue + ", " + x[linha-1].getElementsByTagName("natest")[0].childNodes[0].nodeValue
		
		//Morou em outro município
		codigo+="</td></tr><tr class='impar'><td>Morou em outro município:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("morout")[0].childNodes[0].nodeValue;
		if (x[linha-1].getElementsByTagName("morout")[0].childNodes[0].nodeValue == "Sim")
		{
		codigo+="</td></tr><tr class='impar'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Qual:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("moroutmun")[0].childNodes[0].nodeValue + ", " + x[linha-1].getElementsByTagName("moroutest")[0].childNodes[0].nodeValue
		}
		
		//Situação Ocupacional
		codigo+="</td></tr><tr class='par'><td>Situação Ocupacional:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("funcao")[0].childNodes[0].nodeValue;
		
		//Profissional de Saúde
		codigo+="</td></tr><tr class='impar'><td>Profissional de Saúde:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("profsaude")[0].childNodes[0].nodeValue;
		
		//Grau de instrução do chefe de família
		codigo+="</td></tr><tr class='par'><td>Grau de instrução do chefe de família:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("instrucao")[0].childNodes[0].nodeValue;
		
		//Empregada mensalista
		codigo+="</td></tr><tr class='impar'><td>Empregada mensalista:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("empregada")[0].childNodes[0].nodeValue;
		
		//Itens em casa
		codigo+="</td></tr><tr class='par'><td>Itens em casa:</td><td>";
		codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Automóvel:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("auto")[0].childNodes[0].nodeValue;
		codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Banheiro:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("banhei")[0].childNodes[0].nodeValue;
		codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Freezer:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("freezer")[0].childNodes[0].nodeValue;
		codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Geladeira:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("gel")[0].childNodes[0].nodeValue;
		codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Máqu. de lavar roupa:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("mlav")[0].childNodes[0].nodeValue;
		codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Rádio:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("rad")[0].childNodes[0].nodeValue;
		codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - TV em cores:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("tv")[0].childNodes[0].nodeValue;
		codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Videocassete/DVD:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("video")[0].childNodes[0].nodeValue;

		//Morador de rua nos últimos dois anos
		codigo+="</td></tr><tr class='impar'><td>Morador de rua nos últimos dois anos:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("morrua")[0].childNodes[0].nodeValue;
		
		//Morador de asilo nos últimos dois anos
		codigo+="</td></tr><tr class='par'><td>Morador de asilo nos últimos dois anos:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("morasil")[0].childNodes[0].nodeValue;
		
		//Ex-detento nos últimos dois anos
		codigo+="</td></tr><tr class='impar'><td>Ex-detento nos últimos dois anos:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("presid")[0].childNodes[0].nodeValue;
		
		//Internado nos últimos dois anos
		codigo+="</td></tr><tr class='par'><td>Internado nos últimos dois anos:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("intern")[0].childNodes[0].nodeValue;
		
		//Unidade de saúde que procura
		codigo+="</td></tr><tr class='impar'><td>Unidade de saúde que procura:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("qunis")[0].childNodes[0].nodeValue;
		
		//Conhece o agente de saúde do bairro
		codigo+="</td></tr><tr class='par'><td>Conhece o agente de saúde do bairro:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("agens")[0].childNodes[0].nodeValue;
		
		//Em relação ao hábito de fumar
		codigo+="</td></tr><tr class='impar'><td>Em relação ao hábito de fumar:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("fumo")[0].childNodes[0].nodeValue;
		if ((x[linha-1].getElementsByTagName("fumo")[0].childNodes[0].nodeValue == "Fumante atual") || (x[linha-1].getElementsByTagName("fumo")[0].childNodes[0].nodeValue == "Ex-fumante"))
		{
		codigo+="</td></tr><tr class='impar'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Número de cigarros que fuma/fumava por dia:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("numcigdia")[0].childNodes[0].nodeValue;
		codigo+="</td></tr><tr class='impar'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Número de anos que fumou:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("numanosfumo")[0].childNodes[0].nodeValue;
		codigo+="</td></tr><tr class='impar'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Carga tabágica:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("cargtab")[0].childNodes[0].nodeValue + " (maços-cigarro/ano)";
		}
		if (x[linha-1].getElementsByTagName("fumo")[0].childNodes[0].nodeValue == "Ex-fumante")
		{
		codigo+="</td></tr><tr class='impar'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Parou de fumar há quanto tempo? </td><td>";
		codigo+=x[linha-1].getElementsByTagName("semparoufum")[0].childNodes[0].nodeValue + " semana(s)<br>";
		codigo+=x[linha-1].getElementsByTagName("mesparoufum")[0].childNodes[0].nodeValue + " mes(es)<br>";
		codigo+=x[linha-1].getElementsByTagName("anoparoufum")[0].childNodes[0].nodeValue + " ano(s)";
		}
		
		//Uso de drogas alguma vez na vida
		codigo+="</td></tr><tr class='par'><td>Uso de drogas alguma vez na vida:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("drogas")[0].childNodes[0].nodeValue;
		
		//Tipo de bebida alcoólica preferida
		codigo+="</td></tr><tr class='impar'><td>Tipo de bebida alcoólica preferida:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("alcool")[0].childNodes[0].nodeValue;
		if (x[linha-1].getElementsByTagName("amizade").length)
		{
			codigo+="</td></tr><tr class='impar'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Você tem facilidade de fazer amizades?</td><td>";
			codigo+=x[linha-1].getElementsByTagName("amizade")[0].childNodes[0].nodeValue;
		}
		if (x[linha-1].getElementsByTagName("diminuirQuantidade").length)
		{
			codigo+="</td></tr><tr class='impar'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Alguma vez sentiu que deveria diminuir a quantidade da bebida?</td><td>";
			codigo+=x[linha-1].getElementsByTagName("diminuirQuantidade")[0].childNodes[0].nodeValue;
		}
		if (x[linha-1].getElementsByTagName("critica").length)
		{
			codigo+="</td></tr><tr class='impar'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Alguém critica ou já criticou o seu modo de beber?</td><td>";
			codigo+=x[linha-1].getElementsByTagName("critica")[0].childNodes[0].nodeValue;
		}
		if (x[linha-1].getElementsByTagName("diminuirNervosismo").length)
		{
			codigo+="</td></tr><tr class='impar'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Você costuma beber de manhã para diminuir o nervosismo/ressaca?</td><td>";
			codigo+=x[linha-1].getElementsByTagName("diminuirNervosismo")[0].childNodes[0].nodeValue;
		}
		if (x[linha-1].getElementsByTagName("culpado").length)
		{
			codigo+="</td></tr><tr class='impar'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Você se sente culpado pela maneira que costuma beber?</td><td>";
			codigo+=x[linha-1].getElementsByTagName("culpado")[0].childNodes[0].nodeValue;
		}
		
		//Observações
		if (x[linha-1].getElementsByTagName("obs1")[0].childNodes[0])
		{
			codigo+="</td></tr><tr class='par'><td>Observações:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("obs1")[0].childNodes[0].nodeValue;
			codigo+=x[linha-1].getElementsByTagName("obs1")[0].childNodes[0].lenght;
		}
		
		//Morou/mora com alguém com tuberculose
		codigo+="<tr class='forms'><td colspan='2'><h4>2. Avaliação Inicial/Clínica do Contato/Sintomático Respiratório/Suspeito</h4></td></tr>";
		codigo+="</td></tr><tr class='par'><td>Já morou antes (mora) com alguém com tuberculose no pulmão, familiar ou não nos últimos dois anos?</td><td>";
		codigo+=x[linha-1].getElementsByTagName("morou")[0].childNodes[0].nodeValue;
		if (x[linha-1].getElementsByTagName("morou")[0].childNodes[0].nodeValue == "Sim")
		{
			codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Desde que o paciente passou a tossir,  qual a média de horas de contato por dia?</td><td>";
			codigo+=x[linha-1].getElementsByTagName("trabhor1")[0].childNodes[0].nodeValue;
			codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; -  	Há quanto tempo o caso índice tosse/tossia?</td><td>";
			codigo+=x[linha-1].getElementsByTagName("semanastosse1")[0].childNodes[0].nodeValue + " semanas <br>";	
			codigo+=x[linha-1].getElementsByTagName("mesestosse1")[0].childNodes[0].nodeValue + " meses";	
		}
		
		//Teve/tem alguém na família com tuberculose
		codigo+="</td></tr><tr class='impar'><td>Teve (tem) alguém da família com tuberculose no pulmão nos últimos dois anos? (não residente no mesmo domicílio)</td><td>";
		codigo+=x[linha-1].getElementsByTagName("familia")[0].childNodes[0].nodeValue;
		if (x[linha-1].getElementsByTagName("familia")[0].childNodes[0].nodeValue == "Sim")
		{
			codigo+="</td></tr><tr class='impar'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Desde que o paciente passou a tossir,  qual a média de horas de contato por dia?</td><td>";
			codigo+=x[linha-1].getElementsByTagName("trabhor2")[0].childNodes[0].nodeValue;
			codigo+="</td></tr><tr class='impar'><td>&nbsp;&nbsp;&nbsp;&nbsp; -  	Há quanto tempo o caso índice tosse/tossia?</td><td>";
			codigo+=x[linha-1].getElementsByTagName("semanastosse2")[0].childNodes[0].nodeValue + " semanas <br>";	
			codigo+=x[linha-1].getElementsByTagName("mesestosse2")[0].childNodes[0].nodeValue + " meses";	
		}
		
		//Teve/tem alguém do círculo de amizade/trabalho com tuberculose
		codigo+="</td></tr><tr class='par'><td>Teve (tem) alguém do círculo de amizade/trabalho com tuberculose no pulmão (não residente no mesmo domicílio)</td><td>";
		codigo+=x[linha-1].getElementsByTagName("circulo")[0].childNodes[0].nodeValue;
		if (x[linha-1].getElementsByTagName("circulo")[0].childNodes[0].nodeValue == "Sim")
		{
			codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Desde que o paciente passou a tossir,  qual a média de horas de contato por dia?</td><td>";
			codigo+=x[linha-1].getElementsByTagName("trabhor3")[0].childNodes[0].nodeValue;
			codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; -  	Há quanto tempo o caso índice tosse/tossia?</td><td>";
			codigo+=x[linha-1].getElementsByTagName("semanastosse3")[0].childNodes[0].nodeValue + " semanas <br>";	
			codigo+=x[linha-1].getElementsByTagName("mesestosse3")[0].childNodes[0].nodeValue + " meses";	
		}
		
		//Tomou remédios
		codigo+="</td></tr><tr class='impar'><td>Já tomou alguma vez estes remédios por mais de um mês?</td><td>";
		codigo+=x[linha-1].getElementsByTagName("remedios")[0].childNodes[0].nodeValue;
		if (x[linha-1].getElementsByTagName("rem").length)
		{
			codigo+="</td></tr><tr class='impar'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Quais?</td><td>";
			codigo+=x[linha-1].getElementsByTagName("rem")[0].childNodes[0].nodeValue;
		}
		if (x[linha-1].getElementsByTagName("rem").length == 2)
			codigo+="<br>" + x[linha-1].getElementsByTagName("rem")[1].childNodes[0].nodeValue;
			
		//Tuberculose no passado
		codigo+="</td></tr><tr class='par'><td>Teve tuberculose anteriormente:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("tbprev")[0].childNodes[0].nodeValue;
		if (x[linha-1].getElementsByTagName("tbprev")[0].childNodes[0].nodeValue == "Sim")
		{
			codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - H&aacute; quantos anos?</td><td>";
			codigo+=x[linha-1].getElementsByTagName("dttbpast")[0].childNodes[0].nodeValue;
			codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Qual foi o resultado(desfecho) do tratamento anti-TB?</td><td>";
			codigo+=x[linha-1].getElementsByTagName("tbdesf")[0].childNodes[0].nodeValue;
		}

		//Resultado do tratamento notificado no SINAN
		if (x[linha-1].getElementsByTagName("ressinan")[0])
		{
			codigo+="</td></tr><tr class='impar'><td>Resultado do tratamento notificado no SINAN:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("ressinan")[0].childNodes[0].nodeValue;
		}

		//Cicatriz vacinal BCG
		codigo+="</td></tr><tr class='par'><td>Cicatriz vacinal BCG:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("cicbcg")[0].childNodes[0].nodeValue;

		//Falta de ar crônica ou enfisema
		codigo+="</td></tr><tr class='impar'><td>Falta de ar crônica ou enfisema:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("falta")[0].childNodes[0].nodeValue;

		//Asma ou bronquite
		codigo+="</td></tr><tr class='par'><td>Asma ou bronquite:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("asma")[0].childNodes[0].nodeValue;

		//Outros problemas de saúde
		codigo+="</td></tr><tr class='impar'><td>Outros problemas de saúde:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("psaude")[0].childNodes[0].nodeValue;
		if (x[linha-1].getElementsByTagName("psaude")[0].childNodes[0].nodeValue == "Sim")
		{
			codigo+="</td></tr><tr class='impar'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Qual?</td><td>";
			codigo+=x[linha-1].getElementsByTagName("outrosSaude")[0].childNodes[0].nodeValue;
		}

		//Presença de sintomas no momento
		if (cidade != "Curitiba/Paraná")
		{
		codigo+="</td></tr><tr class='par'><td>Presença de sintomas no momento:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("sint")[0].childNodes[0].nodeValue;
		}
		if (((cidade != "Curitiba/Paraná") && (x[linha-1].getElementsByTagName("sint")[0].childNodes[0].nodeValue == "Sim")) || (cidade == "Curitiba/Paraná"))
		{	
			//Tosse
			codigo+="</td></tr><tr class='par'><td>Tosse:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("tosse")[0].childNodes[0].nodeValue;
			if (x[linha-1].getElementsByTagName("tosse")[0].childNodes[0].nodeValue == "Sim")
			{
				codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Há quantos dias?</td><td>";
				codigo+=x[linha-1].getElementsByTagName("qntsem")[0].childNodes[0].nodeValue + " dias";
				codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Já havia procurado antes avaliação médica por esta tosse?</td><td>";
				codigo+=x[linha-1].getElementsByTagName("tosseAntes")[0].childNodes[0].nodeValue;
				if (x[linha-1].getElementsByTagName("tosseAntes")[0].childNodes[0].nodeValue == "Sim")
				{
					codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Há quanto tempo?</td><td>";
					codigo+=x[linha-1].getElementsByTagName("qntTosseAntes")[0].childNodes[0].nodeValue + " dias";
				}
			}
			
			//Catarro e expectoração
			codigo+="</td></tr><tr class='impar'><td>Catarro e expectoração:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("catarr")[0].childNodes[0].nodeValue;
			if (x[linha-1].getElementsByTagName("catarr")[0].childNodes[0].nodeValue == "Sim")
			{
				codigo+="</td></tr><tr class='impar'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Há quantos dias?</td><td>";
				codigo+=x[linha-1].getElementsByTagName("qntsem")[0].childNodes[0].nodeValue;
			}
			
			//Sangue no catarro/Hemoptise
			codigo+="</td></tr><tr class='par'><td>Sangue no catarro/Hemoptise:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("hempti")[0].childNodes[0].nodeValue;
			
			//Suores à noite
			codigo+="</td></tr><tr class='impar'><td>Suores à noite:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("sudore")[0].childNodes[0].nodeValue;
			
			//Dor Torácica/dor no peito
			codigo+="</td></tr><tr class='par'><td>Dor Torácica/dor no peito:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("hempto")[0].childNodes[0].nodeValue;
			
			//Febre
			codigo+="</td></tr><tr class='impar'><td>Febre:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("febre")[0].childNodes[0].nodeValue;
			
			//Falta de apetite
			codigo+="</td></tr><tr class='par'><td>Falta de apetite:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("hipore")[0].childNodes[0].nodeValue;
			
			//Emagrecimento
			codigo+="</td></tr><tr class='impar'><td>Emagrecimento:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("emagre")[0].childNodes[0].nodeValue;
			
			//Peso anterior
			codigo+="</td></tr><tr class='par'><td>Peso anterior:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("peso1")[0].childNodes[0].nodeValue + " kg";
			
			//Peso atual
			codigo+="</td></tr><tr class='par'><td>Peso atual:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("pesokg2")[0].childNodes[0].nodeValue + " kg";
			
			//Cansaço
			codigo+="</td></tr><tr class='impar'><td>Cansaço:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("asteni")[0].childNodes[0].nodeValue;
			
			//Rouquidão
			codigo+="</td></tr><tr class='par'><td>Rouquidão:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("rouqui")[0].childNodes[0].nodeValue;
			
			//Ínguas
			codigo+="</td></tr><tr class='impar'><td>Ínguas:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("linfon")[0].childNodes[0].nodeValue;
			
			//Falta de ar (Dispnéia)
			codigo+="</td></tr><tr class='par'><td>Falta de ar (Dispnéia):</td><td>";
			codigo+=x[linha-1].getElementsByTagName("dispn")[0].childNodes[0].nodeValue;
			
			//Chiado no peito
			codigo+="</td></tr><tr class='impar'><td>Chiado no peito:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("chiado")[0].childNodes[0].nodeValue;	
		}
		
		//Outros sintomas
		codigo+="</td></tr><tr class='par'><td>Outros sintomas:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("ot")[0].childNodes[0].nodeValue;
		if (x[linha-1].getElementsByTagName("ot")[0].childNodes[0].nodeValue == "Sim")
		{
			codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Quais?</td><td>";
			codigo+=x[linha-1].getElementsByTagName("outros")[0].childNodes[0].nodeValue;
		}
		
		//Observações
		if (x[linha-1].getElementsByTagName("obs2")[0].childNodes.length)
		{
			codigo+="</td></tr><tr class='impar'><td>Observações:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("obs2")[0].childNodes[0].nodeValue;
		}
		
		//Horário de encerramento da entrevista
		codigo+="</td></tr><tr class='impar'><td>Horário de encerramento da entrevista:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("horaenc")[0].childNodes[0].nodeValue + ":" + x[linha-1].getElementsByTagName("minenc")[0].childNodes[0].nodeValue;
		
		//Probabilidade de tuberculose pulmonar ativa apenas com os dados desta entrevista (sintomas)
		codigo+="</td></tr><tr class='par'><td>Probabilidade de tuberculose pulmonar ativa apenas com os dados desta entrevista (sintomas):</td><td>";
		codigo+=x[linha-1].getElementsByTagName("probclin")[0].childNodes[0].nodeValue;
		
		//Condições da entrevista
		codigo+="</td></tr><tr class='impar'><td>Condições da entrevista:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("condicao")[0].childNodes[0].nodeValue;
		
		//Colaboração do entrevistado
		codigo+="</td></tr><tr class='par'><td>Colaboração do entrevistado:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("colaboracao")[0].childNodes[0].nodeValue;
		
		//Credibilidade das respostas
		codigo+="</td></tr><tr class='impar'><td>Credibilidade das respostas:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("credibilidade")[0].childNodes[0].nodeValue;
		
		//Sinais ao exame físico
		codigo+="<tr class='forms'><td colspan='2'><h4>3. Avaliação Complementar do Contato/Sintomático Respiratório/Suspeito - quando indicado</h4></td></tr>";
		if (cidade != "Curitiba/Paraná")
		{
			codigo+="</td></tr><tr class='par'><td>Sinais ao exame físico:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("sinaisExames")[0].childNodes[0].nodeValue;
			
			// Probabilidade de tuberculose pulmonar ativa com a avaliação de sinais de história + exame físico médico- PARA EQUIPE MÉDICA
			codigo+="</td></tr><tr class='impar'><td>Probabilidade de tuberculose pulmonar ativa com a avaliação de sinais de história + exame físico médico- PARA EQUIPE MÉDICA:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("probem")[0].childNodes[0].nodeValue;
		}
		
		//Telerradiografia de tórax (PA e perfil) - Laudo
		codigo+="</td></tr><tr class='par'><td>Telerradiografia de tórax (PA e perfil) - Laudo:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("rxtor")[0].childNodes[0].nodeValue;
		
		//Identificação da área acometida
		if ((x[linha-1].getElementsByTagName("rxtor")[0].childNodes[0].nodeValue != "Não Realizada")&&((x[linha-1].getElementsByTagName("rxtor")[0].childNodes[0].nodeValue != "Em andamento")))
		{
			codigo+="</td></tr><tr class='impar'><td>Identificação da área acometida:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("area")[0].childNodes[0].nodeValue;
			codigo+="</td></tr><tr class='impar'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Data do exame:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("diaExame")[0].childNodes[0].nodeValue + "/" + x[linha-1].getElementsByTagName("mesExame")[0].childNodes[0].nodeValue + "/" + x[linha-1].getElementsByTagName("anoExame")[0].childNodes[0].nodeValue;
		}
		
		//Em caso de alta ou média probabilidade de TB ativa pela clínica
		if (cidade != "Curitiba/Paraná")
		{
			codigo+="</td></tr><tr class='par'><td>Em caso de alta ou média probabilidade de TB ativa pela clínica:</td><td>";
			if (x[linha-1].getElementsByTagName("rxtam").length)
				codigo+=x[linha-1].getElementsByTagName("rxtam")[0].childNodes[0].nodeValue;
			else if (x[linha-1].getElementsByTagName("rxtam1").length)
				codigo+=x[linha-1].getElementsByTagName("rxtam1")[0].childNodes[0].nodeValue;
		
			//Em caso de baixa probabilidade de TB ativa pela clínica
			codigo+="</td></tr><tr class='impar'><td>Em caso de baixa probabilidade de TB ativa pela clínica:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("rxbaix")[0].childNodes[0].nodeValue;
			
			//Probabilidade pelo médico de tuberculose pulmonar ativa com a avaliação complementar da teleradiografia de tórax
			codigo+="</td></tr><tr class='par'><td>Probabilidade pelo médico de tuberculose pulmonar ativa com a avaliação complementar da teleradiografia de tórax:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("probrx")[0].childNodes[0].nodeValue;
		}
		
		//Resultado da PT
		codigo+="</td></tr><tr class='impar'><td>Resultado da PT:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("ppdmed")[0].childNodes[0].nodeValue;
		if (x[linha-1].getElementsByTagName("ppdmed")[0].childNodes[0].nodeValue != "NR")
		{
			codigo+=" mm de enduração" + "</td></tr><tr class='impar'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Data da leitura:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("diaLeit")[0].childNodes[0].nodeValue + "/" + x[linha-1].getElementsByTagName("mesLeit")[0].childNodes[0].nodeValue + "/" + x[linha-1].getElementsByTagName("anoLeit")[0].childNodes[0].nodeValue;
			codigo+="</td></tr><tr class='impar'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Leitor:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("leitor")[0].childNodes[0].nodeValue;
		}
		
		//Amostra de trato respiratório inferior (1ª amostra)
		codigo+="</td></tr><tr class='par'><td>Amostra de trato respiratório inferior (1ª amostra):</td><td>";
		codigo+=x[linha-1].getElementsByTagName("amostri1")[0].childNodes[0].nodeValue;
		
		//Baciloscopia (1ª amostra)
		codigo+="</td></tr><tr class='impar'><td>Baciloscopia (1ª amostra):</td><td>";
		codigo+=x[linha-1].getElementsByTagName("znescar1")[0].childNodes[0].nodeValue;
		if ((cidade == "Curitiba/Paraná") && ((x[linha-1].getElementsByTagName("znescar1")[0].childNodes[0].nodeValue != "Ignorado/Não Realizado") && (x[linha-1].getElementsByTagName("znescar1")[0].childNodes[0].nodeValue != "Em andamento")) && (x[linha-1].getElementsByTagName("znescar1")))
		{
			codigo+=" mm de enduração" + "</td></tr><tr class='impar'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Data da leitura:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("horaColeta1")[0].childNodes[0].nodeValue + ":" + x[linha-1].getElementsByTagName("minutoColeta1")[0].childNodes[0].nodeValue;
		}
		if (x[linha-1].getElementsByTagName("znescar1")[0].childNodes[0].nodeValue == "Positivo")
		{
			codigo+="</td></tr><tr class='impar'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Intensidade:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("znesint1")[0].childNodes[0].nodeValue;
		}
		
		//Amostra de trato respiratório inferior (2ª amostra)
		codigo+="</td></tr><tr class='par'><td>Amostra de trato respiratório inferior (2ª amostra):</td><td>";
		codigo+=x[linha-1].getElementsByTagName("amostri2")[0].childNodes[0].nodeValue;
		
		//Baciloscopia (2ª amostra)
		codigo+="</td></tr><tr class='impar'><td>Baciloscopia (2ª amostra):</td><td>";
		codigo+=x[linha-1].getElementsByTagName("znescar2")[0].childNodes[0].nodeValue;
		if ((cidade == "Curitiba/Paraná") && (x[linha-1].getElementsByTagName("znescar2")[0].childNodes[0].nodeValue != "Não realizado/Ignorado") && (x[linha-1].getElementsByTagName("znescar2")[0].childNodes[0].nodeValue != "Em andamento"))
		{
			codigo+=" mm de enduração" + "</td></tr><tr class='impar'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Data da leitura:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("horaColeta2")[0].childNodes[0].nodeValue + ":" + x[linha-1].getElementsByTagName("minutoColeta2")[0].childNodes[0].nodeValue;
		}
		if (x[linha-1].getElementsByTagName("znescar2")[0].childNodes[0].nodeValue == "Positivo")
		{
			codigo+="</td></tr><tr class='impar'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Intensidade:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("znesint2")[0].childNodes[0].nodeValue;
		}
		
		//Probabilidade de tuberculose pulmonar ativa com a avaliação complementar do RX e de baciloscopia
		codigo+="</td></tr><tr class='par'><td>Probabilidade de tuberculose pulmonar ativa com a avaliação complementar do RX e de baciloscopia:</td><td>";
		codigo+=x[linha-1].getElementsByTagName("prrxzn")[0].childNodes[0].nodeValue;
		
		//Cultura para micobactérias (1)
		codigo+="</td></tr><tr class='impar'><td>Cultura para micobactérias (1):</td><td>";
		codigo+=x[linha-1].getElementsByTagName("cultbk1")[0].childNodes[0].nodeValue;
		if (x[linha-1].getElementsByTagName("cultbk1")[0].childNodes[0].nodeValue != "Não realizada")
		{
			codigo+="</td></tr><tr class='impar'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Método:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("metodo1")[0].childNodes[0].nodeValue;
		}
		if (x[linha-1].getElementsByTagName("cultbk1")[0].childNodes[0].nodeValue == "Positiva")
		{
			codigo+="</td></tr><tr class='impar'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Tipificação:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("culttip1")[0].childNodes[0].nodeValue;
		}
		
		//Outro exame (1)
		codigo+="</td></tr><tr class='par'><td>Outro exame (1):</td><td>";
		codigo+=x[linha-1].getElementsByTagName("outtbk1")[0].childNodes[0].nodeValue;
		if (x[linha-1].getElementsByTagName("outtbk1")[0].childNodes[0].nodeValue != "Não realizado")
		{
			codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Exame:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("exame1")[0].childNodes[0].nodeValue;
		}
		
		//Outro exame (2)
		codigo+="</td></tr><tr class='impar'><td>Outro exame (2):</td><td>";
		codigo+=x[linha-1].getElementsByTagName("outtbk2")[0].childNodes[0].nodeValue;
		if (x[linha-1].getElementsByTagName("outtbk2")[0].childNodes[0].nodeValue != "Não realizado")
		{
			codigo+="</td></tr><tr class='impar'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Exame:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("exame2")[0].childNodes[0].nodeValue;
		}
		
		//Outro exame (3)
		codigo+="</td></tr><tr class='par'><td>Outro exame (3):</td><td>";
		codigo+=x[linha-1].getElementsByTagName("outtbk3")[0].childNodes[0].nodeValue;
		if (x[linha-1].getElementsByTagName("outtbk3")[0].childNodes[0].nodeValue != "Não realizado")
		{
			codigo+="</td></tr><tr class='par'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Exame:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("exame3")[0].childNodes[0].nodeValue;
		}
		
		//Outro exame (4)
		codigo+="</td></tr><tr class='impar'><td>Outro exame (4):</td><td>";
		codigo+=x[linha-1].getElementsByTagName("outtbk4")[0].childNodes[0].nodeValue;
		if (x[linha-1].getElementsByTagName("outtbk4")[0].childNodes[0].nodeValue != "Não realizado")
		{
			codigo+="</td></tr><tr class='impar'><td>&nbsp;&nbsp;&nbsp;&nbsp; - Exame:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("exame4")[0].childNodes[0].nodeValue;
		}
	
		// Acompanhamento
		codigo+="<tr class='forms'><td colspan='2'><h4>4. Acompanhamento</h4></td></tr>";
		
		//Desfecho do caso
		if (x[linha-1].getElementsByTagName("desfecho")[0])
		{
			codigo+="</td></tr><tr class='impar'><td>Desfecho do caso:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("desfecho")[0].childNodes[0].nodeValue;
		}
		//Desfecho do caso diagnosticado como tuberculose
		if (x[linha-1].getElementsByTagName("dtub")[0])
		{
			codigo+="</td></tr><tr class='par'><td>Desfecho do caso diagnosticado como tuberculose:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("dtub")[0].childNodes[0].nodeValue;
		}
		
		//Desfecho do caso diagnosticado como NÃO tuberculose
		if( x[linha-1].getElementsByTagName("dntub")[0] )
		{
			codigo+="</td></tr><tr class='impar'><td>Desfecho do caso diagnosticado como NÃO tuberculose:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("dntub")[0].childNodes[0].nodeValue;
		}
		
		//Se apresentou diagnóstico posterior de tuberculose, onde?
		if (x[linha-1].getElementsByTagName("aprtbp")[0])
		{
			codigo+="</td></tr><tr class='par'><td>Se apresentou diagnóstico posterior de tuberculose, onde?</td><td>";
			codigo+=x[linha-1].getElementsByTagName("aprtbp")[0].childNodes[0].nodeValue;
		}
		
		//Data da última consulta/VD
		if (x[linha-1].getElementsByTagName("diaUCons")[0].childNodes.length)
		{
			codigo+="</td></tr><tr class='impar'><td>Data da última consulta/VD:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("diaUCons")[0].childNodes[0].nodeValue + "/" + x[linha-1].getElementsByTagName("mesUCons")[0].childNodes[0].nodeValue + "/" + x[linha-1].getElementsByTagName("anoUCons")[0].childNodes[0].nodeValue;
		}
		
		//Observações
		if (x[linha-1].getElementsByTagName("obs3")[0].childNodes.length)
		{
			codigo+="</td></tr><tr class='par'><td>Observações:</td><td>";
			codigo+=x[linha-1].getElementsByTagName("obs3")[0].childNodes[0].nodeValue;
		}
		
		codigo+="</td></tr>";
		
		
		codigo+="</table>"
		codigo+="<p><br><br><br></p>"
		
		document.getElementById("xml").innerHTML = codigo;
		document.getElementById("xml1").focus();
		}
	}
	
	function mostraCidade(cidade1, cidade2, cidade3, username)
	{
		var xmlDoc=null;
		if (window.ActiveXObject)
		{// code for IE
			xmlDoc=new ActiveXObject("Microsoft.XMLDOM");
		}
		else if (document.implementation.createDocument)
		{// code for Mozilla, Firefox, Opera, etc.
			xmlDoc=document.implementation.createDocument("","",null);
		}
		else
		{
			alert('Your browser cannot handle this script');
		}
		if (xmlDoc!=null)
		{
		document.getElementById("xml").innerHTML = "";
		xmlDoc.async=false;
		xmlDoc.load("../xml/pacientes.xml");
		var fname = 0;

		var x=xmlDoc.getElementsByTagName("paciente");
		var codigo;
		
		codigo="<table width='600' align='center' cellspacing='1' cellpadding='0'>"
		codigo+="<tr class='nome' align='center'>";
		codigo+="<td><h4>N&uacute;mero</h4></td>";
		codigo+="<td><h4>Nome</h4></td>";
		codigo+="<td><h4>Data de nascimento</h4></td>";
		codigo+="<td><h4>Data da entrevista</h4></td>";
		codigo+="<td><h4>Remover</h4></td>";
		codigo+="<td><h4>Editar</h4></td></tr>";
		linha = 0;
		for (i=0;i<x.length;i++)
		{ 
			contaLinhas();
			if ((x[i].getElementsByTagName("cidade")[0].childNodes[0].nodeValue == "Curitiba/Paraná" && (cidade1.checked)) || (x[i].getElementsByTagName("cidade")[0].childNodes[0].nodeValue == "Fortaleza/Ceará" && (cidade2.checked)) || (x[i].getElementsByTagName("cidade")[0].childNodes[0].nodeValue == "Itaboraí/RJ" && (cidade3.checked)))
			{
				if (!(i % 2))
					codigo+= "<tr class='par'>";
				else
					codigo+="<tr class='impar'>";
				//codigo+="<tr class='nome'";
				//codigo+="<td></td>";
				codigo+="<td width='50' align='center'>" +  linha + ".</td>";
				codigo+="<td class='link' onClick='showXSL(" + linha + "," + fname + ")'>";
				codigo+=x[i].getElementsByTagName("nome")[0].childNodes[0].nodeValue;
				codigo+="</td>";
				codigo+="<td class='link' align='center' onClick='showXSL(" + linha + "," + fname + ")'>";
				codigo+= x[i].getElementsByTagName("diaNasc")[0].childNodes[0].nodeValue + "/" + x[i].getElementsByTagName("mesNasc")[0].childNodes[0].nodeValue + "/" + x[i].getElementsByTagName("anoNasc")[0].childNodes[0].nodeValue;
				codigo+="</td>";
				codigo+="<td class='link' align='center' onClick='showXSL(" + linha + "," + fname + ")'>";
				codigo+= x[i].getElementsByTagName("diaEntr")[0].childNodes[0].nodeValue + "/" + x[i].getElementsByTagName("mesEntr")[0].childNodes[0].nodeValue + "/" + x[i].getElementsByTagName("anoEntr")[0].childNodes[0].nodeValue;
				codigo+="</td>";
				codigo+="<td class='link'  align='center'>"
				codigo+="<a href=\"remover.cgi?paciente=" + linha + "&uid=" + username + "\">Remover";
				codigo+="</a></td>";
				codigo+="<td class='link'  align='center'>"
				codigo+="<a href=\"editar.cgi?paciente=" + linha + "&uid=" + username + "\">Editar";
				codigo+="</a></td>";
				codigo+="</tr>";
			}	
		}
		
		codigo+="</table>"
		codigo+="<p><br><br><br></p>"
		
		document.getElementById("lugar").innerHTML = codigo;
	}

	}

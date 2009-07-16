/*
	Universidade Federal do Rio de Janeiro
	Escola Politecnica
	Departamento de Engenharia Eletronica e de Computacao
	
	Laboratorio de Processamento de Sinais
	Projeto Decit
	Autor: Renato Sampaio
	Arquivo Original: Luiz Evora
	Atualização: Laura Moraes
	Ultima atualizacao: 12/02/2009 

	$Author$
	$Date$
	$Log$
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "functions.h"
#include "cgi.h"
/*
#include "ntbConfig.h"
#include "Const.h"
#include "Types.h"
#include "Error.h"
#include "Functions.h"
*/

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

int main (int argc, char **argv)
{
	char *username;
	
	//CGI process
	
	cgi_init();
	cgi_process_form();
	username = cgi_param("uid");
	
	cgi_init_headers();

	//HTML
printf("\r\n");
printf("<html>\n");
printf("<!-- Arquivo para o projeto NeuralTB -->\n");
printf("<!-- Universidade Federal do Rio de Janeiro\n");
printf("     Escola Politecnica\n");
printf("     Departamento de Engenharia Eletronica e de Computacao\n");
printf("	\n");
printf("     Laboratorio de Processamento de Sinais\n");
printf("	\n");
printf("     Autor: Luiz Evora\n");
printf("     Atualizacao: Laura de Oliveira Fernandes Moraes\n");
printf("     Ultima atualizacao: 29/07/2008 -->\n");
printf("\n");
printf("  <head>\n");
printf("\n");
printf("    <meta http-equiv=content-type content=\"text/html; charset=UTF-8\">\n");
printf("\n");
printf("    <title>.:. Neural TB .:. Busca de pacientes</title>\n");
printf("\n");
printf("    <link  rel=\"stylesheet\" type=\"text/css\" href=\"../css/standart.css\"/>\n");
printf("\n");
printf("    <script language=\"javascript\" src=\"../js/xml.js\"></script>\n");
printf("    <script language=\"javascript\" src=\"../js/busca.js\"></script>\n");
printf("\n");
printf("<script>\n");
printf("\n");
printf("	var linha=0;\n");
printf("\n");
printf("	function contaLinhas()\n");
printf("\n");
printf("	{\n");
printf("\n");
printf("		linha+=1;\n");
printf("\n");
printf("	}\n");
printf("\n");
printf("	</script>\n");
printf("\n");
printf("\n");
printf("\n");
printf("  </head>\n");
printf("\n");
printf("\n");
printf("\n");
printf("<!--  <body onLoad=\"displayResult('xml','../xml/pacientes.xml','../xml/nomes.xsl');\" class=\"style1\">-->\n");
printf("\n");
printf("<body class=\"style1\">\n");
printf("\n");
printf("     <table height=\"120\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\" id= \"d\">\n");
printf("\n");
printf("	<tr bgcolor=\"#CCCCCC\">\n");
printf("\n");
printf("	    <td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</td>\n");
printf("\n");
printf("	    <td><b><u><font size=\"5\">Menu</font></u></b></td>\n");
printf("\n");
printf("	    <td>&nbsp;</td>\n");
printf("\n");
printf("	</tr>\n");
printf("\n");
printf("	<tr bgcolor=\"#CCCCCC\">\n");
printf("\n");
printf("        <td>&nbsp;</td>\n");
printf("\n");
printf("        <td width=\"100%%\">\n");
printf("\n");
printf("	       <a href=\"formulario.cgi?uid=%s\">Adicionar Paciente</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n", username);
printf("\n");
printf("	       <a href=\"busca.cgi?uid=%s\"> Buscar/Editar/Remover</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n", username);
printf("\n");
printf("		   <a href=\"backup.cgi\"> Back-up</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf("\n");
printf("           &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf("\n");
printf("           &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf("\n");
printf("           &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf("\n");
printf("           &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf("\n");
printf("           <a href=\"principal.cgi?uid=%s\">Página principal</a>\n", username);
printf("\n");
printf("	    </td>\n");
printf("\n");
printf("         <td></td>\n");
printf("\n");
printf("	</tr>\n");
printf("\n");
printf("	<tr bgcolor=\"#CCCCCC\">\n");
printf("\n");
printf("                  <td>&nbsp;</td>\n");
printf("\n");
printf("                  <td>\n");
printf("\n");
printf("                     <a href=\"exibirPacientes.cgi?uid=%s\">Exibir questionários</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n", username);
printf("\n");
printf("          	         <a href=\"exibirRecusa.cgi?uid=%s\">Exibir recusas</a>\n", username);
printf("\n");
printf("                  </td>\n");
printf("\n");
printf("                   <td></td>\n");
printf("\n");
printf("    </tr>\n");
printf("\n");
printf("	</table>\n");
printf("\n");
printf("	<a id=\"xml1\" href=\"\"></a>\n");
printf("	\n");
printf("	<form action=\"searchPatient.cgi?uid=%s\"  method=\"post\" name=\"check\" id=\"searchForm\"  onSubmit=\"return validarBusca(this);\" />\n", username);
printf("<input type=\"HIDDEN\" name=\"uid\" value=\"%s\">\n",username);
printf("          <table width=\"70%%%%\" border=\"0\" cellpadding=\"1\" cellspacing=\"2\" bordercolor=\"#999999\" id=\"tabela\" align=center>\n");
printf("             <tr class=\"styleBusca1\">\n");
printf("                <td width=\"30%%%%\" title=\"Atributo através do qual será realizada a busca\">\n");
printf("                    <div class=\"styleBusca2\">&nbsp;Busca por</div>\n");
printf("                </td>\n");
printf("                <td width=\"20%%%%\" id=\"operador_0\">&nbsp;</td>\n");
printf("                <td id=\"VALORES_TITULO\" width=\"40%%%%\">\n");
printf("                    <div class=\"styleBusca2\">&nbsp;</div>\n");
printf("                </td>\n");
/*printf("                <td id=\"ORDENA_TITULO\" width=\"10%%%%\" title=\"Ordena os pacientes buscados de acordo com o atributo selecionado\">\n");
printf("                    <div class=\"styleBusca2\">&nbsp;Ordenar por</div>\n");
printf("                </td>\n");*/
printf("             </tr>\n");
printf("             <tr class=\"fundoTabela\">\n");
printf("                <td title=\"Atributo através do qual será realizada a busca\">\n");
printf("                    <div align=\"center\"><strong><font color=\"#003399\" size=\"2\" face=\"Arial, Helvetica, sans-serif\">\n");
printf("                    <!-- select da celula [1][0] -->\n");
printf("                    <select name=\"select\" onChange=\"_options(this);\" onKeyUp=\"_options(this.form);\">\n");
printf("                    <option value=\"1\" selected>&nbsp;Selecione</option>\n");
printf("                    <option value=\"2.nome\">Nome</option>\n"); //Opcao 2 para nomes
printf("                    <option value=\"3.diaNasc\">Data de nascimento</option>\n"); //Opcao 3 para datas
printf("                    <option value=\"4.cidade\">Cidade de estudo</option>\n"); //Opcao 4 para escolhas restritas (com opcoes)
printf("                    <option value=\"3.diaEntr\">Data da entrevista</option>\n"); //Opcao 3 para datas
printf("                    </select>\n");
printf("                    </font></strong></div>\n");
printf("                </td>\n");
printf("                <td id=\"operadores\">&nbsp;</td>\n");
printf("                <td id=\"valores\">&nbsp;</td>\n");
/*printf("		 		<td id=\"ordena\" title=\"Ordena os pacientes buscados de acordo com o atributo selecionado\">\n");
printf("                    <!-- select da celula [1][3] -->\n");
printf("                     <select name=\"selectOrdena\">\n");
printf("                    <option value=\"id\" selected>N&ordm; de identifica&ccedil;&atilde;o</option>\n");
printf("                    <option value=\"nome\">Nome</option>\n");
printf("					<option value=\"diaNasc\">Data de Nascimento</option>\n");
printf("					<option value=\"cidade\">Cidade de estudo</option>\n");
printf("                    </select>\n");
printf("                </td> \n");*/
printf("             </tr>\n");
printf("          </table>\n");
printf("<p align=center> <input type=\"submit\" name=\"Submit\" value=\"Pesquisar\"> </p>\n");
printf("</form>\n");
printf("\n");
printf("<div align=center><h3> Pacientes Inseridos</h3></div>\n");
printf("\n");
printf("<div id=\"xml\">\n");
printf("\n");
printf("</div>\n");
printf("\n");
printf("<table width=\"600\" align=\"center\" cellspacing=\"1\" cellpadding=\"0\" id=\"xml1\">\n");
printf("<tr class=\"nome\" align=\"center\">\n");
printf("<td><h4>N&uacute;mero</h4></td>");
printf("<td><h4>Nome</h4></td>");
printf("<td><h4>Data de nascimento</h4></td>");
printf("<td><h4>Data da entrevista</h4></td>");
printf("<td><h4>Remover</h4></td>");
printf("<td><h4>&nbsp;&nbsp;Editar&nbsp;&nbsp;</h4></td></tr>");
printf("\n");
printf("	<script>\n");
printf("\n");
printf("\n");
printf("\n");
printf("		var xmlDoc=null;\n");
printf("\n");
printf("		if (window.ActiveXObject)\n");
printf("\n");
printf("		{// code for IE\n");
printf("\n");
printf("			xmlDoc=new ActiveXObject(\"Microsoft.XMLDOM\");\n");
printf("\n");
printf("		}\n");
printf("\n");
printf("		else if (document.implementation.createDocument)\n");
printf("\n");
printf("		{// code for Mozilla, Firefox, Opera, etc.\n");
printf("\n");
printf("			xmlDoc=document.implementation.createDocument(\"\",\"\",null);\n");
/*printf("			document.write(\"<td></td>\");");
printf("			document.write(\"<td><h4>N&uacute;mero</h4></td>\");");
printf("			document.write(\"<td><h4>Nome</h4></td>\");");
printf("			document.write(\"<td><h4>Data de nascimento</h4></td>\");");
printf("			document.write(\"<td><h4>Remover</h4></td>\");");
printf("			document.write(\"<td><h4>&nbsp;&nbsp;Editar&nbsp;&nbsp;</h4></td>\");");*/
printf("\n");
printf("		}\n");
printf("\n");
printf("		else\n");
printf("\n");
printf("		{\n");
printf("\n");
printf("			alert('Your browser cannot handle this script');\n");
printf("\n");
printf("		}\n");
printf("\n");
printf("		if (xmlDoc!=null)\n");
printf("\n");
printf("		{\n");
printf("\n");
printf("		xmlDoc.async=false;\n");
printf("\n");
printf("		xmlDoc.load(\"../xml/pacientes.xml\");\n");
printf("		var fname = 0;\n");
printf("\n");
printf("\n");
printf("\n");
printf("		var x=xmlDoc.getElementsByTagName(\"paciente\");\n");
//printf("document.write('</tr>');");
printf("\n");
printf("		for (i=0;i<x.length;i++)\n");
printf("\n");
printf("		{ \n");
printf("\n");
printf("		contaLinhas();\n");
printf("\n");
printf("if (!(i %% 2))\n");
printf("		document.write(\"<tr class='par'>\");\n");
printf("		else\n");
printf("		document.write(\"<tr class='impar'>\");\n");
printf("\n");
//printf("		document.write(\"<td></td>\");\n");
printf("\n");
printf("		document.write(\"<td width='50' align='center'>\" +  linha + \".</td>\");\n");
printf("\n");
printf("		document.write(\"<td class='link' onClick='showXSL(\" + x[i].getElementsByTagName(\"id\")[0].childNodes[0].nodeValue + \",\" + fname + \")'>\");\n");
printf("\n");
printf("		document.write(x[i].getElementsByTagName(\"nome\")[0].childNodes[0].nodeValue);\n");
printf("\n");
printf("		document.write(\"</td>\");\n");
printf("		document.write(\"<td class='link' align='center' onClick='showXSL(\" + x[i].getElementsByTagName(\"id\")[0].childNodes[0].nodeValue + \",\" + fname + \")'>\");\n");
printf("\n");
printf("		document.write(x[i].getElementsByTagName(\"diaNasc\")[0].childNodes[0].nodeValue + \"/\" + x[i].getElementsByTagName(\"mesNasc\")[0].childNodes[0].nodeValue + \"/\" + x[i].getElementsByTagName(\"anoNasc\")[0].childNodes[0].nodeValue);\n");
printf("\n");
printf("		document.write(\"</td>\");\n");
printf("\n");
printf("		document.write(\"<td class='link' align='center' onClick='showXSL(\" + x[i].getElementsByTagName(\"id\")[0].childNodes[0].nodeValue + \",\" + fname + \")'>\");\n");
printf("\n");
printf("		document.write(x[i].getElementsByTagName(\"diaEntr\")[0].childNodes[0].nodeValue + \"/\" + x[i].getElementsByTagName(\"mesEntr\")[0].childNodes[0].nodeValue + \"/\" + x[i].getElementsByTagName(\"anoEntr\")[0].childNodes[0].nodeValue);\n");
printf("\n");
printf("		document.write(\"</td>\");\n");
printf("\n");
printf("		document.write(\"<td class='link'  align='center'>\");\n");
		
//printf("		var endereco = \"remover.cgi?paciente=\" + (i+1) + \"&uid=%s>\"\n",username);
printf("		var endereco = \"remover.cgi?paciente=\" + x[i].getElementsByTagName(\"id\")[0].childNodes[0].nodeValue + \"&uid=%s>\"\n",username);
		
printf("		document.write(\"<a href=\" + endereco + \"Remover\" + \"</a>\");\n");
printf("		document.write(\"</td>\");\n");	

printf("		document.write(\"<td class='link'  align='center'>\");\n");
		
//printf("		endereco = \"editar.cgi?paciente=\" + (i+1) + \"&uid=%s>\"\n",username);
printf("		endereco = \"editar.cgi?paciente=\" + x[i].getElementsByTagName(\"id\")[0].childNodes[0].nodeValue + \"&uid=%s>\"\n",username);
		
printf("		document.write(\"<a href=\" + endereco + \"Editar\" + \"</a>\");\n");
printf("		document.write(\"</td>\");\n");
printf("\n");
printf("\n");
printf("		document.write(\"</tr>\");\n");
printf("\n");
printf("		}\n");
printf("\n");
printf("		//document.write(\"</table>\");\n");
printf("\n");
printf("		}\n");
printf("\n");
printf("\n");
printf("\n");
printf("	</script>\n");
printf("\n");
printf("</table>\n");
printf("\n");
printf("	</body>\n");
printf("\n");
printf("</html>\n");
printf("\n");
printf("\n");



	
	cgi_end();
	
	return 0;
}

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/* $RCSfile$ */

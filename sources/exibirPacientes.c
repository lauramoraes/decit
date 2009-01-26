/*
	Universidade Federal do Rio de Janeiro
	Escola Politecnica
	Departamento de Engenharia Eletronica e de Computacao
	
	Laboratorio de Processamento de Sinais
	Projeto Decit
	Autor: Renato Sampaio

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
printf ("<html>\n");
printf ("<!-- Arquivo para o projeto NeuralTB -->\n");
printf ("<!-- Universidade Federal do Rio de Janeiro\n");
printf ("     Escola Politecnica\n");
printf ("     Departamento de Engenharia Eletronica e de Computacao\n");
printf ("	\n");
printf ("     Laboratorio de Processamento de Sinais\n");
printf ("	\n");
printf ("     Autor: Luiz Evora\n");
printf ("     Atualizacao: Laura de Oliveira Fernandes Moraes\n");
printf ("     Ultima atualizacao: 21/10/2008 -->\n");
printf ("  <head>\n");
printf ("    <meta http-equiv=content-type content=\"text/html; charset=UTF-8\">\n");
printf ("    <title>.:. Neural TB .:. Pacientes que aceitaram</title>\n");
printf ("    <link  rel=\"stylesheet\" type=\"text/css\" href=\"../css/standart.css\"/>\n");
printf ("    <script language=\"javascript\" src=\"../js/xml.js\"></script>\n");
printf ("<script>\n");
printf ("	var linha=0;\n");
printf ("	function contaLinhas()\n");
printf ("	{\n");
printf ("		linha+=1;\n");
printf ("	}\n");
printf ("	</script>\n");
printf ("\n");
printf ("  </head>\n");
printf ("\n");
printf ("<!--  <body onLoad=\"displayResult('../xml','../xml/pacientes.xml','../xml/nomes.xsl');\" class=\"style1\">-->\n");
printf ("<body class=\"style1\" onLoad=\"mostraCidade(document.getElementById('PR'),document.getElementById('CE'), document.getElementById('RJ'))\">\n");
printf ("     <table height=\"120\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\" id= \"d\">\n");
printf ("	<tr bgcolor=\"#CCCCCC\">\n");
printf ("	    <td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</td>\n");
printf ("	    <td><b><u><font size=\"5\">Menu</font></u></b></td>\n");
printf ("	    <td>&nbsp;</td>\n");
printf ("	</tr>\n");
printf ("	<tr bgcolor=\"#CCCCCC\">\n");
printf ("        <td>&nbsp;</td>\n");
printf ("        <td width=\"100%%\">\n");
printf ("	       <a href=\"formulario.cgi?uid=%s\">Adicionar Paciente</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n", username);
printf ("	        <a href=\"busca.cgi?uid=%s\">  Buscar/Editar/Remover</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n", username);
printf ("		<a href=\"cgi-bin/backup.cgi\"> Back-up</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf ("           &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf ("           &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf ("           &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf ("           &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf ("           <a href=\"principal.cgi?uid=%s\">Página principal</a>\n", username);
printf ("	    </td>\n");
printf ("         <td></td>\n");
printf ("	</tr>\n");
printf ("	<tr bgcolor=\"#CCCCCC\">\n");
printf ("                  <td>&nbsp;</td>\n");
printf ("                  <td>\n");
printf ("                     <a href=\"exibirPacientes.cgi?uid=%s\">Exibir questionários</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n", username);
printf ("          	         <a href=\"exibirRecusa.cgi?uid=%s\">Exibir recusas</a>\n", username);
printf ("                  </td>\n");
printf ("                   <td></td>\n");
printf ("    </tr>\n");
printf ("	</table>\n");
printf ("	<a id=\"xml1\" href=\"\"></a>\n");
printf ("<div align=center><h3> Pacientes Inseridos</h3></div>\n");
printf ("<div align=\"center\">Escolha a cidade:\n");
printf ("<form>\n");
printf ("	<input type=\"checkbox\" value=\"Curitiba/Paraná\" id=\"PR\" onClick=\"if (!this.checked) {todos.checked = false}; mostraCidade(PR, CE, RJ);\" checked/>Curitiba/Paran&aacute;&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf ("	<input type=\"checkbox\" value=\"Fortaleza/Ceará\" id=\"CE\" onClick=\"if (!this.checked) {todos.checked = false}; mostraCidade(PR, CE, RJ);\" checked/>Fortaleza/Cear&aacute;&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf ("	<input type=\"checkbox\" value=\"Itaboraí/RJ\" id=\"RJ\" onClick=\"if (!this.checked) {todos.checked = false}; mostraCidade(PR, CE, RJ);\" checked/>Itabora&iacute;/RJ&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf ("	<input type=\"checkbox\" value=\"todos\" id=\"todos\" onClick=\"if (this.checked) {PR.checked= true; CE.checked = true; RJ.checked= true;} else {PR.checked= false; CE.checked = false; RJ.checked= false;}; mostraCidade(PR, CE, RJ);\" checked/>Todas\n");
printf ("</form>\n");
printf ("</div>\n");
printf ("<div id=\"xml\">\n");
printf ("</div>\n");
printf ("<div id=\"lugar\">\n");
printf ("</div>\n");
printf ("</body>\n");
printf ("</html>");


	
	cgi_end();
	
	return 0;
}

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/* $RCSfile$ */

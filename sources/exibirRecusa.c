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
printf ("\n");
printf ("  <head>\n");
printf ("\n");
printf ("    <meta http-equiv=content-type content=\"text/html; charset=UTF-8\">\n");
printf ("\n");
printf ("    <title>.:. Neural TB .:. Pacientes que recusaram</title>\n");
printf ("\n");
printf ("    <script src=\"../js/xml.js\"></script>\n");
printf ("\n");
printf ("    <link  rel=\"stylesheet\" type=\"text/css\" href=\"../css/standart.css\"/>\n");
printf ("\n");
printf ("  </head> \n");
printf ("\n");
printf ("	\n");
printf ("\n");
printf ("	<body onLoad=\"displayResult('showXML','../xml/recusa.xml','../xml/recusa.xsl');\" class=\"style1\">\n");
printf ("\n");
printf ("		   <table height=\"120\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">\n");
printf ("\n");
printf ("	<tr bgcolor=\"#CCCCCC\">\n");
printf ("\n");
printf ("	    <td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</td>\n");
printf ("\n");
printf ("	    <td><b><u><font size=\"5\">Menu</font></u></b></td>\n");
printf ("\n");
printf ("	    <td>&nbsp;</td>\n");
printf ("\n");
printf ("	</tr>\n");
printf ("\n");
printf ("	<tr bgcolor=\"#CCCCCC\">\n");
printf ("\n");
printf ("        <td>&nbsp;</td>\n");
printf ("\n");
printf ("        <td width=\"100%%\">\n");
printf ("\n");
printf ("	       <a href=\"formulario.cgi?uid=%s\">Adicionar Paciente</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n", username);
printf ("\n");
printf ("	       <a href=\"busca.cgi?uid=%s\"> Buscar/Editar/Remover</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n", username);
printf ("		<a href=\"backup.cgi\"> Back-up</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf ("\n");
printf ("           &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf ("\n");
printf ("           &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf ("\n");
printf ("           &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf ("\n");
printf ("           &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf ("\n");
printf ("           <a href=\"principal.cgi?uid=%s\">Página principal</a>\n", username);
printf ("\n");
printf ("	    </td>\n");
printf ("\n");
printf ("         <td></td>\n");
printf ("\n");
printf ("	</tr>\n");
printf ("\n");
printf ("	<tr bgcolor=\"#CCCCCC\">\n");
printf ("\n");
printf ("                  <td>&nbsp;</td>\n");
printf ("\n");
printf ("                  <td>\n");
printf ("\n");
printf ("                     <a href=\"exibirPacientes.cgi?uid=%s\">Exibir questionários</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n", username);
printf ("\n");
printf ("          	         <a href=\"exibirRecusa.cgi?uid=%s\">Exibir recusas</a>\n", username);
printf ("\n");
printf ("                  </td>\n");
printf ("\n");
printf ("                   <td></td>\n");
printf ("\n");
printf ("    </tr>\n");
printf ("\n");
printf ("	</table>\n");
printf ("\n");
printf ("<div align=center><h3> Pacientes que Recusaram</h3></div>\n");
printf ("\n");
printf ("<div id=\"showXML\"></div>\n");
printf ("\n");
printf ("	\n");
printf ("\n");
printf ("	</body>\n");
printf ("\n");
printf ("</html>\n");
printf ("\n");
printf ("\n");
printf ("\n");

	
	cgi_end();
	
	return 0;
}

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/* $RCSfile$ */

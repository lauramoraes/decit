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
printf ("<HTML>\n");
printf ("<HEAD>\n");
printf ("	<meta http-equiv=content-type content=\"text/html; charset=UTF-8\">\n");
printf ("	<TITLE>.:. Projeto Neural TB .:.</TITLE>\n");
printf ("	<link  rel=\"stylesheet\" type=\"text/css\" href=\"css/standart.css\"/>\n");
printf ("</HEAD>\n");
printf ("<BODY class=\"style1\">\n");
printf ("	<table height=\"120\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">\n");
printf ("		<tr bgcolor=\"#CCCCCC\">\n");
printf ("			<td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</td>\n");
printf ("			<td><b><u><font size=\"5\">Menu</font></u></b></td>\n");
printf ("			<td>&nbsp;</td>\n");
printf ("		</tr>\n");
printf ("		<tr bgcolor=\"#CCCCCC\">\n");
printf ("			<td>&nbsp;</td>\n");
printf ("			<td width=\"100%%\">\n");
printf ("				<a href=\"formulario.cgi?uid=%s\">Adicionar Paciente</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n", username);
printf ("				<a href=\"busca.cgi?uid=%s\">  Buscar/Editar/Remover</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n", username);
printf ("				<a href=\"backup.cgi\">  Back-up</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf ("					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf ("					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf ("					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf ("					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf ("				<a href=\"principal.cgi?uid=%s\">Página principal</a>\n", username);
printf ("			</td>\n");
printf ("			<td></td>\n");
printf ("		</tr>\n");
printf ("		<tr bgcolor=\"#CCCCCC\">\n");
printf ("			<td>&nbsp;</td>\n");
printf ("			<td>\n");
printf ("				<a href=\"exibirPacientes.cgi?uid=%s\">Exibir questionários</a>\n", username);
printf ("					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
printf ("				<a href=\"exibirRecusa.cgi?uid=%s\">Exibir recusas</a>\n", username);
printf ("			</td>\n");
printf ("			<td></td>\n");
printf ("		</tr>\n");
printf ("	</table>\n");
printf ("	<p>&nbsp;</p><p>&nbsp;</p>\n");
printf ("	<div align=\"center\">\n");
printf ("		<table cellpadding=3 border=1 cellspacing=0.1>\n");
printf ("			<tr>\n");
printf ("				<td><img src=\"../imagens/cnpq.jpg\"></td>\n");
printf ("				<td class=\"style3\">CNPq - Conselho Nacional de Desenvolvimento Científico<br>\n");
printf ("									 Projeto CNPq Decit - Edital Doenças Negligenciadas - Área Diagnóstica<br>\n");
printf ("									 Centros de Estudo: Itaboraí, Fortaleza, Curitiba\n");
printf ("				</td>\n");
printf ("			</tr>\n");
printf ("		</table>\n");
printf ("	</div>\n");
printf ("	<br>\n");
printf ("	<div align=\"center\" class=\"style2\">\n");
printf ("				TUBERCULOSE INFECÇÃO E DOENÇA ENTRE SINTOMÁTICOS RESPIRATÓRIOS,<br>\n");
printf ("				CONTATOS INTRA-DOMICILIARES E VALIDAÇÃO / CUSTO-EFETIVIDADE DE<br>\n");
printf ("				DIFERENTES TÉCNICAS DIAGNÓSTICAS EM DIFERENTES CENÁRIOS CLÍNICO-<br>\n");
printf ("				EPIDEMIOLÓGICOS\n");
printf ("	</div>\n");
printf ("</BODY>\n");
printf ("</HTML>\n");

	
	cgi_end();
	
	return 0;
}

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/* $RCSfile$ */

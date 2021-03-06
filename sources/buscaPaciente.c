/******************************************************************************
 * Autor: Rony Tadeu Vernet Braga                                             *
 * Projeto: Neural TB                                                         *
 * Description: CGI to find patients in the XML file through XSLT and XPATH   *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "tiposModif.h"
#include "consts.h"
#include "patientFunctionsModif.h"


int main (void)
{
	unsigned x,y, opt;
	double contentLength;
	char *orderValue;
	char* temp1;
	char* temp2;
	char originalString[10240];
	char processedString[10240];
	char hexa[3];
	FILE* paciente_xsl;
	const char *length;
	chainType *form, *aux, *first;
	char tabFields[27][3][100];
	FILE *xml_sessao;
	char temp[1024];
	char status[10];
	char login[16];


	strcpy(tabFields[0][0], "nome");
	strcpy(tabFields[0][1], "Nome");
	strcpy(tabFields[1][0], "idade");
	strcpy(tabFields[1][1], "Idade");
	strcpy(tabFields[2][0], "sexo");
	strcpy(tabFields[2][1], "Sexo");
	strcpy(tabFields[3][0], "tosse");
	strcpy(tabFields[3][1], "Tosse");
	strcpy(tabFields[4][0], "hemoptoico");
	strcpy(tabFields[4][1], "Hemoptóico");
	strcpy(tabFields[5][0], "sudorese");
	strcpy(tabFields[5][1], "Sudorese Noturna");
	strcpy(tabFields[6][0], "febre");
	strcpy(tabFields[6][1], "Febre");
	strcpy(tabFields[7][0], "emagrecimento");
	strcpy(tabFields[7][1], "Emagrecimento");
	strcpy(tabFields[8][0], "dispneia");
	strcpy(tabFields[8][1], "Dispnéia");
	strcpy(tabFields[9][0], "anorexia");
	strcpy(tabFields[9][1], "Anorexia");
	strcpy(tabFields[10][0], "fuma_atualmente");
	strcpy(tabFields[10][1], "Fuma Atualmente");
	strcpy(tabFields[11][0], "tb_extrapulmonar");
	strcpy(tabFields[11][1], "TB extrapulmonar");
	strcpy(tabFields[12][0], "internacao_hospitalar");
	strcpy(tabFields[12][1], "Internação hospitalar");
	strcpy(tabFields[13][0], "sida");
	strcpy(tabFields[13][1], "SIDA");
	strcpy(tabFields[14][0], "resultado");
	strcpy(tabFields[14][1], "Resultado");
	strcpy(tabFields[15][0], "grupo_de_risco");
	strcpy(tabFields[15][1], "Grupo de Risco");
	strcpy(tabFields[16][0], "visto_de_analise");
	strcpy(tabFields[16][1], "Visto de Análise");

/******************************************************************************
 *                      READ CONTENT StrING FROM SERVER                       *
 ******************************************************************************/

	if(!(length= getenv("CONTENT_LENGTH")))
	{

		printf("Content-type: text/html\n\n");
		printf("<html>\n");
		printf("<head>\n");
		printf("<title>Resultado</title>\n");
		printf("</head>\n");
		printf("<body>\n");
		printf("erro ao repassar os argumentos");
		printf("</body>\n");
		return(OK);
	}

	contentLength=strtol(length, NULL, 10);
	fread(originalString, contentLength, 1, stdin);

/******************************************************************************
 *                    CONVERT CONTENT StrING StrANGE CHARS                    *
 ******************************************************************************/


	for (x = 0, y = 0; x < strlen(originalString); x++, y++)
	{
		switch (originalString[x])
		{
			/* Convert all + chars to space chars */
			case '+':
				processedString[y] = ' ';
				break;

			/* Convert all %xy hex codes into ASCII chars */
			case '%':
				/* Copy the two bytes following the % */
				strncpy(hexa, &originalString[x + 1], 2);
				/* Skip over the hex */
				x = x + 2;
				/* Convert the hex to ASCII */
				/* Prevent user from altering URL delimiter sequence */
				if( ((strcmp(hexa,"26")==0)) || ((strcmp(hexa,"3D")==0)) )
				{
					processedString[y]='%';
					y++;
					strcpy(processedString,hexa);
					y+=2;
					break;
				}
				processedString[y] = (char)strtol(hexa, NULL, 16);
				break;

			/* Make an exact copy of anything else */
			default:
				processedString[y] = originalString[x];
				break;
		}
	}

/******************************************************************************
 *  EXtrACT AtrIBUTES AND VALUES FROM CONVERTED StrING AND PUT'EM IN A CHAIN  *
 ******************************************************************************/

	temp1 = (char*)&processedString;
	aux=NULL;
	for (temp2=strsep(&temp1,"&"); temp2!=NULL; temp2=strsep(&temp1,"&"))
	{
		form = (chainType*)malloc(sizeof(chainType));
		form->attribute=strsep(&temp2,"=");
		form->value=strsep(&temp2,"\0");

		if (aux == NULL)
			first = form;
		else
			aux->next = form;

		aux = form;
	}

/******************************************************************************
 *                              HTML RETURN CODE                              *
 ******************************************************************************/


	printf("Content-type: text/html\r\n\r\n");
	printf("<html>\r\n");
	printf("<head>\r\n");
	printf("<title>.:. Pesquisa de pacientes .:. Projeto Neural TB .:.</title>\r\n");
	printf("<link rel=\"stylesheet\" href=\"../sistema/css/busca.css\" type=\"text/css\">\r\n");
	printf("<link rel=\"stylesheet\" href=\"../sistema/css/menu.css\"   type=\"text/css\">\r\n");
	printf("</head>\r\n");
	printf("<body leftmargin=\"0\" topmargin=\"0\" marginwidth=\"0\" marginheight=\"0\">\r\n");
	printf("<table width=\"3020px\" height=\"80\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">");
	printf("<tr bgcolor=\"#DDDDDD\">");
	printf("<td>&nbsp;</td>");
	printf("<td ><b><u>Menu</u></b></td>");
	printf("<td>&nbsp;</td>");
	printf("</tr>");
	printf("<tr bgcolor=\"#DDDDDD\">");
	printf("<td width=\"5%%\">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<img src=\"../sistema/figuras/neuraltb.gif\" width=\"300\" height=\"65\"></td>");
	printf("<td width=\"5%%\" valign=\"top\">");
	printf("<ul>");
	xml_sessao = fopen("../sistema/xml/sessao.xml", "r");
	fgets(temp, 1024, xml_sessao);
	fgets(temp, 1024, xml_sessao);
	fgets(temp, 1024, xml_sessao);
	fgets(temp, 1024, xml_sessao);
	getXmlTextNode(temp, login);
	fgets(temp, 1024, xml_sessao);
	getXmlTextNode(temp, status);
	if (!strcmp(status, "admin"))
		printf("<li><font color=\"#CCCCCC\" size=\"2\"><a href=\"../sistema/formAdicionaUsuario.html\">Adicionar Usuário</a></font></li>\r\n");
	printf("<li><font color=\"#CCCCCC\" size=\"2\"><a href=\"../sistema/formAdicionaPaciente.html\">Adicionar Paciente</a></font></li>");
	printf("<li><font color=\"#CCCCCC\" size=\"2\"><a href=\"../sistema/formGerenciador.html\">Buscar/Editar/Remover</a></font></li>");
	printf("</ul>");
	printf("<td width=\"90%%\" valign=\"bottom\">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font size=\"2\"><b>Seja bem-vindo!</b> [<a href=\"logout.cgi\">logout</a>]</font></td>");
	printf("</td>");
	printf("</tr>");
	printf("</table>");
	printf("<p></p>\r\n");
	opt=strtoul(first->value,NULL,10);
	paciente_xsl= fopen("../sistema/xml/buscaPaciente.xsl", "w");
		fprintf(paciente_xsl,"<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>\r\n");
		fprintf(paciente_xsl,"<xsl:stylesheet version=\"1.0\" xmlns:xsl=\"http://www.w3.org/1999/XSL/Transform\">\r\n");
		/***** Se o campo de busca for nome essas variaveis serao usadas *****/
		if(opt == 2)
		{
				fprintf(paciente_xsl,"<xsl:param name=\"upperCase\" select=\"'ABCDEFGHIJKLMNOPQRSTUVWXYZ'\"/>\r\n");
				fprintf(paciente_xsl,"<xsl:param name=\"lowerCase\" select=\"'abcdefghijklmnopqrstuvwxyz'\"/>\r\n");
				fprintf(paciente_xsl,"<xsl:param name=\"searchTextToTranslate\" select=\"'%s'\"/>\r\n", first->next->next->value);
				fprintf(paciente_xsl,"<xsl:variable name=\"translatedSearchText\" select=\"translate($searchTextToTranslate, $upperCase, $lowerCase)\"/>\r\n");
		}
		/*********************************************************************/
		fprintf(paciente_xsl,"<xsl:template match=\"/\">\r\n");

		/***** Bloco responsavel pela verificacao de valores encontrados para a busca *****/
		switch(opt)
		{
			case 1: //Atributo Todos
				fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente)\" />\r\n");
			break;
			case 2: //Atributo nome
				switch(strtoul(first->next->value,NULL, 10)) //valor do campo de operador
				{
					case 1: //nome contendo
						fprintf(paciente_xsl,"<xsl:variable name=\"contador\">\r\n");
						fprintf(paciente_xsl,"0\r\n");
						fprintf(paciente_xsl,"<xsl:for-each select=\"doc/paciente\">\r\n");
						fprintf(paciente_xsl,"<xsl:if test=\"contains(translate(nome, $upperCase, $lowerCase), $translatedSearchText)\">\r\n");
						fprintf(paciente_xsl,"<xsl:number count=\"paciente\" />\r\n");
						fprintf(paciente_xsl,"</xsl:if>\r\n");
						fprintf(paciente_xsl,"</xsl:for-each>\r\n");
						fprintf(paciente_xsl,"</xsl:variable>\r\n");
					break;
					case 2: //nome exatamente igual a
						fprintf(paciente_xsl,"<xsl:variable name=\"contador\">\r\n");
						fprintf(paciente_xsl,"0\r\n");
						fprintf(paciente_xsl,"<xsl:for-each select=\"doc/paciente\">\r\n");
						fprintf(paciente_xsl,"<xsl:if test=\"translate(nome, $upperCase, $lowerCase)=$translatedSearchText\">\r\n");
						fprintf(paciente_xsl,"<xsl:number count=\"paciente\" />\r\n");
						fprintf(paciente_xsl,"</xsl:if>\r\n");
						fprintf(paciente_xsl,"</xsl:for-each>\r\n");
						fprintf(paciente_xsl,"</xsl:variable>\r\n");
					break;
					case 3: //nome iniciado por
						fprintf(paciente_xsl,"<xsl:variable name=\"contador\">\r\n");
						fprintf(paciente_xsl,"0\r\n");
						fprintf(paciente_xsl,"<xsl:for-each select=\"doc/paciente\">\r\n");
						fprintf(paciente_xsl,"<xsl:if test=\"starts-with(translate(nome, $upperCase, $lowerCase), $translatedSearchText)\">\r\n");
						fprintf(paciente_xsl,"<xsl:number count=\"paciente\" />\r\n");
						fprintf(paciente_xsl,"</xsl:if>\r\n");
						fprintf(paciente_xsl,"</xsl:for-each>\r\n");
						fprintf(paciente_xsl,"</xsl:variable>\r\n");
					break;
					default:
					break;
				}
			break;
			case 3: //Atributo idade
				switch(strtoul(first->next->value,NULL, 10)) //valor do campo de operador
				{
					case 1: //idade menor que
						fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[%s&lt;%s])\" />\r\n", tabFields[opt-2][0], first->next->next->value);
					break;
					case 2: //idade igual que
						fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[%s=%s])\" />\r\n", tabFields[opt-2][0], first->next->next->value);
					break;
					case 3: //idade maior que
							fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[%s&gt;%s])\" />\r\n", tabFields[opt-2][0], first->next->next->value);
					break;
					default:
					break;
				}
			break;
			case 16:
				fprintf(paciente_xsl,"<xsl:variable name=\"contador\">\r\n");
				fprintf(paciente_xsl,"0\r\n");
				fprintf(paciente_xsl,"<xsl:for-each select=\"doc/paciente\">\r\n");
				fprintf(paciente_xsl,"<xsl:if test=\"contains(%s, '%s')\">\r\n", tabFields[opt-2][0], first->next->next->value);
				fprintf(paciente_xsl,"<xsl:number count=\"paciente\" />\n");
				fprintf(paciente_xsl,"</xsl:if>\n");
				fprintf(paciente_xsl,"</xsl:for-each>\n");
				fprintf(paciente_xsl,"</xsl:variable>\n");
			break;
			default: //Demais atributos
			fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[%s='%s'])\" />\n",tabFields[opt-2][0], first->next->next->value);
			break;
		}
		/************************************************************************************************/

		fprintf(paciente_xsl,"<html>\n");
		fprintf(paciente_xsl,"<head>\n");
		fprintf(paciente_xsl,"<title>.:. Resultados da busca .:. Projeto Neural TB .:.</title>\n");
		fprintf(paciente_xsl,"<link rel=\"stylesheet\" href=\"../sistema/css/busca.css\" type=\"text/css\" />\n");
		fprintf(paciente_xsl,"<link rel=\"stylesheet\" href=\"../sistema/css/menu.css\"   type=\"text/css\" />\n");
		fprintf(paciente_xsl,"</head>\n");
		fprintf(paciente_xsl,"<body>\n");
		fprintf(paciente_xsl,"<xsl:choose>\n");
		fprintf(paciente_xsl,"<xsl:when test=\"$contador != 0\">\n");
		/***** Iframe invisivel onde serao rodadas as CGIs de visto de paciente sem carregar uma nova pagina do browser *****/
		fprintf(paciente_xsl,"<iframe name=\"iframeInvisivel\" height=\"0\" width=\"0\"></iframe>\n");
		fprintf(paciente_xsl,"<table id=\"tabelaPacientes\" width=\"3000px\" border=\"1\" bordercolor=\"#000000\" cellspacing=\"0\" cellpadding=\"2\">\n");
		fprintf(paciente_xsl,"<tr bgcolor=\"999999\">\n");
		fprintf(paciente_xsl,"<th width=\"100\">Marcador</th>\n");
		fprintf(paciente_xsl,"<th width=\"50\">Editar</th>\n");
		fprintf(paciente_xsl,"<th width=\"50\">Remover</th>\n");
		fprintf(paciente_xsl,"<th width=\"50\">ID</th>\n");
		fprintf(paciente_xsl,"<th width=\"250\">Nome</th>\n");
		fprintf(paciente_xsl,"<th width=\"100\">Data de Nascimento</th>\n");
		fprintf(paciente_xsl,"<th width=\"50\">Idade</th>\n");
		fprintf(paciente_xsl,"<th width=\"100\">Sexo</th>\n");
		fprintf(paciente_xsl,"<th width=\"50\">Tosse</th>\n");
		fprintf(paciente_xsl,"<th width=\"100\">Hemoptóico</th>\n");
		fprintf(paciente_xsl,"<th width=\"100\">Sudorese Noturna</th>\n");
		fprintf(paciente_xsl,"<th width=\"50\">Febre</th>\n");
		fprintf(paciente_xsl,"<th width=\"50\">Emagrecimento</th>\n");
		fprintf(paciente_xsl,"<th width=\"50\">Dispnéia</th>\n");
		fprintf(paciente_xsl,"<th width=\"50\">Anorexia</th>\n");
		fprintf(paciente_xsl,"<th width=\"100\">Fuma Atualmente</th>\n");;
		fprintf(paciente_xsl,"<th width=\"100\">TB Extrapulmonar</th>\n");
		fprintf(paciente_xsl,"<th width=\"100\">Internação Hospitalar</th>\n");
		fprintf(paciente_xsl,"<th width=\"100\">SIDA</th>\n");
		fprintf(paciente_xsl,"<th width=\"500\">Observações</th>\n");

		/***** Os resultados do nnet sao exibidos apenas para medicos e administradores! *****/
		if (!strcmp(status, "medico") || !strcmp(status, "admin"))
		{
			fprintf(paciente_xsl,"<th width=\"300\">Resultado</th>\n");
			fprintf(paciente_xsl,"<th width=\"100\">&#160;Grupo de Risco&#160;</th>\n");
			fprintf(paciente_xsl,"<th width=\"100\">&#160;Gráfico de Grupo&#160;</th>\n");
			fprintf(paciente_xsl,"<th width=\"100\">&#160;Visto de Análise&#160;</th>\n");
		}
		/********************************************************************************/

		fprintf(paciente_xsl,"</tr>\n");
		fprintf(paciente_xsl,"<form name=\"check\">\n");
		fprintf(paciente_xsl,"<xsl:for-each select=\"doc/paciente\">\n");

		/***** Associando o valor pego no formulario ao campo de ordenacao *****/
		switch(opt)
		{
			case 1: //Atributo Todos
				orderValue = first->next->value;
			break;
			case 2: //Aributo nome
				orderValue = first->next->next->next->value;
			break;
			case 3: //Atributo idade
				orderValue = first->next->next->next->value;
			break;
			default: //Demais atributos
				orderValue = first->next->next->next->value;
		}
		/************************************************************************/

		if (!strcmp(orderValue, "idade")) //verifica se o campo de ordenacao e idade
			fprintf(paciente_xsl,"<xsl:sort select=\"%s\" data-type=\"number\" order=\"descending\" />\n", orderValue);
		else
			if (strcmp(orderValue, "id")) //verifica se o campo de ordenacao nao e id
				fprintf(paciente_xsl,"<xsl:sort select=\"%s\" data-type=\"text\" />\n", orderValue);
		fprintf(paciente_xsl,"<xsl:variable name=\"posicao\">\n");
		fprintf(paciente_xsl,"<xsl:number count=\"paciente\" />\n");
		fprintf(paciente_xsl,"</xsl:variable>\n");
		fprintf(paciente_xsl,"<xsl:variable name=\"linha\" select=\"position()\"/>\n");
		fprintf(paciente_xsl,"<xsl:variable name=\"linkEdit\" select=\"concat('%s/cgi-bin/formEdicao.cgi?id=', $posicao - 1)\"/>\n", SERVER);
		fprintf(paciente_xsl,"<xsl:variable name=\"linkRemove\" select=\"concat('%s/cgi-bin/removePaciente.cgi?id=', $posicao - 1)\"/>\n", SERVER);
		fprintf(paciente_xsl,"<xsl:variable name=\"linkParcialGrafico\" select=\"grafico_de_grupo\"  />\n");
		fprintf(paciente_xsl,"<xsl:variable name=\"linkCompletoGrafico\" select=\"concat($linkParcialGrafico, $posicao - 1)\"/>\n");
		fprintf(paciente_xsl,"<xsl:variable name=\"marcador\" select=\"concat('marcador', $linha)\" />\n");
		fprintf(paciente_xsl,"<xsl:variable name=\"visto\" select=\"concat('visto', $posicao - 1)\" />\n");
/*********************************************** FILTRANDO RESULTADOS DA BUSCA **********************************************************************************************************************************/
		switch(opt)
		{
			case 1:
			break;
			/* buscar nome */
			case 2:
				switch(strtoul(first->next->value,NULL, 10)) //valor do campo de operador
				{
					case 1:
						 fprintf(paciente_xsl,"<xsl:if test=\"contains(translate(nome, $upperCase, $lowerCase), $translatedSearchText)\">\n");
						break;
					case 2:
						 fprintf(paciente_xsl,"<xsl:if test=\"translate(nome, $upperCase, $lowerCase)=$translatedSearchText\">\n");
						break;
					case 3:
						 fprintf(paciente_xsl,"<xsl:if test=\"starts-with(translate(nome, $upperCase, $lowerCase), $translatedSearchText)\">\n");
					break;
					default:
					break;
				}
			break;
			/* buscar idade */
			case 3:
				switch(strtoul(first->next->value,NULL, 10)) //valor do campo de operador
				{
					case 1:
						fprintf(paciente_xsl,"<xsl:if test=\"%s &lt; %s\">\n", tabFields[opt-2][0], first->next->next->value);
					break;
					case 2:
						fprintf(paciente_xsl,"<xsl:if test=\"%s='%s'\">\n", tabFields[opt-2][0], first->next->next->value);
					break;
					case 3:
							fprintf(paciente_xsl,"<xsl:if test=\"%s &gt; '%s'\">\n", tabFields[opt-2][0], first->next->next->value);
					break;
					default:
					break;
				}
			break;
			case 16:
				fprintf(paciente_xsl,"<xsl:if test=\"contains(%s, '%s')\">\n", tabFields[opt-2][0], first->next->next->value);
			break;
			default: //Demais atributos
				fprintf(paciente_xsl,"<xsl:if test=\"%s ='%s'\">\n",tabFields[opt-2][0], first->next->next->value);
		}
/**************************************************************************************************************************************************************************************************/

		fprintf(paciente_xsl,"<tr align=\"center\" onClick=\"var marcador = 'marcador' + this.rowIndex;if(document.getElementById(marcador).checked == true) document.getElementById('tabelaPacientes').rows[this.rowIndex].style.background = '#99CCFF'; else document.getElementById('tabelaPacientes').rows[this.rowIndex].style.background = '#FFFFFF';\">\n");
		fprintf(paciente_xsl,"<td>\n");
		fprintf(paciente_xsl,"<input type=\"checkbox\" id=\"{$marcador}\" />\n");
		fprintf(paciente_xsl,"</td>\n");
		fprintf(paciente_xsl,"<td>\n");
		fprintf(paciente_xsl,"<a href=\"{$linkEdit}\"><img src=\"../sistema/figuras/edit.png\" /></a>\n");
		fprintf(paciente_xsl,"</td>\n");
		fprintf(paciente_xsl,"<td>\n");
		fprintf(paciente_xsl,"<a href=\"{$linkRemove}\"><img src=\"../sistema/figuras/remove.png\" /></a>\n");
		fprintf(paciente_xsl,"</td>\n");
		fprintf(paciente_xsl,"<td>\n");
		fprintf(paciente_xsl,"<xsl:number count=\"paciente\" format=\"001\" />\n");
		fprintf(paciente_xsl,"</td>\n");
		fprintf(paciente_xsl,"<td>\n");
		fprintf(paciente_xsl,"<xsl:value-of select=\"nome\"/>\n");
		fprintf(paciente_xsl,"</td>\n");
		fprintf(paciente_xsl,"<td>\n");
		fprintf(paciente_xsl,"<xsl:value-of select=\"data_nascimento\"/>\n");
		fprintf(paciente_xsl,"</td>\n");
		fprintf(paciente_xsl,"<td>\n");
		fprintf(paciente_xsl,"<xsl:value-of select=\"idade\"/>\n");
		fprintf(paciente_xsl,"</td>\n");
		fprintf(paciente_xsl,"<td>\n");
		fprintf(paciente_xsl,"<xsl:value-of select=\"sexo\"/>\n");
		fprintf(paciente_xsl,"</td>\n");
		fprintf(paciente_xsl,"<td>\n");
		fprintf(paciente_xsl,"<xsl:value-of select=\"tosse\"/>\n");
		fprintf(paciente_xsl,"</td>\n");
		fprintf(paciente_xsl,"<td>\n");
		fprintf(paciente_xsl,"<xsl:value-of select=\"hemoptoico\"/>\n");
		fprintf(paciente_xsl,"</td>\n");
		fprintf(paciente_xsl,"<td>\n");
		fprintf(paciente_xsl,"<xsl:value-of select=\"sudorese\"/>\n");
		fprintf(paciente_xsl,"</td>\n");
		fprintf(paciente_xsl,"<td>\n");
		fprintf(paciente_xsl,"<xsl:value-of select=\"febre\"/>\n");
		fprintf(paciente_xsl,"</td>\n");
		fprintf(paciente_xsl,"<td>\n");
		fprintf(paciente_xsl,"<xsl:value-of select=\"emagrecimento\"/>\n");
		fprintf(paciente_xsl,"</td>\n");
		fprintf(paciente_xsl,"<td>\n");
		fprintf(paciente_xsl,"<xsl:value-of select=\"dispneia\"/>\n");
		fprintf(paciente_xsl,"</td>\n");
		fprintf(paciente_xsl,"<td>\n");
		fprintf(paciente_xsl,"<xsl:value-of select=\"anorexia\"/>\n");
		fprintf(paciente_xsl,"</td>\n");
		fprintf(paciente_xsl,"<td>\n");
		fprintf(paciente_xsl,"<xsl:value-of select=\"fuma_atualmente\"/>\n");
		fprintf(paciente_xsl,"</td>\n");
		fprintf(paciente_xsl,"<td>\n");
		fprintf(paciente_xsl,"<xsl:value-of select=\"tb_extrapulmonar\"/>\n");
		fprintf(paciente_xsl,"</td>\n");
		fprintf(paciente_xsl,"<td>\n");
		fprintf(paciente_xsl,"<xsl:value-of select=\"internacao_hospitalar\"/>\n");
		fprintf(paciente_xsl,"</td>\n");
		fprintf(paciente_xsl,"<td>\n");
		fprintf(paciente_xsl,"<xsl:value-of select=\"sida\"/>\n");
		fprintf(paciente_xsl,"</td>\n");
		fprintf(paciente_xsl,"<td>\n");
		fprintf(paciente_xsl,"&#160;<xsl:value-of select=\"observacoes\"/>\n");
		fprintf(paciente_xsl,"</td>\n");
		/**************************************************************************
		 *                        VERIFICANDO NIVEL DE ACESSO DO USUARIO          *
		 **************************************************************************/
		if (!strcmp(status, "medico") || !strcmp(status, "admin"))
		{
			fprintf(paciente_xsl,"<td>\n");
			fprintf(paciente_xsl,"<xsl:value-of select=\"resultado\"/>\n");
			fprintf(paciente_xsl,"</td>\n");
			fprintf(paciente_xsl,"<td>\n");
			fprintf(paciente_xsl,"<xsl:value-of select=\"grupo_de_risco\"/>\n");
			fprintf(paciente_xsl,"</td>\n");
			fprintf(paciente_xsl,"<td>\n");
			fprintf(paciente_xsl,"<a href=\"{$linkCompletoGrafico}\" target=\"_blank\">Visualizar</a>\n");
			fprintf(paciente_xsl,"</td>\n");
			fprintf(paciente_xsl,"<td>\n");
			fprintf(paciente_xsl,"<input type=\"checkbox\" id=\"{$visto}\" onClick=\"var nroLinha = this.id.substring(5); var linkInsereVisto = '%s/cgi-bin/insereVisto.cgi?id=' + nroLinha; var linkRemoveVisto = '%s/cgi-bin/removeVisto.cgi?id=' + nroLinha; if (this.checked == true) document.all.iframeInvisivel.src = linkInsereVisto; else document.all.iframeInvisivel.src = linkRemoveVisto;\"  />\n", SERVER, SERVER);
			fprintf(paciente_xsl,"</td>\n");
			fprintf(paciente_xsl,"<xsl:if test=\"visto_de_analise = 'Sim'\">\n");
			fprintf(paciente_xsl,"<script language=\"javascript\">ultimo = document.check.elements.length; idVisto = document.check.elements[ultimo-1].id; document.getElementById(idVisto).checked = true;</script>\n");
			fprintf(paciente_xsl,"</xsl:if>\n");
		}
		fprintf(paciente_xsl,"</tr>\n");
		if(opt != 1)
			fprintf(paciente_xsl,"</xsl:if>\n");
		fprintf(paciente_xsl,"</xsl:for-each>\n");
		fprintf(paciente_xsl,"</form>\n");
		fprintf(paciente_xsl,"</table>\n");
		fprintf(paciente_xsl,"</xsl:when>\n");
		fprintf(paciente_xsl,"<xsl:otherwise>\n");
		fprintf(paciente_xsl,"<p>&#160;&#160;&#160;&#160;&#160;<b>Não foram encontrados pacientes.</b></p>\n");
		fprintf(paciente_xsl,"</xsl:otherwise>\n");
		fprintf(paciente_xsl,"</xsl:choose>\n");
		fprintf(paciente_xsl,"</body>\n");
		fprintf(paciente_xsl,"</html>\n");
		fprintf(paciente_xsl,"</xsl:template>\n");
		fprintf(paciente_xsl,"</xsl:stylesheet>\n");
		fclose(paciente_xsl);
		printf("\n<!-- xhtml -->\n");
		printf("<script type=\"text/javascript\">\n");

		// Load XML
		printf("var xml = new ActiveXObject(\"Microsoft.XMLDOM\");\n");
		printf("xml.async = false;\n");
		printf("xml.load(\"../sistema/xml/guadalupe_paciente.xml\");\n");

		// Load XSL
		printf("var xsl = new ActiveXObject(\"Microsoft.XMLDOM\");\n");
		printf("xsl.async = false;\n");
		printf("xsl.load(\"../sistema/xml/buscaPaciente.xsl\");\n");

		// Transform
		printf("document.write(xml.transformNode(xsl));\n");
		printf("</script>\n");

		printf("</body>\n");
		printf("</html>\n");


/******************************************************************************
 *                            FREE MEMORY AND EXIT                            *
 ******************************************************************************/

	for (aux=form=first; aux!=NULL; form=aux)
	{
		aux = form->next;
		free (form);
	}

	exit(OK);
}

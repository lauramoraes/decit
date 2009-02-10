/******************************************************************************
 Adaptado de:
 * Autor: Rony Tadeu Vernet Braga                                             *
 * Projeto: Neural TB                                                         *
 * Description: CGI to find patients in the XML file through XSLT and XPATH   *
 
 Atualização: Laura Moraes
 Ultima atualizacao: 28/10/2008 
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
	int i=0;
	double contentLength;
	char *orderValue;
	char* temp1;
	char* temp2;
	char* fieldNameTemp;
	char fieldName[20];
	char optionNumber[3];
	char originalString[10240];
	char processedString[10240];
	char hexa[3];
	char* username;
	FILE* paciente_xsl;
	const char *length;
	chainType *form, *aux, *first, *dates;
	
/******************************************************************************
 *                      READ CONTENT StrING FROM SERVER                       *
 ******************************************************************************/


	if(!(length= getenv("CONTENT_LENGTH")))
	{

		printf("Content-type: text/html\n\n");
		//printf("\r\n");
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

	printf("Content-type: text/html\n\n");
    printf("<html>\n");
  	printf("<head>\n");
	printf("<meta http-equiv=content-type content=\"text/html; charset=UTF-8\">\n");
    printf("<title>.:. Neural TB .:. Busca de pacientes</title>\n");
    printf("<link  rel=\"stylesheet\" type=\"text/css\" href=\"../css/standart.css\"/>\n");
    printf("<script language=\"javascript\" src=\"../js/xml.js\"></script>\n");
    printf("<script language=\"javascript\" src=\"../js/busca.js\"></script>\n");
	printf("<script>\n");
	printf("var contaExib=0\n");
	printf("var linha=0;\n");
	printf("function contaLinhas()\n");
	printf("{\n");
	printf("	linha+=1;\n");
	printf("}\n");
	printf("</script>\n");
	printf("  </head>\n");
	printf("<body bgcolor=\"white\">\n");
	printf("<table height=\"120\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">\n");
    printf("<tr bgcolor=\"#CCCCCC\">\n");
	printf("<td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</td>");
	printf("<td><b><u><font size=\"5\">Menu</font></u></b></td>\n");
	printf("<td>&nbsp;</td>\n");
    printf("</tr>\n");
    printf("<tr bgcolor=\"#CCCCCC\">");
    printf("<td>&nbsp;</td>");
    printf("<td width=\"100%c\">",37);
	printf("<a href=\"formulario.cgi?uid=%s\">Adicionar Paciente</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n", first->value);
	printf("<a href=\"busca.cgi?uid=%s\">Buscar/Editar/Remover</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;", first->value);
	printf("<a href=\"backup.cgi\"> Back-up</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
	printf("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
    printf("<a href=\"principal.cgi?uid=%s\">P&aacute;gina principal</a>\n", first->value);
	printf("</td>\n");
    printf("<td></td>\n");
    printf("</tr>\n");
    printf("<tr bgcolor=\"#CCCCCC\">");
    printf("<td>&nbsp;</td>\n");
    printf("<td>\n");
    printf("<a href=\"exibirPacientes.cgi?uid=%s\">Exibir question&aacute;rios</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n", first->value);
    printf("<a href=\"exibirRecusa.cgi?uid=%s\">Exibir recusas</a>\n", first->value);
    printf("</td>\n");
    printf("<td></td>\n");
    printf("</tr>\n");
    printf(" </table>\n");
	printf("<p></p>\r\n");
//opt=strtoul(first->value,NULL,10);
///////// Separa o numero do nome do campo dado em 'first->value' no FORMATO: numero.nome (exemplo: 3.idade) em duas variáveis /////////
	
	username = first->value;
	first = first->next;
	while (((first->value)[i] != '.')&&((first->value)[i] != '\0'))
	{
		optionNumber[i] = (first->value)[i];
		i++;
	}
	optionNumber[i] = '\0';
	
	opt=strtoul(optionNumber,NULL,10);
	
	fieldNameTemp = strchr(first->value, '.');
	
	for (i=0; i<strlen(fieldNameTemp); i++)
	{
		fieldName[i] = fieldNameTemp[i+1];
	}
	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	paciente_xsl= fopen("../xml/buscaPaciente.xsl", "w");
	fprintf(paciente_xsl,"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
	fprintf(paciente_xsl,"<xsl:stylesheet version=\"1.0\" xmlns:xsl=\"http://www.w3.org/1999/XSL/Transform\">\r\n");
		/***** Se o campo de busca for nome essas variaveis serao usadas *****/
		if(opt == 2)
		{
				fprintf(paciente_xsl,"<xsl:param name=\"upperCase\" select=\"'ABCDEFGHIJKLMNOPQRSTUVWXYZ'\"/>\r\n"); //Cria variavel com letras maiusculas
				fprintf(paciente_xsl,"<xsl:param name=\"lowerCase\" select=\"'abcdefghijklmnopqrstuvwxyz'\"/>\r\n"); //Cria variavel com letras minusculas
				fprintf(paciente_xsl,"<xsl:param name=\"searchTextToTranslate\" select=\"'%s'\"/>\r\n", first->next->next->value); //Cria variavel com o valor a ser procurado
				fprintf(paciente_xsl,"<xsl:variable name=\"translatedSearchText\" select=\"translate($searchTextToTranslate, $upperCase, $lowerCase)\"/>\r\n"); //Transforma o valor a ser procurado para letras minusculas
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
			case 3: //Caso de datas
				fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[%s='%s'])\" />\n",fieldName, first->next->value);
				dates = first->next->next;
				fprintf(paciente_xsl,"<xsl:variable name=\"contadorMes\" select=\"count(doc/paciente[%s='%s'])\" />\n",dates->attribute, dates->value);
				dates = dates->next;
				fprintf(paciente_xsl,"<xsl:variable name=\"contadorAno\" select=\"count(doc/paciente[%s='%s'])\" />\n",dates->attribute, dates->value);
			break;
			/*case 3: //Atributo idade
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
			break;*/
			default: //Demais atributos
			fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[%s='%s'])\" />\n",fieldName, first->next->value);
			break;
		}
		/************************************************************************************************/
		
		fprintf(paciente_xsl,"<html>\n");
		fprintf(paciente_xsl,"<head>\n");
		fprintf(paciente_xsl,"<title>.:. Resultados da busca .:. Projeto Neural TB .:.</title>\n");
		fprintf(paciente_xsl,"<link rel=\"stylesheet\" type=\"text/css\" href=\"../css/standard.css\"/>\n");
		fprintf(paciente_xsl,"</head>\n");
		fprintf(paciente_xsl,"<body>\n");
		fprintf(paciente_xsl,"<xsl:choose>\n");
		fprintf(paciente_xsl,"<xsl:when test=\"$contador != 0\">\n");
		
		if (opt == 3) //Caso seja data, eh preciso considerar os outros contadores
		{
			fprintf(paciente_xsl,"<xsl:choose>\n");
			fprintf(paciente_xsl,"<xsl:when test=\"$contadorMes != 0\">\n");
			fprintf(paciente_xsl,"<xsl:choose>\n");
			fprintf(paciente_xsl,"<xsl:when test=\"$contadorAno != 0\">\n");
		}
		
		/***** Iframe invisivel onde serao rodadas as CGIs de visto de paciente sem carregar uma nova pagina do browser *****
		fprintf(paciente_xsl,"<iframe name=\"iframeInvisivel\" height=\"0\" width=\"0\"></iframe>\n");*/
		fprintf(paciente_xsl,"<table id=\"tabelaPacientes\" width=\"650\" align=\"center\" cellspacing=\"1\" cellpadding=\"0\">\n");
		fprintf(paciente_xsl,"<tr class=\"nome\" align=\"center\">\n");
		fprintf(paciente_xsl,"<td><h4>Numero</h4></td>\n");
		fprintf(paciente_xsl,"<td><h4>Nome</h4></td>\n");
		fprintf(paciente_xsl,"<td><h4>Data de nascimento</h4></td>\n");
		fprintf(paciente_xsl,"<td><h4>Data da entrevista</h4></td>\n");
		fprintf(paciente_xsl,"<td><h4>Remover</h4></td>\n");
		fprintf(paciente_xsl,"<td><h4>Editar</h4></td>\n");

		/***** Os resultados do nnet sao exibidos apenas para medicos e administradores! 
	/*	if (!strcmp(status, "medico") || !strcmp(status, "admin"))
		{
			fprintf(paciente_xsl,"<th width=\"300\">Resultado</th>\n");
			fprintf(paciente_xsl,"<th width=\"100\">&#160;Grupo de Risco&#160;</th>\n");
			fprintf(paciente_xsl,"<th width=\"100\">&#160;Gráfico de Grupo&#160;</th>\n");
			fprintf(paciente_xsl,"<th width=\"100\">&#160;Visto de Análise&#160;</th>\n");
		}
		/********************************************************************************/

		fprintf(paciente_xsl,"</tr>\n");
		//fprintf(paciente_xsl,"<form name=\"check\">\n");
		fprintf(paciente_xsl,"<xsl:for-each select=\"doc/paciente\">\n");

		/***** Associando o valor pego no formulario ao campo de ordenacao *****/
		
	/*	orderValue = first->next->next->next->value;
		
		/************************************************************************/

		/*if (!strcmp(orderValue, "idade")) //verifica se o campo de ordenacao e idade
			fprintf(paciente_xsl,"<xsl:sort select=\"%s\" data-type=\"number\" order=\"descending\" />\n", orderValue);
		else
			if (strcmp(orderValue, "id")) //verifica se o campo de ordenacao nao e id
				fprintf(paciente_xsl,"<xsl:sort select=\"%s\" data-type=\"text\" />\n", orderValue);
		fprintf(paciente_xsl,"<xsl:variable name=\"posicao\">\n");
		fprintf(paciente_xsl,"<xsl:number count=\"paciente\" />\n");
		fprintf(paciente_xsl,"</xsl:variable>\n");
		fprintf(paciente_xsl,"<xsl:variable name=\"linha\" select=\"position()\"/>\n");
		fprintf(paciente_xsl,"<xsl:variable name=\"linkEdit\" select=\"concat('%s/cgi-bin/formEdicaoModif.cgi?id=', $posicao - 1)\"/>\n", SERVER);
		fprintf(paciente_xsl,"<xsl:variable name=\"linkRemove\" select=\"concat('%s/cgi-bin/removePacienteModif.cgi?id=', $posicao - 1)\"/>\n", SERVER);
		fprintf(paciente_xsl,"<xsl:variable name=\"linkParcialGrafico\" select=\"grafico_de_grupo\"  />\n");
		fprintf(paciente_xsl,"<xsl:variable name=\"linkCompletoGrafico\" select=\"concat($linkParcialGrafico, $posicao - 1)\"/>\n");
		fprintf(paciente_xsl,"<xsl:variable name=\"marcador\" select=\"concat('marcador', $linha)\" />\n");
		fprintf(paciente_xsl,"<xsl:variable name=\"visto\" select=\"concat('visto', $posicao - 1)\" />\n");*/
/*********************************************** FILTRANDO RESULTADOS DA BUSCA **********************************************************************************************************************************/
		switch(opt)
		{
			case 1:
			break;
			// buscar nome 
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
			case 3:
				fprintf(paciente_xsl,"<xsl:if test=\"%s ='%s'\">\n",fieldName, first->next->value);
				dates = first->next->next;
				fprintf(paciente_xsl,"<xsl:if test=\"%s ='%s'\">\n",dates->attribute, dates->value);
				dates = dates->next;
				fprintf(paciente_xsl,"<xsl:if test=\"%s ='%s'\">\n",dates->attribute, dates->value);
			break;
			// buscar idade 
			/*case 3:
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
			break;*/
			default: //Demais atributos
				fprintf(paciente_xsl,"<xsl:if test=\"%s ='%s'\">\n",fieldName, first->next->value);
		}
/**************************************************************************************************************************************************************************************************/

		fprintf(paciente_xsl,"<tr class=\"fundoTabela\" align=\"center\" onClick=\"var marcador = 'marcador' + this.rowIndex;if(document.getElementById(marcador).checked == true) document.getElementById('tabelaPacientes').rows[this.rowIndex].style.background = '#99CCFF'; else document.getElementById('tabelaPacientes').rows[this.rowIndex].style.background = '#FFFFFF';\">\n");
		fprintf(paciente_xsl,"<td>\n");
		fprintf(paciente_xsl,"<xsl:number count=\"paciente\" format=\"1\"/>\n");
		fprintf(paciente_xsl,"</td>\n");
		fprintf(paciente_xsl,"<td>\n");
		fprintf(paciente_xsl,"<xsl:value-of select=\"nome\"/>\n");
		fprintf(paciente_xsl,"</td>\n");
		fprintf(paciente_xsl,"<td>\n");
		fprintf(paciente_xsl,"<xsl:value-of select=\"diaNasc\"/>/<xsl:value-of select=\"mesNasc\"/>/<xsl:value-of select=\"anoNasc\"/>\n");
		fprintf(paciente_xsl,"</td>\n");
		fprintf(paciente_xsl,"<td>\n");
		fprintf(paciente_xsl,"<xsl:value-of select=\"diaEntr\"/>/<xsl:value-of select=\"mesEntr\"/>/<xsl:value-of select=\"anoEntr\"/>\n");
		fprintf(paciente_xsl,"</td>\n");
		fprintf(paciente_xsl,"<td class='link'  align='center'>\n");
		fprintf(paciente_xsl,"<a href=\"remover.cgi?paciente={position()}&amp;uid=%s\">Remover</a>\n",username);
		fprintf(paciente_xsl,"</td>\n");
		fprintf(paciente_xsl,"<td class='link'  align='center'>\n");
		fprintf(paciente_xsl,"<a href=\"editar.cgi?paciente={position()}&amp;uid=%s\">Editar</a>\n",username);
		fprintf(paciente_xsl,"</td>\n");

		/**************************************************************************
		 *                        VERIFICANDO NIVEL DE ACESSO DO USUARIO          *
		 **************************************************************************/
		/*if (!strcmp(status, "medico") || !strcmp(status, "admin"))
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
			fprintf(paciente_xsl,"<input type=\"checkbox\" id=\"{$visto}\" onClick=\"var nroLinha = this.id.substring(5); var linkInsereVisto = '%s/cgi-bin/insereVistoModif.cgi?id=' + nroLinha; var linkRemoveVisto = '%s/cgi-bin/removeVistoModif.cgi?id=' + nroLinha; if (this.checked == true) document.all.iframeInvisivel.src = linkInsereVisto; else document.all.iframeInvisivel.src = linkRemoveVisto;\"  />\n", SERVER, SERVER);
			fprintf(paciente_xsl,"</td>\n");
			fprintf(paciente_xsl,"<xsl:if test=\"visto_de_analise = 'Sim'\">\n");
			fprintf(paciente_xsl,"<script language=\"javascript\">ultimo = document.check.elements.length; idVisto = document.check.elements[ultimo-1].id; document.getElementById(idVisto).checked = true;</script>\n");
			fprintf(paciente_xsl,"</xsl:if>\n");
		}
	*/
		fprintf(paciente_xsl,"</tr>\n");
		if(opt != 1)
			fprintf(paciente_xsl,"</xsl:if>\n");
			
		if (opt == 3) //Caso seja data, eh preciso fechar os outros 'if'
		{
			fprintf(paciente_xsl,"</xsl:if>\n");
			fprintf(paciente_xsl,"</xsl:if>\n");
		}
			
		fprintf(paciente_xsl,"</xsl:for-each>\n");
		//fprintf(paciente_xsl,"</form>\n");
		fprintf(paciente_xsl,"</table>\n");
		fprintf(paciente_xsl,"</xsl:when>\n");
		fprintf(paciente_xsl,"<xsl:otherwise>\n");
		fprintf(paciente_xsl,"<p>&#160;&#160;&#160;&#160;&#160;<b>Não foram encontrados pacientes.</b></p>\n");
		fprintf(paciente_xsl,"</xsl:otherwise>\n");
		fprintf(paciente_xsl,"</xsl:choose>\n");
		
		if (opt == 3) //Caso seja data, eh preciso fechar os outros 'when'
		{
			fprintf(paciente_xsl,"</xsl:when>\n");
			fprintf(paciente_xsl,"<xsl:otherwise>\n");
			fprintf(paciente_xsl,"<p>&#160;&#160;&#160;&#160;&#160;<b>Não foram encontrados pacientes.</b></p>\n");
			fprintf(paciente_xsl,"</xsl:otherwise>\n");
			fprintf(paciente_xsl,"</xsl:choose>\n");
			fprintf(paciente_xsl,"</xsl:when>\n");
			fprintf(paciente_xsl,"<xsl:otherwise>\n");
			fprintf(paciente_xsl,"<p>&#160;&#160;&#160;&#160;&#160;<b>Não foram encontrados pacientes.</b></p>\n");
			fprintf(paciente_xsl,"</xsl:otherwise>\n");
			fprintf(paciente_xsl,"</xsl:choose>\n");
		}

		fprintf(paciente_xsl,"</body>\n");
		fprintf(paciente_xsl,"</html>\n");
		fprintf(paciente_xsl,"</xsl:template>\n");
		fprintf(paciente_xsl,"</xsl:stylesheet>\n");
		fclose(paciente_xsl);
		printf("<div id='showXML'></div>\n");
		printf("\n<!-- xhtml -->\n");
		printf("<script type=\"text/javascript\">\n");

		// Load XML
		printf("var xml=null;\n");
		printf("if (window.ActiveXObject)\n");
		printf("{// code for IE\n");
		printf("xml=new ActiveXObject(\"Microsoft.XMLDOM\");\n");
		printf("}\n");
		printf("else if (document.implementation.createDocument)\n");
		printf("{// code for Mozilla, Firefox, Opera, etc.\n");
		printf("xml=document.implementation.createDocument(\"\",\"\",null);\n");
		printf("}\n");
		printf("else\n");
		printf("{\n");
		printf("alert('Your browser cannot handle this script');\n");
		printf("}\n");
		printf("xml.async = false;\n");
		printf("xml.load(\"../xml/pacientes.xml\");\n");

		// Load XSL
		printf("var xsl=null;\n");
		printf("if (window.ActiveXObject)\n");
		printf("{// code for IE\n");
		printf("xsl=new ActiveXObject(\"Microsoft.XMLDOM\");\n");
		printf("}\n");
		printf("else if (document.implementation.createDocument)\n");
		printf("{// code for Mozilla, Firefox, Opera, etc.\n");
		printf("xsl=document.implementation.createDocument(\"\",\"\",null);\n");
		printf("}\n");
		printf("else\n");
		printf("{\n");
		printf("alert('Your browser cannot handle this script');\n");
		printf("}\n");
		printf("xsl.async = false;\n");
		printf("xsl.load(\"../xml/buscaPaciente.xsl\");\n");

		// Transform
		printf("if (window.ActiveXObject)\n");
		printf("{\n");
		printf("  ex=xml.transformNode(xsl);\n");
		printf("  document.getElementById(\"showXML\").innerHTML=ex;\n");
		printf("  }\n");
		printf("// code for Mozilla, Firefox, Opera, etc.\n");
		printf("else if (document.implementation \n");
		printf("&& document.implementation.createDocument)\n");
		printf("  {\n");
		printf("  xsltProcessor=new XSLTProcessor();\n");
		printf("  xsltProcessor.importStylesheet(xsl);\n");
		printf("  resultDocument = xsltProcessor.transformToFragment(xml,document);\n");
		printf("  document.getElementById(\"showXML\").appendChild(resultDocument);\n");
		printf("  }\n");
		printf("</script>\n");
		
		//Calculando a frequencia das variáveis
		printf("<div align=center><b>\n");
		printf("<script>\n");
		printf("var nroPacTotal = xml.getElementsByTagName(\"paciente\").length;\n");
		printf("var nroPac= document.getElementById(\"tabelaPacientes\").rows.length;\n");
		printf("document.write(((nroPac-1)*100/nroPacTotal).toFixed(2));\n");
		printf("document.write(\"%% dos pacientes apresentam o critério procurado\");\n");
		printf("</script>\n");
		printf("</b></div>\n");
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

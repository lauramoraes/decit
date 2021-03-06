#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct chain
{
	char *attribute;
	char *value;
	struct chain *next;
} chainType;


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

    printf("Content-type: text/html\n\n");
    printf("<html>\n");
    printf("<head>\n");
    printf("<title>NeuralTB</title>\n");
    printf("<link  rel=\"stylesheet\" type=\"text/css\" href=\"css/standart.css\">\n");
	printf("<script src=\"js/busca.js\"></script>\n");
    printf("</head>\n");
    printf("<body class=\"style1\">\n");
    printf("<table height=\"120\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">\n");
	printf("<tr bgcolor=\"#CCCCCC\">\n");
	printf("    <td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</td>\n");
	printf("    <td><b><u><font size=\"5\">Menu</font></u></b></td>\n");
	printf("    <td>&nbsp;</td>\n");
	printf("</tr>\n");
    printf("	<tr bgcolor=\"#CCCCCC\">\n");
    printf("    <td>&nbsp;</td>\n");
    printf("    <td width=\"100%%\">\n");
	printf("       <a href=\"formulario.html\">Adicionar Paciente</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
	printf("       <a href=\"busca.html\">Buscar/Editar/Remover</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
    printf("       &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
    printf("       &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
    printf("       &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
    printf("       &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
    printf("       <a href=\"principal.html\">Página principal</a>\n");
	printf("    </td>\n");
    printf("    <td></td>\n");
	printf("</tr>\n");
	printf("<tr bgcolor=\"#CCCCCC\">\n");
    printf("    <td>&nbsp;</td>\n");
    printf("    <td>\n");
    printf("       <a href=\"exibirPacientes.html\">Exibir questionários</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
    printf("       <a href=\"exibirRecusa.html\">Exibir recusas</a>\n");
    printf("    </td>\n");
    printf("</tr>\n");
	printf("</table>\n");
	printf("<p>&nbsp;</p>\n");
    opt=strtoul(first->value,NULL,10);
	paciente_xsl= fopen("../xml/buscaPaciente.xsl", "w");
        fprintf(paciente_xsl,"<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>\n");
		fprintf(paciente_xsl,"<xsl:stylesheet version=\"1.0\" xmlns:xsl=\"http://www.w3.org/1999/XSL/Transform\">\n");
		/***** Se o campo de busca for nome essas variaveis serao usadas *****/
		if(opt == 2)
		{
				fprintf(paciente_xsl,"<xsl:param name=\"upperCase\" select=\"'ABCDEFGHIJKLMNOPQRSTUVWXYZ'\"/>\n");
				fprintf(paciente_xsl,"<xsl:param name=\"lowerCase\" select=\"'abcdefghijklmnopqrstuvwxyz'\"/>\n");
				fprintf(paciente_xsl,"<xsl:param name=\"searchTextToTranslate\" select=\"'%s'\"/>\n", first->next->next->value);
				fprintf(paciente_xsl,"<xsl:variable name=\"translatedSearchText\" select=\"translate($searchTextToTranslate, $upperCase, $lowerCase)\"/>\n");
		}
  		fprintf(paciente_xsl,"<xsl:template match=\"/\">\n");
  		
        /***** Bloco responsavel pela verificacao de valores encontrados para a busca - conta eles *****/
		switch(opt)
		{
   			case 2: //Atributo nome
				switch(strtoul(first->next->value,NULL, 10)) //valor do campo de operador
				{
					case 1: //nome contendo
						fprintf(paciente_xsl,"<xsl:variable name=\"contador\">\n");
						fprintf(paciente_xsl,"0\n");
						fprintf(paciente_xsl,"<xsl:for-each select=\"doc/paciente\">\n");
						fprintf(paciente_xsl,"<xsl:if test=\"contains(translate(nome, $upperCase, $lowerCase), $translatedSearchText)\">\n");
						fprintf(paciente_xsl,"<xsl:number count=\"paciente\" />\n");
						fprintf(paciente_xsl,"</xsl:if>\n");
						fprintf(paciente_xsl,"</xsl:for-each>\n");
						fprintf(paciente_xsl,"</xsl:variable>\n");
					break;
					case 2: //nome exatamente igual a
						fprintf(paciente_xsl,"<xsl:variable name=\"contador\">\n");
						fprintf(paciente_xsl,"0\n");
						fprintf(paciente_xsl,"<xsl:for-each select=\"doc/paciente\">\n");
						fprintf(paciente_xsl,"<xsl:if test=\"translate(nome, $upperCase, $lowerCase)=$translatedSearchText\">\n");
						fprintf(paciente_xsl,"<xsl:number count=\"paciente\" />\n");
						fprintf(paciente_xsl,"</xsl:if>\n");
						fprintf(paciente_xsl,"</xsl:for-each>\n");
						fprintf(paciente_xsl,"</xsl:variable>\n");
					break;
					case 3: //nome iniciado por
						fprintf(paciente_xsl,"<xsl:variable name=\"contador\">\n");
						fprintf(paciente_xsl,"0\n");
						fprintf(paciente_xsl,"<xsl:for-each select=\"doc/paciente\">\n");
						fprintf(paciente_xsl,"<xsl:if test=\"starts-with(translate(nome, $upperCase, $lowerCase), $translatedSearchText)\">\n");
						fprintf(paciente_xsl,"<xsl:number count=\"paciente\" />\n");
						fprintf(paciente_xsl,"</xsl:if>\n");
						fprintf(paciente_xsl,"</xsl:for-each>\n");
						fprintf(paciente_xsl,"</xsl:variable>\n");
					break;
					default:
					break;
				}
			break;
			case 3: //atributo cidade
                if(!strcmp(first->next->next->value,"1"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[cidade='Curitiba / Paraná'])\" />\n",);
                else if(!strcmp(first->next->next->value,"2"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[cidade='Fortaleza/Ceará'])\" />\n",);
                else(!strcmp(first->next->next->value,"3"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[cidade='Itaboraí/RJ'])\" />\n",);
            break;
			case 4: //atributo unidade
                if(!strcmp(first->next->next->value,"1"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[unidade='Programa Saúde Família'])\" />\n",);
                else if(!strcmp(first->next->next->value,"2"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[unidade='Unidade Básica de Saúde'])\" />\n",);
                else if(!strcmp(first->next->next->value,"3"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[unidade='Ambulatório - Posto de Saúde'])\" />\n",);
                else if(!strcmp(first->next->next->value,"4"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[unidade='Unid Pronto Atendimento/Urgência/Emergência'])\" />\n",);
                else if(!strcmp(first->next->next->value,"5"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[unidade='Unidade Hospitalar'])\" />\n",);
                else(!strcmp(first->next->next->value,"6"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[unidade!='Outro'])\" />\n",);
			break;
			case 5: //atributo tipo
                if(!strcmp(first->next->next->value,"1"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[cidade='Contato assintomático'])\" />\n",);
                else if(!strcmp(first->next->next->value,"2"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[cidade='Sintomático Respiratório'])\" />\n",);
                else if(!strcmp(first->next->next->value,"3"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[cidade='Caso Suspeito de Tuberculose Pulmonar'])\" />\n",);
                else(!strcmp(first->next->next->value,"4"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[cidade!='outro'])\" />\n",);
			break;
			case 6: //atributo numero cat-sus
                fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[numfns='%s'])\" />\n", first->next->value);
			break;
			case 7: //atributo prof. saude
                if(!strcmp(first->next->next->value,"sim"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[profsaude='Sim'])\" />\n",);
                else
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[profsaude='Não'])\" />\n",);

			break;
			case 8: //atributo sintomas
                if(!strcmp(first->next->next->value,"1"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[tosse='Sim'])\" />\n",);
                else if(!strcmp(first->next->next->value,"2"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[catarr='Sim'])\" />\n",);
                else if(!strcmp(first->next->next->value,"3"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[hempti='Sim'])\" />\n",);
                else if(!strcmp(first->next->next->value,"4"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[hempto='Sim'])\" />\n",);
                else if(!strcmp(first->next->next->value,"5"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[febre='Sim'])\" />\n",);
                else if(!strcmp(first->next->next->value,"6"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[sudore='Sim'])\" />\n",);
                else if(!strcmp(first->next->next->value,"7"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[hipore='Sim'])\" />\n",);
                else if(!strcmp(first->next->next->value,"8"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[emagre='Sim'])\" />\n",);
                else if(!strcmp(first->next->next->value,"9"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[asteni='Sim'])\" />\n",);
                else if(!strcmp(first->next->next->value,"10"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[rouqui='Sim'])\" />\n",);
                else if(!strcmp(first->next->next->value,"11"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[linfon='Sim'])\" />\n",);
                else if(!strcmp(first->next->next->value,"12"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[dispn='Sim'])\" />\n",);
                else if(!strcmp(first->next->next->value,"13"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[chiado='Sim'])\" />\n",);
                else(!strcmp(first->next->next->value,"14"))
                   fprintf(paciente_xsl,"<xsl:variable name=\"contador\" select=\"count(doc/paciente[sint='Não'])\" />\n",);
			break;
		}
		/****************************************************************************************/
		
		fprintf(paciente_xsl,"<html>\n");
		fprintf(paciente_xsl,"<head>\n");
		fprintf(paciente_xsl,"<title>.:. Resultados da busca .:. Projeto Neural TB .:.</title>\n");
		fprintf(paciente_xsl,"<link rel=\"stylesheet\" href=\"../css/standart.css\" type=\"text/css\" />\n");
		fprintf(paciente_xsl,"</head>\n");
		fprintf(paciente_xsl,"<body>\n");
		fprintf(paciente_xsl,"<xsl:choose>\n");
		fprintf(paciente_xsl,"<xsl:when test=\"$contador != 0\">\n");
		fprintf(paciente_xsl,"<iframe name=\"iframeInvisivel\" height=\"0\" width=\"0\"></iframe>\n");

    	fprintf(paciente_xsl,"<xsl:for-each select=\"doc/paciente\">\n");

		/***** Associando o valor pego no formulario ao campo de ordenacao *****/
		switch(opt)
		{
			case 2: //Atributo nome
				orderValue = first->next->next->next->value;
			break;
			default: //Demais atributos
                orderValue = first->next->next->value;
		}
        if (!strcmp(orderValue, "id")) //verifica se o campo de ordenacao e idade
			fprintf(paciente_xsl,"<xsl:sort select=\"%s\" data-type=\"number\" order=\"descending\" />\n", orderValue);
		else
			fprintf(paciente_xsl,"<xsl:sort select=\"%s\" data-type=\"text\" />\n", orderValue);
		
/******************************************** FILTRANDO RESULTADOS DA BUSCA **********************************************************************************************************************************/
		switch(opt)
		{
   			case 2: //Atributo nome
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
            case 3: //atributo cidade
                if(!strcmp(first->next->next->value,"1"))
                   fprintf(paciente_xsl,"<xsl:if test=\"cidade='Curitiba / Paraná'\" />\n",);
                else if(!strcmp(first->next->next->value,"2"))
                   fprintf(paciente_xsl,"<xsl:if test=\"cidade='Fortaleza/Ceará'\" />\n",);
                else(!strcmp(first->next->next->value,"3"))
                   fprintf(paciente_xsl,"<xsl:if test=\"cidade='Itaboraí/RJ'\" />\n",);
            break;
			case 4: //atributo unidade
                if(!strcmp(first->next->next->value,"1"))
                   fprintf(paciente_xsl,"<xsl:if test=\"unidade='Programa Saúde Família'\" />\n",);
                else if(!strcmp(first->next->next->value,"2"))
                   fprintf(paciente_xsl,"<xsl:if test=\"unidade='Unidade Básica de Saúde'\" />\n",);
                else if(!strcmp(first->next->next->value,"3"))
                   fprintf(paciente_xsl,"<xsl:if test=\"unidade='Ambulatório - Posto de Saúde'\" />\n",);
                else if(!strcmp(first->next->next->value,"4"))
                   fprintf(paciente_xsl,"<xsl:if test=\"unidade='Unid Pronto Atendimento/Urgência/Emergência'\" />\n",);
                else if(!strcmp(first->next->next->value,"5"))
                   fprintf(paciente_xsl,"<xsl:if test=\"unidade='Unidade Hospitalar'\" />\n",);
                else(!strcmp(first->next->next->value,"6"))
                   fprintf(paciente_xsl,"<xsl:if test=\"unidade!='Outro'\" />\n",);
			break;
			case 5: //atributo tipo
                if(!strcmp(first->next->next->value,"1"))
                   fprintf(paciente_xsl,"<xsl:if test=\"cidade='Contato assintomático'\" />\n",);
                else if(!strcmp(first->next->next->value,"2"))
                   fprintf(paciente_xsl,"<xsl:if test=\"cidade='Sintomático Respiratório'\" />\n",);
                else if(!strcmp(first->next->next->value,"3"))
                   fprintf(paciente_xsl,"<xsl:if test=\"cidade='Caso Suspeito de Tuberculose Pulmonar'\" />\n",);
                else(!strcmp(first->next->next->value,"4"))
                   fprintf(paciente_xsl,"<xsl:if test=\"cidade!='outro'\" />\n",);
			break;
			case 6: //atributo numero cat-sus
                fprintf(paciente_xsl,"<xsl:if test=\"numfns='%s'\" />\n", first->next->value);
			break;
			case 7: //atributo prof. saude
                if(!strcmp(first->next->next->value,"sim"))
                   fprintf(paciente_xsl,"<xsl:if test=\"profsaude='Sim'\" />\n",);
                else
                   fprintf(paciente_xsl,"<xsl:if test=\"profsaude='Não'\" />\n",);

			break;
			case 8: //atributo sintomas
                if(!strcmp(first->next->next->value,"1"))
                   fprintf(paciente_xsl,"<xsl:if test=\"tosse='Sim'\" />\n",);
                else if(!strcmp(first->next->next->value,"2"))
                   fprintf(paciente_xsl,"<xsl:if test=\"catarr='Sim'\" />\n",);
                else if(!strcmp(first->next->next->value,"3"))
                   fprintf(paciente_xsl,"<xsl:if test=\"hempti='Sim'\" />\n",);
                else if(!strcmp(first->next->next->value,"4"))
                   fprintf(paciente_xsl,"<xsl:if test=\"hempto='Sim'\" />\n",);
                else if(!strcmp(first->next->next->value,"5"))
                   fprintf(paciente_xsl,"<xsl:if test=\"febre='Sim'\" />\n",);
                else if(!strcmp(first->next->next->value,"6"))
                   fprintf(paciente_xsl,"<xsl:if test=\"sudore='Sim'\" />\n",);
                else if(!strcmp(first->next->next->value,"7"))
                   fprintf(paciente_xsl,"<xsl:if test=\"hipore='Sim'\" />\n",);
                else if(!strcmp(first->next->next->value,"8"))
                   fprintf(paciente_xsl,"<xsl:if test=\"emagre='Sim'\" />\n",);
                else if(!strcmp(first->next->next->value,"9"))
                   fprintf(paciente_xsl,"<xsl:if test=\"asteni='Sim'\" />\n",);
                else if(!strcmp(first->next->next->value,"10"))
                   fprintf(paciente_xsl,"<xsl:if test=\"rouqui='Sim'\" />\n",);
                else if(!strcmp(first->next->next->value,"11"))
                   fprintf(paciente_xsl,"<xsl:if test=\"linfon='Sim'\" />\n",);
                else if(!strcmp(first->next->next->value,"12"))
                   fprintf(paciente_xsl,"<xsl:if test=\"dispn='Sim'\" />\n",);
                else if(!strcmp(first->next->next->value,"13"))
                   fprintf(paciente_xsl,"<xsl:if test=\"chiado='Sim'\" />\n",);
                else(!strcmp(first->next->next->value,"14"))
                   fprintf(paciente_xsl,"<xsl:if test=\"sint='Não'\" />\n",);
			break;
		}
/**************************************************************************************************************************************************************************************************/

fprintf(paciente_xsl,"<table width=\"600\" align=\"center\" cellspacing=\"1\" cellpadding=\"0\" id=\"xml\">\n");
fprintf(paciente_xsl,"<tr class=\"nome\">\n");
fprintf(paciente_xsl,"<td colspan=\"2\" align=\"center\" >\n");
fprintf(paciente_xsl,"No de Identificação: <xsl:value-of select =\"id\" /> \n");
fprintf(paciente_xsl,"</td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"nome\">\n");
fprintf(paciente_xsl,"<td width=\"100\" align=\"left\" >");
fprintf(paciente_xsl,"<img src=\"../imagens/setacima.jpg\"></img> \n");
fprintf(paciente_xsl,"<img src=\"../imagens/setabaixo.jpg\"></img>\n");
fprintf(paciente_xsl,"Nome: \n");
fprintf(paciente_xsl,"</td>\n");
fprintf(paciente_xsl,"<td > <xsl:value-of select =\"nome\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"forms\">\n");
fprintf(paciente_xsl,"<td colspan=\"2\">\n");
fprintf(paciente_xsl,"<img src=\"../imagens/setacima.jpg\"></img>\n");
fprintf(paciente_xsl,"<img src=\"../imagens/setabaixo.jpg\"></img>\n");
fprintf(paciente_xsl," - Entrevista \n");
fprintf(paciente_xsl,"</td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Cidade de Estudo:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"cidade\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<xsl:choose>\n");
fprintf(paciente_xsl,"<xsl:when test=\"cidade = Curitiba/Paraná\">");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Tipo de Unidade de Saúde:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"unidade2\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Tipo de participante:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"tipo2\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"</xsl:when>\n");
fprintf(paciente_xsl,"<xsl:otherwise>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Tipo de Unidade de Saúde:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"unidade\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Tipo de participante:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"tipo\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"</xsl:otherwise>\n");
fprintf(paciente_xsl,"</xsl:choose>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Entrevistador:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"entrevistador\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Categoria Profissional:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"categProf\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Data da Entrevista:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"diaEntr\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Local da Entrevista:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"local\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Supervisor:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"supervisor\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Data:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"dia\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Horário do início da entrevista:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"horaInicio\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"forms\">\n");
fprintf(paciente_xsl,"<td colspan=\"2\">\n");
fprintf(paciente_xsl,"<img src=\"../imagens/setacima.jpg\"></img>\n");
fprintf(paciente_xsl,"<img src=\"../imagens/setabaixo.jpg\"></img> \n");
fprintf(paciente_xsl,"1.  Caracterização Socioeconômica / Sócio-demográfica / Hábitos de Vida \n");
fprintf(paciente_xsl,"</td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Logradouro:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"logradouro\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Número:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"numero\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Estado:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"est\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Município:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"município\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Bairro:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"bairro\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >CEP:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"cep\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Telefone para contato:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"telefone\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Número do CAT-SUS:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"numfns\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Data de Nascimento:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"diaNasc\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Gênero:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"sexo\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Cor da pele:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"cor\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Situação conjugal:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"estciv\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Naturalidade - Estado:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"natest\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Naturalidade - Cidade:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"natmun\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Já morou em outro local diferente do município atual?</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"morout\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >No momento você está:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"funcao\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Profissional de Saúde:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"profsaude\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Grau de instrução do chefe da família:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"grinstrch\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Tem empregada mensalista em casa?</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"empregada\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Aspirador de pó:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"asppo\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Automóvel:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"auto\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Banheiro:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"banhei\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Freezer (ou duplex):</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"freezer\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Geladeira duplex:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"geldup\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Geladeira simples:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"gelsim\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Máqu. de lavar roupa:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"mlav\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Rádio:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"rad\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >TV em cores:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"tv\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Videocassete/DVD:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"video\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Foi morador de rua nos últimos 2 anos?</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"morrua\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Mora(ou) em asilos rua nos últimos 2 anos?</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"morasil\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Ex-detento?</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"presid\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Esteve internado nos últimos dois anos?</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"intern\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Que unidade de saúde você procura quando adoece?</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"qunis\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Conhece o agente de saúde do bairro?</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"agens\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Em relação ao hábito de fumar...:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"fumo\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Uso de drogas (inalatórias / injetáveis):</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"drogas\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Bebida alcoólica preferida:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"alcool\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Observações:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"observacoes\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"forms\">\n");
fprintf(paciente_xsl,"<td colspan=\"2\">\n");
fprintf(paciente_xsl,"<img src=\"../imagens/setacima.jpg\"></img>\n");
fprintf(paciente_xsl,"<img src=\"../imagens/setabaixo.jpg\"></img> \n");
fprintf(paciente_xsl," 2.Avaliação Inicial/Clínica do Contato/Sintomático Respiratório/Suspeito\n");
fprintf(paciente_xsl,"</td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Morou antes com alguém com tuberculose no pulmão, familiar ou não?</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"morou\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Teve (tem) alguém da família com tuberculose no pulmão?</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"familia\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Teve (tem) alguém do círculo de amizade/trabalho com tuberculose no pulmão?</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"circulo\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Tomou alguma vez estes remédios?</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"tipoqx\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Teve tuberculose no passado?</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"tbprev\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Resultado do tratamento notificado no SINAN</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"ressinan\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Cicatriz vacinal BCG?</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"cicbcg\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Tem falta de ar ou enfisema?</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"falta\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Tem asma ou bronquite?</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"asma\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Tem ou teve outros problemas de saúde?</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"psaude\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<xsl:if test=\"sint = Sim\">
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Tosse:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"tosse\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Catarro/Expectoração:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"catarr\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Sangue no catarro/Hemoptise:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"hempti\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Dor Torácica/dor no peito:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"hempto\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Febre:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"febre\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Suores à noite:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"sudore\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Falta de apetite:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"hipore\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Emagrecimento:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"emagre\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Peso anterior:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"pesokg1\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Peso atual:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"pesokg2\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Cansaço:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"asteni\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Rouquidão:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"rouqui\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Ínguas:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"linfon\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Falta de ar (Dispnéia):</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"dispn\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Chiado no peito:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"chiado\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Outros:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"ot\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"</xsl:if>
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Observações:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"obs\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Horário de encerramento da entrevista:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"horaenc\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Probabilidade de tuberculose pulmonar ativa pela enfermeira apenas com a avaliação médica de sinais de sintomas (história e exame físico):</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"probclin\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Condições da entrevista:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"condicao\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Colaboração do entrevistado:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"colaboracao\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Credibilidade das respostas na sua opinião:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"credibilidade\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"forms\">\n");
fprintf(paciente_xsl,"<td colspan=\"2\">\n");
fprintf(paciente_xsl,"<img src=\"../imagens/setacima.jpg\"></img>\n");
fprintf(paciente_xsl,"<img src=\"../imagens/setabaixo.jpg\"></img>\n");
fprintf(paciente_xsl," 3.Avaliação Complementar do Contato/Sintomático Respiratório/Suspeito\n");
fprintf(paciente_xsl,"</td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Sinais ao exame físico:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"sinaisExames\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<xsl:if test=\"cidade != Curitiba/Paraná\">\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Probabilidade de tuberculose pulmonar ativa com a avaliação de sinais de história + exame físico médico- PARA EQUIPE MÉDICA</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"probem\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"</xsl:if>
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Telerradiografia de tórax(PA e perfil) - Laudo:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"rxtor\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Data do exame:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"diaExame\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Área acometida:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"area\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<xsl:if test=\"cidade != Curitiba/Paraná\">
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Em caso de alta ou média probabilidade de TB ativa pela clínica:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"rxtam\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Em caso de baixa probabilidade de TB ativa pela clínica:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"rxbaix\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Probabilidade pelo médico de tuberculose pulmonar ativa com a avaliação complementar do RX:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"probrx\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"</xsl:if>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Data da leitura:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"diaLeit\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Leitor:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"leitor\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Amostra de trato respiratório inferior:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"amostri\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Baciloscopia (1ª amostra):</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"znescar1\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Baciloscopia (2ª amostra):</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"znescar2\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Probabilidade de tuberculose pulmonar ativa com a avaliação complementar do RX e de baciloscopia:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"prrxzn\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Cultura para micobactérias (1) - método:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"metodo1\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Cultura para micobactérias (2) - método:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"metodo2\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Outro exame (1):</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"exame1\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Outro exame (2):</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"exame2\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Outro exame (3):</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"exame3\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Outro exame (4):</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"exame4\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"forms\">
fprintf(paciente_xsl,"<td colspan=\"2\">
fprintf(paciente_xsl," <img src=\"../imagens/setacima.jpg\"></img>\n");
fprintf(paciente_xsl," <img src=\"../imagens/setabaixo.jpg\"></img>\n");
fprintf(paciente_xsl," 4.Acompanhamento\n");
fprintf(paciente_xsl,"</td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Desfecho do caso:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"desfecho\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Desfecho do caso diagnosticado como tuberculose:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"dtub\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Desfecho do caso diagnosticado como NÃO tuberculose:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"dntub\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Se apresentou diagnóstico posterior de tuberculose, onde?</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"aprtbp\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"par\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Data da última consulta/VD:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"diaUCons\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");
fprintf(paciente_xsl,"<tr class=\"impar\">\n");
fprintf(paciente_xsl,"<td align=\"left\" >Observações:</td>\n");
fprintf(paciente_xsl,"<td ><xsl:value-of select =\"observ\" /></td>\n");
fprintf(paciente_xsl,"</tr>\n");

        fprintf(paciente_xsl,"</xsl:if>\n");
		fprintf(paciente_xsl,"</xsl:for-each>\n");
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
		printf("xml.load(\"../xml/pacientes.xml\");\n");

		// Load XSL
		printf("var xsl = new ActiveXObject(\"Microsoft.XMLDOM\");\n");
		printf("xsl.async = false;\n");
		printf("xsl.load(\"../xml/buscaPaciente.xsl\");\n");

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




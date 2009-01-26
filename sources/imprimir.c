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

#define PATHFILE "../xml/imprimir.xsl"

int main (int argc, char **argv)
{
	FILE *xsl;
	
	char *username;
	char *pid;
	
	//CGI process
	
	cgi_init();
	cgi_process_form();
	username = cgi_param("uid");
	pid = cgi_param("pid");


	//XSL

	xsl = fopen(PATHFILE, "w");



fprintf ( xsl, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
fprintf ( xsl, "<xsl:stylesheet version=\"1.0\" xmlns:xsl=\"http://www.w3.org/1999/XSL/Transform\">\r\n");
fprintf ( xsl, "<xsl:template match=\"/doc\">\r\n");
fprintf ( xsl, "<html>\r\n");
fprintf ( xsl, "<head>\r\n");
fprintf ( xsl, "<title>.:. Projeto Neural TB .:.</title>\r\n");
fprintf ( xsl, "<link  rel=\"stylesheet\" type=\"text/css\" href=\"../css/standart.css\"/>\r\n");
fprintf ( xsl, "<script language=\"javascript\" src=\"../js/validacoes.js\"></script>\r\n");
fprintf ( xsl, "</head>\r\n");
fprintf ( xsl, "<body>\r\n");
fprintf ( xsl, "<table width=\"600\" align=\"center\" cellspacing=\"1\" cellpadding=\"0\" id=\"xml\">\r\n");
//fprintf ( xsl, "<xsl:if test=\"nome = '%s'\">\r\n", pid);
fprintf ( xsl, "<tr class=\"nome\">\r\n");
fprintf ( xsl, "	<td colspan=\"2\" align=\"center\" >\r\n");
//fprintf ( xsl, "           No de Identificação: <xsl:value-of select =\"paciente[%s]/id\" />\r\n", pid);
fprintf ( xsl, "           No de Identificação: %s \r\n", pid);
fprintf ( xsl, "    </td>\r\n");
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"nome\">\r\n");
fprintf ( xsl, "	<td width=\"100\" align=\"left\" >\r\n");
fprintf ( xsl, "<!--           <img src=\"../imagens/setacima.jpg\"></img> -->\r\n");
fprintf ( xsl, "<!--           <img src=\"../imagens/setabaixo.jpg\"></img> -->\r\n");
fprintf ( xsl, "           Nome:\r\n");
fprintf ( xsl, "    </td>\r\n");
fprintf ( xsl, "	<td > <xsl:value-of select =\"paciente[%s]/nome\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"forms\">\r\n");
fprintf ( xsl, "     <td colspan=\"2\">\r\n");
fprintf ( xsl, "<!--           <img src=\"../imagens/setacima.jpg\"></img> -->\r\n");
fprintf ( xsl, "<!--           <img src=\"../imagens/setabaixo.jpg\"></img> -->\r\n");
fprintf ( xsl, "            Entrevista\r\n");
fprintf ( xsl, "     </td>\r\n");
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "    <td align=\"left\" >Cidade de Estudo:</td>\r\n");
fprintf ( xsl, "    <td ><xsl:value-of select =\"paciente[%s]/cidade\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<xsl:choose>\r\n");
fprintf ( xsl, "  <xsl:when test=\"cidade = Curitiba/Paraná\">\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Tipo de Unidade de Saúde:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/unidade2\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Tipo de participante:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/tipo2\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "  </xsl:when>\r\n");
fprintf ( xsl, "  <xsl:otherwise>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Tipo de Unidade de Saúde:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/unidade\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Tipo de participante:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/tipo\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "  </xsl:otherwise>\r\n");
fprintf ( xsl, "</xsl:choose>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Entrevistador:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/entrevistador\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Categoria Profissional:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/categProf\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Data da Entrevista:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/diaEntr\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Local da Entrevista:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/local\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Supervisor:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/supervisor\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Data:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/dia\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Horário do início da entrevista:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/horaInicio\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"forms\">\r\n");
fprintf ( xsl, "     <td colspan=\"2\">\r\n");
fprintf ( xsl, "<!--           <img src=\"../imagens/setacima.jpg\"></img> -->\r\n");
fprintf ( xsl, "<!--           <img src=\"../imagens/setabaixo.jpg\"></img> -->\r\n");
fprintf ( xsl, "           1.  Caracterização Socioeconômica / Sócio-demográfica / Hábitos de Vida\r\n");
fprintf ( xsl, "     </td>\r\n");
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Logradouro:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/logradouro\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Número:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/numero\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Estado:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/est\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Município:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/município\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Bairro:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/bairro\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >CEP:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/cep\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Telefone para contato:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/telefone\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Número do CAT-SUS:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/numfns\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Data de Nascimento:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/diaNasc\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Gênero:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/sexo\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Cor da pele:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/cor\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Situação conjugal:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/estciv\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Naturalidade - Estado:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/natest\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Naturalidade - Cidade:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/natmun\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Já morou em outro local diferente do município atual?</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/morout\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >No momento você está:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/funcao\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Profissional de Saúde:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/profsaude\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Grau de instrução do chefe da família:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/grinstrch\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Tem empregada mensalista em casa?</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/empregada\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Aspirador de pó:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/asppo\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Automóvel:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/auto\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Banheiro:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/banhei\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Freezer (ou duplex):</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/freezer\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Geladeira duplex:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/geldup\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Geladeira simples:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/gelsim\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Máqu. de lavar roupa:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/mlav\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Rádio:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/rad\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >TV em cores:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/tv\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Videocassete/DVD:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/video\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Foi morador de rua nos últimos 2 anos?</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/morrua\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Mora(ou) em asilos rua nos últimos 2 anos?</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/morasil\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Ex-detento?</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/presid\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Esteve internado nos últimos dois anos?</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/intern\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Que unidade de saúde você procura quando adoece?</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/qunis\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Conhece o agente de saúde do bairro?</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/agens\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Em relação ao hábito de fumar...:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/fumo\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Carga tabágica:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/cargtab\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Uso de drogas (inalatórias / injetáveis):</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/drogas\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Bebida alcoólica preferida:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/alcool\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<xsl:if test=\"qbebida0 = Sim\">\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Você tem facilidade de fazer amizades?</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/qbebida0\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "</xsl:if>\r\n");
fprintf ( xsl, "<xsl:if test=\"qbebida1 = Sim\">\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Alguma vez sentiu que deveria diminuir a quantidade da bebida?</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/qbebida0\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "</xsl:if>\r\n");
fprintf ( xsl, "<xsl:if test=\"qbebida2 = Sim\">\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Alguém critica ou já criticou o seu modo de beber?</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/qbebida0\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "</xsl:if>\r\n");
fprintf ( xsl, "<xsl:if test=\"qbebida3 = Sim\">\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Você costuma beber de manhã para diminuir o nervosismo/ressaca?</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/qbebida0\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "</xsl:if>\r\n");
fprintf ( xsl, "<xsl:if test=\"qbebida4 = Sim\">\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Você se sente culpado pela maneira que costuma beber?</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/qbebida0\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "</xsl:if>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Observações:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/observacoes\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"forms\">\r\n");
fprintf ( xsl, "      <td colspan=\"2\">\r\n");
fprintf ( xsl, "<!--            <img src=\"../imagens/setacima.jpg\"></img> -->\r\n");
fprintf ( xsl, "<!--            <img src=\"../imagens/setabaixo.jpg\"></img> -->\r\n");
fprintf ( xsl, "           2.	Avaliação Inicial/Clínica do Contato/Sintomático Respiratório/Suspeito\r\n");
fprintf ( xsl, "      </td>\r\n");
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Morou antes com alguém com tuberculose no pulmão, familiar ou não?</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/morou\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Teve (tem) alguém da família com tuberculose no pulmão?</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/familia\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Teve (tem) alguém do círculo de amizade/trabalho com tuberculose no pulmão?</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/circulo\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Tomou alguma vez estes remédios?</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/tipoqx\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Teve tuberculose no passado?</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/tbprev\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Resultado do tratamento notificado no SINAN</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/ressinan\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Cicatriz vacinal BCG?</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/cicbcg\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Tem falta de ar ou enfisema?</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/falta\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Tem asma ou bronquite?</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/asma\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Tem ou teve outros problemas de saúde?</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/psaude\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<xsl:if test=\"sint = Sim\">\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Tosse:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/tosse\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Catarro/Expectoração:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/catarr\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Sangue no catarro/Hemoptise:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/hempti\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Dor Torácica/dor no peito:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/hempto\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Febre:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/febre\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Suores à noite:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/sudore\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Falta de apetite:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/hipore\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Emagrecimento:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/emagre\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Peso anterior:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/pesokg1\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Peso atual:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/pesokg2\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Cansaço:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/asteni\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Rouquidão:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/rouqui\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Ínguas:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/linfon\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Falta de ar (Dispnéia):</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/dispn\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Chiado no peito:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/chiado\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Outros:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/ot\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "</xsl:if>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Observações:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/obs\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Horário de encerramento da entrevista:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/horaenc\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Probabilidade de tuberculose pulmonar ativa pela enfermeira apenas com a avaliação médica de sinais de sintomas (história e exame físico):</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/probclin\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Condições da entrevista:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/condicao\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Colaboração do entrevistado:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/colaboracao\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Credibilidade das respostas na sua opinião:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/credibilidade\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"forms\">\r\n");
fprintf ( xsl, "      <td colspan=\"2\">\r\n");
fprintf ( xsl, "<!--            <img src=\"../imagens/setacima.jpg\"></img> -->\r\n");
fprintf ( xsl, "<!--            <img src=\"../imagens/setabaixo.jpg\"></img> -->\r\n");
fprintf ( xsl, "           3.	Avaliação Complementar do Contato/Sintomático Respiratório/Suspeito\r\n");
fprintf ( xsl, "      </td>\r\n");
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Sinais ao exame físico:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/sinaisExames\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<xsl:if test=\"cidade != Curitiba/Paraná\">\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Probabilidade de tuberculose pulmonar ativa com a avaliação de sinais de história + exame físico médico- PARA EQUIPE MÉDICA</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/probem\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "</xsl:if>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Telerradiografia de tórax(PA e perfil) - Laudo:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/rxtor\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Data do exame:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/diaExame\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Área acometida:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/area\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<xsl:if test=\"cidade != Curitiba/Paraná\">\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Em caso de alta ou média probabilidade de TB ativa pela clínica:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/rxtam\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Em caso de baixa probabilidade de TB ativa pela clínica:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/rxbaix\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Probabilidade pelo médico de tuberculose pulmonar ativa com a avaliação complementar do RX:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/probrx\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "</xsl:if>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Data da leitura:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/diaLeit\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Leitor:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/leitor\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Amostra de trato respiratório inferior:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/amostri\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Baciloscopia (1ª amostra):</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/znescar1\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Baciloscopia (2ª amostra):</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/znescar2\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Probabilidade de tuberculose pulmonar ativa com a avaliação complementar do RX e de baciloscopia:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/prrxzn\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Cultura para micobactérias (1) - método:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/metodo1\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Cultura para micobactérias (2) - método:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/metodo2\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Outro exame (1):</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/exame1\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Outro exame (2):</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/exame2\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Outro exame (3):</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/exame3\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Outro exame (4):</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/exame4\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"forms\">\r\n");
fprintf ( xsl, "      <td colspan=\"2\">\r\n");
fprintf ( xsl, "<!--           <img src=\"../imagens/setacima.jpg\"></img> -->\r\n");
fprintf ( xsl, "<!--           <img src=\"../imagens/setabaixo.jpg\"></img> -->\r\n");
fprintf ( xsl, "           4.	Acompanhamento\r\n");
fprintf ( xsl, "      </td>\r\n");
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Desfecho do caso:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/desfecho\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Desfecho do caso diagnosticado como tuberculose:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/dtub\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Desfecho do caso diagnosticado como NÃO tuberculose:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/dntub\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Se apresentou diagnóstico posterior de tuberculose, onde?</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/aprtbp\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"par\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Data da última consulta/VD:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/diaUCons\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
fprintf ( xsl, "<tr class=\"impar\">\r\n");
fprintf ( xsl, "	<td align=\"left\" >Observações:</td>\r\n");
fprintf ( xsl, "	<td ><xsl:value-of select =\"paciente[%s]/observ\" /></td>\r\n", pid);
fprintf ( xsl, "</tr>\r\n");
//fprintf ( xsl, "</xsl:if>\r\n");
fprintf ( xsl, "</table>\r\n");
fprintf ( xsl, "</body>\r\n");
fprintf ( xsl, "</html>\r\n");
fprintf ( xsl, "</xsl:template>\r\n");
fprintf ( xsl, "</xsl:stylesheet>\r\n");


fclose(xsl);

	
//RESULTADO

	cgi_init_headers();

	printf("<html>\n");
	printf("<head>\n");
	printf("\t<title>Versão de Impressão:%s</title>\n", pid);
 
	printf("\
	<script>\n\
		function loadXMLDoc(fname)\n\
		{\n\
			var xmlDoc;\n\
			\n\
			// code for IE\n\
			if (window.ActiveXObject)\n\
			{\n\
				xmlDoc = new ActiveXObject(\"Microsoft.XMLDOM\");\n\
			}\n\
			\n\
			// code for Mozilla, Firefox, Opera, etc.\n\
			else if (document.implementation && document.implementation.createDocument)\n\
			{\n\
				xmlDoc = document.implementation.createDocument(\"\",\"\",null);\n\
			}\n\
			else\n\
			{\n\
				alert('O seu navegador n&atilde;o tem suporte a este script');\n\
			}\n\
			xmlDoc.async = false;\n\
			xmlDoc.load(fname);\n\
			return(xmlDoc);\n\
		}\n\
		\n\
		function displayResult()\n\
		{\n\
			xml = loadXMLDoc(\"../xml/pacientes.xml\");\n\
			xsl = loadXMLDoc(\"../xml/imprimir.xsl\");\n\
			\n\
			// code for IE\n\
			if (window.ActiveXObject)\n\
			{\n\
				x = xml.transformNode(xsl);\n\
				document.getElementById(\"result\").innerHTML = x;\n\
			}\n\
			\n\
			// code for Mozilla, Firefox, Opera, etc.\n\
			else if (document.implementation && document.implementation.createDocument)\n\
			{\n\
				xsltProcessor = new XSLTProcessor();\n\
				xsltProcessor.importStylesheet(xsl);\n\
				resultDocument = xsltProcessor.transformToFragment(xml,document);\n\
				document.getElementById(\"result\").appendChild(resultDocument);\n\
			}\n\
		}\n\
	</script>\n");






	printf("</head>\n");
	printf("<body id=\"result\" onLoad=\"displayResult(), window.print()\">\n");
	printf("</body>\n");
	printf("</html>");

	cgi_end();
	
	return 0;
}

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/* $RCSfile$ */

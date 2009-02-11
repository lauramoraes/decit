#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "const.h"

#define OK 0


typedef struct chain
{
	char *option;
	char *value;
	struct chain *next;
} chainType;

int main (void)
{
	

	char *queryString;
	char *paciente, *uid;

	if(!(queryString = getenv("QUERY_STRING")))
	{

		printf("Content-type: text/html\n\n");
		printf("<html>\n");
		printf("<head>\n");
		printf("<title>Resultado</title>\n");
		printf("</head>\n");
		printf("<body>\n");
		printf("Erro ao repassar os argumentos");
		printf("</body>\n");
		printf("</html>\n");
		exit(OK);
	}

	paciente=(char*)malloc(sizeof(char));
	
	if(!paciente)
	{
		printf("Content-type: text/html\n\n");
		printf("<html>\n");
		printf("<head>\n");
		printf("<title>Resultado</title>\n");
		printf("</head>\n");
		printf("<body>\n");
		printf("Erro ao alocar memória");
		printf("</body>\n");
		printf("</html>");
		exit(OK);
	}
	if(strcmp("paciente",strsep(&queryString,"=")))
	{
		printf("Content-type: text/html\n\n");
		printf("<html>\n");
		printf("<head>\n");
		printf("<title>Resultado</title>\n");
		printf("</head>\n");
		printf("<body>\n");
		printf("Erro: sem numero de paciente");
		printf("</body>\n");
		printf("</html>");
		exit(OK);
	}

	paciente = strsep(&queryString,"&");
	
	if(strcmp("uid",strsep(&queryString,"=")))
	{
		printf("Content-type: text/html\n\n");
		printf("<html>\n");
		printf("<head>\n");
		printf("<title>Resultado</title>\n");
		printf("</head>\n");
		printf("<body>\n");
		printf("Erro: sem numero de usuário");
		printf("</body>\n");
		printf("</html>");
		exit(OK);
	}
	
	uid = strsep(&queryString,"\0");

	printf("Content-type: text/html\n\n");
	printf("<html>\n");
	printf("<head>\n");
	printf("<title>.:. Neural TB .:. Motivo da exclusão</title>\n");
        printf("<meta http-equiv=\"content-type\" content=\"text/html; charset=UTF-8\">");
	printf("<script language=\"javascript\" src=\"../js/motivo.js\" charset=\"UTF-8\"></script>\n");
	printf("<script language=\"javascript\" src=\"../js/xml.js\" charset=\"UTF-8\"></script>\n");
	printf("</head>\n");
	printf("<body>\n");
	printf("<table height=\"120\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">\n");
    printf("<tr bgcolor=\"#CCCCCC\">\n");
	printf("<td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</td>");
	printf("<td><b><u><font size=\"5\">Menu</font></u></b></td>\n");
	printf("<td>&nbsp;</td>\n");
    printf("</tr>\n");
    printf("<tr bgcolor=\"#CCCCCC\">");
    printf("<td>&nbsp;</td>");
    printf("<td width=\"100%c\">",37);
	printf("<a href=\"formulario.cgi?uid=%s\">Adicionar Paciente</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n", uid);
	printf("<a href=\"busca.cgi?uid=%s\">Buscar/Editar/Remover</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;", uid);
	printf("<a href=\"backup.cgi\"> Back-up</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
	printf("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
    printf("<a href=\"principal.cgi?uid=%s\">P&aacute;gina principal</a>\n", uid);
	printf("</td>\n");
    printf("<td></td>\n");
    printf("</tr>\n");
    printf("<tr bgcolor=\"#CCCCCC\">");
    printf("<td>&nbsp;</td>\n");
    printf("<td>\n");
    printf("<a href=\"exibirPacientes.cgi?uid=%s\">Exibir question&aacute;rios</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n", uid);
    printf("<a href=\"exibirRecusa.cgi?uid=%s\">Exibir recusas</a>\n", uid);
    printf("</td>\n");
    printf("<td></td>\n");
    printf("</tr>\n");
    printf(" </table>\n");
	printf("<p></p>\r\n");
	printf("<div align='center'>\n");
	printf("<form name = \"motivoRemove\" method = \"post\" action = \"%s\" onSubmit=\"return validarCampoMotivo(motivo)\">\n",REMOVER_CGI);
	printf("<input type = \"hidden\" name=\"uid\" value = \"%s\">\n",uid);
	//printf("<table align = \"center\">\n");
	//printf("<tr>\n");
	//printf("<td align=\"center\">Para continuar digite o motivo do apagamento do paciente <b>%s</b></td>\n",paciente);
	printf("<p><h3>Para continuar digite o motivo da remoção do paciente: <b><span id='nomePaciente'></span></b></h3></p>\n");
	printf("<p><h3>Data de nascimento:<b><span id='dataNasc'></span></b></h3></p>\n");
	printf("<input type = \"hidden\" name=\"pacienteNumero\" value = \"%s\">\n",paciente);
	printf("<input type = \"hidden\" name=\"diaNasc\" value = \"\">\n");
	printf("<input type = \"hidden\" name=\"mesNasc\" value = \"\">\n");
	printf("<input type = \"hidden\" name=\"anoNasc\" value = \"\">\n");
	printf("<script>var xmlDoc = loadXMLDoc('../xml/pacientes.xml');\n");
	printf("document.getElementById(\"nomePaciente\").innerHTML = xmlDoc.getElementsByTagName(\"paciente\")[%s-1].getElementsByTagName(\"nome\")[0].childNodes[0].nodeValue;\n",paciente,paciente,paciente);
	printf("dataNascimento = xmlDoc.getElementsByTagName(\"paciente\")[%s-1].getElementsByTagName(\"diaNasc\")[0].childNodes[0].nodeValue + '/' + xmlDoc.getElementsByTagName(\"paciente\")[%s-1].getElementsByTagName(\"mesNasc\")[0].childNodes[0].nodeValue + '/' + xmlDoc.getElementsByTagName(\"paciente\")[%s-1].getElementsByTagName(\"anoNasc\")[0].childNodes[0].nodeValue\n",paciente,paciente,paciente);
	printf("document.getElementById(\"dataNasc\").innerHTML = dataNascimento\n");
	printf("document.getElementsByName(\"diaNasc\")[0].value = xmlDoc.getElementsByTagName(\"paciente\")[%s-1].getElementsByTagName(\"diaNasc\")[0].childNodes[0].nodeValue\n",paciente);
	printf("document.getElementsByName(\"mesNasc\")[0].value = xmlDoc.getElementsByTagName(\"paciente\")[%s-1].getElementsByTagName(\"mesNasc\")[0].childNodes[0].nodeValue\n",paciente);
	printf("document.getElementsByName(\"anoNasc\")[0].value = xmlDoc.getElementsByTagName(\"paciente\")[%s-1].getElementsByTagName(\"anoNasc\")[0].childNodes[0].nodeValue</script>\n",paciente);
	//printf("</tr>\n");
	//printf("<tr>\n");
	//printf("<td align = \"left\">motivo:</td>\n");
	printf("<p>Motivo:</p>\n");
	//printf("<td> <TEXTAREA COLS=50 ROWS=6 name = \"motivo\" MAXLENGTH=500 onFocus=\"this.className = 'CSS_FOCUS_IN'\" onblur=\"validarCampoMotivo(this);  this.className = 'CSS_FOCUS_OUT';\"></TEXTAREA></td>\n");
	printf("<p><TEXTAREA COLS=50 ROWS=6 name = \"motivo\" MAXLENGTH=500 onFocus=\"this.className = 'CSS_FOCUS_IN'\" onblur=\"validarCampoMotivo(this);  this.className = 'CSS_FOCUS_OUT';\"></TEXTAREA></p>\n");
	//printf("</tr>\n");
	//printf("<tr>\n");
	//printf("<td><a href = \"%s\">Voltar</a></td>\n",BUSCA_CGI);
	printf("<a href = \"%s?uid=%s\">Voltar</a>&nbsp;&nbsp;&nbsp;&nbsp;\n",BUSCA_CGI,uid);
	//printf("<td><input type = \"submit\" value = \"remover\"</td>\n");
	printf("<input type = \"submit\" value = \"Remover\"/>\n");
	//printf("</tr>\n");
	//printf("</table>\n");
	printf("</form>\n");
	printf("</body>\n");
	printf("</html>\n");
	exit(OK);
}

/* Arquivo para o projeto NeuralTB
     Universidade Federal do Rio de Janeiro
     Escola Politecnica
     Departamento de Engenharia Eletronica e de Computacao
	
     Laboratorio de Processamento de Sinais
	
     Autor: Luiz Evora
     Atualizacao: Laura de Oliveira Fernandes Moraes
     Ultima atualizacao: 28/10/2008 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

#define OK 0

typedef struct chain
{
	char *attribute;
	char *value;
	struct chain *next;
} chainType;

void errorMsgCgi(char *title, char*msg)
{
    printf("Content-type: text/html\n\n");
	printf("<html>\n");
	printf("<head>\n");
	printf("<title>%s</title>\n",title);
	printf("</head>\n");
	printf("<body>\n");
	printf("%s",msg);
	printf("</body>\n");
	printf("</html>\n");
}


int main (void)
{
	FILE *xml,*xml_temp;
    	unsigned x,y;
	double contentLength;
	char* temp1;
	char* temp2;
	char temp[1024];
	char originalString[10240];
	char processedString[10240];
//	char test[14000];
	char hexa[3];
	const char *length;
	chainType *form, *aux, *first;
	int aceitou, curitiba;
	char *uid;

//	printf("Content-type: text/html\n\n");
//		printf("<html>\n");
//		printf("<head>\n");
//		printf("<title>Resultado</title>\n");
//		printf("</head>\n");
//		printf("<body>\n");
//	printf("%s\n",getenv("CONTENT_LENGTH"));
    	if(!(length= getenv("CONTENT_LENGTH"))) //verifica se string lida é null
	{

		printf("Content-type: text/html\n\n");
		printf("<html>\n");
		printf("<head>\n");
		printf("<title>Resultado</title>\n");
		printf("</head>\n");
		printf("<body>\n");
		printf("erro ao repassar os argumentos");
		printf("</body>\n");
		printf("</html>\n");
		exit(OK);
	}
//		printf("%s\n",length);
		
//	printf("fim %s\n",length);

	//converte string com o tamanho em long int
	contentLength=strtol(length, NULL, 10);
    	//le linha das informacoes 1 vez com o tamanho de contentLength do stdin
    	//e armazena em originalString
    	//fread(test, contentLength, 1, stdin);
	//	printf("%s\n",test);
    	fread(originalString, contentLength, 1, stdin);
	//	printf("%s\n",originalString);
	//	printf("</body\n");
	//	printf("</html");
	//	exit(OK);
//	printf("%s\n",originalString);
    
    	//le char por char da url substituindo os carac especiais
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
	
	//pega a stringprecessada e separa os campos//
	temp1 = (char*)&processedString;
	aux = (chainType*)malloc(sizeof(chainType));
	first = (chainType*)malloc(sizeof(chainType));
	aux=first=NULL;
	
	for (temp2=strsep(&temp1,"&"); temp2!=NULL; temp2=strsep(&temp1,"&"))
	{
        	form = (chainType*)malloc(sizeof(chainType));
		form->attribute=strsep(&temp2,"=");
		form->value=strsep(&temp2,"\0");

		//Descobrindo se o paciente recusou ou aceitou
		if(strcmp(form->attribute,"situacao")==OK) {
            		if(strcmp(form->value,"aceitou")==OK)  aceitou=1;
            		else aceitou=2;
		}
		//Descobrindo se o paciente preencheu o formulário de Curitiba ou não
		if(strcmp(form->attribute,"cidade") == OK)  {
                	if(!strcmp(form->value,"Curitiba/Paraná"))  curitiba = 1;
			else curitiba = 0;
		}
		if (aux == NULL)
			first = form;
		else
			aux->next = form;

		aux = form;
	}

	form->next = NULL;

	if(!form)
	{
		printf("Content-type: text/html\n\n");
		printf("<html>\n");
		printf("<head>\n");
		printf("<title>Resultado</title>\n");
		printf("</head>\n");
		printf("<body>\n");
		printf("Erro");
		printf("</body>\n");
		printf("</html>");
		exit(OK);
	}
	//Recupera o login do usuário
	uid = first->value;
	first= first->next;

///////////////////////ve se existe arquivo pacientes.xml///////////////////////
	if (aceitou == 1)
	{
		if ((xml=fopen("../xml/pacientes.xml", "r")) == NULL)
		{
			xml = fopen("../xml/pacientes.xml", "w");
			fprintf(xml, "<?xml version=\"1.0\" encoding=\"iso-8859-1\"?>\n");		
			fprintf(xml, "<doc>\n");
			fprintf(xml, "    <paciente>\n");
			for (aux=first; aux!=NULL; aux=aux->next)
			{
				//Não repassar os campos que não são preenchidos em curitiba
				if ((curitiba == 1) && ((!strcmp(aux->attribute, "numfns")) || (!strcmp(aux->attribute, "sint")) || (!strcmp(aux->attribute, "sinaisExames")) || (!strcmp(aux->attribute, "probem")) || (!strcmp(aux->attribute,  "rxtam")) || (!strcmp(aux->attribute,  "rxtam1")) || (!strcmp(aux->attribute,  "rxbaix")) || (!strcmp(aux->attribute, "probrx"))));

				//Não repassar os campos que são preenchidos somente em Curitiba
				else if ((curitiba != 1) && ((!strcmp(aux->attribute,  "horaColeta1")) || (!strcmp(aux->attribute,  "minutoColeta1")) || (!strcmp(aux->attribute,  "minutoColeta2")) ||(!strcmp(aux->attribute,  "horaColeta2"))));

				//Caso o valor seja "outro" repassar o valor do próximo campo (o especificado)
				else if (!strcmp(aux->value,  "outro"))
				{
					fprintf(xml, "      <%s>%s</%s>\n",aux->attribute,aux->next->value,aux->attribute);
                       			aux=aux->next;
				}

				else
				fprintf(xml, "      <%s>%s</%s>\n",aux->attribute,aux->value,aux->attribute);
			}
    			fprintf(xml, "    </paciente>\n");
			fprintf(xml, "</doc>");
			fclose(xml);
		}
		else
		{
			xml_temp = fopen("../xml/pacientesTemp.xml", "w");
			fgets(temp, 1024, xml);
			while(strstr(temp, "</doc>") == 0)
			{
				fputs(temp, xml_temp);
				fgets(temp, 1024, xml);	
			}
			fprintf(xml_temp, "    <paciente>\n");
			for (aux=first; aux!=NULL; aux=aux->next)
			{
				//Não repassar os campos que não são preenchidos em curitiba
				if ((curitiba == 1) && ((!strcmp(aux->attribute, "numfns")) || (!strcmp(aux->attribute, "sint")) || (!strcmp(aux->attribute, "sinaisExames")) || (!strcmp(aux->attribute, "probem")) || (!strcmp(aux->attribute,  "rxtam")) || (!strcmp(aux->attribute,  "rxtam1")) || (!strcmp(aux->attribute,  "rxbaix")) || (!strcmp(aux->attribute, "probrx"))));

				//Não repassar os campos que são preenchidos somente em Curitiba
				else if ((curitiba != 1) && ((!strcmp(aux->attribute,  "horaColeta1")) || (!strcmp(aux->attribute,  "minutoColeta1")) || (!strcmp(aux->attribute,  "minutoColeta2")) || (!strcmp(aux->attribute,  "horaColeta2"))));

				//Caso o valor seja "outro" repassar o valor do próximo campo (o especificado)
				else if (!strcmp(aux->value,  "outro"))
				{
					fprintf(xml_temp, "      <%s>%s</%s>\n",aux->attribute,aux->next->value,aux->attribute);
                       			aux=aux->next;
				}

				else
				fprintf(xml_temp, "      <%s>%s</%s>\n",aux->attribute,aux->value,aux->attribute);
			}
	    		fprintf(xml_temp, "    </paciente>\n");
			fprintf(xml_temp, "</doc>");
			fclose(xml);
			fclose(xml_temp);
			remove("../xml/pacientes.xml");
			rename("../xml/pacientesTemp.xml","../xml/pacientes.xml");
		}
	}
	//Se o paciente recusou
	else
	{
		if ((xml=fopen("../xml/recusa.xml", "r")) == NULL)
	  	{
        		xml = fopen("../xml/recusa.xml", "w");
			fprintf(xml, "<?xml version=\"1.0\" encoding=\"iso-8859-1\"?>\n");
			fprintf(xml, "<?xml-stylesheet type=\"text/xsl\" href=\"recusa.xsl\"?>\n");
			fprintf(xml, "<doc>\n");
			fprintf(xml, "    <paciente>\n");
			for (aux=first; aux!=NULL; aux=aux->next)
			{
				//Caso o valor seja "outro" repassar o valor do próximo campo (o especificado)
				if (!strcmp(aux->value, "outro"))
				{
					fprintf(xml, "      <%s>%s</%s>\n",aux->attribute,aux->next->value,aux->attribute);
                       			aux=aux->next;
				}
            			else if((!strcmp(aux->attribute,"cidade")) || (!strcmp(aux->attribute,"unidade")) || (!strcmp(aux->attribute,"unidadeCurit")) ||(!strcmp(aux->attribute,"recusa")) || (!strcmp(aux->attribute,"recusaCurit")) || (!strcmp(aux->attribute,"recusa")) || (!strcmp(aux->attribute,"idade")) || (!strcmp(aux->attribute,"sexo1")) || (!strcmp(aux->attribute,"tem")) || (!strcmp(aux->attribute,"motivo")))
                			fprintf(xml, "      <%s>%s</%s>\n",aux->attribute,aux->value,aux->attribute);
     			}
        		fprintf(xml, "    </paciente>\n");
			fprintf(xml, "</doc>");
			fclose(xml);
      		}
      		else
      		{
        		xml_temp = fopen("../xml/pacientesTemp.xml", "w");
			fgets(temp, 1024, xml);
			while(strstr(temp, "</doc>") == 0)
			{
				fputs(temp, xml_temp);
				fgets(temp, 1024, xml);
			}
        		fprintf(xml_temp, "    <paciente>\n");
			for (aux=first; aux!=NULL; aux=aux->next)
			{
				//Caso o valor seja "outro" repassar o valor do próximo campo (o especificado)
            			if (!strcmp(aux->value, "outro"))
				{
					fprintf(xml_temp, "      <%s>%s</%s>\n",aux->attribute,aux->next->value,aux->attribute);
                       			aux=aux->next;
				}
            			else if((!strcmp(aux->attribute,"cidade")) || (!strcmp(aux->attribute,"unidade")) || (!strcmp(aux->attribute,"unidadeCurit")) || (!strcmp(aux->attribute,"recusa")) || (!strcmp(aux->attribute,"recusaCurit")) || (!strcmp(aux->attribute,"idade")) || (!strcmp(aux->attribute,"sexo1")) || (!strcmp(aux->attribute,"tem")) || (!strcmp(aux->attribute,"motivo")))
                			fprintf(xml_temp, "      <%s>%s</%s>\n",aux->attribute,aux->value,aux->attribute);

			}
        		fprintf(xml_temp, "    </paciente>\n");
			fprintf(xml_temp, "</doc>");
        		fclose(xml);
			fclose(xml_temp);
			remove("../xml/recusa.xml");
        		rename("../xml/pacientesTemp.xml","../xml/recusa.xml");
      		}
	}

	printf("Content-type: text/html\n\n");
    	printf("<html>\n");
	printf("<head>\n");
	printf("<title>Formulário adicionado</title>\n");	
	printf("</head>\n");
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
	printf("<a href=\"formulario.cgi?uid=%s\">Adicionar Paciente</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n", uid);
	printf("<a href=\"busca.cgi?uid=%s\">Buscar/Editar/Remover</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;", uid);
	printf("<a href=\"backup.cgi\"> Back-up</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
	printf("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
        printf("<a href=\"principal.cgi?uid=%s\">Página principal</a>\n", uid);
	printf("</td>\n");
        printf("<td></td>\n");
        printf("</tr>\n");
        printf("<tr bgcolor=\"#CCCCCC\">");
        printf("<td>&nbsp;</td>\n");
        printf("<td>\n");
        printf("<a href=\"exibirPacientes.cgi?uid=%s\">Exibir questionários</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n", uid);
        printf("<a href=\"exibirRecusa.cgi?uid=%s\">Exibir recusas</a>\n", uid);
        printf("</td>\n");
        printf("<td></td>\n");
        printf("</tr>\n");
        printf(" </table>\n");
	printf("<div align=center>Paciente inserido!</div><br><br>\n");
    printf("<script type=\"text/javascript\">\n");
	printf("var xml=null\n");
	printf("var xsl=null\n");
	printf("if (window.ActiveXObject)\n");
	printf("{\n");

/////////////////////// load xml ///////////////////////

	printf("xml = new ActiveXObject(\"Microsoft.XMLDOM\");\n");
	printf("xml.async = false;\n");
    printf("xml.load(\"../xml/paciente.xml\");\n");

/////////////////////// load xsl ///////////////////////

	printf("xsl = new ActiveXObject(\"Microsoft.XMLDOM\");\n");
	printf("xsl.async = false;\n");
	printf("xsl.load(\"../xml/paciente.xsl\");\n");

/////////////////////// show xhtml ///////////////////////

    printf("document.write(xml.transformNode(xsl));\n");
	printf("}\n");
	printf("else if (document.implementation.createDocument)\n");
	printf("{\n");

/////////////////////// load xml ///////////////////////

	printf("xml = document.implementation.createDocument(\"\",\"\",null);\n");
	printf("xml.async = false;\n");
    printf("xml.load(\"../xml/paciente.xml\");\n");

/////////////////////// load xsl ///////////////////////

	printf("xsl = document.implementation.createDocument(\"\",\"\",null);\n");
	printf("xsl.async = false;\n");
    printf("xsl.load(\"../xsl/pacienteAdicionado.xsl\");\n");
	printf("}\n");
	printf("else\n");
	printf("{\n");
	printf("alert(\'Your browser cannot handle this script\');\n");
	printf("}\n");
	
	printf("</script>\n");
    printf("</body>\n");
	printf("</html>");



	for (aux=form=first; aux!=NULL; form=aux)
	{
		aux = form->next;
		free (form);
	}
	exit(OK);
}

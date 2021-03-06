#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <libxml/tree.h>
#include <libxml/xmlsave.h>
#include "const.h"

#define OK 0
#define MEDIC "médico"

int getFullDataParts(char hour[3],char minute[3], char second[5],char day[3],char month[3],char year[5])
{
	time_t rawtime;
	struct tm *timeinfo;

	time(&rawtime);
	timeinfo = localtime ( &rawtime );

	if(!strftime(day,3,"%d",timeinfo))
		return(1);
	if(!strftime(month,3,"%m",timeinfo))
		return(2);
	if(!strftime(year,5,"%Y",timeinfo))
		return(3);
	if(!strftime(hour,3,"%H",timeinfo))
		return(4);
	if(!strftime(minute,3,"%M",timeinfo))
		return(5);
	if(!strftime(second,3,"%S",timeinfo))
		return(6);
	return(0);
}

typedef struct chain
{
	char *attribute;
	char *value;
	struct chain *next;
} chainType;

int main (void)
{
//	char *queryString;
	FILE *test;
	unsigned x,y;
	double contentLength;
	char* temp1;
	char* temp2;
//	int naoAchado=0;
//	char temp[1024];
	char originalString[10240];
	char processedString[10240];
	char hexa[3];
	const char *length;
	chainType *form, *aux, *first;
	char *uid;
	long long unsigned int i=1;
	xmlChar* version= "1.0";
	
//	char *paciente;
	xmlDoc *doc = NULL;
	xmlDoc *docNew = NULL;
	xmlNode *root_element = NULL;
	xmlNode *root_element_new = NULL;
	xmlNode *currently;
	xmlNode *patientFound;
//	xmlNode *info;
	//xmlNode *removed;
	xmlNode *extracted;

//	char hour[3],minute[3],second[3],day[3],month[3],year[5];

	if(!(length= getenv("CONTENT_LENGTH"))) //verifica se string lida é null
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

	//converte string com o tamanho em long int
	contentLength=strtol(length, NULL, 10);
    //le linha das informacoes 1 vez com o tamanho de contentLength do stdin
    //e armazena em originalString
    fread(originalString, contentLength, 1, stdin);
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

	
	/* pega a stringprecessada e separa os campos **
	** &atributo=valor"\0" */

	temp1 = (char*)&processedString;
	aux = (chainType*)malloc(sizeof(chainType));
	first = (chainType*)malloc(sizeof(chainType));
	aux=first=NULL;

//	paciente=(char*)malloc(sizeof(char));
/*
		printf("Content-type: text/html\n\n");
		printf("<html>\n");
		printf("<head>\n");
		printf("<title>Resultado</title>\n");
		printf("</head>\n");
		printf("<body>\n");
		printf("%s",temp1);
		printf("</body>\n");
		printf("</html>");
		exit(OK);
*/
	for (temp2=strsep(&temp1,"&"); temp2!=NULL; temp2=strsep(&temp1,"&"))
	{
        	form = (chainType*)malloc(sizeof(chainType));
       		form->attribute=strsep(&temp2,"=");
         	form->value=strsep(&temp2,"\0");
          	if (aux == NULL)
           	{
            	first = form;
            }
            else
            {
            	aux->next = form;
            }

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
		printf("Erro: ponteiro nulo");
		printf("</body>\n");
		printf("</html>");
		exit(OK);
	}
	uid = first->value;
	aux=first->next;
/*
		printf("Content-type: text/html\n\n");
		printf("<html>\n");
		printf("<head>\n");
		printf("<title>Resultado</title>\n");
		printf("</head>\n");
		printf("<body>\n");
		printf("%s-%s<BR>%s-%s\n",aux->attribute,aux->value,aux->next->attribute,aux->next->value);
		printf("</body>\n");
		printf("</html>");
		exit(OK);
*/
	doc = xmlReadFile(XML_ADDED, NULL, 256);

	if (doc == NULL) 
	{
		printf("Content-type: text/html\n\n");
		printf("<html>\n");
		printf("<head>\n");
		printf("<title>Resultado</title>\n");
		printf("</head>\n");
		printf("<body>\n");
		printf("Erro ao tentar abrir o arquivo.\n");
		printf("%s",XML_ADDED);
		printf("</body>\n");
		printf("</html>");
		exit(OK);
	}
	root_element = xmlDocGetRootElement(doc);
	//printf("%s\n",root_element->name);

//	currently = root_element->children; comentei essa linha o codigo deve continuar funcionando!!
//	printf("%s\n",currently->name);

/*				printf("Content-type: text/html\n\n");
				printf("<html>\n");
				printf("<head>\n");
				printf("<title>Resultado</title>\n");
				printf("</head>\n");
				printf("<body>\n");*/
		
	for (currently = root_element->children; currently; currently=currently->next)
	{
		/*printf("%s\n",xmlNodeGetContent(currently->children));
		printf("%d\n",i);
		printf("%s\n",aux->value);*/
		if(i == atoi(aux->value))
		{
			patientFound = currently->children;
			
			while ((strcmp(patientFound->name, "nome")) && (patientFound))
			//{
				patientFound = patientFound->next;
				// printf("<p>%s</p>\n", patientFound->name);
			//}
			
			if (!patientFound)
			{
				printf("Content-type: text/html\n\n");
				printf("<html>\n");
				printf("<head>\n");
				printf("<title>Resultado</title>\n");
				printf("</head>\n");
				printf("<body>\n");
				printf("Erro: paciente não encontrado");
				printf("</body>\n");
				printf("</html>");
				exit(OK);
			}
			
			/*if(!strcmp(xmlNodeGetContent(patientFound),aux->next->value))       ///NAO ACEITA NOMES COM ACENTO!!!! RESOLVER DEPOIS!!!!
			{
				printf("<p>%s = %s?</p>\n",xmlNodeGetContent(patientFound),aux->next->value);*/
				extracted = xmlReplaceNode(currently,currently->next);
			//}
			
		}
		i++;
	}
	
	test = fopen(XML_REMOVED,"r");
	if(test == NULL)
	{
		docNew = xmlNewDoc(version);
		root_element_new = xmlNewNode(NULL,"doc");
		xmlDocSetRootElement(docNew, root_element_new);
//		xmlNewChild(extracted, NULL,"motivo", BAD_CAST aux->next->value);
	        xmlAddChild(root_element_new,extracted);
	}
	else
	{
		fclose(test);
		docNew = xmlReadFile(XML_REMOVED, NULL, 256);
		root_element_new = xmlDocGetRootElement(docNew);
//		xmlNewTextChild(extracted->children,NULL,"motivo",aux->next->value);
        	xmlAddChild(root_element_new,extracted);
	}

	/*  save the file that contents removed patients and free memory */

	if(xmlSaveFormatFileEnc(XML_REMOVED,docNew,"UTF-8",1) < 0 )
	{
		printf("Content-type: text/html\n\n");
		printf("<html>\n");
		printf("<head>\n");
		printf("<title>Resultado</title>\n");
		printf("</head>\n");
		printf("<body>\n");
		printf("Erro ao salvar arquivo<BR>\n");
		printf("%s",XML_REMOVED);
		printf("</body>\n");
		printf("</html>");
		exit(OK);
	}
	xmlFreeNode(extracted);
	xmlFreeDoc(docNew);
	xmlCleanupParser();
	xmlMemoryDump();
	
	/*  save the file of patients and free memory */
	if(xmlSaveFormatFileEnc(XML_ADDED,doc,"UTF-8",1) < 0 )
	{
		printf("Content-type: text/html\n\n");
		printf("<html>\n");
		printf("<head>\n");
		printf("<title>Resultado</title>\n");
		printf("</head>\n");
		printf("<body>\n");
		printf("Erro ao salvar arquivo\n");
		printf("%s",XML_ADDED);
		printf("</body>\n");
		printf("</html>");
		exit(OK);
	}
	xmlFreeDoc(doc);
	xmlFreeNode(currently);
	xmlCleanupParser();
	xmlMemoryDump();
	
/*		printf("Content-type: text/html\n\n");
		printf("<html>\n");
		printf("<head>\n");
		printf("<title>Resultado</title>\n");
		printf("</head>\n");
		printf("<body>\n");
		printf("chegou aqui!\n");
		printf("%s",PATHFILE);
		printf("</body>\n");
		printf("</html>");
		exit(OK);
*/		
//	test = fopen(XML_HISTORIC,"r");

	/* File Historic.xml doesn´t exist */

	/*if(test == NULL)
	{
		docNew = xmlNewDoc("1.0");
		root_element_new = xmlNewNode(NULL,"doc");
		xmlDocSetRootElement(docNew, root_element_new);
		extracted=xmlNewNode(NULL,"paciente");
		xmlNewChild(extracted,NULL,"nome",aux->next->value);
		info=xmlNewNode(NULL,"info");
	}

	// File Historic.xml exist and need to find his position if there is a historic of the patient

	else
	{
		fclose(test);
		docNew = xmlReadFile(XML_HISTORIC, NULL, 256);
		root_element_new = xmlDocGetRootElement(docNew);
		for (currently = root_element_new->children; ((naoAchado == 0) && (strcmp(xmlNodeGetContent(currently->children),aux->value) ) ); )
		{
	             if(currently->next == NULL)
        	        naoAchado++;
               	     else
	                currently=currently->next;
//printf("%s\n",xmlNodeGetContent(currently->children));
		}
//		xmlNewTextChild(extracted->children,NULL,"motivo",aux->next->value);

		// if currently is null, there is no historic of that patient 

		if(naoAchado)
		{
			extracted=xmlNewNode(NULL,"paciente");
			xmlNewChild(extracted,NULL,"numeroPaciente",aux->value);  // faltar verificar se aux->value contem msm o numero do paciente
			info=xmlNewNode(NULL,"info");			
		}

		// there is already a historic of the patient

		else
		{
			extracted=currently;
			info=extracted->children->next;			
		}
	}
	removed=xmlNewNode(NULL,"removido");

	// get time: hour,minute,second, day,month,year

	if(getFullDataParts(hour,minute,second,day,month,year))
	{
		printf("Content-type: text/html\n\n");
		printf("<html>\n");
		printf("<head>\n");
		printf("<title>Resultado</title>\n");
		printf("</head>\n");
		printf("<body>\n");
		printf("Erro ao pegar data<BR>\n");
		printf("</body>\n");
		printf("</html>");
		exit(OK);
	}
	xmlNewChild(removed,NULL,"day",day);
							printf("Content-type: text/html\n\n");
		printf("<html>\n");
		printf("<head>\n");
		printf("<title>Resultado</title>\n");
		printf("</head>\n");
		printf("<body>\n");
		printf("chegou aqui![4]\n");
		printf("%s",PATHFILE);
		printf("</body>\n");
		printf("</html>");
		exit(OK);*/
	/*xmlNewChild(removed,NULL,"month",month);
	xmlNewChild(removed,NULL,"year",year);
	xmlNewChild(removed,NULL,"hour",hour);
	xmlNewChild(removed,NULL,"minute",minute);
	xmlNewChild(removed,NULL,"second",second);
	xmlNewChild(removed,NULL,"user",MEDIC);
	xmlNewChild(removed,NULL,"reason",aux->next->value);
	xmlAddChild(info,removed);
	xmlAddChild(extracted,info);
	xmlAddChild(root_element_new,extracted);

	if(xmlSaveFormatFileEnc(XML_HISTORIC,docNew,"UTF-8",1) < 0 )
	{
		printf("Content-type: text/html\n\n");
		printf("<html>\n");
		printf("<head>\n");
		printf("<title>Resultado</title>\n");
		printf("</head>\n");
		printf("<body>\n");
		printf("Erro ao salvar arquivo<BR>\n");
		printf("%s",XML_HISTORIC);
		printf("</body>\n");
		printf("</html>");
		exit(OK);
	}

	xmlFreeNode(extracted);
	xmlFreeNode(currently);
	xmlFreeNode(info);
	xmlFreeNode(removed);
	xmlFreeDoc(docNew);
	xmlCleanupParser();
	xmlMemoryDump();
  
	root_element = xmlDocGetRootElement(doc);
	printf("%s\n",root_element->name);

	for (currently = root_element->children; currently; currently=currently->next)
	{
		printf("%s\n",currently->name);
	}
*/	
	printf("Content-type: text/html\n\n");
	printf("<html>\n");
	printf("<head>\n");
	printf("<title>.:. Neural TB .:. Paciente removido com sucesso</title>\n");
	printf("<script language=\"javascript\" src=\"../js/motivo.js\" charset=\"UTF-8\"></script>\n");
	printf("<script language=\"javascript\" src=\"../js/xml.js\" charset=\"UTF-8\"></script>\n");
	printf("</head>\n");
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
	printf("<h3><div align='center'>Paciente removido com sucesso!</div></h3>\n");
	printf("</body>\n");
	printf("</html>");

	for (aux=form=first; aux!=NULL; form=aux)
	{
		aux = form->next;
		free (form);
	}
		
	exit(OK);
}

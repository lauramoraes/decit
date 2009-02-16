/*
	Universidade Federal do Rio de Janeiro
	Escola Politecnica
	Departamento de Engenharia Eletronica e de Computacao
	
	Laboratorio de Processamento de Sinais
	Projeto Neural TB (Guadalupe)
	Autor: Igor Cunha Braganca

	$Author$
	$Date$
	$Log$
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xmlstring.h>

#include "cgi.h"
#include "ntbError.h"
#include "ntbConfig.h"
#include "ntbConsts.h"
#include "ntbTypes.h"
#include "ntbFunctions.h"

#define XML_FILE_PATH "../xml/pacientes.xml"
#define XML_TEMP_FILE "../xml/TempPacientes.xml"

void usualFreeMemory (xmlDocPtr doc)
{
	cgi_end();
	if (doc)
		xmlFreeDoc(doc);
	xmlCleanupParser();
	xmlMemoryDump();
}

void printSuccess (char *username)
{
	cgi_init_headers();
	
	printf ("<html>\n");
	printf ("\t<head>\n");
	printf ("\t\t<title>Usu&aacute;rio Editado</title>\n");
	printf ("\t\t<meta http-equiv=\"refresh\" content=\"2; URL=busca.cgi?uid=%s\" />\n",username);
	printf ("\t</head>\n");
	printf ("\t<body>\n");
	printf ("<span style=\"background-color:green; color: white; font-family: Verdana, Arial; font-size:15pt; padding: 5px\">");
	printf ("Usu&aacute;rio editado com sucesso. Aguarde...</span>");
	printf ("\t</body>\n");
	printf ("</html>");
}

void printError (char *msg)
{
	cgi_init_headers();
	
	printf ("<html><head><title>Erro</title></head><body><h2>%s</h2></body></html>", msg);
}

int main (void)
{
	
	int atual;
	
	/* libcgi declarations */
		
	/* libxml2 declarations */
	xmlChar *strUTF = NULL;
	xmlDocPtr doc;
	xmlNodePtr root_element, cur_node, new_form, new_node, edited_patient, old_patient;
	
	char buf[5];
	
	/*
	 * this initialize the library and check potential ABI mismatches
	 * between the version it was compiled for and the actual shared
	 * library used.
	 */
	LIBXML_TEST_VERSION
	
/******************************************************************************
 *            READ CONTENT STRING FROM SERVER.		*
 *            PROCESS DATA.						*
 *            CREATE A LINKED LIST.					*
 ******************************************************************************/
	
	cgi_init();
	
/******************************************************************************
 *            OPENING AND PARSING AN XML FILE TO A TREE                       *
 ******************************************************************************/	
 
	doc = xmlReadFile(XML_FILE_PATH, NULL, XML_PARSE_NOBLANKS);
	if (doc == NULL)
	{
		printError("Failed to parse doc");
		usualFreeMemory(NULL);
		exit(0);
	}
	root_element = xmlDocGetRootElement(doc);
	cur_node = root_element->children;
	
	
	
/******************************************************************************
 *            SEARCH THE SAME <numeroGeral>                                   *
 ******************************************************************************/
		
	atual = 1;

		while(cur_node != NULL )
		{

			new_form = cur_node;
			
			new_node = xmlNewNode (NULL, "id");
			sprintf(buf, "%d", atual);
			xmlNodeAddContent (new_node, buf);
				
			xmlAddChild (new_form, new_node);
	
			atual++;
			cur_node = cur_node->next;
		}
		
	
		
/******************************************************************************
 *            DUMPING DOCUMENT TO FILE		*
 ******************************************************************************/
	
	xmlSaveFormatFileEnc(XML_TEMP_FILE, doc, "UTF-8", 1);

	
	remove(XML_FILE_PATH);
    
    if (rename(XML_TEMP_FILE, XML_FILE_PATH))
    {
        printError("Erro ao renomear o arquivo atualizado");
        usualFreeMemory(doc);
        exit(0);
    }

/******************************************************************************
 *            FREE MEMORY AND EXIT			*
 ******************************************************************************/

	printSuccess(buf);
		
	usualFreeMemory(doc);
	
	
	return 0;
}

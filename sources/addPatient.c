/*
	Universidade Federal do Rio de Janeiro
	Escola Politecnica
	Departamento de Engenharia Eletronica e de Computacao
	
	Laboratorio de Processamento de Sinais
	Projeto Neural TB (DECIT)
	Autor: Renato Sampaio Ribeiro

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
	printf ("\t\t<meta http-equiv=\"refresh\" content=\"2; URL=principal.cgi?uid=%s\" />\n",username);
	printf ("\t</head>\n");
	printf ("\t<body>\n");
	printf ("<span style=\"background-color:green; color: white; font-family: Verdana, Arial; font-size:15pt; padding: 5px\">");
	printf ("Paciente inserido com sucesso. Aguarde...</span>");
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
	char *formName, *username, *nroPacientes;
	boolean found_patient;
	
	/* libcgi declarations */
	formvars *first_input, *input;
	
	/* libxml2 declarations */
	xmlChar *strUTF = NULL;
	xmlDocPtr doc;
	xmlNodePtr root_element, cur_node, new_form, new_node, new_patient;
	
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
	first_input = cgi_process_form();
	username = cgi_param("uid");
	

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
	
	
	new_patient = xmlNewNode (NULL,BAD_CAST "paciente");
	
/******************************************************************************
 *            ADD NEW FORM                                                    *
 ******************************************************************************/

	new_form = new_patient;

	for (input = first_input; input; input = input->next)
	{
		if (!strcmp(input->name,"form"))
			input = input->next;
			
		if (!strcmp(input->name,"uid"))
			input = input->next;
			
		if (!strcmp(input->name,"paciente"))
			input = input->next;
		
		
		/* Validate tag name input against UTF-8 */
		strUTF = input->name;
		//printf("%s : \n", strUTF);
		new_node = xmlNewNode (NULL, strUTF);
		free(strUTF);//frees input->name
		
		
		/* Validate tag value input against UTF-8 */
		strUTF = input->value;
		//printf("%s <br>\n", strUTF);
		xmlNodeAddContent (new_node, strUTF);
		free(strUTF);//frees input->value
		
		
		xmlAddChild (new_form, new_node);
	}
	
	new_node = xmlNewNode( NULL, "id" );
	
	//nroPacientes = root_element.getAttribute("nroPacientes");
	nroPacientes = xmlGetProp(root_element, "nroPacientes");
	sprintf(nroPacientes, "%d", (atoi(nroPacientes)+1));
	
	xmlNodeAddContent(new_node, nroPacientes);
	xmlAddChild(new_form, new_node);
	
	//new_node = xmlNewNode( NULL, "nroPacientes" );
	//xmlNodeAddContent(new_node, nroPacientes);
	
	xmlSetProp(root_element, "nroPacientes", nroPacientes);
	
	//xmlReplaceNode(root_element.getAttributeNode("nroPacientes"), new_node);

/******************************************************************************
*	Substituindo o noh antigo pelo novo		*
******************************************************************************/

	xmlAddChild (root_element, new_patient);
	
/******************************************************************************
 *            DUMPING DOCUMENT TO FILE		*
 ******************************************************************************/
	
	if ((xmlSaveFormatFileEnc(XML_TEMP_FILE, doc, "UTF-8", 1)) < 0)
	{
		remove(XML_TEMP_FILE);
		printError("Erro ao salvar arquivo");
		usualFreeMemory(doc);
		exit(0);
	}
	
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

	printSuccess(username);
	
	usualFreeMemory(doc);
	
	xmlFreeNode(new_patient);
	
	return 0;
}

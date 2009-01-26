/*
	Universidade Federal do Rio de Janeiro
	Escola Politecnica
	Departamento de Engenharia Eletronica e de Computacao
	
	Laboratorio de Processamento de Sinais
	Projeto Neural TB
	
	Autor: Patrick Svaiter
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <libxml/encoding.h>
#include "cgi.h"
#include "ntbError.h"
#include "ntbTypes.h"
#include "ntbFunctions.h"

/*
	Convert lowercase letters to uppercase in a string
	Returns the new string keeping the original one intact
	
	A void function that replace the original string with the uppercase one
	is easily achieved by removing malloc and its error treatment.
*/
char *to_uppercase (char *str)
{
	int i, len;
	char *STR;
	
	i=0;
	len = strlen (str);
	STR = (char *) malloc(len +1);
	if (!STR)
		return NULL;
	
	while (i < len)
	{
		STR[i] = (char) toupper (str[i]);
		i++;
	}
	
	STR[i] = '\0';
	
	return STR;
}


/**
 * Check if a string is an UTF-8.
 * If it is, a new string, copy of @in, is returned.
 * If not, a conversion is made from ISO Latin 1 to UTF-8 and the new string is
 * returned.
 * That's because an enconding detection is not performed and the former has
 * a large use in web.
 * This routine is intended to make use of the same variable whether it was
 * converted or not.
 *
 * Input
 *	@in: a pointer to an array of ISO Latin 1 chars
 * Output
 *	-
 * Returns:
 *	NULL in case of error
 *	A new string if success
 *
 * Notes: Returned string may be freed by the caller if != NULL
 *
 * use:
 *	char *str_in, *str_out;
 *	str_out = fixCgiStr (str_in); 
 */
xmlChar *fixCgiStr (xmlChar *in)
{
	int utf8;
	xmlChar *out = NULL;
	
	if (in == NULL) return NULL;
	
	utf8 = xmlCheckUTF8 (in);
	if (!utf8)
	{
		if (convertISO88591toUTF8(in, &out) < 0)
			return NULL;
		return (out);
	}
	
	return (xmlStrdup(in));
}

/**
 * Convert a string from ISO-8859-1 to UTF-8
 * Allocates double of ISO string size for UTF-8 string size
 * Input
 *	@strISO: a pointer to an array of ISO Latin 1 chars
 * Output
 *	@*strUTF: a pointer to an array of UTF-8 chars
 *
 * Returns:
 * -2 if any of char pointers are NULL
 * Otherwise, returns isolat1ToUTF8 return
 * Notes: strUTF may be freed by the caller if return >= 0
 */
int convertISO88591toUTF8 (unsigned char *strISO, unsigned char **strUTF)
{	
	int lenISO, lenUTF, rc;
	
	if (strISO == NULL || strUTF == NULL)
		return(-2);
	
	lenISO = strlen(strISO);
	lenUTF = 2 * lenISO;
	*strUTF = BAD_CAST malloc ((size_t) (lenUTF + 1));
	
	rc = isolat1ToUTF8 (*strUTF, &lenUTF, strISO, &lenISO);
	(*strUTF)[lenUTF] = '\0';
	
	if (rc < 0)
		free(*strUTF);
	
	return rc;
}

/*
	It gets the tag name and the text content between 2 tags.
	
	This is not a general parsing function.
	It does not verify several conditions to avoid unexpected behaviors,
	like checking if end of string was reached.
	Thus, it is a custom-made for a specific xml doc, which must contain
	in a line a starting tag and at least another starting tag, where it
	will stop getting text content. The tag name returned belongs to the
	first starting tag found.
	In the future, this may disappear to make way for an expat function.
	
	Expat is a C library for XML manipulation
*/
void getTagNameAndTextContent (char *str, parsedvars *parsed)
{
	int i,j;
	
	for (i=0; str[i] != '<'; i++);
	
	i++;
	for (j=0; ((str[i] != ' ') && (str[i] != '>')); i++, j++)
		parsed->name[j] = str[i];
	
	parsed->name[j] = '\0';
	
	if (str[i] == ' ')
		for ( ; str[i] != '>'; i++);	//skipping attributes
	
	i++;
	for (j=0; ((str[i] != '<') && (str[i] != '\0') && (str[i] != '\n')); i++, j++)
		parsed->text[j] = str[i];
	
	parsed->text[j] = '\0';
	
	return;
}

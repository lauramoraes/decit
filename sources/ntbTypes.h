/*
	Universidade Federal do Rio de Janeiro
	Escola Politecnica
	Departamento de Engenharia Eletronica e de Computacao
	
	Laboratorio de Processamento de Sinais
	Projeto Neural TB
	Autor: Patrick Svaiter

	$Author$
	$Date$
	$Log$
 */

#ifndef NTB_TYPES
#define NTB_TYPES "@(#)ntbTypes.h $Revision$"

#include "ntbConsts.h"

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

typedef enum {no_answer, dont_match, match} responseType;
typedef enum {false, true} boolean;

/*
	Use of dynamic memory allocation was postponed
	The max limit allowed in the xml doc was used to prevent possible errors
	This is another custom-made feature and need to be revised
*/
typedef struct
{
	char name[TEXT_FILE_LINE_MAX];
	char text[TEXT_FILE_LINE_MAX];
} parsedvars;


#endif

/* $RCSfile$ */

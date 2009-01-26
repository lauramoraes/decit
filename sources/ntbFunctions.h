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

#ifndef NTB_FUNCTIONS
#define NTB_FUNCTIONS "@(#)ntbFunctions.h $Revision$"

#include "ntbTypes.h"

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/* char * */

char *to_uppercase (char *);

/* int */

int convertISO88591toUTF8 (unsigned char *, unsigned char **);
unsigned char *fixCgiStr (unsigned char *);

/* void */

void getTagNameAndTextContent (char *, parsedvars *);


#endif



/* $RCSfile$ */

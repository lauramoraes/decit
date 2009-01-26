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

#ifndef NTB_ERROR
#define NTB_ERROR

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

typedef enum {
	ok,
	errorAllocatingMemory,
	errorOpeningReadOnlyFile,
	errorOpeningWriteOnlyFile,
	errorReadingFile
} ntbErrorType;


#endif

/* $RCSfile$ */

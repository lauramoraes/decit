#ifndef _PATIENT_FUNCTIONS_
#define _PATIENT_FUNCTIONS_


#include "tiposModif.h"

int scoreTriagemTb(chainType *);
int getPatient(FILE* paciente_xml, pacienteDataType *paciente);
int getXmlTextNode(char *string, char *result);
int writePatientInXmlFile (FILE* paciente_xml, pacienteDataType *paciente);
void criarStringAleatoria (char *, char *, unsigned);
int getUser(FILE*, userDataType *);

#endif

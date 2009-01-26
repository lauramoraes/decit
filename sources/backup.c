/*
* UFRJ - LPS
* Autor: Gabriel Nascimento Machado
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "const.h"
#include "error.h"
/*
unsigned lerPosto(const char*, char*);
unsigned lerPosto(const char *path, char *posto)
{
	FILE *users;
	char line[128+1];
	char *aux;
	
	if (!(users=fopen(path,"r")))
		return(ERROR_OPENING_FILE);
	while (fgets(line,128+1,users))
	{
		if ((aux=strstr(line,"usuarios ")))
		{
			aux=strchr(aux,'\"');
			aux++;
			strncpy(posto,aux,strchr(aux,'\"')-aux);
			posto[strchr(aux,'\"')-aux]='\0';
			return(OK);
		}
	}
	return(WRONG_XML_ROOT);
}
*/
int main (int argc, char *argv[])
{
	FILE *xml, *backup;
	char date[DATE_LENGTH+1];
	char backupPath[strlen(XML_NAME)+32+1+1+strlen(XML_BACKUP_PATH)+1+DATE_LENGTH+1];
	char posto[32+1], path[strlen(XML_DIR_PATH)+1+MAX_LENGTH_HEALTH_CENTER+1+strlen(XML_GENERIC_NAME)+1];
	int ch;
	time_t seg;
	struct tm *tempo;
	
	time(&seg);
	tempo=localtime(&seg);
	snprintf (date,DATE_LENGTH+1,"%04i-%02i-%02i_%02i-%02i-%02i",1900+tempo->tm_year,tempo->tm_mon+1,tempo->tm_mday,tempo->tm_hour,tempo->tm_min,tempo->tm_sec);
	//lerPosto(USERS_DATA_PATH,posto);
	strcpy(backupPath,"");
	snprintf (path,strlen(XML_DIR_PATH)+1+MAX_LENGTH_HEALTH_CENTER+1+strlen(XML_GENERIC_NAME),"%spacientes.xml",XML_DIR_PATH);
	snprintf (backupPath,strlen(XML_NAME)+strlen(XML_BACKUP_PATH)+DATE_LENGTH+strlen(posto)+1+1+1+1,"%s%s-pacientes.xml",XML_BACKUP_PATH,date);
	if (!(xml=fopen(path, "r")))
	{
		printf("Content-Type: text/html\r\n\r\n");
		printf("<html><head><title>Erro</title></head><body>Erro abrindo arquivo de usu&aacute;rios</body></html>");
		exit(0);
	}
	if (!(backup=fopen(backupPath, "w")))
	{
		printf("Content-Type: text/html\r\n\r\n");
		fclose(xml);
		printf("<html><head><title>Erro</title></head><body>Erro abrindo arquivo de Backup</body></html>");
		exit(0);
	}
	printf("Content-Type: application/force-download\r\n");
	printf("Content-Disposition: attachment; filename=DECIT_%s_backup.xml\r\n\r\n",date);	
	while((ch=getc(xml)) != EOF)
	{
		printf("%c",ch);
		fputc(ch,backup);
	}
	fclose(xml);
	fclose(backup);

	exit(0);
}

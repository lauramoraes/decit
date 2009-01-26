#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "const.h"
#include "error.h"


unsigned createRandomString (unsigned lenght, char *validCharacters, char *string)
{
	unsigned indice=0;
	
	if (!(validCharacters))
	{
		string[0]='\0';
		return (NULL_POINTER);
	}
	srand(time(NULL));
	for (indice=0; indice < lenght; indice++)
        string[indice]= validCharacters [(rand()%(strlen(validCharacters)))];
	string[indice]='\0';

	return (OK);
}
/*-----------------------------------------------------------------*/
unsigned validateField(char *Field, char *ValidChars, unsigned MinLenght, unsigned MaxLenght)
{

unsigned Indice=0;

if ((Field==NULL) || (ValidChars==NULL) || (!(strchr(Field,'\0'))) || (!(strchr(ValidChars,'\0'))))
        return(NULL_POINTER);


if ((strlen(Field) < MinLenght) || (strlen(Field) > MaxLenght))
        return(INVALID_FIELD_LENGTH);

while(Indice < strlen(Field))
        {       
                if ((!(strchr(ValidChars,Field[Indice]))) && (Field[Indice]!='\n'))
                return(INVALID_FIELD_CHAR);
        Indice++;      
        }
return (OK);
}
/*-----------------------------------------------------------------*/
unsigned createCookie(char *username, char *cookie, char *Ip) 
{
FILE *arquivo;
	unsigned returnCode;
	char cookiePath[strlen(COOKIES_PATH)+MAX_LENGTH_USERNAME+1];
	/*time_t expiration;*/
	
	/* Validating inputs */
	if((!(username)) || (!(Ip)))
		return(NULL_POINTER);
	if((returnCode=validateField(username,VALID_CHARS_USERNAME,MIN_LENGTH_USERNAME,MAX_LENGTH_USERNAME))!=OK)
		return(returnCode);
	if((returnCode=validateField(Ip,VALID_CHARS_IP,MIN_LENGTH_IP,MAX_LENGTH_IP))!=OK)
		return(returnCode);
		
	if((returnCode=createRandomString(LENGTH_COOKIE_VALUE,VALID_CHARS_COOKIE,cookie))!=OK)
		return(returnCode);
	if(!(arquivo=fopen(strncat(strcpy(cookiePath,COOKIES_PATH),username,strlen(username)),"w")))
		return(ERROR_OPENING_FILE);
		
	/*expiration=time(NULL)+1800;*/
	Ip[strlen(Ip)]='\0';
	cookie[LENGTH_COOKIE_VALUE]='\0';
	/*fwrite(&expiration,1,sizeof(time_t),arquivo);*/
	fwrite(cookie,1,LENGTH_COOKIE_VALUE+1,arquivo);
	fwrite(Ip,1,strlen(Ip)+1,arquivo);	
fclose(arquivo);
return(OK);
}
void unencode(char *src, char *last, char *dest)
{
char aux[2+1];
long int hex;

 for(; src != last; src++, dest++)
   if(*src == '+')
     *dest = ' ';
   else if(*src == '%') {
     
	 src++;
	 strncpy (aux,src,2);
	 hex = strtol(aux,(char**)NULL,16);
	 snprintf(dest,1+1,"%c",(int)hex);
     src ++; }
   else
     *dest = *src;
 *dest = '\0';
}
/*-----------------------------------------------------------------*/
unsigned getCookie(char *name, char *value)
{
char cookie[MAX_LENGTH_USERNAME+LENGTH_COOKIE_VALUE+1+1];
unsigned indice;

indice=0;
strcpy(cookie,getenv("HTTP_COOKIE"));
if (!(strlen(cookie)) || !(cookie) )
	{
	return(NO_COOKIE);
	}
	/*if (strlen(cookie)>MAX_LENGTH_USERNAME+LENGTH_COOKIE_VALUE+1)
		return(INVALID_COOKIE_LENGTH);*/
		/*if ((strchr(cookie, ';')) != NULL)
			return(INVALID_COOKIE);*/

		while (cookie[indice] != '=')
			indice++;

	if(indice>MAX_LENGTH_USERNAME)
		return(INVALID_COOKIE_NAME_LENGTH);
	strncpy(name, cookie, indice);
	strncpy(value, &cookie[indice+1], LENGTH_COOKIE_VALUE);
return(OK);
}
/*-----------------------------------------------------------------*/
unsigned getSpecificCookie(const char *name, char *value)
{
char *cookie;
unsigned indice;
if (!(name))
	return(NULL_POINTER);

indice=0;
/*strcpy(cookie,getenv("HTTP_COOKIE"));*/
cookie=getenv("HTTP_COOKIE");
if (!(strstr(cookie,name)))
	return(COOKIE_NAME_NOT_FOUND);
cookie=strstr(cookie,name);
if (!(strlen(cookie)) || !(cookie) )
	{
	return(NO_COOKIE);
	}
	/*if (strlen(cookie)>MAX_LENGTH_USERNAME+LENGTH_COOKIE_VALUE+1)
		return(INVALID_COOKIE_LENGTH);*/
		/*if ((strchr(cookie, ';')) != NULL)
			return(INVALID_COOKIE);*/

		while (cookie[indice] != '=')
			indice++;

	if(indice>MAX_LENGTH_USERNAME)
		return(INVALID_COOKIE_NAME_LENGTH);
	/*strncpy(name, cookie, indice);*/
	strncpy(value, &cookie[indice+1], LENGTH_COOKIE_VALUE);
return(OK);
}
/*-----------------------------------------------------------------*/
unsigned checkCookie(char *value, char *ip, char *name)
{
FILE *ArquivoCookie;
char ReadIp[MAX_LENGTH_IP+1], ReadCookieValue[LENGTH_COOKIE_VALUE+1];
/*time_t expiration;*/
/*size_t lidos;*/

if(!(ArquivoCookie=fopen(name,"r")))
	return(INVALID_COOKIE);

/*fread(&expiration,1,sizeof(time_t),ArquivoCookie);*/

fread(ReadCookieValue,1,LENGTH_COOKIE_VALUE+1,ArquivoCookie);
fread(ReadIp,1,MAX_LENGTH_IP+1,ArquivoCookie);

		if(ferror(ArquivoCookie))
			{
			fclose(ArquivoCookie);
			return(ERROR_READING_FILE);
			}

fclose(ArquivoCookie);

	/*if (expiration<time(NULL))
		return(_COOKIE_EXPIRED);*/
	if (strcmp(value,ReadCookieValue)) /*Check if the values match*/
		return(INVALID_COOKIE_VALUE);
	if (strcmp(ip,ReadIp))
		return(INVALID_COOKIE_IP);			

return(OK);
}
/*-----------------------------------------------------------------*/
unsigned searchUser (char *username, char *password, unsigned *group)
{
	char linha[1024];
	FILE *doc;
	char *pos;
	char usernameRead[MAX_LENGTH_USERNAME+1], passwordRead[MAX_LENGTH_PASSWORD+1], groupRead[MAX_LENGTH_GROUP+1];
	unsigned index=0;
	
	if (!(username))
		return(NULL_POINTER);
	
    if( !(doc = fopen( USERS_DATA_PATH , "r" ) ) )
	{
        return(ERROR_OPENING_USERS_XML);
    }
	
	while(fgets(linha,1024+1,doc))
	{
		if ((pos=(strstr(linha,"<username>"))))
		{
		pos++;
		while((linha[pos+strlen("<username>")-linha-1+index] != '<') && (linha[pos+strlen("<grupo>")-linha-1+index] != '\n') && (linha))
			{
			usernameRead[index]=linha[pos+strlen("<username>")-linha-1+index];
			index++;
			}
		usernameRead[index]='\0';
	
		index=0;
		if (!strcmp(username, usernameRead))
		{
			if (!(fgets(linha,1024+1,doc)))
				return(INVALID_XML_FILE);
			if ((pos=(strstr(linha,"<senha>"))))
			{
				pos++;
				while((linha[pos+strlen("<senha>")-linha-1+index] != '<') && (linha[pos+strlen("<grupo>")-linha-1+index] != '\n') && (linha))
				{
					passwordRead[index]=linha[pos+strlen("<senha>")-linha-1+index];
					index++;
				}
				passwordRead[index]='\0';
				strcpy(password,passwordRead);
				index=0;
				
				/*Geting group*/
				if (!(fgets(linha,1024+1,doc)))
					return(INVALID_XML_FILE);
				if ((pos=(strstr(linha,"<grupo>"))))
				{
					pos++;
					while((linha[pos+strlen("<grupo>")-linha-1+index] != '<') && (linha[pos+strlen("<grupo>")-linha-1+index] != '\n')  && (linha))
						{
						groupRead[index]=linha[pos+strlen("<grupo>")-linha-1+index];
						index++;
						}
					groupRead[index]='\0';
					if (!strcmp(groupRead,"medico")) *group = MEDICO;
					else if (!strcmp(groupRead,"enfermeiro")) *group=ENFERMEIRO;
					else *group=ATENDENTE;
					
					fclose(doc);
					return(OK);
				}
				else return (INVALID_XML_FILE);
			}
			else return (INVALID_XML_FILE);
		}
	}
}

fclose(doc);

return (USER_NOT_FOUND);
}
/*-----------------------------------------------------------------*/
unsigned authenticateUser (char *username, char *password, unsigned *group)
{
	char passwordFound[MAX_LENGTH_PASSWORD+1];
	unsigned returnCode;


	if (!username)
		return (NULL_POINTER);
	if (!password)
		return (NULL_POINTER);
	if ((returnCode = searchUser(username, passwordFound, group)) != OK)
		return (returnCode);
	if (!passwordFound)
		return (NULL_POINTER);
	if (!(strcmp(password,passwordFound)))
		return (OK);
	
	return(WRONG_PASSWORD);
}
/*-----------------------------------------------------------------*/



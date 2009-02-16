
#ifndef CONST_H
#define CONST_H


#define MAXLEN 64
#define EXTRA 9
#define MAXINPUT MAXLEN+2*EXTRA+1



#define COOKIES_PATH ""
#define USERS_DATA_PATH "../xml/users.xml"

#define MEDICO 1
#define ENFERMEIRO 2
#define ATENDENTE 3

#define XML_DIR_PATH "../xml/"
#define XML_GENERIC_NAME "pacientes.xml"

#define XML_ADDED "../xml/pacientes.xml"
#define XML_REMOVED "../xml/removidos.xml"
#define XML_HISTORIC "../xml/historico.xml"
#define XML_BACKUP_PATH "../backup/"
#define XML_NAME "pacientes.xml" /* Mantido para servir de referencia aos tamanhos de string,  deve ser mudado para um posto com nome maior que "Guadalupe"*/
#define DATE_LENGTH 2+1+2+1+4+1+1+2+1+2+1+2 //20

#define MAX_LENGTH_HEALTH_CENTER 32

#define REMOVER_CGI "../cgi-bin/remover.py"
#define BUSCA_CGI "../cgi-bin/busca.cgi"

#define MAX_LENGTH_UID 24
#define MAX_LENGTH_USERNAME 32
#define LENGTH_ENCRYPTED_PASSWORD 34
#define MAX_LENGTH_PASSWORD 32
#define MAX_LENGTH_QUERY_STRING 1024

#define LENGTH_SALT 8
#define LENGTH_COOKIE_VALUE 64
#define MAX_LENGTH_IP 15
#define MAX_LENGTH_FIELD 100
#define MAX_LENGTH_GROUP 10

#define MIN_LENGTH_UID 1
#define MIN_LENGTH_USERNAME 2
#define MIN_LENGTH_IP 7
#define MIN_LENGTH_PASSWORD 6
#define MIN_LENGTH_NAME 5
#define MIN_LENGTH_GROUP 6

#define VALID_CHARS_USERNAME "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define VALID_CHARS_PASSWORD "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789/.#$"
#define VALID_CHARS_NAME "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.- "
#define VALID_CHARS_SALT "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789/."
#define VALID_CHARS_EMAIL "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.-_@0123456789"
#define VALID_CHARS_COOKIE "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
#define VALID_CHARS_IP "0123456789."
#define VALID_CHARS_GROUP "mediconfrat"


#endif

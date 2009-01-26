/*
	Universidade Federal do Rio de Janeiro
	Escola Politecnica
	Departamento de Engenharia Eletronica e de Computacao
	
	Laboratorio de Processamento de Sinais
	Projeto Neural TB
	
	Autores:	Gabriel Nascimento Machado
				Patrick Svaiter
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <limits.h>

#include "cgi.h"

#include "functions.h"
#include "const.h"
#include "error.h"


int main (void)
{
	char *username;
	char *password;
	unsigned returnCode, group;

	//incluir aceitacao SOMENTE para metodo POST. LibCGI identifica e aceita qualquer metodo

	cgi_init();
	cgi_process_form();
	
	username = cgi_param("username");
	password = cgi_param("password");
	
	//se cgi_end viesse aqui teria problema com o username?
	//a cgi_end libera a memoria alocada, e username eh um ponteiro para uma regiao alocada
	//porem em uma outra cgi, ao usar cgi_end antes de usar username, o valor de username permaneceu
	//pq?
	
	printf ("Content-type: text/html\r\n");
	
	if (!(returnCode = authenticateUser(username,password,&group)))
	{
		/*strncpy(ip,getenv("REMOTE_ADDR"),15); //Creating cookie
		createCookie(username,cookie,ip);
		printf("Set-Cookie: %s=%s; path=/",username,cookie);*/
		printf("Location: principal.cgi?uid=%s\r\n", username);
		printf("\r\n");
	}
	
	/* Mensagem de username ou senha invalido */
	else 
		if ((returnCode==WRONG_PASSWORD) || (returnCode==USER_NOT_FOUND) || (returnCode==NULL_POINTER))
		{
			printf("\r\n");
			
			printf ("<html>\n");
			printf ("<head>\n");
			printf ("	<title>Neural TB - Entrar</title>\n");
			printf ("	<!--<link rel=\"stylesheet\" type=\"text/css\" href=\"css/main.css\">-->\n");
			printf ("	<link rel=\"stylesheet\" type=\"text/css\" href=\"css/login.css\">\n");
			printf ("	<script language=javascript src=\"../js/funcoes.js\"></script>\n");
			printf ("	</head>\n");
			printf ("\n");
			printf ("	<body onLoad=\"login.username.focus()\">\n");
			printf ("	<div align=\"center\">\n");
			printf ("\n");
			printf ("	<img src=\"../imagens/NeuralTB3.jpg\">\n");
			printf ("	<br /><br />\n");
			printf ("	<div class=\"\">\n");
			printf ("	<table>\n");
			printf ("		<tr>\n");
			printf ("			<td style=\"vertical-align:top; padding-top:8px\">\n");
			printf ("				<form name=\"login\" action=\"login.cgi\" method=\"post\">\n");
			printf ("				<table border=\"0\">\n");
			printf ("					<tr>\n");
			printf ("						<td style=\"text-align:right\">Usu&aacute;rio:</td>\n");
			printf ("						<td><input name=\"username\" type=\"text\" maxlength=18 ></td>\n");
			printf ("					</tr>\n");
			printf ("					<tr>\n");
			printf ("						<td style=\"text-align:right\">Senha:</td>\n");
			printf ("						<td><input name=\"password\" type=\"password\" maxlength=18 ></td>\n");
			printf ("					</tr>\n");
			printf ("					<tr>\n");
			printf ("						<td colspan=\"2\" height=\"15\"></td>\n");
			printf ("					</tr>\n");
			printf ("					<tr>\n");
			printf ("						<td></td>\n");
			printf ("						<td style=\"text-align:right\"><input type=\"submit\" value=\"Entrar\"></td>\n");
			printf ("					</tr>\n");
			
			if (!(username)||(!password)) {
			printf ("					<tr>\n");
			printf ("						<td colspan=\"2\" style=\"color:red\">Preencha todos os campos</td>\n");
			printf ("					</tr>\n");
			}
			
			else {
			printf ("					<tr>\n");
			printf ("						<td colspan=\"2\" style=\"color:red\">Usu&aacute;rio e senha nao correspondem</td>\n");
			printf ("					</tr>\n");
			}
			
			printf ("				</table>\n");
			printf ("				</form>\n");
			printf ("			</td>\n");
			printf ("			<td style=\"padding-left:20px\"><img src=\"../imagens/humanSmallest.jpg\" style=\"z-index:-1\"></td>\n");
			printf ("		</tr>\n");
			printf ("	</table>\n");
			printf ("	</div>\n");
			printf ("\n");
			printf ("</div>\n");
			printf ("</body>\n");
			printf ("</html>");
		}
		
		else
		{
			printf("\r\n");
			printf("Erro %u", returnCode);
		}
	
	cgi_end();

	return 0;
}

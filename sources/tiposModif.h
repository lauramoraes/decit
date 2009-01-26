/********************************************************************************************
 * UFRJ/POLI/COPPE/LPS - Unidade de Pesquisa em Tuberculose                                 *
 * Projeto Neural TB                                                                        *
 * Author: Rony Tadeu Vernet Braga                                                          *
 * Description: Header file that contains the types used in Neural TB programs              *
 ********************************************************************************************/

#ifndef _TIPOS_
#define _TIPOS_

#define tipo_float double

	typedef struct chain
	{
		char *attribute;
		char *value;
		double entry;
		struct chain *next;
	} chainType;

typedef enum{false,true} boolean;


typedef struct pacienteDataType
{
	char nome[256];
	char idade[256];
	char data_nascimento[256];
	char sexo[256];
	char tosse[256];
	char hemoptoico[256];
	char sudorese[256];
	char febre[256];
	char emagrecimento[256];
	char anorexia[256];
	char dispneia[256];
	char fuma_atualmente[256];
	char tb_extrapulmonar[256];
	char internacao_hospitalar[256];
	char sida[256];
	char observacoes[256];
	char result[256];
	char grupo_de_risco[256];
	char grafico_de_grupo[256];
	char visto_de_analise[256];
	struct pacienteDataType *next;
} pacienteDataType;

typedef struct userDataType {
	char login[16];
	char senha[40];
	char status[10];
} userDataType;

typedef struct tipopaciente{
	double idade ;
	double genero;
	double estado;
	double cor ;
	double renda;
	double tosse ;
	double escarro;
	double hemoptoico;
	double hemoptise;
	double sudorese;
	double febre;
	double emagrecimento;
	double dortoracica;
	double calafrios;
	double dispneia;
	double astenia;
	double anorexia;
	double jafumou;
	double fumaatual;
	double diabetes;
	double alcoolismo;
	double tbpulmant;
	double tbextrapulm;
	double interhosp;
	double contato;
	double sida;
	double diag;
} tipopaciente;


#endif

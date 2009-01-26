/*Author: Fernando Guimarães Ferreira
 *Date: 29/07/2005
 *Universidade Federal do Rio de Janeiro
 *Laboratorio de Processamento de Sinais(LPS/COPPE-UFRJ)
 *Set of javascript functions for Neural TB project
 *Apanhado de funções em javascript para o projeto Neural TB
 */


/*Revisao de codigo por Rony Tadeu Vernet Braga
 *Ultima atualizacao: 11/05/2006
 */


// JavaScript Document
//validação  de forms
/************************************************************************/
//Definição dos campos
	tabFields= new Array(15);
	tabFields[0] = ["nome", "Nome"];						//field0
	tabFields[1] = ["idade", "Idade"];	//field1
	tabFields[2] = ["sexo","Sexo"];							//field2
	tabFields[3] = ["tosse","Tosse"];						//field3
	tabFields[4] = ["hemoptoico","Hemoptóico"];					//field4
	tabFields[5] = ["sudorese","Sudorese Noturna"];				//field5
	tabFields[6] =["febre","Febre"];						//field6
	tabFields[7] =["emagrecimento","Emagrecimento"];				//field7
	tabFields[8] =["dispneia","Dispnéia"];						//field8
	tabFields[9] =["anorexia","Anorexia"];						//field9
	tabFields[10] =["fuma_atualmente", "Fuma Atualmente"];				//field10
	tabFields[11] =["tb_extrapulmonar","TB extrapulmonar"];			//field11
	tabFields[12] =["internacao_hospitalar","Internação Hospitalar"];		//field12
	tabFields[13] =["sida","SIDA"];							//field13
	tabFields[14] =["data_nascimento","Data de Nascimento"];			//field14
	//fim da definição dos campos


	//Variáveis auxiliares para validação dos campos dia/mes/ano e idade
	var diaValido = true;
	var mesValido = true;
	var anoValido = true;
	var idadeValida = true;
	var blank = "null";

	//Definição dos valores
	var tabValores= new Array("Masculino", "Feminino", "Acompanhado", "Desacompanhado", "Presente", "Ausente", "Ignorado","Sim", "Não");

	// variaveis globais
	var campoHidden= 4;// posição do campo Hidden --data de aniversário
	var campoIdade = 6;// posição do campo Idade

/* Força a quebra de linha de um texto */
function forcarQuebraDeLinha(texto, caracteresPorLinha)
{
	var inicio = 0;
	var fim = caracteresPorLinha;
	if (fim >= texto.length)
		document.write(texto);
	else
		while(inicio < texto.length)
		{
			document.write(texto.substring(inicio, fim) +"<br />");
			inicio += caracteresPorLinha;
			if ((texto.length - inicio)  < caracteresPorLinha)
				fim = inicio + (texto.length - inicio);
			else
				fim = inicio + caracteresPorLinha;
		}
}

/*função que nomeia os campos*/
function changeNames(form)
{
	form.elements[0].name= tabFields[0][0];
	for(count=campoIdade, index=1; count<(form.elements.length-3); count++)
	{
	 	/* mudanca de nome em inputs de 1 opcao */
		if((form.elements[count-1].name != form.elements[count].name)&&
			(form.elements[count].name)!= form.elements[count+1].name)
		{
		   form.elements[count].name= tabFields[index][0];
		   index++;
		}
		/* mudanca de nome em inputs de 2 opcoes */
		if ((form.elements[count-1].name != form.elements[count].name) &&
		   (form.elements[count].name == form.elements[count+1].name) &&
		   (form.elements[count+1].name != form.elements[count+2].name))
		{
			form.elements[count].name= tabFields[index][0];
			form.elements[count+1].name= tabFields[index][0];
			index++;
		}
		/* mudanca de nome em inputs de 3 opcoes */
		if ((form.elements[count].name == form.elements[count+1].name) &&
		  (form.elements[count+1].name == form.elements[count+2].name))
		{
			form.elements[count].name= tabFields[index][0];
			form.elements[count+1].name= tabFields[index][0];
			form.elements[count+2].name= tabFields[index][0];
			index++;
		}
  	 }
	 form.elements[campoHidden].name= tabFields[14][0];

}/*---------------------------------------------------------------------*/


/* Função para testar se determinada String contém somente números */
function isNumberString(InString)
{
	if(InString.length==0)
		return (false);
	var RefString="1234567890";
	for (Count=0; Count < InString.length; Count++)
	{
		TempChar= InString.substring (Count, Count+1);
		if (RefString.indexOf (TempChar, 0)==-1)
			return (false);
	}
	return (true);
}/*---------------------------------------------------------------------*/

/* Função para capitalizar o campo nome */
function capitalizeName(val)
{
	if (val == '')
		return('');
	newVal = '';
	val = val.split(' ');
	for(var c=0; c < val.length; c++)
	{
		newVal += val[c].substring(0,1).toUpperCase() + val[c].substring(1,val[c].length).toLowerCase() + ' ';
	}
	return(newVal);
}/*---------------------------------------------------------------------*/

/* Função para remover espacos em excesso de uma string */
function trim(str)
{
	while( (str.search(/  /g)) != (-1) )
		str=str.replace(/  /g," ");
	return str.replace(/^\s*|\s*$/g,"");
}/*---------------------------------------------------------------------*/

/* Função que é iniciada ao submeter o formulário */
function validar(form)
{
	var first=true;
	var error=false;
	var numberInval =false;
	var errorMsg="";
	changeNames(form);
	form.elements[0].value = trim(capitalizeName(form.elements[0].value));
	errorMsg+=("Os seguintes campos não foram preenchidos:\n");
	index=0;
	/* Validacao dos campos Nome e Idade*/
	for(count=0; count < (campoIdade+1); count += campoIdade, index++)
	{
		if (form.elements[count].value == "")
		{
			error = true;
			if (first == true)
			{
				errorMsg += tabFields[index][1];
				first=false;
			}
			else
				errorMsg+= (", " + tabFields[index][1]);
		}
	}
		/*Validacao do campo Data de nascimento*/
	form.elements[campoHidden].value= "";
	for(count=1; count < campoHidden; count++)
	{
		if (form.elements[count].value == "")
		{
			error = true;
			if (first == true)
			{
				errorMsg += tabFields[14][1];
				first=false;
			}
			else
				errorMsg += (", " + tabFields[14][1]);
			break;
		}
		else
		{
			form.elements[campoHidden].value = form.elements[campoHidden].value + form.elements[count].value;
			if (count < 3)
				form.elements[campoHidden].value = form.elements[campoHidden].value + "/";
			if (error == true)
				form.elements[count].disabled = false;
		}
	}
	for (count=(campoIdade+1);count<(form.elements.length-2);count++)
	{
			/* Verifica os campos com 2 opções */
		if ((form.elements[count-1].name != form.elements[count].name) &&
				(form.elements[count+0].name == form.elements[count+1].name) &&
				(form.elements[count+1].name != form.elements[count+2].name))
		{
			if ((!form.elements[count].checked) && (!form.elements[count+1].checked))
			{
				error=true;
				if (first==true)
				{
					errorMsg += tabFields[index][1];
					first=false;
				}
				else
					errorMsg+= (", " + tabFields[index][1]);
			}
			index++;
		}

		/* Verifica os campos com 3 opções */
		if ((form.elements[count].name == form.elements[count+1].name) && (form.elements[count+1].name == form.elements[count+2].name))
		{
			if ((!form.elements[count].checked) && (!form.elements[count+1].checked) && (!form.elements[count+2].checked))
			{
				error=true;
				if (first==true)
				{
					errorMsg += tabFields[index][1];
					first=false;
				}
				else
					errorMsg+= (", " + tabFields[index][1]);
			}
			index++;
		}

	}
	if(error==true)
	{
		form.elements[campoIdade-1].disabled= false;
		for(count=1; count<campoHidden; count++)
			form.elements[count].disabled= false;
		form.elements[campoHidden].value= "";
		alert(errorMsg+=".");
		return false;
	}
	/* Confirmação do usuário para enviar os dados */
	if (confirm("Deseja enviar os dados ?"))
		return true;
	else
	{
		for(count=1; count < campoHidden; count++)
			form.elements[count].disabled = false;
		form.elements[campoHidden].value = "";
		return false;
	}
	return false;
}/*---------------------------------------------------------------------*/


/*Função que calcula a idade do paciente*/
function lifetimer(form)
{

	today = new Date()
	ano = document.check.ano.value;
	mes = document.check.mes.value;
	dia = document.check.dia.value;
	ano_atual =today.getFullYear();
	mes_atual =today.getMonth();
	dia_atual =today.getDate();

	switch(mes)
	{
		case '02'://fevereiro
			if((retcode=(ano-1900)%4 )== 0) // Se o ano é bissexto
			{
				if(dia<1 || dia>29)
				{
					alert("Dia inválido:" +"\n" +"Use valores entre 01 e 29, pois este é o mês de Fevereiro");
					diaValido = false;
		document.check.dia.value = "";
		document.check.dia.focus();
					return false;
				}
			}
			else if(dia<1 || dia>28)//O ano não é bissexto
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 28, pois este é o mês de Fevereiro");
				diaValido = false;
			document.check.dia.value = "";
		document.check.dia.focus();
				return false;
			}
		break;
		case '01'://janeiro
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				diaValido = false;
			document.check.dia.value = "";
		document.check.dia.focus();
				return false;
			}
		break;
		case '03'://março
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				diaValido = false;
		document.check.dia.value = "";
		document.check.dia.focus();
				return false;
			}
		break;
		case '05'://maio
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				diaValido = false;
		document.check.dia.value = "";
		document.check.dia.focus();
				return false;
			}
		break;
		case '07'://julho
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				diaValido = false;
		document.check.dia.value = "";
		document.check.dia.focus();
				return false;
			}
		break;
		case '08'://agosto
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				diaValido = false;
			document.check.dia.value = "";
		document.check.dia.focus();
				return false;
			}
		break;
		case '10'://outubro
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				diaValido = false;
					document.check.dia.value = "";
		document.check.dia.focus();
				return false;
			}
		break;
		case '12'://dezembro
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				diaValido = false;
						document.check.dia.value = "";
		document.check.dia.focus();
				return false;
			}
		break;
		case '04'://abril
			if(dia<1 || dia>30)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 30");
				diaValido = false;
						document.check.dia.value = "";
		document.check.dia.focus();
				return false;
			}
		break;
		case '06'://junho
			if(dia<1 || dia>30)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 30");
				diaValido = false;
							document.check.dia.value = "";
		document.check.dia.focus();
				return false;
			}
		break;
		case '09'://setembro
			if(dia<1 || dia>30)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 30");
				diaValido = false;
						document.check.dia.value = "";
		document.check.dia.focus();
				return false;
			}
		break;
		case '11'://novembro
			if(dia<1 || dia>30)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 30");
				diaValido = false;
						document.check.dia.value = "";
		document.check.dia.focus();
				return false;
			}
		break;
		default://mes invalido
			alert("Mês inválido:" +"\n" +"Use valores entre 01 e 12");
			document.check.mes.value = "";
			document.check.mes.focus();
			mesValido = false;
			return false;
	}
	if ((ano_atual - ano < 1) || (ano_atual - ano > 120) || (ano_atual - ano == 1 && mes_atual - mes < 1) || (ano_atual - ano == 1 && mes_atual == mes && dia_atual - dia < 1))
	{
		alert("Ano inválido:\n A idade não deve ser maior que 120 anos, nem menor do que 1 ano.");
			document.check.ano.value = "";
			document.check.ano.focus();
		anoValido = false;
		return false;
	}
	BirthDay = new Date(ano, mes-1 ,dia);
	if(BirthDay.getTime()>today.getTime())
	{
		alert("A data de nascimento não pode ser posterior à data de hoje");
			document.check.ano.value = "";
			document.check.ano.focus();
		anoValido = false;
		return false;
	}
	idade= (ano_atual - ano);
	if(mes-1>mes_atual)
		idade--;
	if(mes-1 == mes_atual)
		if(dia>dia_atual)
			idade--;
	form.elements[campoIdade].value= idade;
}/******************************************************************************************************/

/* Funcao que antecede o calculo da idade a partir da data de nascimento */
function calcularIdade(form)
{
	inval=false;
	if (document.check.dia.value&&document.check.mes.value&&document.check.ano.value)
	{
		if(!isNumberString(document.check.dia.value))
			return(false);
		if(!isNumberString(document.check.mes.value))
			return(false);
		if(!isNumberString(document.check.ano.value))
			return(false);
		lifetimer(form);
	}
}/*--------------------------------------------------------------------------------------*/

/* Funcao que habilita o campo idade se o paciente nao souber sua data de nascimento exata */
function habilitaIdade(form)
{
	today = new Date();
	year= today.getFullYear();
 	if(document.check.habilita_idade.checked)
 	{
		document.check.dia.value= "XX";
		document.check.mes.value = "XX";
		form.elements[campoIdade].readOnly= false;
		document.check.dia.readOnly= false;
		document.check.mes.readOnly = true;
		document.check.ano.readOnly = true;
		form.elements[campoIdade].focus();
	if(form.elements[campoIdade].value != blank)
	{
		if(!isNumberString(form.elements[campoIdade].value)&&form.elements[campoIdade].value != "")
		{
			alert("Valor inválido para idade, digite somente números.");
			idadeValida = false;
			form.elements[campoIdade].value = "";
			return false;
		}
		else
			idadeValida = true;
		if ((form.elements[campoIdade].value < 1 || form.elements[campoIdade].value > 120) && form.elements[campoIdade].value != "")
		{
			alert("Ano inválido:\n A idade não deve ser maior que 120 anos, nem menor do que 1 ano.");
			form.elements[campoIdade].value = "";
			idadeValida = false;
			return false;
		}
		else
			idadeValida = true;
	}
		if(form.elements[campoIdade].value && idadeValida == true)
			document.check.ano.value= year - form.elements[campoIdade].value;
		else
			if (idadeValida == true)
				document.check.ano.value="XXXX";
		document.getElementById("aproximadamente").innerHTML= "&nbsp;&nbsp;" + tabFields[1][1] + " aproximada:";
	}
	else
	{
		document.check.dia.value= '';
		document.check.mes.value = '';
		form.elements[campoIdade].readOnly= true;
		document.check.dia.readOnly= false;
		document.check.mes.readOnly = false;
		document.check.ano.readOnly = false;
		document.check.ano.value= '' ;
		form.elements[campoIdade].value= '';
		document.getElementById("aproximadamente").innerHTML= "&nbsp;&nbsp;" + tabFields[1][1] + ":";
	}
}/*-----------------------------------------------------------------------------------------*/

/* Funcao auxiliar na validacao do dia de nascimento do paciente */
function validarDia()
{
	if (!isNumberString(document.check.dia.value))
	{
		alert("Valor inválido para dia, digite somente números.");
		document.check.dia.value = "";
		document.check.dia.focus();
		diaValido = false;
	}
	else
		if (document.check.dia.value < 1 || document.check.dia.value > 31)
		{
			alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
			document.check.dia.value = "";
			document.check.dia.focus();
			diaValido = false;
		}
		else
		{
			diaValido = true;
			document.check.mes.focus();
		}

}/*----------------------------------------------------------------------*/

/* Funcao auxiliar na validacao do mes de nascimento do paciente */
function validarMes()
{
	if (!isNumberString(document.check.mes.value))
	{
		alert("Valor inválido para mes, digite somente números.");
		document.check.mes.value = "";
		document.check.mes.focus();
		mesValido = false;
	}
	else
		if (document.check.mes.value < 1 || document.check.mes.value > 12)
		{
			alert("Mês inválido:" +"\n" +"Use valores entre 01 e 12");
			document.check.mes.value = "";
			document.check.mes.focus();
			mesValido = false;
		}
		else
		{
			mesValido = true;
			document.check.ano.focus();
		}

}/*-----------------------------------------------------------------------*/

/* Funcao auxiliar na validacao do ano de nascimento do paciente */
function validarAno()
{
	if ((document.check.ano.value.length==4) && (document.check.ano.value != blank))
	{
		if(!isNumberString(document.check.ano.value))
		{
			alert("Valor inválido para ano, digite somente números.");
			anoValido = false;
			document.check.ano.value = "";
			document.check.ano.focus();
		}
		else
			anoValido = true;
		if ((diaValido == true)&&(mesValido==true))
		{
			calcularIdade(check);
			if ((diaValido==true)&&(mesValido==true)&&(anoValido==true))
				document.check.elements[campoIdade+1].focus();
		}
	}
}/*----------------------------------------------------------------------*/

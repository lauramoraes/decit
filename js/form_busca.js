// JavaScript Document

function _options(opcao)

{

	switch(opcao.value)

	{

		case "1":       //todos

			document.getElementById("operador_0").innerHTML="&nbsp;"

			document.getElementById("VALORES_TITULO").innerHTML="&nbsp;"

			document.all.tabela.rows[1].cells[1].innerHTML="&nbsp;"

			document.all.tabela.rows[1].cells[2].innerHTML="&nbsp;"


		break;

		case "2":     //nome

			document.getElementById("operador_0").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Operador</font></strong>"

			document.getElementById("VALORES_TITULO").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Valor</font></strong>"

			document.all.tabela.rows[1].cells[2].innerHTML=eval(("\"<div align='center'> <input id='searchValue' name='nameValue' type='text'  size='55'></div>\""));

			document.all.tabela.rows[1].cells[1].innerHTML=eval(("\"<div align='center'> <select id='operator' name='nameOperator' size='1'><option value='1'>Contém</option><option value='2'>Exatamente igual a</option><option value='3'>Começado por</option><option value='4' selected></option></select></div>\"" ));

		break;

		case "3":    //idade

			document.getElementById("operador_0").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Operador</font></strong>"

			document.getElementById("VALORES_TITULO").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Valor</font></strong>"

			document.all.tabela.rows[1].cells[2].innerHTML="<div align='center'><input id='searchValue' name='"+tabFields[1][0]+"' type='text' id='search2' size='1'></div>"

			document.all.tabela.rows[1].cells[1].innerHTML=eval(("\"<div align='center'> <select id='operator' name='operator' size='1'><option value='1'>Menor que</option><option value='2'>Igual a</option><option value='3'>Maior que</option><option value='4' selected></option></select></div>\"" ));

		break;


		case "4":   //sexo

						document.getElementById("operador_0").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Operador</font></strong>"

			document.getElementById("VALORES_TITULO").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Valor</font></strong>"

			document.all.tabela.rows[1].cells[2].innerHTML= eval("\"<div align='center'> <font face='arial' size='2'><input id='searchValue1'  name='sexoValue' value='" + tabValores[0]+ "' type='radio'>" + tabValores[0] + "<input id='searchValue2'  name='sexoValue' value='" + tabValores[1]+ "' type='radio'> " + tabValores[1]+"</font></div>\"");

									document.all.tabela.rows[1].cells[1].innerHTML=eval(("\"<div align='center'> <select id='operator' name='operator' size='1'><option value='2' selected>Igual a</option></select></div>\"" ));

		break;


		case "5":    //tosse

						document.getElementById("operador_0").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Operador</font></strong>"

			document.getElementById("VALORES_TITULO").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Valor</font></strong>"

			document.all.tabela.rows[1].cells[2].innerHTML=eval("\"<div align='center'> <font face='arial' size='2'><input id='searchValue1'  name='tosseValue' value='" + tabValores[4]+ "' type='radio'>" + tabValores[4] + "<input id='searchValue2' name='tosseValue' value='" + tabValores[5]+ "' type='radio'> " + tabValores[5]+ "<input id='searchValue3' name='tosseValue' value='" + tabValores[6]+ "' type='radio'> " + tabValores[6] + "</font></div>\"");

								document.all.tabela.rows[1].cells[1].innerHTML=eval(("\"<div align='center'> <select id='operator' name='operator' size='1'><option value='2' selected>Igual a</option></select></div>\"" ));

		break;

		case "6":  //hemoptoico

												document.getElementById("operador_0").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Operador</font></strong>"

			document.getElementById("VALORES_TITULO").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Valor</font></strong>"

			document.all.tabela.rows[1].cells[2].innerHTML=eval("\"<div align='center'> <font face='arial' size='2'><input id='searchValue1'  name='hemoptoicoValue' value='" + tabValores[7]+ "' type='radio'>" + tabValores[7] + "<input id='searchValue2'  name='hemoptoicoValue' value='" + tabValores[8]+ "' type='radio'> " + tabValores[8]+ "<input id='searchValue3' name='hemoptoicoValue' value='" + tabValores[6]+ "' type='radio'> " + tabValores[6] + "</font></div>\"");

									document.all.tabela.rows[1].cells[1].innerHTML=eval(("\"<div align='center'> <select id='operator' name='operator' size='1'><option value='2' selected>Igual a</option></select></div>\"" ));

		break;

		case "7":    //sudorese

					document.getElementById("operador_0").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Operador</font></strong>"

			document.getElementById("VALORES_TITULO").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Valor</font></strong>"

			document.all.tabela.rows[1].cells[2].innerHTML=eval("\"<div align='center'> <font face='arial' size='2'><input id='searchValue1'  name='sudoresevalue' value='" + tabValores[4]+ "' type='radio'>" + tabValores[4] + "<input id='searchValue2' name='sudoreseValue' value='" + tabValores[5]+ "' type='radio'> " + tabValores[5]+ "<input id='searchValue3' name='sudoreseValue' value='" + tabValores[6]+ "' type='radio'> " + tabValores[6] + "</font></div>\"");

									document.all.tabela.rows[1].cells[1].innerHTML=eval(("\"<div align='center'> <select id='operator' name='operator' size='1'><option value='2' selected>Igual a</option></select></div>\"" ));

		break;

		case "8":    //febre

												document.getElementById("operador_0").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Operador</font></strong>"

			document.getElementById("VALORES_TITULO").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Valor</font></strong>"

			document.all.tabela.rows[1].cells[2].innerHTML=eval("\"<div align='center'> <font face='arial' size='2'><input id='searchValue1'  name='febreValue' value='" + tabValores[4]+ "' type='radio'>" + tabValores[4] + "<input id='searchValue2' name='febreValue' value='" + tabValores[5]+ "' type='radio'> " + tabValores[5]+ "<input  id='searchValue3' name='febreValue' value='" + tabValores[6]+ "' type='radio'> " + tabValores[6] + "</font></div>\"");

									document.all.tabela.rows[1].cells[1].innerHTML=eval(("\"<div align='center'> <select id='operator' name='operator' size='1'><option value='2' selected>Igual a</option></select></div>\"" ));

		break;

		case "9":  //emagrecimento

												document.getElementById("operador_0").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Operador</font></strong>"

			document.getElementById("VALORES_TITULO").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Valor</font></strong>"

			document.all.tabela.rows[1].cells[2].innerHTML=eval("\"<div align='center'> <font face='arial' size='2'><input id='searchValue1' name='emagrecimentoValue' value='" + tabValores[4]+ "' type='radio'>" + tabValores[4] + "<input id='searchValue2' name='emagrecimentoValue' value='" + tabValores[5]+ "' type='radio'> " + tabValores[5]+ "<input id='searchValue3' name='emagrecimentoValue' value='" + tabValores[6]+ "' type='radio'> " + tabValores[6] + "</font></div>\"");

									document.all.tabela.rows[1].cells[1].innerHTML=eval(("\"<div align='center'> <select id='operator' name='operator' size='1'><option value='2' selected>Igual a</option></select></div>\"" ));

		break;

		case "10":   //dispneia

												document.getElementById("operador_0").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Operador</font></strong>"

			document.getElementById("VALORES_TITULO").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Valor</font></strong>"

			document.all.tabela.rows[1].cells[2].innerHTML=eval("\"<div align='center'> <font face='arial' size='2'><input id='searchValue1'  name='dispneiavalue' value='" + tabValores[4]+ "' type='radio'>" + tabValores[4] + "<input id='searchValue2' name='dispneiaValue' value='" + tabValores[5]+ "' type='radio'> " + tabValores[5]+ "<input id='searchValue3' name='dispneiaValue' value='" + tabValores[6]+ "' type='radio'> " + tabValores[6] + "</font></div>\"");

									document.all.tabela.rows[1].cells[1].innerHTML=eval(("\"<div align='center'> <select id='operator' name='operator' size='1'><option value='2' selected>Igual a</option></select></div>\"" ));

		break;

		case "11":  //anorexia

							document.getElementById("operador_0").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Operador</font></strong>"

			document.getElementById("VALORES_TITULO").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Valor</font></strong>"

			document.all.tabela.rows[1].cells[2].innerHTML=eval("\"<div align='center'> <font face='arial' size='2'><input id='searchValue1' name='anorexiaValue' value='" + tabValores[4]+ "' type='radio'>" + tabValores[4] + "<input id='searchValue2' name='anorexiaValue' value='" + tabValores[5]+ "' type='radio'> " + tabValores[5]+ "<input id='searchValue3' name='anorexiaValue' value='" + tabValores[6]+ "' type='radio'> " + tabValores[6] + "</font></div>\"");

									document.all.tabela.rows[1].cells[1].innerHTML=eval(("\"<div align='center'> <select id='operator' name='operator' size='1'><option value='2' selected>Igual a</option></select></div>\"" ));

		break;

		case "12":    //fuma atualmente

												document.getElementById("operador_0").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Operador</font></strong>"

			document.getElementById("VALORES_TITULO").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Valor</font></strong>"

			document.all.tabela.rows[1].cells[2].innerHTML=eval("\"<div align='center'> <font face='arial' size='2'><input id='searchValue1' name='search12' value='" + tabValores[7]+ "' type='radio'>" + tabValores[7] + "<input id='searchValue2' name='search12' value='" + tabValores[8]+ "' type='radio'> " + tabValores[8]+ "<input id='searchValue3' name='search12' value='" + tabValores[6]+ "' type='radio'> " + tabValores[6] + "</font></div>\"");

									document.all.tabela.rows[1].cells[1].innerHTML=eval(("\"<div align='center'> <select id='operator' name='operator' size='1'><option value='2' selected>Igual a</option></select></div>\"" ));

		break;

		case "13":  //tb extrapulmonar

											document.getElementById("operador_0").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Operador</font></strong>"

			document.getElementById("VALORES_TITULO").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Valor</font></strong>"

			document.all.tabela.rows[1].cells[2].innerHTML=eval("\"<div align='center'> <font face='arial' size='2'><input id='searchValue1'  name='search13' value='" + tabValores[7]+ "' type='radio'>" + tabValores[7] + "<input id='searchValue2' name='search13' value='" + tabValores[8]+ "' type='radio'> " + tabValores[8]+ "<input id='searchValue3' name='search13' value='" + tabValores[6]+ "' type='radio'> " + tabValores[6] + "</font></div>\"");

									document.all.tabela.rows[1].cells[1].innerHTML=eval(("\"<div align='center'> <select id='operator' name='operator' size='1'><option value='2' selected>Igual a</option></select></div>\"" ));

		break;

		case "14": // internacao hospitalar
								document.getElementById("operador_0").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Operador</font></strong>"

			document.getElementById("VALORES_TITULO").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Valor</font></strong>"

			document.all.tabela.rows[1].cells[2].innerHTML=eval("\"<div align='center'> <font face='arial' size='2'><input id='searchValue1'  name='search14' value='" + tabValores[7]+ "' type='radio'>" + tabValores[7] + "<input id='searchValue2' name='search14' value='" + tabValores[8]+ "' type='radio'> " + tabValores[8]+ "<input id='searchValue3' name='search14' value='" + tabValores[6]+ "' type='radio'> " + tabValores[6] + "</font></div>\"");

									document.all.tabela.rows[1].cells[1].innerHTML=eval(("\"<div align='center'> <select id='operator' name='operator' size='1'><option value='2' selected>Igual a</option></select></div>\"" ));
		break;

		case "15": //SIDA
								document.getElementById("operador_0").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Operador</font></strong>"

			document.getElementById("VALORES_TITULO").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Valor</font></strong>"

			document.all.tabela.rows[1].cells[2].innerHTML=eval("\"<div align='center'> <font face='arial' size='2'><input id='searchValue1'  name='search15' value='" + tabValores[7]+ "' type='radio'>" + tabValores[7] + "<input id='searchValue2' name='search15' value='" + tabValores[8]+ "' type='radio'> " + tabValores[8]+ "<input id='searchValue3' name='search15' value='" + tabValores[6]+ "' type='radio'> " + tabValores[6] + "</font></div>\"");

									document.all.tabela.rows[1].cells[1].innerHTML=eval(("\"<div align='center'> <select id='operator' name='operator' size='1'><option value='2' selected>Igual a</option></select></div>\"" ));
		break;

	case "16": //Resultado
		document.getElementById("operador_0").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Operador</font></strong>"
		document.getElementById("VALORES_TITULO").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Valor</font></strong>"
		document.all.tabela.rows[1].cells[1].innerHTML=eval(("\"<div align='center'> <select id='operator' name='operator' size='1'><option value='2' selected>Igual a</option></select></div>\"" ));
		document.all.tabela.rows[1].cells[2].innerHTML=eval("\"<div align='center'> <font face='arial' size='2'><input id='searchValue1'  name='search16' value='Paciente tuberculoso' type='radio'>Tuberculoso<input id='searchValue2' name='search16' value='Paciente não-tuberculoso' type='radio'>Não-Tuberculoso</font></div>\"");
	break;

	case "17": //Grupo de risco
		document.getElementById("operador_0").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Operador</font></strong>"
		document.getElementById("VALORES_TITULO").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Valor</font></strong>"
		document.all.tabela.rows[1].cells[1].innerHTML=eval(("\"<div align='center'> <select id='operator' name='operator' size='1'><option value='2' selected>Igual a</option></select></div>\"" ));
		document.all.tabela.rows[1].cells[2].innerHTML=eval("\"<div align='center'> <font face='arial' size='2'><input id='searchValue1'  name='search17' value='Baixo' type='radio'>Baixo&nbsp;<input id='searchValue2' name='search17' value='Médio' type='radio'>Médio&nbsp;<input id='searchValue3' name='search17' value='Alto' type='radio'>Alto</font></div>\"");
	break;

	case "18": //Visto de análise
		document.getElementById("operador_0").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Operador</font></strong>"
		document.getElementById("VALORES_TITULO").innerHTML="<strong><font color='#666666' size='3' face='Arial, Helvetica, sans-serif'>Valor</font></strong>"
		document.all.tabela.rows[1].cells[1].innerHTML=eval(("\"<div align='center'> <select id='operator' name='operator' size='1'><option value='2' selected>Igual a</option></select></div>\"" ));
		document.all.tabela.rows[1].cells[2].innerHTML=eval("\"<div align='center'> <font face='arial' size='2'><input id='searchValue1'  name='search18' value='Sim' type='radio'>Sim&nbsp;<input id='searchValue2' name='search18' value='Não' type='radio'>Não&nbsp;</font></div>\"");
	break;

		default:

		break;

	}

}

function validarBusca(form)
{
	if(document.getElementById('operator').value == 4)
	{
		alert("Selecione um Operador");
		return(false);
	}
	switch(form.select.selectedIndex)
	{
		case 0:
		break;
		case 1:
			if(document.getElementById('searchValue').value == "")
			{
				alert("Preencha o campo valor");
				return(false);
			}
		break;
		case 2:
			if(form.dia.value == "" || form.mes.value == "" || form.ano.value == "")
			{
				alert("Preencha todos os campos da data de nascimento.");
				return(false);
			}
			if((!validarDia()) || (!validarMes()) || (!validarAnoBusca()) || (!lifetimerBusca()))
				return(false);
		break;
		case 3:
			if(form.operator.value == 1 && form.idade.value <= 1)
			{
				alert("A idade não deve ser menor que 1 ano.");
				return(false);
			}
			if(form.operator.value == 3 && form.idade.value >= 120)
			{
				alert("A idade não deve ser maior que 120 anos.");
				return(false);
			}
			if(form.idade.value == "")
			{
				alert("Preencha o campo valor.");
				return(false);
			}
			if(form.idade.value < 1 || form.idade.value > 120)
			{
				alert("A idade não deve ser menor que 1 ano nem maior que 120 anos.");
				return(false);
			}
			if(!isNumberString(document.check.idade.value))
			{
				alert("Valor inválido para idade digite somente números.");
				return(false);
			}
		break;
		case 4:
			if(document.getElementById('searchValue').value == "")
			{
				alert("Preencha o campo valor");
				return(false);
			}
		break;
		case 5:
		case 6:
			if(document.getElementById('searchValue1').checked == false && document.getElementById('searchValue2').checked == false)
			{
				alert("Preencha o campo valor");
				return(false);
			}
		break;
		default:
			if(document.getElementById('searchValue1').checked == false && document.getElementById('searchValue2').checked == false && document.getElementById('searchValue3').checked == false)
			{
				alert("Preencha o campo valor");
				return(false);
			}
		break;
	}
	return(true);
}

function lifetimerBusca(form)
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
					document.check.dia.focus();
					document.check.dia.select();
					return false;
				}
			}
			else if(dia<1 || dia>28)//O ano não é bissexto
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 28, pois este é o mês de Fevereiro");
				diaValido = false;
					document.check.dia.focus();
					document.check.dia.select();
				return false;
			}
		break;
		case '01'://janeiro
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				diaValido = false;
					document.check.dia.focus();
					document.check.dia.select();
				return false;
			}
		break;
		case '03'://março
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				diaValido = false;
					document.check.dia.focus();
					document.check.dia.select();
				return false;
			}
		break;
		case '05'://maio
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				diaValido = false;
					document.check.dia.focus();
					document.check.dia.select();
				return false;
			}
		break;
		case '07'://julho
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				diaValido = false;
					document.check.dia.focus();
					document.check.dia.select();
				return false;
			}
		break;
		case '08'://agosto
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				diaValido = false;
					document.check.dia.focus();
					document.check.dia.select();
				return false;
			}
		break;
		case '10'://outubro
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				diaValido = false;
					document.check.dia.focus();
					document.check.dia.select();
				return false;
			}
		break;
		case '12'://dezembro
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				diaValido = false;
					document.check.dia.focus();
					document.check.dia.select();
				return false;
			}
		break;
		case '04'://abril
			if(dia<1 || dia>30)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 30");
				diaValido = false;
					document.check.dia.focus();
					document.check.dia.select();
				return false;
			}
		break;
		case '06'://junho
			if(dia<1 || dia>30)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 30");
				diaValido = false;
					document.check.dia.focus();
					document.check.dia.select();
				return false;
			}
		break;
		case '09'://setembro
			if(dia<1 || dia>30)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 30");
				diaValido = false;
					document.check.dia.focus();
					document.check.dia.select();
				return false;
			}
		break;
		case '11'://novembro
			if(dia<1 || dia>30)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 30");
				diaValido = false;
					document.check.dia.focus();
					document.check.dia.select();
				return false;
			}
		break;
		default://mes invalido
			alert("Mês inválido:" +"\n" +"Use valores entre 01 e 12");
			document.check.mes.focus();
			document.check.mes.select();
			mesValido = false;
			return false;
	}
	if ((ano_atual - ano < 1) || (ano_atual - ano > 120) || (ano_atual - ano == 1 && mes_atual - mes < 1) || (ano_atual - ano == 1 && mes_atual == mes && dia_atual - dia < 1))
	{
		alert("Ano inválido:\n A idade não deve ser maior que 120 anos, nem menor do que 1 ano.");
		document.check.ano.focus();
		document.check.ano.select();
		anoValido = false;
		return false;
	}
	BirthDay = new Date(ano, mes-1 ,dia);
	if(BirthDay.getTime()>today.getTime())
	{
		alert("A data de nascimento não pode ser posterior à data de hoje");
		document.check.ano.focus();
		document.check.ano.select();
		anoValido = false;
		return false;
	}
	idade= (ano_atual - ano);
	if(mes-1>mes_atual)
		idade--;
	if(mes-1 == mes_atual)
		if(dia>dia_atual)
			idade--;
	return true;
}/******************************************************************************************************/


/* Funcao auxiliar na validacao do ano de nascimento do paciente */
function validarAnoBusca()
{
	if ((document.check.ano.value.length==4) && (document.check.ano.value != blank))
		if(!isNumberString(document.check.ano.value))
		{
			alert("Valor inválido para ano, digite somente números.");
			anoValido = false;
			document.check.ano.focus();
			document.check.ano.select();
			return false;
		}
		else
		{
			anoValido = true;
			return true;
		}
}/*----------------------------------------------------------------------*/





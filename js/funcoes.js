function exibeLinhaOculta(tabela, linha)
{
	document.getElementById(tabela).rows[linha].style.display = "";
}

function ocultaLinha(tabela, linha)
{
	document.getElementById(tabela).rows[linha].style.display = "none";
}

function enviar()
{
	var i;
	var j;
	var str = "Linhas escondidas: ";
	var nroLinhas = document.getElementById('tabelaSintomas').rows.length - 8;
	for(i = 0; i < nroLinhas; i++)
		if(document.getElementById('tabelaSintomas').rows[i].style.display != "none")
			for(j = 0; j < document.getElementById('tabelaSintomas').rows[i].getElementsByTagName("input").length; j++)
			{
				nomeCampo = document.getElementById('tabelaSintomas').rows[i].getElementsByTagName("input")[j].name;
				switch(document.getElementsByName(nomeCampo).length)
				{
					case 1:
						if(document.getElementById('tabelaSintomas').rows[i].getElementsByTagName("input")[j].value == "")
						{
							alert("Falha no envio: há campos não preenchidos.");
							return false;
						}
					break;
					case 2:
					if(document.getElementById('tabelaSintomas').rows[i].getElementsByTagName("input")[j].checked == false && document.getElementById('tabelaSintomas').rows[i].getElementsByTagName("input")[++j].checked == false)
					{
						alert("Falha no envio: há campos não preenchidos.");
						return false;
					}
					break;
					case 3:
					if(document.getElementById('tabelaSintomas').rows[i].getElementsByTagName("input")[j].checked == false && document.getElementById('tabelaSintomas').rows[i].getElementsByTagName("input")[++j].checked == false && document.getElementById('tabelaSintomas').rows[i].getElementsByTagName("input")[++j].checked == false)
					{
						alert("Falha no envio: há campos não preenchidos.");
						return false;
					}
					break;
				}
			}
	document.getElementById('idade').readOnly = false;
	return true;
}

function isNumberString(InString)
{
	if(InString.length==0)
		return (true);
	var RefString="1234567890";
	for (Count=0; Count < InString.length; Count++)
	{
		TempChar= InString.substring (Count, Count+1);
		if (RefString.indexOf (TempChar, 0)==-1)
			return (false);
	}
	return (true);
}

function validarCampoNumerico(campo)
{
	if(!isNumberString(campo.value))
	{
		alert("Valor inválido, digite somente números.");
		campo.focus();
		campo.select();
	}
}

function validarPorcentagem(campo)
{
	if(campo.value > 100)
	{
		alert("Digite um valor entre 0 e 100.");
		campo.focus();
		campo.select();
	}
}

function validarDia(campoDia)
{
	if(campoDia.value.length != 2)
	{
		alert("O campo dia deve conter dois dígitos.");
		campoDia.focus();
		campoDia.select();
		return false;
	}
	if(!isNumberString(campoDia.value))
	{
		alert("Valor inválido para dia, digite somente números.");
		campoDia.focus();
		campoDia.select();
		return false;
	}
	if(campoDia.value < 1 || campoDia.value > 31)
	{
		alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
		campoDia.focus();
		campoDia.select();
		return false;
	}
	return true;
}

function validarMes(campoMes)
{
	if(campoMes.value.length != 2)
	{
		alert("O campo mês deve conter dois dígitos.");
		campoMes.focus();
		campoMes.select();
		return false;
	}
	if (!isNumberString(campoMes.value))
	{
		alert("Valor inválido para mês, digite somente números.");
		campoMes.focus();
		campoMes.select();
		return false;
	}
	if (campoMes.value < 1 || campoMes.value > 12)
	{
		alert("Mês inválido:" +"\n" +"Use valores entre 01 e 12");
		campoMes.focus();
		campoMes.select();
		return false;
	}
	return true;
}

function validarAno(campoAno)
{
	if(campoAno.value.length != 4)
	{
		alert("O campo ano deve conter quatro dígitos.");
		campoAno.focus();
		campoAno.select();
		return false;
	}
	if(!isNumberString(campoAno.value))
	{
		alert("Valor inválido para ano, digite somente números.");
		campoAno.focus();
		campoAno.select();
		return false;
	}
	return true;
}

function validarIdade(campoIdade)
{
	if(!isNumberString(campoIdade.value))
	{
		alert("Valor inválido para idade, digite somente números.");
		campoIdade.focus();
		campoIdade.select();
		return false;
	}			
	if ((campoIdade.value < 1 || campoIdade.value > 120) && campoIdade.value != "")
	{
		alert("Ano inválido:\n A idade não deve ser maior que 120 anos, nem menor do que 1 ano.");
		campoIdade.focus();
		campoIdade.select();
		return false;
	}
	return true;
}

function validarData(form)
{
	today = new Date();
	dia = form.dia_nascimento.value;
	mes = form.mes_nascimento.value;
	ano = form.ano_nascimento.value;
	dia_atual =today.getDate();
	mes_atual =today.getMonth();
	ano_atual =today.getFullYear();

	switch(mes)
	{
		case '01'://janeiro
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				form.dia_nascimento.focus();
				form.dia_nascimento.select();
				return false;
			}
		break;
		case '02'://fevereiro
		if((retcode=(ano-1900)%4 )== 0) // Se o ano é bissexto
		{
			if(dia<1 || dia>29)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 29, pois este é o mês de Fevereiro");
				form.dia_nascimento.focus();
				form.dia_nascimento.select();
				return false;
			}
		}
		else 
			if(dia<1 || dia>28)//O ano não é bissexto
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 28, pois este é o mês de Fevereiro");
				form.dia_nascimento.focus();
				form.dia_nascimento.select();
				return false;
			}
		break;
		case '03'://março
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				form.dia_nascimento.focus();
				form.dia_nascimento.select();
				return false;
			}
		break;
		case '04'://abril
		if(dia<1 || dia>30)
		{
			alert("Dia inválido:" +"\n" +"Use valores entre 01 e 30");
			form.dia_nascimento.focus();
			form.dia_nascimento.select();
			return false;
		}
		break;
		case '05'://maio
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				form.dia_nascimento.focus();
				form.dia_nascimento.select();
				return false;
			}
		break;
		case '06'://junho
		if(dia<1 || dia>30)
		{
			alert("Dia inválido:" +"\n" +"Use valores entre 01 e 30");
			form.dia_nascimento.focus();
			form.dia_nascimento.select();
			return false;
		}
		break;
		case '07'://julho
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				form.dia_nascimento.focus();
				form.dia_nascimento.select();
				return false;
			}
		break;
		case '08'://agosto
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				form.dia_nascimento.focus();
				form.dia_nascimento.select();
				return false;
			}
		break;
		case '09'://setembro
			if(dia<1 || dia>30)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 30");
				form.dia_nascimento.focus();
				form.dia_nascimento.select();
				return false;
			}
		break;
		case '10'://outubro
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				form.dia_nascimento.focus();
				form.dia_nascimento.select();
				return false;
			}
		break;
		case '11'://novembro
			if(dia<1 || dia>30)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 30");
				form.dia_nascimento.focus();
				form.dia_nascimento.select();
				return false;
			}
		break;
		case '12'://dezembro
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				form.dia_nascimento.focus();
				form.dia_nascimento.select();
				return false;
			}
		break;
		default://mes invalido
		alert("Mês inválido:" +"\n" +"Use valores entre 01 e 12");
		form.mes_nascimento.focus();
		form.mes_nascimento.select();
		return false;
	}
	if ((ano_atual - ano < 1) || (ano_atual - ano > 120) || (ano_atual - ano == 1 && mes_atual - mes < 1) || (ano_atual - ano == 1 && mes_atual == mes && dia_atual - dia < 1))
	{
		alert("Ano inválido:\n A idade não deve ser maior que 120 anos, nem menor do que 1 ano.");
		form.ano_nascimento.focus();
		form.ano_nascimento.select();
		return false;
	}
	BirthDay = new Date(ano, mes-1 ,dia);
	if(BirthDay.getTime()>today.getTime())
	{
		alert("A data de nascimento não pode ser posterior à data de hoje");
		form.ano_nascimento.focus();
		form.ano_nascimento.select();
		return false;
	}
	return true;
}

function habilitaIdade(form)
{
	if(form.habilita_idade.checked)
 	{
		form.dia_nascimento.value = "XX";
		form.mes_nascimento.value = "XX";
		form.ano_nascimento.value = "XXXX";
		form.idade.value = "";
		form.idade.readOnly= false;
		form.dia_nascimento.readOnly= true;
		form.mes_nascimento.readOnly = true;
		form.ano_nascimento.readOnly = true;
		form.idade.focus();
		document.getElementById("aproximadamente").innerHTML = tabFields[6][1] + " aproximada:";
	}
	else
	{
		form.dia_nascimento.value= '';
		form.mes_nascimento.value = '';
		//aqui true
		form.idade.readOnly= true;
		form.dia_nascimento.readOnly= false;
		form.mes_nascimento.readOnly = false;
		form.ano_nascimento.readOnly = false;
		form.ano_nascimento.value= '' ;
		form.idade.value= '';
		document.getElementById("aproximadamente").innerHTML = tabFields[6][1] + ":";
		form.dia_nascimento.focus();
	}
}

function calcularAnoNascimento(idade)
{
	today = new Date();
	anoAtual = today.getFullYear();
	return(anoAtual - idade);
}

function calcularIdade(diaNascimento, mesNascimento, anoNascimento)
{
	today = new Date();
	diaAtual =today.getDate();
	mesAtual =today.getMonth();
	anoAtual = today.getFullYear();
	idade= (anoAtual - anoNascimento);
	if(mesNascimento-1 > mesAtual)
		idade--;
	if(mesNascimento-1 == mesAtual)
		if(diaNascimento > diaAtual)
			idade--;
	return(idade);
}

function getElement(aID){ 
    return (document.getElementById(aID)) || document.all[aID];
}

function validarHora(campo)
{
	if(campo.value > 23)
	{
		alert("Digite um valor entre 0 e 23.");
		campo.focus();
		campo.select();
		return false;
	}
	return true
}

function validarMinuto(campo)
{
	if(campo.value > 59)
	{
		alert("Digite um valor entre 0 e 59.");
		campo.focus();
		campo.select();
		return false
	}
	return true
}

function validarAnosRio()
{
	if(document.check.idade.value < document.check.naturalidadeAnosRio.value)
	{
		alert("O valor deve ser menor do que a idade do paciente.");
		naturalidadeAnosRio.focus();
		naturalidadeAnosRio.select();
	}
}

function validarQualquerData(campoDia,campoMes,campoAno)
{
	today = new Date();
	dia = campoDia.value;
	mes = campoMes.value;
	ano = campoAno.value;
	dia_atual =today.getDate();
	mes_atual =today.getMonth();
	ano_atual =today.getFullYear();

	switch(mes)
	{
		case '01'://janeiro
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				campoDia.focus();
				campoDia.select();
				return false;
			}
		break;
		case '02'://fevereiro
		if((retcode=(ano-1900)%4 )== 0) // Se o ano é bissexto
		{
			if(dia<1 || dia>29)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 29, pois este é o mês de Fevereiro");
				campoDia.focus();
				campoDia.select();
				return false;
			}
		}
		else 
			if(dia<1 || dia>28)//O ano não é bissexto
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 28, pois este é o mês de Fevereiro");
				campoDia.focus();
				campoDia.select();
				return false;
			}
		break;
		case '03'://março
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				campoDia.focus();
				campoDia.select();
				return false;
			}
		break;
		case '04'://abril
		if(dia<1 || dia>30)
		{
			alert("Dia inválido:" +"\n" +"Use valores entre 01 e 30");
			campoDia.focus();
			campoDia.select();
			return false;
		}
		break;
		case '05'://maio
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				campoDia.focus();
				campoDia.select();
				return false;
			}
		break;
		case '06'://junho
		if(dia<1 || dia>30)
		{
			alert("Dia inválido:" +"\n" +"Use valores entre 01 e 30");
			campoDia.focus();
			campoDia.select();
			return false;
		}
		break;
		case '07'://julho
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				campoDia.focus();
				campoDia.select();
				return false;
			}
		break;
		case '08'://agosto
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				campoDia.focus();
				campoDia.select();
				return false;
			}
		break;
		case '09'://setembro
			if(dia<1 || dia>30)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 30");
				campoDia.focus();
				campoDia.select();
				return false;
			}
		break;
		case '10'://outubro
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				campoDia.focus();
				campoDia.select();
				return false;
			}
		break;
		case '11'://novembro
			if(dia<1 || dia>30)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 30");
				campoDia.focus();
				campoDia.select();
				return false;
			}
		break;
		case '12'://dezembro
			if(dia<1 || dia>31)
			{
				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
				campoDia.focus();
				campoDia.select();
				return false;
			}
		break;
		default://mes invalido
		alert("Mês inválido:" +"\n" +"Use valores entre 01 e 12");
		campoMes.focus();
		campoMes.select();
		return false;
	}
	/*if ((ano_atual - ano < 1) || (ano_atual - ano > 120) || (ano_atual - ano == 1 && mes_atual - mes < 1) || (ano_atual - ano == 1 && mes_atual == mes && dia_atual - dia < 1))
	{
		alert("Ano inválido:\n A idade não deve ser maior que 120 anos, nem menor do que 1 ano.");
		campoAno.focus();
		campoAno.select();
		return false;
	}
	BirthDay = new Date(ano, mes-1 ,dia);
	if(BirthDay.getTime()>today.getTime())
	{
		alert("A data de nascimento não pode ser posterior à data de hoje");
		campoAno.focus();
		campoAno.select();
		return false;
	} */
	return true;
}

function showmenu(elmnt)
{
	document.getElementById(elmnt).style.visibility="visible";
}
function hidemenu(elmnt)
{
	document.getElementById(elmnt).style.visibility="hidden";
}
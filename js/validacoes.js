/* Arquivo para o projeto NeuralTB
     Universidade Federal do Rio de Janeiro
     Escola Politecnica
     Departamento de Engenharia Eletronica e de Computacao
	
     Laboratorio de Processamento de Sinais
	
     Autor: Luiz Evora
     Atualizacao: Laura de Oliveira Fernandes Moraes
     Ultima atualizacao: 21/07/2008 */



	function changeClass(identidade,classe)
	{
		document.getElementById(identidade).className = classe;
	}
		
	function changeNumber(identidade,numero)
	{
		document.getElementById(identidade).innerHTML = numero + ".";
	}
		
	function isNumberString(InString)
	{
		if(InString.length==0)
		return (true);
		var RefString="1234567890";
		for (i=0; i < InString.length; i++)
		{
			TempChar= InString.substring (i, i+1);
			if (RefString.indexOf (TempChar, 0)==-1)
			return (false);
		}
		return (true);
	}

	function validarCampoNumerico(campo, tamanho, minimo, maximo)
    	{
	globalvar = campo;
      	    if((campo.value.length != tamanho) && (tamanho != 0))
       	    {
    	   	alert("O campo deve conter " + tamanho +  " dígitos.");
			setTimeout("globalvar.focus()",250);
           	//campo.select();
           	return false;
	    }
	    if(!isNumberString(campo.value))
	    {
        	alert("Valor inválido, digite somente números.");
		    setTimeout("globalvar.focus()",250);
		    //campo.select();
		    return false;
	    }
	    if((campo.value < minimo || campo.value > maximo) && (maximo != 0 ))
	    {
        	alert("Número inválido:" + "\n" + "Use valores entre " + minimo + " e " +  maximo);
		    setTimeout("globalvar.focus()",250);
		    //campo.select();
		    return false;
		}
	        return true;
	}

    function calcularCarga(cigarros, tempo)
    {
		carga = ((cigarros.value)*(tempo.value));
        return (carga);
	}
          
    function validarData(campoDia,campoMes,campoAno)
    {
		
	}
      
    function data(dia,mes,ano)
    {
       	if(dia.value!=''&& mes.value!='' && ano.value != '')
	{

    		today = new Date();
		    dia_atual =today.getDate();
		    mes_atual =today.getMonth();
		    ano_atual =today.getFullYear();
 	       switch(mes.value)
		    {
	    		case '01'://janeiro
			case '03'://março
			case '05'://maio
			case '07'://julho
			case '08'://agosto
			case '10'://outubro
			case '12'://dezembro
				if(dia.value<1 || dia.value>31)
				{
                			alert("Dia inválido:" +"\n" +"Use valores entre 01 e 31");
					globalvar = dia;
					setTimeout("globalvar.focus()",250);
				    	return false;
				}
			break;
			case '02'://fevereiro
			    	if((retcode=(ano.value-1900)%4 )== 0) // Se o ano é bissexto
		        	{
			    		if(dia.value<1 || dia.value>29)
				        {
        			            	alert("Dia inválido:" +"\n" +"Use valores entre 01 e 29, pois este é o mês de Fevereiro");
						globalvar = dia;
						setTimeout("globalvar.focus()",250);
					        return false;
			        	}
		        	}
		        	else 
			    		if(dia.value<1 || dia.value>28)//O ano não é bissexto
			      		{
                       				alert("Dia inválido:" +"\n" +"Use valores entre 01 e 28, pois este é o mês de Fevereiro");
						globalvar = dia;
						setTimeout("globalvar.focus()",250);
					       return false;
			              	}
				break;
			case '04'://abril
			case '06'://junho
			case '09'://setembro
			case '11'://novembro
		    		if(dia.value<1 || dia.value>30)
			        {
        		        	alert("Dia inválido:" +"\n" +"Use valores entre 01 e 30");
					globalvar = dia;
					setTimeout("globalvar.focus()",250);
			        	return false;
		        	}
			break;
			default://mes invalido
		    		alert("Mês inválido:" +"\n" +"Use valores entre 01 e 12");
				globalvar = mes;
				setTimeout("globalvar.focus()",250);
			      	return false;
		}
       		BirthDay = new Date(ano.value, mes.value-1 ,dia.value);
		if(BirthDay.getTime()>today.getTime())
	        {
        		alert("A data não pode ser posterior a data de hoje");
			globalvar = ano;
			setTimeout("globalvar.focus()",250);
			    return false;
	        } 
		return true;
	}
	}

	function verifNascimento(diaNasc,mesNasc,anoNasc,dia,mes,ano)
	{
		if (diaNasc.value != '' && mesNasc.value != '' && anoNasc.value != '' && dia.value!=''&& mes.value!='' && ano.value != '')
			if (ano.value < anoNasc.value)
			{
				alert("Data menor que a data de nascimento");
				globalvar = ano;
				setTimeout("globalvar.focus()",250);
				return false;
			}
			else if (ano.value == anoNasc.value)
				if (mes.value < mesNasc.value)
				{
					alert("Data menor que a data de nascimento");
					globalvar = mes;
					setTimeout("globalvar.focus()",250);
					return false;
				}
				else if (mes.value == mesNasc.value)
					if (dia.value < diaNasc.value)
					{
						alert("Data menor que a data de nascimento");
						globalvar = dia;
						setTimeout("globalvar.focus()",250);
						return false;
					}
		return true;
	}

	function comparaData(diaNasc,mesNasc,anoNasc)
	{
		if (verifNascimento(diaNasc,mesNasc,anoNasc,document.getElementsByName('diaEntr')[0],document.getElementsByName('mesEntr')[0],document.getElementsByName('anoEntr')[0]) == true)
			if (verifNascimento(diaNasc,mesNasc,anoNasc,document.getElementsByName('dia')[0],document.getElementsByName('mes')[0],document.getElementsByName('ano')[0]) == true)
				if (verifNascimento(diaNasc,mesNasc,anoNasc,document.getElementsByName('diaExame')[0],document.getElementsByName('mesExame')[0],document.getElementsByName('anoExame')[0]) == true)
					if (verifNascimento(diaNasc,mesNasc,anoNasc,document.getElementsByName('diaLeit')[0],document.getElementsByName('mesLeit')[0],document.getElementsByName('anoLeit')[0]) == true)
						if (verifNascimento(diaNasc,mesNasc,anoNasc,document.getElementsByName('diaUCons')[0],document.getElementsByName('mesUCons')[0],document.getElementsByName('anoUCons')[0]) == true)
							return true;
		return false;
	}

	function escolherTabela(tabela)
	{
		if (tabela == "empty") //Escolhendo a tabela
			return ("tabelaRecusa");
		else if (tabela == "tabelaRecusa")
			return ("tabelaCaracterizacao");
		else if (tabela == "tabelaCaracterizacao")
			return ("tabelaSintomas");
		else if (tabela == "tabelaSintomas")
			return ("tabelaAvaliacao");
		else if (tabela == "tabelaAvaliacao")
			return ("tabelaComplementar");
		else
			return ("tabelaAcompanhamento");
	}

    function inicializaOcultos()
    {
		var i;
		var tabela = "empty";
		do
		{
			tabela = escolherTabela(tabela);
			for (i = 1; i < document.getElementById(tabela).rows.length; i++)
		     	document.getElementById(tabela).rows[i].style.display = "none";//
		 }while (tabela != "tabelaAcompanhamento");

		document.getElementById("tabelaAvaliacao").rows[0].style.display = "none";//
					
	}
			 
	function exibeForm(cidade)
	{	
	 	var i;
	 	var tabela="empty";
	 	do
		{	
			tabela = escolherTabela(tabela);
			for (i = 0; i < document.getElementById(tabela).rows.length; i++)
			{
				switch (tabela) //Verifica se as linhas podem ser exibidas ou não
				{ //Formato: (((Linhas que nao sao exibidas somente para curitiba) || (Linhas que nao sao exibidas somente para outras cidades)) && (Linhas que nao sao exibidas para as duas))
					case "tabelaRecusa":
						if ((((cidade == "curitiba") && (i != 1) && (i != 5) && (i != 8)) || ((cidade != "curitiba") && (i != 2) && (i != 6) && (i != 9))) && (i !=3) && (i != 10))
							document.getElementById(tabela).rows[i].style.display = "";//
					break;
					case "tabelaCaracterizacao":
						if ((((cidade == "curitiba") && (i != 5)) || (cidade != "curitiba")) && (i != 4) && (i != 9) && (i != 13) && (i != 15) && (i != 27) && (i != 28) && (i != 29) && (i != 32) && (i != 33))
							document.getElementById(tabela).rows[i].style.display = "";//
					break;
					case "tabelaSintomas":
						if ((((cidade == "curitiba") && (i != 21)) || (cidade != "curitiba")) && ((i != 3) && (i != 4) && (i != 6) && (i != 7) && (i != 9) && (i != 10) && (i != 13) && (i != 14) && (i != 20) && ((i < 22) || (i > 40)) && (i != 42)))
							document.getElementById(tabela).rows[i].style.display = "";//
					break;
					case "tabelaComplementar":
						if ((((cidade == "curitiba") && (i != 2) && (i != 3) && (i != 6) && (i != 7) && (i != 8)) || ((cidade != "curitiba") && (i != 12) && (i != 16))) && ((i != 13) && (i != 17) && (i != 20)))
							document.getElementById(tabela).rows[i].style.display = "";//
					break;
					case "tabelaAcompanhamento":
						if (i != 6)
							document.getElementById(tabela).rows[i].style.display = "";//
					break;
					default:
						document.getElementById(tabela).rows[i].style.display = "";//
				}
			}
		}while (tabela != "tabelaComplementar");
	}
	
	function showHideAcompanhamento(box)
	{
		var i;
		var tabela="tabelaAcompanhamento";
		
		for (i = 0; i < document.getElementById(tabela).rows.length; i++)
		{
			
			if (box.checked = true)
			{
				if (i != 6)
				{
					document.getElementById(tabela).rows[i].style.display = "";//
				}
			}
			else
			{
				document.getElementById(tabela).rows[i].style.display = "none";
			}
		}
	}
	
	function hideAcompanhamento()
	{
		var i;
		var tabela="tabelaAcompanhamento";
		
		for (i = 1; i < document.getElementById(tabela).rows.length; i++)
			document.getElementById(tabela).rows[i].style.display = "none";
	}
		
			 
	function exibeSintomas()
    {
		var i = 22;
		while (i <41)
		{
			if ((i != 23) && (i != 24) && (i != 25) && (i != 27))
				document.getElementById("tabelaSintomas").rows[i].style.display = "";
			i++;
		}
	}
			 
	function ocultaSintomas()
    {
		var i;
		for (i = 22; i < 41; i++)
	    	document.getElementById("tabelaSintomas").rows[i].style.display = "none";//
	}
	
	function exibeLinhaOculta(tabela, linha)
    {
    	document.getElementById(tabela).rows[linha].style.display = "";
    }

    function ocultaLinha(tabela, linha)
    {
    	document.getElementById(tabela).rows[linha].style.display = "none";
	}
             
	function  enviar(tabela)
	{
    	    var i, j;
	    var k = 0;
	    var nroLinhas = document.getElementById(tabela).rows.length;
	    var aviso,numero,numero1,linha;
	    var nomeAnterior;
    	    var boolean = 1;
	    var haveSpace = 0;

    	for(i = 0; i < nroLinhas; i++) //varro as linhas
	    {
			if ((tabela != "tabelaRecusa") && (tabela != "tabelaAvaliacao") && (document.getElementById(tabela).rows[i].getElementsByTagName("td")[0].innerHTML != ''))
				numero = document.getElementById(tabela).rows[i].getElementsByTagName("td")[0].innerHTML;
		
		if(document.getElementById(tabela).rows[i].style.display != "none") //entra só qnd aparece
		{
			for(j = 0; j < document.getElementById(tabela).rows[i].getElementsByTagName("input").length; j++) //varre os inputs dentro da linha
			{
				if (document.getElementById(tabela).rows[i].getElementsByTagName("input")[j].disabled != true) //Se o campo não está desabilitado
				{
					haveSpace = 0;
					k = 0;
					campo = document.getElementById(tabela).rows[i].getElementsByTagName("input")[j]
			        nomeCampo=campo.name; //pego o nome do input

			        	switch(document.getElementsByName(nomeCampo).length) //vejo quantos inputs tem com esse nome
			        	{
			          	 case 1:        //Verifica se não há somente espacos
					   		while ((haveSpace == 0) && (k < campo.value.length)) 
							{
								if (campo.value.substring(k,k+1) != " ")
									haveSpace = 1;
								k++;
							}
							if((campo.value == "") || (haveSpace == 0))
						    	{
								showAlert(tabela,numero);
								globalvar = campo;
								setTimeout("globalvar.focus()",250);
								return false;
							}
					   break;
					   default: //Verifica se ao menos um entre vários campos com o mesmo nome está marcado
							if ((nomeCampo != nomeAnterior) && (boolean == 1))
							{
								nomeAnterior = nomeCampo;
								boolean = 0;
							}
							if ((nomeCampo == nomeAnterior) && (campo.checked == true))
								boolean = 1;
							else if ((nomeCampo != nomeAnterior) && (boolean == 0))
							{
								showAlert(tabela,numero1);
								globalvar = document.getElementsByName(nomeAnterior)[0];
								setTimeout("globalvar.focus()",250);
								return false;
							}
					   		if ((tabela != "tabelaRecusa") && (tabela != "tabelaAvaliacao") && (document.getElementById(tabela).rows[i].getElementsByTagName("td")[0].innerHTML != ''))
								numero1 = document.getElementById(tabela).rows[i].getElementsByTagName("td")[0].innerHTML;
								numero = numero1;
						   break;
					}
		        	}
			 }

			for(j = 0; j < document.getElementById(tabela).rows[i].getElementsByTagName("textarea").length; j++) //varre os textarea dentro da linha
			{
				haveSpace = 0;
				k = 0;
				campo = document.getElementById(tabela).rows[i].getElementsByTagName("textarea")[j]

				if (campo.name.substring(0,3) != "obs") //Os campo que comecam com obs não possuem preenchimento obrigatório
				{	//Verifica se os outros campos não estão preenchidos somente com espacos
					while ((haveSpace == 0) && (k < campo.value.length)) 
					{
						if (campo.value.substring(k,k+1) != " ")
							haveSpace = 1;
						k++;
					}
					if((campo.value == "") || (haveSpace == 0))
					{
						showAlert(tabela,numero);
						globalvar = campo;
						setTimeout("globalvar.focus()",250);
						return false;
					}
				}
			}
		}
	    }	
			if (boolean == 0 )
			{
				showAlert(tabela,numero1);
				globalvar = document.getElementsByName(nomeAnterior)[0];
				setTimeout("globalvar.focus()",250);
				return false;
			}
    			return true;
	}
	
	function changeColor (campo)
	{
		if (campo.disabled == true)
			campo.style.backgroundColor = "#CCCCCC";
		else
			campo.style.backgroundColor = "white";
	}

	function showAlert(tabela,numero)
	{
		if (tabela == "tabelaRecusa")
			aviso = "na primeira parte (fundo cinza)."
		else if (tabela == "tabelaCaracterizacao")
			aviso = "no formulário número um, pergunta " + numero;
		else if (tabela == "tabelaSintomas")
			aviso = "no formulário número dois, pergunta " + numero;
		else if  (tabela == "tabelaAvaliacao")
			aviso = "no formulário número dois, na auto-avaliação."
		else if (tabela == "tabelaComplementar")
			aviso = "no formulário número três, pergunta " + numero;
		else if (tabela == "tabelaAcompanhamento")
			aviso = "no formulário número quatro, pergunta " + numero;
		alert("Falha no envio: há campos não preenchidos " + aviso);
	}
	
	function confirmaEnvio()
	{
		if ((enviar('tabelaRecusa') == true) && (enviar('tabelaCaracterizacao') == true) && (enviar('tabelaSintomas') == true) && (enviar('tabelaAvaliacao') == true) && (enviar('tabelaComplementar') == true) && (enviar('tabelaAcompanhamento') == true))
			return true;
		else
			return false;
	}

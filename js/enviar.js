// JavaScript Document
//Atualização do arquivo validações.jsfunction  enviar(tabela)
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

				if ((campo.name.substring(0,3) != "obs") && (campo.name.substring(0,11) != "complemento")) //Os campo que comecam com obs e complemento não possuem preenchimento obrigatório
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
	
		
		/*tamanho = document.getElementsByName(nomeCampo).length; //vejo quantos inputs tem com esse nome

			        	if (tamanho == 1) 
			        	{   //Verifica se não há somente espacos
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
						
					   	if (document.getElementsByName(nomeAnterior).length > 1)
							tamanho++;
							
						if (tamanho > 1)
						{
						   //Verifica se ao menos um entre vários campos com o mesmo nome está marcado
							if ((nomeCampo != nomeAnterior) && (boolean == 1))
							{
								nomeAnterior = nomeCampo;
								boolean = 0;
							}
							if ((nomeCampo == nomeAnterior) && (campo.checked == true))
								boolean = 1;
							else if ((nomeCampo != nomeAnterior) && (boolean == 0))
							{
								showAlert(tabela,numero-1);
								globalvar = document.getElementsByName(nomeAnterior)[0];
								setTimeout("globalvar.focus()",250);
								return false;
							}
						}
		        	}
			 	}*/
				
				

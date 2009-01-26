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

		case "2.nome":     //nome

			document.getElementById("operador_0").innerHTML="<div class=\"styleBusca2\">Operador</div>"

			document.getElementById("VALORES_TITULO").innerHTML="<div class=\"styleBusca2\">Valor</div>"

			document.all.tabela.rows[1].cells[2].innerHTML=eval(("\"<div align='center'> <input id='searchValue' name='valor' type='text'  size='55'></div>\""));

			document.all.tabela.rows[1].cells[1].innerHTML=eval(("\"<div align='center'> <select id='operator' name='nameOperator' size='1'><option value='1'>Contém</option><option value='2'>Exatamente igual a</option><option value='3'>Começado por</option><option value='4' selected></option></select></div>\"" ));

		break;

		case "3.cidade":    //Cidade de estudo

			document.getElementById("operador_0").innerHTML="<div class=\"styleBusca2\">Operador</div>"

			document.getElementById("VALORES_TITULO").innerHTML="<div class=\"styleBusca2\">Valor</div>"

			document.all.tabela.rows[1].cells[2].innerHTML=eval(("\"<div align='center'> <select id='searchValue2' name='valor' size='1'><option value='Curitiba/Paraná'>Curitiba/Paraná</option><option value='Fortaleza/Ceará'>Fortaleza/Ceará</option><option value='Itaboraí/RJ'>Itaboraí/RJ</option><option value='4' selected>Qual cidade?</option></select></div>\"" ));

			document.all.tabela.rows[1].cells[1].innerHTML="&nbsp;"

		break;

		case "4.numfns":  //No do CAT-SUS

			document.getElementById("operador_0").innerHTML="<div class=\"styleBusca2\">Operador</div>"

			document.getElementById("VALORES_TITULO").innerHTML="<div class=\"styleBusca2\">Valor</div>"

			document.all.tabela.rows[1].cells[2].innerHTML=eval(("\"<div align='center'> <input id='searchValue5' name='valor' type='text'  size='10' maxlength='11'></div>\""));

            document.all.tabela.rows[1].cells[1].innerHTML="&nbsp;"

		break;

		case "5.profsaude":    //psaude

			document.getElementById("operador_0").innerHTML="<div class=\"styleBusca2\">Operador</div>"

			document.getElementById("VALORES_TITULO").innerHTML="<div class=\"styleBusca2\">Valor</div>"

			document.all.tabela.rows[1].cells[2].innerHTML=eval("\"<div align='center'> <font face='arial' size='2'><input id='searchValue6'  name='valor' value='Sim' type='radio'> Sim <input id='searchValue66' name='psaude' value='Não' type='radio'> Não </font></div>\"");

			document.all.tabela.rows[1].cells[1].innerHTML="&nbsp;"

		break;

		case "6.tosse":    //Sintomas

			document.getElementById("operador_0").innerHTML="<div class=\"styleBusca2\">Operador</div>"

			document.getElementById("VALORES_TITULO").innerHTML="<div class=\"styleBusca2\">Valor</div>"

			document.all.tabela.rows[1].cells[2].innerHTML=eval("\"<div align='center'> <font face='arial' size='2'><input id='searchValue6'  name='tosse' value='Sim' type='radio'> Sim <input id='searchValue66' name='tosse' value='Não' type='radio'> Não </font></div>\"");

			document.all.tabela.rows[1].cells[1].innerHTML="&nbsp;"

		break;
		
				case "7.catarr":    //Sintomas

			document.getElementById("operador_0").innerHTML="<div class=\"styleBusca2\">Operador</div>"

			document.getElementById("VALORES_TITULO").innerHTML="<div class=\"styleBusca2\">Valor</div>"

			document.all.tabela.rows[1].cells[2].innerHTML=eval("\"<div align='center'> <font face='arial' size='2'><input id='searchValue6'  name='catarr' value='Sim' type='radio'> Sim <input id='searchValue66' name='catarr' value='Não' type='radio'> Não </font></div>\"");

			document.all.tabela.rows[1].cells[1].innerHTML="&nbsp;"

		break;
		
				case "8.hempti":    //Sintomas

			document.getElementById("operador_0").innerHTML="<div class=\"styleBusca2\">Operador</div>"

			document.getElementById("VALORES_TITULO").innerHTML="<div class=\"styleBusca2\">Valor</div>"

			document.all.tabela.rows[1].cells[2].innerHTML=eval("\"<div align='center'> <font face='arial' size='2'><input id='searchValue6'  name='hempti' value='Sim' type='radio'> Sim <input id='searchValue66' name='hempti' value='Não' type='radio'> Não </font></div>\"");

			document.all.tabela.rows[1].cells[1].innerHTML="&nbsp;"

		break;
		
				case "9.sudore":    //Sintomas

			document.getElementById("operador_0").innerHTML="<div class=\"styleBusca2\">Operador</div>"

			document.getElementById("VALORES_TITULO").innerHTML="<div class=\"styleBusca2\">Valor</div>"

			document.all.tabela.rows[1].cells[2].innerHTML=eval("\"<div align='center'> <font face='arial' size='2'><input id='searchValue6'  name='sudore' value='Sim' type='radio'> Sim <input id='searchValue66' name='sudore' value='Não' type='radio'> Não </font></div>\"");

			document.all.tabela.rows[1].cells[1].innerHTML="&nbsp;"

		break;

		case "9":  //Prob. de TB pela enfermeira

			document.getElementById("operador_0").innerHTML="<div class=\"styleBusca2\">Operador</div>"

			document.getElementById("VALORES_TITULO").innerHTML="<div class=\"styleBusca2\">Valor</div>"

			document.all.tabela.rows[1].cells[2].innerHTML=eval(("\"<div align='center'> <select id='searchValue8' name='prob' size='1'><option value='1'>Alta</option><option value='2'>Média</option><option value='3'>Baixa</option><option value='4'>Não sei</option><option value='5' selected>Qual?</option></select></div>\"" ));

			document.all.tabela.rows[1].cells[1].innerHTML="&nbsp;"

		break;

		default:

		break;

	}

}

function validarBusca(form)
{
 	switch(form.select.selectedIndex)
	{
		case 0:
		break;
		case 1:
		    if(document.getElementById('operator').value == 4)
	        {
                alert("Selecione um Operador");
		        return(false);
	        }
			if(document.getElementById('searchValue').value == "")
			{
				alert("Preencha o campo valor");
				return(false);
			}
		break;
		case 2:
            if(document.getElementById('searchValue2').value == 4)
	        {
		        alert("Selecione uma Cidade");
                return(false);
	        }
		break;
		case 3:
            if(document.getElementById('searchValue3').value == 6)
	        {
		        alert("Selecione uma unidade");
                return(false);
	        }
		break;
		case 4:
             if(document.getElementById('searchValue4').value == 6)
	        {
		        alert("Selecione um tipo");
                return(false);
	        }
		break;
		case 5:
		    	if(document.getElementById('searchValue5').value == "")
			{
				alert("Preencha o campo valor");
				return(false);
			}
		break;
		case 6:
            if(document.getElementById('searchValue6').checked == false && document.getElementById('searchValue66').checked == false)
			{
				alert("Selecione sim ou não");
				return(false);
			}
		break;
		case 7:
              if(document.getElementById('searchValue7').value == 15)
	        {
		        alert("Selecione um sintoma");
                return(false);
	        }
		break;
		case 8:
               if(document.getElementById('searchValue8').value == 5)
	        {
		        alert("Selecione um valor");
                return(false);
	        }
		break;

		default:

		break;
	}
	return(true);
}


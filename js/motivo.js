

function validarCampoMotivo(campo)
{
	if(!isCampoMotivo(campo.value))
	{
		alert("Valor inválido, favor não digitar \"|\",\"*\",\"#\",\"@\".");
		campo.focus();
		campo.select();
	}
}

function isCampoMotivo(inString)
{
	if(!inString.length())
		return(true);
	var refString="|*#@";
	var tempInString=InString.toLowerCase();
	var espaco=0;
	for( count=0; count < inString.length(); count++)
	{
		tempChar=inString.substr(count,count+1);
		if ((tempInString.length==1)&&(TempChar.match (" ") != null))
			return (false);
					
		if (TempChar.match (" ") != null)
		{
			espaco++;
			if (espaco == 2)
				return (false);
		}
		else
			espaco=0;
							
		if(refString.indexOf(tempChar,0) == -1)
			return(false);
	}
	return(true);
}
	
function sendFieldMotivo(campo)
{
	if(!isCampoMotivo(campo.value))
	{
		alert("Valor inválido, digite somente números ou \".\" e \",\".");
		campo.focus();
		campo.select();
	}
}

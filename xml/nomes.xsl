<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/doc">
<html>
<head>
<title>.:. Projeto Neural TB .:.</title>
<link  rel="stylesheet" type="text/css" href="css/standart.css"/>
<script language="javascript" src="js/validacoes.js"></script>
<script>
	var linha = 0;
	function contaLinha()
	{
		linha+=1;
	}
</script>

</head>
<table width="600" align="center" cellspacing="1" cellpadding="0" id="xml">
<xsl:for-each select="paciente">
<tr class="nome">
	<td width="100" align="left" >
           Nome:
	</td>
	<td> <xsl:value-of select ="nome" /></td>
</tr>
</xsl:for-each>
</table>
</body>
</html>
</xsl:template>
</xsl:stylesheet>

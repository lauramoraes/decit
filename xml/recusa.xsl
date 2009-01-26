<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/doc">
<html>
<head>
<title>.:. Projeto Neural TB .:.</title>
</head>
<body>
<table align="center" cellspacing="5" cellpadding="0">
<xsl:for-each select ="paciente">
<tr class="par">
    <td align="right" >Cidade de Estudo:</td>
    <td ><xsl:value-of select ="cidade" /></td>
</tr>
<xsl:choose>
  <xsl:when test="cidade = 'Curitiba/Paraná'">
<tr class="impar">
	<td align="right" >Tipo de Unidade de Saúde:</td>
	<td ><xsl:value-of select ="unidadeCurit" /></td>
</tr>
<tr class="par">
	<td align="right" >Recusa:</td>
	<td ><xsl:value-of select ="recusaCurit" /></td>
</tr>
  </xsl:when>
  <xsl:otherwise>
<tr class="impar">
	<td align="right" >Tipo de Unidade de Saúde:</td>
	<td ><xsl:value-of select ="unidade" /></td>
</tr>
<tr class="par">
	<td align="right" >Recusa:</td>
	<td ><xsl:value-of select ="recusa" /></td>
</tr>
  </xsl:otherwise>
</xsl:choose>
<tr class="impar">
	<td align="right">Idade:</td>
	<td ><xsl:value-of select ="idade" /></td>
</tr>
<tr class="par">
	<td align="right" >Sexo:</td>
	<td ><xsl:value-of select ="sexo1" /></td>
</tr>
<tr class="impar">
	<td align="right">Tem febre ou emagrecimento?</td>
	<td ><xsl:value-of select ="tem" /></td>
</tr>
<tr class="par">
	<td align="right">Poderia dizer o motivo da recusa?</td>
	<td ><xsl:value-of select ="motivo" /></td>
</tr>
<tr><td></td></tr>
</xsl:for-each>
</table>
</body>
</html>
</xsl:template>
</xsl:stylesheet>

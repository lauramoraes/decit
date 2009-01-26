<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:param name="upperCase" select="'ABCDEFGHIJKLMNOPQRSTUVWXYZ'"/>
<xsl:param name="lowerCase" select="'abcdefghijklmnopqrstuvwxyz'"/>
<xsl:param name="searchTextToTranslate" select="'Maria'"/>
<xsl:variable name="translatedSearchText" select="translate($searchTextToTranslate, $upperCase, $lowerCase)"/>
<xsl:template match="/">
<xsl:variable name="contador">
0
<xsl:for-each select="doc/paciente">
<xsl:if test="contains(translate(nome, $upperCase, $lowerCase), $translatedSearchText)">
<xsl:number count="paciente" />
</xsl:if>
</xsl:for-each>
</xsl:variable>
<html>
<head>
<title>.:. Resultados da busca .:. Projeto Neural TB .:.</title>
<link rel="stylesheet" type="text/css" href="../css/standard.css"/>
</head>
<body>
<xsl:choose>
<xsl:when test="$contador != 0">
<table id="tabelaPacientes" width="100%" border="1" bordercolor="#FFFFFF" cellspacing="0" cellpadding="2">
<tr class="styleBusca1">
<th width="100">Marcador</th>
<th width="50">Nome</th>
<th width="100">Data de Nascimento</th>
<th width="100">Sexo</th>
<th width="50">Tosse</th>
<th width="100">Dor torácica/Dor no peito</th>
<th width="100">Sudorese Noturna</th>
<th width="50">Febre</th>
<th width="50">Emagrecimento</th>
<th width="50">Dispnéia</th>
<th width="100">Hábito de fumar</th>
<th width="100">Internação Hospitalar</th>
</tr>
<xsl:for-each select="doc/paciente">
<xsl:if test="contains(translate(nome, $upperCase, $lowerCase), $translatedSearchText)">
<tr class="fundoTabela" align="center" onClick="var marcador = 'marcador' + this.rowIndex;if(document.getElementById(marcador).checked == true) document.getElementById('tabelaPacientes').rows[this.rowIndex].style.background = '#99CCFF'; else document.getElementById('tabelaPacientes').rows[this.rowIndex].style.background = '#FFFFFF';">
<td>
<xsl:number count="paciente" format="001" />
</td>
<td>
<xsl:value-of select="nome"/>
</td>
<td>
<xsl:value-of select="diaNasc"/>/<xsl:value-of select="mesNasc"/>/<xsl:value-of select="anoNasc"/>
</td>
<td>
<xsl:value-of select="sexo"/>
</td>
<td>
<xsl:value-of select="tosse"/>
</td>
<td>
<xsl:value-of select="hempto"/>
</td>
<td>
<xsl:value-of select="sudore"/>
</td>
<td>
<xsl:value-of select="febre"/>
</td>
<td>
<xsl:value-of select="emagre"/>
</td>
<td>
<xsl:value-of select="dispn"/>
</td>
<td>
<xsl:value-of select="fumo"/>
</td>
<td>
<xsl:value-of select="intern"/>
</td>
</tr>
</xsl:if>
</xsl:for-each>
</table>
</xsl:when>
<xsl:otherwise>
<p>&#160;&#160;&#160;&#160;&#160;<b>Não foram encontrados pacientes.</b></p>
</xsl:otherwise>
</xsl:choose>
</body>
</html>
</xsl:template>
</xsl:stylesheet>

<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="2.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<!--<xsl:output method="html" version="1.0" encoding="ISO-8859-1" omit-xml-declaration="yes"/>-->
<xsl:template match="/doc">
<!-- Ajeitar tempo entrevista -->
<!-- Tempo de fumo n�o tem unidade -->
<html>
<head>
<title>.:. Projeto Neural TB .:.</title>
<link  rel="stylesheet" type="text/css" href="../css/standart.css"/>
<script language="javascript" src="js/validacoes.js"></script>
</head>
<body>
<table width="600" align="center" cellspacing="1" cellpadding="0" id="xml">
<xsl:for-each select="paciente">
<tr class="nome">
	<td width="100" align="left" >


           Nome:
    </td>
	<td > <xsl:value-of select ="NOME" /></td>
</tr>
 <tr class="forms">
     <td colspan="2">
            - Entrevista
     </td>
</tr>
<tr class="impar">
	<td align="left" >Tipo de Unidade de Sa�de:</td>
	<td ><xsl:value-of select ="TIPOUS" /></td>
</tr>
<tr class="par">
	<td align="left" >Tipo de participante:</td>
	<td ><xsl:value-of select ="TIPOP" /></td>
</tr>
<tr class="impar">
	<td align="left" >US:</td>
	<td ><xsl:value-of select ="US" /></td>
</tr>
<tr class="par">
	<td align="left" >Entrevistador:</td>
	<td ><xsl:value-of select ="ENTREV" /></td>
</tr>
<tr class="impar">
	<td align="left" >Data da Entrevista:</td>
	<td ><xsl:value-of select ="DATAE" /></td>
</tr>
<tr class="par">
	<td align="left" >Hor�rio do in�cio da entrevista:</td>
	<td ><xsl:value-of select ="HORAI" /></td>
</tr>
<tr class="forms">
     <td colspan="2">


           1.  Caracteriza��o Socioecon�mica / S�cio-demogr�fica / H�bitos de Vida
     </td>
</tr>
<tr class="impar">
	<td align="left" >Data de Nascimento:</td>
	<td ><xsl:value-of select ="DATAN" /></td>
</tr>
<tr class="impar">
	<td align="left" >- Idade:</td>
	<td ><xsl:value-of select ="IDADE" /></td>
</tr>
<tr class="par">
	<td align="left" >G�nero:</td>
	<td ><xsl:value-of select ="SEXO" /></td>
</tr>
<tr class="impar">
	<td align="left" >Cor da pele:</td>
	<td ><xsl:value-of select ="COR" /></td>
</tr>
<xsl:if test="COR = 'Outra'">
        <tr class="impar">
		<td align="left" >- Qual?</td>
		<td ><xsl:value-of select ="COROU" /></td>
	</tr>
</xsl:if>
<tr class="par">
	<td align="left" >Situa��o conjugal:</td>
	<td ><xsl:value-of select ="ESTCIV" /></td>
</tr>
<tr class="impar">
	<td align="left" >Naturalidade - Estado:</td>
	<td ><xsl:value-of select ="NATEST" /></td>
</tr>
<tr class="impar">
	<td align="left" >Naturalidade - Cidade:</td>
	<td ><xsl:value-of select ="NATMUN" /></td>
</tr>
<tr class="par">
	<td align="left" >J� morou em outro local diferente do munic�pio atual?</td>
	<td ><xsl:value-of select ="MOROUT" /></td>
</tr>
<xsl:if test="MOROUT = 'Sim'">
        <tr class="par">
		<td align="left" >- Onde?</td>
		<td ><xsl:value-of select ="MOROUT1" /></td>
	</tr>
</xsl:if>
<tr class="impar">
	<td align="left" >No momento voc� est�:</td>
	<td ><xsl:value-of select ="FUNCAO" /></td>
</tr>
<xsl:if test="FUNCAO = 'Outros'">
        <tr class="impar">
		<td align="left" >- Qual?</td>
		<td ><xsl:value-of select ="QUAL" /></td>
	</tr>
</xsl:if>
<tr class="par">
	<td align="left" >Profissional de Sa�de:</td>
	<td ><xsl:value-of select ="PROFSAUD" /></td>
</tr>
<tr class="impar">
	<td align="left" >Grau de instru��o do chefe da fam�lia:</td>
	<td ><xsl:value-of select ="GRINST" /></td>
</tr>
<tr class="par">
	<td align="left" >Tem empregada mensalista em casa?</td>
	<td ><xsl:value-of select ="EMPREGAD" /></td>
</tr>
<tr class="impar">
	<td align="left" >Autom�vel:</td>
	<td ><xsl:value-of select ="AUTO" /></td>
</tr>
<tr class="par">
	<td align="left" >Banheiro:</td>
	<td ><xsl:value-of select ="BANHEI" /></td>
</tr>
<tr class="impar">
	<td align="left" >Freezer (ou duplex):</td>
	<td ><xsl:value-of select ="FREEZER" /></td>
</tr>
<tr class="par">
	<td align="left" >Geladeira duplex:</td>
	<td ><xsl:value-of select ="GEL" /></td>
</tr>
<tr class="par">
	<td align="left" >M�qu. de lavar roupa:</td>
	<td ><xsl:value-of select ="MLAV" /></td>
</tr>
<tr class="impar">
	<td align="left" >R�dio:</td>
	<td ><xsl:value-of select ="RAD" /></td>
</tr>
<tr class="par">
	<td align="left" >TV em cores:</td>
	<td ><xsl:value-of select ="TV" /></td>
</tr>
<tr class="impar">
	<td align="left" >Videocassete/DVD:</td>
	<td ><xsl:value-of select ="VIDEO" /></td>
</tr>
<tr class="par">
	<td align="left" >Foi morador de rua nos �ltimos 2 anos?</td>
	<td ><xsl:value-of select ="MORRUA" /></td>
</tr>
<tr class="impar">
	<td align="left" >Mora(ou) em asilos rua nos �ltimos 2 anos?</td>
	<td ><xsl:value-of select ="MORASIL" /></td>
</tr>
<tr class="par">
	<td align="left" >Ex-detento?</td>
	<td ><xsl:value-of select ="PRESIDI" /></td>
</tr>
<tr class="impar">
	<td align="left" >Esteve internado nos �ltimos dois anos?</td>
	<td ><xsl:value-of select ="INTER" /></td>
</tr>
<tr class="par">
	<td align="left" >Que unidade de sa�de voc� procura quando adoece?</td>
	<td ><xsl:value-of select ="QUEUNI" /></td>
</tr>
<tr class="impar">
	<td align="left" >Conhece o agente de sa�de do bairro?</td>
	<td ><xsl:value-of select ="CONHACS" /></td>
</tr>
<tr class="par">
	<td align="left" >Em rela��o ao h�bito de fumar...</td>
	<td ><xsl:value-of select ="FUMO" /></td>
</tr>
<xsl:if test="FUMO = 'Ex-fumante'">
        <tr class="par">
		<td align="left" >- Parou de fumar h� quanto tempo?</td>
		<td ><xsl:value-of select ="TEMPFU" /></td>
	</tr>
	<tr class="par">
		<td align="left" >- N�mero de cigarros que fuma ou fumava por dia?</td>
		<td ><xsl:value-of select ="CIGARROS" /> cigarros</td>
	</tr>
	<tr class="par">
		<td align="left" >- N�mero de anos que fuma ou fumou?</td>
		<td ><xsl:value-of select ="ANO" /> anos</td>
	</tr>
	<tr class="par">
		<td align="left" >- Carga tab�gica:</td>
		<td ><xsl:value-of select ="CARGTAB" /> (ma�os-cigarros/ano)</td>
	</tr>
</xsl:if>
<xsl:if test="FUMO = 'Fumante atual'">
        <tr class="par">
		<td align="left" >- N�mero de cigarros que fuma ou fumava por dia?</td>
		<td ><xsl:value-of select ="CIGARROS" /> cigarros</td>
	</tr>
	<tr class="par">
		<td align="left" >- N�mero de anos que fuma ou fumou?</td>
		<td ><xsl:value-of select ="ANO" /> anos</td>
	</tr>
	<tr class="par">
		<td align="left" >- Carga tab�gica:</td>
		<td ><xsl:value-of select ="CARGTAB" /> (ma�os-cigarros/ano)</td>
	</tr>
</xsl:if>
<tr class="impar">
	<td align="left" >Uso de drogas (inalat�rias / injet�veis):</td>
	<td ><xsl:value-of select ="DROGAS" /></td>
</tr>
<tr class="par">
	<td align="left" >Bebida alco�lica preferida:</td>
	<td ><xsl:value-of select ="ALCOOL" /></td>
</tr>
<xsl:if test="ALCOOL = 'Outras'">
        <tr class="par">
		<td align="left" >- Qual?</td>
		<td ><xsl:value-of select ="especif" /></td>
	</tr>
</xsl:if>
<tr class="forms">
      <td colspan="2">


           2.	Avalia��o Inicial/Cl�nica do Contato/Sintom�tico Respirat�rio/Suspeito
      </td>
</tr>
<tr class="par">
	<td align="left" >Morou antes com algu�m com tuberculose no pulm�o, familiar ou n�o?</td>
	<td ><xsl:value-of select ="MORATB" /></td>
</tr>
<tr class="par">
	<td align="left" >Teve (tem) algu�m da fam�lia com tuberculose no pulm�o?</td>
	<td ><xsl:value-of select ="FAMILTB" /></td>
</tr>
<tr class="par">
	<td align="left" >Teve (tem) algu�m do c�rculo de amizade/trabalho com tuberculose no pulm�o?</td>
	<td ><xsl:value-of select ="AMIGOTB" /></td>
</tr>
<xsl:choose>
	<xsl:when test="MORATB = 'Sim'">
	<tr class="par">
		<td align="left" >- Qual a m�dia de horas de contato por dia?</td>
		<td ><xsl:value-of select ="TABHOR" /></td>
	</tr>
	<tr class="par">
		<td align="left" >- H� quanto tempo o caso �ndice tosse?</td>
		<td ><xsl:value-of select ="TPTSEIND" /></td>
	</tr>
  	</xsl:when>
	<xsl:when test="FAMILTB = 'Sim'">
	<tr class="par">
		<td align="left" >- Qual a m�dia de horas de contato por dia?</td>
		<td ><xsl:value-of select ="TABHOR" /></td>
	</tr>
	<tr class="par">
		<td align="left" >- H� quanto tempo o caso �ndice tosse?</td>
		<td ><xsl:value-of select ="TPTSEIND" /></td>
	</tr>
  	</xsl:when>
	<xsl:when test="AMIGOTB = 'Sim'">
	<tr class="par">
		<td align="left" >- Qual a m�dia de horas de contato por dia?</td>
		<td ><xsl:value-of select ="TABHOR" /></td>
	</tr>
	<tr class="par">
		<td align="left" >- H� quanto tempo o caso �ndice tosse?</td>
		<td ><xsl:value-of select ="TPTSEIND" /></td>
	</tr>
  	</xsl:when>
  	<xsl:otherwise>
  	</xsl:otherwise>
</xsl:choose>
<tr class="impar">
	<td align="left" >Tomou alguma vez estes rem�dios?</td>
	<td ><xsl:value-of select ="TIPOQX" /></td>
</tr>
<tr class="par">
	<td align="left" >Teve tuberculose no passado?</td>
	<td ><xsl:value-of select ="TBPREV" /></td>
</tr>
<xsl:if test="TBPREV = 'Sim'">
        <tr class="par">
		<td align="left" >- H� quantos anos?</td>
		<td ><xsl:value-of select ="DTTBPAST" /></td>
	</tr>
	<tr class="par">
		<td align="left" >- Qual foi o resultado (desfecho) do tratamento anti-TB?</td>
		<td ><xsl:value-of select ="TBDESF" /></td>
	</tr>
	<tr class="par">
		<td align="left" >- Resultado do tratamento notificado no SINAN:</td>
		<td ><xsl:value-of select ="SINAN" /></td>
	</tr>
</xsl:if>
<tr class="impar">
	<td align="left" >Cicatriz vacinal BCG?</td>
	<td ><xsl:value-of select ="CICBCG" /></td>
</tr>
<tr class="par">
	<td align="left" >Tem falta de ar ou enfisema?</td>
	<td ><xsl:value-of select ="DISPENF" /></td>
</tr>
<tr class="impar">
	<td align="left" >Tem asma ou bronquite?</td>
	<td ><xsl:value-of select ="ASMABROQ" /></td>
</tr>
<tr class="par">
	<td align="left" >Tem ou teve outros problemas de sa�de?</td>
	<td ><xsl:value-of select ="OUTROPBL" /></td>
</tr>
<xsl:if test="OUTROPBL = 'Sim'">
        <tr class="par">
		<td align="left" >- Qual?</td>
		<td ><xsl:value-of select ="TIPOPROBL" /></td>
	</tr>
</xsl:if>
<tr class="impar">
	<td align="left" >Tosse:</td>
	<td ><xsl:value-of select ="TOSSE" /></td>
</tr>
<xsl:if test="TOSSE = 'Sim'">
        <tr class="impar">
		<td align="left" >- H� quantas semanas (em dias)?</td>
		<td ><xsl:value-of select ="TOSSETEMP" /> dias</td>
	</tr>
</xsl:if>
<tr class="par">
	<td align="left" >Catarro/Expectora��o:</td>
	<td ><xsl:value-of select ="EXPECT" /></td>
</tr>
<xsl:if test="EXPECT = 'Sim'">
        <tr class="par">
		<td align="left" >- H� quantas semanas (em dias)?</td>
		<td ><xsl:value-of select ="EXPECTEMP" /> dias</td>
	</tr>
</xsl:if>
<tr class="impar">
	<td align="left" >Sangue no catarro/Hemoptise:</td>
	<td ><xsl:value-of select ="HEMPTI" /></td>
</tr>
<tr class="par">
	<td align="left" >Dor Tor�cica/dor no peito:</td>
	<td ><xsl:value-of select ="DOTTX" /></td>
</tr>
<tr class="impar">
	<td align="left" >Febre:</td>
	<td ><xsl:value-of select ="FEBRE" /></td>
</tr>
<tr class="par">
	<td align="left" >Suores � noite:</td>
	<td ><xsl:value-of select ="SUDORESE" /></td>
</tr>
<tr class="impar">
	<td align="left" >Falta de apetite:</td>
	<td ><xsl:value-of select ="HIPORE" /></td>
</tr>
<tr class="par">
	<td align="left" >Emagrecimento:</td>
	<td ><xsl:value-of select ="EMAGRE" /></td>
</tr>
<tr class="impar">
	<td align="left" >Peso anterior:</td>
	<td ><xsl:value-of select ="PESOANT" /> kg</td>
</tr>
<tr class="impar">
	<td align="left" >Peso atual:</td>
	<td ><xsl:value-of select ="PESOAT" /> kg</td>
</tr>
<xsl:if test="PESOANT &gt; PESOAT">
        <tr class="impar">
		<td align="left" >- Diferen�a de peso:</td>
		<td ><xsl:value-of select ="DIFPESO" /> kg</td>
	</tr>
	<tr class="impar">
		<td align="left" >- Porcentagem de peso perdida:</td>
		<td ><xsl:value-of select ="CORELPESO" />%</td>
	</tr>
</xsl:if>
<tr class="par">
	<td align="left" >Cansa�o:</td>
	<td ><xsl:value-of select ="ASTENI" /></td>
</tr>
<tr class="impar">
	<td align="left" >Rouquid�o:</td>
	<td ><xsl:value-of select ="ROUQUI" /></td>
</tr>
<tr class="par">
	<td align="left" >�nguas:</td>
	<td ><xsl:value-of select ="LINFON" /></td>
</tr>
<tr class="impar">
	<td align="left" >Falta de ar (Dispn�ia):</td>
	<td ><xsl:value-of select ="DISPN" /></td>
</tr>
<tr class="par">
	<td align="left" >Chiado no peito:</td>
	<td ><xsl:value-of select ="CHIADO" /></td>
</tr>
<tr class="impar">
	<td align="left" >Outros sintomas:</td>
	<td ><xsl:value-of select ="OUTSINT" /></td>
</tr>
<xsl:if test="OUTSINT = 'Sim'">
        <tr class="par">
		<td align="left" >- Qual?</td>
		<td ><xsl:value-of select ="TIPOSINT" /></td>
	</tr>
</xsl:if>
<tr class="par">
	<td align="left" >Hor�rio de encerramento da entrevista:</td>
	<td ><xsl:value-of select ="HORAF" /></td>
</tr>
<tr class="impar">
	<td align="left" >Tempo de entrevista:</td>
	<td ><xsl:value-of select ="TEMPOENT" /></td>
</tr>
<tr class="impar">
	<td align="left" >Probabilidade de tuberculose pulmonar ativa apenas com os dados desta entrevista (sintomas) - PARA EQUIPE DE ENFERMAGEM:</td>
	<td ><xsl:value-of select ="PROBSINT" /></td>
</tr>
<tr class="par">
	<td align="left" >Condi��es da entrevista:</td>
	<td ><xsl:value-of select ="ENTREV" /></td>
</tr>
<tr class="impar">
	<td align="left" >Colabora��o do entrevistado:</td>
	<td ><xsl:value-of select ="ENTEVTADO" /></td>
</tr>
<tr class="par">
	<td align="left" >Credibilidade das respostas na sua opini�o:</td>
	<td ><xsl:value-of select ="OPNIAO" /></td>
</tr>
</xsl:for-each>
</table>
</body>
</html>
</xsl:template>
</xsl:stylesheet>

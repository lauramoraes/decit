<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="2.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<!--<xsl:output method="html" version="1.0" encoding="ISO-8859-1" omit-xml-declaration="yes"/>-->
<xsl:template match="/doc">
<!-- Ajeitar tempo entrevista -->
<!-- Tempo de fumo não tem unidade -->
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
	<td align="left" >Tipo de Unidade de Saúde:</td>
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
	<td align="left" >Horário do início da entrevista:</td>
	<td ><xsl:value-of select ="HORAI" /></td>
</tr>
<tr class="forms">
     <td colspan="2">


           1.  Caracterização Socioeconômica / Sócio-demográfica / Hábitos de Vida
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
	<td align="left" >Gênero:</td>
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
	<td align="left" >Situação conjugal:</td>
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
	<td align="left" >Já morou em outro local diferente do município atual?</td>
	<td ><xsl:value-of select ="MOROUT" /></td>
</tr>
<xsl:if test="MOROUT = 'Sim'">
        <tr class="par">
		<td align="left" >- Onde?</td>
		<td ><xsl:value-of select ="MOROUT1" /></td>
	</tr>
</xsl:if>
<tr class="impar">
	<td align="left" >No momento você está:</td>
	<td ><xsl:value-of select ="FUNCAO" /></td>
</tr>
<xsl:if test="FUNCAO = 'Outros'">
        <tr class="impar">
		<td align="left" >- Qual?</td>
		<td ><xsl:value-of select ="QUAL" /></td>
	</tr>
</xsl:if>
<tr class="par">
	<td align="left" >Profissional de Saúde:</td>
	<td ><xsl:value-of select ="PROFSAUD" /></td>
</tr>
<tr class="impar">
	<td align="left" >Grau de instrução do chefe da família:</td>
	<td ><xsl:value-of select ="GRINST" /></td>
</tr>
<tr class="par">
	<td align="left" >Tem empregada mensalista em casa?</td>
	<td ><xsl:value-of select ="EMPREGAD" /></td>
</tr>
<tr class="impar">
	<td align="left" >Automóvel:</td>
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
	<td align="left" >Máqu. de lavar roupa:</td>
	<td ><xsl:value-of select ="MLAV" /></td>
</tr>
<tr class="impar">
	<td align="left" >Rádio:</td>
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
	<td align="left" >Foi morador de rua nos últimos 2 anos?</td>
	<td ><xsl:value-of select ="MORRUA" /></td>
</tr>
<tr class="impar">
	<td align="left" >Mora(ou) em asilos rua nos últimos 2 anos?</td>
	<td ><xsl:value-of select ="MORASIL" /></td>
</tr>
<tr class="par">
	<td align="left" >Ex-detento?</td>
	<td ><xsl:value-of select ="PRESIDI" /></td>
</tr>
<tr class="impar">
	<td align="left" >Esteve internado nos últimos dois anos?</td>
	<td ><xsl:value-of select ="INTER" /></td>
</tr>
<tr class="par">
	<td align="left" >Que unidade de saúde você procura quando adoece?</td>
	<td ><xsl:value-of select ="QUEUNI" /></td>
</tr>
<tr class="impar">
	<td align="left" >Conhece o agente de saúde do bairro?</td>
	<td ><xsl:value-of select ="CONHACS" /></td>
</tr>
<tr class="par">
	<td align="left" >Em relação ao hábito de fumar...</td>
	<td ><xsl:value-of select ="FUMO" /></td>
</tr>
<xsl:if test="FUMO = 'Ex-fumante'">
        <tr class="par">
		<td align="left" >- Parou de fumar há quanto tempo?</td>
		<td ><xsl:value-of select ="TEMPFU" /></td>
	</tr>
	<tr class="par">
		<td align="left" >- Número de cigarros que fuma ou fumava por dia?</td>
		<td ><xsl:value-of select ="CIGARROS" /> cigarros</td>
	</tr>
	<tr class="par">
		<td align="left" >- Número de anos que fuma ou fumou?</td>
		<td ><xsl:value-of select ="ANO" /> anos</td>
	</tr>
	<tr class="par">
		<td align="left" >- Carga tabágica:</td>
		<td ><xsl:value-of select ="CARGTAB" /> (maços-cigarros/ano)</td>
	</tr>
</xsl:if>
<xsl:if test="FUMO = 'Fumante atual'">
        <tr class="par">
		<td align="left" >- Número de cigarros que fuma ou fumava por dia?</td>
		<td ><xsl:value-of select ="CIGARROS" /> cigarros</td>
	</tr>
	<tr class="par">
		<td align="left" >- Número de anos que fuma ou fumou?</td>
		<td ><xsl:value-of select ="ANO" /> anos</td>
	</tr>
	<tr class="par">
		<td align="left" >- Carga tabágica:</td>
		<td ><xsl:value-of select ="CARGTAB" /> (maços-cigarros/ano)</td>
	</tr>
</xsl:if>
<tr class="impar">
	<td align="left" >Uso de drogas (inalatórias / injetáveis):</td>
	<td ><xsl:value-of select ="DROGAS" /></td>
</tr>
<tr class="par">
	<td align="left" >Bebida alcoólica preferida:</td>
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


           2.	Avaliação Inicial/Clínica do Contato/Sintomático Respiratório/Suspeito
      </td>
</tr>
<tr class="par">
	<td align="left" >Morou antes com alguém com tuberculose no pulmão, familiar ou não?</td>
	<td ><xsl:value-of select ="MORATB" /></td>
</tr>
<tr class="par">
	<td align="left" >Teve (tem) alguém da família com tuberculose no pulmão?</td>
	<td ><xsl:value-of select ="FAMILTB" /></td>
</tr>
<tr class="par">
	<td align="left" >Teve (tem) alguém do círculo de amizade/trabalho com tuberculose no pulmão?</td>
	<td ><xsl:value-of select ="AMIGOTB" /></td>
</tr>
<xsl:choose>
	<xsl:when test="MORATB = 'Sim'">
	<tr class="par">
		<td align="left" >- Qual a média de horas de contato por dia?</td>
		<td ><xsl:value-of select ="TABHOR" /></td>
	</tr>
	<tr class="par">
		<td align="left" >- Há quanto tempo o caso índice tosse?</td>
		<td ><xsl:value-of select ="TPTSEIND" /></td>
	</tr>
  	</xsl:when>
	<xsl:when test="FAMILTB = 'Sim'">
	<tr class="par">
		<td align="left" >- Qual a média de horas de contato por dia?</td>
		<td ><xsl:value-of select ="TABHOR" /></td>
	</tr>
	<tr class="par">
		<td align="left" >- Há quanto tempo o caso índice tosse?</td>
		<td ><xsl:value-of select ="TPTSEIND" /></td>
	</tr>
  	</xsl:when>
	<xsl:when test="AMIGOTB = 'Sim'">
	<tr class="par">
		<td align="left" >- Qual a média de horas de contato por dia?</td>
		<td ><xsl:value-of select ="TABHOR" /></td>
	</tr>
	<tr class="par">
		<td align="left" >- Há quanto tempo o caso índice tosse?</td>
		<td ><xsl:value-of select ="TPTSEIND" /></td>
	</tr>
  	</xsl:when>
  	<xsl:otherwise>
  	</xsl:otherwise>
</xsl:choose>
<tr class="impar">
	<td align="left" >Tomou alguma vez estes remédios?</td>
	<td ><xsl:value-of select ="TIPOQX" /></td>
</tr>
<tr class="par">
	<td align="left" >Teve tuberculose no passado?</td>
	<td ><xsl:value-of select ="TBPREV" /></td>
</tr>
<xsl:if test="TBPREV = 'Sim'">
        <tr class="par">
		<td align="left" >- Há quantos anos?</td>
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
	<td align="left" >Tem ou teve outros problemas de saúde?</td>
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
		<td align="left" >- Há quantas semanas (em dias)?</td>
		<td ><xsl:value-of select ="TOSSETEMP" /> dias</td>
	</tr>
</xsl:if>
<tr class="par">
	<td align="left" >Catarro/Expectoração:</td>
	<td ><xsl:value-of select ="EXPECT" /></td>
</tr>
<xsl:if test="EXPECT = 'Sim'">
        <tr class="par">
		<td align="left" >- Há quantas semanas (em dias)?</td>
		<td ><xsl:value-of select ="EXPECTEMP" /> dias</td>
	</tr>
</xsl:if>
<tr class="impar">
	<td align="left" >Sangue no catarro/Hemoptise:</td>
	<td ><xsl:value-of select ="HEMPTI" /></td>
</tr>
<tr class="par">
	<td align="left" >Dor Torácica/dor no peito:</td>
	<td ><xsl:value-of select ="DOTTX" /></td>
</tr>
<tr class="impar">
	<td align="left" >Febre:</td>
	<td ><xsl:value-of select ="FEBRE" /></td>
</tr>
<tr class="par">
	<td align="left" >Suores à noite:</td>
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
		<td align="left" >- Diferença de peso:</td>
		<td ><xsl:value-of select ="DIFPESO" /> kg</td>
	</tr>
	<tr class="impar">
		<td align="left" >- Porcentagem de peso perdida:</td>
		<td ><xsl:value-of select ="CORELPESO" />%</td>
	</tr>
</xsl:if>
<tr class="par">
	<td align="left" >Cansaço:</td>
	<td ><xsl:value-of select ="ASTENI" /></td>
</tr>
<tr class="impar">
	<td align="left" >Rouquidão:</td>
	<td ><xsl:value-of select ="ROUQUI" /></td>
</tr>
<tr class="par">
	<td align="left" >Ínguas:</td>
	<td ><xsl:value-of select ="LINFON" /></td>
</tr>
<tr class="impar">
	<td align="left" >Falta de ar (Dispnéia):</td>
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
	<td align="left" >Horário de encerramento da entrevista:</td>
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
	<td align="left" >Condições da entrevista:</td>
	<td ><xsl:value-of select ="ENTREV" /></td>
</tr>
<tr class="impar">
	<td align="left" >Colaboração do entrevistado:</td>
	<td ><xsl:value-of select ="ENTEVTADO" /></td>
</tr>
<tr class="par">
	<td align="left" >Credibilidade das respostas na sua opinião:</td>
	<td ><xsl:value-of select ="OPNIAO" /></td>
</tr>
</xsl:for-each>
</table>
</body>
</html>
</xsl:template>
</xsl:stylesheet>

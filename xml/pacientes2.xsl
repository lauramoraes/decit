<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/doc">
<html>
<head>
<title>.:. Projeto Neural TB .:.</title>
<link  rel="stylesheet" type="text/css" href="../css/standart.css"/>
<script language="javascript" src="../js/validacoes.js"></script>
</head>
<body>
<table width="600" align="center" cellspacing="1" cellpadding="0" id="xml">
<tr class="nome">
	<td colspan="2" align="center" >
           No de Identifica��o: <xsl:value-of select ="paciente[last()]/id" />
    </td>
</tr>
<tr class="nome">
	<td width="100" align="left" >
           <img src="../imagens/setacima.jpg"></img>
           <img src="../imagens/setabaixo.jpg"></img>
           Nome:
    </td>
	<td > <xsl:value-of select ="paciente[last()]/nome" /></td>
</tr>
<tr class="forms">
     <td colspan="2">
           <img src="../imagens/setacima.jpg"></img>
           <img src="../imagens/setabaixo.jpg"></img>
            - Entrevista
     </td>
</tr>
<tr class="par">
    <td align="left" >Cidade de Estudo:</td>
    <td ><xsl:value-of select ="paciente[last()]/cidade" /></td>
</tr>
<xsl:choose>
  <xsl:when test="cidade = Curitiba/Paran�">
<tr class="impar">
	<td align="left" >Tipo de Unidade de Sa�de:</td>
	<td ><xsl:value-of select ="paciente[last()]/unidade2" /></td>
</tr>
<tr class="par">
	<td align="left" >Tipo de participante:</td>
	<td ><xsl:value-of select ="paciente[last()]/tipo2" /></td>
</tr>
  </xsl:when>
  <xsl:otherwise>
<tr class="impar">
	<td align="left" >Tipo de Unidade de Sa�de:</td>
	<td ><xsl:value-of select ="paciente[last()]/unidade" /></td>
</tr>
<tr class="par">
	<td align="left" >Tipo de participante:</td>
	<td ><xsl:value-of select ="paciente[last()]/tipo" /></td>
</tr>
  </xsl:otherwise>
</xsl:choose>
<tr class="impar">
	<td align="left" >Entrevistador:</td>
	<td ><xsl:value-of select ="paciente[last()]/entrevistador" /></td>
</tr>
<tr class="impar">
	<td align="left" >Categoria Profissional:</td>
	<td ><xsl:value-of select ="paciente[last()]/categProf" /></td>
</tr>
<tr class="par">
	<td align="left" >Data da Entrevista:</td>
	<td ><xsl:value-of select ="paciente[last()]/diaEntr" /></td>
</tr>
<tr class="impar">
	<td align="left" >Local da Entrevista:</td>
	<td ><xsl:value-of select ="paciente[last()]/local" /></td>
</tr>
<tr class="par">
	<td align="left" >Supervisor:</td>
	<td ><xsl:value-of select ="paciente[last()]/supervisor" /></td>
</tr>
<tr class="impar">
	<td align="left" >Data:</td>
	<td ><xsl:value-of select ="paciente[last()]/dia" /></td>
</tr>

<tr class="par">
	<td align="left" >Hor�rio do in�cio da entrevista:</td>
	<td ><xsl:value-of select ="paciente[last()]/horaInicio" /></td>
</tr>
<tr class="forms">
     <td colspan="2">
           <img src="../imagens/setacima.jpg"></img>
           <img src="../imagens/setabaixo.jpg"></img>
           1.  Caracteriza��o Socioecon�mica / S�cio-demogr�fica / H�bitos de Vida
     </td>
</tr>
<tr class="impar">
	<td align="left" >Logradouro:</td>
	<td ><xsl:value-of select ="paciente[last()]/logradouro" /></td>
</tr>
<tr class="par">
	<td align="left" >N�mero:</td>
	<td ><xsl:value-of select ="paciente[last()]/numero" /></td>
</tr>
<tr class="impar">
	<td align="left" >Estado:</td>
	<td ><xsl:value-of select ="paciente[last()]/est" /></td>
</tr>
<tr class="par">
	<td align="left" >Munic�pio:</td>
	<td ><xsl:value-of select ="paciente[last()]/munic�pio" /></td>
</tr>
<tr class="impar">
	<td align="left" >Bairro:</td>
	<td ><xsl:value-of select ="paciente[last()]/bairro" /></td>
</tr>
<tr class="par">
	<td align="left" >CEP:</td>
	<td ><xsl:value-of select ="paciente[last()]/cep" /></td>
</tr>
<tr class="impar">
	<td align="left" >Telefone para contato:</td>
	<td ><xsl:value-of select ="paciente[last()]/telefone" /></td>
</tr>
<tr class="par">
	<td align="left" >N�mero do CAT-SUS:</td>
	<td ><xsl:value-of select ="paciente[last()]/numfns" /></td>
</tr>
<tr class="impar">
	<td align="left" >Data de Nascimento:</td>
	<td ><xsl:value-of select ="paciente[last()]/diaNasc" /></td>
</tr>
<tr class="par">
	<td align="left" >G�nero:</td>
	<td ><xsl:value-of select ="paciente[last()]/sexo" /></td>
</tr>
<tr class="impar">
	<td align="left" >Cor da pele:</td>
	<td ><xsl:value-of select ="paciente[last()]/cor" /></td>
</tr>
<tr class="par">
	<td align="left" >Situa��o conjugal:</td>
	<td ><xsl:value-of select ="paciente[last()]/estciv" /></td>
</tr>
<tr class="impar">
	<td align="left" >Naturalidade - Estado:</td>
	<td ><xsl:value-of select ="paciente[last()]/natest" /></td>
</tr>
<tr class="par">
	<td align="left" >Naturalidade - Cidade:</td>
	<td ><xsl:value-of select ="paciente[last()]/natmun" /></td>
</tr>
<tr class="impar">
	<td align="left" >J� morou em outro local diferente do munic�pio atual?</td>
	<td ><xsl:value-of select ="paciente[last()]/morout" /></td>
</tr>
<tr class="par">
	<td align="left" >No momento voc� est�:</td>
	<td ><xsl:value-of select ="paciente[last()]/funcao" /></td>
</tr>
<tr class="impar">
	<td align="left" >Profissional de Sa�de:</td>
	<td ><xsl:value-of select ="paciente[last()]/profsaude" /></td>
</tr>
<tr class="par">
	<td align="left" >Grau de instru��o do chefe da fam�lia:</td>
	<td ><xsl:value-of select ="paciente[last()]/grinstrch" /></td>
</tr>
<tr class="impar">
	<td align="left" >Tem empregada mensalista em casa?</td>
	<td ><xsl:value-of select ="paciente[last()]/empregada" /></td>
</tr>
<tr class="par">
	<td align="left" >Aspirador de p�:</td>
	<td ><xsl:value-of select ="paciente[last()]/asppo" /></td>
</tr>
<tr class="impar">
	<td align="left" >Autom�vel:</td>
	<td ><xsl:value-of select ="paciente[last()]/auto" /></td>
</tr>
<tr class="par">
	<td align="left" >Banheiro:</td>
	<td ><xsl:value-of select ="paciente[last()]/banhei" /></td>
</tr>
<tr class="impar">
	<td align="left" >Freezer (ou duplex):</td>
	<td ><xsl:value-of select ="paciente[last()]/freezer" /></td>
</tr>
<tr class="par">
	<td align="left" >Geladeira duplex:</td>
	<td ><xsl:value-of select ="paciente[last()]/geldup" /></td>
</tr>
<tr class="impar">
	<td align="left" >Geladeira simples:</td>
	<td ><xsl:value-of select ="paciente[last()]/gelsim" /></td>
</tr>
<tr class="par">
	<td align="left" >M�qu. de lavar roupa:</td>
	<td ><xsl:value-of select ="paciente[last()]/mlav" /></td>
</tr>
<tr class="impar">
	<td align="left" >R�dio:</td>
	<td ><xsl:value-of select ="paciente[last()]/rad" /></td>
</tr>
<tr class="par">
	<td align="left" >TV em cores:</td>
	<td ><xsl:value-of select ="paciente[last()]/tv" /></td>
</tr>
<tr class="impar">
	<td align="left" >Videocassete/DVD:</td>
	<td ><xsl:value-of select ="paciente[last()]/video" /></td>
</tr>
<tr class="par">
	<td align="left" >Foi morador de rua nos �ltimos 2 anos?</td>
	<td ><xsl:value-of select ="paciente[last()]/morrua" /></td>
</tr>
<tr class="impar">
	<td align="left" >Mora(ou) em asilos rua nos �ltimos 2 anos?</td>
	<td ><xsl:value-of select ="paciente[last()]/morasil" /></td>
</tr>
<tr class="par">
	<td align="left" >Ex-detento?</td>
	<td ><xsl:value-of select ="paciente[last()]/presid" /></td>
</tr>
<tr class="impar">
	<td align="left" >Esteve internado nos �ltimos dois anos?</td>
	<td ><xsl:value-of select ="paciente[last()]/intern" /></td>
</tr>
<tr class="impar">
	<td align="left" >Que unidade de sa�de voc� procura quando adoece?</td>
	<td ><xsl:value-of select ="paciente[last()]/qunis" /></td>
</tr>
<tr class="impar">
	<td align="left" >Conhece o agente de sa�de do bairro?</td>
	<td ><xsl:value-of select ="paciente[last()]/agens" /></td>
</tr>
<tr class="par">
	<td align="left" >Em rela��o ao h�bito de fumar...:</td>
	<td ><xsl:value-of select ="paciente[last()]/fumo" /></td>
</tr>
<tr class="par">
	<td align="left" >Carga tab�gica:</td>
	<td ><xsl:value-of select ="paciente[last()]/cargtab" /></td>
</tr>
<tr class="impar">
	<td align="left" >Uso de drogas (inalat�rias / injet�veis):</td>
	<td ><xsl:value-of select ="paciente[last()]/drogas" /></td>
</tr>
<tr class="par">
	<td align="left" >Bebida alco�lica preferida:</td>
	<td ><xsl:value-of select ="paciente[last()]/alcool" /></td>
</tr>
<xsl:if test="qbebida0 = Sim">
<tr class="impar">
	<td align="left" >Voc� tem facilidade de fazer amizades?</td>
	<td ><xsl:value-of select ="paciente[last()]/qbebida0" /></td>
</tr>
</xsl:if>
<xsl:if test="qbebida1 = Sim">
<tr class="par">
	<td align="left" >Alguma vez sentiu que deveria diminuir a quantidade da bebida?</td>
	<td ><xsl:value-of select ="paciente[last()]/qbebida0" /></td>
</tr>
</xsl:if>
<xsl:if test="qbebida2 = Sim">
<tr class="impar">
	<td align="left" >Algu�m critica ou j� criticou o seu modo de beber?</td>
	<td ><xsl:value-of select ="paciente[last()]/qbebida0" /></td>
</tr>
</xsl:if>
<xsl:if test="qbebida3 = Sim">
<tr class="par">
	<td align="left" >Voc� costuma beber de manh� para diminuir o nervosismo/ressaca?</td>
	<td ><xsl:value-of select ="paciente[last()]/qbebida0" /></td>
</tr>
</xsl:if>
<xsl:if test="qbebida4 = Sim">
<tr class="impar">
	<td align="left" >Voc� se sente culpado pela maneira que costuma beber?</td>
	<td ><xsl:value-of select ="paciente[last()]/qbebida0" /></td>
</tr>
</xsl:if>
<tr class="par">
	<td align="left" >Observa��es:</td>
	<td ><xsl:value-of select ="paciente[last()]/observacoes" /></td>
</tr>
<tr class="forms">
      <td colspan="2">
           <img src="../imagens/setacima.jpg"></img>
           <img src="../imagens/setabaixo.jpg"></img>
           2.	Avalia��o Inicial/Cl�nica do Contato/Sintom�tico Respirat�rio/Suspeito
      </td>
</tr>
<tr class="par">
	<td align="left" >Morou antes com algu�m com tuberculose no pulm�o, familiar ou n�o?</td>
	<td ><xsl:value-of select ="paciente[last()]/morou" /></td>
</tr>
<tr class="impar">
	<td align="left" >Teve (tem) algu�m da fam�lia com tuberculose no pulm�o?</td>
	<td ><xsl:value-of select ="paciente[last()]/familia" /></td>
</tr>
<tr class="par">
	<td align="left" >Teve (tem) algu�m do c�rculo de amizade/trabalho com tuberculose no pulm�o?</td>
	<td ><xsl:value-of select ="paciente[last()]/circulo" /></td>
</tr>
<tr class="impar">
	<td align="left" >Tomou alguma vez estes rem�dios?</td>
	<td ><xsl:value-of select ="paciente[last()]/tipoqx" /></td>
</tr>
<tr class="par">
	<td align="left" >Teve tuberculose no passado?</td>
	<td ><xsl:value-of select ="paciente[last()]/tbprev" /></td>
</tr>
<tr class="par">
	<td align="left" >Resultado do tratamento notificado no SINAN</td>
	<td ><xsl:value-of select ="paciente[last()]/ressinan" /></td>
</tr>
<tr class="impar">
	<td align="left" >Cicatriz vacinal BCG?</td>
	<td ><xsl:value-of select ="paciente[last()]/cicbcg" /></td>
</tr>
<tr class="par">
	<td align="left" >Tem falta de ar ou enfisema?</td>
	<td ><xsl:value-of select ="paciente[last()]/falta" /></td>
</tr>
<tr class="impar">
	<td align="left" >Tem asma ou bronquite?</td>
	<td ><xsl:value-of select ="paciente[last()]/asma" /></td>
</tr>
<tr class="par">
	<td align="left" >Tem ou teve outros problemas de sa�de?</td>
	<td ><xsl:value-of select ="paciente[last()]/psaude" /></td>
</tr>
<xsl:if test="sint = Sim">
<tr class="impar">
	<td align="left" >Tosse:</td>
	<td ><xsl:value-of select ="paciente[last()]/tosse" /></td>
</tr>
<tr class="par">
	<td align="left" >Catarro/Expectora��o:</td>
	<td ><xsl:value-of select ="paciente[last()]/catarr" /></td>
</tr>
<tr class="impar">
	<td align="left" >Sangue no catarro/Hemoptise:</td>
	<td ><xsl:value-of select ="paciente[last()]/hempti" /></td>
</tr>
<tr class="par">
	<td align="left" >Dor Tor�cica/dor no peito:</td>
	<td ><xsl:value-of select ="paciente[last()]/hempto" /></td>
</tr>
<tr class="impar">
	<td align="left" >Febre:</td>
	<td ><xsl:value-of select ="paciente[last()]/febre" /></td>
</tr>
<tr class="par">
	<td align="left" >Suores � noite:</td>
	<td ><xsl:value-of select ="paciente[last()]/sudore" /></td>
</tr>
<tr class="impar">
	<td align="left" >Falta de apetite:</td>
	<td ><xsl:value-of select ="paciente[last()]/hipore" /></td>
</tr>
<tr class="par">
	<td align="left" >Emagrecimento:</td>
	<td ><xsl:value-of select ="paciente[last()]/emagre" /></td>
</tr>
<tr class="par">
	<td align="left" >Peso anterior:</td>
	<td ><xsl:value-of select ="paciente[last()]/pesokg1" /></td>
</tr>
<tr class="par">
	<td align="left" >Peso atual:</td>
	<td ><xsl:value-of select ="paciente[last()]/pesokg2" /></td>
</tr>
<tr class="par">
	<td align="left" >Cansa�o:</td>
	<td ><xsl:value-of select ="paciente[last()]/asteni" /></td>
</tr>
<tr class="impar">
	<td align="left" >Rouquid�o:</td>
	<td ><xsl:value-of select ="paciente[last()]/rouqui" /></td>
</tr>
<tr class="par">
	<td align="left" >�nguas:</td>
	<td ><xsl:value-of select ="paciente[last()]/linfon" /></td>
</tr>
<tr class="impar">
	<td align="left" >Falta de ar (Dispn�ia):</td>
	<td ><xsl:value-of select ="paciente[last()]/dispn" /></td>
</tr>
<tr class="par">
	<td align="left" >Chiado no peito:</td>
	<td ><xsl:value-of select ="paciente[last()]/chiado" /></td>
</tr>
<tr class="impar">
	<td align="left" >Outros:</td>
	<td ><xsl:value-of select ="paciente[last()]/ot" /></td>
</tr>
</xsl:if>
<tr class="impar">
	<td align="left" >Observa��es:</td>
	<td ><xsl:value-of select ="paciente[last()]/obs" /></td>
</tr>
<tr class="par">
	<td align="left" >Hor�rio de encerramento da entrevista:</td>
	<td ><xsl:value-of select ="paciente[last()]/horaenc" /></td>
</tr>
<tr class="impar">
	<td align="left" >Probabilidade de tuberculose pulmonar ativa pela enfermeira apenas com a avalia��o m�dica de sinais de sintomas (hist�ria e exame f�sico):</td>
	<td ><xsl:value-of select ="paciente[last()]/probclin" /></td>
</tr>
<tr class="par">
	<td align="left" >Condi��es da entrevista:</td>
	<td ><xsl:value-of select ="paciente[last()]/condicao" /></td>
</tr>
<tr class="impar">
	<td align="left" >Colabora��o do entrevistado:</td>
	<td ><xsl:value-of select ="paciente[last()]/colaboracao" /></td>
</tr>
<tr class="par">
	<td align="left" >Credibilidade das respostas na sua opini�o:</td>
	<td ><xsl:value-of select ="paciente[last()]/credibilidade" /></td>
</tr>
<tr class="forms">
      <td colspan="2">
           <img src="../imagens/setacima.jpg"></img>
           <img src="../imagens/setabaixo.jpg"></img>
           3.	Avalia��o Complementar do Contato/Sintom�tico Respirat�rio/Suspeito
      </td>
</tr>
<tr class="par">
	<td align="left" >Sinais ao exame f�sico:</td>
	<td ><xsl:value-of select ="paciente[last()]/sinaisExames" /></td>
</tr>
<xsl:if test="cidade != Curitiba/Paran�">
<tr class="par">
	<td align="left" >Probabilidade de tuberculose pulmonar ativa com a avalia��o de sinais de hist�ria + exame f�sico m�dico- PARA EQUIPE M�DICA</td>
	<td ><xsl:value-of select ="paciente[last()]/probem" /></td>
</tr>
</xsl:if>
<tr class="impar">
	<td align="left" >Telerradiografia de t�rax(PA e perfil) - Laudo:</td>
	<td ><xsl:value-of select ="paciente[last()]/rxtor" /></td>
</tr>
<tr class="par">
	<td align="left" >Data do exame:</td>
	<td ><xsl:value-of select ="paciente[last()]/diaExame" /></td>
</tr>
<tr class="par">
	<td align="left" >�rea acometida:</td>
	<td ><xsl:value-of select ="paciente[last()]/area" /></td>
</tr>
<xsl:if test="cidade != Curitiba/Paran�">
<tr class="impar">
	<td align="left" >Em caso de alta ou m�dia probabilidade de TB ativa pela cl�nica:</td>
	<td ><xsl:value-of select ="paciente[last()]/rxtam" /></td>
</tr>
<tr class="par">
	<td align="left" >Em caso de baixa probabilidade de TB ativa pela cl�nica:</td>
	<td ><xsl:value-of select ="paciente[last()]/rxbaix" /></td>
</tr>
<tr class="impar">
	<td align="left" >Probabilidade pelo m�dico de tuberculose pulmonar ativa com a avalia��o complementar do RX:</td>
	<td ><xsl:value-of select ="paciente[last()]/probrx" /></td>
</tr>
</xsl:if>
<tr class="par">
	<td align="left" >Data da leitura:</td>
	<td ><xsl:value-of select ="paciente[last()]/diaLeit" /></td>
</tr>
<tr class="impar">
	<td align="left" >Leitor:</td>
	<td ><xsl:value-of select ="paciente[last()]/leitor" /></td>
</tr>
<tr class="par">
	<td align="left" >Amostra de trato respirat�rio inferior:</td>
	<td ><xsl:value-of select ="paciente[last()]/amostri" /></td>
</tr>
<tr class="impar">
	<td align="left" >Baciloscopia (1� amostra):</td>
	<td ><xsl:value-of select ="paciente[last()]/znescar1" /></td>
</tr>
<tr class="par">
	<td align="left" >Baciloscopia (2� amostra):</td>
	<td ><xsl:value-of select ="paciente[last()]/znescar2" /></td>
</tr>
<tr class="impar">
	<td align="left" >Probabilidade de tuberculose pulmonar ativa com a avalia��o complementar do RX e de baciloscopia:</td>
	<td ><xsl:value-of select ="paciente[last()]/prrxzn" /></td>
</tr>
<tr class="par">
	<td align="left" >Cultura para micobact�rias (1) - m�todo:</td>
	<td ><xsl:value-of select ="paciente[last()]/metodo1" /></td>
</tr>
<tr class="impar">
	<td align="left" >Cultura para micobact�rias (2) - m�todo:</td>
	<td ><xsl:value-of select ="paciente[last()]/metodo2" /></td>
</tr>
<tr class="par">
	<td align="left" >Outro exame (1):</td>
	<td ><xsl:value-of select ="paciente[last()]/exame1" /></td>
</tr>
<tr class="impar">
	<td align="left" >Outro exame (2):</td>
	<td ><xsl:value-of select ="paciente[last()]/exame2" /></td>
</tr>
<tr class="par">
	<td align="left" >Outro exame (3):</td>
	<td ><xsl:value-of select ="paciente[last()]/exame3" /></td>
</tr>
<tr class="impar">
	<td align="left" >Outro exame (4):</td>
	<td ><xsl:value-of select ="paciente[last()]/exame4" /></td>
</tr>
<tr class="forms">
      <td colspan="2">
           <img src="../imagens/setacima.jpg"></img>
           <img src="../imagens/setabaixo.jpg"></img>
           4.	Acompanhamento
      </td>
</tr>
<tr class="par">
	<td align="left" >Desfecho do caso:</td>
	<td ><xsl:value-of select ="paciente[last()]/desfecho" /></td>
</tr>
<tr class="impar">
	<td align="left" >Desfecho do caso diagnosticado como tuberculose:</td>
	<td ><xsl:value-of select ="paciente[last()]/dtub" /></td>
</tr>
<tr class="par">
	<td align="left" >Desfecho do caso diagnosticado como N�O tuberculose:</td>
	<td ><xsl:value-of select ="paciente[last()]/dntub" /></td>
</tr>
<tr class="impar">
	<td align="left" >Se apresentou diagn�stico posterior de tuberculose, onde?</td>
	<td ><xsl:value-of select ="paciente[last()]/aprtbp" /></td>
</tr>
<tr class="par">
	<td align="left" >Data da �ltima consulta/VD:</td>
	<td ><xsl:value-of select ="paciente[last()]/diaUCons" /></td>
</tr>
<tr class="impar">
	<td align="left" >Observa��es:</td>
	<td ><xsl:value-of select ="paciente[last()]/observ" /></td>
</tr>
</table>
</body>
</html>
</xsl:template>
</xsl:stylesheet>

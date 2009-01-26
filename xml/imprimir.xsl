<?xml version="1.0" encoding="UTF-8"?>
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
           No de Identificação: 98 
    </td>
</tr>
<tr class="nome">
	<td width="100" align="left" >
<!--           <img src="../imagens/setacima.jpg"></img> -->
<!--           <img src="../imagens/setabaixo.jpg"></img> -->
           Nome:
    </td>
	<td > <xsl:value-of select ="paciente[98]/nome" /></td>
</tr>
<tr class="forms">
     <td colspan="2">
<!--           <img src="../imagens/setacima.jpg"></img> -->
<!--           <img src="../imagens/setabaixo.jpg"></img> -->
            Entrevista
     </td>
</tr>
<tr class="par">
    <td align="left" >Cidade de Estudo:</td>
    <td ><xsl:value-of select ="paciente[98]/cidade" /></td>
</tr>
<xsl:choose>
  <xsl:when test="cidade = Curitiba/Paraná">
<tr class="impar">
	<td align="left" >Tipo de Unidade de Saúde:</td>
	<td ><xsl:value-of select ="paciente[98]/unidade2" /></td>
</tr>
<tr class="par">
	<td align="left" >Tipo de participante:</td>
	<td ><xsl:value-of select ="paciente[98]/tipo2" /></td>
</tr>
  </xsl:when>
  <xsl:otherwise>
<tr class="impar">
	<td align="left" >Tipo de Unidade de Saúde:</td>
	<td ><xsl:value-of select ="paciente[98]/unidade" /></td>
</tr>
<tr class="par">
	<td align="left" >Tipo de participante:</td>
	<td ><xsl:value-of select ="paciente[98]/tipo" /></td>
</tr>
  </xsl:otherwise>
</xsl:choose>
<tr class="impar">
	<td align="left" >Entrevistador:</td>
	<td ><xsl:value-of select ="paciente[98]/entrevistador" /></td>
</tr>
<tr class="impar">
	<td align="left" >Categoria Profissional:</td>
	<td ><xsl:value-of select ="paciente[98]/categProf" /></td>
</tr>
<tr class="par">
	<td align="left" >Data da Entrevista:</td>
	<td ><xsl:value-of select ="paciente[98]/diaEntr" /></td>
</tr>
<tr class="impar">
	<td align="left" >Local da Entrevista:</td>
	<td ><xsl:value-of select ="paciente[98]/local" /></td>
</tr>
<tr class="par">
	<td align="left" >Supervisor:</td>
	<td ><xsl:value-of select ="paciente[98]/supervisor" /></td>
</tr>
<tr class="impar">
	<td align="left" >Data:</td>
	<td ><xsl:value-of select ="paciente[98]/dia" /></td>
</tr>

<tr class="par">
	<td align="left" >Horário do início da entrevista:</td>
	<td ><xsl:value-of select ="paciente[98]/horaInicio" /></td>
</tr>
<tr class="forms">
     <td colspan="2">
<!--           <img src="../imagens/setacima.jpg"></img> -->
<!--           <img src="../imagens/setabaixo.jpg"></img> -->
           1.  Caracterização Socioeconômica / Sócio-demográfica / Hábitos de Vida
     </td>
</tr>
<tr class="impar">
	<td align="left" >Logradouro:</td>
	<td ><xsl:value-of select ="paciente[98]/logradouro" /></td>
</tr>
<tr class="par">
	<td align="left" >Número:</td>
	<td ><xsl:value-of select ="paciente[98]/numero" /></td>
</tr>
<tr class="impar">
	<td align="left" >Estado:</td>
	<td ><xsl:value-of select ="paciente[98]/est" /></td>
</tr>
<tr class="par">
	<td align="left" >Município:</td>
	<td ><xsl:value-of select ="paciente[98]/município" /></td>
</tr>
<tr class="impar">
	<td align="left" >Bairro:</td>
	<td ><xsl:value-of select ="paciente[98]/bairro" /></td>
</tr>
<tr class="par">
	<td align="left" >CEP:</td>
	<td ><xsl:value-of select ="paciente[98]/cep" /></td>
</tr>
<tr class="impar">
	<td align="left" >Telefone para contato:</td>
	<td ><xsl:value-of select ="paciente[98]/telefone" /></td>
</tr>
<tr class="par">
	<td align="left" >Número do CAT-SUS:</td>
	<td ><xsl:value-of select ="paciente[98]/numfns" /></td>
</tr>
<tr class="impar">
	<td align="left" >Data de Nascimento:</td>
	<td ><xsl:value-of select ="paciente[98]/diaNasc" /></td>
</tr>
<tr class="par">
	<td align="left" >Gênero:</td>
	<td ><xsl:value-of select ="paciente[98]/sexo" /></td>
</tr>
<tr class="impar">
	<td align="left" >Cor da pele:</td>
	<td ><xsl:value-of select ="paciente[98]/cor" /></td>
</tr>
<tr class="par">
	<td align="left" >Situação conjugal:</td>
	<td ><xsl:value-of select ="paciente[98]/estciv" /></td>
</tr>
<tr class="impar">
	<td align="left" >Naturalidade - Estado:</td>
	<td ><xsl:value-of select ="paciente[98]/natest" /></td>
</tr>
<tr class="par">
	<td align="left" >Naturalidade - Cidade:</td>
	<td ><xsl:value-of select ="paciente[98]/natmun" /></td>
</tr>
<tr class="impar">
	<td align="left" >Já morou em outro local diferente do município atual?</td>
	<td ><xsl:value-of select ="paciente[98]/morout" /></td>
</tr>
<tr class="par">
	<td align="left" >No momento você está:</td>
	<td ><xsl:value-of select ="paciente[98]/funcao" /></td>
</tr>
<tr class="impar">
	<td align="left" >Profissional de Saúde:</td>
	<td ><xsl:value-of select ="paciente[98]/profsaude" /></td>
</tr>
<tr class="par">
	<td align="left" >Grau de instrução do chefe da família:</td>
	<td ><xsl:value-of select ="paciente[98]/grinstrch" /></td>
</tr>
<tr class="impar">
	<td align="left" >Tem empregada mensalista em casa?</td>
	<td ><xsl:value-of select ="paciente[98]/empregada" /></td>
</tr>
<tr class="par">
	<td align="left" >Aspirador de pó:</td>
	<td ><xsl:value-of select ="paciente[98]/asppo" /></td>
</tr>
<tr class="impar">
	<td align="left" >Automóvel:</td>
	<td ><xsl:value-of select ="paciente[98]/auto" /></td>
</tr>
<tr class="par">
	<td align="left" >Banheiro:</td>
	<td ><xsl:value-of select ="paciente[98]/banhei" /></td>
</tr>
<tr class="impar">
	<td align="left" >Freezer (ou duplex):</td>
	<td ><xsl:value-of select ="paciente[98]/freezer" /></td>
</tr>
<tr class="par">
	<td align="left" >Geladeira duplex:</td>
	<td ><xsl:value-of select ="paciente[98]/geldup" /></td>
</tr>
<tr class="impar">
	<td align="left" >Geladeira simples:</td>
	<td ><xsl:value-of select ="paciente[98]/gelsim" /></td>
</tr>
<tr class="par">
	<td align="left" >Máqu. de lavar roupa:</td>
	<td ><xsl:value-of select ="paciente[98]/mlav" /></td>
</tr>
<tr class="impar">
	<td align="left" >Rádio:</td>
	<td ><xsl:value-of select ="paciente[98]/rad" /></td>
</tr>
<tr class="par">
	<td align="left" >TV em cores:</td>
	<td ><xsl:value-of select ="paciente[98]/tv" /></td>
</tr>
<tr class="impar">
	<td align="left" >Videocassete/DVD:</td>
	<td ><xsl:value-of select ="paciente[98]/video" /></td>
</tr>
<tr class="par">
	<td align="left" >Foi morador de rua nos últimos 2 anos?</td>
	<td ><xsl:value-of select ="paciente[98]/morrua" /></td>
</tr>
<tr class="impar">
	<td align="left" >Mora(ou) em asilos rua nos últimos 2 anos?</td>
	<td ><xsl:value-of select ="paciente[98]/morasil" /></td>
</tr>
<tr class="par">
	<td align="left" >Ex-detento?</td>
	<td ><xsl:value-of select ="paciente[98]/presid" /></td>
</tr>
<tr class="impar">
	<td align="left" >Esteve internado nos últimos dois anos?</td>
	<td ><xsl:value-of select ="paciente[98]/intern" /></td>
</tr>
<tr class="impar">
	<td align="left" >Que unidade de saúde você procura quando adoece?</td>
	<td ><xsl:value-of select ="paciente[98]/qunis" /></td>
</tr>
<tr class="impar">
	<td align="left" >Conhece o agente de saúde do bairro?</td>
	<td ><xsl:value-of select ="paciente[98]/agens" /></td>
</tr>
<tr class="par">
	<td align="left" >Em relação ao hábito de fumar...:</td>
	<td ><xsl:value-of select ="paciente[98]/fumo" /></td>
</tr>
<tr class="par">
	<td align="left" >Carga tabágica:</td>
	<td ><xsl:value-of select ="paciente[98]/cargtab" /></td>
</tr>
<tr class="impar">
	<td align="left" >Uso de drogas (inalatórias / injetáveis):</td>
	<td ><xsl:value-of select ="paciente[98]/drogas" /></td>
</tr>
<tr class="par">
	<td align="left" >Bebida alcoólica preferida:</td>
	<td ><xsl:value-of select ="paciente[98]/alcool" /></td>
</tr>
<xsl:if test="qbebida0 = Sim">
<tr class="impar">
	<td align="left" >Você tem facilidade de fazer amizades?</td>
	<td ><xsl:value-of select ="paciente[98]/qbebida0" /></td>
</tr>
</xsl:if>
<xsl:if test="qbebida1 = Sim">
<tr class="par">
	<td align="left" >Alguma vez sentiu que deveria diminuir a quantidade da bebida?</td>
	<td ><xsl:value-of select ="paciente[98]/qbebida0" /></td>
</tr>
</xsl:if>
<xsl:if test="qbebida2 = Sim">
<tr class="impar">
	<td align="left" >Alguém critica ou já criticou o seu modo de beber?</td>
	<td ><xsl:value-of select ="paciente[98]/qbebida0" /></td>
</tr>
</xsl:if>
<xsl:if test="qbebida3 = Sim">
<tr class="par">
	<td align="left" >Você costuma beber de manhã para diminuir o nervosismo/ressaca?</td>
	<td ><xsl:value-of select ="paciente[98]/qbebida0" /></td>
</tr>
</xsl:if>
<xsl:if test="qbebida4 = Sim">
<tr class="impar">
	<td align="left" >Você se sente culpado pela maneira que costuma beber?</td>
	<td ><xsl:value-of select ="paciente[98]/qbebida0" /></td>
</tr>
</xsl:if>
<tr class="par">
	<td align="left" >Observações:</td>
	<td ><xsl:value-of select ="paciente[98]/observacoes" /></td>
</tr>
<tr class="forms">
      <td colspan="2">
<!--            <img src="../imagens/setacima.jpg"></img> -->
<!--            <img src="../imagens/setabaixo.jpg"></img> -->
           2.	Avaliação Inicial/Clínica do Contato/Sintomático Respiratório/Suspeito
      </td>
</tr>
<tr class="par">
	<td align="left" >Morou antes com alguém com tuberculose no pulmão, familiar ou não?</td>
	<td ><xsl:value-of select ="paciente[98]/morou" /></td>
</tr>
<tr class="impar">
	<td align="left" >Teve (tem) alguém da família com tuberculose no pulmão?</td>
	<td ><xsl:value-of select ="paciente[98]/familia" /></td>
</tr>
<tr class="par">
	<td align="left" >Teve (tem) alguém do círculo de amizade/trabalho com tuberculose no pulmão?</td>
	<td ><xsl:value-of select ="paciente[98]/circulo" /></td>
</tr>
<tr class="impar">
	<td align="left" >Tomou alguma vez estes remédios?</td>
	<td ><xsl:value-of select ="paciente[98]/tipoqx" /></td>
</tr>
<tr class="par">
	<td align="left" >Teve tuberculose no passado?</td>
	<td ><xsl:value-of select ="paciente[98]/tbprev" /></td>
</tr>
<tr class="par">
	<td align="left" >Resultado do tratamento notificado no SINAN</td>
	<td ><xsl:value-of select ="paciente[98]/ressinan" /></td>
</tr>
<tr class="impar">
	<td align="left" >Cicatriz vacinal BCG?</td>
	<td ><xsl:value-of select ="paciente[98]/cicbcg" /></td>
</tr>
<tr class="par">
	<td align="left" >Tem falta de ar ou enfisema?</td>
	<td ><xsl:value-of select ="paciente[98]/falta" /></td>
</tr>
<tr class="impar">
	<td align="left" >Tem asma ou bronquite?</td>
	<td ><xsl:value-of select ="paciente[98]/asma" /></td>
</tr>
<tr class="par">
	<td align="left" >Tem ou teve outros problemas de saúde?</td>
	<td ><xsl:value-of select ="paciente[98]/psaude" /></td>
</tr>
<xsl:if test="sint = Sim">
<tr class="impar">
	<td align="left" >Tosse:</td>
	<td ><xsl:value-of select ="paciente[98]/tosse" /></td>
</tr>
<tr class="par">
	<td align="left" >Catarro/Expectoração:</td>
	<td ><xsl:value-of select ="paciente[98]/catarr" /></td>
</tr>
<tr class="impar">
	<td align="left" >Sangue no catarro/Hemoptise:</td>
	<td ><xsl:value-of select ="paciente[98]/hempti" /></td>
</tr>
<tr class="par">
	<td align="left" >Dor Torácica/dor no peito:</td>
	<td ><xsl:value-of select ="paciente[98]/hempto" /></td>
</tr>
<tr class="impar">
	<td align="left" >Febre:</td>
	<td ><xsl:value-of select ="paciente[98]/febre" /></td>
</tr>
<tr class="par">
	<td align="left" >Suores à noite:</td>
	<td ><xsl:value-of select ="paciente[98]/sudore" /></td>
</tr>
<tr class="impar">
	<td align="left" >Falta de apetite:</td>
	<td ><xsl:value-of select ="paciente[98]/hipore" /></td>
</tr>
<tr class="par">
	<td align="left" >Emagrecimento:</td>
	<td ><xsl:value-of select ="paciente[98]/emagre" /></td>
</tr>
<tr class="par">
	<td align="left" >Peso anterior:</td>
	<td ><xsl:value-of select ="paciente[98]/pesokg1" /></td>
</tr>
<tr class="par">
	<td align="left" >Peso atual:</td>
	<td ><xsl:value-of select ="paciente[98]/pesokg2" /></td>
</tr>
<tr class="par">
	<td align="left" >Cansaço:</td>
	<td ><xsl:value-of select ="paciente[98]/asteni" /></td>
</tr>
<tr class="impar">
	<td align="left" >Rouquidão:</td>
	<td ><xsl:value-of select ="paciente[98]/rouqui" /></td>
</tr>
<tr class="par">
	<td align="left" >Ínguas:</td>
	<td ><xsl:value-of select ="paciente[98]/linfon" /></td>
</tr>
<tr class="impar">
	<td align="left" >Falta de ar (Dispnéia):</td>
	<td ><xsl:value-of select ="paciente[98]/dispn" /></td>
</tr>
<tr class="par">
	<td align="left" >Chiado no peito:</td>
	<td ><xsl:value-of select ="paciente[98]/chiado" /></td>
</tr>
<tr class="impar">
	<td align="left" >Outros:</td>
	<td ><xsl:value-of select ="paciente[98]/ot" /></td>
</tr>
</xsl:if>
<tr class="impar">
	<td align="left" >Observações:</td>
	<td ><xsl:value-of select ="paciente[98]/obs" /></td>
</tr>
<tr class="par">
	<td align="left" >Horário de encerramento da entrevista:</td>
	<td ><xsl:value-of select ="paciente[98]/horaenc" /></td>
</tr>
<tr class="impar">
	<td align="left" >Probabilidade de tuberculose pulmonar ativa pela enfermeira apenas com a avaliação médica de sinais de sintomas (história e exame físico):</td>
	<td ><xsl:value-of select ="paciente[98]/probclin" /></td>
</tr>
<tr class="par">
	<td align="left" >Condições da entrevista:</td>
	<td ><xsl:value-of select ="paciente[98]/condicao" /></td>
</tr>
<tr class="impar">
	<td align="left" >Colaboração do entrevistado:</td>
	<td ><xsl:value-of select ="paciente[98]/colaboracao" /></td>
</tr>
<tr class="par">
	<td align="left" >Credibilidade das respostas na sua opinião:</td>
	<td ><xsl:value-of select ="paciente[98]/credibilidade" /></td>
</tr>
<tr class="forms">
      <td colspan="2">
<!--            <img src="../imagens/setacima.jpg"></img> -->
<!--            <img src="../imagens/setabaixo.jpg"></img> -->
           3.	Avaliação Complementar do Contato/Sintomático Respiratório/Suspeito
      </td>
</tr>
<tr class="par">
	<td align="left" >Sinais ao exame físico:</td>
	<td ><xsl:value-of select ="paciente[98]/sinaisExames" /></td>
</tr>
<xsl:if test="cidade != Curitiba/Paraná">
<tr class="par">
	<td align="left" >Probabilidade de tuberculose pulmonar ativa com a avaliação de sinais de história + exame físico médico- PARA EQUIPE MÉDICA</td>
	<td ><xsl:value-of select ="paciente[98]/probem" /></td>
</tr>
</xsl:if>
<tr class="impar">
	<td align="left" >Telerradiografia de tórax(PA e perfil) - Laudo:</td>
	<td ><xsl:value-of select ="paciente[98]/rxtor" /></td>
</tr>
<tr class="par">
	<td align="left" >Data do exame:</td>
	<td ><xsl:value-of select ="paciente[98]/diaExame" /></td>
</tr>
<tr class="par">
	<td align="left" >Área acometida:</td>
	<td ><xsl:value-of select ="paciente[98]/area" /></td>
</tr>
<xsl:if test="cidade != Curitiba/Paraná">
<tr class="impar">
	<td align="left" >Em caso de alta ou média probabilidade de TB ativa pela clínica:</td>
	<td ><xsl:value-of select ="paciente[98]/rxtam" /></td>
</tr>
<tr class="par">
	<td align="left" >Em caso de baixa probabilidade de TB ativa pela clínica:</td>
	<td ><xsl:value-of select ="paciente[98]/rxbaix" /></td>
</tr>
<tr class="impar">
	<td align="left" >Probabilidade pelo médico de tuberculose pulmonar ativa com a avaliação complementar do RX:</td>
	<td ><xsl:value-of select ="paciente[98]/probrx" /></td>
</tr>
</xsl:if>
<tr class="par">
	<td align="left" >Data da leitura:</td>
	<td ><xsl:value-of select ="paciente[98]/diaLeit" /></td>
</tr>
<tr class="impar">
	<td align="left" >Leitor:</td>
	<td ><xsl:value-of select ="paciente[98]/leitor" /></td>
</tr>
<tr class="par">
	<td align="left" >Amostra de trato respiratório inferior:</td>
	<td ><xsl:value-of select ="paciente[98]/amostri" /></td>
</tr>
<tr class="impar">
	<td align="left" >Baciloscopia (1ª amostra):</td>
	<td ><xsl:value-of select ="paciente[98]/znescar1" /></td>
</tr>
<tr class="par">
	<td align="left" >Baciloscopia (2ª amostra):</td>
	<td ><xsl:value-of select ="paciente[98]/znescar2" /></td>
</tr>
<tr class="impar">
	<td align="left" >Probabilidade de tuberculose pulmonar ativa com a avaliação complementar do RX e de baciloscopia:</td>
	<td ><xsl:value-of select ="paciente[98]/prrxzn" /></td>
</tr>
<tr class="par">
	<td align="left" >Cultura para micobactérias (1) - método:</td>
	<td ><xsl:value-of select ="paciente[98]/metodo1" /></td>
</tr>
<tr class="impar">
	<td align="left" >Cultura para micobactérias (2) - método:</td>
	<td ><xsl:value-of select ="paciente[98]/metodo2" /></td>
</tr>
<tr class="par">
	<td align="left" >Outro exame (1):</td>
	<td ><xsl:value-of select ="paciente[98]/exame1" /></td>
</tr>
<tr class="impar">
	<td align="left" >Outro exame (2):</td>
	<td ><xsl:value-of select ="paciente[98]/exame2" /></td>
</tr>
<tr class="par">
	<td align="left" >Outro exame (3):</td>
	<td ><xsl:value-of select ="paciente[98]/exame3" /></td>
</tr>
<tr class="impar">
	<td align="left" >Outro exame (4):</td>
	<td ><xsl:value-of select ="paciente[98]/exame4" /></td>
</tr>
<tr class="forms">
      <td colspan="2">
<!--           <img src="../imagens/setacima.jpg"></img> -->
<!--           <img src="../imagens/setabaixo.jpg"></img> -->
           4.	Acompanhamento
      </td>
</tr>
<tr class="par">
	<td align="left" >Desfecho do caso:</td>
	<td ><xsl:value-of select ="paciente[98]/desfecho" /></td>
</tr>
<tr class="impar">
	<td align="left" >Desfecho do caso diagnosticado como tuberculose:</td>
	<td ><xsl:value-of select ="paciente[98]/dtub" /></td>
</tr>
<tr class="par">
	<td align="left" >Desfecho do caso diagnosticado como NÃO tuberculose:</td>
	<td ><xsl:value-of select ="paciente[98]/dntub" /></td>
</tr>
<tr class="impar">
	<td align="left" >Se apresentou diagnóstico posterior de tuberculose, onde?</td>
	<td ><xsl:value-of select ="paciente[98]/aprtbp" /></td>
</tr>
<tr class="par">
	<td align="left" >Data da última consulta/VD:</td>
	<td ><xsl:value-of select ="paciente[98]/diaUCons" /></td>
</tr>
<tr class="impar">
	<td align="left" >Observações:</td>
	<td ><xsl:value-of select ="paciente[98]/observ" /></td>
</tr>
</table>
</body>
</html>
</xsl:template>
</xsl:stylesheet>

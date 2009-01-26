/* Javascript code for Neural TB Project */
	
	tabFields = new Array();
	tabFields[0] = ["nomeCompleto", "Nome"];
	tabFields[1] = ["nomeMae","Nome da mãe"];
	tabFields[2] = ["endereco","Endereço residencial"];
	tabFields[3] = ["contato","Endereço/tel para contato(associação de moradores, bar, igreja, etc)"];
	tabFields[4] = ["cidade","Cidade"];
	tabFields[5] = ["dia_nascimento","Data de nascimento"];
	tabFields[6] = ["idade", "Idade"];	
	tabFields[7] = ["naturalidadeEstado","Naturalidade","Cidade","UF"];
	tabFields[8] = ["naturalidadeCidade","Naturalidade"];
	tabFields[9] = ["naturalidadeAnosRio","Chegou no Rio há"];
	tabFields[10] = ["sexo","Sexo"];
	tabFields[11] = ["raca1","Raça"];
	tabFields[12] = ["raca2","Especifique"];
	tabFields[13] = ["estadoCivil","Estado civil"];
	tabFields[14] = ["companheiro","Tem companheiro(a)"];
	tabFields[15] = ["peso_habitual","Peso Habitual"];
	tabFields[16] = ["peso_atual","Peso Atual"];
	tabFields[17] = ["altura","Altura"];
	tabFields[18] = ["imc","IMC"];
	
	tabFields[19] = ["tosse","Tosse"];
	tabFields[20] = ["expectoracao","Expectoração"];
	tabFields[21] = ["hemoptoico","Hemoptóico"];
	tabFields[22] = ["hemoptise","Hemoptise"];
	tabFields[23] = ["hemoptiseQtd","Quantidade de hemoptise"];
	tabFields[24] = ["sudorese","Sudorese noturna"];
	tabFields[25] = ["febre","Febre"];
	tabFields[26] = ["dispneia","Dispnéia"];
	tabFields[27] = ["perdaApetite","Perda de apetite"];
	tabFields[28] = ["perdaPeso","Perda de peso"];
	tabFields[29] = ["dorToracica", "Dor torácica"];
	tabFields[30] = ["result","Resultado"];
	
	tabFields[31] = ["tratamentoAnteriorTB","Tratamento de TB anterior"];
	tabFields[32] = ["mes_diagnostico","ano_diagnostico","Data do diagnóstico de TB no passado"];
	tabFields[33] = ["TBdesfecho","Desfecho de TB"];
	
	tabFields[34] = ["internado","Internação Hospitalar"];
	tabFields[35] = ["prisao","Esteve em prisão"];
	tabFields[36] = ["delegacia","Esteve em delegacia"];
	tabFields[37] = ["contatoTBP","Contato com pessoas com TBP"];
	tabFields[38] = ["contatoTBPmoravaJunto","Morava com você"];
	tabFields[39] = ["contatoTBPtrabalhavaJunto","Trabalhava com você"];
	tabFields[40] = ["contatoTBPamigoParenteColega","Amigo, parente ou colega que não morava com você"];
	tabFields[41] = ["contatoTBPmenorQue3Anos","Alguns destes contatos foi menor do que 3 anos"];
	tabFields[42] = ["contatoTBPqual","Especifique esse contato"];
	tabFields[43] = ["fuma","Fuma"];
	tabFields[44] = ["fumaQtd","Número de cigarros que fuma/fumava por dia"];
	tabFields[45] = ["fumaTempo","Número de anos que fumou/fuma"];
	tabFields[46] = ["bebida","Bebida alcoólica favorita"];
	tabFields[47] = ["facilidadeFazerAmizades","Possui facilidade em fazer amizades"];
	tabFields[48] = ["diminuirQtdBebida","Já sentiu necessidade de diminuir a quantidade da bebida"];
	tabFields[49] = ["criticaModoBeber","Alguém critica ou já criticou o modo de beber"];
	tabFields[50] = ["bebidaManha","Costuma beber de manhã para diminuir nervosismo/ressaca"];
	tabFields[51] = ["culpadoManeiraBeber","Sente culpa pela maneira que bebe"];
	
	tabFields[52] = ["cagePositivo","Cage positivo"];
	
	tabFields[53] = ["desfechoConsultaIncial","Desfecho da consulta inicial"];
	tabFields[54] = ["inclusao","Inclusão"];
	tabFields[55] = ["criteriosInclusao","Critérios de inclusão"];
	tabFields[56] = ["dia_coleta1","#1"];
	tabFields[57] = ["coleta1","Forma"];
	tabFields[58] = ["dia_coleta2","#2"];
	tabFields[59] = ["coleta2","Forma"];
	tabFields[60] = ["cicatrizBCG","Cicatriz de BCG"];
	tabFields[61] = ["resultadoLeitura","Resultado da leitura"];
	tabFields[62] = ["dia_aplicacao","Data de aplicação da prova tuberculínica"];
	tabFields[63] = ["dia_leitura","Data da Leitura"];
	tabFields[64] = ["PTprimeiraDose","PT 1ª dose leitor"];
	
	
	
	
	
	/*
	
	var tabValores= new Array("Masculino", "Feminino", "Presente", "Ausente", "Ignorado",
	"Sim", "Não", "Branco", "Não-branco", "Negro", "Mulato", "Índio", "Asiático", "Outro", 
	"Casado", "Solteiro", "Separado", "Viúvo", "Pulmão", "Pleura", "Gânglio");
	
	tabFields[] = ["data_tbpassado","Data do diagnóstico de TB no passado"];
	tabFields[50] = ["local_tb","Local onde teve TB"];
	
	
	tabFields[64] = ["data_aplicacao","Data de aplicação da prova tuberculínica"];
	tabFields[65] = ["data_leitura","Data de leitura"];
	
	tabFields[67] = ["primeiro_auxilio_prob_saude","Quando procurou pela primeira vez auxilio para seu problema de saúde?"];
	tabFields[68] = ["onde_foi","Onde foi?"];
	tabFields[69] = ["porque_procurou","Por que procurou?"];
	tabFields[70] = ["companhia_familiares","Veio acompanhado de familiares?"];
	tabFields[71] = ["posto"," Foi encaminhado para o Posto pelo P. Saúde de Família?"];
	tabFields[72] = ["qual","Qual?"];
	tabFields[73] = ["sus"," Foi encaminhado por Unidade de Saúde do SUS?"];
	tabFields[74] = ["qual2","Qual?"];
	tabFields[75] = ["usp","Foi encaminhado por Unidade de Saúde Particular?"];
	tabFields[76] = ["qual3","Qual?"];
	tabFields[77] = ["auxilio_medico_sozinho","Decidiu sozinho procurar auxilio medico na Policlínica?"];
	tabFields[78] = ["porque","Por que?"];
	tabFields[79] = ["setor_policlinica","O encaminhamento foi para atendimento em qual setor da Policlínica?"];
	tabFields[80] = ["tratamento_tosse","Fez algum tratamento para a tosse ultimamente?"];
	tabFields[81] = ["qual4","Qual?"];
	tabFields[82] = ["dias","Durante quantos dias(total)?"];
	tabFields[83] = ["rx_torax","Trouxe RX de tórax?"];
	tabFields[84] = ["resultado_rx_torax","Trouxe algum resultado de RX de tórax?"];
	tabFields[85] = ["material_escarro","Trouxe material de escarro?"];
	tabFields[86] = ["resultado_escarro","Trouxe algum resultado de exame de escarro?"];
	tabFields[87] = ["resultado_biopsia","Trouxe algum resultado de biópsia?"];
	tabFields[88] = ["outro_resultado"," Trouxe algum outro resultado?"];
	tabFields[89] = ["qual5","Qual?"];
	
	*/
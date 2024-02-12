// Função de Empacotamento dos Dados
unsigned int Empacotar(unsigned int passo, unsigned int cor, unsigned int pos, unsigned int vel, unsigned int oleo) {
	unsigned int package = 0;

	// Movendo os bits de cada inteiro de 32 Bits sem sinal para seus respectivos locais
	passo = passo << 24;
	cor = cor << 16;
	pos = pos << 9;
	vel = vel << 5;
	oleo = oleo << 4;

	// Adicionando todos os bits na variavel "package" por meio do operador OR
	package = package | passo | cor | pos | vel | oleo;

	return package;
}

// Função de Retorno - Passo
unsigned int Passo(unsigned int pack) {
	// Movimentando os bits de "Passo" para os primeiros da cadeia
	pack = pack >> 24;

	return pack;
}

// Função de Retorno - Cor
unsigned int Cor(unsigned int pack) {
	// Movimentando os bits de "Cor" para os primeiros da cadeia
	pack = pack << 8;
	pack = pack >> 24;

	return pack;
}

// Função de Retorno - Posição
unsigned int Posicao(unsigned int pack) {
	// Movimentando os bits de "Posição" para os primeiros da cadeia
	pack = pack << 16;
	pack = pack >> 25;

	return pack;
}

// Função de Retorno - Velocidade
unsigned int Velocidade(unsigned int pack) {
	// Movimentando os bits de "Velocidade" para os primeiros da cadeia
	pack = pack << 23;
	pack = pack >> 28;

	return pack;
}

// Função de Retorno - Óleo (Pista)
unsigned int Pista(unsigned int pack) {
	// Movimentando o bit de "Pista" para o primeiro da cadeia
	pack = pack << 27;
	pack = pack >> 31;

	return pack;
}
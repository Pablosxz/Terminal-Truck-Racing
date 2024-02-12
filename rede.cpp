#include "pacote.h"
#include "cores.h"
#include <iostream>
using namespace std;

// Vari�vel Global
int rede;

// Fun��o de Transmiss�o dos Dados
void Transmitir(unsigned int passo, unsigned int cor, unsigned int pos, unsigned int vel, unsigned int oleo) {
	cout << "Transmitindo dados...\n";
	rede = Empacotar(passo, cor, pos, vel, oleo); // Empacota todos os dados em um Inteiro de 32 bits sem sinal.

	// Impress�o do Pacote
	AjustarCor(black, Cor(rede));
	cout << rede << "\n";
	ResetarCor();
}

// Fun��o de Recep��o dos Dados
unsigned int Receber() {
	cout << "Recebendo dados...\n";

	// Frame (Passo)
	AjustarCor(Cor(rede), black);
	cout << "Frame ";
	AjustarCor(black, Cor(rede));
	cout << " " << Passo(rede) << " ";

	// Posi��o
	AjustarCor(Cor(rede), black);
	cout << " Pos "; 
	AjustarCor(black, Cor(rede));
	cout << " " << Posicao(rede) << " ";

	// Velocidade
	AjustarCor(Cor(rede), black);
	cout << " Vel "; 
	AjustarCor(black, Cor(rede));
	cout << " " << Velocidade(rede) << " ";

	// �leo
	AjustarCor(Cor(rede), black);
	cout << " Oil ";
	AjustarCor(black, Cor(rede));
	if (Pista(rede) == true) {
		cout << " True \n";
	}
	else {
		cout << " False \n";
	}
	
	ResetarCor();
	return rede;
}

// Fun��o de Processamento dos Dados
unsigned int Processar(unsigned int rede) {
	cout << "Processando dados...\n";
	unsigned int n_pos = Posicao(rede) + Velocidade(rede) - Pista(rede); // Calcula a nova posi��o do Caminh�o

	// Impress�o da Nova Posi��o
	AjustarCor(Cor(rede), black);
	cout << "Pr�xima posi��o: " << n_pos << "\n\n";
	ResetarCor();
	return n_pos;
}
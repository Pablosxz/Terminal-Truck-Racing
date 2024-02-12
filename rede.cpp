#include "pacote.h"
#include "cores.h"
#include <iostream>
using namespace std;

// Variável Global
int rede;

// Função de Transmissão dos Dados
void Transmitir(unsigned int passo, unsigned int cor, unsigned int pos, unsigned int vel, unsigned int oleo) {
	cout << "Transmitindo dados...\n";
	rede = Empacotar(passo, cor, pos, vel, oleo); // Empacota todos os dados em um Inteiro de 32 bits sem sinal.

	// Impressão do Pacote
	AjustarCor(black, Cor(rede));
	cout << rede << "\n";
	ResetarCor();
}

// Função de Recepção dos Dados
unsigned int Receber() {
	cout << "Recebendo dados...\n";

	// Frame (Passo)
	AjustarCor(Cor(rede), black);
	cout << "Frame ";
	AjustarCor(black, Cor(rede));
	cout << " " << Passo(rede) << " ";

	// Posição
	AjustarCor(Cor(rede), black);
	cout << " Pos "; 
	AjustarCor(black, Cor(rede));
	cout << " " << Posicao(rede) << " ";

	// Velocidade
	AjustarCor(Cor(rede), black);
	cout << " Vel "; 
	AjustarCor(black, Cor(rede));
	cout << " " << Velocidade(rede) << " ";

	// Óleo
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

// Função de Processamento dos Dados
unsigned int Processar(unsigned int rede) {
	cout << "Processando dados...\n";
	unsigned int n_pos = Posicao(rede) + Velocidade(rede) - Pista(rede); // Calcula a nova posição do Caminhão

	// Impressão da Nova Posição
	AjustarCor(Cor(rede), black);
	cout << "Próxima posição: " << n_pos << "\n\n";
	ResetarCor();
	return n_pos;
}
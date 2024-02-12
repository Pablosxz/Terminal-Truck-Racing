#include <iostream>
#include "cores.h"
using namespace std;

// Fun��o de Ajuste das Cores
void AjustarCor(unsigned int texto, unsigned int fundo) {

	// Cor do Texto
	cout << "\033[38;5;" << texto << "m";

	// Cor do Fundo
	cout << "\033[48;5;" << fundo << "m";
}

// Fun��o de Reset das Cores
void ResetarCor() {

	// Cor Padr�o do Terminal
	cout << Default;
}
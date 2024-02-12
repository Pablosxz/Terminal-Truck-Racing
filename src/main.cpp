#include <iostream>
#include <cstdlib>
#include "cores.h"
#include "rede.h" 
#include "pacote.h"
using namespace std;

// Prot�tipos
void WhiteSpace(int);
void Desenhar(int, int);

int main()
{
	// Seed da fun��o 'rand()'
	srand(unsigned(time(NULL)));

	// Inicializa��o
	unsigned int posA = 0, posB = 0;
	int corA = cyan, corB = green;
	short int velA = 0, velB = 0;
	bool oleoA = 0, oleoB = 0;
	
	int passo = 0;

	// Loop
	do {
		system("cls");

		// T�tulo
		AjustarCor(white, gray);
		cout.width(61); cout << "Truck Racing"; cout.width(61);

		// Impress�o
		Desenhar(posA, corA);
		Desenhar(posB, corB);

		// Atualiza��es
		velA = rand() % 10 + 1;
		velB = rand() % 10 + 1;
		oleoA = rand() % 2;
		oleoB = rand() % 2;

		// Rede - A
		Transmitir(passo, corA, posA, velA, oleoA);
		unsigned int rede = Receber();
		posA = Processar(rede);

		// Rede - B
		Transmitir(passo, corB, posB, velB, oleoB);
		rede = Receber();
		posB = Processar(rede);

		// Rodap�
		AjustarCor(white, gray);
		cout.width(120); cout << right << "[ENTER] Continuar >";
		ResetarCor();
		system("pause > nul");

		passo++;
	}while(posA <= 100 && posB <= 100);

	system("cls");

	// T�tulo
	AjustarCor(white, gray);
	cout.width(61); cout << "Truck Racing"; cout.width(61);
	
	// Impress�o
	Desenhar(posA, corA);
	Desenhar(posB, corB);

	// Sub-T�tulo
	AjustarCor(white, gray);
	cout.width(65); cout << "Corrida Conclu�da"; cout.width(65);

	// Resultados
	cout << "\n\n Passos ";
	ResetarCor();
	cout << " " << passo << " \n\n";

	// Resultado A
	AjustarCor(black, corA);
	cout << " Posi��o "; 
	AjustarCor(corA, black);
	cout << " " << posA << " ";

	AjustarCor(black, corA);
	cout << " Velocidade m�dia ";
	AjustarCor(corA, black);

	// Imprimindo a velocidade m�dia A com 2 casas decimais
	cout << fixed;
	cout.precision(2);
	cout << " " << float(posA) / passo << " " << "\n\n";

	// Resultado B
	AjustarCor(black, corB);
	cout << " Posi��o ";
	AjustarCor(corB, black);
	cout << " " << posB << " ";

	AjustarCor(black, corB);
	cout << " Velocidade m�dia ";
	AjustarCor(corB, black);

	// Imprimindo a velocidade m�dia B com 2 casas decimais
	cout << fixed;
	cout.precision(2);
	cout << " " << float(posB) / passo << " " << "\n";
	ResetarCor();
	cout << "\n";

	// Linha Separadora
	AjustarCor(white, gray);
	cout.width(123);
	ResetarCor();
	cout << "\n";
}

// Fun��o de Espa�os
void WhiteSpace(int qtd) { while (qtd-- > 0) cout << ' '; }

// Fun��o de Impress�o
void Desenhar(int pos, int cor) {

	cout << "\n\n";

	// Imprimindo o Caminh�o
	AjustarCor(cor, black);
	WhiteSpace(pos);
	cout << " \xDB\xDB\xDB\xDB\xDB\xDB \xDB\xDB\xDC\n";
	WhiteSpace(pos);
	cout << " \xDFOO\xDF\xDF\xDF\xDF\xDFO\xDF\n";
	cout << " ----------------------------------------------------------------------------------------------------|------------------\n";
	cout << "                                                                                                    100";
	
	cout << "\n\n";

	ResetarCor();
}
#include <iostream>
#include <cstdlib>
#include "cores.h"
#include "rede.h" 
#include "pacote.h"
using namespace std;

// Protótipos
void WhiteSpace(int);
void Desenhar(int, int);

int main()
{
	// Seed da função 'rand()'
	srand(unsigned(time(NULL)));

	// Inicialização
	unsigned int posA = 0, posB = 0;
	int corA = cyan, corB = green;
	short int velA = 0, velB = 0;
	bool oleoA = 0, oleoB = 0;
	
	int passo = 0;

	// Loop
	do {
		system("cls");

		// Título
		AjustarCor(white, gray);
		cout.width(61); cout << "Truck Racing"; cout.width(61);

		// Impressão
		Desenhar(posA, corA);
		Desenhar(posB, corB);

		// Atualizações
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

		// Rodapé
		AjustarCor(white, gray);
		cout.width(120); cout << right << "[ENTER] Continuar >";
		ResetarCor();
		system("pause > nul");

		passo++;
	}while(posA <= 100 && posB <= 100);

	system("cls");

	// Título
	AjustarCor(white, gray);
	cout.width(61); cout << "Truck Racing"; cout.width(61);
	
	// Impressão
	Desenhar(posA, corA);
	Desenhar(posB, corB);

	// Sub-Título
	AjustarCor(white, gray);
	cout.width(65); cout << "Corrida Concluída"; cout.width(65);

	// Resultados
	cout << "\n\n Passos ";
	ResetarCor();
	cout << " " << passo << " \n\n";

	// Resultado A
	AjustarCor(black, corA);
	cout << " Posição "; 
	AjustarCor(corA, black);
	cout << " " << posA << " ";

	AjustarCor(black, corA);
	cout << " Velocidade média ";
	AjustarCor(corA, black);

	// Imprimindo a velocidade média A com 2 casas decimais
	cout << fixed;
	cout.precision(2);
	cout << " " << float(posA) / passo << " " << "\n\n";

	// Resultado B
	AjustarCor(black, corB);
	cout << " Posição ";
	AjustarCor(corB, black);
	cout << " " << posB << " ";

	AjustarCor(black, corB);
	cout << " Velocidade média ";
	AjustarCor(corB, black);

	// Imprimindo a velocidade média B com 2 casas decimais
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

// Função de Espaços
void WhiteSpace(int qtd) { while (qtd-- > 0) cout << ' '; }

// Função de Impressão
void Desenhar(int pos, int cor) {

	cout << "\n\n";

	// Imprimindo o Caminhão
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
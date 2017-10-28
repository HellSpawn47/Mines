#include "Randomizador.h"

using namespace std;

int Randomizador::obtenerNumeroAleatorioEntreRango(int minimo, int maximo){
	setearSemillaRandom();
	int numero=0;
	numero=(rand()%(maximo+1-minimo))+minimo;

	return numero;
}

void Randomizador::setearSemillaRandom(){
	srand((time(0)));
}

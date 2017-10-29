#include "Randomizador.h"

using namespace std;

uint Randomizador::obtenerNumeroAleatorioEntreRango(uint minimo, uint maximo){
	uint numero=0;
	numero=(rand()%(maximo+1-minimo))+minimo;

	return numero;
}

void Randomizador::setearSemillaRandom(){
	srand((time(0)));
}

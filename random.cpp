#include "random.h"

using namespace std;

int numeroAleatorioEntreRango(int minimo, int maximo){

	int numero=0;
	numero=(rand()%(maximo+1-minimo))+minimo;

	return numero;
}

void setearSemillaRandom(){
	srand((time(0)));
}

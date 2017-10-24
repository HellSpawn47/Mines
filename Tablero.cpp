#include "Tablero.h"

Tablero::Tablero(int filas, int columnas){

	tablero = new char* [filas];

	for(int i = 0; i < filas; i++){

		tablero[i] = new char [columnas];
	}
}

Tablero::Inicializar(int cantidadDeBombas){


}

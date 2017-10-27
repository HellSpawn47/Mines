#include "Tablero.h"
#include <iostream>

Tablero::Tablero(uint filas, uint columnas){

	this->filas = filas;
	this->columnas = columnas;

	tablero = new Casillero* [filas];

	for(uint i = 0; i < filas; i++){

		tablero[i] = new Casillero [columnas];
	}
}

void Tablero::inicializar(uint cantidadDeBombas){


}

uint Tablero::obtenerValorCasillero(uint fila, uint columna){

	return tablero[fila][columna].getValor();

}

void Tablero::imprimir(){

	for(uint i = 0; i < this->filas; i++){
		for(uint j = 0; j < this->columnas; j++){

			std::cout << this->obtenerValorCasillero(i, j);

		}
		std::cout << '\n';

	}


}

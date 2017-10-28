#include "Tablero.h"
#include "constantes.h"
#include <iostream>

Tablero::Tablero(uint filas, uint columnas){

	this->cantidadFilas = filas;
	this->cantidadColumnas = columnas;

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

uint Tablero::obtenerEstadoCasillero(uint fila, uint columna){

	return tablero[fila][columna].getEstado();

}

void Tablero::cambiarEstadoCasillero(uint fila, uint columna, uint nuevoEstado){

	tablero[fila][columna].setEstado(nuevoEstado);

}

void Tablero::marcarCasillero(uint fila, uint columna){

	this->cambiarEstadoCasillero(fila, columna, MARCADO);

}

void Tablero::descubirCasillero(uint fila, uint columna){

	this->cambiarEstadoCasillero(fila, columna, DESCUBIERTO);

}

uint Tablero::obtenerCantidadFilas(){

	return this->cantidadFilas;

}

uint Tablero::obtenerCantidadColumnas(){

	return this->cantidadColumnas;

}

void Tablero::imprimir(){

	for(uint i = 0; i < this->cantidadFilas; i++){
		for(uint j = 0; j < this->cantidadColumnas; j++){

			std::cout << this->obtenerValorCasillero(i, j);

		}
		std::cout << '\n';

	}


}

#include "Tablero.h"
#include "Randomizador.h"
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

	this->ponerBombasAleatoriamente(cantidadDeBombas);

	this->rellenarConNumeros();

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

void Tablero::ponerBombasAleatoriamente(uint cantidadBombas){
		Randomizador* randomizador = new Randomizador;
		randomizador->setearSemillaRandom();
		uint coordenadaX, coordenadaY;
		for(uint cantBombas = 0; cantBombas < cantidadBombas; cantBombas++){

			do{

				coordenadaX = randomizador->obtenerNumeroAleatorioEntreRango(0, this->cantidadFilas-1);
				coordenadaY = randomizador->obtenerNumeroAleatorioEntreRango(0, this->cantidadColumnas-1);

			}while(tablero[coordenadaX][coordenadaY].getValor() == BOMBA);

			tablero[coordenadaX][coordenadaY].setValor(BOMBA);
		}

		delete randomizador;

}

void Tablero::rellenarConNumeros(){
	for(uint fila = 0; fila < this->cantidadFilas; fila++){
		for(uint columna = 0; columna < this->cantidadColumnas; columna++){

			if(this->obtenerValorCasillero(fila, columna) == BOMBA){
				rellenarSubMatrizAledaniaBomba(fila, columna);
			}

		}
	}
}

void Tablero::rellenarSubMatrizAledaniaBomba(uint fila,uint columna){
	for(uint i = fila-1; i <= fila+1; i++){
		for(uint j = columna-1; j <= columna+1; j++){

			if(this->esPosicionValida(i,j) && this->obtenerValorCasillero(fila, columna) != BOMBA){
				tablero[i][j].incrementarValor();
			}

		}
	}
}

bool Tablero::esPosicionValida(uint fila, uint columna){

	return (fila >= 0 && columna >= 0 && fila < this->cantidadFilas && columna < this->cantidadColumnas);

}

Tablero::~Tablero() {
	for (uint i=0; i<this->cantidadFilas; i++){
		delete[] tablero[i];
	}
	delete[] tablero;
}

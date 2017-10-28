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

void Tablero::ponerBombasAleatoriamente(){
	/*	setearSemillaRandom();
		int coordenadaX, coordenadaY;
		for(int cantBombas = 0; cantBombas < CANTIDAD_BOMBAS; cantBombas++){

			do{

				coordenadaX = numeroAleatorioEntreRango(0, DIMENSION-1);
				coordenadaY = numeroAleatorioEntreRango(0, DIMENSION-1);

			}while(tablero[coordenadaX][coordenadaY].getValor() == BOMBA);

			tablero[coordenadaX][coordenadaY].setValor(BOMBA);
		}*/
	//Eso esta mal,falta hacerlo de forma copada
}

void Tablero::rellenarConNumeros(){
	for(int fila = 0; fila < this->cantidadFilas; fila++){
		for(int columna = 0; columna < this->cantidadColumnas; columna++){

			if(this->obtenerValorCasillero(fila, columna) == BOMBA){
				rellenarSubMatrizAledaniaBomba(fila, columna);
			}

		}
	}
}

void Tablero::rellenarSubMatrizAledaniaBomba(int fila,int columna){
	for(int i = fila-1; i <= fila+1; i++){
		for(int j = columna-1; j <= columna+1; j++){

			if(this->esPosicionValida(i,j) && this->obtenerValorCasillero(fila, columna) != BOMBA){
				tablero[i][j].incrementarValor();
			}

		}
	}
}

bool Tablero::esPosicionValida(uint fila, uint columna){

	return (fila >= 0 && columna >= 0 && fila < this->cantidadFilas && columna < this->cantidadColumnas);

}

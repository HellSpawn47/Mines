#include "Tablero.h"
#include "Randomizador.h"
#include "constantes.h"
#include "TableroBMP.h"
#include <iostream>

using namespace std;

Tablero::Tablero(uint filas, uint columnas){

	this->cantidadFilas = filas;
	this->cantidadColumnas = columnas;
    this->casillerosPorDescubrir = filas*columnas;

	tablero = new Casillero* [filas];

	for(uint i = 0; i < filas; i++){

		tablero[i] = new Casillero [columnas];
	}
}

void Tablero::inicializar(uint cantidadDeBombas){

    this->casillerosPorDescubrir = this->casillerosPorDescubrir - cantidadDeBombas;

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
	if (this->obtenerEstadoCasillero(fila,columna) == MARCADO){
		this->cambiarEstadoCasillero(fila,columna,OCULTO);
	}
	else{
		this->cambiarEstadoCasillero(fila, columna, MARCADO);
	}
}

void Tablero::descubrirCasillero(uint fila, uint columna){

	if(tablero[fila][columna].getValor() == CERO){
		this->descubrirCasillerosAledaniosVacio(fila, columna);
	}
	else{
		this->cambiarEstadoCasillero(fila, columna, DESCUBIERTO);
	}

}

int Tablero::descubrirCasillerosAledaniosVacio(int fila,int columna){

	if(!esPosicionValida(fila,columna))
		return 0;
	if(tablero[fila][columna].getValor() == CERO && tablero[fila][columna].getEstado() == OCULTO){

		this->cambiarEstadoCasillero(fila, columna, DESCUBIERTO);

		for(int i = fila-1; i <= fila+1; i++){
			for(int j = columna-1; j <= columna+1; j++){

				if(this->descubrirCasillerosAledaniosVacio(i, j)){ //Llamado recursivo.
					return 1;
				}

			}
		}
	}
	else{
		this->cambiarEstadoCasillero(fila, columna, DESCUBIERTO);
		return 0;
	}
	return 0;
}

uint Tablero::obtenerCantidadFilas(){

	return this->cantidadFilas;

}

uint Tablero::obtenerCantidadColumnas(){

	return this->cantidadColumnas;

}

void Tablero::imprimir(){
	int marcados = 0;
	TableroBMP tableroBMP(this->cantidadFilas, this->cantidadColumnas);

	for(int fila = 0; fila < this->cantidadFilas; fila++){

		for(int columna = 0; columna < this->cantidadColumnas; columna++){
			if(tablero[fila][columna].getEstado() == OCULTO){
				tableroBMP.completarCasilleroOculto(fila, columna);
			}
			else if(tablero[fila][columna].getEstado()==MARCADO){
				tableroBMP.completarConBandera(fila, columna);
				marcados++;
			}
			else {
				tableroBMP.completarConJugada(fila, columna, tablero[fila][columna].getValor());
			}
		}

	}
	if(marcados>0){
		cout<<"               Cantidad de Casilleros Marcados: "<<marcados<<endl;
	}

	tableroBMP.imprimirTablero();

}

void Tablero::ponerBombasAleatoriamente(uint cantidadBombas){

		Randomizador* randomizador = new Randomizador;
		randomizador->setearSemillaRandom();
		uint cantPosiciones = (this->cantidadFilas * this->cantidadColumnas);
		uint vectorDePosiciones[cantPosiciones];

		for(uint i = 0; i < cantPosiciones; i++){
			vectorDePosiciones[i] = i;
		}

		for (uint i = 0; i < cantidadBombas; i++) {
			uint random = randomizador->obtenerNumeroAleatorioEntreRango(0, cantPosiciones - i - 1);
		    uint posicion = vectorDePosiciones[random];
		    vectorDePosiciones[random] = vectorDePosiciones[cantPosiciones - i - 1];
		    uint fila = posicion / (this->cantidadFilas);
		    uint col = posicion % (this->cantidadColumnas);
		    this->tablero[fila][col].setValor(BOMBA);

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

void Tablero::rellenarSubMatrizAledaniaBomba(int fila,int columna){
	for(int i = fila-1; i <= fila+1; i++){
		for(int j = columna-1; j <= columna+1; j++){

			if(this->esPosicionValida(i, j) && this->obtenerValorCasillero(i, j) != BOMBA){
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

void Tablero::descubrirTodasLasBombas(){
	for(uint fila = 0; fila < this->cantidadFilas; fila++){
		for(uint columna = 0; columna < this->cantidadColumnas; columna++){

			if(this->obtenerValorCasillero(fila, columna) == BOMBA){
				this->cambiarEstadoCasillero(fila, columna, DESCUBIERTO);
			}

		}
	}

}

bool Tablero::estanTodosCasillerosDescubiertos(){
	for(uint fila = 0; fila < this->cantidadFilas; fila++){
		for(uint columna = 0; columna < this->cantidadColumnas; columna++){

			if(this->obtenerValorCasillero(fila, columna) != BOMBA && this->obtenerEstadoCasillero(fila,columna) == OCULTO){
				return false;
			}

		}
	}
	return true;
}

uint Tablero::casillerosRestantesPorDescubrir(){
    return (this->casillerosPorDescubrir);
}

#include "EstadoDePartida.h"

#include <iostream>

EstadoDePartida::EstadoDePartida(){

	this->posicionesDescubiertas = NULL;

	this->tope = 0;
}

void EstadoDePartida::agregarPosicionDescubierta(uint fila, uint columna){
	tope++;
	Posicion* arrayAuxiliar = new Posicion [tope];
	Posicion nuevaPosicion;

	nuevaPosicion.fila = fila;
	nuevaPosicion.columna = columna;

	if(posicionesDescubiertas){
		for (uint i = 0; i < tope ; i++){
			arrayAuxiliar[i] = posicionesDescubiertas[i];
		}
	}

	arrayAuxiliar[tope-1] = nuevaPosicion;

	posicionesDescubiertas = arrayAuxiliar;

	for (int i = 0 ; i < tope ; i++){

		std::cout << "fila, columna: " << posicionesDescubiertas[i].fila << posicionesDescubiertas[i].columna << std::endl;

	}
}


Posicion* EstadoDePartida::obtenerPosicionesDescubiertas(){

	return posicionesDescubiertas;

}

EstadoDePartida::~EstadoDePartida(){
	delete [] posicionesDescubiertas;
}



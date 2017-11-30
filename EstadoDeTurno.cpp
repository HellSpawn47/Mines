#include "EstadoDeTurno.h"

#include <iostream>

EstadoDeTurno::EstadoDeTurno(){

	this->posicionesDescubiertas = NULL;

	this->jugadorEliminado=NULL;

	this->tope = 0;
}

void EstadoDeTurno::agregarPosicionInteractuada(uint fila, uint columna, char estadoDeLaPosicion){
	tope++;
	Posicion* arrayAuxiliar = new Posicion [tope];
	Posicion nuevaPosicion;

	nuevaPosicion.fila = fila;
	nuevaPosicion.columna = columna;
	nuevaPosicion.estadoDePosicion = estadoDeLaPosicion;

	if(posicionesDescubiertas){
		for (uint i = 0; i < (tope-1) ; i++){
			arrayAuxiliar[i] = posicionesDescubiertas[i];
		}
	}

	arrayAuxiliar[tope-1] = nuevaPosicion;

	delete[] posicionesDescubiertas;
	posicionesDescubiertas = arrayAuxiliar;


}

void EstadoDeTurno::agregarJugadorEliminado(Jugador* jugador){
	this->jugadorEliminado = jugador;

}

Jugador* EstadoDeTurno::obtenerJugadorEliminado(){
	return jugadorEliminado;

}

Posicion* EstadoDeTurno::obtenerPosicionesDescubiertas(){

	return posicionesDescubiertas;

}

uint EstadoDeTurno::obtenerTope(){
	return tope;
}


EstadoDeTurno::~EstadoDeTurno(){
	delete[] posicionesDescubiertas;
}



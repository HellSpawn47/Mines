#include "EstadoDePartida.h"

#include <iostream>

EstadoDePartida::EstadoDePartida(){

	this->posicionesDescubiertas = NULL;

	this->jugadorEliminado=NULL;

	this->tope = 0;
}

void EstadoDePartida::agregarPosicionInteractuada(uint fila, uint columna, char estadoDeLaPosicion){
	tope++;
	Posicion* arrayAuxiliar = new Posicion [tope];
	Posicion nuevaPosicion;

	nuevaPosicion.fila = fila;
	nuevaPosicion.columna = columna;
	nuevaPosicion.estadoDePosicion = estadoDeLaPosicion;

	if(posicionesDescubiertas){
		for (uint i = 0; i < tope ; i++){
			arrayAuxiliar[i] = posicionesDescubiertas[i];
		}
	}

	arrayAuxiliar[tope-1] = nuevaPosicion;

	delete[] posicionesDescubiertas;
	posicionesDescubiertas = arrayAuxiliar;

	/*
	for (uint i = 0 ; i < tope ; i++){

		std::cout << "fila, columna: " << posicionesDescubiertas[i].fila << posicionesDescubiertas[i].columna << std::endl;

	}
	*/
}

void EstadoDePartida::agregarJugadorEliminado(Jugador* jugador){
	this->jugadorEliminado = jugador;

}

Jugador* EstadoDePartida::obtenerJugadorEliminado(){
	return jugadorEliminado;

}

Posicion* EstadoDePartida::obtenerPosicionesDescubiertas(){

	return posicionesDescubiertas;

}

uint EstadoDePartida::obtenerTope(){
	return tope;
}


EstadoDePartida::~EstadoDePartida(){
	delete[] posicionesDescubiertas;
}



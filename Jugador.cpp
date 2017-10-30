#include "Jugador.h"

using namespace std;

Jugador::Jugador(string nombre, uint numeroJugador){

	this->nombre = nombre;
	this->puntaje = 0;
	this->sigueJugando = true;
	this->numeroJugador = numeroJugador;

}

string Jugador::getNombre(){

	return this->nombre;

}

int Jugador::getPuntaje(){

	return this->puntaje;

}

bool Jugador::getSigueJugando(){

	return this->sigueJugando;

}

void Jugador::modificarPuntaje(short int puntos){

	this->puntaje += puntos;

}

void Jugador::dejarFueraDeJuego(){

	this->sigueJugando = false;

}

uint Jugador::getNumeroJugador(){

	return this->numeroJugador;

}

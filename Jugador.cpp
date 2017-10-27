#include "Jugador.h"

using namespace std;

Jugador::Jugador(string nombre){

	this->nombre = nombre;
	this->puntaje = 0;
	this->sigueJugando = true;

}

string Jugador::getNombre(){

	return this->nombre;

}

uint Jugador::getPuntaje(){

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

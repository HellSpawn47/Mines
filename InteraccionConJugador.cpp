#include "InteraccionConJugador.h"
#include <iostream>

using namespace std;

uint InteraccionConJugador::pedirCantidad(string unaCosa){
	uint cantidad = 0;

	cout << "Ingrese la cantidad de" << unaCosa << ": ";

	cin >> cantidad ;

	return cantidad;

}

char InteraccionConJugador::pedirDificultad(){
	char dificultad;

	cout << "Ingrese la dificultad: ";

	cin >> dificultad;

	return dificultad;

}

string InteraccionConJugador::pedirNombreJugador(uint numero){
	string nombre;

	cout << "Ingrese el nombre del Jugador " << numero << ": ";

	cin >> nombre;

	return nombre;
}

string InteraccionConJugador::pedirJugada(){
	string jugada;

	cout << "Ingrese accion(m/d/s),fila,columna: ";

	cin >> jugada;

	return jugada;

}

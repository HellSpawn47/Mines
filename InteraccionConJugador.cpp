#include "InteraccionConJugador.h"
#include <iostream>

using namespace std;

void InteraccionConJugador::bienvenida(){

	imprimirMensaje("BIENVENIDO AL BUSCAMINAS");
	imprimirMensaje("V2.0 - by God Save The Pandas");

}

void InteraccionConJugador::imprimirMensaje(string frase){

	cout<<"\n                 ..::"<<frase<<"::..\n";
}

uint InteraccionConJugador::pedirCantidad(string unaCosa){
	uint cantidad = 0;

	cout << "Ingrese la cantidad de " << unaCosa << ": ";

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

void InteraccionConJugador::pedirJugada(Jugada* jugada){
	uint fila, columna;
	char accion, coma;
	cout << "Ingrese accion(d/m/s),fila,columna: ";

	cin >> accion;
	cin >> coma;
	cin >> fila;
	cin >> coma;
	cin >> columna;

	jugada->modificarFila(fila);
	jugada->modificarColumna(columna);
	jugada->modificarAccion(accion);
}

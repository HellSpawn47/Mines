#include "InteraccionConJugador.h"
#include <iostream>

using namespace std;

void InteraccionConJugador::bienvenida(){

	imprimirBanner();
	imprimirMensaje("BIENVENIDO AL BUSCAMINAS");
	imprimirMensaje("V2.0 - by God Save The Pandas");
	cout << endl;

}

void InteraccionConJugador::imprimirBanner(){
	cout << "	                                              __ \n";
	cout << "	    _____                       _            |  |\n";
	cout << "	   | __  |_ _ ___ ___ ___ _____|_|___ ___ ___|  |\n";
	cout << "	   | __ -| | |_ -|  _| .'|     | |   | .'|_ -|__|\n";
	cout << "	   |_____|___|___|___|__,|_|_|_|_|_|_|__,|___|__|\n";
	cout << "	                                                 V2.0\n";
	cout << "\n";
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

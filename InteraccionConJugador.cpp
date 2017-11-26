#include "InteraccionConJugador.h"
#include "validadorDeIngresos.h"
#include "Partida.h"
#include <iostream>


using namespace std;

void InteraccionConJugador::bienvenida(){

	imprimirBanner();
	imprimirMensaje("BIENVENIDO AL BUSCAMINAS");
	imprimirMensaje("V3.0 - by God Save The Pandas");
	cout << endl;

}

void InteraccionConJugador::imprimirBanner(){
	cout << "	                                              __ \n";
	cout << "	    _____                       _            |  |\n";
	cout << "	   | __  |_ _ ___ ___ ___ _____|_|___ ___ ___|  |\n";
	cout << "	   | __ -| | |_ -|  _| .'|     | |   | .'|_ -|__|\n";
	cout << "	   |_____|___|___|___|__,|_|_|_|_|_|_|__,|___|__|\n";
	cout << "	                                                 V3.0\n";
	cout << "\n";
}

void InteraccionConJugador::imprimirMensaje(string frase){

	cout<<"\n                 ..::"<<frase<<"::..\n";
}

uint InteraccionConJugador::pedirCantidad(string unaCosa){
	uint cantidad = 0;

	cout << "\nIngrese la cantidad de " << unaCosa << ": ";

	cin >> cantidad ;

	return cantidad;

}

char InteraccionConJugador::pedirDificultad(){
	char dificultad;
	Validador validador;
	do{

		cout << "\nIngrese la dificultad: ";

		cin >> dificultad;

		if (!validador.esDificultadValida(dificultad)){
			cout << "La dificultad ingresada no es valida, ingrese nuevamente" << endl;
		}

	}while (!validador.esDificultadValida(dificultad));

	return dificultad;

}

string InteraccionConJugador::pedirNombreJugador(uint numero){
	string nombre;

	cout << "\nIngrese el nombre del Jugador " << numero+1<< ": ";

	cin >> nombre;

	return nombre;
}

void InteraccionConJugador::pedirJugada(Jugada* jugada,Partida* partida){
	uint fila, columna;
	Validador validador;
	char accion, coma;
	do{
		cout << "\nIngrese accion(d/m),fila,columna: ";

		cin >> accion;
		cin >> coma;
		cin >> fila;
		cin >> coma;
		cin >> columna;

		fila--;
		columna--;
		if ((!partida->getTablero()->esPosicionValida(fila,columna))||(!validador.esAccionValida(accion))){
				cout << "La accion ingresada no es valida, ingrese nuevamente" << endl;
		}



	}while ((!partida->getTablero()->esPosicionValida(fila,columna))||(!validador.esAccionValida(accion)));

	jugada->modificarFila(fila);
	jugada->modificarColumna(columna);
	jugada->modificarAccion(accion);
}

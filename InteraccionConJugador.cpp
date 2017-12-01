#include "InteraccionConJugador.h"
#include "validadorDeIngresos.h"
#include "constantes.h"
#include "NodoDeEstados.h"
#include <iostream>
#include <sstream>

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

bool InteraccionConJugador::preguntarViajeTemporal(){
	Validador validador;
	char accion;
	do{
		cout << "Quiere deshacer/rehacer turnos? s/n: ";
		cin >> accion;
		if (!validador.verificarSiNo(accion)){
			cout << "La accion ingresada no es valida, ingrese nuevamente" << endl;
		}
	}while (!validador.verificarSiNo(accion));

	return (accion=='s');
}

void InteraccionConJugador::pedirJugada(Jugada* jugada,Partida* partida){
	uint fila = 0;
	uint columna = 0;
	Validador validador;
	char accion, coma;
	//s: Si, n: No.

	//a: Abrir, m: Marcar
	do{
			cout << "\nIngrese accion(a/m/s),fila,columna: ";
			cin >> accion;

			if(accion != SALIR){
				cin >> coma;
				cin >> fila;
				cin >> coma;
				cin >> columna;
				fila--;
				columna--;
				if ((!partida->getTablero()->esPosicionValida(fila,columna))||(!validador.esAccionValida(accion))){
					cout << "La accion ingresada no es valida, ingrese nuevamente" << endl;
				}
			}

	}while (((!partida->getTablero()->esPosicionValida(fila,columna))||(!validador.esAccionValida(accion))) && (accion!=SALIR));
		if (accion!=SALIR){
			jugada->modificarFila(fila);
			jugada->modificarColumna(columna);
	}

	jugada->modificarAccion(accion);
}

char InteraccionConJugador::pedirDeshacerORehacer(int puntaje,int cantidadRehacer,int cantidadDeshacer){
	char accion;
	string cantidadPosible;
	if (COSTE>0){
		int division = puntaje/COSTE;
		stringstream ss;
		ss << division;
		cantidadPosible = ss.str();
	}else{
		cantidadPosible = "infinitas";
	}

	do{

		cout << "Con tu puntaje actual podes deshacer/rehacer hasta " << cantidadPosible << " jugadas, es posible deshacer " << cantidadDeshacer <<
		    " turnos y \n" << "rehacer hasta " << cantidadRehacer << " turnos (considerando realidades alternativas), que desea hacer (d/r/s)?" << endl;
		cin >> accion;

		if (accion!=REHACER && accion!=DESHACER && accion!=SALIR){
			cout << "\nLa accion ingresada no es valida, ingrese nuevamente \n" << endl;
		}

	}while (accion!=REHACER && accion!=DESHACER && accion!=SALIR);
	return accion;
}

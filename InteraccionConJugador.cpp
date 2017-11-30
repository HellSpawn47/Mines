#include "InteraccionConJugador.h"
#include "validadorDeIngresos.h"
#include "constantes.h"
#include "NodoDeEstados.h"
#include "ArbolDeEstados.h"
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

void InteraccionConJugador::pedirJugada(Jugada* jugada,Partida* partida,ArbolDeEstados* arbol){
	uint fila, columna;
	Validador validador;
	char accion, coma;
	//s: Si, n: No.
	/*if (puntajeJugadorEnTurno >= 3){
		do{
			cout << "Quiere deshacer/rehacer turnos? s/n: ";
			cin >> accion;
			if (!validador.verificarSiNo(accion)){
				cout << "La accion ingresada no es valida, ingrese nuevamente" << endl;
			}
		}while (!validador.verificarSiNo(accion));
	}*/
	//a: Abrir, m: Marcar.
	do{
			cout << "\nIngrese accion(a/m/s),fila,columna: ";
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
		}while (((!partida->getTablero()->esPosicionValida(fila,columna))||(!validador.esAccionValida(accion))) && (accion!=SALIR));
		if (accion!=SALIR){
			jugada->modificarFila(fila);
			jugada->modificarColumna(columna);
	}
	//d: Deshacer la jugada anterior, r: Rehacer jugada, s: Dejar de deshacer o rehacer.
	/*else {
		do{
			cout << "Con tu puntaje actual podes deshacer/rehacer hasta " << puntajeJugadorEnTurno/3 << " jugadas, es posible deshacer " << cantidadDeshacer <<
				    "turnos y \n" << "rehacer hasta " << cantidadRehacer << "turnos (considerando realidades alternativas), que desea hacer (d/r/s)?" << endl;
			cin >> accion;
			if ((accion==REHACER && cantidadRehacer > 0) || (accion==DESHACER && cantidadDeshacer > 0)) {
				puntajeARestar = arbol->modificarSenialador(accion, partida);
				partida->obtenerJugadorEnTurno()->modificarPuntaje(puntajeARestar);
				puntajeJugadorEnTurno=partida->obtenerJugadorEnTurno()->getPuntaje();
				cantidadDeshacer = arbol->obtenerSenialador()->obtenerCantidadDeNodosSuperiores();
				cantidadRehacer = arbol->obtenerSenialador()->obtenerCantidadDeNodosInferiores();
				partida->imprimirTablero(partida->obtenerTurnoActual());
			}
			else if(!validador.verificarDeshacerRehacerOSalir(accion)){
				cout << "La accion ingresada no es valida, ingrese nuevamente" << endl;
			}
		}while(accion!='s' && puntajeJugadorEnTurno > 3);

	}
	*/
	jugada->modificarAccion(accion);
}

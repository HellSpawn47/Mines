#include <iostream>

#include "EstadoDeTurno.h"
#include "Jugador.h"
#include "Tablero.h"
#include "Randomizador.h"
#include "InteraccionConJugador.h"
#include "Partida.h"
#include "ArbolDeEstados.h"

using namespace std;

int main(){
	//Se definio el tipo de dato unsigned int como uint

	InteraccionConJugador* interactuar = new InteraccionConJugador();
	ArbolDeEstados* arbol = new ArbolDeEstados;
	EstadoDeTurno* estado;
	interactuar->bienvenida();
	uint filas = interactuar->pedirCantidad("filas");
	uint columnas = interactuar->pedirCantidad("columnas");
	char dificultad = interactuar->pedirDificultad();
	int puntaje = 0;
	Jugada* jugada = new Jugada;

	Partida* partida = new Partida(filas, columnas, dificultad);

	PuntajesBMP* puntajes = new PuntajesBMP;

	uint cantJugadores = interactuar->pedirCantidad("jugadores");
	partida->agregarJugadores(cantJugadores);

	partida->imprimirTablero(1);
	partida->avanzarTurno();
	//Inicio de cada jugada
	bool viajeTemporal;

	do{

		if(partida->obtenerJugadorEnTurno()->getSigueJugando()){
			cout << "\nEs el turno de: " << partida->obtenerJugadorEnTurno()->getNombre() << endl;

			if (partida->obtenerJugadorEnTurno()->getPuntaje()>=COSTE){
				viajeTemporal = interactuar->preguntarViajeTemporal();
			}else{
				viajeTemporal = false;
			}

			if (viajeTemporal){

				arbol->viajarEnElTiempo(partida,interactuar);


			}else{

				interactuar->pedirJugada(jugada,partida);

				arbol->agregar();
				estado=arbol->obtenerSenialador()->obtenerEstado();
				puntaje = partida->actualizarTablero(jugada,estado);

				partida->actualizarPuntaje(puntaje);
				partida->imprimirTablero(partida->obtenerTurnoActual());

				cout << "\npuntaje: " << partida->obtenerJugadorEnTurno()->getPuntaje() << endl;
				cout << "\n------------------------------------------------------------------" << endl;
				puntajes->imprimirPuntajes(partida->obtenerListaDeJugadores(), partida->obtenerTurnoActual());

			}
		}

		partida->avanzarTurno();


	}while( partida->continuarPartida() );

	if(partida->getTablero()->casillerosRestantesPorDescubrir() > 0){
		partida->getTablero()->descubrirTodasLasBombas();
	}

	interactuar->imprimirMensaje("Partida Terminada");

	partida->imprimirTablero(partida->obtenerTurnoActual());

	delete interactuar;
	delete jugada;
	delete partida;
	delete puntajes;
	delete arbol;

	return 0;
}

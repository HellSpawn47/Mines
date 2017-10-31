#include <iostream>
#include "Jugador.h"
#include "ListaCircular.h"
#include "Tablero.h"
#include "Randomizador.h"
#include "InteraccionConJugador.h"
#include "Partida.h"
using namespace std;

int main(){

	//Se definio el tipo de dato unsigned int como uint

	InteraccionConJugador* interactuar = new InteraccionConJugador();
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

	//Inicio de cada jugada

	do{

		partida->avanzarTurno();

		if(partida->obtenerJugadorEnTurno()->getSigueJugando()){
			cout << "\nEs el turno de: " << partida->obtenerJugadorEnTurno()->getNombre() << endl;

			interactuar->pedirJugada(jugada,partida);
			puntaje = partida->actualizarTablero(jugada);

			partida->actualizarPuntaje(puntaje);
			partida->imprimirTablero(partida->obtenerTurnoActual());

			cout << "\npuntaje: " << partida->obtenerJugadorEnTurno()->getPuntaje() << endl;
			cout << "\n------------------------------------------------------------------" << endl;
			partida->imprimirPuntajes(puntajes, partida->obtenerJugadorEnTurno()->getNombre(), partida->obtenerJugadorEnTurno()->getPuntaje(), partida->obtenerJugadorEnTurno()->getNumeroJugador());
		}


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
	return 0;
}

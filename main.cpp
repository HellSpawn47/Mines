#include <iostream>
#include "Jugador.h"
#include "ListaCircular.h"
#include "Tablero.h"
#include "Randomizador.h"
#include "InteraccionConJugador.h"
#include "Partida.h"
using namespace std;

int main(){
	InteraccionConJugador* interactuar = new InteraccionConJugador();
	//se definio el tipo de dato unsigned int como uint
	uint filas = interactuar->pedirCantidad("filas");
	uint columnas = interactuar->pedirCantidad("columnas");
	char dificultad = interactuar->pedirDificultad();
	int puntaje = 0;
	Jugada* jugada = new Jugada;

	Partida* partida = new Partida(filas, columnas, dificultad);

	uint cantJugadores = interactuar->pedirCantidad("jugadores");
	partida->agregarJugadores(cantJugadores);

	//inicio de cada jugada
	do{

		partida->avanzarTurno();
		cout << "Es el turno de: " << partida->obtenerJugadorEnTurno()->getNombre() << endl;
		interactuar->pedirJugada(jugada);
		puntaje = partida->actualizarTablero(jugada);
		partida->actualizarPuntaje(puntaje);
		partida->imprimirTablero();


		cout << "puntaje: " << partida->obtenerJugadorEnTurno()->getPuntaje() << endl;

	}while( partida->continuarPartida() );


	delete interactuar;
	delete jugada;
	return 0;
}

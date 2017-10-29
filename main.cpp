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
	uint filas = interactuar->pedirCantidad("filas");
	uint columnas = interactuar->pedirCantidad("columnas");
	char dificultad = interactuar->pedirDificultad();

	Partida* partida = new Partida(filas, columnas, dificultad);

	uint cantJugadores = interactuar->pedirCantidad("jugadores");
	partida->agregarJugadores(cantJugadores);

	do{
		Jugada* jugada = new Jugada;
		partida->avanzarTurno();
		interactuar->pedirJugada(jugada);
		partida->actualizarTablero(jugada);
		partida->imprimirTablero();
	}while(1);

	return 0;
}

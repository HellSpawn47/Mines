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

	Partida* partida = new Partida(filas, columnas, dificultad);

	uint cantJugadores = interactuar->pedirCantidad("jugadores");
	partida->agregarJugadores(cantJugadores);

	//inicio de cada jugada
	do{
		Jugada* jugada = new Jugada;
		partida->avanzarTurno();
		interactuar->pedirJugada(jugada);
		partida->actualizarTablero(jugada);
		partida->imprimirTablero();
		delete jugada;
	}while(partida->cantidadJugadoresActivos()>0);

	return 0;
}

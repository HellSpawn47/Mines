#include "Partida.h"
#include "InteraccionConJugador.h"

Partida::Partida(){
	uint filas = 0, columnas = 0;
	/*Pedir dificultad, cantidad de jugadores, filas y columnas*/
	InteraccionConJugador interactuar;

	filas = interactuar.pedirCantidadFilas();
	columnas = interactuar.pedirCantidadColumnas();
	char nivelDificultad = interactuar.pedirDificultad();

	tablero = new Tablero(filas, columnas);
	dificultad = new Dificultad(nivelDificultad);
	listaDeJugadores = new Lista<Jugador*>;


}

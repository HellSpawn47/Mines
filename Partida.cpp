#include "Partida.h"

Partida::Partida(){

	/*Pedir dificultad, cantidad de jugadores, filas y columnas*/
	tablero = new Tablero(filas, columnas);
	dificultad = new Dificultad(dificultad);
	listaDeJugadores = new Lista<Jugador*>;

}

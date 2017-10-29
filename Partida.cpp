#include "Partida.h"
#include "InteraccionConJugador.h"

Partida::Partida(uint cantidadFilas, uint cantidadColumnas, char nivelDificultad){

	tablero = new Tablero(cantidadFilas, cantidadColumnas);
	dificultad = new Dificultad(cantidadFilas, cantidadColumnas, nivelDificultad);
	listaDeJugadores = new Lista<Jugador*>;
	listaDeJugadores->iniciarCursor();
	jugadorEnTurno = NULL;

	tablero->inicializar(dificultad->obtenerCantidadDeBombas());

}

void Partida::agregarJugador(std::string nombre){

	Jugador* nuevoJugador = new Jugador(nombre);
	listaDeJugadores->agregar(nuevoJugador);

}

void Partida::avanzarTurno(){

	listaDeJugadores->avanzarCursor();
	jugadorEnTurno = listaDeJugadores->obtenerCursor();

}

Partida::~Partida() {
/*	delete Tablero;
	delete dificultad;
	delete listaDeJugadores;
*/
}

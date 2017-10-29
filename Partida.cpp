#include "Partida.h"
#include "InteraccionConJugador.h"
#include "constantes.h"

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

void Partida::agregarJugadores(uint cantJugadores){
	InteraccionConJugador interactuar;
	for (uint i = 0; i < cantJugadores; i++){

		std::string nombre = interactuar.pedirNombreJugador(i);
		this->agregarJugador(nombre);

	}

}

void Partida::avanzarTurno(){

	listaDeJugadores->avanzarCursor();
	jugadorEnTurno = listaDeJugadores->obtenerCursor();

}

Jugador* Partida::obtenerJugadorEnTurno(){

	return this->jugadorEnTurno;

}

void Partida::actualizarTablero(Jugada* jugada){

	if(jugada->obtenerAccion() == DESCUBRIR){
		tablero->descubrirCasillero(jugada->obtenerFila(), jugada->obtenerColumna());
	}

}

void Partida::imprimirTablero(){

	tablero->imprimir();

}

Partida::~Partida() {
	delete tablero;
	delete dificultad;
	delete listaDeJugadores;
}

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

int Partida::actualizarTablero(Jugada* jugada){
	int puntaje = 0;
	if(jugada->obtenerAccion() == DESCUBRIR){
		tablero->descubrirCasillero(jugada->obtenerFila(), jugada->obtenerColumna());

		if(tablero->obtenerValorCasillero(jugada->obtenerFila(), jugada->obtenerColumna()) == BOMBA){
			jugadorEnTurno->dejarFueraDeJuego();
		}
	}
	else if(jugada->obtenerAccion() == MARCAR){
		bool estabaMarcado = (tablero->obtenerEstadoCasillero(jugada->obtenerFila(),jugada->obtenerColumna()) == MARCADO);
		tablero->marcarCasillero(jugada->obtenerFila(), jugada->obtenerColumna());

		if (tablero->obtenerValorCasillero(jugada->obtenerFila(),jugada->obtenerColumna()) == BOMBA){
			if (estabaMarcado) {
				puntaje = -2;
			}
			else {
				puntaje = 1;
			}
		}
		else{
			if (estabaMarcado){
				puntaje = 2;
			}
			else{
				puntaje = -1;
			}
		}
	}
	return puntaje;
}

void Partida::actualizarPuntaje(int puntaje){

	this->jugadorEnTurno->modificarPuntaje(puntaje);

}

void Partida::imprimirTablero(){

	tablero->imprimir();

}

uint Partida::cantidadJugadoresActivos() {
	Jugador* jugadorActual;
	uint jugadoresActivos = 0;
	for (uint i=0; i<listaDeJugadores->contarElementos();i++){
		jugadorActual = listaDeJugadores->obtener(i);
		if (jugadorActual->getSigueJugando()){
			jugadoresActivos++;
		}
	}
	return jugadoresActivos;
}

bool Partida::continuarPartida(){
	return ((this->tablero->casillerosRestantesPorDescubrir() > 0)&&(this->cantidadJugadoresActivos() > 0));
}

Partida::~Partida() {
	delete tablero;
	delete dificultad;
	delete listaDeJugadores;
}

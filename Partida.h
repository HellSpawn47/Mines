#ifndef	PARTIDA_H
#define	PARTIDA_H

#include "Dificultad.h"
#include "Tablero.h"
#include "ListaCircular.h"
#include "Jugador.h"

class Partida{

	private:

		Tablero* tablero;

		Dificultad* dificultad;

		Lista<Jugador*>* listaDeJugadores;

		Jugador* jugadorEnTurno;


	public:

		Partida(uint cantidadFilas, uint cantidadColumnas, char nivelDificultad);

		void agregarJugador(std::string nombre);

		void avanzarTurno();

		~Partida();

};

#endif

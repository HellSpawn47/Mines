#ifndef INTERACCION_H
#define INTERACCION_H

#include "typedefs.h"
#include "Jugador.h"

class InteraccionConJugador{

	public:

		uint pedirCantidadFilas();

		uint pedirCantidadColumnas();

		uint pedirCantidadBombas();

		char pedirDificultad();

		uint pedirCantidadJugadores();

		Jugador* pedirNombreJugador();

		char pedirJugada();
};

#endif

#ifndef INTERACCION_H
#define INTERACCION_H

#include "typedefs.h"
#include "Jugador.h"
#include "Jugada.h"


class InteraccionConJugador{

	public:

		uint pedirCantidad(std::string unaCosa);

		char pedirDificultad();

		std::string pedirNombreJugador(uint numero);

		void pedirJugada(Jugada* jugada);
};

#endif

#ifndef INTERACCION_H
#define INTERACCION_H

#include "typedefs.h"
#include "Jugador.h"


class InteraccionConJugador{

	public:

		uint InteraccionConJugador::pedirCantidad(std::string unaCosa);

		char pedirDificultad();

		std::string pedirNombreJugador(uint numero);

		std::string pedirJugada();
};

#endif

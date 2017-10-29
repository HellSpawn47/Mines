#ifndef INTERACCION_H
#define INTERACCION_H

#include "typedefs.h"
#include "Jugador.h"
#include "Jugada.h"

class InteraccionConJugador{


	/*
	 * La interaccion con el jugador es
	 */
	public:

		/*
		 * Pre: Recibe el tipo de cosa que de la que se quiere pedir el valor.
		 * Post: Devuelve la cantidad ingresada por el usuario de "unaCosa".
		 */
		uint pedirCantidad(std::string unaCosa);

		/*
		 * Post: Devuelve FACIL, MEDIA o DIFICIL segun lo que ingrese el usuario.
		 */
		char pedirDificultad();

		/*
		 * Pre: Recibe el numero que representa a uno de los jugadores que van participar en la partida.
		 * Post: Devuelve el nombre que el usuario le asigno al jugador recibido.
		 */
		std::string pedirNombreJugador(uint numero);

		/*
		 * Pre: Recibe
		 * Post: Devuelve
		 */
		void pedirJugada(Jugada* jugada);

		void bienvenida();

		void imprimirMensaje(std::string frase);
};

#endif

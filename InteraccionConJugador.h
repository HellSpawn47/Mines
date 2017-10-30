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
		 * Pre : Recibe el tipo de cosa que de la que se quiere pedir el valor.
		 * Post: Devuelve la cantidad ingresada por el usuario de "unaCosa".
		 */
		uint pedirCantidad(std::string unaCosa);

		/*
		 * Post: Devuelve FACIL, MEDIA o DIFICIL segun lo que ingrese el usuario.
		 */
		char pedirDificultad();

		/*
		 * Pre : Recibe el numero que representa a uno de los jugadores que van participar en la partida.
		 * Post: Devuelve el nombre que el usuario le asigno al jugador recibido.
		 */
		std::string pedirNombreJugador(uint numero);

		/*
		 * Post: Le asigna a la jugada recibida los valores de accion, fila y columna que ingrese el jugador por teclado.
		 */
		void pedirJugada(Jugada* jugada);

		/*
		 * Post: Muestra los mensajes de bienvenida por pantalla.
		 */
		void bienvenida();

		/*
		 * Post: Muestra por pantalla el banner del buscaminas.
		 */
		void imprimirBanner();

		/*
		 * Post: Imprime por pantalla una frase en una linea.
		 */
		void imprimirMensaje(std::string frase);
};

#endif

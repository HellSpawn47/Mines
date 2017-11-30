#ifndef ESTADO_DE_PARTIDA_H
#define ESTADO_DE_PARTIDA_H

#include "Posicion.h"
#include "Jugador.h"
#include "typedefs.h"

	/*
	 * Representa los cambios realizados durante un turno de la partida.
	 */

class EstadoDeTurno{

	private:

		Posicion* posicionesDescubiertas;

		Jugador* jugadorEliminado;

		uint tope;

	public:

		/*
		 *
		 * Post: Inicializa atributos en NULL
		 *
		 *
		 */
		EstadoDeTurno();

		/*
		 * Pre:  Recibe fila, columna y la modificacion que se realizo en esa posicion.
		 * Post: Guarda la posicion recibida en ese turno.
		 *
		 *
		 */
		void agregarPosicionInteractuada(uint fila, uint columna,char estadoDeLaPosicion);

		/*
		 * Pre:  Recibe un jugador que fue eliminado.
		 * Post: Se guarda el jugador eliminado en ese turno.
		 *
		 *
		 */
		void agregarJugadorEliminado(Jugador* jugador);

		/*
		 *
		 * Post: Devuelve el jugador eliminado en ese turno. (Si no se elimino ningun jugador devuelve NULL)
		 *
		 *
		 */
		Jugador* obtenerJugadorEliminado();

		/*
		 *
		 * Post: Devuelve las posiciones modificadas en ese turno.
		 *
		 *
		 */
		Posicion* obtenerPosicionesDescubiertas();

		/*
		 *
		 * Post: Devuelve la cantidad de posiciones modificadas en ese turno.
		 *
		 *
		 */
		uint obtenerTope();

		~EstadoDeTurno();
};


#endif

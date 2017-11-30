#ifndef ESTADO_DE_PARTIDA_H
#define ESTADO_DE_PARTIDA_H

#include "Posicion.h"
#include "Jugador.h"
#include "typedefs.h"

class EstadoDePartida{

	/*
	 * Representa los cambios realizados durante un turno de la partida.
	 */

	private:

		Posicion* posicionesDescubiertas;

		Jugador* jugadorEliminado;

		uint tope;

	public:

		EstadoDePartida();

		void agregarPosicionInteractuada(uint fila, uint columna,char estadoDeLaPosicion);

		void agregarJugadorEliminado(Jugador* jugador);

		Jugador* obtenerJugadorEliminado();

		Posicion* obtenerPosicionesDescubiertas();

		uint obtenerTope();

		~EstadoDePartida();
};


#endif

#ifndef ESTADO_DE_PARTIDA_H
#define ESTADO_DE_PARTIDA_H

#include "Posicion.h"
#include "typedefs.h"

class EstadoDePartida{

	private:

		Posicion* posicionesDescubiertas;

		uint tope;

	public:

		EstadoDePartida();

		void agregarPosicionDescubierta(uint fila, uint columna);

		Posicion* obtenerPosicionesDescubiertas();

		~EstadoDePartida();
};


#endif

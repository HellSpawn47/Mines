#ifndef	PARTIDA_H
#define	PARTIDA_H

#include "Dificultad.h"
#include "Tablero.h"
#include "Lista.h"
#include "Jugador.h"

class Partida{

	private:

		Tablero* tablero;

		Dificultad* dificultad;

		Lista<Jugador*>* listaDeJugadores;

	public:

		Partida();

};

#endif

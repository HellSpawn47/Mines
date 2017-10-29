#ifndef	PARTIDA_H
#define	PARTIDA_H

#include "Dificultad.h"
#include "Tablero.h"
#include "ListaCircular.h"
#include "Jugador.h"
#include "Jugada.h"

class Partida{

	private:

		Tablero* tablero;

		Dificultad* dificultad;

		Lista<Jugador*>* listaDeJugadores;

		Jugador* jugadorEnTurno;


	public:

		Partida(uint cantidadFilas, uint cantidadColumnas, char nivelDificultad);

		void agregarJugador(std::string nombre);

		void agregarJugadores(uint cantJugadores);

		void avanzarTurno();

		Jugador* obtenerJugadorEnTurno();

		void actualizarTablero(Jugada* jugada);

		void imprimirTablero();

		~Partida();

};

#endif

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

		//pre: cantidad de filas del tablero, cantidad de columnas y nivel de dificultad deseado (FACIL, MEDIO, DIFICIL)
		//post: inicia una partida.
		Partida(uint cantidadFilas, uint cantidadColumnas, char nivelDificultad);

		//pre: un nombre
		//post: agrega el jugador con el nombre indicado
		void agregarJugador(std::string nombre);

		//pre: numero mayor a cero.
		//post: agrega la cantidad de jugadores indicada pidiendo que se ingrese un nombre para cada uno
		void agregarJugadores(uint cantJugadores);

		//post: pasa al siguiente jugador.
		void avanzarTurno();

		//post: devuelve el jugador del turno actual.
		Jugador* obtenerJugadorEnTurno();

		//pre: recibe un puntero a jugada
		//post: realiza la jugada en el tablero
		int actualizarTablero(Jugada* jugada);

		void actualizarPuntaje(int puntaje);

		//post: imprime por pantalla el tablero en su estado actual.
		void imprimirTablero();

		//post: devuelve la cantidad de jugadores que todavia no perdieron.
		uint cantidadJugadoresActivos ();

		//post: devuelve si la partida puede continuar
		bool continuarPartida();

		~Partida();

};

#endif

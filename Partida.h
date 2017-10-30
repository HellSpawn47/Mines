#ifndef	PARTIDA_H
#define	PARTIDA_H

#include <iostream>
#include "Dificultad.h"
#include "Tablero.h"
#include "ListaCircular.h"
#include "Jugador.h"
#include "Jugada.h"

class Partida{

	/*
	 * Una partida es
	 */
	private:

		Tablero* tablero;

		Dificultad* dificultad;

		Lista<Jugador*>* listaDeJugadores;

		Jugador* jugadorEnTurno;

	public:

		/* Pre : Recibe cantidad de filas y columnas del tablero que ingreso el jugador por teclado, asi como tambien el nivel
		 * 		 de dificultad deseado (FACIL, MEDIO, DIFICIL)
		 * Post: Prepara un tablero de filas por columnas, con una cantidad de bombas que depende de la dificultad recibida y se genera
		 * 		 una lista de jugadores que van a participar en la partida. Tambien se asigna NULL al "jugadorEnTurno".
		 */
		Partida(uint cantidadFilas, uint cantidadColumnas, char nivelDificultad);

		/*
		 * Pre : Recibe el nombre de un jugador para agregarlo a la lista de jugadores.
		 * Post: Agrega el jugador con el nombre indicado a la lista de jugadores.
		 */
		void agregarJugador(std::string nombre);

		/*
		 * Pre : Recibe la cantidad de jugadores que van a participar de la partida.
		 * Post: Agrega la cantidad de jugadores a la lista de jugadores pidiendo que se ingrese un nombre para cada uno.
		 */
		void agregarJugadores(uint cantJugadores);

		/*
		 * Post: Pasa el turno al siguiente jugador.
		 */
		void avanzarTurno();

		/*
		 * Post: Devuelve el jugador del turno actual.
		 */
		Jugador* obtenerJugadorEnTurno();

		/*
		 * Pre : Recibe un puntero a la jugada que quiere realizar el jugador.
		 * Post: Realiza la jugada en el tablero.
		 */
		int actualizarTablero(Jugada* jugada);

		/*
		 * Post: Al jugador que este en turno se le agregan o restan los puntos que correspondan segun los puntos recibidos.
		 */
		void actualizarPuntaje(int puntaje);

		/*
		 * Post: Imprime por pantalla el tablero en su estado actual.
		 */
		void imprimirTablero();

		/*
		 * Post: Devuelve la cantidad de jugadores que todavia no perdieron.
		 */
		uint cantidadJugadoresActivos ();

		/*
		 * Post: Devuelve verdadero si la partida puede continuar y falso si es no es el caso.
		 */
		bool continuarPartida();

		/*
		 * Post: Devuelve un puntero al tablero.
		 */
		Tablero* getTablero();

		/*
		 * Post: Libera los recursos pedidos por el tablero, la lista de jugadores y la dificultad.
		 */
		~Partida();

};

#endif

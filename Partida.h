#ifndef	PARTIDA_H
#define	PARTIDA_H

#include <iostream>
#include "Dificultad.h"
#include "Tablero.h"
#include "ListaCircular.h"
#include "Jugador.h"
#include "Jugada.h"
#include "PuntajesBMP.h"
#include "Posicion.h"
#include "EstadoDePartida.h"

class Partida{

	/*
	 * Una partida es el conjunto de jugadas que se van a realizar en un juego para que uno de los jugadores gane o pierda definitivamente.
	 *
	 * La partida posee un tablero, que sera modificado a lo largo de la misma y como se genere dependera de la dificultad que los usuarios
	 * quieran que tenga la partida. La partida tambien tiene una lista de los jugadores que van a participar en el juego y puede controlar
	 * de quien es el turno.
	 */
	private:

		Tablero* tablero;

		Dificultad* dificultad;

		Lista<Jugador*>* listaDeJugadores;

		Jugador* jugadorEnTurno;

		uint turno;

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
		void agregarJugador(std::string nombre, uint numeroJugador);

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
		 * Post: devuelve el puntaje que le corresponde a la jugada.
		 */
		int calcularPuntajeDeJugada(Jugada* jugada);

		/*
		 * Pre:
		 * Post:
		 */
		void eliminarJugador();

		/*
		 * Pre : Recibe un puntero a la jugada que quiere realizar el jugador y al estado de la partida.
		 * Post: Realiza la jugada en el tablero y modifica el estado de la partida segun los cambios hechos en el turno.
		 */
		int actualizarTablero(Jugada* jugada,EstadoDePartida* estado);

		/*
		 * Pre:
		 * Post:
		 */
		int actualizarTableroDeshaciendoJugada(EstadoDePartida* estado);

		/*
		 * Pre:
		 * Post:
		 */
		int actualizarTableroRehaciendoJugada(EstadoDePartida* estado);

		/*
		 * Post: Al jugador que este en turno se le agregan o restan los puntos que correspondan segun los puntos recibidos.
		 */
		void actualizarPuntaje(int puntaje);

		/*
		 * Post: Imprime por pantalla el tablero en su estado actual.
		 */
		void imprimirTablero(uint turno);

		/*
		 * Post: Devuelve la cantidad de jugadores que todavia no perdieron.
		 */
		uint cantidadJugadoresActivos ();

		/*
		 * Post: Devuelve verdadero si la partida puede continuar y falso si es no es el caso.
		 */
		bool continuarPartida();

		/*
		 * Post: Devuelve el turno actual.
		 */

		int obtenerTurnoActual();

		/*
		 * Pre:
		 * Post:
		 */
		int volverAlFuturo(EstadoDePartida* estado,char accion);

		/*
		 * Post: Devuelve la lista de jugadores.
		 */
		Lista<Jugador*>* obtenerListaDeJugadores();

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

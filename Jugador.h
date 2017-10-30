#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include "typedefs.h"
class Jugador {

	/*
	 * Un jugador es un participante del juego. Posee un nombre, un puntaje (que inicialmente es CERO), y un atributo que indica
	 * si esta habilitado para continuar jugando.
	 */
	private:

		std::string nombre;

		int puntaje;

		bool sigueJugando;

	public:

		/*
		 * Pre : Recibe el nombre que se le quiera asignar al jugador.
		 * Post: Le asigna al jugador el nombre, se inicializa su puntaje en 0 y sigueJugando en true.
		 */
		Jugador(std::string nombre);

		/*
		 * Post: Devuelve el nombre del jugador.
		 */
		std::string getNombre();

		/*
		 * Post: Devuelve el puntaje del jugador.
		 */
		int getPuntaje();

		/*
		 * Pre : Recibe los puntos que se le deben agregar o restar al puntaje del jugador.
		 * Post: Se le restan o suman los puntos correspondientes al jugador.
		 */
		void modificarPuntaje(short int puntos);

		/*
		 * Post: Devuelve verdadero o falso segun si el usuario esta habilitado para continuar jugando.
		 */
		bool getSigueJugando();

		/*
		 * Post: Inhabilita al usuario para que continue participando en la partida.
		 */
		void dejarFueraDeJuego();
};

#endif

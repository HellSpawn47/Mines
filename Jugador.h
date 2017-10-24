#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>

class Jugador {

	private:

		std::string nombre;

		unsigned int puntaje;

		bool sigueJugando;

	public:

		/* pre: nombre es una cadena de caracteres valida.
		 *
		 * post: construye un jugador asignandole el 'nombre', inicializando su 'puntaje' en 0 y 'sigueJugando' en true.
		 */
		Jugador(std::string nombre);

		std::string getNombre();

		unsigned int getPuntaje();

		void modificarPuntaje(short int puntos);

		bool getSigueJugando();

		void dejarFueraDeJuego();
};

#endif

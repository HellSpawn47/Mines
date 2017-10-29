#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include "typedefs.h"
class Jugador {

	private:

		std::string nombre;

		int puntaje;

		bool sigueJugando;

	public:

		/* pre: nombre es una cadena de caracteres valida.
		 *
		 * post: construye un jugador asignandole el 'nombre', inicializando su 'puntaje' en 0 y 'sigueJugando' en true.
		 */
		Jugador(std::string nombre);

		std::string getNombre();

		int getPuntaje();

		void modificarPuntaje(short int puntos);

		bool getSigueJugando();

		void dejarFueraDeJuego();
};

#endif

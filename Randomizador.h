#ifndef RANDOM_H
#define RANDOM_H
#include <cstdlib>
#include <ctime>
#include "typedefs.h"

class Randomizador {

	/*
	 * El randomizador es un generador de numeros enteros aleatorios al que se le puede pedir que genere un numero entre cierto rango.
	 *
	 * El generador genera numeros a partir de una semilla, que podra ser cambiada en funcion de la hora que tenga la computadora para que
	 * sea aun mas aleatorio.
	 */
	public:
		/*
		 * Pre : La semilla debe estar inicializada.
		 * Post: Calcula un numero entero pseudo-aleatorio entre el rango [minimo..maximo].
		 */
		uint obtenerNumeroAleatorioEntreRango(uint minimo, uint maximo);

		/*
		 * Post: Prepara la semilla para obtenerNumeroAleatorioEntreRango() a partir de la hora.
		 */
		void setearSemillaRandom();

};

#endif

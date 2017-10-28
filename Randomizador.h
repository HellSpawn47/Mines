#ifndef RANDOM_H
#define RANDOM_H
#include <cstdlib>
#include <ctime>

class Randomizador {

	public:
		/*
		 * pre: La semilla debe estar inicializada.
		 * post: Calcula un numero entero pseudo-aleatorio entre el rango (minimo, maximo).
		 *
		 */
		int obtenerNumeroAleatorioEntreRango(int minimo, int maximo);

		/*
		 * pre:
		 * post: Prepara la semilla para obtenerNumeroAleatorioEntreRango() a partir de la hora.
		 *
		 */
		void setearSemillaRandom();

};

#endif

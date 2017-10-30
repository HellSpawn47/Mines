#ifndef RANDOM_H
#define RANDOM_H
#include <cstdlib>
#include <ctime>
#include "typedefs.h"

class Randomizador {

	/*
	 * El randomizador se utiliza para
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

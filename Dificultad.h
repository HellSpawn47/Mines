#ifndef DIFICULTAD_H
#define DIFICULTAD_H

#include "typedefs.h"

	/*
	 * Definir Dificultad
	 *
	 */
class Dificultad{

	private:

		uint cantidadDeBombas;

	public:

		/*
		 * Pre : Recibe el caracter que representa la dificultad que ingreso el usuario, asi como tambien el numero de fila y de columnas
		 * Post: Le asigna un valor a cantidadDeBombas que resulta de hacer la multiplicacion de la cantidad de filas por columnas por
		 * 		 un coeficiente que depende de la dificultad recibida. Este coeficiente sera 0.15 si la dificultad es FACIL, 0.20 si la
		 * 		 dificultad es MEDIA y 0.25 si la dificultad es DIFICIL.
		 */
		Dificultad(uint filas, uint columnas, char dificultad);

		/*
		 * Post: Devuelve la cantidad de bombas que hay en la partida.
		 */
		uint obtenerCantidadDeBombas();

};

#endif

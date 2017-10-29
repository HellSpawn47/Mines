#ifndef JUGADA_H
#define JUGADA_H

#include "typedefs.h"

class Jugada{

	/*
	 * Una jugada es
	 */
	private:

		uint fila;
		uint columna;
		char accion;

	public:

		/*
		 *
		 */
		void modificarFila(uint nuevaFila);

		/*
		 *
		 */
		void modificarColumna(uint nuevaColumna);

		/*
		 *
		 */
		void modificarAccion(char nuevaAccion);

		/*
		 * Post: Devuelve la fila.
		 */
		uint obtenerFila();

		/*
		 * Post: Devuelve la columna.
		 */
		uint obtenerColumna();

		/*
		 * Post: Devuelve el caracter de accion (DESCUBRIR, MARCAR o SALIR).
		 */
		char obtenerAccion();

};

#endif

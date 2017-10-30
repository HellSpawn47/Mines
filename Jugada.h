#ifndef JUGADA_H
#define JUGADA_H

#include "typedefs.h"

class Jugada{

	/*
	 * Una jugada es una acción o intervención de un participante en un juego, en este caso la intervencion del jugador va a ser
	 * elegir una accion a realizar en el tablero del juego, en que fila y en que columna.
	 */
	private:

		uint fila;
		uint columna;
		char accion;

	public:

		/*
		 * Pre : Recibe la fila que el usuario haya ingresado para realizar una accion.
		 * Post: Se actualiza la fila por la fila recibida.
		 */
		void modificarFila(uint nuevaFila);

		/*
		 * Pre : Recibe la columna que el usuario haya ingresado para realizar una accion.
		 * Post: Se actualiza la columna por columna recibida.
		 */
		void modificarColumna(uint nuevaColumna);

		/*
		 * Pre : Recibe el caracter de accion que el usuario haya ingresado (DESCUBRIR, MARCAR o SALIR).
		 * Post: Se actualiza la accion por el caracter de accion recibido.
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

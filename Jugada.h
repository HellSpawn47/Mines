#ifndef JUGADA_H
#define JUGADA_H

#include "typedefs.h"

class Jugada{

	private:

		uint fila;
		uint columna;
		char accion;

	public:

		void modificarFila(uint nuevaFila);
		void modificarColumna(uint nuevaColumna);
		void modificarAccion(char nuevaAccion);

		uint obtenerFila();
		uint obtenerColumna();
		char obtenerAccion();

};

#endif

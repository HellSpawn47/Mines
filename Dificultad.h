#ifndef DIFICULTAD_H
#define DIFICULTAD_H

#include "typedefs.h"

class Dificultad{

	private:

		uint cantidadDeBombas;

	public:

		Dificultad(uint filas, uint columnas, char dificultad);

		uint obtenerCantidadDeBombas();

};

#endif

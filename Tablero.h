#ifndef TABLERO_H
#define TABLERO_H

#include "Casillero.h"
#include "typedefs.h"

class Tablero{

	private:

		Casillero ** tablero;
		uint filas;
		uint columnas;

	public:

		Tablero(uint filas,uint columnas);

		void inicializar(uint cantidadDeBombas);

		uint obtenerValorCasillero(uint fila,uint columna);

		uint obtenerEstadoCasillero(uint fila, uint columna);

		void cambiarEstadoCasillero(uint fila, uint columna);

		void marcarCasillero(uint fila, uint columna);

		void descubirCasillero(uint fila, uint columna);

		void imprimir();

	private:

		void ponerBombasAleatoriamente();

		void rellenarConNumeros();

};

#endif

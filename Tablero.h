#ifndef TABLERO_H
#define TABLERO_H

/*Holi*/

#include "Casillero.h"

class Tablero{

	private:

		Casillero ** tablero;

	public:

		Tablero(int filas, int columnas);

		int obtenerValorCasillero(int fila, int columna);

		int obtenerEstadoCasillero(int fila, int columna);

		void cambiarEstadoCasillero(int fila, int columna);

		void marcarCasillero(int fila, int columna);

		void descubirCasillero(int fila, int columna);

		void imprimir();

	private:

		void ponerBombasAleatoriamente();

		void rellenarConNumeros();

		void
};

#endif

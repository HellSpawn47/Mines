#ifndef TABLERO_H
#define TABLERO_H

#include "Casillero.h"
#include "typedefs.h"

class Tablero{

	private:

		Casillero ** tablero;
		uint cantidadFilas;
		uint cantidadColumnas;

	public:

		Tablero(uint filas,uint columnas);

		void inicializar(uint cantidadDeBombas);

		uint obtenerValorCasillero(uint fila,uint columna);

		uint obtenerEstadoCasillero(uint fila, uint columna);

		void cambiarEstadoCasillero(uint fila, uint columna, uint nuevoEstado);

		void marcarCasillero(uint fila, uint columna);

		void descubirCasillero(uint fila, uint columna);

		uint obtenerCantidadFilas();

		uint obtenerCantidadColumnas();

		void imprimir();

		~Tablero();

	private:

		void ponerBombasAleatoriamente();

		void rellenarConNumeros();

		void rellenarSubMatrizAledaniaBomba(int fila,int columna);

		bool esPosicionValida(uint fila, uint columna);

};

#endif

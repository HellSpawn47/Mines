#ifndef TABLERO_H
#define TABLERO_H

#include "Casillero.h"
#include "typedefs.h"

class Tablero{

	private:

		Casillero ** tablero;
		uint cantidadFilas;
		uint cantidadColumnas;
		uint casillerosPorDescubrir;

	public:

		Tablero(uint filas,uint columnas);

		void inicializar(uint cantidadDeBombas);

		uint obtenerValorCasillero(uint fila,uint columna);

		uint obtenerEstadoCasillero(uint fila, uint columna);

		Casillero* obtenerCasillero(uint fila, uint columna);

		void cambiarEstadoCasillero(uint fila, uint columna, uint nuevoEstado);

		void marcarCasillero(uint fila, uint columna);

		void descubrirCasillero(uint fila, uint columna);

		uint obtenerCantidadFilas();

		uint obtenerCantidadColumnas();

		void descubrirTodasLasBombas();

		void imprimir();

		uint casillerosRestantesPorDescubrir();

		~Tablero();

	private:

		void ponerBombasAleatoriamente(uint cantidadBombas);

		void rellenarConNumeros();

		void rellenarSubMatrizAledaniaBomba(int fila,int columna);

		int descubrirCasillerosAledaniosVacio(int fila,int columna);

		bool esPosicionValida(uint fila, uint columna);



};

#endif

#ifndef TABLERO_H
#define TABLERO_H

#include "Casillero.h"
#include "typedefs.h"

class Tablero{

	/*
	 * Un tablero es
	 */
	private:

		Casillero ** tablero;
		uint cantidadFilas;
		uint cantidadColumnas;
		uint casillerosPorDescubrir;

	public:

		/*
		 * Pre :
		 * Post:
		 */
		Tablero(uint filas,uint columnas);

		/*
		 * Pre :
		 * Post:
		 */
		void inicializar(uint cantidadDeBombas);

		/*
		 * Pre :
		 * Post:
		 */
		uint obtenerValorCasillero(uint fila,uint columna);

		/*
		 * Pre :
		 * Post:
		 */
		uint obtenerEstadoCasillero(uint fila, uint columna);


		Casillero* obtenerCasillero(uint fila, uint columna);


		/*
		 * Pre :
		 * Post:
		 */

		void cambiarEstadoCasillero(uint fila, uint columna, uint nuevoEstado);

		/*
		 * Pre :
		 * Post:
		 */
		void marcarCasillero(uint fila, uint columna);

		/*
		 * Pre :
		 * Post:
		 */
		void descubrirCasillero(uint fila, uint columna);

		/*
		 * Pre :
		 * Post:
		 */
		uint obtenerCantidadFilas();

		/*
		 * Pre :
		 * Post:
		 */
		uint obtenerCantidadColumnas();

		/*
		 * Pre :
		 * Post:
		 */
		void descubrirTodasLasBombas();

		/*
		 * Pre :
		 * Post:
		 */
		void imprimir();

		/*
		 * Pre :
		 * Post:
		 */
		uint casillerosRestantesPorDescubrir();

		/*
		 * Pre :
		 * Post:
		 */
		~Tablero();

	private:

		/*
		 * Pre :
		 * Post:
		 */
		void ponerBombasAleatoriamente(uint cantidadBombas);

		/*
		 * Pre :
		 * Post:
		 */
		void rellenarConNumeros();

		/*
		 * Pre :
		 * Post:
		 */
		void rellenarSubMatrizAledaniaBomba(int fila,int columna);

		/*
		 * Pre :
		 * Post:
		 */
		int descubrirCasillerosAledaniosVacio(int fila,int columna);

		/*
		 * Pre :
		 * Post:
		 */
		bool esPosicionValida(uint fila, uint columna);



};

#endif

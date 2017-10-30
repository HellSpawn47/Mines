#ifndef TABLERO_H
#define TABLERO_H

#include "Casillero.h"
#include "typedefs.h"

class Tablero{

	/*
	 * Un tablero es un conjunto de n*m casilleros en el que se desarrollara la partida.
	 *
	 * Posee una cantidad n de filas y m de columnas que seran definidos por el usuario al comienzo de la partida, asi como un contador
	 * de los casilleros restantes por descubrir para que finalice la partida.
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

		/*
		 * Pre :
		 * Post:
		 */
		bool esPosicionValida(uint fila, uint columna);

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




};

#endif

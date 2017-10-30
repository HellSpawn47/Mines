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
		 * Pre : Recibe la cantidad de filas y columnas de casilleros que el usuario quiera que tenga el tablero.
		 * Post: Crea un tablero con la cantidad de casilleros recibida y como todavia no hay minas en el tablero la cantidad de
		 * 		 casilleros por descubrir es filas*columnas.
		 */
		Tablero(uint filas,uint columnas);

		/*
		 * Pre : Recibe la cantidad de bombas que tendra el tablero esta partida.
		 * Post: Ubica las bombas en el tablero y le asigna a los casilleros aledaños a las bombas los numeros correspondientes que
		 *  	 indiquen la cantidad de bombas que tienen alrededor.
		 */
		void inicializar(uint cantidadDeBombas);

		/*
		 * Pre : Recibe la posicion de fila y columna en la que se encuentre algun casillero del tablero.
		 * Post: Devuelve el valor de ese casillero.
		 */
		uint obtenerValorCasillero(uint fila,uint columna);

		/*
		 * Pre : Recibe la posicion de fila y columna en la que se encuentre algun casillero del tablero.
		 * Post: Devuelve el estado de ese casillero.
		 */
		uint obtenerEstadoCasillero(uint fila, uint columna);

		/*
		 * Pre : Recibe la posicion de fila y columna en la que se encuentre algun casillero del tablero.
		 * Post: Devuelve un puntero a ese casillero.
		 */
		Casillero* obtenerCasillero(uint fila, uint columna);


		/*
		 * Pre : Recibe la posicion de fila y columna en la que se encuentre algun casillero del tablero y el estado que se
		 * 		 le quiera asignar a ese casillero.
		 * Post: El estado del casillero cambia por el estado recibido, si el casillero se descubrio se resta 1 al contador de casilleros
		 * 		 por descubrir.
		 */

		void cambiarEstadoCasillero(uint fila, uint columna, uint nuevoEstado);

		/*
		 * Pre : Recibe la posicion de fila y columna en la que se encuentre algun casillero del tablero que no este descubierto aun.
		 * Post: Si el casillero estaba marcado con una bandera se desmarca, y si no estaba marcado se marca con una bandera.
		 */
		void marcarCasillero(uint fila, uint columna);

		/*
		 * Pre : Recibe la posicion de fila y columna en la que se encuentre algun casillero del tablero.
		 * Post: Se descubre esa posicion y si es un casillero que no tenga bombas en ninguno de los casilleros vecinos (ni tampoco en
		 * 		 esa posicion) estos se descubren automaticamente.
		 */
		void descubrirCasillero(uint fila, uint columna);

		/*
		 * Post: Devuelve la cantidad de filas del tablero.
		 */
		uint obtenerCantidadFilas();

		/*
		 * Post: Devuelve la cantidad de columnas de tablero.
		 */
		uint obtenerCantidadColumnas();

		/*
		 * Post: Todos los casilleros con bombas cambian su estado a DESCUBIERTO.
		 */
		void descubrirTodasLasBombas();

		/*
		 * Post: Crea un archivo bmp que muestra el estado del tablero, los jugadores y su puntaje.
		 */
		void imprimir(uint turno);

		/*
		 * Post: Devuelve la cantidad de casilleros que faltan descubrir para que termine la partida.
		 */
		uint casillerosRestantesPorDescubrir();

		/*
		 * Post: Libera los recursos pedidos por cada casillero del tablero.
		 */
		~Tablero();

		/*
		 * Pre : Recibe dos numeros enteros.
		 * Post: Devuelve si es una posicion valida en el tablero y si no es una jugada que ya se hizo.
		 */
		bool esPosicionValida(uint fila, uint columna);

	private:

		/*
		 * Pre : Recibe la cantidad de bombas que se van a asignar al tablero.
		 * Post: Ubica las bombas en casilleros aleatorios del tablero.
		 */
		void ponerBombasAleatoriamente(uint cantidadBombas);

		/*
		 * Post: A los casilleros que tengan bombas aledanias (y no tengan bombas) les asigna la cantidad de bombas que tienen alrededor.
		 */
		void rellenarConNumeros();

		/*
		 * Pre : Recibe la posicion de fila y columna en la que se encuentre algun casillero donde haya una bomba.
		 * Post: Incrementa en uno el valor de los casilleros aledanios que no tengan bombas.
		 */
		void rellenarSubMatrizAledaniaBomba(int fila,int columna);

		/*
		 * Pre : Recibe la posicion de fila y columna en la que se encuentre algun casillero que se quiera descubrir.
		 * Post: Si el casillero que se descubre no tiene bombas alrededor se realizara un llamado recursivo para descubirir los casilleros
		 * 		 aledanios y ver la cantidad bombas que tienen estos alrededor.
		 */
		int descubrirCasillerosAledaniosVacio(int fila,int columna);





};

#endif

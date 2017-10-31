/*
 * TableroBMP.h
 *
 *  Created on: 29 oct. 2017
 *      Author: gonzalo
 */

#ifndef TABLEROBMP_H_
#define TABLEROBMP_H_


#include <iostream>
#include "EasyBMP.h"
#include "typedefs.h"


/*
 * Un TableroBMP es una imagen que representa el estado de la partida.
 * Contiene un alto y un ancho que estaran representados segun sea el tamanio del tablero y el tamanio del pixel que
 * se calcula en base a la cantidad de filas y columnas que tengan.
 */
class TableroBMP
{
private:

	BMP tablero;
	unsigned int alto;
	unsigned int ancho;
	unsigned int tamanioPixel;

public:

	/*
	 * Pre : Recibe las filas y columnas que tendra
	 * Post: Prepara una BMP que se utilizara para mostrar el estado del tablero
	 */
	TableroBMP(unsigned int filas, unsigned int columnas);

	/*
	 * Post: Guarda una imagen BMP con el tablero inicial
	 */
	void generarTableroInicial();

	/*
	 * Pre : Recibe como parametros la fila, columna y el valor de la jugada a actualizar en el tablero
	 * Post: Actualiza el tablero segun los parametros ingresados
	 */
	void completarConJugada(unsigned int fila, unsigned int columna, unsigned int valor);

	/*
	 * Pre : Recibe como entrada la fila y columna donde se ha marcado una bandera
	 * Post: Actualiza el BMP con la bandera segun fila y columna
	 */
	void completarConBandera(unsigned int fila, unsigned int columna);

	/*
	 * Pre : Recibe como entrada la fila y columna del casillero oculto
	 * Post: Actualiza el BMP con un casillero oculto segun fila y columna
	 */
	void completarCasilleroOculto(unsigned int fila, unsigned int columna);

	/*
	 * Post: Genera un archivo BMP segun el turno ingresado
	 */
	void imprimirTablero(uint turno);

};




#endif /* TABLEROBMP_H_ */

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
	 * pre: recibe las filas y columnas que tendra
	 * pos: prepara una BMP que se utilizara para mostrar el estado del tablero
	 */
	TableroBMP(unsigned int filas, unsigned int columnas);

	/*
	 * post: Guarda una imagen BMP con el tablero inicial
	 */
	void generarTableroInicial();

	/*
	 * pre: recibe como parametros la fila, columna y el valor de la jugada a actualizar en el tablero
	 * post: actualiza el tablero segun los parametros ingresados
	 */
	void completarConJugada(unsigned int fila, unsigned int columna, unsigned int valor);

	/*
	 * pre: recibe como entrada la fila y columna donde se ha marcado una bandera
	 * post: actualiza el BMP con la bandera segun fila y columna
	 */
	void completarConBandera(unsigned int fila, unsigned int columna);

	/*
	 * pre: recibe como entrada la fila y columna del casillero oculto
	 * post: actualiza el BMP con un casillero oculto segun fila y columna
	 */
	void completarCasilleroOculto(unsigned int fila, unsigned int columna);

	/*
	 * post: genera un archivo BMP segun el turno ingresado
	 */
	void imprimirTablero(uint turno);

};




#endif /* TABLEROBMP_H_ */

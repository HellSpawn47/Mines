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
	TableroBMP();

	void generarTableroInicial();

	void completarConJugada(unsigned int fila, unsigned int columna, unsigned int valor);

	void completarConBandera(unsigned int fila, unsigned int columna);

	void completarCasilleroOculto(unsigned int fila, unsigned int columna);

	void imprimirTablero(uint turno);

};




#endif /* TABLEROBMP_H_ */

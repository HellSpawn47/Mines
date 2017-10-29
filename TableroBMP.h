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

class TableroBMP
{
private:

	BMP tablero;
	unsigned int alto;
	unsigned int ancho;
	unsigned int tamanioPixel;

public:

	TableroBMP(unsigned int filas, unsigned int columnas);

	void generarTableroInicial();

	void completarConJugada(unsigned int fila, unsigned int columna, unsigned int valor);

	void completarConBandera(unsigned int fila, unsigned int columna);

	void imprimirTablero();
};




#endif /* TABLEROBMP_H_ */

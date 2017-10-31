/*
 * PuntajesBMP.h
 *
 *  Created on: 30 oct. 2017
 *      Author: gonzalo
 */

#ifndef PUNTAJESBMP_H_
#define PUNTAJESBMP_H_

#include <iostream>
#include "EasyBMP.h"
#include "typedefs.h"
#include "EasyBMP_Font.h"
#include "EasyBMP_Geometry.h"

class PuntajesBMP
{
private:

	BMP puntaje;

public:

	PuntajesBMP();

	void imprimirPuntajes(std::string nombreJugador, int puntaje, uint posicion);

};

#endif /* PUNTAJESBMP_H_ */

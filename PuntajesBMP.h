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
#include "Jugador.h"
#include "ListaCircular.h"

/*
 * Un PuntajesBMP es una imagen que representa los puntajes de los jugadores en la partida.
 */
class PuntajesBMP
{
private:

	BMP puntaje;

public:

	/*
	 * Post: Crea una imagen vacia que se utilizara para mostrar los puntajes de cada jugador
	 */
	PuntajesBMP();

	/*
	 * Post: Actualiza el puntaje del jugador ingresado en "nombreJugador" en el BMP.
	 */
	void imprimirPuntajes(Lista<Jugador*>* jugador, unsigned int turno);

};

#endif /* PUNTAJESBMP_H_ */

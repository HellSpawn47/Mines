/*
 * ValidadorDeIngresos.cpp
 *
 *  Created on: 30/10/2017
 *      Author: javier
 */

#include "constantes.h"
#include "validadorDeIngresos.h"

bool Validador::esDificultadValida(char dificultad){

	return (dificultad==FACIL)||(dificultad==MEDIA)||(dificultad==DIFICIL);

}

bool Validador::esAccionValida(char accion){

	return (accion==DESCUBRIR)||(accion==MARCAR);

}



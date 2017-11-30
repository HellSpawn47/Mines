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

	return (accion==ABRIR)||(accion==MARCAR)||(accion==SALIR);

}

bool Validador::verificarSiNo(char accion){
	return (accion=='s')||(accion=='n');
}

bool Validador::verificarDeshacerRehacerOSalir(char accion){
	return (accion=SALIR)||(accion==DESHACER)||(accion==REHACER);
}


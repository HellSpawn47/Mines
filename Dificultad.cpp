#include "Dificultad.h"
#include "constantes.h"

Dificultad::Dificultad(uint filas, uint columnas, char dificultad){

	uint cantidadBombas = 0;
	float coeficienteProporcion = 0;
	/*Calcular en base a la dificultad f/m/d la cantidad de bombas y asignarla */

	if(dificultad == FACIL)
		coeficienteProporcion = 0.15;
	else if(dificultad == MEDIA)
		coeficienteProporcion = 0.20;
	else if(dificultad == DIFICIL)
		coeficienteProporcion = 0.25;

	cantidadBombas = filas * columnas * coeficienteProporcion;

	cantidadDeBombas = cantidadBombas;

}

uint Dificultad::obtenerCantidadDeBombas(){

return this->cantidadDeBombas;

}

#include "Casillero.h"

#include "constantes.h"

//hola xd probando

Casillero::Casillero(){

	valor = CERO;
	estado = OCULTO;

}

void Casillero::descubrir(){

	estado = DESCUBIERTO;

}

void Casillero::marcar(){

	estado = MARCADO;

}

uint Casillero::getValor(){

	return valor;

}

uint Casillero::getEstado(){

	return estado;

}

void Casillero::setValor(uint nuevoValor){

	valor = nuevoValor;

}

void Casillero::setEstado(uint nuevoEstado){

	estado = nuevoEstado;

}

void Casillero::incrementarValor(){

	valor++;

}






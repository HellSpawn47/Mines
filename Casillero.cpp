#include "Casillero.h"

#include "constantes.h"

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

int Casillero::getValor(){

	return valor;

}

int Casillero::getEstado(){

	return estado;

}

void Casillero::setValor(int nuevoValor){

	valor = nuevoValor;

}

void Casillero::setEstado(int nuevoEstado){

	estado = nuevoEstado;

}

void Casillero::incrementarValor(){

	valor++;

}






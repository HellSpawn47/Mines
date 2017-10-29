#include "Jugada.h"

void Jugada::modificarFila(uint nuevaFila){

	this->fila = nuevaFila;

}

void Jugada::modificarColumna(uint nuevaColumna){

	this->columna = nuevaColumna;

}

void Jugada::modificarAccion(char nuevaAccion){

	this->accion = nuevaAccion;

}

uint Jugada::obtenerFila(){

	return this->fila;

}

uint Jugada::obtenerColumna(){

	return this->columna;

}

char Jugada::obtenerAccion(){

	return this->accion;

}

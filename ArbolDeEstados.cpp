#include "ArbolDeEstados.h"

ArbolDeEstados::ArbolDeEstados(EstadoDePartida Estado){

	NodoDeEstados* nuevoNodo = new NodoDeEstados(Estado);

	this->raiz = nuevoNodo;
	this->senialador = raiz;

}

void ArbolDeEstados::agregar(EstadoDePartida nuevoEstado){

	NodoDeEstados* nuevo = new NodoDeEstados(nuevoEstado);

	this->senialador->agregarEstadoHijo(nuevo);

	nuevo->cambiarPadre(this->senialador);

	this->senialador = nuevo;

}

void ArbolDeEstados::modificarSenialador(std::string opcion){

}

NodoDeEstados* ArbolDeEstados::obtenerSenialador(){

	return this->senialador;
}


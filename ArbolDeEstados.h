#ifndef ARBOL_ESTADOS_H
#define ARBOL_ESTADOS_H

#include <string>

#include "EstadoDePartida.h"
#include "NodoDeEstados.h"

class ArbolDeEstados{

	private:

		NodoDeEstados* raiz;

		NodoDeEstados* senialador;

	public:

		ArbolDeEstados(EstadoDePartida Estado);

		void agregar(EstadoDePartida nuevoEstado);

		void modificarSenialador(std::string opcion);

		NodoDeEstados* obtenerSenialador();

};

#endif

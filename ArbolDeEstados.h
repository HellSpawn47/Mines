#ifndef ARBOL_ESTADOS_H
#define ARBOL_ESTADOS_H

#include <string>

#include "EstadoDePartida.h"
#include "NodoDeEstados.h"
#include "constantes.h"
#include "Partida.h"

class ArbolDeEstados{

	private:

		NodoDeEstados* raiz;

		NodoDeEstados* senialador;

	public:

		ArbolDeEstados();

		void agregar();

		int modificarSenialador(char opcion,Partida* partida);

		NodoDeEstados* obtenerSenialador();

};

#endif

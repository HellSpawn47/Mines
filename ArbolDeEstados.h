#ifndef ARBOL_ESTADOS_H
#define ARBOL_ESTADOS_H

#include <string>

#include "EstadoDePartida.h"
#include "NodoDeEstados.h"
#include "constantes.h"
#include "Partida.h"
	
	/* 
	 * Un Arbol de Estados es una estructura de datos que permite almacenar el estado de cada turno. Tiene una raiz 
	 * que corresponde al primer elemento del arbol. Y un señalador para navegar entre los elementos.
	 */
class ArbolDeEstados{

	private:

		NodoDeEstados* raiz;

		NodoDeEstados* senialador;

	public:
		/*
		 * Constructor
		 *
		 */
		ArbolDeEstados();

		void agregar();

		int modificarSenialador(char opcion,Partida* partida);

		NodoDeEstados* obtenerSenialador();


		void viajarEnElTiempo();

		~ArbolDeEstados();

};

#endif

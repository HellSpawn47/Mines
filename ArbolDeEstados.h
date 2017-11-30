#ifndef ARBOL_ESTADOS_H
#define ARBOL_ESTADOS_H

#include <string>

#include "EstadoDeTurno.h"
#include "NodoDeEstados.h"
#include "constantes.h"
#include "Partida.h"
#include "InteraccionConJugador.h"

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

		/*
		 *
		 * Post: Crea y agrega un nodo de estados nuevo en un nivel inferior al que apunta el senialador. Y mueve el senialador al nuevo nodo.
		 *
		 */
		void agregar();

		/*
		 * Pre:  Recibe la opcion (deshacer/rehacer) y la partida.
		 * Post: Deshace o rehace el turno modificando el senialador.
		 *
		 */
		int modificarSenialador(char opcion,Partida* partida);

		/*
		 *
		 * Post: Devuelve el nodo al cual apunta el senialador.
		 *
		 */
		NodoDeEstados* obtenerSenialador();

		/*
		 * Pre:  Recibe la partida y la interfaz de interaccion con el usuario.
		 * Post: Pregunta al jugador si quiere deshacer o rehacer turnos mientras tenga puntaje suficiente para realizar esta accion, o si el
		 *  	 jugador desea salir de este menu.
		 */
		void viajarEnElTiempo(Partida* partida, InteraccionConJugador* interactuar);

		/*
		 *
		 * Destructor.
		 *
		 */
		~ArbolDeEstados();

};

#endif

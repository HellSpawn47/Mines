#ifndef NODO_ESTADOS_H
#define NODO_ESTADOS_H

#ifndef NULL
#define NULL 0
#endif

#include "iostream"
#include "EstadoDeTurno.h"
#include "ListaCircular.h"
#include "typedefs.h"

class NodoDeEstados {

	/*
	 * Un Nodo es uno de los elementos que componen un arbol, este tiene un estado y está conectado al nodo padre,
	 * además posee una lista de nodos hijo.
	 */
    private:

		EstadoDeTurno* estado;

        NodoDeEstados* padre;

        Lista<NodoDeEstados*>* listaDeHijos;

        uint cantidadDeNodosSuperiores;

        uint cantidadDeNodosInferiores;


    public:

        /*
         * Post: El Nodo resulta inicializado
         *       y sin un Nodo siguiente.
         */
        NodoDeEstados(){

            this->estado = new EstadoDeTurno;
            this->padre = NULL;
            this->listaDeHijos = new Lista<NodoDeEstados*>;
            this->cantidadDeNodosSuperiores=0;
            this->cantidadDeNodosInferiores=0;
        }

        /*
         * Post: Devuelve el valor del estado.
         */
        EstadoDeTurno* obtenerEstado() {

            return this->estado;
        }

        /*
         * Post: Cambia el valor del estado.
         */
        void cambiarEstado(EstadoDeTurno* nuevoEstado) {

            this->estado = nuevoEstado;
        }

		/*
		 *
		 * Post: Devuelve el nodo padre del nodo actual si es que lo posee.
		 *
		 */
        NodoDeEstados* obtenerPadre() {

            return this->padre;
        }

		/*
		 *
		 * Post: Devuelve la lista de nodos hijo.
		 *
		 */
        Lista<NodoDeEstados*>* obtenerEstadosHijos() {

            return this->listaDeHijos;
        }

		/*
		 *
		 * Post: Cambia el nodo padre del nodo actual e incrementa el contador de nodos inferiores que tienen sus nodos
		 * 		 superiores.
		 *
		 */
        void cambiarPadre(NodoDeEstados* nuevoPadre) {

            this->padre = nuevoPadre;
            cantidadDeNodosSuperiores=nuevoPadre->obtenerCantidadDeNodosSuperiores() + 1;
        }

		/*
		 *
		 * Post: Agrega el nodo recibido a la lista de hijos del nodo actual e incrementa el contador de nodos inferiores
		 * 		 del nodo actual.
		 *
		 */
        void agregarEstadoHijo(NodoDeEstados* nuevoEstado){

        	listaDeHijos->agregar(nuevoEstado);
        	cantidadDeNodosInferiores++;
        	if (obtenerPadre() != NULL){
        		obtenerPadre()->aumentarNodosInferioresAPadre();
        	}

        }

		/*
		 *
		 * Post: Incrementa el contador de nodos inferiores y si el nodo tiene padre aumenta tambien el de este.
		 * 		 (Llamado recursivo)
		 *
		 */
        void aumentarNodosInferioresAPadre(){
        	cantidadDeNodosInferiores++;
        	if (this->obtenerPadre()!=NULL){
        		this->obtenerPadre()->aumentarNodosInferioresAPadre();
        	}
        }

		/*
		 *
		 * Post: Devuelve la cantidad de nodos superiores.
		 *
		 */
        int obtenerCantidadDeNodosSuperiores(){

        	return this->cantidadDeNodosSuperiores;
        }

		/*
		 *
		 * Post: Devuelve la cantidad de nodos inferiores.
		 *
		 */
        int obtenerCantidadDeNodosInferiores(){
        	return this->cantidadDeNodosInferiores;
        }

		/*
		 *
		 * Destructor.
		 *
		 */
        ~NodoDeEstados(){
        	delete estado;

        	listaDeHijos->iniciarCursor();
        	while(listaDeHijos->avanzarCursor()){
        		NodoDeEstados * nodoABorrar = listaDeHijos->obtenerCursor();
        		delete nodoABorrar;
        	}

        	delete listaDeHijos;
        }
};


#endif /* NODO_H_ */

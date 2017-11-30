#ifndef NODO_ESTADOS_H
#define NODO_ESTADOS_H

#ifndef NULL
#define NULL 0
#endif

#include "iostream"
#include "EstadoDePartida.h"
#include "ListaCircular.h"
#include "typedefs.h"

class NodoDeEstados {

	/*
	 * Un Nodo que es uno de los elementos que componen una lista, este tiene un estado y está conectado al nodo padre,
	 * además posee una lista de nodos hijo.
	 */
    private:

		EstadoDePartida* estado;

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

            this->estado = new EstadoDePartida;
            this->padre = NULL;
            this->listaDeHijos = new Lista<NodoDeEstados*>;
            this->cantidadDeNodosSuperiores=0;
            this->cantidadDeNodosInferiores=0;
        }

        /*
         * Post: Devuelve el valor del estado.
         */
        EstadoDePartida* obtenerEstado() {

            return this->estado;
        }

        /*
         * Post: Cambia el valor del estado.
         */
        void cambiarEstado(EstadoDePartida* nuevoEstado) {

            this->estado = nuevoEstado;
        }

        NodoDeEstados* obtenerPadre() {

            return this->padre;
        }

        Lista<NodoDeEstados*>* obtenerEstadosHijos() {

            return this->listaDeHijos;
        }

        void cambiarPadre(NodoDeEstados* nuevoPadre) {

            this->padre = nuevoPadre;
            cantidadDeNodosSuperiores=nuevoPadre->obtenerCantidadDeNodosSuperiores() + 1;
        }

        void agregarEstadoHijo(NodoDeEstados* nuevoEstado){

        	listaDeHijos->agregar(nuevoEstado);
        	cantidadDeNodosInferiores++;
        	if (obtenerPadre() != NULL){
        		obtenerPadre()->aumentarNodosInferioresAPadre();
        	}

        }

        void aumentarNodosInferioresAPadre(){
        	cantidadDeNodosInferiores++;
        	if (this->obtenerPadre()!=NULL){
        		this->obtenerPadre()->aumentarNodosInferioresAPadre();
        	}
        }

        int obtenerCantidadDeNodosSuperiores(){

        	return this->cantidadDeNodosSuperiores;
        }

        int obtenerCantidadDeNodosInferiores(){
        	return this->cantidadDeNodosInferiores;
        }

        ~NodoDeEstados(){
        	delete estado;
        	delete[] listaDeHijos;
        }
};


#endif /* NODO_H_ */

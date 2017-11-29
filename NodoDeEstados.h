#ifndef NODO_ESTADOS_H
#define NODO_ESTADOS_H

#ifndef NULL
#define NULL 0
#endif

#include "iostream"
#include "EstadoDePartida.h"
#include "ListaCircular.h"

class NodoDeEstados {

	/*
	 * Un Nodo que es uno de los elementos que componen una lista, este tiene un estado y está conectado al nodo padre,
	 * además posee una lista de nodos hijo.
	 */
    private:

		EstadoDePartida estado;

        NodoDeEstados* padre;

        Lista<NodoDeEstados*>* listaDeHijos;


    public:

        /*
         * Post: El Nodo resulta inicializado con el estado dado
         *       y sin un Nodo siguiente.
         */
        NodoDeEstados(EstadoDePartida estado) {

            this->estado = estado;
            this->padre = NULL;
            this->listaDeHijos = NULL;

        }

        /*
         * Post: Devuelve el valor del estado.
         */
        EstadoDePartida obtenerEstado() {

            return this->estado;
        }

        /*
         * Post: Cambia el valor del estado.
         */
        void cambiarEstado(EstadoDePartida nuevoEstado) {

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
        }

        void agregarEstadoHijo(NodoDeEstados* nuevoEstado){

        	listaDeHijos->agregar(nuevoEstado);

        }
};


#endif /* NODO_H_ */

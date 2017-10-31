#ifndef NODO_H_
#define NODO_H_

#ifndef NULL
#define NULL 0
#endif

template<class T> class Nodo {

	/*
	 * Un Nodo que es uno de los elementos que componen una lista, este tiene un dato y está conectado al siguiente
	 * elemento de la lista.
	 */
    private:

        T dato;

        Nodo<T>* siguiente;

    public:

        /*
         * Post: El Nodo resulta inicializado con el dato dado
         *       y sin un Nodo siguiente.
         */
        Nodo(T dato) {

            this->dato = dato;
            this->siguiente = NULL;
        }

        /*
         * Post: Devuelve el valor del dato.
         */
        T obtenerDato() {

            return this->dato;
        }

        /*
         * Post: Cambia el valor del dato.
         */
        void cambiarDato(T nuevoDato) {

            this->dato = nuevoDato;
        }

        /*
         * Post: Devuelve el siguiente Nodo.
         */
        Nodo<T>* obtenerSiguiente() {

            return this->siguiente;
        }

        /*
         * Post: Cambia el siguiente Nodo por nuevoSiguiente.
         */
        void cambiarSiguiente(Nodo<T>* nuevoSiguiente) {

            this->siguiente = nuevoSiguiente;
        }
};


#endif /* NODO_H_ */

#ifndef LISTA_H_
#define LISTA_H_

#include "Nodo.h"

/*
 * Una Lista es una coleccion dinamica de elementos dispuestos en una secuencia.
 *
 * Define operaciones para agregar, remover, acceder y cambiar elementos
 * en cualquier posicion.
 *
 * Tiene un cursor que permite recorrer todos los elementos secuencialmente.
 *
 */
template<class T> class Lista {

    private:

        Nodo<T>* primero;

        unsigned int tamanio;

        Nodo<T>* cursor;

    public:

        /*
         * Post: Lista vacia.
         */
        Lista();

        /*
         * Post: Lista que tiene los mismos elementos que otraLista.
         *       La instancia resulta en una copia de otraLista.
         */
        Lista(Lista<T>& otraLista);

        /*
         * Post: Indica si la Lista tiene algun elemento.
         */
        bool estaVacia();

        /*
         * Post: Devuelve la cantidad de elementos que tiene la Lista.
         */
        unsigned int contarElementos();

        /*
         * Post: Agrega el elemento al final de la Lista, en la posicion:
         *       contarElementos() + 1.
         */
        void agregar(T elemento);

        /*
         * Pre : Posicion pertenece al intervalo: [1, contarElementos() + 1]
         * Post: Agrega el elemento en la posicion indicada.
         */
        void agregar(T elemento, unsigned int posicion);

        /*
         * Post: Agrega todos los elementos de otraLista
         *       a partir de la posicion contarElementos() + 1.
         */
        void agregar(Lista<T> &otraLista);

        /*
         * Pre : Posicion pertenece al intervalo: [1, contarElementos()]
         * Post: Devuelve el elemento en la posici�n indicada.
         */
        T obtener(unsigned int posicion);

        /*
         * Pre : Posicion pertenece al intervalo: [1, contarElementos()]
         * Post: cambia el elemento en la posicion indicada por el
         *       elemento dado.
         */
        void asignar(T elemento, unsigned int posicion);

        /*
         * Pre : Posicion pertenece al intervalo: [1, contarElementos()]
         * Post: Remueve de la Lista el elemento en la posicion indicada.
         * 		 Si el dato en el nodo es un puntero a memoria dinamica
         * 		 se debe liberar esa memoria previamente. Este metodo
         * 		 libera unicamente la memoria reservada para el nodo
         * 		 independientemente de el dato que contenga.
         */
        void remover(unsigned int posicion);

        /*
         * Post: Deja el cursor de la Lista preparado para hacer un nuevo
         *       recorrido sobre sus elementos.
         */
        void iniciarCursor();

        /*
         * Pre : Se ha iniciado un recorrido (invocando el metodo
         *       iniciarCursor()) y desde entonces no se han agregado o
         *       removido elementos de la Lista.
         * Post: Mueve el cursor y lo posiciona en el siguiente elemento
         *       del recorrido.
         *       El valor de retorno indica si el cursor quedo posicionado
         *       sobre un elemento o no (en caso de que la Lista esta vacia o
         *       no existan mas elementos por recorrer.)
         */
        bool avanzarCursor();

        /*
         * Pre : El cursor esta posicionado sobre un elemento de la Lista,
         *       (fue invocado el metodo avanzarCursor() y devolvio true)
         * Post: Devuelve el elemento en la posicion del cursor.
         *
         */
        T obtenerCursor();

        /*
         * Post: Libera los recursos asociados a la Lista.
         */
        ~Lista();

        /*
         * Pre : Posicion pertenece al intervalo: [1, contarElementos()]
         * Post: Devuelve el nodo en la posicion indicada.
         */
        Nodo<T>* obtenerNodo(unsigned int posicion);
};

template<class T> Lista<T>::Lista() {

    this->primero = NULL;
    this->tamanio = 0;
    this->cursor = NULL;
}

template<class T> Lista<T>::Lista(Lista<T>& otraLista) {

    this->primero = NULL;
    this->tamanio = 0;
    this->cursor = NULL;

    /* Copia los elementos de otraLista */
    this->agregar(otraLista);
}

template<class T> bool Lista<T>::estaVacia() {

    return (this->contarElementos() == 0);
}

template<class T> unsigned int Lista<T>::contarElementos() {

    return this->tamanio;
}

template<class T> void Lista<T>::agregar(T elemento) {

    this->agregar(elemento, this->tamanio + 1);
}

template<class T> void Lista<T>::agregar(T elemento, unsigned int posicion) {

    if ((posicion > 0) && (posicion <= this->tamanio + 1)) {

        Nodo<T>* nuevo = new Nodo<T>(elemento);

        if (this->estaVacia()){
            nuevo->cambiarSiguiente(nuevo);
            this->primero = nuevo;
        }
        else if (posicion==1){
            Nodo<T>* ultimo = obtenerNodo(this->contarElementos());
            ultimo->cambiarSiguiente(nuevo);
            nuevo->cambiarSiguiente(primero);
            primero = nuevo;
        }
        else {
            Nodo<T>* nodoAnterior = obtenerNodo(posicion-1);
            nuevo->cambiarSiguiente(nodoAnterior->obtenerSiguiente());
            nodoAnterior->cambiarSiguiente(nuevo);
        }

        this->tamanio++;

        /* Cualquier recorrido actual queda invalidado */
        this->iniciarCursor();
    }

}

template<class T> void Lista<T>::agregar(Lista<T> &otraLista) {

    otraLista.iniciarCursor();
    while (otraLista.avanzarCursor()) {
        this->agregar(otraLista.obtenerCursor());
    }
}

template<class T> T Lista<T>::obtener(unsigned int posicion) {

    T elemento;

    if ((posicion > 0) && (posicion <= this->tamanio)) {

        elemento = this->obtenerNodo(posicion)->obtenerDato();
    }

    return elemento;
}

template<class T> void Lista<T>::asignar(T elemento, unsigned int posicion) {

    if ((posicion > 0) && (posicion <= this->tamanio)) {

        this->obtenerNodo(posicion)->cambiarDato(elemento);
    }
}

template<class T> void Lista<T>::remover(unsigned int posicion) {

    if ((posicion > 0) && (posicion <= this->tamanio)) {

        Nodo<T>* removido;

        if (this->contarElementos()==1){

            removido = this->primero;
            primero = NULL;

        }
        else if (posicion == 1) {

            removido = this->primero;
            this->primero = removido->obtenerSiguiente();
            Nodo<T>* ultimo = obtenerNodo(this->contarElementos());
            ultimo->cambiarSiguiente(primero);

        } else {

            Nodo<T>* anterior = this->obtenerNodo(posicion - 1);
            removido = anterior->obtenerSiguiente();
            anterior->cambiarSiguiente(removido->obtenerSiguiente());
        }

        delete removido;
        this->tamanio--;

        /* Cualquier recorrido actual queda invalidado */
        this->iniciarCursor();
    }
}

template<class T> void Lista<T>::iniciarCursor() {

    this->cursor = NULL;
}

template<class T> bool Lista<T>::avanzarCursor() {

    if (this->cursor == NULL) {

        this->cursor = this->primero;

    } else {

        this->cursor = this->cursor->obtenerSiguiente();
    }

    /* Pudo avanzar si el cursor ahora apunta a un nodo */
    return (this->cursor != NULL);
}

template<class T> T Lista<T>::obtenerCursor() {

    T elemento;

    if (this->cursor != NULL) {

        elemento = this->cursor->obtenerDato();
    }

    return elemento;
}

template<class T> Lista<T>::~Lista() {

    while (!this->estaVacia()) {
        remover(1);
    }
}

template<class T> Nodo<T>* Lista<T>::obtenerNodo(unsigned int posicion) {

    Nodo<T>* actual = this->primero;
    for (unsigned int i = 1; i < posicion; i++) {

        actual = actual->obtenerSiguiente();
    }

    return actual;
}

#endif /* LISTA_H_ */

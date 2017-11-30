#include "ArbolDeEstados.h"
#include "Partida.h"
#include "constantes.h"
#include <iostream>

using namespace std;

ArbolDeEstados::ArbolDeEstados(){

	NodoDeEstados* nuevoNodo = new NodoDeEstados();

	this->raiz = nuevoNodo;
	this->senialador = raiz;

}

void ArbolDeEstados::agregar(){

	NodoDeEstados* nuevo = new NodoDeEstados();

	this->senialador->agregarEstadoHijo(nuevo);

	nuevo->cambiarPadre(this->senialador);

	this->senialador = nuevo;

}

int ArbolDeEstados::modificarSenialador(char opcion,Partida* partida){
	int puntajeARestar;
	if (opcion == DESHACER && senialador!=raiz){
		NodoDeEstados* senialadorANodoAuxiliar = senialador;
		senialador=senialadorANodoAuxiliar->obtenerPadre();
		puntajeARestar=partida->actualizarTableroDeshaciendoJugada(senialadorANodoAuxiliar->obtenerEstado());
	}
	else if (opcion == DESHACER && senialador==raiz){
		cout << "No se puede deshacer \n";
		puntajeARestar=0;
	}
	else if (opcion == REHACER && (senialador->obtenerEstadosHijos() != NULL)){
		Lista<NodoDeEstados*>* listaDeNodos = senialador->obtenerEstadosHijos();
		listaDeNodos->iniciarCursor();
		listaDeNodos->avanzarCursor();
		if (listaDeNodos->contarElementos() != 1){
			uint caminoARehacer=0;
			while ((caminoARehacer < 1) || (caminoARehacer > (listaDeNodos->contarElementos()))){
				cout << "Elija el futuro al que quiera acceder, entre 1 y " << listaDeNodos->contarElementos() << ": ";
				cin >> caminoARehacer;
				cout << endl;
			}
			for (uint i=1; i<caminoARehacer; i++){
				listaDeNodos->avanzarCursor();
			}
		}
		senialador = listaDeNodos->obtenerCursor();
		listaDeNodos->iniciarCursor();
		puntajeARestar=partida->actualizarTableroRehaciendoJugada(senialador->obtenerEstado());
	}
	else{
		cout << "No se puede rehacer \n";
		puntajeARestar=0;
	}
	return puntajeARestar;
}

NodoDeEstados* ArbolDeEstados::obtenerSenialador(){

	return this->senialador;
}


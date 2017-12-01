#include "ArbolDeEstados.h"
#include "constantes.h"
#include <iostream>
#include <string>
#include "validadorDeIngresos.h"
#include "InteraccionConJugador.h"

using namespace std;

ArbolDeEstados::ArbolDeEstados(){

	NodoDeEstados* nuevoNodo = new NodoDeEstados;

	this->raiz = nuevoNodo;
	this->senialador = raiz;

}

void ArbolDeEstados::agregar(){

	NodoDeEstados* nuevo = new NodoDeEstados;

	this->senialador->agregarEstadoHijo(nuevo);

	nuevo->cambiarPadre(this->senialador);

	this->senialador = nuevo;

}

int ArbolDeEstados::modificarSenialador(char opcion,Partida* partida){
	int puntajeARestar;
	if (opcion == DESHACER && senialador!=raiz){
		puntajeARestar=partida->volverAlFuturo(senialador->obtenerEstado(),opcion);
		senialador=senialador->obtenerPadre();
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
		puntajeARestar=partida->volverAlFuturo(senialador->obtenerEstado(),opcion);
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

void ArbolDeEstados::viajarEnElTiempo(Partida* partida, InteraccionConJugador* interactuar){
	
	uint cantidadDeshacer,cantidadRehacer;
	int puntajeJugadorEnTurno, puntajeARestar;
	Validador validador;
	cantidadDeshacer = this->obtenerSenialador()->obtenerCantidadDeNodosSuperiores();
	cantidadRehacer = this->obtenerSenialador()->obtenerCantidadDeNodosInferiores();
	char accion;
	puntajeJugadorEnTurno=partida->obtenerJugadorEnTurno()->getPuntaje();

	do{

		accion = interactuar->pedirDeshacerORehacer(puntajeJugadorEnTurno,cantidadRehacer,cantidadDeshacer);

		if ((accion==REHACER && cantidadRehacer > 0) || (accion==DESHACER && cantidadDeshacer > 0)) {
			puntajeARestar = this->modificarSenialador(accion, partida);
			partida->obtenerJugadorEnTurno()->modificarPuntaje(puntajeARestar);
			puntajeJugadorEnTurno=partida->obtenerJugadorEnTurno()->getPuntaje();
			cantidadDeshacer = this->obtenerSenialador()->obtenerCantidadDeNodosSuperiores();
			cantidadRehacer = this->obtenerSenialador()->obtenerCantidadDeNodosInferiores();
		}
		else if(!validador.verificarDeshacerRehacerOSalir(accion)){
			cout << "La accion ingresada no es valida, ingrese nuevamente" << endl;
		}

	}while(accion!='s' && puntajeJugadorEnTurno >= COSTE);

}


ArbolDeEstados::~ArbolDeEstados(){
	delete raiz;
}




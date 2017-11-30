#include "ArbolDeEstados.h"
#include "constantes.h"
#include <iostream>
#include "validadorDeIngresos.h"
#include "InteraccionConJugador.h"

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
		senialador=senialador->obtenerPadre();
		puntajeARestar=partida->volverAlFuturo(senialador->obtenerEstado(),opcion);
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
	//xd
	do{
		cout << "Con tu puntaje actual podes deshacer/rehacer hasta " << puntajeJugadorEnTurno/3 << " jugadas, es posible deshacer " << cantidadDeshacer <<
			    "turnos y \n" << "rehacer hasta " << cantidadRehacer << "turnos (considerando realidades alternativas), que desea hacer (d/r/s)?" << endl;
		cin >> accion;
		if ((accion==REHACER && cantidadRehacer > 0) || (accion==DESHACER && cantidadDeshacer > 0)) {
			puntajeARestar = this->modificarSenialador(accion, partida);
			partida->obtenerJugadorEnTurno()->modificarPuntaje(puntajeARestar);
			puntajeJugadorEnTurno=partida->obtenerJugadorEnTurno()->getPuntaje();
			cantidadDeshacer = this->obtenerSenialador()->obtenerCantidadDeNodosSuperiores();
			cantidadRehacer = this->obtenerSenialador()->obtenerCantidadDeNodosInferiores();
			partida->imprimirTablero(partida->obtenerTurnoActual());
		}
		else if(!validador.verificarDeshacerRehacerOSalir(accion)){
			cout << "La accion ingresada no es valida, ingrese nuevamente" << endl;
		}
	}while(accion!='s' && puntajeJugadorEnTurno > 3);

}


ArbolDeEstados::~ArbolDeEstados(){
	delete raiz;
}




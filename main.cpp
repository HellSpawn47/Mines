#include <iostream>

#include "EstadoDePartida.h"
#include "Jugador.h"
#include "Tablero.h"
#include "Randomizador.h"
#include "InteraccionConJugador.h"
#include "Partida.h"
#include "ArbolDeEstados.h"

using namespace std;

int main(){
	//Se definio el tipo de dato unsigned int como uint

	InteraccionConJugador* interactuar = new InteraccionConJugador();
	ArbolDeEstados* arbol = new ArbolDeEstados;
	EstadoDePartida* estado;
	interactuar->bienvenida();
	uint filas = interactuar->pedirCantidad("filas");
	uint columnas = interactuar->pedirCantidad("columnas");
	char dificultad = interactuar->pedirDificultad();
	int puntaje = 0;
	Jugada* jugada = new Jugada;

	Partida* partida = new Partida(filas, columnas, dificultad);

	PuntajesBMP* puntajes = new PuntajesBMP;

	uint cantJugadores = interactuar->pedirCantidad("jugadores");
	partida->agregarJugadores(cantJugadores);

	partida->imprimirTablero(1);

	//Inicio de cada jugada

	do{

		partida->avanzarTurno();


		if(partida->obtenerJugadorEnTurno()->getSigueJugando()){
			cout << "\nEs el turno de: " << partida->obtenerJugadorEnTurno()->getNombre() << endl;

			interactuar->pedirJugada(jugada,partida,arbol);
			if (jugada->obtenerAccion() == ABRIR || jugada->obtenerAccion() == MARCAR){
				arbol->agregar();
				estado=arbol->obtenerSenialador()->obtenerEstado();
				puntaje = partida->actualizarTablero(jugada,estado);
			}
			else{
				//arbol->modificarSenialador(jugada->obtenerAccion(),partida);
			}

			partida->actualizarPuntaje(puntaje);
			partida->imprimirTablero(partida->obtenerTurnoActual());

			cout << "\npuntaje: " << partida->obtenerJugadorEnTurno()->getPuntaje() << endl;
			cout << "\n------------------------------------------------------------------" << endl;
			puntajes->imprimirPuntajes(partida->obtenerListaDeJugadores(), partida->obtenerTurnoActual());
		}


	}while( partida->continuarPartida() );

	if(partida->getTablero()->casillerosRestantesPorDescubrir() > 0){
		partida->getTablero()->descubrirTodasLasBombas();
	}

	interactuar->imprimirMensaje("Partida Terminada");

	partida->imprimirTablero(partida->obtenerTurnoActual());

	delete interactuar;
	delete jugada;
	delete partida;
	delete puntajes;


	/*EstadoDePartida estado;
	ArbolDeEstados arbol(estado);

	estado.agregarPosicionDescubierta(4,5);
	EstadoDePartida otroEstado;

	otroEstado.agregarPosicionDescubierta(7,6);
	cout << "1" << endl;
	arbol.agregar(otroEstado);
	cout << "2" << endl;

	cout << arbol.obtenerSenialador()->obtenerEstado().obtenerPosicionesDescubiertas()->fila << endl;

	*/
	return 0;
}

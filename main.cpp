#include <iostream>
#include "Jugador.h"
#include "Lista.h"
using namespace std;

int main(){

	Lista<Jugador*> ListaDeJugadores;
	string nombre;
	Jugador* nuevoJugador;
	int i = 0;

	while (i < 3){
		cout << "Ingrese el nombre del nuevo Jugador: ";
		cin >> nombre ;
		nuevoJugador = new Jugador(nombre);
		ListaDeJugadores.agregar(nuevoJugador);
		i++;
	}

	ListaDeJugadores.iniciarCursor();

	while(ListaDeJugadores.avanzarCursor()){
		Jugador* jugadorActual = ListaDeJugadores.obtenerCursor();
		cout << jugadorActual->getNombre() << endl;
	}

	return 0;
}

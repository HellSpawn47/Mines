#ifndef CASILLERO_H
#define CASILLERO_H

#include "typedefs.h"
class Casillero{

	/*
	 * Un casillero es un segmento del tablero. Puede estar oculto, marcado o descubierto y posee un valor que indica cuantas bombas
	 * tiene alrededor o si tiene una bomba dentro.
	 */
	private:

		uint valor;
		uint estado;

	public:

		/*
		 * Post: Se inicializan los atributos (estado = OCULTO, valor = CERO).
		 */
		Casillero();

		/*
		 * Post: El estado del casillero pasa a ser 'DESCUBIERTO'.
		 */
		void descubrir();

		/*
		 * Post: El estado del casillero pasa a ser 'MARCADO'.
		 */
		void marcar();

		/*
		 * Post: Retorna el valor del atributo 'valor'.
		 */
		uint getValor();

		/*
		 * Post: Retorna el valor del atributo 'estado'.
		 */
		uint getEstado();

		/*
		 * Post: Cambia el atributo 'valor' por 'nuevoValor'.
		 */
		void setValor(uint nuevoValor);

		/*
		 * Pre : NuevoEstado debe ser un numero entero positivo.
		 * Post: Cambia el atributo 'estado' por 'nuevoEstado'.
		 */
		void setEstado(uint nuevoEstado);

		/*
		 * Post: Suma '1' al atributo valor.
		 */
		void incrementarValor();

};


#endif /* CASILLERO_H */

#ifndef CASILLERO_H
#define CASILLERO_H

#include "typedefs.h"

class Casillero{

	private:

		uint valor;
		uint estado;

	public:

		/*
		 * pre: Ninguna.
		 * post: Se inicializan los atributos (estado = OCULTO, valor = CERO).
		 *
		 */
		Casillero();

		/*
		 * pre: Ninguna.
		 * post: El estado del casillero pasa a ser 'DESCUBIERTO'.
		 *
		 */
		void descubrir();

		/*
		 * pre:
		 * post: El estado del casillero pasa a ser 'MARCADO'.
		 *
		 */
		void marcar();

		/*
		 * pre:
		 * post: Retorna el valor del atributo 'valor'.
		 *
		 */
		uint getValor();

		/*
		 * pre:
		 * post: Retorna el valor del atributo 'estado'.
		 *
		 */
		uint getEstado();

		/*
		 * pre: nuevoValor debe ser un numero entero positivo.
		 * post: Cambia el atributo 'valor' por 'nuevoValor'.
		 *
		 */
		void setValor(uint nuevoValor);

		/*
		 * pre: nuevoEstado debe ser un numero entero positivo.
		 * post: Cambia el atributo 'estado' por 'nuevoEstado'.
		 *
		 */
		void setEstado(uint nuevoEstado);

		/*
		 * pre:
		 * post: Suma '1' al atributo valor.
		 *
		 */
		void incrementarValor();

};


#endif /* CASILLERO_H */

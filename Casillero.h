#ifndef CASILLERO_H
#define CASILLERO_H

class Casillero{

	private:

		int valor;
		int estado;

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
		int getValor();

		/*
		 * pre:
		 * post: Retorna el valor del atributo 'estado'.
		 *
		 */
		int getEstado();

		/*
		 * pre: nuevoValor debe ser un numero entero positivo.
		 * post: Cambia el atributo 'valor' por 'nuevoValor'.
		 *
		 */
		void setValor(int nuevoValor);

		/*
		 * pre: nuevoEstado debe ser un numero entero positivo.
		 * post: Cambia el atributo 'estado' por 'nuevoEstado'.
		 *
		 */
		void setEstado(int nuevoEstado);

		/*
		 * pre:
		 * post: Suma '1' al atributo valor.
		 *
		 */
		void incrementarValor();

};


#endif /* CASILLERO_H */

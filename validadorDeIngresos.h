/*
 * validadorDeIngresos.h
 *
 *  Created on: 30/10/2017
 *      Author: javier
 */

#ifndef VALIDADORDEINGRESOS_H_
#define VALIDADORDEINGRESOS_H_

class Validador{


	/*
	 * El Validador cumple la funcion de verificar si algun dato recibido se corresponde con otro. En este caso el validador
	 * comprobara que una dificultad recibida sea una de las dificultades constantes, definidas como DIFICIL, MEDIA o FACIL, y tambien
	 * puede validar que una accion recibida sea una de las acciones constantes, definidas como DESCUBRIR o MARCAR.
	 */
public:

	/*
	 * Pre : Recibe la dificultad que ingreso el usuario por teclado.
	 * Post: Si la dificultad que ingreso el usuario es DIFICIL, MEDIA o FACIL devuelve verdadero, sino devuelve falso.
	 */
	bool esDificultadValida (char dificultad);

	/*
	 * Pre : Recibe la accion que ingreso el usuario por teclado.
	 * Post: Si la accion que ingreso el usuario es DESCUBRIR o MARCAR devuelve verdadero, sino devuelve falso.
	 */
	bool esAccionValida (char accion);

};


#endif /* VALIDADORDEINGRESOS_H_ */

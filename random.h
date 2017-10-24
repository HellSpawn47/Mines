#ifndef RANDOM_H
#define RANDOM_H
#include <cstdlib>
#include <ctime>


/*
 * pre: La semilla debe estar inicializada.
 * post: Calcula un numero entero pseudo-aleatorio entre el rango (minimo, maximo).
 *
 */
int numeroAleatorioEntreRango(int minimo, int maximo);

/*
 * pre:
 * post: Prepara la semilla para numeroAleatorioEntreRango() a partir de la hora.
 *
 */
void setearSemillaRandom();

#endif

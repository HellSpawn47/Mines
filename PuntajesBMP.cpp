/*
 * PuntajesBMP.cpp
 *
 *  Created on: 30 oct. 2017
 *      Author: gonzalo
 */

#include "PuntajesBMP.h"
#include <string>
#include <iostream>
#include "Jugador.h"

using namespace std;

PuntajesBMP::PuntajesBMP(){

	SetEasyBMPwarningsOff();

	this->puntaje.SetSize(800,600);

}

void PuntajesBMP::imprimirPuntajes(Lista<Jugador*>* jugador, unsigned int turno)
{
	//BMP puntajes;
	RGBApixel colorFuente;
	Jugador* jugadorAux = NULL;
	char* mensajeFinal, *rutaBMP;
	string mensaje, rtn, simbolo = "", nombreBMP;
	uint j;

	colorFuente.Red = 255; colorFuente.Alpha = 0; colorFuente.Blue = 0; colorFuente.Green = 0;

    //Genero el nombre que tendra el BMP
    for(rtn="";turno>0;rtn.insert(rtn.begin(),turno%10+'0'),turno/=10);

    nombreBMP = "puntajes-turno";
    nombreBMP += rtn;
    nombreBMP += ".bmp";

    rutaBMP = (char *)nombreBMP.c_str();



    this->puntaje.SetSize(800,600);

    for (uint i = 1; i < jugador->contarElementos()+1; i++)
    {
    	jugadorAux = jugador->obtener(i);


        uint puntajeFinal = abs(jugadorAux->getPuntaje());
        simbolo = "";

        if (jugadorAux->getPuntaje() < 0)
        {
            simbolo = "-";
        }

        if (puntajeFinal == 0)
        {
            rtn = "0";
        } else
        {
            for(rtn="";puntajeFinal>0;rtn.insert(rtn.begin(),puntajeFinal%10+'0'),puntajeFinal/=10);
        }

        mensaje = jugadorAux->getNombre();
        mensaje += ": ";
        mensaje += simbolo;
        mensaje += rtn;
        mensaje += " puntos";

        mensajeFinal = (char *)mensaje.c_str();

        PrintString(this->puntaje, mensajeFinal, 5, jugadorAux->getNumeroJugador()*15, 12, colorFuente);
    }


    this->puntaje.WriteToFile(rutaBMP);
}

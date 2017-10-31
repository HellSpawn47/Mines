/*
 * PuntajesBMP.cpp
 *
 *  Created on: 30 oct. 2017
 *      Author: gonzalo
 */

#include "PuntajesBMP.h"
#include <string>
#include <iostream>

using namespace std;

PuntajesBMP::PuntajesBMP(){

	SetEasyBMPwarningsOff();

	this->puntaje.ReadFromFile("puntajes.bmp");

	this->puntaje.SetSize(800,600);

	this->puntaje.WriteToFile("puntajes.bmp");

}

void PuntajesBMP::imprimirPuntajes(std::string nombreJugador, int puntaje, uint posicion)
{
	//BMP puntajes;
	RGBApixel colorFuente;
	char* mensajeFinal;
	string mensaje, rtn, simbolo = "";
	uint puntajeFinal = abs(puntaje);

	colorFuente.Red = 255, colorFuente.Alpha = 0, colorFuente.Blue = 0, colorFuente.Green = 0;

	this->puntaje.ReadFromFile("puntajes.bmp");

	if (puntaje < 0)
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

	mensaje += nombreJugador;
	mensaje += ": ";
	mensaje += simbolo;
	mensaje += rtn;
	mensaje += " puntos";

	mensajeFinal = (char *)mensaje.c_str();

	PrintString(this->puntaje, mensajeFinal, 5, posicion*15, 12, colorFuente);

	this->puntaje.WriteToFile("puntajes.bmp");


}

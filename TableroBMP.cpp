/*
 * TableroBMP.cpp
 *
 *  Created on: 29 oct. 2017
 *      Author: gonzalo
 */

#include "TableroBMP.h"
#include <string>
#include <iostream>

using namespace std;

TableroBMP::TableroBMP(unsigned int filas, unsigned int columnas)
{
	BMP otraImagen;

	this->tamanioPixel = 800/columnas;

	if ((600 / filas) < (800/columnas))
	{
		this->tamanioPixel = 600/filas;
	}

	this->alto = filas;
	this->ancho = columnas;

	this->tablero.SetSize(this->tamanioPixel * this->ancho, this->tamanioPixel * this->alto);

}

TableroBMP::TableroBMP(){


	this->tamanioPixel = 10;
	this->alto = 0;
	this->ancho = 0;
	this->tablero.SetSize(800,600);

}

void TableroBMP::generarTableroInicial ()
{
	BMP otraImagen;

	otraImagen.ReadFromFile("oculta.bmp");

	Rescale(otraImagen, 'W', this->tamanioPixel);
	Rescale(otraImagen, 'H', this->tamanioPixel);

	for (int i = 0; i < (this->tamanioPixel * this->alto) + 1; i = i + this->tamanioPixel)
	{
		for (int j = 0; j < (this->tamanioPixel * this->ancho) + 1; j = j + this->tamanioPixel)
		{
			RangedPixelToPixelCopy(otraImagen,0,this->tamanioPixel,0,this->tamanioPixel,this->tablero,j,i);
		}
	}

	//this->tablero.WriteToFile("tablero.bmp");

}

void TableroBMP::completarConJugada(unsigned int fila, unsigned int columna, unsigned int valor)
{
	BMP imagen;

	switch (valor)
	{
		case 1:

			imagen.ReadFromFile("uno.bmp");
			break;

		case 2:

			imagen.ReadFromFile("dos.bmp");
			break;

		case 3:

			imagen.ReadFromFile("tres.bmp");
			break;

		case 4:

			imagen.ReadFromFile("cuatro.bmp");
			break;

		case 5:

			imagen.ReadFromFile("cinco.bmp");
			break;

		case 6:

			imagen.ReadFromFile("seis.bmp");
			break;

		case 7:

			imagen.ReadFromFile("siete.bmp");
			break;

		case 8:

			imagen.ReadFromFile("ocho.bmp");
			break;

		case 'B':

			imagen.ReadFromFile("mina.bmp");
			break;

		default:

			imagen.ReadFromFile("descubierta.bmp");
			break;
	}

	Rescale(imagen, 'W', this->tamanioPixel);
	Rescale(imagen, 'H', this->tamanioPixel);

	RangedPixelToPixelCopy(imagen, 0, this->tamanioPixel, 0, this->tamanioPixel, this->tablero, columna * this->tamanioPixel, fila * this->tamanioPixel);

}

void TableroBMP::completarConBandera(unsigned int fila, unsigned int columna)
{
	BMP bandera;

	bandera.ReadFromFile("bandera.bmp");

	Rescale(bandera, 'W', this->tamanioPixel);
	Rescale(bandera, 'H', this->tamanioPixel);

	RangedPixelToPixelCopy(bandera, 0, this->tamanioPixel, 0, this->tamanioPixel, this->tablero, columna * this->tamanioPixel, fila * this->tamanioPixel);

}

void TableroBMP::completarCasilleroOculto(unsigned int fila, unsigned int columna)
{
	BMP oculto;

	oculto.ReadFromFile("oculta.bmp");

	Rescale(oculto, 'W', this->tamanioPixel);
	Rescale(oculto, 'H', this->tamanioPixel);

	RangedPixelToPixelCopy(oculto, 0, this->tamanioPixel, 0, this->tamanioPixel, this->tablero, columna * this->tamanioPixel, fila * this->tamanioPixel);
}

void TableroBMP::imprimirTablero(uint turno)
{
	string rtn, ruta;
	char* nombreBMP;

	for(rtn="";turno>0;rtn.insert(rtn.begin(),turno%10+'0'),turno/=10);

    ruta += "tablero-partida1-turno";
    ruta += rtn;
    ruta += ".bmp";

    nombreBMP = (char *)ruta.c_str();

	this->tablero.WriteToFile(nombreBMP);
}

void TableroBMP::imprimirPuntajes(std::string nombreJugador, int puntaje, uint posicion)
{
	BMP puntajes;
	RGBApixel colorFuente;
	char* mensajeFinal;
	string mensaje, rtn, simbolo = "";
	uint puntajeFinal = abs(puntaje);

	colorFuente.Red = 255, colorFuente.Alpha = 0, colorFuente.Blue = 0, colorFuente.Green = 0;

	if (!puntajes.ReadFromFile("puntajes.bmp"))
	{
		puntajes.SetSize(800,600);
		puntajes.WriteToFile("puntajes.bmp");
	}

	puntajes.ReadFromFile("puntajes.bmp");

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

	PrintString(puntajes, mensajeFinal, 5, posicion*15, 12, colorFuente);

	puntajes.WriteToFile("puntajes.bmp");


}



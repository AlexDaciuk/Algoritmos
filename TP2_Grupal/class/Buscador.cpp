#ifndef BUSCADOR_H
#define BUSCADOR_H

#ifndef NULL
#define NULL 0
#endif

#include "Buscador.h"

Buscador::Buscador(Lista<Central>* centrales)
{
	this->centralesTotales = centrales;
	this->mejorCamino = new Lista<Enlace*>*;
	this->rutaActual = new Lista<Spot>*;
	this->precioDeLaLlamada= 0;
	this->distanciaDeLaLlamada = 0;
}

Lista<Enlace*>* Buscador::obtenerRuta()
{
	return (this->mejorCamino);
}

int Buscador::obtenerPrecioDeLaLlamada()
{
	return (this->precioDeLaLlamada);
}

int Buscador::obtenerDistanciaDeLaLlamada()
{
	return (this->distanciaDeLaLlamada);
}

void Buscador::encontrarCaminoPorPrecio(int centralEmisora, int centralReceptora, int emisor, int receptor)
{
	
	Central* centralActual = this->encontrarLaCentral(centralEmisora);
	this->rutaActual->insertar(Spot spot(centralActual, 0, 0));
	if (this->esLlamadaInterna(centralEmisora, centralReceptora))
	{
		this->definirEstePrecioYDistancia();
		this->rutaActual = NULL;
		this->mejorCamino = NULL;
	}
	else
	{
		this->rutaActual->iniciarCursorNodo();
		this->rutaActual->avanzarCursorNodo();
		int mejorPrecio = this->rutaActual->obtenerCursorNodo()->obtenerPrecioHastaSpot;
		while((this->precioDeLaLlamada > mejorPrecio) || (this->precioDeLaLlamada == 0))
		{
			Lista<Enlace*>* enlacesActuales = centralActual->obtenerEnlaces();
		}
	}
}

void Buscador::encontrarCaminoPordistancia(int centralEmisora, int centralReceptora, int emisor, int receptor)
{
	
}

Central* Buscador::encontrarLaCentral(int central)
{
	this->centralesTotales->iniciarCursorNodo();
	while(this->centralesTotales->avanzarCursorNodo())
	{
		if(this->centralesTotales->obtenerCursorNodo()->obtenerNumero == central)
			return(this->centralesTotales->obtenerCursorNodo());
	}
}

bool Buscador::indicaSiPasePorLaCentral(Central* central)
{
	laEncontre=true;
	this->rutaActual->iniciarCursorNodo();
	while((this->rutaActual->avanzarCursorNodo()) && (!laEncontre))
	{
		if(this->rutaActual->obtenerCursorNodo()->visitasteLacentral(central))
			return(laEncontre);
	}
	return(!laEncontre);
}

bool Buscador::esLlamadaInterna(int centralEmisora, int centralReceptora)
{
	return(centralEmisora == centralReceptora);
}

Interno* Buscador::encontrarInternoEnLa(Central* central, int numeroDeInterno)
{
	return(central->obtenerInterno(numeroDeInterno));
}

void Buscador::definirEstePrecioYDistancia()
{
	this->rutaActual->iniciarCursorNodo();
	this->rutaActual->avanzarCursorPorElFinal();
	this->precioDeLaLlamada = this->rutaActual->obtenerCursorNodo()->obtenerPrecioHastaSpot();
	this->distanciaDeLaLlamada = this->rutaActual->obtenerCursorNodo()->obtenerDistanciaRecorrida();
}
	  

#endif

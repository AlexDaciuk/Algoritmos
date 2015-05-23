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
	this->precioDeLaLlamada= -1;
}

Lista<Enlace*>* Buscador::obtenerRuta()
{
	return (this->mejorCamino);
}

int Buscador::obtenerprecioDeLaLlamada()
{
	return (this->precioDeLaLlamada);
}

void Buscador::encontrarCaminoPorPrecio(int centralEmisora, int centralReceptora, int emisor, int receptor)
{
	
	Central* centralActual = this->encontrarLaCentral(centralEmisora);
	this->rutaActual->insertar(Spot spot(centralActual->obtenerNumero(), 0));
	if (this->esLlamadaInterna(centralEmisora, centralReceptora))
	{
		this->precioDeLaLlamada = 0;
		this->rutaActual = NULL;
		this->mejorCamino = NULL;
	}
	else
	{
		while(this->precioDeLaLlamada > )
		Enlace* enlacesActuales = centralActual->obtenerEnlaces();
		
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
	return(central->obtenerPunteroAInterno(numeroDeInterno));
}

#endif

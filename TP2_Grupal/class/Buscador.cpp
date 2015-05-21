#ifndef BUSCADOR_H
#define BUSCADOR_H

#ifndef NULL
#define NULL 0
#endif

#include "Internos.h"
#include "Buscador.h"
#include "Lista.h"
#include "Enlace.h"
#include "Central.h"
#include "Spot.h"

Buscador::Buscador(Lista<Central>* centrales)
{
	this->centralesTotales = centrales;
	this->mejorCamino = new Lista<Enlace*>*;
	this->rutaActual = new Lista<Spot>*;
	this->valorDelCamino= 0;
}

Lista<Enlace*>* Buscador::obtenerRuta()
{
	return (this->mejorCamino);
}

int Buscador::obtenerValorDelCamino()
{
	return (this->valorDelCamino);
}

Central* Buscador::obtenerCentralEmisora( int emisor)
{
	this->mejorCamino->iniciarCursorNodo();
	this->mejorCamino->avanzarCursorNodo();
	Enlace* enlace = this->mejorCamino->obtenerCursorNodo();
	if(enlace->obtenerDestino()->obtenerNumero() == emisor)
		return (enlace->obtenerDestino());
	else	
	    return (enlace->obtenerOrigen());
}

Central* Buscador::obtenerCentralReceptora(int receptor)
{
	this->mejorCamino->iniciarCursorNodo();
	this->mejorCamino->avanzarCursorPorElFinal();
	Enlace* enlace = this->mejorCamino->obtenerCursorNodo();
	if(enlace->obtenerDestino()->obtenerNumero() == receptor)
		return (enlace->obtenerDestino());
	else	
	    return (enlace->obtenerOrigen());
} 

void Buscador::encontrarCaminoPorPrecio(int centralEmisora, int centralReceptora, int emisor, int receptor)
{
	if (this->esLlamadaInterna(centralEmisora, centralReceptora))
		//pongo valordecamino 0, punteros a NULL
}

void Buscador::encontrarCaminoPordistancia(int centralEmisora, int centralReceptora, int emisor, int receptor)
{
	
}

Central* Buscador::encontrarCentralDeEmision(Lista<Central>* centrales, int centralEmisora)
{
	
}

bool Buscador::indicaSiPasePorLaCentral(Central* central)
{
	
}

bool Buscador::esLlamadaInterna(int centralEmisora, int centralReceptora)
{
	
}

Interno* Buscador::encontrarInternoEnLa(Central* central, int numeroDeInterno)
{
	
}

#endif

#ifndef BUSCADOR_H
#define BUSCADOR_H

#ifndef NULL
#define NULL 0
#endif

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

Central* Buscador::obtenerCentralEmisora(int centralEmisora)
{
	this->mejorCamino->
}
obtenerPunteroAlObjeto(centralEmisora)
Central* Buscador::obtenerCentralReceptora()
{
	
} 


#endif

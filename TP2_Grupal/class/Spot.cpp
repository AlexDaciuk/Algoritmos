#ifndef LISTA_H_
#define LISTA_H_

#ifndef NULL
#define NULL 0
#endif

#include "Spot.h"

Spot::Spot(Central* posicion, int precioHastaSpot, int distanciaHastaSpot)
{
	this->precioHastaSpot = precioHastaSpot;
	this->distanciaHastaSpot = distanciaHastaSpot;
	this->posicion = posicion;
	this->enlaceRecorrido = NULL;
	this->centralesVisitadas= new Lista<Central*>*;
}

void Spot::anotarCaminoRecorrido(Central* CentralAVisitar, Enlace* enlaceRecorrido)
{
	this->centralesVisitadas->insertar(CentralAVisitar);
	this->enlaceRecorrido = enlaceRecorrido;
}

bool Spot::visitasteLacentral(Central* centralAVisitar)
{
	laEncontre=false;
	this->centralesVisitadas->iniciarCursorNodo();
	while((this->centralesVisitadas->avanzarCursorNodo()) && (!laEncontre))
	{
		Central* centralActual=this->centralesVisitadas->obtenerCursorNodo();
		if(centralActual->obtenerNumero() == centralAVisitar->obtenerNumero())
			laEncontre=true;
	}
	return(laEncontre);
}

int Spot::obtenerPrecioHastaSpot()
{
	return(this->precioHastaSpot);
}

int Spot::obtenerDistanciaRecorrida()
{
	return(this->distanciaHastaSpot);
}

Spot::~Spot()
{
	delete centralesVisitadas;
}
#endif
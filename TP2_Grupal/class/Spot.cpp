
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
	this->centralesVisitadas= new Lista<Central*>;
}

Central* Spot::obtenerPosicion()
{
	return (this->posicion);
}

void Spot::anotarCaminoRecorrido(Central* CentralAVisitar, Enlace* enlaceRecorrido)
{
	this->centralesVisitadas->insertar(CentralAVisitar);
	this->enlaceRecorrido = enlaceRecorrido;
}

bool Spot::visitasteLacentral(Central* centralAVisitar)
{
	bool laEncontre=false;
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

bool Spot::recorriTodosLosEnlaces()
{
	bool losRecorri = true;
	Lista<Enlace*>* enlacesDisponibles = this->obtenerPosicion()->obtenerEnlaces();
	enlacesDisponibles->iniciarCursorNodo();
	while((enlacesDisponibles->avanzarCursorNodo())&& (losRecorri))
	{
		Enlace* enlaceActual = enlacesDisponibles->obtenerCursorNodo();
		if (enlaceActual->obtenerDestino()->obtenerNumero() != this->obtenerPosicion()->obtenerNumero())
		{
			if(!this->visitasteLacentral(enlaceActual->obtenerDestino()))
				losRecorri = false;
		}
		else
		{
			if(!this->visitasteLacentral(enlaceActual->obtenerOrigen()))
				losRecorri = false;
		}
	}
	return (losRecorri);
}

Enlace* Spot::obtenerEnlaceRecorrido()
{
	return (this->enlaceRecorrido); 
}

Spot::~Spot()
{
	delete (this->centralesVisitadas);
}

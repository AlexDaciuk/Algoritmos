#include "Spot.h"

#ifndef NULL
#define NULL 0
#endif


Spot::Spot(Central* posicion, int precioHastaSpot, int distanciaHastaSpotTemporal)
{
	this->precioHastaSpot = precioHastaSpot;
	this->distanciaHastaSpot = distanciaHastaSpotTemporal;
	this->posicion = posicion;
	this->centralesVisitadas= new Lista<Central*>;
	this->enlacesARecorrer = posicion->obtenerEnlaces();
	this->enlacesARecorrer->iniciarCursorNodo();
	this->hayMasEnlaces = true;
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
	if(this->posicion->obtenerNumero() == centralAVisitar->obtenerNumero()) {
		laEncontre = true;
	} else {
		while((this->centralesVisitadas->avanzarCursorNodo()) && (!laEncontre)) {
			Central* centralActual=this->centralesVisitadas->obtenerCursorNodo();
			if(centralActual->obtenerNumero() == centralAVisitar->obtenerNumero())
				laEncontre=true;
		}
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
	while((enlacesDisponibles->avanzarCursorNodo()) && (losRecorri)) {
		Enlace* enlaceActual = enlacesDisponibles->obtenerCursorNodo();
		if (enlaceActual->obtenerDestino()->obtenerNumero() != this->obtenerPosicion()->obtenerNumero()) {
			if(!this->visitasteLacentral(enlaceActual->obtenerDestino()))
				losRecorri = false;
		} else {
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

Enlace* Spot::obtenerEnlaceSiguiente()
{
	return(this->enlacesARecorrer->obtenerCursorNodo());
}

bool Spot::VerSiHayMasEnlaces()
{
	return(this->enlacesARecorrer->avanzarCursorNodo());
}

Spot::~Spot()
{
	delete (this->centralesVisitadas);
}

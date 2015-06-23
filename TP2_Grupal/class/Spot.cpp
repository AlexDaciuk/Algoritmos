#include "Spot.h"
#ifndef NULL
#define NULL 0
#endif

Spot::Spot(Central* posicion, int precioHastaSpot, int distanciaHastaSpotTemporal)
{
	this->precioHastaSpot = precioHastaSpot;
	this->distanciaHastaSpot = distanciaHastaSpotTemporal;
	this->posicion = posicion;
	this->centralesVisitadas = new Lista<Central*>;
	this->enlacesARecorrer = posicion->obtenerEnlaces();
	this->hayMasEnlaces = true;
	this->enlacesRecorridos = new Lista<Enlace*>;
}

Central* Spot::obtenerPosicion()
{
	return (this->posicion);
}

Lista<Enlace*>* Spot::obtenerEnlacesARecorrer()
{
	return this->enlacesARecorrer;
}

void Spot::anotarCaminoRecorrido(Central* CentralAVisitar, Enlace* enlaceRecorrido)
{
	this->centralesVisitadas->insertar(CentralAVisitar);
	this->enlacesRecorridos->insertar(enlaceRecorrido);
}

bool Spot::visitasteLaCentral(Central* centralAVisitar)
{
	bool laEncontre = false;
	this->centralesVisitadas->iniciarCursorNodo();

	while ((this->centralesVisitadas->avanzarCursorNodo()) && (!laEncontre)) {
		Central* centralActual = this->centralesVisitadas->obtenerCursorNodo();
		if ((centralActual->obtenerNumero() == centralAVisitar->obtenerNumero()) || (centralAVisitar == this->posicion))
			laEncontre = true;
	}
	return (laEncontre);
}

bool Spot::visiteLaCentral(Central* centralAVisitar)
{
	bool laEncontre = false;
	this->centralesVisitadas->iniciarCursorNodo();
	while ((this->centralesVisitadas->avanzarCursorNodo()) && (!laEncontre)) {
		Central* centralActual = this->centralesVisitadas->obtenerCursorNodo();
		if (centralActual->obtenerNumero() == centralAVisitar->obtenerNumero())
			laEncontre = true;
	}
	return (laEncontre);
}

int Spot::obtenerPrecioHastaSpot()
{
	return (this->precioHastaSpot);
}

int Spot::obtenerDistanciaRecorridaHastaSpot()
{
	return (this->distanciaHastaSpot);
}

bool Spot::recorriTodosLosEnlaces()
{
	bool losRecorri = true;
	Lista<Enlace*>* enlacesDisponibles = this->obtenerPosicion()->obtenerEnlaces();
	enlacesDisponibles->iniciarCursorNodo();
	while ((enlacesDisponibles->avanzarCursorNodo()) && (losRecorri)) {
		Enlace* enlaceActual = enlacesDisponibles->obtenerCursorNodo();
		if (enlaceActual->obtenerDestino()->obtenerNumero() != this->obtenerPosicion()->obtenerNumero()) {
			if (!this->visiteLaCentral(enlaceActual->obtenerDestino()))
				losRecorri = false;
		} else {
			if (!this->visiteLaCentral(enlaceActual->obtenerOrigen()))
				losRecorri = false;
		}
	}
	return (losRecorri);
}

Enlace* Spot::obtenerEnlaceRecorrido()
{
	this->enlacesRecorridos->iniciarCursorNodo();
	this->enlacesRecorridos->avanzarCursorNodo();
	return (this->enlacesRecorridos->obtenerCursorNodo());
}

Enlace* Spot::obtenerEnlaceSiguiente()
{
	return (this->posicionarmeEnUltimoEnlace());
}

void Spot::resetListaEnlaces()
{
	this->enlacesARecorrer->iniciarCursorNodo();
}

bool Spot::VerSiHayMasEnlaces()
{
	return (this->enlacesARecorrer->avanzarCursorNodo());
}

Enlace* Spot::posicionarmeEnUltimoEnlace()
{
	bool mePosicione = false;
	Enlace* posicionEnlace;
	Enlace* enlaceActual;
	Lista<Enlace*>* enlacesDelSpot = this->obtenerPosicion()->obtenerEnlaces();
	this->enlacesRecorridos->iniciarCursorNodo();
	if (this->enlacesRecorridos->avanzarCursorNodo()) {
		enlacesDelSpot->iniciarCursorNodo();
		while ((!mePosicione) && (enlacesDelSpot->avanzarCursorNodo())) {
			enlaceActual = enlacesDelSpot->obtenerCursorNodo();
			mePosicione = true;
			this->enlacesRecorridos->iniciarCursorNodo();
			while ((mePosicione) && (this->enlacesRecorridos->avanzarCursorNodo())) {
				posicionEnlace = this->enlacesRecorridos->obtenerCursorNodo();
				if ((enlaceActual->obtenerDestino() == posicionEnlace->obtenerDestino()) &&
				    (enlaceActual->obtenerOrigen() == posicionEnlace->obtenerOrigen())) {
					mePosicione = false;
				}
			}
		}
	} else {
		enlacesDelSpot->iniciarCursorNodo();
		enlacesDelSpot->avanzarCursorNodo();
	}
	return enlacesDelSpot->obtenerCursorNodo();
}

Spot::~Spot()
{
	delete (this->centralesVisitadas);
}

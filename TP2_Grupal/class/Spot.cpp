#include "Spot.h"
#include <iostream>
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
	bool laEncontre=false;
	this->centralesVisitadas->iniciarCursorNodo();
	
		while((this->centralesVisitadas->avanzarCursorNodo()) && (!laEncontre)) {
			Central* centralActual=this->centralesVisitadas->obtenerCursorNodo();
			if((centralActual->obtenerNumero() == centralAVisitar->obtenerNumero()) && (centralAVisitar == this->posicion))
				laEncontre=true;
		}
	
	return(laEncontre);
}

bool Spot::visiteLaCentral(Central* centralAVisitar)
{
	bool laEncontre=false;
	this->centralesVisitadas->iniciarCursorNodo();
	while((this->centralesVisitadas->avanzarCursorNodo()) && (!laEncontre)) {
			Central* centralActual=this->centralesVisitadas->obtenerCursorNodo();
			std::cout<<"La central comparacion en el spot "<<this->posicion->obtenerNumero()<<" de visiteLaCentral es: "<<centralActual->obtenerNumero()<<"\n";
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
	while((enlacesDisponibles->avanzarCursorNodo()) && (losRecorri)) {
		Enlace* enlaceActual = enlacesDisponibles->obtenerCursorNodo();
		if (enlaceActual->obtenerDestino()->obtenerNumero() != this->obtenerPosicion()->obtenerNumero()) {
			if(!this->visiteLaCentral(enlaceActual->obtenerDestino()))
				losRecorri = false;
		} else {
			if(!this->visiteLaCentral(enlaceActual->obtenerOrigen()))
				losRecorri = false;
		}
	}
	//this->posicionarmeEnUltimoEnlace();
	std::cout<<"recorriTodosLosEnlaces dice :"<<losRecorri<<"\n";
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
	return(this->posicionarmeEnUltimoEnlace());
}

void Spot::resetListaEnlaces()
{
	this->enlacesARecorrer->iniciarCursorNodo();
}

bool Spot::VerSiHayMasEnlaces()
{
	return(this->enlacesARecorrer->avanzarCursorNodo());
}

Enlace* Spot::posicionarmeEnUltimoEnlace()
{
	bool mePosicione = false;
	Enlace* posicionEnlace;
	Enlace* enlaceActual;
	Lista<Enlace*>* enlacesDelSpot = this->obtenerPosicion()->obtenerEnlaces();
	this->enlacesRecorridos->iniciarCursorNodo();
	if(this->enlacesRecorridos->avanzarCursorNodo()){
			enlacesDelSpot->iniciarCursorNodo();
			std::cout<<"entre a posicionarme :\n";
			while((!mePosicione) && (enlacesDelSpot->avanzarCursorNodo()) )
			{
				std::cout<<"I\n";
				 enlaceActual = enlacesDelSpot->obtenerCursorNodo();
				 mePosicione = true;
				 this->enlacesRecorridos->iniciarCursorNodo();
				 while((mePosicione) && (this->enlacesRecorridos->avanzarCursorNodo())){
					 posicionEnlace = this->enlacesRecorridos->obtenerCursorNodo();
					if((enlaceActual->obtenerDestino() == posicionEnlace->obtenerDestino()) &&
					(enlaceActual->obtenerOrigen() == posicionEnlace->obtenerOrigen()))
					{
							mePosicione = false;
							std::cout<<"era el de antes \n";
					}
				}
			}
			//if((mePosicione) && (enlacesDelSpot->avanzarCursorNodo()))
				//return enlacesDelSpot->obtenerCursorNodo();
	}
	else 
	{
		enlacesDelSpot->iniciarCursorNodo();
		enlacesDelSpot->avanzarCursorNodo();
		std::cout<<"recorro el primer enlace\n";
	}
	std::cout<<"El destino del enlace es :"<<enlacesDelSpot->obtenerCursorNodo()->obtenerDestino()->obtenerNumero() <<"\n";
	std::cout<<"El origen del enlace es :"<<enlacesDelSpot->obtenerCursorNodo()->obtenerOrigen()->obtenerNumero() <<"\n";
	return enlacesDelSpot->obtenerCursorNodo();
}

Spot::~Spot()
{
	delete (this->centralesVisitadas);
}

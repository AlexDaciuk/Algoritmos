#include "Recorrido.h"

Recorrido::Recorrido(Lista<Enlace*>* camino)
{
	this->centralLlegada=0;
	this->camino = camino;
	this->precio=32768;
}


void Recorrido::definirPrecioRecorrido(unsigned int nuevoPrecio)
{
	this->precio = nuevoPrecio;
}


void Recorrido::definirCentralDeLlegada(unsigned int nuevaCentral)
{
	if (nuevaCentral > 0 && nuevaCentral <= 9999) {
		this->centralLlegada = nuevaCentral;
	}
}


void Recorrido::definirCamino(Lista<Enlace*>* mejorCamino)
{
	this->camino = mejorCamino;
}


int Recorrido::obtenerPrecioRecorrido()
{
	return this->precio;
}


int Recorrido::obtenerCentralDeLlegada()
{
	return this->centralLlegada;
}


Lista<Enlace*>* Recorrido::obtenerEnlacesRecorridos()
{
	return this->camino;
}

Recorrido::~Recorrido()
{
	delete this->camino;
}

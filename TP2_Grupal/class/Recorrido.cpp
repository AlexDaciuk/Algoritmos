#include "Recorrido.h"

Recorrido::Recorrido()
{
	this->centralLlegada=0;
	this->enlacesRecorridos = new Lista<Enlace*>;
	this->precio=32768;
}


void Recorrido::definirPrecioRecorrido(unsigned int nuevoPrecio)
{
	this->precio = nuevoPrecio;
}


void Recorrido::definirCentralDeLlegada(unsigned int nuevaCentral)
{
	if (nuevaCentral > 0 && nuevaCentral =< 9999) {
		this->centralLlegada = nuevaCentral;
	}
}


void Recorrido::agregarEnlaceRecorrido(Enlace* enlaceAAgregar)
{
	this->enlacesRecorrido->insertar(enlaceAAgregar);
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
	return this->enlacesRecorridos;
}

Recorrido::~Recorrido()
{
	delete this->enlacesRecorridos;
}

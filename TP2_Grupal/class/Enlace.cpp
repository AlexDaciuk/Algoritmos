#include "Enlace.h"


Enlace::Enlace(int origenTemporal, int destinoTemporal, int distanciaTemporal, int cantidadCanalesTemporal, int CostoPorMinutoTemporal, Lista<Central*>* centralesTemporal)
{
	this->cantidadDeCanales = cantidadCanalesTemporal;
	this->distanciaKm = distanciaTemporal;
	this->costoPorMinuto = CostoPorMinutoTemporal;
	this->cantidadCanalesEnUso = 0;
	this->centrales = centralesTemporal;
	this->destino = centralesTemporal->obtenerPunteroAlObjeto(destinoTemporal)->obtenerObjeto();
	this->origen = centralesTemporal->obtenerPunteroAlObjeto(origenTemporal)->obtenerObjeto();
}


int Enlace::obtenerNumeroDeCanales()
{
	return(this->cantidadDeCanales);
}


int Enlace::obtenerDistancia()
{
	return(this->distanciaKm);
}


int Enlace::obtenerPrecio()
{
	return(this->costoPorMinuto);
}


int Enlace::obtenerCantidadEnlacesEnUso()
{
	return(this->cantidadCanalesEnUso);
}


Central* Enlace::obtenerOrigen()
{
	return(origen);
}


Central* Enlace::obtenerDestino()
{
	return(this->destino);
}


bool Enlace::chequearDisponibilidadCanales()
{
	return (this->cantidadCanalesEnUso < this->cantidadDeCanales);
}


void Enlace::agregarLlamadaEnCurso()
{
	if ( this->chequearDisponibilidadCanales() ) {
		this->cantidadCanalesEnUso++;
	}
}


void Enlace::eliminarLlamadaEnCurso()
{
	if (this->cantidadCanalesEnUso > 0) {
		this->cantidadCanalesEnUso--;
	}
}

#include "Enlace.h"


Enlace::Enlace(int origenTemporal, int destinoTemporal, int distanciaTemporal, int cantidadCanalesTemporal, int CostoPorMinutoTemporal, Lista<Central*>* centralesTemporal)

{
	this->cantidadDeCanales = cantidadCanalesTemporal;
	this->distanciaKm = distanciaTemporal;
	this->costoPorMinuto = CostoPorMinutoTemporal;
	this->cantidadCanalesEnUso = 0;
	this->centrales = centralesTemporal;
	this->destino = centrales->obtenerPunteroAlObjeto(destinoTemporal);
	this->origen = centrales->obtenerPunteroAlObjeto(origenTemporal);
}

int Enlace::obtenerOrigen()
{
	return ( origen->obtenerNumero() );
}

int Enlace::obtenerNumeroDeCanales()
{
	return (this->cantidadDeCanales);
}

int Enlace::obtenerDistancia()
{
	return (this->distanciaKm);
}

int Enlace::obtenerPrecio()
{
	return (this->costoPorMinuto);
}

int Enlace::obtenerCantidadEnlacesEnUso()
{
	return (this->cantidadCanalesEnUso);
}

Central* Enlace::obtenerOrigen()
{
	return (this->origen);
}

Central* Enlace::obteneroDestino()
{
	return (this->destino);
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

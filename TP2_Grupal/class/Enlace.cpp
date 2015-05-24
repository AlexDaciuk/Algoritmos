#include "Enlace.h"



Enlace::Enlace(int OrigenTemporal, int DestinoTemporal, int distanciaTemporal, int cantidadCanalesTemporal, int costoPorMinutoTemporal)

{
  this->cantidadDeCanales = cantidadCanalesTemporal;
  this->distaciaKm = distanciaTemporal;
  this->costoPorMinuto = costoPorMinutoTemporal;
  this->cantidadCanalesEnUso = 0;
  this->punteroDestino = ListaCentrales->obtenerPunteroAlObjeto(DestinoTemporal);
  this->punteroOrigen = ListaCentrales->obtenerPunteroAlObjeto(OrigenTemporal);

}

int Enlace::obtenerOrigen()
{
  return (Origen->Central);
}


int Enlace::obtenerDistancia()
{
  return this->distanciaKm;
}

int Enlace::obtenerPrecio()
{
  return this->costoPorMinuto;
}

int Enlace::obtenerCantidadEnlacesEnUso()
{
  return this->cantidadCanalesEnUso;
}


Central* Enlace::obtenerOrigen()
{
  return this->Origen;
}

Central* Enlace::obteneroDestino()
{
  return this->Destino;
}

bool Enlace::chequearDisponibilidadCanales()
{
	return (this->cantidadCanalesEnUso < this->cantidadDeCanales);
}


void Enlace::agregarLlamadaEnCurso()
{
  if ( this->chequearDisponibilidad() )
    {
      this->cantidadCanalesEnUso++
    }

}

void Enlace::eliminarLlamadaEnCurso()
{
  if (this->cantidadCanalesEnUso > 0)
    {
      this->cantidadCanalesEnUso--;
    }
}

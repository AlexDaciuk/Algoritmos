#include "Enlace.h"


Enlace::Enlace(int centralATemporal, int DestinoTemporal, int distanciaTemporal, int cantidadCanalesTemporal, int costoPorMinutoTemporal)
{
  this->cantidadDeCanales=cantidadCanalesTemporal;
  this->distaciaKm=distanciaTemporal;
  this->costoPorMinuto=costoPorMinutoTemporal;
  this->cantidadCanalesEnUso=0;
  this->punteroCentralA = ListaCentrales->obtenerPunteroAlObjeto(centralATemporal);
  this->punteroDestino = ListaCentrales->obtenerPunteroAlObjeto(DestinoTemporal);
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
  bool disponibleTemporal = false;
  
  if (this->cantidadCanalesEnUso < this->cantidadDeCanales)
    {
      disponibleTemporal = true;
    }

  return (disponibleTemporal);
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

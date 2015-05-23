#include "Enlace.h"


<<<<<<< Updated upstream
Enlace::Enlace(int centralATemporal, int DestinoTemporal, int distanciaTemporal, int cantidadCanalesTemporal, int costoPorMinutoTemporal)
=======
Enlace::Enlace(int OrigenTemporal, int centralBTemporal, int distanciaTemporal, int cantidadCanalesTemporal, int costoPorMinutoTemporal)
>>>>>>> Stashed changes
{
  this->cantidadDeCanales=cantidadCanalesTemporal;
  this->distaciaKm=distanciaTemporal;
  this->costoPorMinuto=costoPorMinutoTemporal;
  this->cantidadCanalesEnUso=0;
<<<<<<< Updated upstream
  this->punteroCentralA = ListaCentrales->obtenerPunteroAlObjeto(centralATemporal);
  this->punteroDestino = ListaCentrales->obtenerPunteroAlObjeto(DestinoTemporal);
}

=======
  this->punteroOrigen = ListaCentrales->obtenerPunteroAlObjeto(OrigenTemporal);
  this->punteroCentralB = ListaCentrales->obtenerPunteroAlObjeto(centralBTemporal);
}

int Enlace::obtenerOrigen()
{
  return (punteroOrigen->Central);
}

int Enlace::obtenerCentralB()
{
  return (punteroCentralB->Central);
}
>>>>>>> Stashed changes

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

<<<<<<< Updated upstream
Central* Enlace::obtenerOrigen()
{
  return this->Origen;
=======
Central* Enlace::obtenerPunteroOrigen()
{
  return this->punteroOrigen;
>>>>>>> Stashed changes
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

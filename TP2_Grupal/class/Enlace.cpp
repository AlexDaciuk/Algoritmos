#include "Enlace.h"


Enlace::Enlace(int centralATemporal, int centralBTemporal, int distanciaTemporal, int cantidadCanalesTemporal, int costoPorMinutoTemporal)
{
  this->cantidadDeCanales=cantidadCanalesTemporal;
  this->distaciaKm=distanciaTemporal;
  this->costoPorMinuto=costoPorMinutoTemporal;
  this->cantidadCanalesEnUso=0;
  this->punteroCentralA = ListaCentrales->obtenerPunteroAlObjeto(centralATemporal);
  this->punteroCentralB = ListaCentrales->obtenerPunteroAlObjeto(centralBTemporal);
}

int Enlace::obtenerCentralA()
{
  return (punteroCentralA->Central);
}

int Enlace::obtenerCentralB()
{
  return (punteroCentralB->Central);
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

Central* Enlace::obtenerPunteroCentralA()
{
  return this->punteroCentralA;
}

Central* Enlace::obtenerPunteroCentralB()
{
  return this->punteroCentralB;
}

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

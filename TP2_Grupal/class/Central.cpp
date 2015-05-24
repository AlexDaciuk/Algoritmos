#include "Central.h"

Central::Central(int numeroCentralTemporal)
{
  this->NumeroCentral= numeroCentralTemporal;
  this->internos = new Lista<Internos>;
  this->enlaces = new Lista<Enlaces*>*;
};

void Central::crearInterno(int numeroInterno)
{
  Interno internoTemporal(numeroInterno);
  if ( (this->internos->primerNodo == NULL) || (this->internos->obtenerPunteroAlObjeto(numeroInterno) == NULL) )
    {
      this->internos->Insertar(internoTemporal);
    }
}

Interno* Central::obtenerPunteroAInterno(int numeroInterno)
{
  return this->internos->obtenerPunteroAlObjeto(numeroIterno);
};

Lista<Interno>* Central::obtenerInternos()
{
	return(this->internos);
}

Lista<Enlace>* Central::obtenerEnlaces()
{
	return(this->enlaces);
}

int Central::obtenerNumero()
{
  return this->NumeroCentral;
};

~Central()
{
  delete this->internos;
  delete this->enlaces;
};
		

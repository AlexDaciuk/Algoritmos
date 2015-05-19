#include "Central.h"

Central::Central(int numeroCentralTemporal)
{
  this->NumeroCentral= numeroCentralTemporal;
  this->listaInternos = new Lista<Internos>;
  this->listaEnlaces = new Lista<Enlaces*>;
};

void Central::crearInterno(int numeroInterno)
{
  Interno internoTemporal(numeroInterno);
  if ( (this->listaInternos->primerNodo == NULL) || (this->listaInternos->obtenerPunteroAlObjeto(numeroInterno) == NULL) )
    {
      this->listaInternos->Insertar(internoTemporal);
    }
}

Interno* Central::obtenerPunteroAInterno(int numeroInterno)
{
  return this->listaInternos->obtenerPunteroAlObjeto(numeroIterno);
};


int Central::obtenerNumero()
{
  return this->NumeroCentral;
};

~Central()
{
  delete this->listaInternos;
  delete this->listaInternos;
};
		

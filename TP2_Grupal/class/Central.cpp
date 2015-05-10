#include "Central.h"
#include "Internos.h"
#include "Lista.h"

Central::Central(int numeroCentralTemporal)
{
	
  this->Central= numeroCentralTemporal;
  this->listaInternos = new Lista<Interno>;
  this->listaEnlaces = new Lista<Enlaces>;
};

void Central::crearInterno(int numeroInterno)
{
  Interno internoTemporal(numeroInterno);
  if (this->listaInternos->primerNodo == NULL)
    {
      listaInternos->Insertar(internoTemporal);
    }
  else if
    {
      if (this->listaInternos->obtenerPunteroAlObjeto(numeroInterno) == NULL)
	{
	  listaInternos->Insertar(internoTemporal); 
	}
    }
}

Interno* Central::obtenerPunteroAInterno(int numeroInterno)
{
  return listaInternos->obtenerPunteroAlObjeto(numeroIterno);
};


int Central::obtenerNumero()
{
  return this->Central;
};

		

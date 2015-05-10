#include "Central.h"
#include "Internos.h"
#include "Lista.h"

Central::Central(int numeroCentralTemporal)
{
	this->Central= numeroCentralTemporal;
	this->listaInternos=NULL;
	this->listaEnlaces=NULL;
};
 
 void Central::crearInterno(int numeroCentral, int numeroInterno)
 {
	 Interno internoTemporal(numeroInterno);
	 if (this->listaInternos==NULL)
	 {
		 Lista<Interno> listaTemporal;
		 listaTemporal->Insertar(internoTemporal);
		 listaInternos= &listaTemporal;
		 		 
	 }
	 else
	 {
		 listaInternos->Insertar(internoTemporal);
	 }
};
		 

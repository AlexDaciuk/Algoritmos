
#include "Llamada.h"
#include "Internos.h"
#include <cstddef>
#include <string>
#include <iostream>
#ifndef NULL
#define NULL 0
using namespace std;

Interno::Interno(int numeroInternoTemporal)
{
  numeroInterno=numeroInternoTemporalTemporal;
  Lista<Llamada>* punteroASusLlamadas= new Lista<Llamada>;
  punteroASusLlamadas=NULL;
  estaOcupado=false;
};

int Interno::obtenerNumero()
{
  return numeroInterno;
};

Lista<Llamada>* Interno::obtenerPunteroASusLlamadas()
{
  return this->punteroASusLlamadas;
};

bool Interno::internoOcupado()
{
 return estaOcupado;
};

Nodo<Llamada>* Interno::existeLlamadaAReceptor(int receptorLlamadaTemporal)
{
  Lista<Llamada>* buscarReceptor= this->punteroASusLlamadas;
  int receptor=buscarReceptor->obtenerNumero();
  
  while (receptor != receptorLlamadaTemporal && buscarReceptor != NULL)
    {
      receptor=buscarReceptor->obtenerNumero();
      buscarReceptor=buscarReceptor->obtenerSiguiente;
    }
  
  return (buscarReceptor);
};

void Interno::agregarLlamada(int receptorLlamadaTemporal, int horaInicioLlamadaEnCursoTemporal)
{
  Nodo<Llamada>* punteroALlamadaTemporal = existeLlamadaAReceptor(receptorLlamadaTemporal);
  if (punteroALlamadaTemporal == NULL)
    {
      this->punteroASusLlamadas->insertar(receptorLlamadaTemporal);
      this->punteroASusLlamadas->obtenerPrimerNodo->empezarLlamada(horaInicioLlamadaEnCursoTemporal);
    }
  else
    {
        punteroALlamadaTemporal->empezarLlamada(horaInicioLlamadaEnCursoTemporal);
    }
};


#endif







	


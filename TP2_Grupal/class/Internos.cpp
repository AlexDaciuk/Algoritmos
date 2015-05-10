
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
  punteroASusLlamadas= NULL;
};

int Interno::obtenerNumero()
{
  return numeroInterno;
};

Llamada* Interno::obtenerPunteroASusLlamadas()
{
  return this->punteroASusLlamadas;
};

bool Interno::internoOcupado()
{
  Llamada* buscarOcupado=punteroASusLlamadas;
  int LlamadaEnCurso=0;
  
  while (LlamadaEnCurso=0 && buscarOcupado != NULL)
    {
      LlamadaEnCurso=buscarOcupado->obtenerHoraInicioLlamadaEnCurso();
      buscarOcupado=buscarOcupado->obtenerPunteroProximaLlamada();
    }
  
  return (LlamadaEnCurso !=0);
};

bool Interno::existeReceptor(int receptorLlamadaTemporal)
{
  Llamada* buscarReceptor=punteroASusLlamadas;
  int receptor=0;
  
  while (receptor != receptorLlamadaTemporal && buscarReceptor != null)
    {
      receptor=buscarReceptor->obtenerReceptorLlamada();
      buscarReceptor=buscarReceptor->obtenerPunteroProximaLlamada();
    }
  
  return (receptor==receptorLlamadaTemporal);
};

void Interno::agregarLlamada(string receptorLlamadaTemporal, int horaInicioLlamadaEnCursoTemporal)
{
  if (! existeReceptor(receptorLlamadaTemporal))
    {
      Llamada* nuevaLlamada= new Llamada (receptorLlamadaTemporal);
      nuevaLlamada->cambiarPunteroProximaLlamada(punteroASusLlamadas);
      punteroASusLlamadas=nuevaLlamada;
      delete nuevaLlamada;
    }
  else
    {
      //verifico que no sea el primer nodo
      if (this->punteroASusLlamadas->obtenerReceptorLlamada()!=receptorLlamadaTemporal)
	{
	  moverLlamadaAlFrente(receptorLlamadaTemporal);
	}
    }
  //exista o no siempre va a quedar al frente 
  punteroASusLlamadas->empezarLlamada(horaInicioLlamadaEnCursoTemporal);
};


#endif







	


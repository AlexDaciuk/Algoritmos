
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
  Llamada* buscarOcupado=punteroASusLlamadas;
  int LlamadaEnCurso=0;
  
  while (LlamadaEnCurso=0 && buscarOcupado != NULL)
    {
      LlamadaEnCurso=buscarOcupado->obtenerHoraInicioLlamadaEnCurso();
      buscarOcupado=buscarOcupado->obtenerPunteroProximaLlamada();
    }
  
  return (LlamadaEnCurso !=0);
};

Nodo<Llamada>* Interno::existeLlamadaAReceptor(int receptorLlamadaTemporal)
{
  Lista<Llamada>* buscarReceptor= this->punteroASusLlamadas;
  int receptor=0;
  
  while (receptor != receptorLlamadaTemporal && buscarReceptor != NULL)
    {
      receptor=buscarReceptor->obtenerNumero();
      buscarReceptor=buscarReceptor->obtenerSiguiente;
    }
  
  return (buscarReceptor);
};

void Interno::agregarLlamada(int receptorLlamadaTemporal, int horaInicioLlamadaEnCursoTemporal)
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







	


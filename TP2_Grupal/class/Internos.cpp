
#include "Llamada.h"
#include "Internos.h"
#include <string>
#ifndef NULL
#define NULL 0


Interno::Interno(int numeroInternoTemporal)
{
  this->numeroInterno = numeroInternoTemporal;
  Lista<Llamada>* punteroASusLlamadas= new Lista<Llamada>;
  this->estaOcupado=false;
};

int Interno::obtenerNumero()
{
  return this->numeroInterno;
};

Lista<Llamada>* Interno::obtenerPunteroASusLlamadas()
{
  return this->punteroASusLlamadas;
};

bool Interno::internoOcupado()
{
  return this->estaOcupado;
};

Nodo<Llamada>* Interno::existeLlamadaAReceptor(int receptorLlamadaTemporal)
{
  Lista<Llamada>* buscarReceptor= this->punteroASusLlamadas;
  int receptor=buscarReceptor->obtenerNumero();
  
  /**
   * Esto hay que cambiarlo para que use el cursor
    while (receptor != receptorLlamadaTemporal && buscarReceptor != NULL)
    {
    receptor=buscarReceptor->obtenerNumero();
    buscarReceptor=buscarReceptor->obtenerSiguiente;
    }
    
    return (buscarReceptor);
  */
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







	


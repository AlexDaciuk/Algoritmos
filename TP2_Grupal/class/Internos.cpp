
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

Lista<Llamada>* Interno::obtenerPunteroALlamadas()
{
  return this->punteroALlamadas;
};

bool Interno::internoOcupado()
{
  return this->estaOcupado;
};

Nodo<Llamada>* Interno::existeReceptorLlamada(int receptorLlamadaTemporal)
{
  Nodo<Llamada>* punteroANodoLlamada = NULL;

  Lista<Llamada>* punteroLlamadasTemporal = this->punteroALlamadas;
  
  punteroLlamadasTemporal->iniciarCursorLista();
  
  // Esto hay que cambiarlo para que use el cursor
  while ( punteroALlamada == NULL | )
    {
      
    }
  
  return (punteroALlamada);
  
};

//agregarLlamadaEmisor(DatosLlamada->obtenerInternoB(), DatosLlamada->obtenerHora(), DatosRecorrido* recorridoTemporal)
/**
 * El internoB es el que recibe la llamada por ende, se lo paso al 
 * emisor asi puede registrar a quien llamo
 */

void Interno::agregarLlamadaEmisor(int InternoBTemporal, int horaTemporal, DatosRecorrido* recorridoTemporal)
{
  /**
   * Obtengo el puntero a la llamada correspondiende al receptor en la lista de llamadas del interno
   */ 
  Lista<Llamadas>* llamadaReceptorTemporal = this->existeReceptorLlamada(InternoBTemporal);

  
  
  if ( ! punteroEmisorTemporal->internoOcupado() )
    {
      punteroEmisorTemporal->

}

  
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







	


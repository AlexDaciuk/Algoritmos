#include "Internos.h"
#include <string>

#ifndef NULL
#define NULL 0
#endif

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



Lista<Llamada>* Interno::obtenerLlamadas()
{
  return this->llamadas;
};



bool Interno::internoOcupado()
{
  return this->estaOcupado;
};



void Interno::creaReceptorLlamada(int receptorLlamadaTemporal)
{
  Lista<Llamada>* punteroLlamadasTemporal = this->llamadas;
  
  bool existeLlamada = false;
  
  cursorLlamadasTemporal->iniciarCursorNodo();
  
  while ( punteroLlamadasTemporal->avanzarCursorNodo() )
    {
      Nodo<Llamada> nodoLlamadaTemporal = punteroLlamadasTemporal->obtenerCursorNodo();
      if (nodoLlamadaTemporal->obtenerReceptorLlamada() = receptorLlamadaTemporal)
	{
	  existeLlamada = true;
	}
    }
  
  if (! existeLlamada)
    {
      punteroLlamadasTemporal->insertar( Llamada(receptorLlamadaTemporal) );
    }  
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









	


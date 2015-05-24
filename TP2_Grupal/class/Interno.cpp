#include "Interno.h"

Interno::Interno(int numeroInternoTemporal)
{
  this->numeroInterno = numeroInternoTemporal;
  Lista<Llamada>* llamadas= new Lista<Llamada>;
  this->estaOcupado=false;
};


int Internos::obtenerNumero()
{
  return (this->numeroInterno);
};



Lista<Llamada>* Interno::obtenerLlamadas()
{
  return (this->llamadas);
};



bool Interno::internoOcupado()
{
  return (this->estaOcupado);
};



void Interno::creaReceptorLlamada(int receptorLlamadaTemporal)
{
  Lista<Llamada>* punteroLlamadasTemporal = this->llamadas;
  
  bool existeLlamada = false;
  
  cursorLlamadasTemporal->iniciarCursorNodo();
  
  while ( punteroLlamadasTemporal->avanzarCursorNodo() )
    {
      Nodo<Llamada> nodoLlamadaTemporal = punteroLlamadasTemporal->obtenerCursorNodo();
      
	  existeLlamada = nodoLlamadaTemporal->obtenerReceptorLlamada() == receptorLlamadaTemporal;

    }
  
  if (! existeLlamada)
    {
      punteroLlamadasTemporal->insertar(Llamada(receptorLlamadaTemporal) );
    }  
};

//agregarLlamadaEmisor(DatosLlamada->obtenerInternoB(), DatosLlamada->obtenerHora(), DatosRecorrido* recorridoTemporal)
/**
 * El internoB es el que recibe la llamada por ende, se lo paso al 
 * emisor asi puede registrar a quien llamo
 */

void Interno::agregarLlamadaEmisor(int EmisorTemporal, int horaTemporal, DatosRecorrido* recorridoTemporal)
{
  /**
   * Obtengo el puntero a la llamada correspondiende al receptor en la lista de llamadas del interno
   */ 
  Lista<Llamadas>* llamadaReceptorTemporal = this->existeReceptorLlamada(OrigenTemporal);

  if ( ! punteroEmisorTemporal->internoOcupado() )
    {
      punteroEmisorTemporal->

};

  
void Interno::agregarLlamada(int receptorLlamadaTemporal, int horaInicioLlamadaEnCursoTemporal)
{
  Nodo<Llamada>* punteroALlamadaTemporal = existeLlamadaAReceptor(receptorLlamadaTemporal);
  if (punteroALlamadaTemporal == NULL)
    {
      this->llamadas->insertar(receptorLlamadaTemporal);
      this->llamadas->obtenerPrimerNodo->empezarLlamada(horaInicioLlamadaEnCursoTemporal);
    }
  else
    {
      punteroALlamadaTemporal->empezarLlamada(horaInicioLlamadaEnCursoTemporal);
    }
};









	


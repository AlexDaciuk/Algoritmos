#include "ProcesadorLlamada.h"

#ifndef NULL
#define NULL 0
#endif


ProcesadorLlamada::ProcesadorLlamada()
{
  datosTemporal= NULL;
  recorridoTemporal= NULL;
  centrales = new Lista<Central>;
  Listaenlaces = new Lista<Enlace>;
}

void ProcesadorLlamada::procesarLlamadas(std::string rutaArchivoLlamadas)
{
  while ( archivoLlamadas->chequearLLamada() )
    {
      datosTemporal = archivoLlamadas->obtenerDatosLlamada();
      agregarCentral(punterodatosTemporal->obtenerOrigen);
      agregarCentral(punterodatosTemporal->obtenerDestino);
	
      if ( datosTemporal->accionTemporal == "Inicio")
      {
        recorridoTemporal = this->buscaCentral; 
        this->iniciarLlamada();  
      }
      else
      { 
        if ( datosTemporal->accionTemporal == "Fin")
        {
          this->finalizarLlamada();
        }
        else
          {    
            if ( datosTemporal->accionTemporal == "Enlace")
            {
             agregarEnlace(datosTemporal->obtenerOrigen(), datosTemporal->obtenerDestino());
            }
          }
      }
    } 
}     

void ProcesadorLlamada::iniciarLlamada();
{
  // Veo si los internos existen o sino, los crea
  centrales->crearInterno(datosTemporal->obtenerOrigen(), datosTemporal->obtenerEmisor());
  centrales->crearInterno(datosTemporal->obtenerDestino(), datosTemporal->obtenerReceptor());
  
  //Obtengo punteros a cada interno
  Internos* Emisor, Receptor;
  
  Emisor = centrales->obtenerInterno(datosTemporal->obtenerOrigen(), datosTemporal->obtenerEmisor() );
  Receptor = centrales->obtenerInterno(datosTemporal->obtenerDestino(), datosTemporal->obtenerReceptor() );
  
  //Agrego la llamada a cada interno
  Emisor->agregarLlamadaEmisor(datosTemporal->obtenerReceptor(), datosTemporal->obtenerHora(), recorridoTemporal);
  Receptor->agregarLlamadaReceptor(datosTemporal->obtenerEmisor(), datosTemporal->obtenerHora(), recorridoTemporal);
  
  //Cambio la disponibilidad de los enlaces
  Enlace* EnlaceTemporal = this->recorridoTemporal->obtenerRuta;
  
  /**
   *  Esto hay que cambiarlo, usar un cursor dentro de la lista
   * u otro metodo inclusive
   * while ( recorridoTemporal->punteroARuta != NULL ) 
   *{
   *punteroEnlaceTemporal->agregarLlamadaEnCurso();
   *
   *punteroEnlaceTemporal = punteroEnlaceTemporal->obtenerSiguiente();
   *}
   */
}


void ProcesadorLlamada::finalizarLlamada()
{
  //Obtengo punteros a cada interno
  Internos* Emisor, Receptor;
  
  Emisor = centrales->obtenerInterno(datosTemporal->obtenerOrigen(), datosTemporal->obtenerEmisor());
  Receptor = centrales->obtenerInterno(datosTemporal->obtenerDestino(), datosTemporal->obtenerReceptor());
  
  
  // Termino la llamada en cada interno
  Emisor->terminarLlamadaEmisor(datosTemporal->obtenerEmisor(), datosTemporal->obtenerHora() );
  Receptor->terminarLlamadaReceptor(datosTemporals->obtenerReceptor(), datosTemporal->obtenerHora() );
  
  
  //Cambio disponibilidad de enlaces

};


void ProcesadorLlamada::agregarCentral(int numeroCentral)
{
  centrales->iniciarCursorNodo();
  bool encontro=false;
  while ((punterocentrales->avanzarCursorNodo()) && (! encontro))
    {
      if (numeroCentral == punterocentrales->obtenerCursorNodo()->obtenerNumero())
	{
	  encontro=true;
	}
    }
  if (! encontro)
    {
      Central* nuevaCentral= new Central(numeroCentral) ;
      punterocentrales->insertar(*punteroNuevaCentral);
           
    }
}

void ProcesadorLlamada::agregarEnlace(int numeroOrigen, int numeroDestino)
{
  punteroListaenlaces->inicarCursorNodo();
  bool encontro=false;
  while ((punteroListaenlaces->avanzarCursorNodo()) && (! encontro)))
  {
    if ((numeroOrigen==punteroListaenlaces->obtenerCursorNodo()->obtenerOrigen()) 
    &&
     numeroDestino==punteroListaenlaces->obtenerCursorNodo()->obtenerDestino())
    {
      encontro=true;
    }
  }
  if (! encontro)
  {
    Enlace* nuevoEnlace = new Enlace( numeroOrigen, numeroDestino, punterodatosTemporal->obtenerDestino(), 
     punterodatosTemporal->obtenerReceptor(), punterodatosTemporal->obtenerHora());
    punteroListaenlaces()->insertar(*nuevoEnlace);
  }
}

    punteroEnlces

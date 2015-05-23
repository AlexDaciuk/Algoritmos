#include "ProcesadorLlamada.h"

#ifndef NULL
#define NULL 0
#endif


ProcesadorLlamada::ProcesadorLlamada()
{
  DatosTemporal= NULL;
  RecorridoTemporal= NULL;
  ListaCentrales = new Lista<Central>;
  ListaEnlaces = new Lista<Enlace>;
}

void ProcesadorLlamada::procesarLlamadas(std::string rutaArchivoLlamadas)
{
  while ( archivoLlamadas->chequearLLamada() )
    {
      DatosTemporal = archivoLlamadas->obtenerDatosLlamada();
      agregarCentral(punteroDatosTemporal->obtenerOrigen);
      agregarCentral(punteroDatosTemporal->obtenerDestino);
	
      if ( DatosTemporal->accionTemporal == "Inicio")
      {
        RecorridoTemporal = this->buscaCentral; 
        this->iniciarLlamada();  
      }
      else
      { 
        if ( DatosTemporal->accionTemporal == "Fin")
        {
          this->finalizarLlamada();
        }
        else
          {    
            if ( DatosTemporal->accionTemporal == "Enlace")
            {
             agregarEnlace(DatosTemporal->obtenerOrigen(), DatosTemporal->obtenerDestino());
            }
          }
      }
    } 
}     

void ProcesadorLlamada::iniciarLlamada();
{
  // Veo si los internos existen o sino, los crea
  ListaCentrales->crearInterno(DatosTemporal->obtenerOrigen(), DatosTemporal->obtenerEmisor());
  ListaCentrales->crearInterno(DatosTemporal->obtenerDestino(), DatosTemporal->obtenerReceptor());
  
  //Obtengo punteros a cada interno
  Internos* Emisor, Receptor;
  
  Emisor = ListaCentrales->obtenerInterno(DatosTemporal->obtenerOrigen(), DatosTemporal->obtenerEmisor() );
  Receptor = ListaCentrales->obtenerInterno(DatosTemporal->obtenerDestino(), DatosTemporal->obtenerReceptor() );
  
  //Agrego la llamada a cada interno
  Emisor->agregarLlamadaEmisor(DatosTemporal->obtenerReceptor(), DatosTemporal->obtenerHora(), recorridoTemporal);
  Receptor->agregarLlamadaReceptor(DatosTemporal->obtenerEmisor(), DatosTemporal->obtenerHora(), recorridoTemporal);
  
  //Cambio la disponibilidad de los enlaces
  Enlace* EnlaceTemporal = this->RecorridoTemporal->obtenerRuta;
  
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
  Internos* punteroEmisor, punteroReceptor;
  
  punteroEmisor = punteroListaCentrales->obtenerPunteroInterno(punteroDatosTemporal->obtenerOrigen(), punteroDatosTemporal->obtenerEmisor());
  punteroReceptor = punteroListaCentrales->obtenerPunteroInterno(punteroDatosTemporal->obtenerDestino(), punteroDatosTemporal->obtenerReceptor());
  
  
  // Termino la llamada en cada interno
  punteroEmisor->terminarLlamadaEmisor(punteroDatosTemporal->obtenerEmisor(), punteroDatosTemporal->obtenerHora() );
  punteroReceptor->terminarLlamadaReceptor(punteroDatosTemporals->obtenerReceptor(), punteroDatosTemporal->obtenerHora() );
  
  
  //Cambio disponibilidad de enlaces

};


void ProcesadorLlamada::agregarCentral(int numeroCentral)
{
  punteroListaCentrales->iniciarCursorNodo();
  bool encontro=false;
  while ((punteroListaCentrales->avanzarCursorNodo()) && (! encontro))
    {
      if (numeroCentral == punteroListaCentrales->obtenerCursorNodo()->obtenerNumero())
	{
	  encontro=true;
	}
    }
  if (! encontro)
    {
      Central* nuevaCentral= new Central(numeroCentral) ;
      punteroListaCentrales->insertar(*punteroNuevaCentral);
           
    }
}

void ProcesadorLlamada::agregarEnlace(int numeroOrigen, int numeroDestino)
{
  punteroListaEnlaces->inicarCursorNodo();
  bool encontro=false;
  while ((punteroListaEnlaces->avanzarCursorNodo()) && (! encontro)))
  {
    if ((numeroOrigen==punteroListaEnlaces->obtenerCursorNodo()->obtenerOrigen()) 
    &&
     numeroDestino==punteroListaEnlaces->obtenerCursorNodo()->obtenerDestino())
    {
      encontro=true;
    }
  }
  if (! encontro)
  {
    Enlace* nuevoEnlace = new Enlace( numeroOrigen, numeroDestino, punteroDatosTemporal->obtenerDestino(), 
     punteroDatosTemporal->obtenerReceptor(), punteroDatosTemporal->obtenerHora());
    punteroListaEnlaces()->insertar(*nuevoEnlace);
  }
}

    punteroEnlces

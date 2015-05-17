#include "ProcesadorLlamada.h"
#include "LectorArchivos.h"
#include "Enlaces.h"
#include "Lista.h"
#ifndef NULL
#define NULL 0


ProcesadorLlamadas::ProcesadorLlamada()
{
  punteroDatosTemporal= NULL;
  punteroRecorridoTemporal= NULL;
  punteroCentrales = new Lista<Central>;
  punteroEnlaces = new Lista<Enlace>;
}

void ProcesadorLlamada::procesarLlamadas(std:: rutaArchivoLlamadas)
{
  LectorArchivos archivoLlamadas(rutaArchivoLlamadas)
  while ( archivoLlamadas->chequearLLamada() )
    {
      punteroDatosTemporal = archivoLlamadas->obtenerDatosLlamada();
      agregarCentral(punteroDatosTemporal->obtenerCentralA);
      agregarCentral(punteroDatosTemporal->obtenerCentralB);
	
      if ( punteroDatosTemporal->accionTemporal == "Inicio")
      {
        punteroRecorridoTemporal = this->buscaCentral; 
        this->iniciarLlamada();  
      }
      else
      { 
        if ( punteroDatosTemporal->accionTemporal == "Fin")
        {
          this->finalizarLlamada();
        }
        else
          {    
            if ( punteroDatosTemporal->accionTemporal == "Enlace")
            {
             agregarEnlace(punteroDatosTemporal->obtenerCentralA(), punteroDatosTemporal->obtenerInternoA());
            }
          }
      }
    } 
}     

void ProcesadorLlamada::iniciarLlamada();
{


  // Veo si los internos existen o sino, los crea
  punteroListaCentrales->crearInterno(punteroDatosTemporal->obtenerCentralA(), punteroDatosTemporal->obtenerInternoA());
  punteroListaCentrales->crearInterno(punteroDatosTemporal->obtenerCentralB(), punteroDatosTemporal->obtenerInternoB());
  
  //Obtengo punteros a cada interno
  Internos* punteroInternoA, punteroInternoB;
  
  punteroInternoA = punteroListaCentrales->obtenerPunteroInterno(punteroDatosTemporal->obtenerCentralA(), punteroDatosTemporal->obtenerInternoA() );
  punteroInternoB = punteroListaCentrales->obtenerPunteroInterno(punteroDatosTemporal->obtenerCentralB(), punteroDatosTemporal->obtenerInternoB() );
  
  //Agrego la llamada a cada interno
  punteroInternoA->agregarLlamadaEmisor(punteroDatosTemporal->obtenerInternoB(), punteroDatosTemporal->obtenerHora(), DatosRecorrido* recorridoTemporal);
  punteroInternoB->agregarLlamadaReceptor(punteroDatosTemporal->obtenerInternoA(), punteroDatosTemporal->obtenerHora(), DatosRecorrido* recorridoTemporal);
  
  //Cambio la disponibilidad de los enlaces
  Enlace* punteroEnlaceTemporal = this->punteroRecorridoTemporal->ObtenerPunteroARuta;
  
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
  Internos* punteroInternoA, punteroInternoB;
  
  punteroInternoA = punteroListaCentrales->obtenerPunteroInterno(punteroDatosTemporal->obtenerCentralA(), punteroDatosTemporal->obtenerInternoA());
  punteroInternoB = punteroListaCentrales->obtenerPunteroInterno(punteroDatosTemporal->obtenerCentralB(), punteroDatosTemporal->obtenerInternoB());
  
  
  // Termino la llamada en cada interno
  punteroInternoA->terminarLlamadaEmisor(punteroDatosTemporal->obtenerInternoA(), punteroDatosTemporal->obtenerHora() );
  punteroInternoB->terminarLlamadaReceptor(punteroDatosTemporals->obtenerInternoB(), punteroDatosTemporal->obtenerHora() );
  
  
  //Cambio disponibilidad de enlaces

};


void ProcesadorLlamada::agregarCentral(int numeroCentral)
{
  punteroCentrales->iniciarCursorNodo();
  bool encontro=false;
  while ((punteroCentrales->avanzarCursorNodo()) && (! encontro))
    {
      if (numeroCentral == punteroCentrales->obtenerCursorNodo()->obtenerNumero())
	{
	  encontro=true;
	}
    }
  if (! encontro)
    {
      Central* nuevaCentral= new Central(numeroCentral) ;
      punteroCentrales->insertar(*punteroNuevaCentral);
           
    }
}

void ProcesadorLlamada::agregarEnlace(int numeroCentralA, int numeroCentralB)
{
  punteroEnlaces->inicarCursorNodo();
  bool encontro=false;
  while ((punteroEnlaces->avanzarCursorNodo()) && (! encontro)))
  {
    if ((numeroCentralA==punteroEnlaces->obtenerCursorNodo()->obtenerCentralA()) 
    &&
     numeroCentralB==punteroEnlaces->obtenerCursorNodo()->obtenerCentralB())
    {
      encontro=true;
    }
  }
  if (! encontro)
  {
    Enlace* nuevoEnlace = new Enlace( numeroCentralA, numeroCentralB, punteroDatosTemporal->obtenerCentralB(), 
     punteroDatosTemporal->obtenerInternoB(), punteroDatosTemporal->obtenerHora());
    punteroEnlaces()->insertar(*nuevoEnlace);
  }
}

    punteroEnlces

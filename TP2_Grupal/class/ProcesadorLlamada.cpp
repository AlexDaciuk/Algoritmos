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
  while ((centrales->avanzarCursorNodo()) && (! encontro))
    {
      if (numeroCentral == centrales->obtenerCursorNodo()->obtenerNumero())
	{
	  encontro=true;
	}
    }
  if (! encontro)
    {
      Central* nuevaCentral= new Central(numeroCentral) ;
      centrales->insertar(nuevaCentral);
           
    }
}

void ProcesadorLlamada::agregarEnlace(int numeroOrigen, int numeroDestino)
{
  this->enlaces->inicarCursorNodo();
  bool encontro=false;
  while ((this->enlaces->avanzarCursorNodo()) && (! encontro)))
  {
    if ((numeroOrigen==this->enlaces->obtenerCursorNodo()->obtenerOrigen()) 
    &&
     numeroDestino==this->enlaces->obtenerCursorNodo()->obtenerDestino())
    {
      encontro=true;
    }
  }
  if (! encontro)
  {
	// Aca tener en cuenta que los atributos de datosTemporal siguen con los nombres como si fuera
	// una llamada, pero realmente es para una central y estan ordenados
	Enlace* nuevoEnlace = new Enlace(numeroOrigen, numeroDestino, this->datosTemporal->obtenerDestino(), 
						  this->datosTemporal->obtenerReceptor(), this->datosTemporal->obtenerHora());
    this->enlaces->insertar(nuevoEnlace);
  }
}



#include "ProcesadorLlamada.h"
#include "LectorArchivos.h"
#include "Enlaces.h"
#include "Lista.h"
#ifndef NULL
#define NULL 0


  ProcesadorLlamdas::ProcesadorLlamada()
  {
    punteroDatosTemporal= NULL;
    punteroRecorridoTemporal= NULL;
    punteroCentrales= new Lista<Central>;
    punteroEnlaces= new Lista<Enlace>;
  }
  
void ProcesadorLlamada::procesarLlamadas(std:: rutaArchivoLlamadas)
{
  LectorArchivos archivoLlamadas(rutaArchivoLlamadas)
  while ( archivoLlamadas->chequearLLamada() )
    {
      punteroDatosTemporal = archivoLlamadas->obtenerDatosLlamada();
      
      //Agrego la centrales, si ya existen no hace nada
      agregarCentralA(punteroDatosTemporal->obtenerCentralA);
      agregarCentralB(punteroDatosTemporal->obtenerCentralB);
      
      if ( punteroDatosTemporal->accionTemporal == "Inicio")
	{
	  punteroRecorridoTemporal = this->buscaCentral; 
	  this->iniciarLlamada();  
	}
      else if ( punteroDatosTemporal->accionTemporal == "Fin")
	{
	  this->finalizarLlamada();
	}
      else if ( punteroDatosTemporal->accionTemporal == "Enlace")
	{
	  ListaEnlaces->Insertar(punteroDatosLlamadas.obtenerCentralA());
    ListaEnlaces->Insertar(punteroDatosLlamadas.obtenerCentralB());
	}
    }
}

void ProcesadorLlamada::iniciarLlamada();
{
  // Veo si los internos existen o sino, los crea
  punteroListaCentrales->crearInterno(DatosLlamada->obtenerCentralA(), DatosLlamada->obtenerInternoA());
  punteroListaCentrales->crearInterno(DatosLlamada->obtenerCentralB(), DatosLlamada->obtenerInternoB());

  //Obtengo punteros a cada interno
  Internos* punteroInternoA, punteroInternoB;

  punteroInternoA = punteroListaCentrales->obtenerPunteroInterno(DatosLlamada->obtenerCentralA(), DatosLlamada->obtenerInternoA() );
  punteroInternoB = punteroListaCentrales->obtenerPunteroInterno(DatosLlamada->obtenerCentralB(), DatosLlamada->obtenerInternoB() );

  //Agrego la llamada a cada interno
  punteroInternoA->agregarLlamadaEmisor(DatosLlamada->obtenerInternoB(), DatosLlamada->obtenerHora(), DatosRecorrido* recorridoTemporal);
  punteroInternoB->agregarLlamadaReceptor(DatosLlamada->obtenerInternoA(), DatosLlamada->obtenerHora(), DatosRecorrido* recorridoTemporal);
  
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

  punteroInternoA = punteroListaCentrales->obtenerPunteroInterno(DatosLlamada->obtenerCentralA(), DatosLlamada->obtenerInternoA());
  punteroInternoB = punteroListaCentrales->obtenerPunteroInterno(DatosLlamada->obtenerCentralB(), DatosLlamada->obtenerInternoB());


  // Termino la llamada en cada interno
  punteroInternoA->terminarLlamadaEmisor(DatosLlamada->obtenerInternoA(), DatosLlamada->obtenerHora() );
  punteroInternoB->terminarLlamadaReceptor(DatosLlamadas->obtenerInternoB(), DatosLlamada->obtenerHora() );


  //Cambio disponibilidad de enlaces


};

void ProcesadorLlamada::agregarCentralA(int numeroCentral)
{
  punteroCentrales->iniciarCursorNodo();
  bool encontro=false;
  while ((punteroCentrales->avanzarCursorNodo()) && (! encontro))
  {
    if (numeroCentral = punteroCentrales->obtenerCursorNodo()->obtenerNumero())
    {
      encontro=true;
    }
  }
  if (! encontro)
  {
    Central* nuevaCentral= new Central(numeroCentral) 
    punteroCentrales->insertar(*punteroNuevaCentral)
    punteroCentrales->obtenerPunteroAlObjeto(numeroCentral)->crearInterno(punteroDatosTemporal->obtenerInternoA());
  {
  delete nuevaCentral;
};

void ProcesadorLlamada::agregarCentralB(int numeroCentral)
{
  punteroCentrales->iniciarCursorNodo();
  bool encontro=false;
  while ((punteroCentrales->avanzarCursorNodo()) && (! encontro))
  {
    if (numeroCentral = punteroCentrales->obtenerCursorNodo()->obtenerNumero())
    {
      encontro=true;
    }
  }
  if (! encontro)
  {
    Central* nuevaCentral= new Central(numeroCentral) 
    punteroCentrales->insertar(*punteroNuevaCentral)
    punteroCentrales->obtenerPunteroAlObjeto(numeroCentral)->crearInterno(punteroDatosTemporal->obtenerInternoB());
  {
  delete nuevaCentral;
};

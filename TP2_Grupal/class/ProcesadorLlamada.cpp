


void ProcesadorLlamada::procesaLlamadas()
{
  while ( LectorArchivos->chequearLLamada() )
    {
      punteroDatosTemporal = LectorArchivos->obtenerDatosLlamada();

      //Agrego la centrales, si ya existen no hace nada
      Central->agregarCentral(string punteroDatosTemporal->centralA, string punteroDatosTemporal->centralB);
      
      if ( DatosLlamada->accionTemporal == "Inicio")
	{
	  punteroRecorridoTemporal = this->buscaCentral; 
	  this->iniciarLlamada();  
	}
      else if ( DatosLlamada->accionTemporal == "Fin")
	{
	  this->finalizarLlamada();
	}
      else if ( DatosLlamada->accionTemporal == "Enlace")
	{
	  ListaEnlaces->agregaEnlace(DatosLlamada* punteroDatosLlamadas);
	}
    }
}


void ProcesadorLlamada::iniciarLlamada();
{
  // Veo si los internos existen o sino, los crea
  punteroListaCentrales->crearInterno(DatosLlamada->obtenerCentralA, DatosLlamada->obtenerInternoA);
  punteroListaCentrales->crearInterno(DatosLlamada->obtenerCentralB, DatosLlamada->obtenerInternoB);

  //Obtengo punteros a cada interno
  Internos* punteroInternoA, punteroInternoB;

  punteroInternoA = punteroListaCentrales->obtenerPunteroInterno(DatosLlamada->obtenerCentralA, DatosLlamada->obtenerInternoA);
  punteroInternoB = punteroListaCentrales->obtenerPunteroInterno(DatosLlamada->obtenerCentralB, DatosLlamada->obtenerInternoB);

  //Agrego la llamada a cada interno
  punteroInternoA->agregarLlamadaEmisor(DatosLlamada->obtenerInternoB, DatosLlamada->obtenerHoraInicio, DatosRecorrido* recorridoTemporal);
  punteroInternoB->agregarLlamadaReceptor(DatosLlamada->obtenerInternoA, DatosLlamada->obtenerHoraInicio, DatosRecorrido* recorridoTemporal);
  
  //Cambio la disponibilidad de los enlaces
  Enlace* punteroEnlaceTemporal = this->punteroRecorridoTemporal->ObtenerPunteroARuta
    // Esto hay que cambiarlo, usar un cursor dentro de la lista
    // u otro metodo inclusive
    /* while ( recorridoTemporal->punteroARuta != NULL ) 
    {
      punteroEnlaceTemporal->agregarLlamadaEnCurso();

      punteroEnlaceTemporal = punteroEnlaceTemporal->obtenerSiguiente();
      }*/
}






void ProcesadorLlamada::procesaLlamadas()
{
  while ( LectorArchivos->chequearLLamada() )
    {
      punteroDatosTemporal = LectorArchivos->obtenerDatosLlamada();

      //Agrego la centrales, si ya existen no hace nada
      Central->agregarCentral(string punteroDatosTemporal->centralA, string punteroDatosTemporal->centralB);
      
      if ( DatosLlamada->accionTemporal == "Inicio")
	{
	  recorridoTemporal = this->buscaCentral;
	      
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
  ListaCentrales->crearInterno(DatosLlamada->centralA, DatosLlamada->internoA);
  ListaCentrales->crearInterno(DatosLlamada->centralB, DatosLlamada->internoB);

  //Obtengo punteros a cada interno
  Internos* punteroInternoA, punteroInternoB;

  punteroInternoA = ListaCentrales->obtenerPunteroInterno(DatosLlamada->centralA, DatosLlamada->internoA);
  punteroInternoB = ListaCentrales->obtenerPunteroInterno(DatosLlamada->centralB, DatosLlamada->internoB);

  //Agrego la llamada a cada interno
  punteroInternoA->agregarLlamadaEmisor(DatosLlamada->internoB, DatosLlamada->horaInicio, DatosRecorrido* recorridoTemporal);
  punteroInternoB->agregarLlamadaReceptor(DatosLlamada->internoA, DatosLlamada->horaInicio, DatosRecorrido* recorridoTemporal);
  
  //Cambio la disponibilidad de los enlaces
  Enlace* punteroEnlaceTemporal = recorridoTemporal->punteroARuta
  while ( recorridoTemporal->punteroARuta != NULL ) 
    {
      punteroEnlaceTemporal->agregarLlamadaEnCurso();

      punteroEnlaceTemporal = punteroEnlaceTemporal->obtenerSiguiente();
    }
}



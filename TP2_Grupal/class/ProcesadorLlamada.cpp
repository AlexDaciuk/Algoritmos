


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
  Central->crearInterno(int DatosLlamada->centralA, int DatosLlamada->internoA);
  Central->crearInterno(int DatosLlamada->centralB, int DatosLlamada->internoB);

  //Obtengo punteros a cada interno
  Internos* punteroInternoA, punteroInternoB;

  punteroInternoA = Central->obtenerPunteroInterno(int DatosLlamada->centralA, int DatosLlamada->internoA);
  punteroInternoB = Central->obtenerPunteroInterno(int DatosLlamada->centralB, int DatosLlamada->internoB);

  
  


}

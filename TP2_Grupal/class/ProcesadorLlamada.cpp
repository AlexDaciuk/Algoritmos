


void ProcesadorLlamada::procesaLlamadas()
{
  while ( LectorArchivos->chequearLLamada() )
    {
      punteroDatosTemporal = LectorArchivos->obtenerDatosLlamada();

      //Agrego la centrales, si ya existen no hace nada
      Central->agregarCentral(string punteroDatosTemporal->centralA, string punteroDatosTemporal->centralB);

      
      if ( DatosLlamada->accionTemporal == "Inicio")
	{
	  recorridoTemporal = this->buscaCentralMenorPrecio;
	      
	  this->iniciarLlamada();
	    
	}
      else if ( DatosLlamada->accionTemporal == "Fin")
	{
	  this->finalizarLlamada();
	}
      else if ( DatosLlamada->accionTemporal == "Enlace")
	{
	  this->agregaEnlace();
	}


}

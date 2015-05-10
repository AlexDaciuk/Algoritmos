


void ProcesadorLlamada::procesaLlamadas()
{
  while ( LectorArchivos.chequearLLamada() )
    {
      punteroDatosTmp = LectorArcnivos.obtenerDatosLlamada();

      //Agrego la centrales, si ya existen no hace nada
      Central.agregarCentral(string punteroDatosTmp->centralA, string punteroDatosTmp->centralB);

      
      if ( DatosLlamada->accionTemporal == "Inicio")
	{
	  if ( opcionAlgoritmo == "Precio")
	    {
	      recorridoTmp = this->buscaCentralMenorPrecio;

	      
	      

	    }
	  else if (opcionAlgoritmo == "Distancia")
	    {
	      recorridoTmp = this->buscaCentralMenorDistancia;

	      

	    }


	}
      else if ( DatosLlamada->accionTemporal == "Fin")
	{
	  
	}
      else if ( DatosLlamada->accionTemporal == "Enlace")
	{
	  this->agregaEnlace();
	}


}

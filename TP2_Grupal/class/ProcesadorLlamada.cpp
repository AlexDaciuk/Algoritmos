


void ProcesadorLlamada::procesaLlamadas()
{
  while ( LectorArchivos.chequearLLamada() )
    {
      DatosLlamada* punteroDatosTmp;

      punteroDatosTmp = LectorArcnivos.obtenerDatosLlamada();

      if ( DatosLlamada->accionTemporal == "Inicio")
	{
	  DatosRecorrido* recorridoTmp;

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




	}


}

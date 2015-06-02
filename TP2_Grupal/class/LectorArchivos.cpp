#include "LectorArchivos.h"


LectorArchivos::LectorArchivos (std::string rutaArchivoTemporal)
{
	this->archivo.open( rutaArchivoTemporal.c_str() );
	this->datosLlamadaTemporal = new DatosLlamada();
	this->hayLlamadas = true;
}


DatosLlamada* LectorArchivos::obtenerDatosLlamada()
{
	if (! this->archivo.eof() ) {
		std::string accionTemporal, origenTemporal, emisorTemporal, destinoTemporal, receptorTemporal, horaTemporal;

		getline(archivo, accionTemporal,' ');

		getline(archivo, origenTemporal,' ');

		getline(archivo, emisorTemporal,' ');

		getline(archivo, destinoTemporal,' ');

		getline(archivo, receptorTemporal,' ');

		getline(archivo, horaTemporal,'\n');

		this->datosLlamadaTemporal->cargarLlamada(accionTemporal, origenTemporal, emisorTemporal, destinoTemporal, receptorTemporal, horaTemporal);
	} else {
		this->hayLlamadas = false;
	}

	return(datosLlamadaTemporal);
}


bool LectorArchivos::chequearLlamadas()
{
	return(this->hayLlamadas);
}


LectorArchivos::~LectorArchivos()
{
	this->archivo.close();
	delete(this->datosLlamadaTemporal);
}

#include "DatosLlamada.h"

DatosLlamada::DatosLlamada()
{
	this->accion = " ";
	this->origen = 0;
	this->destino = 0;
	this->emisor = 0;
	this->receptor = 0;
	this->hora = 0;
}


void DatosLlamada::cargarLlamada(std::string accionActual, std::string origenActual, std::string emisorActual,
                                 std::string destinoActual, std::string receptorActual, std::string horaActual)
{
	if (! accionActual.empty()) {
		this->accion = accionActual;

		std::stringstream origenStream(origenActual);
		origenStream >> this->origen;

		std::stringstream emisorStream(emisorActual);
		emisorStream >> this->emisor;

		std::stringstream destinoStream(destinoActual);
		destinoStream >> this->destino;

		std::stringstream receptorStream(receptorActual);
		receptorStream >> this->receptor;

		std::stringstream horaInicioStreamActual(horaActual);
		horaInicioStreamActual >> this->hora;

	}
}


std::string DatosLlamada::obtenerAccion()
{
	return(this->accion);
}


int DatosLlamada::obtenerOrigen()
{
	return(this->origen);
}


int DatosLlamada::obtenerDestino()
{
	return(this->destino);
}


int DatosLlamada::obtenerEmisor()
{
	return(this->emisor);
}


int DatosLlamada::obtenerReceptor()
{
	return(this->receptor);
}


int DatosLlamada::obtenerHora()
{
	return(this->hora);
}

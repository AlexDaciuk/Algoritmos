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


void DatosLlamada::cargarLlamada(std::string accionTemporal, std::string origenTemporal, std::string emisorTemporal, std::string destinoTemporal, std::string receptorTemporal, std::string horaTemporal)
{
	if (! accionTemporal.empty()) {
		this->accion = accionTemporal;

		std::stringstream origenStream(origenTemporal);
		origenStream >> this->origen;

		std::stringstream emisorStream(emisorTemporal);
		emisorStream >> this->emisor;

		std::stringstream destinoStream(destinoTemporal);
		destinoStream >> this->destino;

		std::stringstream receptorStream(receptorTemporal);
		receptorStream >> this->receptor;

		std::stringstream horaInicioStreamTemporal(horaTemporal);
		horaInicioStreamTemporal >> this->hora;

	}
}

std::string DatosLlamada::obtenerAccion()
{
	return this->accion;
}

int DatosLlamada::obtenerOrigen()
{
	return this->origen;
}
int DatosLlamada::obtenerDestino()
{
	return this->destino;
}

int DatosLlamada::obtenerEmisor()
{
	return this->emisor;
}

int DatosLlamada::obtenerReceptor()
{
	return this->receptor;
}

int DatosLlamada::obtenerHora()
{
	return this->hora;
}

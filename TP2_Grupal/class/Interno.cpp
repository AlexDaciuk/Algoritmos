#include "Interno.h"

Interno::Interno(int numeroInternoTemporal)
{
	this->numeroInterno = numeroInternoTemporal;
	Lista<Llamada>* llamadas= new Lista<Llamada>;
	this->estaOcupado=false;
};


int Internos::obtenerNumero()
{
	return (this->numeroInterno);
};



Lista<Llamada*>* Interno::obtenerLlamadas()
{
	return (this->llamadas);
};



bool Interno::internoOcupado()
{
	return (this->estaOcupado);
};



void Interno::creaReceptorLlamada(int receptorLlamadaTemporal)
{
	Lista<Llamada*>* punteroLlamadasTemporal = this->llamadas;

	bool existeLlamada = false;

	cursorLlamadasTemporal->iniciarCursorNodo();

	while ( punteroLlamadasTemporal->avanzarCursorNodo() ) {
		Nodo<Llamada> nodoLlamadaTemporal = punteroLlamadasTemporal->obtenerCursorNodo();

		existeLlamada = nodoLlamadaTemporal->obtenerReceptorLlamada() == receptorLlamadaTemporal;

	}

	if (! existeLlamada) {
		punteroLlamadasTemporal->insertar(Llamada(receptorLlamadaTemporal) );
	}
};


void Interno::agregarLlamadaEmisor(int receptorTemporal, int horaTemporal, )
{
	// Me fijo si la llamada con el receptor esta creada, sino, la creo
	
	Nodo<Llamada>* punteroALlamadaTemporal = existeLlamadaAReceptor(receptorLlamadaTemporal);
	
	if (punteroALlamadaTemporal == NULL) {
		this->llamadas->insertar(receptorLlamadaTemporal);
		this->llamadas->obtenerPrimerNodo->empezarLlamada(horaInicioLlamadaEnCursoTemporal);
	} else {
		punteroALlamadaTemporal->empezarLlamada(horaInicioLlamadaEnCursoTemporal);
	}


}


};


void Interno::agregarLlamada(int receptorLlamadaTemporal, int horaInicioLlamadaEnCursoTemporal)
{
	Nodo<Llamada>* punteroALlamadaTemporal = existeLlamadaAReceptor(receptorLlamadaTemporal);
	if (punteroALlamadaTemporal == NULL) {
		this->llamadas->insertar(receptorLlamadaTemporal);
		this->llamadas->obtenerPrimerNodo->empezarLlamada(horaInicioLlamadaEnCursoTemporal);
	} else {
		punteroALlamadaTemporal->empezarLlamada(horaInicioLlamadaEnCursoTemporal);
	}
};

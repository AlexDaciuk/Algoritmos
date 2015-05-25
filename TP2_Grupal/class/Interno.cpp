#include "Interno.h"

Interno::Interno(int numeroInternoTemporal)
{
	this->numeroInterno = numeroInternoTemporal;
	Lista<Llamada*>* llamadas= new Lista<Llamada>;
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



Llamada* Interno::creaReceptorLlamada(int receptorLlamadaTemporal)
{
	bool existeLlamada = false;
	Llamada* llamadaTemporal = NULL;
	this->llamadas->iniciarCursorNodo();

	while ( this->llamadas->avanzarCursorNodo() && ! existeLlamada) {
		llamadaTemporal = this->obtenerCursorNodo();
		existeLlamada = nodoLlamadaTemporal->obtenerReceptorLlamada() == receptorLlamadaTemporal;
	}

	if (! existeLlamada) {
		Llamada* nuevaLlamada = new Llamada(receptorLlamadaTemporal);
		llamadaTemporal = nuevaLlamada;
		llamadasTemporal->insertar(nuevaLlamada);
	}

	return llamadaTemporal;
};


void Interno::agregarLlamadaEmisor(int receptorTemporal, int horaTemporal, Interno* receptor )
{
	// Me fijo si la llamada esta creada, sino, la creo
	Llamada* llamadaTemporal = creaReceptorLlamada(receptorLlamadaTemporal);


	if (! receptor->internoOcupado()) {
		llamadaTemporal->empezarLlamada(horaInicioLlamadaEnCursoTemporal);
	} else {
		// Si recibio un ocupado, pongo la hora de inicio en 0, asi puedo diferenciar
		// ocupados en el metodo de terminar llamadas
		llamadaTemporal->empezarLlamada(0);
		llamadaTemporal->agregarOcupadoRecibido();
	}

}


void Interno::agregarLlamadaReceptor(int emisorTemporal, int horaTemporal )
{
	// Me fijo si la llamada con el receptor esta creada, sino, la creo
	Llamada* llamadaTemporal = creaReceptorLlamada(receptorLlamadaTemporal);

	//Consigo un puntero al receptor, para ver si esta ocupado

	if (! this->internoOcupado()) {
		llamadaTemporal->empezarLlamada(horaInicioLlamadaEnCursoTemporal);
	} else {
		// Si dio un ocupado, pongo la hora de inicio en 0, asi puedo diferenciar
		// ocupados en el metodo de terminar llamadas
		llamadaTemporal->empezarLlamada(0);
		llamadaTemporal->agregarOcupadoDado();

	}
}



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

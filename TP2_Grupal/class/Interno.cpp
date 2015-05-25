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

Lista<Enlace*>* Interno::devolverRecorridoLlamada(int emisorLlamadaTemporal, int receptorLlamadaTemporal)
{
	Llamada* llamadaTemporal = NULL;
	this->llamadas->iniciarCursorNodo();

	while ( this->llamadas->avanzarCursorNodo() && ! existeLlamada) {
		llamadaTemporal = this->obtenerCursorNodo();
		existeLlamada = nodoLlamadaTemporal->obtenerReceptorLlamada() == receptorLlamadaTemporal;
	}
}


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

void Interno::agregarLlamadaEmisor(int receptorTemporal, int horaTemporal, Interno* receptor, Lista<Enlace*>* recorridoLlamadaTemporal )
{
	// Me fijo si la llamada esta creada, sino, la creo
	Llamada* llamadaTemporal = creaReceptorLlamada(receptorLlamadaTemporal);


	if (! receptor->internoOcupado()) {
		llamadaTemporal->empezarLlamadaEmisor(horaInicioLlamadaEnCursoTemporal, recorridoLlamadaTemporal);
	} else {
		// Si recibio un ocupado, pongo la hora de inicio en 0, asi puedo diferenciar
		// ocupados en el metodo de terminar llamadas
		llamadaTemporal->empezarLlamadaEmisor(0, recorridoLlamadaTemporal);
		llamadaTemporal->agregarOcupadoRecibido();
	}

}

void Interno::agregarLlamadaReceptor(int emisorTemporal, int horaTemporal, Lista<Enlace*>* recorridoLlamadaTemporal )
{
	// Me fijo si la llamada con el receptor esta creada, sino, la creo
	Llamada* llamadaTemporal = creaReceptorLlamada(receptorLlamadaTemporal);

	//Consigo un puntero al receptor, para ver si esta ocupado

	if (! this->internoOcupado()) {
		llamadaTemporal->empezarLlamadaReceptor(horaInicioLlamadaEnCursoTemporal);
	} else {
		// Si dio un ocupado, pongo la hora de inicio en 0, asi puedo diferenciar
		// ocupados en el metodo de terminar llamadas
		llamadaTemporal->empezarLlamada(0, recorridoLlamadaTemporal);
		llamadaTemporal->agregarOcupadoDado();

	}
}

#include "Interno.h"

Interno::Interno(int numeroInternoTemporal)
{
	this->numeroInterno = numeroInternoTemporal;
	this->llamadas= new Lista<Llamada*>;
	this->estaOcupado=false;
}


int Interno::obtenerNumero()
{
	return(this->numeroInterno);
}


Lista<Llamada*>* Interno::obtenerLlamadas()
{
	return(this->llamadas);
}


Lista<Enlace*>* Interno::devolverRecorridoLlamada( int receptorLlamadaTemporal)
{
	Llamada* llamadaTemporal;
	bool encontreLlamada = false;
	this->llamadas->iniciarCursorNodo();

	while ( this->llamadas->avanzarCursorNodo() && ! encontreLlamada) {
		llamadaTemporal = this->llamadas->obtenerCursorNodo();
		encontreLlamada = llamadaTemporal->obtenerReceptorLlamada() == receptorLlamadaTemporal;
	}

	return(llamadaTemporal->obtenerRecorridoLlamada() );
}


bool Interno::internoOcupado()
{
	return(this->estaOcupado);
}


Llamada* Interno::creaReceptorLlamada(int receptorLlamadaTemporal, int centralReceptoraTemporal )
{
	bool existeLlamada = false;
	Llamada* llamadaTemporal = NULL;
	this->llamadas->iniciarCursorNodo();

	while ( this->llamadas->avanzarCursorNodo() && ! existeLlamada) {
		llamadaTemporal = this->llamadas->obtenerCursorNodo();
		existeLlamada = llamadaTemporal->obtenerReceptorLlamada() == receptorLlamadaTemporal && llamadaTemporal->obtenerOtraCentral() == centralReceptoraTemporal;
	}

	if (! existeLlamada) {
		Llamada* nuevaLlamada = new Llamada(receptorLlamadaTemporal, centralReceptoraTemporal);
		this->llamadas->insertar(nuevaLlamada);
		llamadaTemporal = nuevaLlamada;
	}

	return(llamadaTemporal);
}


void Interno::agregarLlamadaEmisor(int receptorTemporal, int horaTemporal, int centralReceptoraTemporal, Lista<Enlace*>* recorridoLlamadaTemporal, bool fueAnulada, int precioPorMinuto)
{
	// Me fijo si la llamada esta creada, sino, la creo
	Llamada* llamadaTemporal = creaReceptorLlamada(receptorTemporal, centralReceptoraTemporal);

	if (! this->internoOcupado() && ! fueAnulada ) {
		llamadaTemporal->empezarLlamadaEmisor(horaTemporal, recorridoLlamadaTemporal, fueAnulada, precioPorMinuto);
		this->estaOcupado = true;
	} else if ( this->internoOcupado() ) {
		// Si recibio un ocupado o fue anulada, pongo la hora de inicio en 0, asi puedo diferenciar
		// ocupados en el metodo de terminar llamadas
		llamadaTemporal->empezarLlamadaEmisor(0, recorridoLlamadaTemporal, fueAnulada, precioPorMinuto);
		llamadaTemporal->agregarOcupadoRecibido();
	} else if ( fueAnulada ) {
		//si fue Anulada la diferencio con el flag fueAnulada
		llamadaTemporal->empezarLlamadaReceptor(0, recorridoLlamadaTemporal, fueAnulada, precioPorMinuto);
	}
}


void Interno::agregarLlamadaReceptor(int emisorTemporal, int horaTemporal, int centralEmisoraTemporal,  Lista<Enlace*>* recorridoLlamadaTemporal,  bool fueAnulada, int precioPorMinuto )
{
	// Me fijo si la llamada con el receptor esta creada, sino, la creo
	Llamada* llamadaTemporal = creaReceptorLlamada(emisorTemporal, centralEmisoraTemporal);

	if (! this->internoOcupado() && ! fueAnulada ) {
		llamadaTemporal->empezarLlamadaReceptor(horaTemporal, recorridoLlamadaTemporal, fueAnulada, precioPorMinuto);
		this->estaOcupado = true;
	} else if ( this->internoOcupado()) {
		// Si dio un ocupado pongo la hora de inicio en 0, asi puedo diferenciar
		// ocupados en el metodo de terminar llamadas
		llamadaTemporal->empezarLlamadaReceptor(0, recorridoLlamadaTemporal, fueAnulada, precioPorMinuto);
		llamadaTemporal->agregarOcupadoDado();
	} else if ( fueAnulada ) {
		//si fue Anulada la diferencio con el flag fueAnulada
		llamadaTemporal->empezarLlamadaReceptor(0, recorridoLlamadaTemporal, fueAnulada, precioPorMinuto);
	}
}


void Interno::terminarLlamadaEmisor(int receptorTemporal, int horaTemporal )
{
	this->llamadas->iniciarCursorNodo();
	bool encontroLlamada = false;
	Llamada* llamadaTemporal = NULL;

	while(this->llamadas->avanzarCursorNodo() && ! encontroLlamada) {
		llamadaTemporal = this->llamadas->obtenerCursorNodo();
		encontroLlamada = llamadaTemporal->obtenerReceptorLlamada() == receptorTemporal;
	}

	llamadaTemporal->cortarLlamadaEmisor(horaTemporal);

	this->estaOcupado = false;
}


void Interno::terminarLlamadaReceptor(int emisorTemporal, int horaTemporal )
{
	this->llamadas->iniciarCursorNodo();
	bool encontroLlamada = false;
	Llamada* llamadaTemporal = NULL;

	while(this->llamadas->avanzarCursorNodo() && ! encontroLlamada) {
		llamadaTemporal = this->llamadas->obtenerCursorNodo();
		encontroLlamada = llamadaTemporal->obtenerReceptorLlamada() == emisorTemporal;
	}

	llamadaTemporal->cortarLlamadaReceptor(horaTemporal);

	this->estaOcupado = false;
}


int Interno::contarLlamadasAnuladas(Lista<Llamada*>* listaLlamadas)
{
	int llamadasAnuladas = 0;
	listaLlamadas->iniciarCursorNodo();

	while (listaLlamadas->avanzarCursorNodo()) {
		llamadasAnuladas += listaLlamadas->obtenerCursorNodo()->obtenerLlamadasAnuladas();
	}

	return llamadasAnuladas;
}

Interno::~Interno()
{
	delete(this->llamadas);
}

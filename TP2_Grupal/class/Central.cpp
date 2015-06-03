#include "Central.h"

Central::Central(int numeroCentralTemporal)
{
	this->numeroCentral= numeroCentralTemporal;
	this->internos = new Lista<Interno*>;
	this->enlaces = new Lista<Enlace*>;
}


void Central::crearInterno(int numeroInterno)
{
	this->internos->iniciarCursorNodo();
	bool encontro = false;

	while (this->internos->avanzarCursorNodo() && ! encontro) {
		Interno* internoTemporal = this->internos->obtenerCursorNodo();
		encontro = (internoTemporal->obtenerNumero() == numeroInterno);
	}

	if ( ! encontro ) {
		Interno* internoNuevo = new Interno(numeroInterno);
		this->internos->insertar(internoNuevo);
	}
}


Interno* Central::obtenerInterno(int numeroInterno)
{
	Interno* internoDevolver = NULL;
	Interno* internoTemporal = NULL;
	bool encontro = false;

	this->internos->iniciarCursorNodo();

	while (this->internos->avanzarCursorNodo() && ! encontro) {
		internoTemporal = this->internos->obtenerCursorNodo();
		encontro = (internoTemporal->obtenerNumero() == numeroInterno);
	}
	
	if (encontro) {
		internoDevolver=internoTemporal;
	}
	
	return(internoDevolver);
}


Lista<Interno*>* Central::obtenerInternos()
{
	return(this->internos);
}


Lista<Enlace*>* Central::obtenerEnlaces()
{
	return(this->enlaces);
}


void Central::agregarEnlace(Enlace* enlaceTemporal)
{
	this->enlaces->insertar(enlaceTemporal);
}


int Central::obtenerNumero()
{
	return(this->numeroCentral);
}


int Central::obtenerTotalDeLlamadasAnuladasDeInternos(Lista<Interno*>* internos)
{
	int llamadasAnuladasPorInterno = 0;
	internos->iniciarCursorNodo();
	
	while(this->internos->avanzarCursorNodo()) {
		llamadasAnuladasPorInterno += internos->obtenerCursorNodo()->contarLlamadasAnuladas(internos->obtenerCursorNodo()->obtenerLlamadas());
	}
	
	return llamadasAnuladasPorInterno;
}


Central::~Central()
{
	delete(this->internos);
	delete(this->enlaces);
}

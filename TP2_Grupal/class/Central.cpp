#include "Central.h"

Central::Central(int numeroCentralTemporal)
{
<<<<<<< HEAD
	this->NumeroCentral= numeroCentralTemporal;
	this->internos = new Lista<Internos*>;
	this->enlaces = new Lista<Enlaces*>*;
};
=======
	this->numeroCentral= numeroCentralTemporal;
	this->internos = new Lista<Interno*>;
	this->enlaces = new Lista<Enlace*>;
}
>>>>>>> 9ae36e9e09a56545e7f109a6e4e325a042d43de1

void Central::crearInterno(int numeroInterno)
{
	Interno* internoNuevo = new Interno(numeroInterno);

	this->internos->iniciarCursorNodo();

	bool encontro = false;

	while (this->internos->avanzarCursorNodo() && ! encontro) {
		Interno* internoTemporal = this->internos->obtenerCursorNodo();
		encontro = (internoTemporal->obtenerNumero() == numeroInterno);
	}

	if ( ! encontro ) {
		this->internos->insertar(internoNuevo);
	}
}

Interno* Central::obtenerInterno(int numeroInterno)
{
	Interno* internoDevolver = NULL;

	bool encontro = false;

	this->internos->iniciarCursorNodo();

	while (this->internos->avanzarCursorNodo() && ! encontro) {
		Interno* internoTemporal = this->internos->obtenerCursorNodo();
		encontro = (internoTemporal->obtenerNumero() == numeroInterno);
	}

	return internoDevolver;
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
	return this->numeroCentral;
}

Central::~Central()
{
	delete this->internos;
	delete this->enlaces;
}

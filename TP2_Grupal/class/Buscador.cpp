#include "Buscador.h"

Buscador::Buscador(Lista<Central*>* centrales)
{
	this->centralesTotales = centrales;
	this->mejorCamino = new Lista<Enlace*>;
	this->rutaActual = new Lista<Spot*>;
	this->precioDeLaLlamada = 0;
	this->distanciaDeLaLlamada = 0;
	this->tipoDeBusqueda = 0;
	this->llamadaAnulada = false;
}

Lista<Enlace*>* Buscador::obtenerRuta()
{
	return (this->mejorCamino);
}

int Buscador::obtenerPrecioDeLaLlamada()
{
	return (this->precioDeLaLlamada);
}

int Buscador::obtenerDistanciaDeLaLlamada()
{
	return (this->distanciaDeLaLlamada);
}

void Buscador::encontrarCaminoPorPrecio(int centralEmisora, int centralReceptora)
{
	this->establecerBusquedaPorPrecio();

	if (this->esLlamadaInterna(centralEmisora, centralReceptora)) {
		this->definirEstePrecioYDistancia();
	} else {
		Central* centralActual = this->encontrarLaCentral(centralEmisora);
		Spot* nuevoSpot = new Spot(centralActual, 0, 0);
		this->rutaActual->insertar(nuevoSpot);

		this->ProcesoIterativoPorPrecio(centralActual, centralReceptora);
	}
}

void Buscador::encontrarCaminoPordistancia(int centralEmisora, int centralReceptora)
{
	this->establecerBusquedaPorDistancia();

	if (this->esLlamadaInterna(centralEmisora, centralReceptora)) {
		this->definirEstePrecioYDistancia();
	} else {
		Central* centralActual = this->encontrarLaCentral(centralEmisora);
		Spot* nuevoSpot = new Spot(centralActual, 0, 0);
		this->rutaActual->insertar(nuevoSpot);

		this->ProcesoIterativoPorDistancia(centralActual, centralReceptora);
	}
}

Central* Buscador::encontrarLaCentral(int central)
{
	this->centralesTotales->iniciarCursorNodo();

	while (this->centralesTotales->avanzarCursorNodo()) {

		if (this->centralesTotales->obtenerCursorNodo()->obtenerNumero() == central)
			return (this->centralesTotales->obtenerCursorNodo());
	}
	return (this->centralesTotales->obtenerCursorNodo()); // devuelve NULL
}

bool Buscador::YaPasePorLaCentral(Central* central)
{
	bool noLaEncontre = true;
	this->rutaActual->iniciarCursorNodo();

	while ((this->rutaActual->avanzarCursorNodo()) && (noLaEncontre)) {

		if (this->rutaActual->obtenerCursorNodo()->visitasteLaCentral(central))
			return (noLaEncontre);
	}

	return (!noLaEncontre);
}

bool Buscador::esLlamadaInterna(int centralEmisora, int centralReceptora)
{
	return (centralEmisora == centralReceptora);
}

Interno* Buscador::encontrarInternoEnLa(Central* central, int numeroDeInterno)
{
	return (central->obtenerInterno(numeroDeInterno));
}

void Buscador::definirEstePrecioYDistancia()
{
	this->rutaActual->iniciarCursorNodo();

	if (this->rutaActual->avanzarCursorNodo()) {
		this->precioDeLaLlamada = this->rutaActual->obtenerCursorNodo()->obtenerPrecioHastaSpot();
		this->distanciaDeLaLlamada = this->rutaActual->obtenerCursorNodo()->obtenerDistanciaRecorridaHastaSpot();
	} else {
		this->precioDeLaLlamada = 0;
		this->distanciaDeLaLlamada = 0;
	}
}

bool Buscador::hayMasCaminos()
{
	bool hayMasCaminos = true;

	this->rutaActual->iniciarCursorNodo();
	this->rutaActual->avanzarCursorNodo();
	Spot* primerSpot = this->rutaActual->obtenerCursorNodo();

	this->rutaActual->iniciarCursorNodo();
	this->rutaActual->avanzarCursorPorElFinal();
	Spot* ultimoSpot = this->rutaActual->obtenerCursorNodo();

	if ((ultimoSpot == primerSpot) && (primerSpot->recorriTodosLosEnlaces())) {
		hayMasCaminos = false;
	}
	return (hayMasCaminos);
}

Spot* Buscador::caminar(Enlace* enlaceActual, Spot* spotActual)
{
	Spot* spotDevolver = NULL;
	if (enlaceActual->chequearDisponibilidadCanales()) {

		if (enlaceActual->obtenerDestino()->obtenerNumero() != spotActual->obtenerPosicion()->obtenerNumero()) {

			if (!this->YaPasePorLaCentral(enlaceActual->obtenerDestino())) {
				Central* centralNueva = enlaceActual->obtenerDestino();
				int nuevaDistancia = spotActual->obtenerDistanciaRecorridaHastaSpot() + enlaceActual->obtenerDistancia();
				int nuevoPrecio = spotActual->obtenerPrecioHastaSpot() + enlaceActual->obtenerPrecio();
				Spot* spotNuevo = new Spot(centralNueva, nuevoPrecio, nuevaDistancia);
				this->rutaActual->insertar(spotNuevo);
				spotActual->anotarCaminoRecorrido(centralNueva, enlaceActual);
				spotNuevo->anotarCaminoRecorrido(spotActual->obtenerPosicion(), enlaceActual);
				spotDevolver = spotNuevo;
			}
		} else {

			if (!this->YaPasePorLaCentral(enlaceActual->obtenerOrigen())) {
				Central* centralNueva = enlaceActual->obtenerOrigen();
				int nuevaDistancia = spotActual->obtenerDistanciaRecorridaHastaSpot() + enlaceActual->obtenerDistancia();
				int nuevoPrecio = spotActual->obtenerPrecioHastaSpot() + enlaceActual->obtenerPrecio();
				Spot* spotNuevo = new Spot(centralNueva, nuevoPrecio, nuevaDistancia);
				this->rutaActual->insertar(spotNuevo);
				spotActual->anotarCaminoRecorrido(centralNueva, enlaceActual);
				spotNuevo->anotarCaminoRecorrido(spotActual->obtenerPosicion(), enlaceActual);
				spotDevolver = spotNuevo;
			}
		}
	}

	if (spotDevolver == NULL)
		this->anularLlamada();

	return spotDevolver;
}

void Buscador::definirEstaRuta()
{
	this->rutaActual->iniciarCursorNodo();
	// salteo el spot de la central de llegada por como esta hecha la lista.
	this->rutaActual->avanzarCursorNodo();
	while (this->rutaActual->avanzarCursorNodo()) {
		Spot* spotActual = this->rutaActual->obtenerCursorNodo();
		this->mejorCamino->insertar(spotActual->obtenerEnlaceRecorrido());
	}
	this->llamadaAnulada = false;
}

void Buscador::establecerBusquedaPorPrecio()
{
	this->tipoDeBusqueda = 0;
}

void Buscador::establecerBusquedaPorDistancia()
{
	this->tipoDeBusqueda = 1;
}

int Buscador::obtenerTipoDeBusqueda()
{
	return (this->tipoDeBusqueda);
}

Central* Buscador::obtenerCentralEmisora(int centralEmisora)
{
	this->mejorCamino->iniciarCursorNodo();
	this->mejorCamino->avanzarCursorPorElFinal();
	if (this->mejorCamino->obtenerCursorNodo()->obtenerOrigen()->obtenerNumero() == centralEmisora)
		return (this->mejorCamino->obtenerCursorNodo()->obtenerOrigen());
	else
		return (this->mejorCamino->obtenerCursorNodo()->obtenerOrigen());
}

Central* Buscador::obtenerCentralReceptora(int centralReceptora)
{
	this->mejorCamino->iniciarCursorNodo();
	this->mejorCamino->avanzarCursorNodo();
	if (this->mejorCamino->obtenerCursorNodo()->obtenerOrigen()->obtenerNumero() == centralReceptora)
		return (this->mejorCamino->obtenerCursorNodo()->obtenerOrigen());
	else
		return (this->mejorCamino->obtenerCursorNodo()->obtenerOrigen());
}

Interno* Buscador::obtenerInternoEmisor(int emisor)
{
	Central* centralEmisora = this->obtenerCentralEmisora(emisor);
	return (centralEmisora->obtenerInterno(emisor));
}

Interno* Buscador::obtenerInternoReceptor(int receptor)
{
	Central* centralReceptora = this->obtenerCentralReceptora(receptor);
	return (centralReceptora->obtenerInterno(receptor));
}

bool Buscador::noEstaAnuladaLaLlamada()
{
	return this->llamadaAnulada;
}

void Buscador::anularLlamada()
{
	this->llamadaAnulada = true;
}

void Buscador::borrarUnSpot()
{
	Lista<Spot*>* rutaActual = this->obtenerRutaActual();
	rutaActual->iniciarCursorNodo();
	if (rutaActual->avanzarCursorNodo()) {
		Spot* spotActual = rutaActual->obtenerCursorNodo();
		spotActual->resetListaEnlaces();
		rutaActual->remover();
		delete spotActual;
	}
	rutaActual->iniciarCursorNodo();
	rutaActual->avanzarCursorNodo();
}

void Buscador::borrarRutaActual()
{
	Lista<Spot*>* rutaActual = this->obtenerRutaActual();
	rutaActual->iniciarCursorNodo();
	while (rutaActual->avanzarCursorNodo()) {
		Spot* spotActual = rutaActual->obtenerCursorNodo();
		rutaActual->remover();
		delete spotActual;
	}
}

Lista<Spot*>* Buscador::obtenerRutaActual()
{
	return (this->rutaActual);
}

void Buscador::resetDatos()
{
	Lista<Enlace*>* nuevoMejorCamino = new Lista<Enlace*>;
	Lista<Spot*>* nuevaRutaActual = new Lista<Spot*>;
	this->mejorCamino = nuevoMejorCamino;
	this->rutaActual = nuevaRutaActual;
	this->precioDeLaLlamada = 0;
	this->distanciaDeLaLlamada = 0;
	this->tipoDeBusqueda = 0;
	this->llamadaAnulada = false;
}

void Buscador::ProcesoIterativoPorPrecio(Central* centralActual, int centralReceptora)
{
	bool llegue = false;
	Spot* spotActual;

	while ((!this->noEstaAnuladaLaLlamada()) && (this->hayMasCaminos())) {
		this->rutaActual->iniciarCursorNodo();
		this->rutaActual->avanzarCursorNodo();
		spotActual = this->rutaActual->obtenerCursorNodo();
		int precioActual = this->obtenerPrecioDeLaLlamada();
		int buscoMejorValor = -1;

		while (((!this->noEstaAnuladaLaLlamada()) && (precioActual > buscoMejorValor)) &&
		       ((!spotActual->recorriTodosLosEnlaces()) && (!llegue))) {

			if (centralActual->obtenerNumero() != centralReceptora) {
				buscoMejorValor = spotActual->obtenerPrecioHastaSpot();

				if ((precioActual > buscoMejorValor) || (precioActual == 0)) {

					if (!spotActual->recorriTodosLosEnlaces() &&
					    (spotActual->obtenerPosicion()->obtenerNumero() != centralReceptora)) {
						spotActual = this->caminar(spotActual->obtenerEnlaceSiguiente(), spotActual);
					}

					if ((!this->noEstaAnuladaLaLlamada()) &&
					    (spotActual->obtenerPosicion()->obtenerNumero() == centralReceptora)) {
						this->definirEstePrecioYDistancia();
						this->definirEstaRuta();
						llegue = true;
					}
				}
			}
		}

		if (!this->noEstaAnuladaLaLlamada()) {
			this->borrarUnSpot(); // el cursor esta al final
			llegue = false;
		}
	}

	if (this->noEstaAnuladaLaLlamada()) {
		this->anularLlamada();
	}
}

void Buscador::ProcesoIterativoPorDistancia(Central* centralActual, int centralReceptora)
{
	bool llegue = false;
	Spot* spotActual;
	while ((!this->noEstaAnuladaLaLlamada()) && (this->hayMasCaminos())) {
		this->rutaActual->iniciarCursorNodo();
		this->rutaActual->avanzarCursorNodo();
		spotActual = this->rutaActual->obtenerCursorNodo();
		int distanciaActual = this->obtenerDistanciaDeLaLlamada();
		int buscoMejorValor = -1;
		while (((!this->noEstaAnuladaLaLlamada()) && (distanciaActual > buscoMejorValor)) &&
		       ((!spotActual->recorriTodosLosEnlaces()) && (!llegue))) {
			if (centralActual->obtenerNumero() != centralReceptora) {
				buscoMejorValor = spotActual->obtenerDistanciaRecorridaHastaSpot();
				if ((distanciaActual > buscoMejorValor) || (distanciaActual == 0)) {
					if (!spotActual->recorriTodosLosEnlaces() &&
					    (spotActual->obtenerPosicion()->obtenerNumero() != centralReceptora)) {
						spotActual = this->caminar(spotActual->obtenerEnlaceSiguiente(), spotActual);
					}
					if ((!this->noEstaAnuladaLaLlamada()) &&
					    (spotActual->obtenerPosicion()->obtenerNumero() == centralReceptora)) {
						this->definirEstePrecioYDistancia();
						this->definirEstaRuta();
						llegue = true;
					}
				}
			}
		}
		if (!this->noEstaAnuladaLaLlamada()) {
			this->borrarUnSpot(); // el cursor esta al final
			llegue = false;
		}
	}
	if (this->noEstaAnuladaLaLlamada()) {
		this->anularLlamada();
	}
}

bool Buscador::visitasteLaCentral(Central* centralActual)
{
	bool laEncontre = false;
	this->rutaActual->iniciarCursorNodo();
	while (this->rutaActual->avanzarCursorNodo()) {
		Spot* spotActual = this->rutaActual->obtenerCursorNodo();
		if (spotActual->visiteLaCentral(centralActual))
			laEncontre = true;
	}
	return (laEncontre);
}

Buscador::~Buscador()
{
	this->borrarRutaActual();
	delete (this->mejorCamino);
	delete (this->rutaActual);
}

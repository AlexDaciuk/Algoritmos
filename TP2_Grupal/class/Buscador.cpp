

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
	Central* centralActual = this->encontrarLaCentral(centralEmisora);
	Spot* nuevoSpot = new Spot(centralActual, 0, 0);
	this->rutaActual->insertar(nuevoSpot);
	if(this->esLlamadaInterna(centralEmisora, centralReceptora)) {
		this->definirEstePrecioYDistancia();
		//rutaActual y mejorCamino permanecen como NULL
	} else {
		this->rutaActual->iniciarCursorNodo();
		while(this->hayMasCaminos()) {
			if(centralActual->obtenerNumero() != centralReceptora) {
				int buscoMejorValor = this->rutaActual->obtenerCursorNodo()->obtenerPrecioHastaSpot();
				this->avanzarBusquedaDesde(centralActual,buscoMejorValor, this->obtenerPrecioDeLaLlamada(), centralReceptora);
			} else {
				Spot* spotActual = this->rutaActual->obtenerCursorNodo();
				Lista<Enlace*>* enlacesActuales = centralActual->obtenerEnlaces();
				enlacesActuales->iniciarCursorNodo();
				if((!spotActual->recorriTodosLosEnlaces()) || (enlacesActuales->avanzarCursorNodo())) {
					caminarEnlace(centralActual, centralReceptora);
				} else {
					while(spotActual != NULL) {
						this->borrarUnSpot();
						this->rutaActual->avanzarCursorPorElFinal();
						spotActual = this->rutaActual->obtenerCursorNodo();
					if(spotActual != NULL) {
						int buscoMejorValor = this->rutaActual->obtenerCursorNodo()->obtenerPrecioHastaSpot();
						centralActual = this->rutaActual->obtenerCursorNodo()->obtenerPosicion();
						int precioActual =  this->obtenerPrecioDeLaLlamada();
						while(((precioActual > buscoMejorValor) || (precioActual == 0)) &&
						      ((centralActual->obtenerNumero() != centralReceptora) && (!this->YaPasePorLaCentral(centralActual))))
						{
							this->caminarEnlace(centralActual, centralReceptora);
						}
					}
					}
				}
			}
		}
		if(this->obtenerRuta() == NULL)
			this->anularLlamada();
	}
}

void Buscador::encontrarCaminoPordistancia(int centralEmisora, int centralReceptora)
{
	this->establecerBusquedaPorDistancia();
	Central* centralActual = this->encontrarLaCentral(centralEmisora);
	Spot* nuevoSpot = new Spot(centralActual, 0, 0);
	this->rutaActual->insertar(nuevoSpot);
	if(this->esLlamadaInterna(centralEmisora, centralReceptora)) {
		this->definirEstePrecioYDistancia();
		//rutaActual y mejorCamino permanecen como NULL
	} else {
		this->rutaActual->iniciarCursorNodo();
		while(this->hayMasCaminos()) {
			if(centralActual->obtenerNumero() != centralReceptora) {
				int buscoMejorValor = this->rutaActual->obtenerCursorNodo()->obtenerDistanciaRecorrida();
				this->avanzarBusquedaDesde(centralActual,buscoMejorValor, this->obtenerDistanciaDeLaLlamada(), centralReceptora);
			} else {
				Spot* spotActual = this->rutaActual->obtenerCursorNodo();
				Lista<Enlace*>* enlacesActuales = centralActual->obtenerEnlaces();
				enlacesActuales->iniciarCursorNodo();
				if((!spotActual->recorriTodosLosEnlaces()) || (enlacesActuales->avanzarCursorNodo())) {
					caminarEnlace(centralActual, centralReceptora);
				} else {
					while(spotActual != NULL) {
						this->borrarUnSpot();
						this->rutaActual->avanzarCursorPorElFinal();
						spotActual = this->rutaActual->obtenerCursorNodo();
						if(spotActual != NULL) {
							int buscoMejorValor = this->rutaActual->obtenerCursorNodo()->obtenerDistanciaRecorrida();
							int distanciaActual = this->obtenerDistanciaDeLaLlamada();
							centralActual = this->rutaActual->obtenerCursorNodo()->obtenerPosicion();
							while(((distanciaActual > buscoMejorValor) || (distanciaActual == 0)) &&
								  ((centralActual->obtenerNumero() != centralReceptora) && (!this->YaPasePorLaCentral(centralActual)))) 
							{
								this->caminarEnlace(centralActual, centralReceptora);
							}
						}
						}
					}
				}
			}
		if(this->obtenerRuta() == NULL)
			this->anularLlamada();
	}
}

Central* Buscador::encontrarLaCentral(int central)
{
	this->centralesTotales->iniciarCursorNodo();
	while(this->centralesTotales->avanzarCursorNodo()) {
		if(this->centralesTotales->obtenerCursorNodo()->obtenerNumero() == central)
			return (this->centralesTotales->obtenerCursorNodo());
	}
	return (this->centralesTotales->obtenerCursorNodo());//devuelve NULL
}

bool Buscador::YaPasePorLaCentral(Central* central)
{
	bool laEncontre = true;
	this->rutaActual->iniciarCursorNodo();
	while((this->rutaActual->avanzarCursorNodo()) && (!laEncontre)) {
		if(this->rutaActual->obtenerCursorNodo()->visitasteLacentral(central))
			return (laEncontre);
	}
		return (!laEncontre);
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
	this->rutaActual->avanzarCursorPorElFinal();
	this->precioDeLaLlamada = this->rutaActual->obtenerCursorNodo()->obtenerPrecioHastaSpot();
	this->distanciaDeLaLlamada = this->rutaActual->obtenerCursorNodo()->obtenerDistanciaRecorrida();
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

	if((ultimoSpot == primerSpot) && (primerSpot->recorriTodosLosEnlaces())) {
		hayMasCaminos = false;
	}
	return (hayMasCaminos);
}


void Buscador::caminarEnlace(Central* centralActual, int centralReceptora)
{
	Lista<Enlace*>* enlacesActuales = centralActual->obtenerEnlaces();
	Spot* spotActual = this->rutaActual->obtenerCursorNodo();
	enlacesActuales->iniciarCursorNodo();
	while((!spotActual->recorriTodosLosEnlaces()) || (enlacesActuales->avanzarCursorNodo())) {
		if(this->obtenerTipoDeBusqueda() == 0)
			caminarPorPrecio(enlacesActuales->obtenerCursorNodo(), spotActual, centralReceptora);
		else
			caminarPorDistancia(enlacesActuales->obtenerCursorNodo(), spotActual, centralReceptora);
	}
}


void Buscador::avanzarBusquedaDesde(Central* centralActual, int buscoMejorValor, int precioActual, int centralReceptora)
{
	this->rutaActual->avanzarCursorNodo();
	while(((precioActual > buscoMejorValor) || (precioActual == 0)) &&
	      (centralActual->obtenerNumero() != centralReceptora)) {
		this->caminarEnlace(centralActual, centralReceptora);
	}
	if(centralActual->obtenerNumero() == centralReceptora) {
		this->definirEstePrecioYDistancia();
		this->definirEstaRuta();
	}
}

void Buscador::caminarPorPrecio(Enlace* enlaceActual, Spot* spotActual, int centralReceptora)
{
	if(enlaceActual->chequearDisponibilidadCanales()) {
		if(enlaceActual->obtenerDestino()->obtenerNumero() != spotActual->obtenerPosicion()->obtenerNumero()) {
			if(!this->YaPasePorLaCentral(enlaceActual->obtenerDestino())) {
				Central* centralNueva = enlaceActual->obtenerDestino();
				int nuevaDistancia = spotActual->obtenerDistanciaRecorrida() + enlaceActual->obtenerDistancia();
				int nuevoPrecio = spotActual->obtenerPrecioHastaSpot() + enlaceActual->obtenerPrecio();
				Spot* spotNuevo = new Spot(centralNueva, nuevoPrecio, nuevaDistancia);
				this->rutaActual->insertar(spotNuevo);

				spotActual->anotarCaminoRecorrido(centralNueva, enlaceActual);

				this->avanzarBusquedaDesde(centralNueva,nuevoPrecio,this->obtenerPrecioDeLaLlamada(), centralReceptora);
			}
		} else {
			if(!this->YaPasePorLaCentral(enlaceActual->obtenerOrigen())) {
				Central* centralNueva = enlaceActual->obtenerOrigen();
				int nuevaDistancia = spotActual->obtenerDistanciaRecorrida() + enlaceActual->obtenerDistancia();
				int nuevoPrecio = spotActual->obtenerPrecioHastaSpot() + enlaceActual->obtenerPrecio();
				Spot* spotNuevo = new Spot(centralNueva, nuevoPrecio, nuevaDistancia);
				this->rutaActual->insertar(spotNuevo);

				spotActual->anotarCaminoRecorrido(centralNueva, enlaceActual);

				this->avanzarBusquedaDesde(centralNueva,nuevoPrecio,this->obtenerPrecioDeLaLlamada(),centralReceptora);
			}
		}
	}
}

void Buscador::caminarPorDistancia(Enlace* enlaceActual, Spot* spotActual, int centralReceptora)
{
	if(enlaceActual->chequearDisponibilidadCanales()) {
		if(enlaceActual->obtenerDestino()->obtenerNumero() != spotActual->obtenerPosicion()->obtenerNumero()) {
			if(!this->YaPasePorLaCentral(enlaceActual->obtenerDestino())) {
				Central* centralNueva = enlaceActual->obtenerDestino();
				int nuevaDistancia = spotActual->obtenerDistanciaRecorrida() + enlaceActual->obtenerDistancia();
				int nuevoPrecio = spotActual->obtenerPrecioHastaSpot() + enlaceActual->obtenerPrecio();
				 Spot* spotNuevo = new Spot(centralNueva, nuevoPrecio, nuevaDistancia);
				this->rutaActual->insertar(spotNuevo);

				spotActual->anotarCaminoRecorrido(centralNueva, enlaceActual);

				this->avanzarBusquedaDesde(centralNueva,nuevaDistancia,this->obtenerDistanciaDeLaLlamada(), centralReceptora);
			}
		} else {
			if(!this->YaPasePorLaCentral(enlaceActual->obtenerOrigen())) {
				Central* centralNueva = enlaceActual->obtenerOrigen();
				int nuevaDistancia = spotActual->obtenerDistanciaRecorrida() + enlaceActual->obtenerDistancia();
				int nuevoPrecio = spotActual->obtenerPrecioHastaSpot() + enlaceActual->obtenerPrecio();
				Spot* spotNuevo = new Spot(centralNueva, nuevoPrecio, nuevaDistancia);
				this->rutaActual->insertar(spotNuevo);

				spotActual->anotarCaminoRecorrido(centralNueva, enlaceActual);

				this->avanzarBusquedaDesde(centralNueva,nuevaDistancia,this->obtenerDistanciaDeLaLlamada(),centralReceptora);
			}
		}
	}
}

void Buscador::definirEstaRuta()
{
	this->rutaActual->iniciarCursorNodo();
	while(this->rutaActual->avanzarCursorNodo()) {
		Spot* spotActual = this->rutaActual->obtenerCursorNodo();
		this->mejorCamino->insertar(spotActual->obtenerEnlaceRecorrido());
	}
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
	if(this->mejorCamino->obtenerCursorNodo()->obtenerOrigen()->obtenerNumero() == centralEmisora)
		return(this->mejorCamino->obtenerCursorNodo()->obtenerOrigen());
	else
		return(this->mejorCamino->obtenerCursorNodo()->obtenerOrigen());
}

Central* Buscador::obtenerCentralReceptora(int centralReceptora)
{
	this->mejorCamino->iniciarCursorNodo();
	this->mejorCamino->avanzarCursorNodo();
	if(this->mejorCamino->obtenerCursorNodo()->obtenerOrigen()->obtenerNumero() == centralReceptora)
		return(this->mejorCamino->obtenerCursorNodo()->obtenerOrigen());
	else
		return(this->mejorCamino->obtenerCursorNodo()->obtenerOrigen());
}

Interno* Buscador::obtenerInternoEmisor(int emisor)
{
	Central* centralEmisora = this->obtenerCentralEmisora(emisor);
	return (centralEmisora->obtenerInterno(emisor));
}

Interno* Buscador::obtenerInternoReceptor(int receptor)
{
	Central* centralReceptora = this->obtenerCentralReceptora(receptor);
	return(centralReceptora->obtenerInterno(receptor));
}

bool Buscador::estaAnuladaLaLlamada()
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
	if(rutaActual->avanzarCursorNodo())
	{
		Spot* spotActual = rutaActual->obtenerCursorNodo();
		rutaActual->remover();
		delete spotActual;
	}
}

void Buscador::borrarRutaActual()
{
	Lista<Spot*>* rutaActual = this->obtenerRutaActual();
	rutaActual->iniciarCursorNodo();
	while(rutaActual->avanzarCursorNodo())
	{
		Spot* spotActual = rutaActual->obtenerCursorNodo();
		rutaActual->remover();
		delete spotActual;
	}
}

Lista<Spot*>* Buscador::obtenerRutaActual()
{
	return (this->rutaActual);
}

Buscador::~Buscador()
{
	this->borrarRutaActual();
	
	delete (this->mejorCamino);
	delete (this->rutaActual);
}


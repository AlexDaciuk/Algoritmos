#include "Buscador.h"
#include <iostream>
Buscador::Buscador(Lista<Central*>* centrales)
{
	this->centralesTotales = centrales;
	this->mejorCamino = new Lista<Enlace*>;
	this->rutaActual = new Lista<Spot*>;
	this->precioDeLaLlamada = 0;
	this->distanciaDeLaLlamada = 0;
	this->tipoDeBusqueda = 0;
	this->llamadaAnulada = true;
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

	if(this->esLlamadaInterna(centralEmisora, centralReceptora)) {
		this->definirEstePrecioYDistancia();
	} else {
		Central* centralActual = this->encontrarLaCentral(centralEmisora);
		Spot* nuevoSpot = new Spot(centralActual, 0, 0);
		this->rutaActual->insertar(nuevoSpot);
		this->ProcesoIterativoPorPrecio(centralActual, centralReceptora);
		std::cout<<"jeje\n";
	}
}

void Buscador::encontrarCaminoPordistancia(int centralEmisora, int centralReceptora)
{
	this->establecerBusquedaPorDistancia();

	if(this->esLlamadaInterna(centralEmisora, centralReceptora)) {
		this->definirEstePrecioYDistancia();
	} else {
		Central* centralActual = this->encontrarLaCentral(centralEmisora);
		Spot* nuevoSpot = new Spot(centralActual, 0, 0);
		this->rutaActual->insertar(nuevoSpot);
		this->rutaActual->iniciarCursorNodo();
		this->rutaActual->avanzarCursorNodo();
		Spot* spotActual = this->rutaActual->obtenerCursorNodo();
		this->ProcesoIterativoPorDistancia(centralActual, spotActual, centralReceptora);
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
	bool noLaEncontre = true;
	this->rutaActual->iniciarCursorNodo();
	while((this->rutaActual->avanzarCursorNodo()) && (noLaEncontre)) {
		if(this->rutaActual->obtenerCursorNodo()->visitasteLaCentral(central))
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
	if(this->rutaActual->avanzarCursorNodo()) {
		this->precioDeLaLlamada = this->rutaActual->obtenerCursorNodo()->obtenerPrecioHastaSpot();
		this->distanciaDeLaLlamada = this->rutaActual->obtenerCursorNodo()->obtenerDistanciaRecorrida();
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
	std::cout<<"El primer spot tiene a :"<<primerSpot->obtenerPosicion()->obtenerNumero()<<"\n";
	std::cout<<"El ultimo spot tiene a :"<<ultimoSpot->obtenerPosicion()->obtenerNumero()<<"\n";
	if((ultimoSpot == primerSpot) && (primerSpot->recorriTodosLosEnlaces())) {
		hayMasCaminos = false;
	}
	std::cout<<"Hay mas caminos dice :"<<hayMasCaminos<<"\n";
	return (hayMasCaminos);
}



Spot* Buscador::caminarPorPrecio(Enlace* enlaceActual, Spot* spotActual)
{		
	Spot* spotDevolver = NULL;
	if(enlaceActual->chequearDisponibilidadCanales()) {
		if(enlaceActual->obtenerDestino()->obtenerNumero() != spotActual->obtenerPosicion()->obtenerNumero()) {
			if(!this->YaPasePorLaCentral(enlaceActual->obtenerDestino())) {
				Central* centralNueva = enlaceActual->obtenerDestino();
				int nuevaDistancia = spotActual->obtenerDistanciaRecorrida() + enlaceActual->obtenerDistancia();
				int nuevoPrecio = spotActual->obtenerPrecioHastaSpot() + enlaceActual->obtenerPrecio();
				Spot* spotNuevo = new Spot(centralNueva, nuevoPrecio, nuevaDistancia);
				this->rutaActual->insertar(spotNuevo);
				std::cout<<"El nuevo spot tiene la central :"<<spotNuevo->obtenerPosicion()->obtenerNumero()<<"\n";
				spotActual->anotarCaminoRecorrido(centralNueva, enlaceActual);
				spotDevolver = spotNuevo;
			}
		} else {
			if(!this->YaPasePorLaCentral(enlaceActual->obtenerOrigen())) {
				Central* centralNueva = enlaceActual->obtenerOrigen();
				int nuevaDistancia = spotActual->obtenerDistanciaRecorrida() + enlaceActual->obtenerDistancia();
				int nuevoPrecio = spotActual->obtenerPrecioHastaSpot() + enlaceActual->obtenerPrecio();
				Spot* spotNuevo = new Spot(centralNueva, nuevoPrecio, nuevaDistancia);
				this->rutaActual->insertar(spotNuevo);
				std::cout<<"El nuevo spot tiene la central :"<<spotNuevo->obtenerPosicion()->obtenerNumero()<<"\n";
				spotActual->anotarCaminoRecorrido(centralNueva, enlaceActual);

				spotDevolver = spotNuevo;
			}
		}
	}
	return spotDevolver;
}

Spot* Buscador::caminarPorDistancia(Enlace* enlaceActual, Spot* spotActual)
{
	Spot* spotDevolver = NULL;
	if(enlaceActual->chequearDisponibilidadCanales()) {
		if(enlaceActual->obtenerDestino()->obtenerNumero() != spotActual->obtenerPosicion()->obtenerNumero()) {
			if(!this->YaPasePorLaCentral(enlaceActual->obtenerDestino())) {
				Central* centralNueva = enlaceActual->obtenerDestino();
				int nuevaDistancia = spotActual->obtenerDistanciaRecorrida() + enlaceActual->obtenerDistancia();
				int nuevoPrecio = spotActual->obtenerPrecioHastaSpot() + enlaceActual->obtenerPrecio();
				Spot* spotNuevo = new Spot(centralNueva, nuevoPrecio, nuevaDistancia);
				this->rutaActual->insertar(spotNuevo);
				spotActual->anotarCaminoRecorrido(centralNueva, enlaceActual);
				spotDevolver = spotNuevo;
			}
		} else {
			if(!this->YaPasePorLaCentral(enlaceActual->obtenerOrigen())) {
				Central* centralNueva = enlaceActual->obtenerOrigen();
				int nuevaDistancia = spotActual->obtenerDistanciaRecorrida() + enlaceActual->obtenerDistancia();
				int nuevoPrecio = spotActual->obtenerPrecioHastaSpot() + enlaceActual->obtenerPrecio();
				Spot* spotNuevo = new Spot(centralNueva, nuevoPrecio, nuevaDistancia);
				this->rutaActual->insertar(spotNuevo);
				spotDevolver = spotNuevo;
			}
		}
	}
	return spotDevolver;
}

void Buscador::definirEstaRuta()
{
	this->rutaActual->iniciarCursorNodo();
	//salteo el spot de la central de llegada por como esta hecha la lista.
	this->rutaActual->avanzarCursorNodo();
	while(this->rutaActual->avanzarCursorNodo()) {
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
	if(rutaActual->avanzarCursorNodo()) {
		Spot* spotActual = rutaActual->obtenerCursorNodo();
std::cout<<"la central borrada es :"<<spotActual->obtenerPosicion()->obtenerNumero()<<"\n";
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
	while(rutaActual->avanzarCursorNodo()) {
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

Enlace* Buscador::PosicionarEnUltimoEnlaceVisitadoDela(Lista<Enlace*>* enlacesDelSpot, Spot* spotActual)
{
	bool mePosicione = false;
	Enlace* enlaceActual;
	if(spotActual->obtenerEnlaceRecorrido() != NULL) {
		Enlace* posicionEnlace = spotActual->obtenerEnlaceRecorrido();
		enlacesDelSpot->iniciarCursorNodo();
		while((enlacesDelSpot->avanzarCursorNodo()) && (!mePosicione)) {
			enlaceActual = enlacesDelSpot->obtenerCursorNodo();
			if((enlaceActual->obtenerDestino() == posicionEnlace->obtenerDestino()) &&
			   (enlaceActual->obtenerOrigen() == posicionEnlace->obtenerOrigen()))
				mePosicione= true;
		}
	} else {
		enlacesDelSpot->iniciarCursorNodo();
		enlacesDelSpot->avanzarCursorNodo();
		enlaceActual = enlacesDelSpot->obtenerCursorNodo();
	}
	return enlaceActual;
}

void Buscador::ProcesoIterativoPorPrecio(Central* centralActual, int centralReceptora)
{
	bool llegue=false;
	Spot* spotActual;
	std::cout<<"la central "<<centralActual->obtenerNumero()<<" tiene Enlaces :\n";
			Lista<Enlace*>* enlaces = centralActual->obtenerEnlaces();
			enlaces->iniciarCursorNodo();
			while(enlaces->avanzarCursorNodo()){
				std::cout<<"I\n";
			}
	while(this->hayMasCaminos()) {
	this->rutaActual->iniciarCursorNodo();
	this->rutaActual->avanzarCursorNodo();
	 spotActual = this->rutaActual->obtenerCursorNodo();
    std::cout<<"la central 1°paso es :"<<spotActual->obtenerPosicion()->obtenerNumero()<<"\n";
		
		while((!spotActual->recorriTodosLosEnlaces()) && (!llegue)) {
			if(centralActual->obtenerNumero() != centralReceptora) {
				int buscoMejorValor = spotActual->obtenerPrecioHastaSpot();
				
			std::cout<<"la central de ahora es :"<<spotActual->obtenerPosicion()->obtenerNumero()<<"\n";
			int a;
			std::cin>>a;
				int precioActual = this->obtenerPrecioDeLaLlamada();
				if((precioActual > buscoMejorValor) || (precioActual == 0)) {
			
		std::cout<<"recorriTodosLosEnlaces dice :"<<spotActual->recorriTodosLosEnlaces()<<"\n";
		//std::cout<<"verSiHayMasEnlaces dice :"<<spotActual->VerSiHayMasEnlaces()<<"\n";
					if(!spotActual->recorriTodosLosEnlaces()) {
						//this->PosicionarEnUltimoEnlaceVisitadoDela(spotActual->obtenerPosicion()->obtenerEnlaces(), spotActual);
						spotActual = this->caminarPorPrecio(spotActual->obtenerEnlaceSiguiente(), spotActual);
					}
					if (spotActual->obtenerPosicion()->obtenerNumero() == centralReceptora) {
						this->definirEstePrecioYDistancia();
						this->definirEstaRuta();
						std::cout<<"llegue\n";
						llegue = true;
					}
				}
			}

		}
		std::cout<<"borrando\n";
		this->borrarUnSpot();//el cursor esta al final
		this->rutaActual->iniciarCursorNodo();
		std::cout<<"la centrales despues de borrar son :";
		while(this->rutaActual->avanzarCursorNodo()){
		spotActual = this->rutaActual->obtenerCursorNodo();
		std::cout<<spotActual->obtenerPosicion()->obtenerNumero()<<"\n";
		}
	}
	std::cout<<"Sali!\n";
	if(this->estaAnuladaLaLlamada()){
		this->anularLlamada();
		std::cout<<"Anule la llamada!!\n";
	}
}

//!this->visitasteLaCentral(spotActual->obtenerPosicion())

void Buscador::ProcesoIterativoPorDistancia(Central* centralActual, Spot* spotActual, int centralReceptora)
{
	bool llegue=false;
	while(this->hayMasCaminos()) {
		while((!this->visitasteLaCentral(spotActual->obtenerPosicion())) && (!llegue)) {
			if(centralActual->obtenerNumero() != centralReceptora) {
				int buscoMejorValor = spotActual->obtenerDistanciaRecorrida();
				int distanciaActual = this->obtenerDistanciaDeLaLlamada();
				if((distanciaActual > buscoMejorValor) || (distanciaActual == 0)) {
					if((!spotActual->recorriTodosLosEnlaces()) && (spotActual->VerSiHayMasEnlaces())) {
						this->PosicionarEnUltimoEnlaceVisitadoDela(spotActual->obtenerPosicion()->obtenerEnlaces(), spotActual);
						spotActual = this->caminarPorDistancia(spotActual->obtenerEnlaceSiguiente(), spotActual);
					}
					if (spotActual->obtenerPosicion()->obtenerNumero() == centralReceptora) {
						this->definirEstePrecioYDistancia();
						this->definirEstaRuta();
						llegue = true;
					}
				}
			}

		}
		this->borrarUnSpot();//el cursor esta al final

	}
	if(this->estaAnuladaLaLlamada())
		this->anularLlamada();

}


bool Buscador::visitasteLaCentral(Central* centralActual)
{
	bool laEncontre=false;
	this->rutaActual->iniciarCursorNodo();
	std::cout<<"Entre al while(misma cantidad de Spots) : \n";
	while(this->rutaActual->avanzarCursorNodo())
	{
		std::cout<<"I \n";
		Spot* spotActual = this->rutaActual->obtenerCursorNodo();
		if(spotActual->visiteLaCentral(centralActual))
			laEncontre = true;
	}
	return(laEncontre);
}


Buscador::~Buscador()
{
	this->borrarRutaActual();

	delete (this->mejorCamino);
	delete (this->rutaActual);

}

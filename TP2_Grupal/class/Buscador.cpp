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

	if(this->esLlamadaInterna(centralEmisora, centralReceptora)) {
		this->definirEstePrecioYDistancia();
	} else {
		Central* centralActual = this->encontrarLaCentral(centralEmisora);
		std::cout<<"Primer Central :"<<centralActual->obtenerNumero()<<"\n";
		Spot* nuevoSpot = new Spot(centralActual, 0, 0);
		this->rutaActual->insertar(nuevoSpot);
		this->rutaActual->iniciarCursorNodo();
		this->rutaActual->avanzarCursorNodo();
		Spot* spotActual = this->rutaActual->obtenerCursorNodo();
		this->ProcesoIterativo(centralActual, spotActual, centralReceptora);
	}
}

void Buscador::encontrarCaminoPordistancia(int centralEmisora, int centralReceptora)
{
	this->establecerBusquedaPorDistancia();

	if(this->esLlamadaInterna(centralEmisora, centralReceptora)) {
		this->definirEstePrecioYDistancia();
	} else {
		Central* centralActual = this->encontrarLaCentral(centralEmisora);
		std::cout<<"Primer Central :"<<centralActual->obtenerNumero()<<"\n";
		Spot* nuevoSpot = new Spot(centralActual, 0, 0);
		this->rutaActual->insertar(nuevoSpot);
		this->rutaActual->iniciarCursorNodo();
		this->rutaActual->avanzarCursorNodo();
		Spot* spotActual = this->rutaActual->obtenerCursorNodo();
		this->ProcesoIterativo(centralActual, spotActual, centralReceptora);
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
		if(this->rutaActual->obtenerCursorNodo()->visitasteLacentral(central))
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
	if(this->rutaActual->avanzarCursorPorElFinal()) {
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

	std::cout<<"recorriTodosLosEnlaces dice :"<<primerSpot->recorriTodosLosEnlaces()<<"\n";
	if((ultimoSpot == primerSpot) && (primerSpot->recorriTodosLosEnlaces())) {
		hayMasCaminos = false;
	}
	this->rutaActual->iniciarCursorNodo();
	this->rutaActual->avanzarCursorNodo();
	return (hayMasCaminos);
}


/*void Buscador::caminarEnlace(Central* centralActual, int centralReceptora)
{
        std::cout<<"ruta Actual tiene la central:"<<rutaActual->obtenerCursorNodo()->obtenerPosicion()<<"\n";
        Lista<Enlace*>* enlacesActuales = rutaActual->obtenerCursorNodo()->obtenerPosicion()->obtenerEnlaces();
        enlacesActuales->iniciarCursorNodo();
        enlacesActuales->avanzarCursorNodo();
        std::cout<<"el primer enlace es :"<<enlacesActuales->obtenerCursorNodo()<<"\n";

        Spot* spotActual = this->rutaActual->obtenerCursorNodo();
        while((!spotActual->recorriTodosLosEnlaces()) && (spotActual->VerSiHayMasEnlaces())) {
                if(this->obtenerTipoDeBusqueda() == 0)
                        caminarPorPrecio(spotActual->obtenerEnlaceSiguiente(), spotActual, centralReceptora);
                else
                        caminarPorDistancia(spotActual->obtenerEnlaceSiguiente(), spotActual, centralReceptora);
        }
}*/

/*
void Buscador::avanzarBusquedaDesde(Central* centralActual, int buscoMejorValor, int precioActual, int centralReceptora)
{

        while(((precioActual > buscoMejorValor) || (precioActual == 0)) &&
              (centralActual->obtenerNumero() != centralReceptora)) {
                this->caminarEnlace(centralActual, centralReceptora);
        }
        if(centralActual->obtenerNumero() == centralReceptora) {
                this->definirEstePrecioYDistancia();
                this->definirEstaRuta();
                if(this->obtenerTipoDeBusqueda() == 0)
                        this->procesoPorPrecio(centralActual, centralReceptora);
                else
                        this->procesoPorDistancia(centralActual,centralReceptora);
        }
}*/

Spot* Buscador::caminarPorPrecio(Enlace* enlaceActual, Spot* spotActual, int& centralReceptora)
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

				std::cout<<"La siguiente central es :"<<centralNueva->obtenerNumero()<<"   El precio nuevo :"<<nuevoPrecio<<"\n";
				int algo;
				return spotNuevo;
			}
		} else {
			if(!this->YaPasePorLaCentral(enlaceActual->obtenerOrigen())) {
				Central* centralNueva = enlaceActual->obtenerOrigen();
				int nuevaDistancia = spotActual->obtenerDistanciaRecorrida() + enlaceActual->obtenerDistancia();
				int nuevoPrecio = spotActual->obtenerPrecioHastaSpot() + enlaceActual->obtenerPrecio();
				Spot* spotNuevo = new Spot(centralNueva, nuevoPrecio, nuevaDistancia);
				this->rutaActual->insertar(spotNuevo);

				spotActual->anotarCaminoRecorrido(centralNueva, enlaceActual);

				std::cout<<"La siguiente central es** :"<<centralNueva->obtenerNumero()<<"   El precio nuevo** :"<<nuevoPrecio<<"\n";
				int algo;
				return spotNuevo;
			}
		}
	}
}

/*void Buscador::caminarPorDistancia(Enlace* enlaceActual, Spot* spotActual, int centralReceptora)
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
                                this->rutaActual->iniciarCursorNodo();
                                this->rutaActual->avanzarCursorPorElFinal();
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
                                this->rutaActual->iniciarCursorNodo();
                                this->rutaActual->avanzarCursorPorElFinal();
                                this->avanzarBusquedaDesde(centralNueva,nuevaDistancia,this->obtenerDistanciaDeLaLlamada(),centralReceptora);
                        }
                }
        }
}*/

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
	if(rutaActual->avanzarCursorNodo()) {
		Spot* spotActual = rutaActual->obtenerCursorNodo();
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
/*
void Buscador::procesoPorPrecio(Central* centralActual, int centralReceptora)
{
        while(this->hayMasCaminos()) {
                        std::cout<<"La central receptora es :"<<centralReceptora<<"\n";
                        if(centralActual->obtenerNumero() != centralReceptora) {
                                int buscoMejorValor = this->rutaActual->obtenerCursorNodo()->obtenerPrecioHastaSpot();
                                this->avanzarBusquedaDesde(centralActual,buscoMejorValor, this->obtenerPrecioDeLaLlamada(), centralReceptora);
                        } else {
                                std::cout<<"entre por aca"<<"\n";
                                this->borrarUnSpot();//el cursor esta al final
                                Spot* spotActual = this->rutaActual->obtenerCursorNodo();
                                std::cout<<"La posicion del Spot es :"<<spotActual->obtenerPosicion()->obtenerNumero()<<"\n";

                                std::cout<<"Pero La Central Actual:"<<centralActual->obtenerNumero()<<"\n";
                                std::cout<<"el metodo recorriTodosLosEnlaces dice :"<<spotActual->recorriTodosLosEnlaces()<<"\n";
                                //std::cout<<"el metodo ver si hay mas enlacesenlaces dice :"<<spotActual->VerSiHayMasEnlaces()<<"\n";

                                //|| (spotActual->VerSiHayMasEnlaces())

                                if((!spotActual->recorriTodosLosEnlaces()) ) {
                                        std::cout<<"me fijo que central emite aca :"<<spotActual->obtenerPosicion()->obtenerNumero()<<"\n";
                                        caminarEnlace(centralActual, centralReceptora);
                                } else {
                                        std::cout<<"entre por aca tambien "<<"\n";
                                        while(this->hayMasCaminos()) {
                                                std::cout<<"entre jeje "<<"\n";
                                                this->borrarUnSpot();
                                                spotActual = this->rutaActual->obtenerCursorNodo();
                                                if((spotActual != NULL) && (centralActual->obtenerNumero() != centralReceptora)){
                                                int buscoMejorValor = this->rutaActual->obtenerCursorNodo()->obtenerPrecioHastaSpot();
                                                centralActual = this->rutaActual->obtenerCursorNodo()->obtenerPosicion();
                                                int precioActual =  this->obtenerPrecioDeLaLlamada();
                                                while((precioActual > buscoMejorValor) || (precioActual == 0))
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

void Buscador::procesoPorDistancia(Central* centralActual, int centralReceptora)
{
    while(this->hayMasCaminos()) { //queda iniciado y posicionado el cursor en el ultimo spot dentro del metodo
        if(centralActual->obtenerNumero() != centralReceptora) {
            int buscoMejorValor = this->rutaActual->obtenerCursorNodo()->obtenerDistanciaRecorrida();

            this->avanzarBusquedaDesde(
                centralActual, buscoMejorValor, this->obtenerDistanciaDeLaLlamada(), centralReceptora);
        } else {
            std::cout << "entre por aca"
                      << "\n";
            this->borrarUnSpot(); // el cursor esta al final
            Spot* spotActual = this->rutaActual->obtenerCursorNodo();
            if((!spotActual->recorriTodosLosEnlaces()) || (spotActual->VerSiHayMasEnlaces())) {
                caminarEnlace(centralActual, centralReceptora);
            } else {

                while(this->hayMasCaminos()) {
                        this->borrarUnSpot();
                    spotActual = this->rutaActual->obtenerCursorNodo();
                        std::cout<<"me fijo que central emite aca :"<<spotActual->obtenerPosicion()->obtenerNumero()<<"\n";
                    if(spotActual != NULL) {
                        int buscoMejorValor = this->rutaActual->obtenerCursorNodo()->obtenerDistanciaRecorrida();
                        int distanciaActual = this->obtenerDistanciaDeLaLlamada();
                        centralActual = this->rutaActual->obtenerCursorNodo()->obtenerPosicion();
                        while(((distanciaActual > buscoMejorValor) || (distanciaActual == 0)) &&
                              (centralActual->obtenerNumero() != centralReceptora)) {
                            this->caminarEnlace(centralActual, centralReceptora);
                                }
                    }
                }
            }
        }
    }
    if(this->obtenerRuta() == NULL)
        this->anularLlamada();

}*/
/*
void Buscador::PosicionarEnUltimoEnlaceVisitadoDela(Lista<Enlace*>* enlacesDelSpot, Spot* spotActual)
{
        bool mePosicione = false;
        Enlace* posicionEnlace = spotActual->obtenerEnlaceRecorrido();
        enlacesDelSpot->iniciarCursorNodo();
        while((enlacesDelSpot->avanzarCursorNodo()) && (!mePosicione))
        {
                Enlace* enlaceActual = enlacesDelSpot->obtenerCursorNodo();
                if((enlaceActual->obtenerDestino() == posicionEnlace->obtenerDestino()) &&
                   (enlaceActual->obtenerOrigen() == posicionEnlace->obtenerOrigen()))
                           mePosicione = true;
        }
}*/

void Buscador::ProcesoIterativo(Central* centralActual, Spot* spotActual, int centralReceptora)
{
	bool llegue=false;
	while(this->hayMasCaminos()) {
		while((!spotActual->recorriTodosLosEnlaces()) && (!llegue)) {
			std::cout<<"la centralreceptora es :"<<centralReceptora<<"\n";
			std::cout<<"la central de ahora es :"<<spotActual->obtenerPosicion()->obtenerNumero()<<"\n";
			if(centralActual->obtenerNumero() != centralReceptora) {
				int buscoMejorValor = spotActual->obtenerPrecioHastaSpot();

				int precioActual = this->obtenerPrecioDeLaLlamada();
				if((precioActual > buscoMejorValor) || (precioActual == 0)) {
					if((!spotActual->recorriTodosLosEnlaces()) && (spotActual->VerSiHayMasEnlaces())) {
						if(this->obtenerTipoDeBusqueda() == 0) {
							spotActual = this->caminarPorPrecio(spotActual->obtenerEnlaceSiguiente(), spotActual, centralReceptora);
						}
					}
					if (spotActual->obtenerPosicion()->obtenerNumero() == centralReceptora) {
						std::cout<<"llegue\n";
						this->definirEstePrecioYDistancia();
						this->definirEstaRuta();
						llegue = true;
					}
					std::cout<<"la central de ahora es''' :"<<spotActual->obtenerPosicion()->obtenerNumero()<<"\n";
				}
			}

		}

		this->borrarUnSpot();//el cursor esta al final
		Spot* spotActual = this->rutaActual->obtenerCursorNodo();
		std::cout<<"la central de ahora es :"<<spotActual->obtenerPosicion()->obtenerNumero()<<"\n";
	}
	if(this->obtenerRuta() == NULL)
		this->anularLlamada();
}

Buscador::~Buscador()
{
	this->borrarRutaActual();

	delete (this->mejorCamino);
	delete (this->rutaActual);

}

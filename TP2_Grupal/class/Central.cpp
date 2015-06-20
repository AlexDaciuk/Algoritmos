#include "Central.h"

Central::Central(int numeroCentralTemporal)
{
	this->numeroCentral= numeroCentralTemporal;
	this->internos = new Lista<Interno*>;
	this->enlaces = new Lista<Enlace*>;
	this->mejoresCaminos = new Lista<Recorrido*>;
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

void Central::internoQueMasLeHablaronEnLaCentral(Lista<Interno*>* listaInternos,
        int& maximoInternoQueMasLeHablaronEnLaCentral,
        int& internoQueMasHablaronPorCentral)
{

	listaInternos->iniciarCursorNodo();

	while (listaInternos->avanzarCursorNodo()) {
		Interno* internoActual = listaInternos->obtenerCursorNodo();
		int duracionRecibidasPorInterno = 0;
		duracionRecibidasPorInterno = internoActual->sumaDuracionDeRecibidas(internoActual->obtenerLlamadas());

		if (duracionRecibidasPorInterno > maximoInternoQueMasLeHablaronEnLaCentral) {
			internoQueMasHablaronPorCentral = listaInternos->obtenerCursorNodo()->obtenerNumero();
			maximoInternoQueMasLeHablaronEnLaCentral = duracionRecibidasPorInterno;
		}
	}
}

void Central::internoQueMasDioOcuapadoEnLaCentral(Lista<Interno*>* listaInternos,
        int& maximoNumeroDeOcupadosDadosEnLaCentral,
        int& internoQueMasDioOcupadoPorCentral)
{
	listaInternos->iniciarCursorNodo();

	while (listaInternos->avanzarCursorNodo()) {
		Interno* internoActual = listaInternos->obtenerCursorNodo();
		int cantidadOcupadosDadosPorInterno = 0;
		cantidadOcupadosDadosPorInterno = internoActual->sumaDeOcupadosDados(internoActual->obtenerLlamadas());
		if (cantidadOcupadosDadosPorInterno >= maximoNumeroDeOcupadosDadosEnLaCentral) {
			internoQueMasDioOcupadoPorCentral = listaInternos->obtenerCursorNodo()->obtenerNumero();
			maximoNumeroDeOcupadosDadosEnLaCentral = cantidadOcupadosDadosPorInterno;
		}
	}
}

void Central::internoQueMasGastoEnLaCentral(Lista<Interno*>* listaInternos,
        int& maximoGastoEnLaCentral,
        int& internoQueMasGastoPorCentral)
{
	listaInternos->iniciarCursorNodo();

	while (listaInternos->avanzarCursorNodo()) {
		Interno* internoActual = listaInternos->obtenerCursorNodo();
		int GastosPorInterno = 0;
		GastosPorInterno = internoActual->sumaDeGastos(internoActual->obtenerLlamadas());

		if (GastosPorInterno >= maximoGastoEnLaCentral) {
			internoQueMasGastoPorCentral = listaInternos->obtenerCursorNodo()->obtenerNumero();
			maximoGastoEnLaCentral = GastosPorInterno;
		}
	}
}

void Central::internoQueMasLlamadasRecibioEnLaCentral(Lista<Interno*>* listaInternos,
    int& maximoLlamadasRecibidasEnLaCentral,
    int& internoQueMasLlamaronPorCentral)
{

	listaInternos->iniciarCursorNodo();

	while (listaInternos->avanzarCursorNodo()) {
		Interno* internoActual = listaInternos->obtenerCursorNodo();
		int llamadasRecibidasPorInterno = 0;
		llamadasRecibidasPorInterno = internoActual->sumaDeLlamadasRecibidas(internoActual->obtenerLlamadas());

		if (llamadasRecibidasPorInterno >= maximoLlamadasRecibidasEnLaCentral) {
			internoQueMasLlamaronPorCentral = listaInternos->obtenerCursorNodo()->obtenerNumero();
			maximoLlamadasRecibidasEnLaCentral = llamadasRecibidasPorInterno;
		}
	}
}


void Central::internoQueMasHabloEnLaCentral(Lista<Interno*>* listaInternos,
    int& maximaDuracionEnLaCentral,
    int& internoQueMasHabloPorCentral)
{

	listaInternos->iniciarCursorNodo();

	while (listaInternos->avanzarCursorNodo()) {
		int duracionPorInterno = 0;
		Interno* internoActual = listaInternos->obtenerCursorNodo();
		duracionPorInterno = internoActual->sumaDeDuracionDeLlamadas(internoActual->obtenerLlamadas());

		if (duracionPorInterno > maximaDuracionEnLaCentral) {
			internoQueMasHabloPorCentral = listaInternos->obtenerCursorNodo()->obtenerNumero();
			maximaDuracionEnLaCentral = duracionPorInterno;
		}
	}
}

void Central::internoQueMasLlamoEnLaCentral(Lista<Interno*>* listaInternos,
    int& maximoNumeroLLamadasEnLaCentral,
    int& internoQueMasLlamoPorCentral)
{

	listaInternos->iniciarCursorNodo();

	while (listaInternos->avanzarCursorNodo()) {
		Interno* internoActual = listaInternos->obtenerCursorNodo();
		int llamadasPorInterno = 0;
		llamadasPorInterno = internoActual->sumaDeLlamadasEmitidas(internoActual->obtenerLlamadas());

		if (llamadasPorInterno > maximoNumeroLLamadasEnLaCentral) {
			internoQueMasLlamoPorCentral = listaInternos->obtenerCursorNodo()->obtenerNumero();
			maximoNumeroLLamadasEnLaCentral = llamadasPorInterno;
		}
	}
}


void Central::internoQueMasOcupadosRecibioEnLaCentral(Lista<Interno*>* listaInternos,
    int& maximoNumeroOcupadosEnLaCentral,
    int& internoQueMasRecibioOcupadosPorCentral)
{

	listaInternos->iniciarCursorNodo();

	while (listaInternos->avanzarCursorNodo()) {
		Interno* internoActual = listaInternos->obtenerCursorNodo();
		int ocupadosRecibidosPorInterno = 0;
		ocupadosRecibidosPorInterno = internoActual->sumaDeLlamadasRecibidas(internoActual->obtenerLlamadas());

		if (ocupadosRecibidosPorInterno >= maximoNumeroOcupadosEnLaCentral) {
			internoQueMasRecibioOcupadosPorCentral = listaInternos->obtenerCursorNodo()->obtenerNumero();
			maximoNumeroOcupadosEnLaCentral = ocupadosRecibidosPorInterno;
		}
	}
}

void Central::agregarRecorrido(Recorrido* nuevoRecorrido)
{
	this->mejoresCaminos->insertar(nuevoRecorrido);
}

void Central::crearVectorDeEnlaces(Enlace** &enlacesOrdenadas, int &totalEnlaces)
{
	Lista<Enlace*>* enlaces = this->obtenerEnlaces();
	enlaces->iniciarCursorNodo();
	totalCentrales = 0;
	int j = 0;
	while (enlaces->avanzarCursorNodo()) {
		totalCentrales++;
	}
	enlaces->iniciarCursorNodo();
	enlacesOrdenadas = new Enlace* [totalCentrales];
	while (enlaces->avanzarCursorNodo()) {
		enlacesOrdenadas[j] = enlaces->obtenerCursorNodo();
		j++;
	}
}


void Central::ordenarEnlaces()
{
	int totalEnlaces;
	Enlace** enlacesOrdenados;
	crearVectorDeOrdenamiento(enlacesOrdenados, totalEnlaces);
	//Ordeno los punteros que inserte en el vector.
	for (int i = 0; i < totalEnlaces - 1; i++) {
		for (int j = i + 1; j < totalEnlaces ; j++) {
			if (enlacesOrdenados[i]->obtenerPrecio() < enlacesOrdenados[j]->obtenerPrecio()) {
			    
				Central* enlaceTemporal = enlacesOrdenados[i];
				enlacesOrdenados[i] = enlacesOrdenados[j];
				enlacesOrdenados[j]= enlaceTemporal;
			}
		}
	}
	Lista<Enlace*>* enlaces = this->obtenerEnlaces();
	enlaces->iniciarCursorNodo();
	while(enlaces->avanzarCursorNodo())
	{
		enlaces->remover();
	}
	for(int j=0;j < totalEnlaces; j++)
	{
		enlaces->insertar(enlacesOrdenados[j]);
	}
}

Central::~Central()
{
	delete(this->internos);
	delete(this->enlaces);
}

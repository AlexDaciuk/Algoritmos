#ifndef PROCESADORLLAMADA_H_
#define PROCESADORLLAMADA_H_

#ifndef NULL
#define NULL 0
#endif

#include "DatosLlamada.h"
#include "Lista.h"
#include "Central.h"
#include "Enlace.h"
#include "LectorArchivos.h"
#include "Buscador.h"
#include <string>

class ProcesadorLlamada
{
private:
	DatosLlamada* datosLlamada;
	Buscador* recorridoTemporal;
	LectorArchivos* archivoLlamadas;
	Lista<Enlace*>* enlaces;
	Lista<Central*>* centrales;
	std::string variableBusqueda;


public:
	/**
	* Se crea el procesador de llamadas con su lista de enlaces y centrales vacia
	*/
	ProcesadorLlamada(LectorArchivos* lectorArchivosTemporal, std::string variableBusqueda);

	/**
	 * Pre: la ruta donde se encuentra el archivo con los datos de llamadas debe existir.
	 * Post: carga los datos de cada linea del txt de llamadas ya sea datos de enlaces como de inicio
	 * y fin de llamadas
	 * */
	void procesarLlamadas();


	/**
	 * Metodos que devuelven las listas correspondientes, de enlaces o centrales
	 */
	Lista<Enlace*>* obtenerEnlaces();
	Lista<Central*>* obtenerCentrales();


	/**
	 * Destructor de la clase procesador llamada
	 */
	~ProcesadorLlamada();


private:

	/**
	 * Metodos internos para iniciar y finalizar llamadas
	 */
	void iniciarLlamada();
	void finalizarLlamada();


	/**
	 * Post: Si no existe agrega la central a la lista de centrales
	 * si ya existe la central no hace nada.
	 * */
	void agregarCentral(int numeroCentral);


	/**
	 * Metodos que llaman al buscador de caminos en un modo u otro, ya sea en camino de
	 * menor precio o de menor distancia
	 */
	void buscaCentralMenorPrecio();
	void buscaCentralMenorDistancia();


	/**
	 * Post: Si no existe agrega la enlace a la lista de centrales
	 * si ya existe la enlace no hace nada.
	 * */
	void agregarEnlace(int numeroOrigen, int numeroDestino);


	/*
	 * Metodos que crea un interno en la central indicada
	 */
	void crearInterno(int internoNuevo, int central);


	/*
	 * Metodo que obtiene el puntero a un interno de la central indicada
	 */
	Interno* obtenerInterno(int internoAObtener, int central);

};

#endif

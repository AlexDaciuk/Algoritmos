#ifndef PROCESADORLLAMADA_H_
#define PROCESADORLLAMADA_H_

#ifndef NULL
#define NULL 0
#endif

#include "DatosLlamada.h"
#include "Lista.h"
#include "Enlace.h"
#include "Central.h"
#include "LectorArchivos.h"
#include "Buscador.h"
#include <string>

class ProcesadorLlamada
{
private:
	DatosLlamada* datosTemporal;
	Buscador* recorridoTemporal;
	LectorArchivos* archivoLlamadas;
	Lista<Enlace>* enlaces;
	Lista<Central>* centrales;

public:
	/**
	* Se crea el procesador de llamadas con sus punteros apuntando a null
	*/
	ProcesadorLlamada();

	/**
	 * post:si no existe agrega la central a la lista de centrales y tambien les agrega
	 * el interno a la lista de internos de la respectiva central
	 * si ya existe la central no hace nada.
	 * */
	void agregarOrigen(int numeroCentral);
	/**
	 * post:si no existe agrega la central a la lista de centrales
	 * si ya existe la central no hace nada.
	 * */
	void agregarDestino(int numeroCentral);

	Buscador* buscaCentralMenorPrecio();

	Buscador* buscaCentralMenorDistancia();

	/**
	 * Pre: la ruta donde se encuentra el archivo con los datos de llamadas debe existir.
	 * Post: carga los datos de cada linea del txt de llamadas ya sea datos de enlaces como de inicio
	 * y fin de llamadas
	 * */
	void procesarLlamada();


	/**
	 * post:si no existe agrega la enlace a la lista de centrales
	 * si ya existe la enlace no hace nada.
	 * */
	void agregarEnlace(int numeroOrigen, int numeroOrigen);


};

#endif

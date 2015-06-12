#ifndef SPOT_H
#define SPOT_H

#ifndef NULL
#define NULL 0
#endif

#include "Lista.h"
#include "Enlace.h"
#include "Central.h"

/**
 * Clase que solo interactua con el buscador.
 * Tendra la central en donde uno esta posicionado,
 * las centrales que ya visito desde esa central,
 * la distancia ya recorrida o precio de la llamada hasta ahi y
 * un puntero al ultimo enlace utilizado.
 *
 */

class Spot
{

private:


	int precioHastaSpot;
	int distanciaHastaSpot;

	/**
	 * La posicion es la central en donde estoy.
	 * el precioHastaSpot es la distancia recorrida o el
	 * precio acumulado.
	 */
	Central* posicion;

	Lista<Central*>* centralesVisitadas;

	Lista<Enlace*>* enlacesRecorridos;

	Lista<Enlace*>* enlacesARecorrer;

	bool hayMasEnlaces;

public:
	/**
	 *Constructor de la clase Ruta.
	 * Pre: debo indicarle el puntero de la central correspondiente
	 * a la posicion y el valor total del camino recorrido.
	 * En caso de ser la primer central precioHastaSpot valdra 0.
	 * Post: Guardara la informacion de lo indicado en las precondiciones.
	 */
	Spot(Central* posicion, int precioHastaSpot, int distanciaHastaSpotTemporal);

	/**
	 * devuelve el puntero a la central del Spot.
	 */
	Central* obtenerPosicion();

	/**
	 * Pre: debo indicarle el puntero de la central a la que me dirijo y el puntero
	 * del enlace utilizado.
	 * Post: de ser el primer enlace tomado se crea una lista de centrales
	 * visitadas desde esta central.
	 */
	void anotarCaminoRecorrido(Central* CentralAVisitar, Enlace* enlaceRecorrido);

	/**
		* Post: indica si ya visite desde esta central a la CentralAVisitar contando en la que estoy posicionado.
		*/
	bool visitasteLaCentral(Central* CentralAVisitar);

	/**
	* Post: indica si ya visite desde esta central a la CentralAVisitar sin contar en la que estoy
	* posicionado.
	*/
	bool visiteLaCentral(Central* centralAVisitar);

	/**
	* Post: Asigno a NULL el cursor de la lista de enlaces
	*/
	void resetListaEnlaces();

	/**
	* Post: indica el precio del recorrido hasta este spot
	*/
	int obtenerPrecioHastaSpot();

	/**
	* Post: indica la distancia recorrida hasta el spot
	*/
	int obtenerDistanciaRecorridaHastaSpot();

	/**
	* Post: indica si desde la central del spot uso ya todos los enlaces
	*/
	bool recorriTodosLosEnlaces();

	/**
	* Post: otorga el ultimo enlace que se recorrio.
	*/
	Enlace* obtenerEnlaceRecorrido();

	/**
	* Post: indica si hay mas enlaces por recorrer.
	*/
	Enlace* obtenerEnlaceSiguiente();

	/**
	* Post: indica si hay mas enlaces por recorrer.
	*/
	bool VerSiHayMasEnlaces();

	/**
	* Post: devuelve el siguiente enlace al ultimo que se recorrio.
	*/
	Enlace* posicionarmeEnUltimoEnlace();

	/**
	* Post: obtenes la lista de los enlaces de la central posicion del Spot.
	*/
	Lista<Enlace*>* obtenerEnlacesARecorrer();
	/**
	 * Post: destruye toda la lista de caminos recorridos desde esta central
	 */
	~Spot();
};


#endif

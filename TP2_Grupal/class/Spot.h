#ifndef LISTA_H_
#define LISTA_H_

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

class Spot{
	
private:
	
	/**
	 * La posicion es la central en donde estoy.
	 * el precioHastaSpot es la distancia recorrida o el 
	 * precio acumulado.
	 *
	 */
	int precioHastaSpot, distanciaHastaSpot;
	
	Central* posicion;
	
	Lista<Central*>* centralesVisitadas;
	
	Enlace* enlaceRecorrido;
	
public:
	/**
	 *Constructor de la clase Ruta.
	 * Pre: debo indicarle el puntero de la central correspondiente 
	 * a la posicion y el valor total del camino recorrido.
	 * En caso de ser la primer central precioHastaSpot valdra 0.
	 * Post: Guardara la informacion de lo indicado en las precondiciones.
	 */
	Spot(Central* posicion, int precioHastaSpot, int distanciaHastaSpot);
	
	/**
	 * @brief devuelve el puntero a la central del Spot
	 * @return 
	 */
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
	* Post: indica si ya visite desde esta central a la CentralAVisitar
	*/
	bool visitasteLacentral(Central* CentralAVisitar);
	
	/**
	* Post: indica el precio del recorrido hasta este spot
	*/
	int obtenerPrecioHastaSpot();
	
	/**
	* Post: indica la distancia recorrida hasta el spot
	*/
	int obtenerDistanciaRecorrida();
	
	/**
	* Post: indica si desde la central del spot uso ya todos los enlaces
	*/
	bool recorriTodosLosEnlaces();
	
	/**
	 * Post: destruye toda la lista de caminos recorridos desde esta central
	 */
	 ~Spot();
	};


#endif
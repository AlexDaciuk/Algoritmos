#ifndef BUSCADOR_H
#define BUSCADOR_H

#ifndef NULL
#define NULL 0

#include "Lista.h"
#include "Enlace.h"
#include "Central.h"
#include "Spot.h"

/**
 * Esta clase se ocupará de encontrar el camino con la menor distacia
 * o con el precio mas bajo de una central a otra.
 */
class Buscador{
  
private:
  
	Lista<Enlaces*>* mejorCamino;
	
	Lista<Spot>* rutaActual;
	
	/**
	* En esta variable guardare la distancia que  recorre el mejor camino
	* o el precio del camino mas barato segun lo pedido por el usuario.
	*/
	int valorDelCamino;
	
public:

	/**
	 * Pre: se inicia una llamda entre un interno y otro de distintas centrales.
	 * Se le indican las centrales de salida y llegada de la llamada ademas de 
	 * pasarle una lista con todas las centrales disponibles.
	 */
	  Buscador(Lista<Central>* centrales, int salida, int llegada);
	  
	/**
	 * Post: te otorga la ruta que encontro.
	 * Sera nula cuando la llamada fue interna de una central
	 */
	  Lista<Enlaces*>* obtenerRuta();
	
	/**
	 * Post: devuelve la distancia o el precio de la llamada segun corresponda.
	 */
	  int obtenerValorDelCamino();

	/**
	 * Pre: se le da la lista de centrales y la central de donde sale la llamada
	 * Post: encuentra el puntero a esa central
	 */
	  Central* encontrarCentralDeSalida(Lista<Central>* centrales, int salida );
	  
    /**
	 * Post: indica si ya visite a la central en el camino ya hecho
	 */
	  bool indicaSiPasePorLaCentral(Central* central);
	  
	/**
	 * Post: indica si La llamada es entre dos numeros de la misma central
	 */
	  bool esLlamadaInterna( int salida, int llegada);
	  
	  
  //Buscar central de salida en la lista de centrales
  //iniciar camino:
      //me fijo si la llamada es interna en la misma central
      //si no es, guado la central llegada en la lista que voy recorriendo
      //el caminante guarda valor 0
      //
	  ~Buscador();
};
#endif
#endif

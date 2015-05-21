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
  
	Lista<Enlace*>* mejorCamino;
	
	Lista<Spot>* rutaActual;
	
	Lista<Central>* centralesTotales;
	
	/**
	* En esta variable guardare la distancia que  recorre el mejor camino
	* o el precio del camino mas barato segun lo pedido por el usuario.
	*/
	int valorDelCamino;
	
public:

	/**
	 * Pre: se inicia una llamda entre un interno y otro de distintas centrales.
	 * Se le da una lista con todas las centrales disponibles.
	 */
	  Buscador(Lista<Central>* centrales);
	  
	/**
	 * Post: te otorga la ruta de enlaces que encontro.
	 * Sera nula cuando la llamada fue interna de una central
	 */
	  Lista<Enlace*>* obtenerRuta();
	
	/**
	 * Post: devuelve la distancia o el precio de la llamada segun corresponda.
	 */
	  int obtenerValorDelCamino();
	  
	  Central* obtenerCentralReceptora(int centralReceptora);
	  
	  Central* obtenerCentralEmisora(int centralEmisora);
	  
	/**
	 * Post: hace el algoritmo de busqueda por mejor precio
	 */
	  void encontrarCaminoPorPrecio(int centralEmisora, int centralReceptora, int emisor, int receptor);
	  
	/**
	 * Post: hace el algoritmo de busqueda por mejor distancia
	 */
	  void encontrarCaminoPordistancia( int centralEmisora, int centralReceptora, int emisor, int receptor);
	  
	/**
	 * Post: libera la memoria de los spots usados y la lista del mejor camino
	 */
	  ~Buscador();

private:
	/**
	 * Pre: se le da la lista de centrales y la central de donde sale la llamada
	 * Post: encuentra el puntero a esa central
	 */
	  Central* encontrarCentralDeEmision(Lista<Central>* centrales, int salida );
	  
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
	 
};
#endif
#endif

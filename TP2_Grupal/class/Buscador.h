#ifndef BUSCADOR_H
#define BUSCADOR_H

#ifndef NULL
#define NULL 0

#include "Lista.h"
#include "Enlace.h"
#include "Internos.h"
#include "Central.h"
#include "Spot.h"

/**
 * Esta clase se ocupará de encontrar el camino con la menor distacia
 * o con el precio mas bajo de una central a otra.
 * Modo de uso: Luego de crear el buscador, lo primero que se debe hacer es buscar el 
 * camino, ya sea por precio o distancia, antes de pedirle cualquiera de las operaciones.
 */
class Buscador{
  
private:
  
	Lista<Enlace*>* mejorCamino;
	
	Lista<Spot>* rutaActual;
	
	Lista<Central>* centralesTotales;
	
	int precioDeLaLlamada;
	
	int distanciaDeLaLlamada;
	
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
	 * Post: devuelve el precio de la llamada segun corresponda.
	 */
	  int obtenerPrecioDeLaLlamada();
	  
	/**
	 * Post: devuelve la distancia de la llamada segun corresponda.
	 */
	  int obtenerDistanciaDeLaLlamada();
	  
	/**
	 * Pre: se le da la lista de centrales y la central que desea buscar
	 * Post: encuentra el puntero a esa central
	 */
	  Central* encontrarLaCentral(int central);
	  
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
	 * Post: indica si ya visite a la central en el camino ya hecho
	 */
	  bool YaPasePorLaCentral(Central* central);
	  
	/**
	 * Post: indica si La llamada es entre dos numeros de la misma central
	 */
	  bool esLlamadaInterna( int centralEmisora, int centralReceptora);
	  
	  Interno* encontrarInternoEnLa(Central* central, int numeroDeInterno);
	
	  void definirEstePrecioYDistancia();
	  
	  bool hayMasCaminos();
	  
	  void avanzarBusquedaPor(int mejorPrecio, Central* centralActual, int centralReceptora);
	  
	  bool caminarEnlace(Central* centralActual, int mejorValor, int centralReceptora);
	  
	  /**
	   * @brief Camina el enlace dado devolviendo el puntero a la central de destino
	   * @param enlaceActual, centralActual
	   * @return central de destino
	   */
	  Central* caminar(Enlace* enlaceActual, Spot spotActual, int mejorValor, int centralReceptora);
  //Buscar central de salida en la lista de centrales
  //iniciar camino:
      //me fijo si la llamada es interna en la misma central
      //si no es, guado la central llegada en la lista que voy recorriendo
      //el caminante guarda valor 0
      //
	 
};
#endif
#endif

#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <string>
#include <iostream>
#include "Lista.h"
#include "Enlace"
#include "Central"


/**
 * Clase que maneja la interfaz e interaccion con el usuario
 * 
 * 
 */


class Interfaz {
private:
	
	Lista<Enlace>* punteroAEnlaces;
  Lista<Central>* punteroACentrales;
	
	
public:
  /**
   * Constructor de la clase. Inicializa los punteros.
   * */
  Ineterfaz();
  /**
   * Deuelve el puntero a la lista donde se guardan los enlaces para su uso.
   * */ 
  Lista<Enlace>* obtenerPunteroAEnlaces();
	/**
   * Deuelve el puntero a la lista donde se guardan las centrales para su uso.
   * */
  Lista<Central>* obtenerPunteroACentrales();
	/**
	 * Metodo que va a iniciar el programa
	 */
	void iniciarPrograma();
	
	/**
	 * Metodo que va a mostrar el menu al usuario
	 */
	void mostrarMenu();
	
	/**
	 * Metodo que va a pedir la opcion del menu al usuario
	 */
	int pedirOpcionMenu();
	
	/**
	 * Metodo que va a pedir numero de central al usuario
	 */
	int pedirCentral();
	
	/**
	 * Metodo que va a pedir numero de interno al usuario 
	 */
	int pedirInterno();
  /**
   * Metodo que permite elegir la variable que va a tener en 
   * cuenta el algoritmo de busqueda para elegir el mejor camino.
   * */
  int pedirAlgoritmoDeBusqueda();
  /**
   * Metodo que devuelve todos los numeros de los internos que aparecen en los datos de las llamadas 
   * discriminados por central.
   * */
  void mostrarDetallesDeInternos();
  
  
  
  
  
  
  
  
  
 
 
  ~Interfaz();
}
#endif


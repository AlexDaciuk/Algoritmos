#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <string>
#include <iostream>
#include "Lista.h"
#include "Enlace.h"
#include "Central.h"
#include "LectorAchivos.h"



/**
 * Clase que maneja la interfaz e interaccion con el usuario
 * 
 * 
 */


class Interfaz {
private:
	
	Lista<Enlace>* enlaces;
  Lista<Central>* centrales;
  LectorArchivos* punteroALectorDeArchivos;
	
	
public:
  /**
   * Constructor de la clase. Inicializa los punteros.
   * */
  Ineterfaz();
  /**
   * Deuelve el puntero a la lista donde se guardan los enlaces para su uso.
   * */ 
  Lista<Enlace>* obtenerenlaces();
	/**
   * Deuelve el puntero a la lista donde se guardan las centrales para su uso.
   * */
  Lista<Central>* obtenercentrales();
	/**
	 * Metodo que va a iniciar el programa
	 */
	void iniciarPrograma();
  
  /**
   * Inicializa el puntero a la lista de centrales con la direcion de la lista creada al procesar el archivo
   * de llamadas.
   * */
  void iniciarlizarPunteroACentrales(ProcesadorLlamada* procesadorDeLlamadas);
  /**
   * Inicializa el puntero a la lista de enlaces con la direcion de la lista creada al procesar el archivo
   * de llamadas.
   * */
	void iniciarlizarPunteroAEnlaces(ProcesadorLlamada* procesadorDeLlamadas);
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
   * Metodo que pide la ruta donde esta hubicado el archivo de llamadas.
   * */
  std::string pedirRuta();
	
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
  /**
   * Devuleve el puntero a la clase que lee el archivo de llamadas.
   * */
  LectorArchivos* obtenerPunteroALectorDeArchivos();
  
  /**
   * Cambia la direccion donde apunta el puntero.
   * */
  void cambiarPunteroPunteroALectorDeArchivos(LectorArchivos* nuevoPuntero);
  
  
  
  
  
  
  
  
  
 
 
  ~Interfaz();
}
#endif


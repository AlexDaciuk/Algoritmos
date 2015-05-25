#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <string>
#include <sstream>
#include <iostream>
#include "DatosLlamada.h"
#include "Menu.h"
#include "ProcesadorLlamada.h"
#include "LectorArchivos.h"
#include "Opciones.h"
#include "Lista.h"
#include "Enlace.h"
#include "Central.h"
#include "Internos.h"
#include "Llamada.h"

/**
 * Clase que maneja la interfaz e interaccion con el usuario
 *
 *
 */

class Interfaz
{
  private:
  Lista<Enlace>* enlaces;
  Lista<Central>* centrales;
  LectorArchivos* LectorDeArchivos;
  
   /**
   * Cambia la direccion donde apunta el puntero.
   * */
  void cambiarPunteroPunteroALectorDeArchivos(LectorArchivos* nuevoPuntero);

  public:
  /**
   * Constructor de la clase. Inicializa los punteros a NULL.
   * */
  Interfaz();
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
* precondicion: Se tiene que haber leido un archivo de llamadas.
   * postcondicion: Devuleve los numeros de los internos leidos en el archivo de llamadas discriminadas por central.
* */
  void mostrarDetallesDeInternos();
  /**
* precondicion: Se tiene que haber leido un archivo de llamadas.
   * postcondicion: Devuleve los numeros de las centrales leidas en el archivo de llamadas.
* */
  void mostrarDetallesDeCentrales();
  /**
* precondicion: Se tiene que haber leido un archivo de llamadas.
   * postcondicion: Devuelve los numeros de las centrales de origen y destino y cantidad de canales(iniciales) que
* poseen los enlaces leidos en el archivo de llamadas.
* */
  void mostrarDetallesDeEnlaces();
	/**
* precondicion: Se tiene que haber leido un archivo de llamadas.
   * postcondicion: Devuelve el interno con mayor duracion de llamadas de cada central y de todos en general.
	 * Si hay mas de un interno con la misma duracionde llamadas en una central se muestra el primero.
* */
	void internoQueMasHabloPorCentralYGeneral();
	/**
	 * pre: debe existir la central.
	 * post: devuleve el numero del interno con mayor duracion de llamadas totales.
	 */
	void internoQueMasHabloEnUnaCentral(Lista<Interno*>* listaInternos,int& maximaDuracionEnLaCentral,int& internoQueMasHabloPorCentral);
	/**
	 * Pre: debe esxistir la lista de punteros a llamadas.
	 * post: devuelve la sumatoria de todas las duraciones de llamadas de cada llamada en la lista del interno.
	 */
	int sumaDeDuracionDeLlamadas(Lista<Llamada*>* listaLlamadas);
  /**
   * pre: los internos y las centrales deben existir.
   * post: devuelve la cantidad de llamadas totales realizadas entre ellos el tiempo total de conversacion
   * y las cantidad de ocupados que se dieron(ocupados del interno X mas  los del interno Y).
   */
  void detallesLlamadasEntreInternoXeInternoY();
	/**
	 * precondicion: Se tiene que haber leido un archivo de llamadas.
   * postcondicion: Devuelve el interno con mayor numero de llamadas de cada central y de todos en general.
	 * Si hay mas de un interno con la misma cantidad de llamadas en una central se muestra el primero.
  */ 
	void internoQueMasLlamoPorCentralYEnGeneral();
  /**
	 * pre: debe existir la central.
	 * post: devuleve el numero del interno con mayor numero de llamadas y ese numero de llamadas.
	 */
  void internoQueMasLlamoEnUnaCentral(Lista<Interno*>* listaInternos,int& maximoNumeroLLamadasEnLaCentral,int& internoQueMasLlamoPorCentral)
  /**
	 * Pre: debe esxistir la lista de punteros a llamadas.
	 * post: devuelve la sumatoria de las cantidades de llamadas de cada interno.
	 */
  int sumaDeLlamadas(Lista<Llamada*>* listaLlamadas)
  /**
* Devuleve el puntero a la clase que lee el archivo de llamadas.
* */
  LectorArchivos* obtenerPunteroALectorDeArchivos();

  /**
   * Precondicion: Opcion de be estar comprendido entre numeros del 1 a 17 inclusive.
   *
   */
  void tratarOpcion(int opcion);
  /**
   * Precondicion: Se debe haber realizado una consulta anteriormente.
   * La opcion debe estar en tre 1 y 17 inclusive.
   * Postcondiciones: Si se desea continuar te vuelve a mostrar las opciones disponibles sino termina el programa.
   * */
  void realizarOtraConsulta(int& opcion, bool& continuar) ~Interfaz();
}
#endif

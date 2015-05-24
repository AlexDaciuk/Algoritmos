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

class Interfaz
{
  private:
  Lista<Enlace>* enlaces;
  Lista<Central>* centrales;
  LectorArchivos* LectorDeArchivos;

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
   * postcondicion: Devuelve los numeros de las centrales de origen y destino y cantidad de canales(iniciales) que poseen
   * 								los enlaces leidos en el archivo de llamadas.
* */
  void mostrarDetallesDeEnlaces();
	/**
	 * pre: los interneos y las centrales deben existir.
	 * post: devuelve la cantidad de llamadas totales realizadas entre ellos el tiempo total de conversacion 
	 * y las cantidad de ocupados que se dieron(ocupados del interno X mas  los del interno Y).
	 */
	void detallesLlamadasEntreInternoXeInternoY();
  /**
* Devuleve el puntero a la clase que lee el archivo de llamadas.
* */
  LectorArchivos* obtenerPunteroALectorDeArchivos();

  /**
   * Cambia la direccion donde apunta el puntero.
   * */
  void cambiarPunteroPunteroALectorDeArchivos(LectorArchivos* nuevoPuntero);
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

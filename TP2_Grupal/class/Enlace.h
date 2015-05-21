#ifndef ENLACE_H_
#define ENLACE_H_

#ifndef NULL
#define NULL 0
#endif

#include "Central.h"


/**
 * Clase que define cada enlace entre 2 centrales
 */

class Enlace
{
private:
  int cantidadDeCanales, distanciaKm, costoPorMinuto, cantidadCanalesEnUso;
  Central* Origen, CentralB;

public:

  /**
   * Constructor de la clase enlace
   * Post: Queda creado el enlace entre 2 centrales
   */
  

  Enlace(int OrigenTemporal, int centralBTemporal, int distanciaTemporal, int cantidadCanalesTemporal, int costoPorMinutoTemporal);


  /**
   * Funciones varias que devuelven atributos del enlace
   * Post: se devuelve el dato del tipo correspondiente
   */

  int obtenerOrigen();
  int obtenerCentralB();
  int obtenerDistancia();
  int obtenerPrecio();
  int obtenerCantidadEnlacesEnUso();
  Central* obtenerOrigen();
  Central* obtenerCentralB();

   /**
   * Metodo que devuelve true si se puede realizar una llamada mediante el enlace,
   * en caso contrario, devuelve false
   */

  bool chequearDisponibilidadCanales();

  

  /**                                                                                                                                                          * Metodos que van a cambiar la disponibilidad de cada enlace                                                                                             
   * ya sea agregando una llamada o eliminandola                                                                                                               */   

  void agregarLlamadaEnCurso();

  void eliminarLlamadaEnCurso();


  
};

#endif

  





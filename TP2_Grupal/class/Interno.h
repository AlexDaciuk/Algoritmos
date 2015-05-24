#ifndef INTERNOS_H_
#define INTERNOS_H_

#ifndef NULL
#define NULL 0
#endif

#include "Llamada.h"
#include "Lista.h"

/**
 *Clase que define a cada interno de una central
 */

class Interno
{
 private:
  int numeroInterno;
  bool estaOcupado;
  Lista<Llamada>* llamadas; //apunta siempre a la primer llamada
  
 public:
  
  /**
   * Constructor de la clase Interno
   * Post: Queda creado el interno con el numero asignado
   */
  Interno(int numeroInternoTemporal);
  
  /**
   *post: devuelve el numero del interno.
   */
  int obtenerNumero();
  
  /**
   *post: agrega una nueva llamada a la lista de llamadas del interno que 
   * realiza la llamada y la ubica al principio de la lista.
   * En el caso de que ya exista un nodo en la lista con el interno receptor se lleva
   * ese nodo al principio y se suman 
   * los datos directamente ahi, no se crea ningun nodo.
   */
  void agregarLlamadaEmisor(int EmisorTemporal, int horaTemporal, DatosRecorrido* recorridoTemporal);
  
  /**
   *post: devuelve el puntero a la lista de llamadas del interno
   */
   
  Lista<Llamada>* obtenerLlamadas();
  
  /**
    *post: recorre la lista de llamadas del interno emisor y busca si ya existe un nodo
    * con datos pertenecientes a interacciones con el interno receptor. En ese caso de no
    * existir la llamada, la crea
    */
  void creaReceptorLlamada(int receptor);
    
  /**
   *post: recorre la lista de llamadas del interno y se fija si en algun nodo la hora
   * de inicio de una llamada es distinto de cero. En ese caso devuelve verdadero, 
   * si no falso.
   */
  bool internoOcupado();
  
};


#endif

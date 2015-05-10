#ifndef INTERNOS_H
#define INTERNOS_H
#ifndef NULL
#define NULL 0
#include "Llamada.h"
#include <iostream>
 
/**
 *Clase que define a cada interno de una central
 */

class Interno
{
 private:
  int numeroInterno;
  Llamada* punteroASusLlamadas; //apunta siempre a la primer llamada
  Interno* internoSiguiente;
  

 public:

  /**
   * Constructor de la clase Interno
   * Post: Queda creado el interno con el numero asignado
   */
  
  Interno(int numeroInternoTmp);
  
  /*post: devuelve el numero del interno.*/
  int obtenerNumeroInterno();
  
  /*post: agrega una nueva llamada a la lista de llamadas del interno que 
   * realiza la llamada y la ubica al principio de la lista.
   * En el caso de que ya exista un nodo en la lista con el interno receptor se lleva
   * ese nodo al principio y se suman 
   * los datos directamente ahi, no se crea ningun nodo.*/
  void agregarLlamada(std::string receptorLlamadaTmp, int horaInicioLlamadaEnCursoTmp);
  
  /*post: devuelve el puntero a la lista de llamadas del interno*/
  Llamada* obtenerPunteroASusLlamadas();
  
  /*post: cambia la direccion del puntero a la lista de llamadas del interno.*/
  void cambiarPunteroASusLlamadas(Llamada* nuevoPuntero);
  
  /*post:lleva el nodo con los datos pertecnecientes al interno receptor
   * de la lista de llamadas al principio de la misma.*/
  void moverLlamadaAlFrente(std::string receptorLlamadaTmp);
   
   /*post: recorre la lista de llamadas del interno emisor y busca si ya existe un nodo
    * con datos pertenecientes a interacciones con el interno receptor. En ese caso devuele
    * verdadero, si no falso.*/
  bool existeReceptor(std::string receptor);
  
  
  /*post: recorre la lista de llamadas del interno y se fija si en algun nodo la hora
   * de inicio de una llamada es distinto de cero. En ese caso devuelve verdadero, 
   * si no falso.*/
  bool internoOcupado();
};

#endif
#endif

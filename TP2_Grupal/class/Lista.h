#ifndef LISTA_H_
#define LISTA_H_

#ifndef NULL
#define NULL 0
#endif

#include <iostream>
#include "Nodo.h"

template <class T>
class Lista
{
 private:
  
  Nodo<T>* primerNodo;
  Nodo<T>* ultimoNodo;
  Nodo<T>* cursorNodo;
  
public:
  
  /**
   * Constructor de la clase Lista
   * Post: Queda creada la lista con los punteros correspondientes al primer y 
   *  y ultimo nodo apuntando a NULL
   */
  
  Lista();

  /**
   * Inserta un nuevo nodo en el primer lugar de la lista
   * Pre: Tiene que existir la lista
   * Post: Queda creado y posicionado el nodo
   */
  
  void insertar( T objeto);

  /**
   * Devuelve el puntero a un objeto en especial dentro de la lista
   * Post: El puntero apunta al objeto si existiese y a NULL si no existe
   */
  
  Nodo<T>* obtenerPunteroAlObjeto(int numeroDeObjeto);

  /**
   * Pone primero en la lista al objeto indicado en el parametro
   */
  
  void ponerPrimero(int numeroDeObjeto);

  /**
   * Devuelve el objeto al cual esta apuntando el cursor siempre y cuando 
   * no este apuntando a un objeto inexistente
   */
  
  T obtenerCursorNodo(); 

  /**
   * Mueve el cursor al siguiente nodo
   *
   * Pre: Se ha iniciado un recorrido (invocando al metodo iniciarCursor) y desde entonces
   * no se han agregado o removido elementos de la lista
   * 
   * Post: El cursor apunta al siguiente elemento, si no existiese el metodo devuelve false
   *
   */
  
  bool avanzarCursorNodo();

  
  /**
   * Crea un cursor y lo apunta a NULL para poder hacer un recorrido de la lista
   */

  void iniciarCursorNodo();

  ~Lista();
};

template <class T> Lista<T>::Lista()
{
  this->primerNodo=NULL;
  this->ultimoNodo=NULL;
}


template <class T> void Lista<T>::insertar( T objeto)
{
  Nodo<T>* nuevoNodo= new Nodo<T>(objeto);
  if (ultimoNodo!=NULL)
    {
      nuevoNodo->cambiarNodoSiguiente(this->primerNodo);
      this->primerNodo->cambiarNodoAnterior(nuevoNodo);
      this->primerNodo=nuevoNodo;
    }
  else
    {
      this->primerNodo=nuevoNodo;
      this->ultimoNodo=nuevoNodo;
    }
}


template <class T> Nodo<T>* Lista<T>::obtenerPunteroAlObjeto(int numeroDeObjeto)
{
  Nodo<T>* cursor=this->primerNodo;

  while((this->cursor->obtenerObjeto()->obtenerNumero() != numeroDeObjeto) && (cursor != NULL))
    cursor=cursor->obtenerSiguiente();
  
  return cursor;
}



template <class T> void Lista<T>::ponerPrimero(int numeroDeObjeto)
{
  Nodo<T>* cursor = obtenerNumeroObjeto(int numeroDeObjeto);

  Nodo<T>* cursorAnterior= cursor->obtenerAnterior();

  Nodo<T>* cursorSiguiente= cursor->obtenerSiguiente();

  
  cursorAnterior->cambiarNodoSiguiente(cursorSiguiente);
  cursorSiguiente->cambiarNodoAnterior(cursorAnterior);
  cursor->cambiarNodoAnterior(NULL);
  cursor->cambiarNodoSiguiente(this->primerNodo);
  this->primerNodo->cambiarNodoAnterior(cursor);
}



template <class T> void Lista<T>::iniciarCursorNodo()
{
  this->cursor = NULL;
}



template <class T> bool Lista<T>::avanzarCursorNodo()
{
  if (this->cursorNodo == NULL)
    {
      this->cursorNodo = primerNodo;
    }
  else
    {
      this->cursorNodo=this->cursorNodo->obtenerSiguiente();
    }
  return (this->cursorNodo != NULL);
}




template<class T> T Lista<T>::obtenerCursorNodo() 
{
  T elemento;
  if (this->cursor != NULL) 
    {
      elemento = this->cursor->obtenerObjeto();
    }
  return elemento;
}



template <class T> Lista<T>::~Lista() 
{
  while (this->primerNodo != NULL)
    {
      Nodo<T>* aBorrar = this->primerNodo;
      this->primerNodo = this->primerNodo->obtenerSiguiente();
      
      delete aBorrar;
    }
}

#endif


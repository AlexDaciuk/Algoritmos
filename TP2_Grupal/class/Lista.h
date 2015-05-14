#ifndef LISTA_H
#define LISTA_H

#ifndef NULL
#define NULL 0
#include <iostream>
#include "Nodo.h"

template <class T>
class Lista<T>
{
private:
  
  Nodo<T>* primerNodo;
  Nodo<T>* ultimoNodo;
  Nodo<T>* cursorNodo;
  
public:
  
  Lista();
  void insertar( T objeto);
  Nodo<T>* obtenerPunteroAlObjeto(int numeroDeObjeto);
  void ponerPrimero(int numeroDeObjeto);
  T obtenerCursorNodo();
  bool avanzarCursorNodo();
  void iniciarCursorNodo();
  ~Lista();
};

template <class T>
Lista<T>::Lista()
{
  this->primerNodo=NULL;
  this->ultimoNodo=NULL;
};

template <class T>
void Lista<T>::insertar( T objeto)
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
};

template <class T>
Nodo<T>* Lista<T>::obtenerPunteroAlObjeto(int numeroDeObjeto)
{
  Nodo<T>* cursor=this->primerNodo;
  while((this->cursor->obtenerObjeto()->obtenerNumero() != numeroDeObjeto) && (cursor != NULL))
    cursor=cursor->obtenerSiguiente();
  
  return cursor;
};

template <class T>
void Lista<T>::ponerPrimero(int numeroDeObjeto)
{
  Nodo<T>* cursor=obtenerNumeroObjeto(int numeroDeObjeto);
  Nodo<T>* cursorAnterior=cursor->obtenerAnterior();
  Nodo<T>* cursorSiguiente=cursor->obtenerSiguiente();
  cursorAnterior->cambiarNodoSiguiente(cursorSiguiente);
  cursorSiguiente->cambiarNodoAnterior(cursorAnterior);
  cursor->cambiarNodoAnterior(NULL);
  cursor->cambiarNodoSiguiente(this->primerNodo);
  this->primerNodo->cambiarNodoAnterior(cursor);
};

/* post: deja el cursor de la Lista preparado para hacer un nuevo
 * recorrido sobre sus elementos.
 */
template <class T>
void Lista<T>::iniciarCursorNodo()
{
  this->cursor = NULL;
};


/**
 * pre : se ha iniciado un recorrido (invocando el método
 *       iniciarCursor()) y desde entonces no se han agregado o
 *       removido elementos de la Lista.
 * post: mueve el cursor y lo posiciona en el siguiente elemento
 *       del recorrido.
 *       El valor de retorno indica si el cursor quedó posicionado
 *       sobre un elemento o no (en caso de que la Lista esté vacía o
 * no existan más elementos por recorrer.)
 */
template <class T>
bool Lista<T>::avanzarCursorNodo()
{
  if (this->cursorNodo==null)
    {
      this->cursorNodo=primerNodo;
    }
  else
    {
      this->cursorNodo=this->cursorNodo->obtenerSiguiente();
    }
  return (this->cursorNodo != NULL);
};

/*pre : el cursor está posicionado sobre un elemento de la Lista,
 *       (fue invocado el método avanzarCursor() y devolvió true)
 *post: devuelve el elemento en la posición del cursor.
 */
template<class T>  
T Lista<T>::obtenerCursorNodo() 
{
  T elemento;
  if (this->cursor != NULL) 
    {
      elemento = this->cursor->obtenerObjeto();
    }
  return elemento;
};

template <class T>
Lista<T>::~Lista() 
{
  while (this->primerNodo != NULL) {
    
    Nodo<T>* aBorrar = this->primerNodo;
    this->primerNodo = this->primerNodo->obtenerSiguiente();
    
    delete aBorrar;
  }
};

#endif
#endif


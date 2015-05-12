#ifndef NODO_H
#define NODO_H
#ifndef NULL
#define NULL 0
#include <iostream>

template <class T>
class Nodo<T>
{
  private:
    T objeto;
    Nodo<T>* nodoSiguiente;
    Nodo<T>* nodoAnterior;
  public:
  /**
 *Clase que define a cada nodo de una lista simple
 */
    Nodo<T>(T objeto);
    void cambiarNodoSiguiente(Nodo<T>* nodoSiguiente);
    void cambiarNodoAnterior(Nodo<T>* nodoAnterior);
    void cambiarObjeto(T objeto);
    Nodo<T>* obtenerSiguiente();
    Nodo<T>* obtenerAnterior();
    T obtenerObjeto();
};

/**
 * pre: se le debe pasar un objeto del tipo correspondiente al tipo que guarda el nodo.
 * post: el nodo se crea con un dato almacenado y sus punteros apuntando a null
 */
template <class T>
Nodo<T>::Nodo(T objeto)
{
  this-> objeto= objeto;
  this-> nodoSiguiente= NULL;
  this-> nodoAnterior= NULL;
};
/**
 * post: se cambia la direccion del puntero del nodo que apuntaria al siguinete nodo*/
template <class T>
void Nodo<T>::cambiarNodoSiguiente(Nodo<T>* nodoSiguiente)
{
  this->nodoSiguiente=nodoSiguiente;
};
/**
 * post: se cambia la direccion del puntero del nodo que apuntaria al nodo anterior*/
template <class T>
void Nodo<T>::cambiarNodoAnterior(Nodo<T>* nodoAnterior)
{
  this->nodoAnterior=nodoAnterior;
};
/**
 * post: devuelve la direccion de memoria del proximo nodo en la lista.
 * si no existe devuelve null.
 * */
template <class T>
Nodo<T>* Nodo<T>::obtenerSiguiente()
{
  return nodoSiguiente;
};
/**
 * post: devuelve la direccion de memoria del nodo anterior en la lista.
 * si no existe devuelve null.
 * */
template <class T>
Nodo<T>* Nodo<T>::obtenerAnterior()
{
  return nodoAnterior;
};

/**
 * post: devuelve el objeto guardado en el nodo.
 * */
template <class T>
T Nodo<T>::obtenerObjeto()
{
  return objeto;
};

/**
 * pre: el objeto debe ser del mismo tipo del que acepta el nodo.
 * post: devuelve una copia del objeto guardado.
 * */
template <class T>
void Nodo<T>::cambiarObjeto(T objeto)
{
  this->objeto=objeto;
};

#endif
#endif

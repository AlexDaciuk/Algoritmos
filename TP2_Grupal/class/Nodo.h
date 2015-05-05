#ifndef NODO_H
#define NODO_H
#define NULL 0
#include <iostream>

template <class T>
class Nodo<T>
{
  private:
    T objeto;
    Nodo<T>* nodoSiguiente;
  public:
  /**
 *Clase que define a cada nodo de una lista simple
 */
    Nodo<T>(T objeto);
    void cambiarNodoSiguiente(Nodo<T>* nodoSiguiente);
    Nodo<T>* obtenerSiguiente();
    T obtenerObjeto();
};

template <class T>
Nodo<T>::Nodo(T objeto)
{
  this-> objeto= objeto;
  this-> nodoSiguiente= NULL;
};

template <class T>
void Nodo<T>::cambiarNodoSiguiente(Nodo<T>* nodoSiguiente)
{
  this->nodoSiguiente=nodoSiguiente;
};

template <class T>
Nodo<T>* Nodo<T>::obtenerSiguiente()
{
  return nodoSiguiente;
};

template <class T>
T Nodo<T>::obtenerObjeto()
{
  return objeto;
};
#endif

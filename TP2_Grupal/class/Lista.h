#ifndef LISTA_H
#define LISTA_H
#ifndef NULL
#define NULL 0
#include <iostream>

template <class T>
class Lista<T>
{
  private:
  
    Nodo<T>* primerNodo;
    Nodo<T>* ultimoNodo;
    
  public:
  
    Lista();
    void insertar( T objeto);
    Nodo<T>* buscarNodo(int numeroDeObjeto);
    void ponerPrimero(int codigo);
};

template <class T>
Lista::Lista()
{
  this->primerNodo=NULL;
  this->ultimoNodo=NULL;
};

template <class T>
void Lista::insertar( T objeto)
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
Nodo<T>* Lista::buscarNodo(int numeroDeObjeto)
{
  Nodo<T>* cursor=this->primerNodo;
  while((this->cursor->obtenerObjeto->obtenerNumero != numeroDeObjeto) && (cursor != NULL))
    cursor=cursor->obtenerSiguiente;
};
#endif
#endif

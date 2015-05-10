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
    Nodo<T>* obtenerNumeroObjeto(int numeroDeObjeto);
    void ponerPrimero(int numeroDeObjeto);
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
Nodo<T>* Lista<T>::obtenerNumeroObjeto(int numeroDeObjeto)
{
  Nodo<T>* cursor=this->primerNodo;
  while((this->cursor->obtenerObjeto->obtenerNumero != numeroDeObjeto) && (cursor != NULL))
    cursor=cursor->obtenerSiguiente;
    
    return cursor;
};

template <class T>
void Lista<T>::ponerPrimero(int numeroDeObjeto)
{
  Nodo<T>* cursor=obtenerNumeroObjeto(int numeroDeObjeto);
  Nodo<T>* cursorAnterior=cursor->obtenerAnterior;
  Nodo<T>* cursorSiguiente=cursor->obtenerSiguiente;
  cursorAnterior->cambiarNodoSiguiente(cursorSiguiente);
  cursorSiguiente->cambiarNodoAnterior(cursorAnterior);
  cursor->cambiarNodoAnterior(NULL);
  cursor->cambiarNodoSiguiente(this->primerNodo);
  this->primerNodo->cambiarNodoAnterior(cursor);
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

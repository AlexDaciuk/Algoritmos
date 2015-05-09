#ifndef LISTA_H
#define LIsTA_H
#define NULL=0
#include <iostream>

template <class T>
class Lista<T>
{
  private:
  
    Nodo<T>* primerNodo;
    Nodo<T>* ultimoNodo;
    
  public:
  
    Lista();
    void Insertar( T objeto);
    void Borrar(int codigo);//El codigo con el que identificamos al objeto en la lista
    void PonerPrimero(int codigo);
};

template <class T>
Lista::Lista()
{
  this->primerNodo=NULL;
  this->ultimoNodo=NULL;
};

template <class T>
void Lista::Insertar( T objeto)
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


#endif

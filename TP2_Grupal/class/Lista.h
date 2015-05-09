#ifndef LISTA_H
#define LIsTA_H
#include <iostream>

template <class T>
class Lista
{
  private:
  
    Nodo<T>* primerNodo;
    Nodo<T>* ultimoNodo;
    
  public:
  
    Lista();
    void Insertar( T dato);
    void Borrar(int codigo);//El codigo con el que identificamos al objeto en la lista
    void PonerPrimero(int codigo);
};

#endif

#ifndef MENU_H
#define MENU_H
#include "Lista.h"

#include "Opciones.h"

class Menu
{
private:
  
  Lista<Opciones>* punteroOpciones;
  int numeroDeOpciones; 
  
public:
  
  Menu(int numeroDeOpciones);
  void cambiarPunteroOpciones(Lista<Opciones>* nuevoPuntero);
  Lista<Opciones>* obtenerPunteroOpciones();
  int obtenerNumeroDeOpciones();
  std::string mostrarOpciones(Lista<Opciones>* punteroAOpciones);
 
};

#endif

#ifndef MENU_H
#define MENU_H
#include "Lista.h"
#include <string>
#include "Opciones.h"

class Menu
{
private:
  
  Lista<Opciones>*::Lista punteroOpciones;
  int numeroDeOpciones; 
  
public:
  
  Menu(int numeroDeOpciones);
  void cambiarPunteroOpciones(Lista::Lista<Opciones>* nuevoPuntero);
  Lista<Opciones>*::Lista obtenerPunteroOpciones();
  int obtenerNumeroDeOpciones();
  std::string mostrarOpciones();
 
};

#endif

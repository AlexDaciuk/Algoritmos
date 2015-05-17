#include "Menu.h"
#include "Opciones.h"


  Menu::Menu(int cantidadDeOpciones)
{
  this->cantidadDeOpciones=cantidadDeOpciones;
  this->punteroListaOpciones= new Lista<Opciones>;
};

void Menu::cambiarPunteroListaOpciones(Lista<Opciones>* nuevoPuntero)  
{
  this->punteroOpciones=nuevoPuntero;
};

Lista<Opciones>* Menu::obtenerPunteroListaOpciones()
{
  return this->punteroOpciones;
};

int Menu::obtenerCantidadDeOpciones()
{
  return this->cantidadDeOpciones;
};





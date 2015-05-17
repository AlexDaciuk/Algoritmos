#include "Menu.h"
#include "Opciones.h"


  Menu::Menu(int numeroDeOpciones)
{
  this->numeroDeOpciones=numeroDeOpciones;
  this->punteroOpciones= new Lista<Opciones>;
};

void Menu::cambiarPunteroOpciones(Lista<Opciones>* nuevoPuntero)  
{
  this->punteroOpciones=nuevoPuntero;
};

Lista<Opciones>* Menu::obtenerPunteroOpciones()
{
  return this->punteroOpciones;
};

int Menu::obtenerNumeroDeOpciones()
{
  return this->numeroDeOpciones;
};





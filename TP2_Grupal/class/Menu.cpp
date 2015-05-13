#include "Menu.h"
#ifndef NULL
#define NULL 0

Menu::Menu(int numeroDeOpciones)
{
  this->numeroDeOpciones=numeroDeOpciones;
  this->punteroOpciones=NULL;
};

void Menu::cambiarPunteroOpciones(Lista<Opciones>* nuevoPuntero)  
{
  this->punteroOpciones=nuevoPuntero;
};

Lista<Opciones>* Menu::obtenerPunteroOpcion()
{
  return this->punteroOpciones;
};


#include "Menu.h"
#include "Lista.h"
#include "Opciones.h"
#ifndef NULL
#define NULL 0

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

std::string Menu::mostrarOpciones()
{
  std::string Descripcion;
  iniciarCursorNodo();
  while (this->avanzarCursorNodo());
  {
    obtenerCursorNodo()->


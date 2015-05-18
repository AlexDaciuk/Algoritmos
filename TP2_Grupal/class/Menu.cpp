#include "Menu.h"
#include "Opciones.h"


Menu::Menu(int cantidadDeOpciones)
{
  this->cantidadDeOpciones=cantidadDeOpciones;
  this->punteroListaOpciones= new Lista<Opciones>;
}

void Menu::cambiarPunteroListaOpciones(Lista<Opciones>* nuevoPuntero)  
{
  this->punteroOpciones=nuevoPuntero;
}

Lista<Opciones>* Menu::obtenerPunteroListaOpciones()
{
  return this->punteroOpciones;
}

int Menu::obtenerCantidadDeOpciones()
{
  return this->cantidadDeOpciones;
}

std::string Menu::mostrarOpciones()
{
  std::string opcion1="1)Imprimir detalle de internos, nombres y números.\n";
  std::string opcion2="2)Imprimir detalle de internos, nombres y números.\n";
  std::string opcion3="3)Imprimir detalle de enlaces (origen, destino, canales). \n";
  std::string opcion4="4)Detalle de llamadas entre el interno 'X' de la central 'A' al interno 'Y' de la central 'B'.\n";
  std::string opcion5="5)Interno que mas hablo de todos y de cada central.\n";
  std::string opcion6="6)Interno que más llamó de todos y de cada central.\n";
  std::string opcion7="7) Interno que mas le dio ocupado sus intentos y de cada central.\n";
  std::string opcion8="8)Interno al que más llamaron de todos y de cada central.\n";
  std::string opcion9="9)Interno que mas gasto de todos y de cada central.\n";
  std::string opcion10="10)Interno al que más le hablaron de todos y de cada central.\n";
  std::string opcion11="11)Interno que más dio ocupado de todos y de cada central.\n";
  std::string opcion12="12)Detalle de llamadas emitidas por el interno X de la central A.\n";
  std::string opcion13="13)Detalle de llamadas recibidas por el interno X de la central A.\n";
  std::string opcion14="14)Detalle de llamadas realizadas de X de la central A a Y de la Central B.\n";
  std::string opcion15="15)Detalle de llamadas recibidas por X de la Central A y realizadas por Y de la Central B.\n";
  std::string opcion16="16)Imprimir cantidad de llamadas anuladas por falta de enlaces por central,ordenado por cantidad descendiente.\n";
  std::string opcion17="17)Salir. \n \n";
  
  std::string opcionTotal = opcion1 + opcion2 + opcion3 + opcion4 + opcion5 + opcion6 + opcion7 + opcion8 + opcion9 + 
  opcion10 + opcion11 + opcion12 + opcion13 + opcion14 + opcion15 + opcion16 + opcion17;

  return opcionTotal;
}



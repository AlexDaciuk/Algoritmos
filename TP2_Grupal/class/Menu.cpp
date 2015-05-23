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

}

std::string Menu::pedirRuta()
{
	std::cout<<"Ingrese la ruta del archivo de llamadas.\n";
	std::string ruta;
	std::cin >> ruta;
	return ruta;
}

bool Menu::realizarOtraConsulta()
{
	char respuesta;
	std::cout<<"Desea ralizar otra consulta? [s/n]:";
	std::cin>>respuesta;
	return (respuesta==s);
}



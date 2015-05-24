#include "Interfaz.h"
#include <string>
#include <sstream>
#include <iostream>
#include "DatosLlamada.h"
#include "Menu.h"
#include "ProcesadorLlamada.h"
#include "LectorArchivos.h"
#include "Opciones.h"
#include "Lista.h"
#include "Enlace.h"
#include "Central.h"
#include "Internos.h"

Interfaz::Interfaz()
{
  this->enlaces= NULL;
  this->centrales= NULL;
  this->LectorDeArchivos=NULL;
}

void Interfaz::cambiarPunteroPunteroALectorDeArchivos(LectorArchivos* nuevoPuntero)
{
  this->punteroALectorDeArchivos=nuevoPuntero;
}

std::string Interfaz::pedirRuta()
{
  std::string ruta;
  std::cout<<"Ingrese la ruta del archivo de llamadas:";
  std::cin>>ruta;
  return ruta;
}

void Interfaz::mostrarMenu()
{
  std::cout<<"Bienvenido al sistema de informacion de la central telefonica.\n \n";
	std::cout<<"A continuacion de detalla el menu:\n\n";
  std::cout<<"1)Imprimir detalle de internos, nombres y números.\n";
  std::cout<<"2)Imprimir detalle de centrales con su numeración.\n";
  std::cout<<"3)Imprimir detalle de enlaces (origen, destino, canales). \n";
  std::cout<<"4)Detalle de llamadas entre el interno 'X' de la central 'A' al interno 'Y' de la central 'B'.\n";
  std::cout<<"5)Interno que mas hablo de todos y de cada central.\n";
  std::cout<<"6)Interno que más llamó de todos y de cada central.\n";
  std::cout<<"7) Interno que mas le dio ocupado sus intentos y de cada central.\n";
  std::cout<<"8)Interno al que más llamaron de todos y de cada central.\n";
  std::cout<<"9)Interno que mas gasto de todos y de cada central.\n";
  std::cout<<"10)Interno al que más le hablaron de todos y de cada central.\n";
  std::cout<<"11)Interno que más dio ocupado de todos y de cada central.\n";
  std::cout<<"12)Detalle de llamadas emitidas por el interno X de la central A.\n";
  std::cout<<"13)Detalle de llamadas recibidas por el interno X de la central A.\n";
  std::cout<<"14)Detalle de llamadas realizadas de X de la central A a Y de la Central B.\n";
  std::cout<<"15)Detalle de llamadas recibidas por X de la Central A y realizadas por Y de la Central B.\n";
  std::cout<<"16)Imprimir cantidad de llamadas anuladas por falta de enlaces por central,ordenado por cantidad descendiente.\n";
  std::cout<<"17)Salir. \n \n";

}

int Interfaz::pedirOpcionMenu()
{ 
  int opcion;
  std::cout<<"Elija una opcion:";
  std::cin>>opcion;
  return opcion;
}

std::string Interfaz::pedirAlgoritmoDeBusqueda()
{
  int opcion;
  std::string opcionAlgoritmo;
  std::cout<< "Quiere usar algoritmo de: \n";
  std::cout<< "1) Precio mas bajo \n";
  std::cout<< "2) Distancia mas corta \n";
  std::cin>>opcion;
  switch (opcion)
  {
  case 1:
      opcionAlgoritmo = "Precio";
      break;
    
  case 2:
      opcionAlgoritmo = "Distancia";
      break;
  }
  return opcionAlgoritmo;
}

Lista<Enlace>* Interfaz::obtenerenlaces()
{
   return this->enlaces;
}
Lista<Central>* Interfaz::obtenercentrales()
{
  return this->centrales;
}
void Interfaz::iniciarlizarPunteroAEnlaces(ProcesadorLlamada* procesadorDeLlamadas)
{
  this->enlaces= procesadorDeLlamadas->obternerEnlaces();
}
void Interfaz::iniciarlizarPunteroACentrales(ProcesadorLlamada* procesadorDeLlamadas)
{
  this->centrales= procesadorDeLlamadas->obtenerCentrales();
}

void Interfaz::mostrarDetallesDeInternos()
{
  this->centrales->iniciarCursorNodo();
  while (this->centrales->avanzarCursorNodo())
  {
    std:cout<<"Internos de la central:"<<this->centrales->obtenerCursorNodo->obtenerNumero()<<": \n";
    Lista<Internos>* punteroAInternos= this->centrales->obtenercursorNodo()->obtenerInternos();
    punteroAInternos->iniciarCursorNodo();
    while (this->punteroAInternos->avanzarCursorNodo())
    {
      std::cout<<"Interno:"<<punteroAInternos->obternerCursorNodo()->obtenerNumero()<<". \n";
    }
    std::cout>>endl;
  }
}
void Interfaz::tratarOpcion(int opcion)
{
  bool continuar=true;
  while (continuar)
  {
    std::cin>>opcion;
    switch(opcion)
    {
      case 1:	mostrarDetallesDeInternos();
              realizarOtraConsulta(opcion,continuar);
              break;
      
      case 2:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 3:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 4:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 5:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 6:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 7:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 8:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 9:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 10:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 11:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 12:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 13:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 14:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 15:
              realizarOtraConsulta(opcion,continuar);
              break;
  
  
      case 16:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 17: continuar=false;
               std::cout<<endl;
               std::cout<<"Hasta luego. \n"; 
              break;
		} 
	}
}
	void Interfaz::realizarOtraConsulta(int& opcion, bool& continuar)
	{
		std::cout<<"Desea realizar otra consulta? s/n:";
		char respuesta;
		std::cin>>respuesta;
		if 	(respuesta=='s')
		{
			continuar=true;
			std::cout<<endl;
			mostrarMenu();
			opcion = pedirOpcionMenu();
		}
		else	
		{
			continuar=false;
			std::cout<<endl;
			std::cout<<"Hasta luego.\n \n";
		}
	}
void Interfaz::iniciarPrograma()
{
  LectorArchivos* lectorDeArchivos = new LectorArchivos (pedirRuta())
  this->cambiarPunteroALectorDeArchivos(lectorDeArchivos);
  
	std::string variableDeBusqueda = pedirAlgoritmoDeBusqueda();
  mostrarMenu();
  int opcion = pedirOpcionMenu();
	TratarOpcion(opcion);
}



  
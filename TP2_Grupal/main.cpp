#include <iostream>
#include <string>

#include "class/DatosLlamada.h"
#include "class/Menu.h"
#include "class/ProcesadorLlamada.h"
#include "class/LectorArchivos.h"
#include "class/Opciones.h"

int main()
{
  const int numeroDeOpciones = 17;
  std::string opcionAlgoritmo;
  Menu menuOpciones(numeroDeOpciones);
  
  std::cout<< "Quiere usar algoritmo de: \n";
  std::cout<< "1) Precio mas bajo \n";
  std::cout<< "2) Distancia mas corta \n";

  int opcionTemporal;
  
  std::cin >> opcionTemporal;
  switch (opcionTemporal)
    {
    case 1:
      opcionAlgoritmo = "Precio";
      break;
      
    case 2:
      opcionAlgoritmo = "Distancia";
      break;
    }
  
  ProcesadorLlamada* procesadorDeLlamadas = new ProcesadorLlamada::ProcesadorLlamada();
  procesadorDeLlamadas->procesarLlamadas(menuOpciones.pedirRuta());

  std::cout<<"Bienvenido al sistema de informacion de la central telefonica.\n \n";
	std::cout<<"A continuacion de detalla el menu, elija la que desee.\n\n";
  std::cout<< menuOpciones->mostrarOpciones();
  int opcionMenu;
  std::cout<<"Opcion: \n\n";
  std::cin>>opcionMenu;
  
  /**
   * resolucion de opciones
   * */

    
  return 0;
}

#include <iostream>
#include <string>
#include "class/Lista.h"
#include "class/Central.h"
#include "class/Llamada.h"
#include "class/Internos.h"
#include "class/Enlace.h"
#include "class/LectorArchivos.h"
#include "class/DatosLlamada.h"
#include "class/Menu.h"
#include "class/Opciones.h"

int main()
{
  
  std::string opcionAlgoritmo;
  Menu menuOpciones(17);
  Lista<Opciones> listaOpciones;
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
  
  std::cout<<"Menu de opciones:\n\n";
  std::cout<< "i)" <<  menuOpciones.mostrarOpciones(menuOpciones.obtenerPunteroOpciones()) <<"\n";
    
  
    
  return 0;
}

#include <iostream>
#include <string>
#include "class/ProcesadorLlamada.h"
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
  std::cout<<"Ingrese la ruta del archivo de llamadas.\n";
  std::string ruta;
  ProcesadorLlamada procesadorDeLlamadas;
  procesadorDeLlamadas.procesarLlamadas(ruta);
  
  /**
   * Agregar las opciones en la lista.
   * 
   * */
  std::cout<<"Menu de opciones:\n\n";
  Lista<Opciones>* OpcionesDelMenu = menuOpciones.obtenerPunteroOpciones();
  OpcionesDelMenu->iniciarCursorNodo();
  int i=0;
  while (OpcionesDelMenu->avanzarCursorNodo())
  {
    std::cout<<i<<")"<<OpcionesDelMenu->obtenerCursorNodo()->obtenerDescripcion()<<"\n";
    i++;
  }
  
    
  
    
  return 0;
}

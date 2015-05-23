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
  
  
 
  
 
  
  ProcesadorLlamada* procesadorDeLlamadas = new ProcesadorLlamada::ProcesadorLlamada();
  procesadorDeLlamadas->procesarLlamadas(menuOpciones.pedirRuta());

  
  std::cout<< menuOpciones->mostrarOpciones();
  int opcionMenu;
  std::cout<<"Opcion: \n\n";
  std::cin>>opcionMenu;
  
  /**
   * resolucion de opciones
   * */

    
  return 0;
}

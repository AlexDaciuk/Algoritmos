#include <iostream>
#include <string>
#include "class/Central.h"
#include "class/Llamada.h"
#include "class/Internos.h"
#include "class/Enlace.h"
#include "class/LectorArchivos.h"
#include "class/DatosLlamada.h"
#include "class/Menu.h"


int main()
{
  
  std::string opcionAlgoritmo;
  Menu menuOpciones(17);
  Lista<Opciones> listaOpciones;
  cout<< "Quiere usar algoritmo de: \n";
  cout<< "1) Precio mas bajo \n";
  cout<< "2) Distancia mas corta \n";

  int opcionTemporal;
  
  cin >> opcionTemporal;
  switch (opcionTemporal)
    {
    case 1:
      opcionAlgoritmo = "Precio";
      break;
      
    case 2:
      opcionAlgoritmo = "Distancia";
      break;
    }
  
  cout<<"Menu de opciones:\n\n";
  for (int i=0; i<menuOpciones.obtenerNumeroDeOpciones(), i++)
  {
    cout<<i")"menuOpciones.mostrarOpciones()"\n";
  };
    
  
    
  return 0;
}

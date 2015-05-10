#include <iostream>
#include <string>
#include "class/Central.h"
#include "class/Llamada.h"
#include "class/Internos.h"
#include "class/Enlace.h"
#include "class/LectorArchivos.h"
#include "class/DatosLlamada.h"





int main()
{

  std::string opcionAlgoritmo;


  cout << "Quiere usar algoritmo de: \n";
  cout << "1) Precio mas bajo \n";
  cout << "2) Distancia mas corta \n";

  int opcionTmp;

  cin >> opcionTmp;

  
  if ( opcionTmp == 1)
    {
      opcionAlgoritmo = "Precio";
    }
  else if ( opcionTmp == 2)
    {
      opcionAlgoritmo = "Distancia";
    }

  
  
  


  
  return 0;
}

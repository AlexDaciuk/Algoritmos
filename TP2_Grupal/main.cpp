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

  /**
   * Proceso el archivo
   */

  std::cout<<"Ingrese la ruta del archivo de llamadas.\n";
  std::string ruta;

  // ProcesadorLlamada procesadorDeLlamadas;
  procesadorDeLlamadas.procesarLlamadas(ruta);

  std::cout<<"Menu de opciones:\n\n";
  cout<<"0)Imprimir detalle de internos, nombres y números.\n";
  cout<<"1)Imprimir detalle de centrales con su numeración.\n";
  cout<<"2)Imprimir detalle de enlaces (origen, destino, canales). \n";
  cout<<"3)Detalle de llamadas entre el interno 'X' de la central 'A'"; 
  cout<<"al interno 'Y' de la central 'B'.\n";
  
  cout<<"4)Interno que mas hablo de todos y de cada central.\n";
  cout<<"5)Interno que más llamó de todos y de cada central.\n";
  cout<<"6) Interno que mas le dio ocupado sus intentos y de cada central.\n";
  cout<<"7)Interno al que más llamaron de todos y de cada central.\n";
  cout<<"8)Interno que mas gasto de todos y de cada central.\n";
  cout<<"9)Interno al que más le hablaron de todos y de cada central.\n";
  cout<<"10)Interno que más dio ocupado de todos y de cada central.\n";
  cout<<"11)Detalle de llamadas emitidas por el interno X de la central A.\n";
  cout<<"12)Detalle de llamadas recibidas por el interno X de la central A.\n";
  cout<<"13)Detalle de llamadas realizadas de X de la central A a Y de la Central B.\n";
  cout<<"14)Detalle de llamadas recibidas por X de la Central A";
  cout<<"y realizadas por Y de la Central B.\n";
  
  cout<<"15)Imprimir cantidad de llamadas anuladas por falta de enlaces por central,";
  cout<<"ordenado por cantidad descendiente.\n"
  cout>>"16)Salir. \n \n";
  int opcionMenu;
  cout<<"Opcion: \n\n";
  cin>>opcionMenu;
  
  

  
    
  
    
  return 0;
}

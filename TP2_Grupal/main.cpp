#include <iostream>
#include <string>
#include "class/Central.h"
#include "class/Llamada.h"
#include "class/Internos.h"
#include "class/Enlace.h"
#include "class/LectorArchivos.h"
#include "class/DatosLlamada.h"
#include "menu.h"


int main()
{
  
  std::string opcionAlgoritmo;
  int opcion;
  
  ElgirAlgoritmo(opcionAlgoritmo);
  MostrarMenuYElegirOpcion (opcion);
  TratarOpcion(opcion);
  return 0;
}

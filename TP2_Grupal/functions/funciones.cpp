#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "funciones.h"

using namespace std;

/**
 *Funcion normal que pide la ruta relativa del archivo con las llamadas
 * al usuario y luego las separa por linea y luego por palabra para
 * despues procesarlas 
 * Post: Todas las llamadas van a estar registradas en su respectiva central y
 * su respectivo interno
 */

void leerArchivo()
{
  ifstream archivo;
  string ruta;

  cout << "Por favor ingrese la ruta del archivo a procesar: " ;
  getline(cin, ruta);

  archivo.open( ruta.c_str() );

  while (! archivo.eof() )
    {
      string accionTemporal, centralATemporal, internoATemporal, centralBTemporal, internoBTemporal, horaTemporal;
	  string distanciaKmTemporal, precioMinutoTemporal, cantidadCanalesTemporal;
      
      if (accionTemporal == "Enlace")
      {
		  getline(archivo, accionTemporal,' ');

		  getline(archivo, centralATemporal,' ');
		  
		  getline(archivo, centralBTemporal,' ');
		  
		  getline(archivo, distanciaKmTemporal,' ');
			  
		  getline(archivo, precioMinutoTemporal,' ');

		  getline(archivo, cantidadCanalesTemporal,'\n');
		  
		  if (! accionTemporal.empty()  )
			{
			procesarEnlace(accionTemporal, centralATemporal, centralBTemporal, distanciaKmTemporal, precioMinutoTemporal,
						   cantidadCanalesTemporal);
			}
	  }
	  if (accionTemporal != "Enlace")
	  {
		  getline(archivo, accionTemporal,' ');

		  getline(archivo, centralATemporal,' ');
		  
		  getline(archivo, internoATemporal,' ');

		  getline(archivo, centralBTemporal,' ');
			  
		  getline(archivo, internoBTemporal,' ');

		  getline(archivo, horaTemporal,'\n');

		  if (! accionTemporal.empty()  )
			{
			procesarLlamadas(accionTemporal, centralATemporal, internoATemporal, centralBTemporal, internoBTemporal,
							 horaTemporal);
			}
		}
    }
}



void procesarLlamadas(string accionTemporal, string centralATemporal, string internoATemporal, string centralBTemporal, 
					  string internoBTemporal, string horaTemporal)
{

  if ( accionTemporal == "Inicio")
    {
      // Aca vamos a procesar los inicios de llamada, tambien se van a crear los internos si no existen en sus centrales
    }
  else if (accionTemporal == "Fin")
    {
      // Aca vamos a procesar los fines de llamadas
    }
  
}


void procesarEnlace(string accionTemporal, string centralATemporal, string centralBTemporal, string distanciaKmTemporal, string precioMinutoTemporal, string cantidadCanalesTemporal)
{

  // Aca procesamos los enlaces por separado

}

  



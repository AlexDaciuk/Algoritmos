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
      
	  getline(archivo, accionTemporal,' ');
	  
      if (accionTemporal == "Enlace")
      {
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

  
void menu()
{
  int opcionMenu;
    do
      {
		cout << "Bienvenido al sistema de estadisticas telefonicas V2.0 \n\n";
		cout << "Menu \n";
		cout << "1) Detalles de llamadas entre 2 internos (indistinto de central) \n";
		cout << "2) Interno que mas hablo de todos y de cada central \n";
		cout << "3) Interno que mas llamo de todos y de cada central \n";
		cout << "4) Interno con mas ocupados recibidos y de cada central \n";
		cout << "5) Interno al que mas llamaron y de cada central \n";
		cout << "6) Interno que mas gasto y de cada central \n";
		cout << "7) Interno que mas le hablaron y de cada central \n";
		cout << "8) Interno que mas ocupados dio y de cada central \n";
		cout << "9) Detalles de llamadas emitidas de un interno de cierta central \n";
		cout << "10) Detalles de llamadas recibidas de un interno de cierta central \n";
		cout << "11) Detalles de llamadas realizadas de un interno a otro (distintas centrales) \n";
		cout << "12) Imprimir cantidad de llamadas fallidas por falta de enlaces en la central \n";
		cout << "13) Imprimir detalles de enlaces \n";
		cout << "14) Imprimir detalles de internos \n";
		cout << "15) Imprimir detalles de centrales con su numeracion \n";
		cout << "16) Salir \n\n";

		cout << "Opcion : " ;
		cin >> opcionMenu;

		switch (opcionMenu )
		  {
			  case 1:
				{
				  
				}
			  case 2:
				{
				
				}
			  case 3:
				{
				
				}
			  case 4:
				{
				
				}
			  case 5:
				{
				
				}
			  case 6:
				{
				
				}
			  case 7:
				{
				
				}
			  case 8:
				{
				  
				}
			  case 9:
				{
				  
				}
			  case 10:
				{
				
				}
			  case 11:
				{
				  
				}
			  case 12:
				{
				  
				}
			  case 13:
				{
				  
				}
			  case 14:
				{

				}
			  case 15:
				{
				  
				}


		  }
      }
    while (opcionMenu != 16);
};

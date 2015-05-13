#include "menu.h"
#include <iostream>

void MostrarMenuYElegirOpcion (int& opcion)
{
  cout<<"Bienvenido al sistema de informacion de la central telefonica.\n \n";
	cout<<"A continuacion de detalla el menu, elija la que desee.\n\n";
  
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
  cout<<"Opcion: \n\n";
  
};

void ElgirAlgoritmo(sts::string& opcionAlgoritmo)
{
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
};
  

void realizarOtraConsulta(int& opcion, bool& continuar)
{
	cout<<"Desea realizar otra consulta? s/n:";
	char respuesta;
	cin>>respuesta;
	if 	(respuesta=='s')
	{
		continuar=true;
		cout<<endl;
    cout<<"Elija una opcion:\n";
    MostrarMenuElegirOpcion(opcion);
	}
	else	
	{
		continuar=false;
		cout<<endl;
		cout<<"Hasta luego.\n \n";
	}
};

void TratarOpcion(int opcion)
{
  bool continuar=true;
  while (continuar)
  {
    cin>>opcion;
    switch(opcion)
    {
      case 0:
              realizarOtraConsulta(opcion,continuar);
              break;
      
      case 1:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 2:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 3:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 4:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 5:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 6:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 7:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 8:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 9:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 10:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 11:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 12:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 13:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 14:
              realizarOtraConsulta(opcion,continuar);
              break;
  
  
      case 15:
              realizarOtraConsulta(opcion,continuar);
              break;
  
      case 16: continuar=false;
               cout<<endl;
               cout<<"Hasta luego. \n"; 
              break;
  

#include "Interfaz.h"

Interfaz::Interfaz()
{
  this->enlaces = NULL;
  this->centrales = NULL;
  this->lectorDeArchivos = NULL;
}

void Interfaz::cambiarPunteroPunteroALectorDeArchivos(LectorArchivos* nuevoPuntero)
{
  this->lectorDeArchivos = nuevoPuntero;
}

std::string Interfaz::pedirRuta()
{
  std::string ruta;
  std::cout << "Ingrese la ruta del archivo de llamadas:";
  std::cin >> ruta;
  return ruta;
}

void Interfaz::mostrarMenu()
{
  std::cout << "Bienvenido al sistema de informacion de la central telefonica.\n \n";
  std::cout << "A continuacion de detalla el menu:\n\n";
  std::cout << "1)Imprimir detalle de internos, nombres y números.\n";
  std::cout << "2)Imprimir detalle de centrales con su numeración.\n";
  std::cout << "3)Imprimir detalle de enlaces (origen, destino, canales). \n";
  std::cout << "4)Detalle de llamadas entre el interno 'X' de la central 'A' al interno 'Y' de la central 'B'.\n";
  std::cout << "5)Interno que mas hablo de todos y de cada central.\n";
  std::cout << "6)Interno que más llamó de todos y de cada central.\n";
  std::cout << "7) Interno que mas le dio ocupado sus intentos de todos y de cada central.\n";
  std::cout << "8)Interno al que más llamaron de todos y de cada central.\n";
  std::cout << "9)Interno que mas gasto de todos y de cada central.\n";
  std::cout << "10)Interno al que más le hablaron de todos y de cada central.\n";
  std::cout << "11)Interno que más dio ocupado de todos y de cada central.\n";
  std::cout << "12)Detalle de llamadas emitidas por el interno X de la central A.\n";
  std::cout << "13)Detalle de llamadas recibidas por el interno X de la central A.\n";
  std::cout << "14)Detalle de llamadas realizadas de X de la central A a Y de la Central B.\n";
  std::cout << "15)Detalle de llamadas recibidas por X de la Central A y realizadas por Y de la Central B.\n";
  std::cout << "16)Imprimir cantidad de llamadas anuladas por falta de enlaces por central,ordenado por cantidad descendiente.\n";
  std::cout << "17)Salir. \n \n";
}

int Interfaz::pedirOpcionMenu()
{
  int opcion;
  std::cout << "Elija una opcion:";
  std::cin >> opcion;
  if (opcion < 1 || opcion > 17) {
    std::cout << "La opcion no existe. \/n" pedirOpcionMenu();
  }

  return opcion;
}

std::string Interfaz::pedirAlgoritmoDeBusqueda()
{
  int opcion;
  std::string opcionAlgoritmo;
  std::cout << "Quiere usar algoritmo de: \n";
  std::cout << "1) Precio mas bajo \n";
  std::cout << "2) Distancia mas corta \n";
  std::cin >> opcion;
  switch (opcion) {
  case 1:
    opcionAlgoritmo = "Precio";
    break;

  case 2:
    opcionAlgoritmo = "Distancia";
    break;
  }
  return opcionAlgoritmo;
}

Lista<Enlace>* Interfaz::obtenerenlaces()
{
  return this->enlaces;
}
Lista<Central>* Interfaz::obtenercentrales()
{
  return this->centrales;
}
void Interfaz::iniciarlizarPunteroAEnlaces(ProcesadorLlamada* procesadorDeLlamadas)
{
  this->enlaces = procesadorDeLlamadas->obternerEnlaces();
}
void Interfaz::iniciarlizarPunteroACentrales(ProcesadorLlamada* procesadorDeLlamadas)
{
  this->centrales = procesadorDeLlamadas->obtenerCentrales();
}

void Interfaz::mostrarDetallesDeInternos()
{
  this->obtenercentrales()->iniciarCursorNodo();
  while (this->obtenercentrales()->avanzarCursorNodo()) {
  std:
    cout << "Internos de la central:" << this->obtenercentrales()->obtenerCursorNodo->obtenerNumero() << ": \n";
    Lista<Interno*>* punteroAInternos = this->obtenercentrales()->obtenercursorNodo()->obtenerInternos();
    punteroAInternos->iniciarCursorNodo();
    while (this->punteroAInternos->avanzarCursorNodo()) {
      std::cout << "Interno:" << punteroAInternos->obternerCursorNodo()->obtenerNumero() << ". \n";
    }
    std::cout >> endl;
  }
}

void Interfaz::mostrarDetallesDeCentrales()
{
  std::cout << "A continuacion se indican los numeros de las centrales existentes: \n";
  this->obtenercentrales()->iniciarCursorNodo();
  while (this->obtenercentrales()->avanzarCursorNodo()) {
    std::cout << "Central numero:" << this->obtenercentrales()->obtenerCursorNodo()->obtenerNumero() << "\n";
  }
  std::cout << "\n"
}

void Interfaz::mostrarDetallesDeEnlaces()
{
  std::cout << "A continuacion se indican los dettalles de los enlaces existentes: \n";
  this->obtenerenlaces()->iniciarCursorNodo();
  int i = 0;
  while (this->obtenerenlaces()->avanzarCursorNodo()) {
    i++;
    std::cout << "Enlace " << i << ": \n";
    std::cout << "Central origen: " << obtenerenlaces()->obtenerCursorNodo()->obtenerOrigen()->obtenerNumero() << "\n";
    std::cout << "Central destino: " << obtenerenlaces()->obtenerCursorNodo()->obtenerDestino()->obtenerNumero()
              << "\n";
    std::cout << "Numero de canales: " << obtenerenlaces()->obtenerCursorNodo()->obtenerNumeroDeCanales() << "\n \n";
  }
}
int Interfaz::pedirCentral()
{
  int numeroDeCentral;
  std::cout << "Indique a que central pertenece:";
  std::cin >> numeroDeCentral;
  return numeroDeCentral;
}
void Interfaz::detallesLlamadasEntreInternoXeInternoY()
{
  int primerInterno, centralPrimerInterno, segundoInterno, centralSegundoInterno;
  std::cout << "Ingrese el numero del primer interno:";
  std::cin >> primerInterno;
  std::cout << "\n";
  centralPrimerInterno = pedirCentral();
  std::cout << "\n \n" std::cout << "Ingese el numero del segundo interno:";
  std::cin >> segundoInterno;
  centralSegundoInterno = pedirCentral();
  std::cout << "\n \n";
  Interno* buscadorDatosPrimerInterno, buscadorDatosSegundoInterno;
  buscadorDatosPrimerInterno = 
			obtenercentrales()->obtenerPunteroAlObjeto(centralSegundoInterno)->obtenerObjeto()->obtenerInterno(primerInterno); 
  buscadorDatosSegundoInterno =
      obtenercentrales()->obtenerPunteroAlObjeto(centralSegundoInterno)->obtenerObjeto()->obtenerInterno(segundoInterno);
  if (buscadorDatosPrimerInterno == NULL) {
    throw std::string "El primer interno no existe";
  }
  if (buscadorDatosSegundoInterno == NULL) {
    throw std::string "El segundo interno no existe";
  }
  std::cout << "Detalles de llamadas entre el interno " << primerInterno << " y " << segundoInterno << "\n";
  int numeroDeLlamadas = 0;
  int numeroDeOcupados = 0;
  bool encontro = false;
  buscadorDatosPrimerInterno->obtenerLlamadas()->iniciarCursorNodo();
  while (buscadorDatosPrimerInterno->obtenerLlamadas()->avanzarCursorNodo() && !encontro) {
    if (buscadorDatosPrimerInterno->obtenerLlamadas()->obtenerCursorNodo()->obtenerReceptorLlamada() ==
        segundoInterno) {
      encontro = true;
      numeroDeLlamadas = buscadorDatosPrimerInterno->obtenerLlamadas()->obtenerCursorNodo()->obtenerCantidadLlamadas();
      numeroDeOcupados =
          buscadorDatosPrimerInterno->obtenerLlamadas()->obtenerCursorNodo()->obtenerCantidadOcupadosDados() +
          buscadorDatosPrimerInterno->obtenerLlamadas()->obtenerCursorNodo()->obtenerCantidadOcupadosRecibidos();
    }
  }
  std::cout << "Llamadas realizadas:" << numeroDeLlamadas << "\n";
  std::cout << "Cantidad de ocupados:" << numeroDeOcupados << "\n \n";
}

void Interfaz::internoQueMasHabloPorCentralYGeneral()
{
  int maximaDuracionEnLaCentral = 0;
  int maximaDuracionGeneral = 0;
  int internoQueMasHabloPorCentral, internoQueMasHabloGeneral, centralQueMasHablo;
  obtenercentrales()->iniciarCursorNodo();
  while (obtenercentrales()->avanzarCursorNodo()) {
    std::cout << "De la central " << obtenercentrales()->obtenerCursorNodo()->obtenerNumero() << " el interno que mas hablo fue:";
    internoQueMasHabloEnUnaCentral(obtenercentrales()->obtenerCursorNodo()->obtenerInternos(),maximaDuracionEnLaCentral,
                                   internoQueMasHabloPorCentral);
    std::cout << internoQueMasHabloPorCentral<<"\n";
    if (maximaDuracionEnLaCentral > maximaDuracionGeneral) {
      centralQueMasHablo = obtenercentrales()->obtenerCursorNodo()->obtenerNumero();
      internoQueMasHabloGeneral = internoQueMasHabloPorCentral;
      maximaDuracionGeneral = maximaDuracionEnLaCentral;
    }
  }
  std::cout << "\n El interno que mas hablo de todos fue el interno " << internoQueMasHabloGeneral << " de la central "
            << centralQueMasHablo-> << ". \n";
}

void Interfaz::internoQueMasHabloEnUnaCentral(Lista<Interno*>* listaInternos,int& maximaDuracionEnLaCentral,
                                              int& internoQueMasHabloPorCentral)
{
  int duracionPorInterno = 0;
  listaInternos->iniciarCursorNodo();
  while (listaInternos->avanzarCursorNodo()) {
    duracionPorInterno = sumaDeDuracionDeLlamadas(listaInternos->obtenerCursorNodo()->obtenerLlamadas());
    if (duracionPorInterno > maximaDuracionEnLaCentral) {
      internoQueMasHabloEnUnaCentral = listaInternos->obtenerCursorNodo()->obtenerNumero();
      maximaDuracionEnLaCentral = duracionPorInterno;
    }
  }
}
int Interfaz::sumaDeDuracionDeLlamadas(Lista<Llamada*>* listaLlamadas)
{
  int duracion = 0;
  listaLlamadas->iniciarCursorNodo();
  while (listaLlamadas->avanzarCursorNodo()) {
    duracion += listaLlamadas->obtenerCursorNodo()->obtenerDuracionLlamadas();
  }
  return duracion;
}

void Interfaz::internoQueMasLlamoPorCentralYEnGeneral()
{
  int maximoNumeroLLamadasEnLaCentral = 0;
  int maximoNumeroLLamdadasGeneral = 0;
  int internoQueMasLlamoPorCentral, internoQueMasLlamoGeneral, centralQueMasLlamo;
  obtenercentrales()->iniciarCursorNodo();
  while (obtenercentrales()->avanzarCursorNodo()) {
    std::cout << "De la central " << obtenercentrales()->obtenerCursorNodo()->obtenerNumero() << " el interno que mas llamo fue:";
    internoQueMasLlamoEnUnaCentral(obtenercentrales()->obtenerCursorNodo()->obtenerInternos(),maximoNumeroLLamadasEnLaCentral,
                                   internoQueMasLlamoPorCentral);
    std::cout << internoQueMasLlamoPorCentral<<"\n";
    if (maximoNumeroLLamadasEnLaCentral > maximoNumeroLLamdadasGeneral) {
      centralQueMasLlamo = obtenercentrales()->obtenerCursorNodo()->obtenerNumero();
      internoQueMasLlamoGeneral = internoQueMasLlamoPorCentral;
      maximoNumeroLLamdadasGeneral = maximoNumeroLLamadasEnLaCentral;
    }
  }
  std::cout << "\n El interno que mas llamo de todos fue el interno " << internoQueMasLlamoGeneral << " de la central "
            << centralQueMasLlamo-> << ". \n";
}

void Interfaz::internoQueMasLlamoEnUnaCentral(Lista<Interno*>* listaInternos,int& maximoNumeroLLamadasEnLaCentral,int& internoQueMasLlamoPorCentral)
{
  int llamadasPorInterno = 0;
  listaInternos->iniciarCursorNodo();
  while (listaInternos->avanzarCursorNodo()) {
    llamadasPorInterno = sumaDeLlamadas(listaInternos->obtenerCursorNodo()->obtenerLlamadas());
    if (llamadasPorInterno > maximoNumeroLLamadasEnLaCentral) {
      internoQueMasLlamoPorCentral = listaInternos->obtenerCursorNodo()->obtenerNumero();
      maximoNumeroLLamadasEnLaCentral = llamadasPorInterno;
    }
  }                                              
}

int Interfaz::sumaDeLlamadas(Lista<Llamada*>* listaLlamadas)
{
  int llamadas = 0;
  listaLlamadas->iniciarCursorNodo();
  while (listaLlamadas->avanzarCursorNodo()) {
    llamadas += listaLlamadas->obtenerCursorNodo()->obtenerCantidadLlamadasHechas();
  }
  return llamadas;
}                                                

void Interfaz::internoQueAlQueMasOcupadosRecibioPorCentralYGeneral()
{
	int maximoNumeroOcupadosEnLaCentral = 0;
  int maximoNumeroDeOcupadosGeneral = 0;
  int internoQueMasRecibioOcupadosPorCentral, internoQueMasRecibioOcupadosGeneral, centralQueMasRecibioOcupados;
  obtenercentrales()->iniciarCursorNodo();
  while (obtenercentrales()->avanzarCursorNodo()) {
    std::cout << "De la central " << obtenercentrales()->obtenerCursorNodo()->obtenerNumero() << " el interno que mas llamo fue:";
    internoQueMasOcupadosRecibioEnUnaCentral(obtenercentrales()->obtenerCursorNodo()->obtenerInternos(),maximoNumeroOcupadosEnLaCentral,
                                   internoQueMasRecibioOcupadosPorCentral);
    std::cout << internoQueMasRecibioOcupadosPorCentral<<"\n";
    if (maximoNumeroOcupadosEnLaCentral > maximoNumeroDeOcupadosGeneral) {
      centralQueMasRecibioOcupados = obtenercentrales()->obtenerCursorNodo()->obtenerNumero();
      internoQueMasRecibioOcupadosGeneral = internoQueMasRecibioOcupadosPorCentral;
      maximoNumeroDeOcupadosGeneral = maximoNumeroOcupadosEnLaCentral;
    }
  }
  std::cout << "\n El interno que mas ocupados recibio de todos fue el interno " << internoQueMasRecibioOcupadosGeneral << " de la central "
            << centralQueMasRecibioOcupados-> << ". \n";
}

void Interfaz:: internoQueMasOcupadosRecibioEnUnaCentral(Lista<Interno*>* listaInternos,int& maximoNumeroOcupadosEnLaCentral,
int& internoQueMasRecibioOcupadosPorCentral)
{
  int ocupadosRecibidosPorInterno = 0;
  listaInternos->iniciarCursorNodo();
  while (listaInternos->avanzarCursorNodo()) {
   ocupadosRecibidosPorInterno = sumaDeOcupadosRecibidos(listaInternos->obtenerCursorNodo()->obtenerLlamadas());
    if (ocupadosRecibidosPorInterno > maximoNumeroOcupadosEnLaCentral) {
      internoQueMasRecibioOcupadosPorCentral = listaInternos->obtenerCursorNodo()->obtenerNumero();
      maximoNumeroOcupadosEnLaCentral = ocupadosRecibidosPorInterno;
    }
  }                                              
}

int Interfaz::sumaDeOcupadosRecibidos(Lista<Llamada*>* listaLlamadas)
{
  int ocupadosRecibidos = 0;
  listaLlamadas->iniciarCursorNodo();
  while (listaLlamadas->avanzarCursorNodo()) {
    ocupadosRecibidos += listaLlamadas->obtenerCursorNodo()->obtenerCantidadOcupadosRecibidos();
  }
  return ocupadosRecibidos;
}                    
void Interfaz::internoAlQueMasLlamaronPorCentralYGeneral()
{
	int maximoLlamadasRecibidasEnLaCentral = 0;
  int maximoNumeroLlamadasRecibidasGeneral = 0;
  int internoQueMasLlamaronPorCentral, internoQueMasLlamaronGeneral, centralQueMasLlamadasRecibio;
  obtenercentrales()->iniciarCursorNodo();
  while (obtenercentrales()->avanzarCursorNodo()) {
    std::cout << "De la central " << obtenercentrales()->obtenerCursorNodo()->obtenerNumero() << " el interno que mas llamo fue:";
    internoQueMasLlamadasRecibioEnUnaCentral(obtenercentrales()->obtenerCursorNodo()->obtenerInternos(),maximoLlamadasRecibidasEnLaCentral,
                                    internoQueMasLlamaronPorCentral);
    std::cout <<  internoQueMasLlamaronPorCentral<<"\n";
    if (maximoLlamadasRecibidasEnLaCentral > maximoNumeroLlamadasRecibidasGeneral) {
     centralQueMasLlamadasRecibio = obtenercentrales()->obtenerCursorNodo()->obtenerNumero();
      internoQueMasLlamaronGeneral =  internoQueMasLlamaronPorCentral;
      maximoNumeroLlamadasRecibidasGeneral = maximoLlamadasRecibidasEnLaCentral;
    }
  }
  std::cout << "\n El interno que mas llamadas recibio de todos fue el interno " << internoQueMasLlamaronGeneral << " de la central "
            << centralQueMasLlamadasRecibio-> << ". \n";
}
void Interfaz::  internoQueMasLlamadasRecibioEnUnaCentral(Lista<Interno*>* listaInternos,int& maximoLlamadasRecibidasEnLaCentral,
int& internoQueMasLlamaronPorCentral)
{
	int llamadasRecibidasPorInterno = 0;
  listaInternos->iniciarCursorNodo();
  while (listaInternos->avanzarCursorNodo()) {
    llamadasRecibidasPorInterno = sumaDeLlamadasRecibidas(listaInternos->obtenerCursorNodo()->obtenerLlamadas());
    if ( llamadasRecibidasPorInterno > maximoLlamadasRecibidasEnLaCentral) {
      internoQueMasLlamaronPorCentral = listaInternos->obtenerCursorNodo()->obtenerNumero();
      maximoLlamadasRecibidasEnLaCentral = llamadasRecibidasPorInterno;
    }
  }                    
}

int Interfaz::sumaDeLlamadasRecibidas(Lista<Llamada*>* listaLlamadas)
{
  int llamadasRecibidas = 0;
  listaLlamadas->iniciarCursorNodo();
  while (listaLlamadas->avanzarCursorNodo()) {
    llamadasRecibidas += listaLlamadas->obtenerCursorNodo()->obtenerCantidadLlamadasRecibidas();
  }
  return llamadasRecibidas;
}     

void Interfaz::internoQueMasGastoPorCentralYGeneral()
{
	int  = 0;
  int maximoGastoGeneral = 0;
  int internoQueMasGastoPorCentral, internoQueMasGastoGeneral, centralQueMasGasto;
  obtenercentrales()->iniciarCursorNodo();
  while (obtenercentrales()->avanzarCursorNodo()) {
    std::cout << "De la central " << obtenercentrales()->obtenerCursorNodo()->obtenerNumero() << " el interno que mas llamo fue:";
    internoQueMasGastoEnUnaCentral(obtenercentrales()->obtenerCursorNodo()->obtenerInternos(),maximoGastoEnLaCentral,
                                    internoQueMasGastoPorCentral);
    std::cout <<  internoQueMasGastoPorCentral<<"\n";
    if (maximoGastoEnLaCentral > maximoGastoGeneral) {
     centralQueMasGasto = obtenercentrales()->obtenerCursorNodo()->obtenerNumero();
      internoQueMasGastoGeneral =  internoQueMasGastoPorCentral;
      maximoGastoGeneral = maximoGastoEnLaCentral;
    }
  }
  std::cout << "\n El interno que mas llamadas recibio de todos fue el interno " << internoQueMasGastoGeneral << " de la central "
            << centralQueMasGasto-> << ". \n";
}

void Interfaz::  internoQueMasGastoEnUnaCentral(Lista<Interno*>* listaInternos,int& maximoGastoEnLaCentral,
int& internoQueMasGastoPorCentral)
{
	int GastosPorInterno = 0;
  listaInternos->iniciarCursorNodo();
  while (listaInternos->avanzarCursorNodo()) {
    GastosPorInterno = sumaDeGastos(listaInternos->obtenerCursorNodo()->obtenerLlamadas());
    if ( GastosPorInterno > maximoGastoEnLaCentral) {
      internoQueMasGastoPorCentral = listaInternos->obtenerCursorNodo()->obtenerNumero();
      maximoGastoEnLaCentral = GastosPorInterno;
    }
  }                    
}
int Interfaz::sumaDeGastos(Lista<Llamada*>* listaLlamadas)
{
  int gastos = 0;
  listaLlamadas->iniciarCursorNodo();
  while (listaLlamadas->avanzarCursorNodo()) {
    gastos += listaLlamadas->obtenerCursorNodo()->obtenerCantidadLlamadasRecibidas();
  }
  return gastos;
}     
void Interfaz::tratarOpcion(int opcion)
{
  bool continuar = true;
  while (continuar) {
    std::cin >> opcion;
    switch (opcion) {
    case 1:
      mostrarDetallesDeInternos();
      realizarOtraConsulta(opcion, continuar);
      break;

    case 2:
      mostrarDetallesDeCentrales();
      realizarOtraConsulta(opcion, continuar);
      break;

    case 3:
      mostrarDetallesDeEnlaces();
      realizarOtraConsulta(opcion, continuar);
      break;

    case 4:
      detallesLlamadasEntreInternoXeInternoY();
      realizarOtraConsulta(opcion, continuar);
      break;

    case 5:
      internoQueMasHabloPorCentralYGeneral();
      realizarOtraConsulta(opcion, continuar);
      break;

    case 6:
			internoQueMasLlamoPorCentralYEnGeneral();
      realizarOtraConsulta(opcion, continuar);
      break;

    case 7:
			internoQueQueMasOcupadosRecibioPorCentralYGeneral();
      realizarOtraConsulta(opcion, continuar);
      break;

    case 8:
			internoAlQueMasLlamaronPorCentralYGeneral();
      realizarOtraConsulta(opcion, continuar);
      break;

    case 9:
			internoQueMasGastoPorCentralYGeneral();
      realizarOtraConsulta(opcion, continuar);
      break;

    case 10:
      realizarOtraConsulta(opcion, continuar);
      break;

    case 11:
      realizarOtraConsulta(opcion, continuar);
      break;

    case 12:
      realizarOtraConsulta(opcion, continuar);
      break;

    case 13:
      realizarOtraConsulta(opcion, continuar);
      break;

    case 14:
      realizarOtraConsulta(opcion, continuar);
      break;

    case 15:
      realizarOtraConsulta(opcion, continuar);
      break;

    case 16:
      realizarOtraConsulta(opcion, continuar);
      break;

    case 17:
      continuar = false;
      std::cout << endl;
      std::cout << "Hasta luego. \n";
      break;
    }
  }
}
void Interfaz::realizarOtraConsulta(int& opcion, bool& continuar)
{
  std::cout << "Desea realizar otra consulta? s/n:";
  char respuesta;
  std::cin >> respuesta;
  if (respuesta == 's') {
    continuar = true;
    std::cout << endl;
    mostrarMenu();
    opcion = pedirOpcionMenu();
  } else {
    continuar = false;
    std::cout << endl;
    std::cout << "Hasta luego.\n \n";
  }
}
void Interfaz::iniciarPrograma()
{
  LectorArchivos* lectorDeArchivos = new LectorArchivos(pedirRuta());
  this->cambiarPunteroALectorDeArchivos(lectorDeArchivos);
  
  std::string variableDeBusqueda = pedirAlgoritmoDeBusqueda();
  mostrarMenu();
  int opcion = pedirOpcionMenu();
  TratarOpcion(opcion);
}

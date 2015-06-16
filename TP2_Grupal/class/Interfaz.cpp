#include "Interfaz.h"
#include <cstdlib>
Interfaz::Interfaz()
{
	this->enlaces = NULL;
	this->centrales = NULL;
	this->lectorDeArchivos = NULL;
	this->procesadorLlamada = NULL;
}

void Interfaz::cambiarPunteroALectorDeArchivos(LectorArchivos* nuevoPuntero)
{
	this->lectorDeArchivos = nuevoPuntero;
}

std::string Interfaz::pedirRuta()
{
	std::string ruta;
	std::cout << "\n"
	          << "Ingrese la ruta del archivo de llamadas:";
	std::cin >> ruta;
	return ruta;
}

void Interfaz::mostrarMenu()
{
	std::cout << "1)Imprimir detalle de numeros de los internos.\n";
	std::cout << "2)Imprimir detalle de centrales con su numeración.\n";
	std::cout << "3)Imprimir detalle de enlaces (origen, destino, canales). \n";
	std::cout << "4)Detalle de llamadas entre el interno 'X' de la central 'A' al interno 'Y' de la central 'B'.\n";
	std::cout << "5)Interno que mas hablo de todos y de cada central.\n";
	std::cout << "6)Interno que más llamó de todos y de cada central.\n";
	std::cout << "7)Interno que mas ocupados recibio de todos y de cada central.\n";
	std::cout << "8)Interno al que más llamaron de todos y de cada central.\n";
	std::cout << "9)Interno que mas gasto de todos y de cada central.\n";
	std::cout << "10)Interno al que más le hablaron de todos y de cada central.\n";
	std::cout << "11)Interno que más dio ocupado de todos y de cada central.\n";
	std::cout << "12)Detalle de llamadas emitidas por el interno X de la central A.\n";
	std::cout << "13)Detalle de llamadas recibidas por el interno X de la central A.\n";
	std::cout << "14)Detalle de llamadas realizadas de X de la central A a Y de la Central B.\n";
	std::cout << "15)Detalle de llamadas recibidas por X de la Central A y realizadas por Y de la Central B.\n";
	std::cout << "16)Imprimir cantidad de llamadas anuladas por falta de enlaces por central,ordenado por cantidad "
	          "descendiente.\n";
	std::cout << "17)Salir. \n \n";
}

int Interfaz::pedirOpcionMenu()
{
	int opcion;
	do {
		std::cout << "Elija una opcion:";
		std::cin >> opcion;
		std::cout << "\n \n";
	} while (opcion < 1 || opcion > 17);

	return opcion;
}

int Interfaz::pedirInterno()
{
	int numeroInterno;
	do {
		std::cout << "Ingrese el numero de interno:";
		std::cin >> numeroInterno;
	} while (numeroInterno < 0 || numeroInterno > 9999);

	return numeroInterno;

}
std::string Interfaz::pedirAlgoritmoDeBusqueda()
{
	int opcion;
	std::string opcionAlgoritmo;
	std::cout << "Quiere usar algoritmo de: \n";
	std::cout << "1) Precio mas bajo \n";
	std::cout << "2) Distancia mas corta \n";
	std::cout << "Opcion:";
	std::cin >> opcion;

	switch (opcion) {
	case 1:
		opcionAlgoritmo = "Precio";
		break;

	case 2:
		opcionAlgoritmo = "Distancia";
		break;
	}
	std::cout << "\n";
	return opcionAlgoritmo;
}

Lista<Enlace*>* Interfaz::obtenerenlaces()
{
	return this->enlaces;
}
Lista<Central*>* Interfaz::obtenercentrales()
{
	return this->centrales;
}
void Interfaz::iniciarlizarPunteroAEnlaces(ProcesadorLlamada* procesadorDeLlamadas)
{
	this->enlaces = procesadorDeLlamadas->obtenerEnlaces();
}
void Interfaz::iniciarlizarPunteroACentrales(ProcesadorLlamada* procesadorDeLlamadas)
{
	this->centrales = procesadorDeLlamadas->obtenerCentrales();
}

void Interfaz::mostrarDetallesDeInternos()
{
	this->obtenercentrales()->iniciarCursorNodo();

	while (this->obtenercentrales()->avanzarCursorNodo()) {
		std::cout << "Internos de la central:" << this->obtenercentrales()->obtenerCursorNodo()->obtenerNumero() << ": \n";
		Lista<Interno*>* punteroAInternos = this->obtenercentrales()->obtenerCursorNodo()->obtenerInternos();
		punteroAInternos->iniciarCursorNodo();

		while (punteroAInternos->avanzarCursorNodo()) {
			std::cout << "Interno:" << punteroAInternos->obtenerCursorNodo()->obtenerNumero() << ". \n";
		}
		std::cout << "\n";
	}
}

void Interfaz::mostrarDetallesDeCentrales()
{
	std::cout << "A continuacion se indican los numeros de las centrales existentes: \n \n";
	this->obtenercentrales()->iniciarCursorNodo();

	while (this->obtenercentrales()->avanzarCursorNodo()) {
		std::cout << "\nCentral numero:" << this->obtenercentrales()->obtenerCursorNodo()->obtenerNumero() << "\n";
		std::cout << "Conectada con las siguiente/s central/es: \n";
		Lista<Enlace*>* enlacesCentral = obtenercentrales()->obtenerCursorNodo()->obtenerEnlaces();
		enlacesCentral->iniciarCursorNodo();
		while (enlacesCentral->avanzarCursorNodo()) {
			if (enlacesCentral->obtenerCursorNodo()->obtenerDestino()->obtenerNumero() != obtenercentrales()->obtenerCursorNodo()->obtenerNumero()) {
				std::cout<<"- "<<enlacesCentral->obtenerCursorNodo()->obtenerDestino()->obtenerNumero() << "\n";
			} else {
				std::cout<<"- "<<enlacesCentral->obtenerCursorNodo()->obtenerOrigen()->obtenerNumero() << "\n";
			}

		}
	}
	std::cout << "\n";
}

void Interfaz::mostrarDetallesDeEnlaces()
{
	std::cout << "A continuacion se indican los dettalles de los enlaces existentes: \n \n";
	this->obtenerenlaces()->iniciarCursorNodo();
	int i = 0;

	while (this->obtenerenlaces()->avanzarCursorNodo()) {
		i++;
		std::cout << "Enlace " << i << ": \n";
		std::cout << "Central origen: " << obtenerenlaces()->obtenerCursorNodo()->obtenerOrigen()->obtenerNumero() << "\n";
		std::cout << "Central destino: " << obtenerenlaces()->obtenerCursorNodo()->obtenerDestino()->obtenerNumero()
		          << "\n";
		std::cout << "Numero de canales: " << obtenerenlaces()->obtenerCursorNodo()->obtenerNumeroDeCanales() << "\n";
		std::cout << "Distancia que recorre: " << obtenerenlaces()->obtenerCursorNodo()->obtenerDistancia() << " kilometros. \n";
		std::cout << "Precio por minuto: " << obtenerenlaces()->obtenerCursorNodo()->obtenerPrecio() << " centavos. \n \n";
	}
}

int Interfaz::pedirCentral()
{
	int numeroDeCentral;
	do {
		std::cout << "Ingrese el numero de central:";
		std::cin >> numeroDeCentral;
	} while (numeroDeCentral < 0 || numeroDeCentral > 9999);
	return numeroDeCentral;
}


void Interfaz::detallesLlamadasEntreInternoXDeLaCentralAYElInternoYDeLaCentralB()
{
	int primerInterno, centralPrimerInterno, segundoInterno, centralSegundoInterno;
	do {
		std::cout << "Ingrese el numero del primer interno:";
		std::cin >> primerInterno;
	} while (primerInterno < 0 || primerInterno > 9999);
	centralPrimerInterno = pedirCentral();
	std::cout << "\n";

	do {
		std::cout << "Ingrese el numero del segundo interno:";
		std::cin >> segundoInterno;
	} while (segundoInterno < 0 || segundoInterno > 9999);
	centralSegundoInterno = pedirCentral();
	std::cout << "\n \n";

	Interno* DatosPrimerInterno = NULL;
	DatosPrimerInterno =
	  obtenercentrales()->obtenerPunteroAlObjeto(centralPrimerInterno)->obtenerObjeto()->obtenerInterno(primerInterno);

	std::cout << "Detalles de llamadas entre el interno " << primerInterno << " de la central " << centralPrimerInterno;
	std::cout << " y " << segundoInterno << " de la central " << centralSegundoInterno << "\n";

	int numeroDeLlamadas = 0;
	int numeroDeOcupados = 0;
	int duracionDeLlamadas = 0;
	bool encontro = false;
	DatosPrimerInterno->obtenerLlamadas()->iniciarCursorNodo();

	while (DatosPrimerInterno->obtenerLlamadas()->avanzarCursorNodo() && !encontro) {

		if (DatosPrimerInterno->obtenerLlamadas()->obtenerCursorNodo()->obtenerReceptorLlamada() == segundoInterno) {
			encontro = true;
			numeroDeLlamadas = DatosPrimerInterno->obtenerLlamadas()->obtenerCursorNodo()->obtenerCantidadLlamadasHechas() +
			                   DatosPrimerInterno->obtenerLlamadas()->obtenerCursorNodo()->obtenerCantidadLlamadasRecibidas();
			numeroDeOcupados = DatosPrimerInterno->obtenerLlamadas()->obtenerCursorNodo()->obtenerCantidadOcupadosDados() +
			                   DatosPrimerInterno->obtenerLlamadas()->obtenerCursorNodo()->obtenerCantidadOcupadosRecibidos();
			duracionDeLlamadas =
			  DatosPrimerInterno->obtenerLlamadas()->obtenerCursorNodo()->obtenerDuracionLlamadasHechas() +
			  DatosPrimerInterno->obtenerLlamadas()->obtenerCursorNodo()->obtenerDuracionLlamadasRecibidas();
		}
	}
	std::cout << "Llamadas realizadas entre ambos:" << numeroDeLlamadas << "\n";
	std::cout << "Duracion total de llamadas entre ambos:" << duracionDeLlamadas << " minutos.\n";
	std::cout << "Cantidad de ocupados entre ambos:" << numeroDeOcupados << "\n \n";
}


void Interfaz::internoQueMasHabloPorCentralYGeneral()
{
	std::cout << "\n";
	int maximaDuracionGeneral = 0;
	int internoQueMasHabloPorCentral;
	int internoQueMasHabloGeneral = 0;
	int centralQueMasHablo = 0;

	obtenercentrales()->iniciarCursorNodo();

	while (obtenercentrales()->avanzarCursorNodo()) {
		int maximaDuracionEnLaCentral = 0;
		internoQueMasHabloPorCentral = 0;

		std::cout << "De la central " << obtenercentrales()->obtenerCursorNodo()->obtenerNumero();
		Central* centralActual = obtenercentrales()->obtenerCursorNodo();
		centralActual->internoQueMasHabloEnLaCentral(centralActual->obtenerInternos(),
																								maximaDuracionEnLaCentral,internoQueMasHabloPorCentral);

		if(internoQueMasHabloPorCentral == 0) {
			std::cout << " ningun interno hablo.\n";
		} else {
			std::cout << " el interno que mas hablo fue:" << internoQueMasHabloPorCentral << ". Hablo " << maximaDuracionEnLaCentral << " minutos.\n";

			if (maximaDuracionEnLaCentral > maximaDuracionGeneral) {
				centralQueMasHablo = obtenercentrales()->obtenerCursorNodo()->obtenerNumero();
				internoQueMasHabloGeneral = internoQueMasHabloPorCentral;
				maximaDuracionGeneral = maximaDuracionEnLaCentral;
			}
		}
	}
	if (maximaDuracionGeneral==0) {
		std::cout<<"Ningun interno hablo en las centrales. \n\n";
	} else {
		std::cout << "\nEl interno que mas hablo de todos fue el interno " << internoQueMasHabloGeneral << " de la central "
		          << centralQueMasHablo << ". Hablo " << maximaDuracionGeneral << " minutos. \n\n";
	}
}

void Interfaz::internoQueMasLlamoPorCentralYEnGeneral()
{
	std::cout << "\n";
	int maximoNumeroLLamdadasGeneral = 0;
	int internoQueMasLlamoPorCentral;
	int internoQueMasLlamoGeneral = 0;
	int centralQueMasLlamo = 0;
	obtenercentrales()->iniciarCursorNodo();

	while (obtenercentrales()->avanzarCursorNodo()) {
		int maximoNumeroLLamadasEnLaCentral = 0;
		internoQueMasLlamoPorCentral = 0;
		std::cout << "De la central " << obtenercentrales()->obtenerCursorNodo()->obtenerNumero();

		Central* centralActual = obtenercentrales()->obtenerCursorNodo();
		centralActual->internoQueMasLlamoEnLaCentral(centralActual->obtenerInternos(),
		                               maximoNumeroLLamadasEnLaCentral,
		                               internoQueMasLlamoPorCentral);
		if(internoQueMasLlamoPorCentral == 0) {
			std::cout << " ningun interno llamo.\n";
		} else {
			std::cout << " el interno que mas llamo fue:"<< internoQueMasLlamoPorCentral << ". Llamo "
			          << maximoNumeroLLamadasEnLaCentral << " veces.\n";

			if (maximoNumeroLLamadasEnLaCentral > maximoNumeroLLamdadasGeneral) {
				centralQueMasLlamo = obtenercentrales()->obtenerCursorNodo()->obtenerNumero();
				internoQueMasLlamoGeneral = internoQueMasLlamoPorCentral;
				maximoNumeroLLamdadasGeneral = maximoNumeroLLamadasEnLaCentral;
			}
		}
	}
	if (maximoNumeroLLamdadasGeneral==0) {
		std::cout<<"Ningun interno realizo llamadas en las centrales. \n\n";
	} else {
		std::cout << "\nEl interno que mas llamo de todos fue el interno " << internoQueMasLlamoGeneral << " de la central "
		          << centralQueMasLlamo << "\n";
	}
}


void Interfaz::internoQueMasOcupadosRecibioPorCentralYGeneral()
{
	std::cout << "\n";
	int maximoNumeroDeOcupadosGeneral = 0;
	int internoQueMasRecibioOcupadosPorCentral;
	int internoQueMasRecibioOcupadosGeneral = 0;
	int centralQueMasRecibioOcupados = 0;
	obtenercentrales()->iniciarCursorNodo();

	while (obtenercentrales()->avanzarCursorNodo()) {
		int maximoNumeroOcupadosEnLaCentral = 0;
		internoQueMasRecibioOcupadosPorCentral = 0;
		std::cout << "De la central " << obtenercentrales()->obtenerCursorNodo()->obtenerNumero();
		Central* centralActual = obtenercentrales()->obtenerCursorNodo();

		centralActual->internoQueMasOcupadosRecibioEnLaCentral(centralActual->obtenerInternos(),
		    maximoNumeroOcupadosEnLaCentral,
		    internoQueMasRecibioOcupadosPorCentral);
		if (maximoNumeroOcupadosEnLaCentral==0) {
			std::cout<<" ningun interno recibio ocupados.\n";
		} else {
			std::cout <<" el interno que mas ocupados recibio fue:" << internoQueMasRecibioOcupadosPorCentral << ". Recibio " << maximoNumeroOcupadosEnLaCentral
			          << " ocupado/s.\n";

			if (maximoNumeroOcupadosEnLaCentral >= maximoNumeroDeOcupadosGeneral) {
				centralQueMasRecibioOcupados = obtenercentrales()->obtenerCursorNodo()->obtenerNumero();
				internoQueMasRecibioOcupadosGeneral = internoQueMasRecibioOcupadosPorCentral;
				maximoNumeroDeOcupadosGeneral = maximoNumeroOcupadosEnLaCentral;
			}
		}
	}
	if (maximoNumeroDeOcupadosGeneral==0) {
		std::cout<<"Ningun interno recibio ocupados en las centrales. \n\n";
	} else {
		std::cout << "\nEl interno que mas ocupados recibio de todos fue el interno " << internoQueMasRecibioOcupadosGeneral
		          << " de la central " << centralQueMasRecibioOcupados << ". Recibio " << maximoNumeroDeOcupadosGeneral
		          << " ocupado/s. \n\n";
	}
}


void Interfaz::internoAlQueMasLlamaronPorCentralYGeneral()
{
	std::cout << "\n";
	int maximoNumeroLlamadasRecibidasGeneral = 0;
	int internoQueMasLlamaronPorCentral;
	int internoQueMasLlamaronGeneral = 0;
	int centralQueMasLlamadasRecibio = 0;
	obtenercentrales()->iniciarCursorNodo();

	while (obtenercentrales()->avanzarCursorNodo()) {
		int maximoLlamadasRecibidasEnLaCentral = 0;
		internoQueMasLlamaronPorCentral = 0;

		std::cout << "De la central " << obtenercentrales()->obtenerCursorNodo()->obtenerNumero();
		Central* centralActual = obtenercentrales()->obtenerCursorNodo();

		centralActual->internoQueMasLlamadasRecibioEnLaCentral(centralActual->obtenerInternos(),
		    maximoLlamadasRecibidasEnLaCentral,
		    internoQueMasLlamaronPorCentral);
		if (maximoLlamadasRecibidasEnLaCentral==0) {
			std::cout<<" ningun interno recibio llamadas.\n";
		} else {
			std::cout << " el interno al que mas llamaron fue:" << internoQueMasLlamaronPorCentral << ". Recibio " << maximoLlamadasRecibidasEnLaCentral
			          << " llamada/s.\n";

			if (maximoLlamadasRecibidasEnLaCentral > maximoNumeroLlamadasRecibidasGeneral) {
				centralQueMasLlamadasRecibio = obtenercentrales()->obtenerCursorNodo()->obtenerNumero();
				internoQueMasLlamaronGeneral = internoQueMasLlamaronPorCentral;
				maximoNumeroLlamadasRecibidasGeneral = maximoLlamadasRecibidasEnLaCentral;
			}
		}
	}
	if (maximoNumeroLlamadasRecibidasGeneral==0) {
		std::cout<<"Ningun interno recibio llamadas en las centrales. \n\n";
	} else {
		std::cout << "\n El interno que mas llamadas recibio de todos fue el interno " << internoQueMasLlamaronGeneral
		          << " de la central " << centralQueMasLlamadasRecibio << ". Recibio " << maximoNumeroLlamadasRecibidasGeneral
		          << " llamada/s. \n\n";
	}
}


void Interfaz::internoQueMasGastoPorCentralYGeneral()
{
	std::cout << "\n";
	int maximoGastoGeneral = 0;
	int internoQueMasGastoPorCentral;
	int internoQueMasGastoGeneral = 0;
	int centralQueMasGasto = 0;
	obtenercentrales()->iniciarCursorNodo();

	while (obtenercentrales()->avanzarCursorNodo()) {
		int maximoGastoEnLaCentral = 0;
		internoQueMasGastoPorCentral = 0;

		std::cout << "De la central " << obtenercentrales()->obtenerCursorNodo()->obtenerNumero();
		Central* centralActual = obtenercentrales()->obtenerCursorNodo();
		centralActual->internoQueMasGastoEnLaCentral(centralActual->obtenerInternos(),maximoGastoEnLaCentral, internoQueMasGastoPorCentral);
		if (maximoGastoEnLaCentral==0) {
			std::cout<<" ningun interno gasto dinero.\n";
		} else {
			std::cout << " el interno que mas gasto fue:" << internoQueMasGastoPorCentral << ". Gasto " << maximoGastoEnLaCentral << " centavo/s.\n";

			if (maximoGastoEnLaCentral >= maximoGastoGeneral) {
				centralQueMasGasto = obtenercentrales()->obtenerCursorNodo()->obtenerNumero();
				internoQueMasGastoGeneral = internoQueMasGastoPorCentral;
				maximoGastoGeneral = maximoGastoEnLaCentral;
			}
		}
	}
	if (maximoGastoGeneral==0) {
		std::cout<<"No hubo gastos en las centrales. \n\n";
	} else {
		std::cout << "\nEl interno que mas gasto en llamadas de todos fue el interno " << internoQueMasGastoGeneral
		          << " de la central " << centralQueMasGasto << ". Gasto " << maximoGastoGeneral << " centavo/s. \n\n";
	}
}

void Interfaz::internoAlQueMasLeHablaronPorCentralYGeneral()
{
	std::cout << "\n";
	int maximoInternoQueMasLeHablaronEnGeneral = 0;
	int internoQueMasHablaronPorCentral;
	int internoQueMasHablaronGeneral = 0;
	int centralQueMasHablaron = 0;
	obtenercentrales()->iniciarCursorNodo();

	while (obtenercentrales()->avanzarCursorNodo()) {
		int maximoInternoQueMasLeHablaronEnLaCentral = 0;
		internoQueMasHablaronPorCentral = 0;
		std::cout << "De la central " << obtenercentrales()->obtenerCursorNodo()->obtenerNumero();
		Central* centralActual = 	obtenercentrales()->obtenerCursorNodo();
		centralActual->internoQueMasLeHablaronEnLaCentral(centralActual->obtenerInternos(),maximoInternoQueMasLeHablaronEnLaCentral,
																											internoQueMasHablaronPorCentral);
		if (internoQueMasHablaronPorCentral==0) {
			std::cout<<" ningun interno recibio llamadas. \n";
		} else {
			std::cout << " el interno que mas llamo fue:" << internoQueMasHablaronPorCentral << ". Le hablaro " << maximoInternoQueMasLeHablaronEnLaCentral
			          << " minuto/s.\n";

			if (maximoInternoQueMasLeHablaronEnLaCentral > maximoInternoQueMasLeHablaronEnGeneral) {
				centralQueMasHablaron = obtenercentrales()->obtenerCursorNodo()->obtenerNumero();
				internoQueMasHablaronGeneral = internoQueMasHablaronPorCentral;
				maximoInternoQueMasLeHablaronEnGeneral = maximoInternoQueMasLeHablaronEnLaCentral;
			}
		}
	}
	if (maximoInternoQueMasLeHablaronEnGeneral==0) {
		std::cout<<"No le hablaron a ningun interno en las centrales. \n\n";
	} else {
		std::cout << "\n El interno que mas le hablaron de todos fue el interno " << internoQueMasHablaronGeneral
		          << " de la central " << centralQueMasHablaron << ". Le hablaron " << maximoInternoQueMasLeHablaronEnGeneral
		          << " minuto/s. \n\n";
	}
}

void Interfaz::internoQueMasDioOcupadoPorCentralYGeneral()
{
	std::cout << "\n";
	int maximoNumeroDeOcupadosDadosEnGeneral = 0;
	int internoQueMasDioOcupadoPorCentral;
	int internoQueMasDioOcupadoEnGeneral = 0;
	int centralQueMasDioOcuapdo = 0;
	obtenercentrales()->iniciarCursorNodo();

	while (obtenercentrales()->avanzarCursorNodo()) {
		int maximoNumeroDeOcupadosDadosEnLaCentral = 0;
		internoQueMasDioOcupadoPorCentral = 0;

		std::cout << "De la central " << obtenercentrales()->obtenerCursorNodo()->obtenerNumero();
		Central* centralActual = obtenercentrales()->obtenerCursorNodo();
		centralActual->internoQueMasDioOcuapadoEnLaCentral(centralActual->obtenerInternos(),maximoNumeroDeOcupadosDadosEnLaCentral,
																											internoQueMasDioOcupadoPorCentral);
		if (maximoNumeroDeOcupadosDadosEnLaCentral==0) {
			std::cout<<" ningun interno dio ocupados. \n";
		} else {
			std::cout  << " el interno que mas ocupados dio fue:" << internoQueMasDioOcupadoPorCentral << ". Dio " << maximoNumeroDeOcupadosDadosEnLaCentral
			           << " ocupado/s. \n";

			if (maximoNumeroDeOcupadosDadosEnLaCentral >= maximoNumeroDeOcupadosDadosEnGeneral) {
				centralQueMasDioOcuapdo = obtenercentrales()->obtenerCursorNodo()->obtenerNumero();
				internoQueMasDioOcupadoEnGeneral = internoQueMasDioOcupadoPorCentral;
				maximoNumeroDeOcupadosDadosEnGeneral = maximoNumeroDeOcupadosDadosEnLaCentral;
			}
		}
	}
	if (maximoNumeroDeOcupadosDadosEnGeneral==0) {
		std::cout<<"Ningun interno dio ocupados en las centrales. \n\n";
	} else {
		std::cout << "\nEl interno que mas dio ocupados de todos fue el interno " << internoQueMasDioOcupadoEnGeneral
		          << " de la central " << centralQueMasDioOcuapdo << ". Dio " << maximoNumeroDeOcupadosDadosEnGeneral
		          << " ocupado/s. \n\n";
	}
}

void Interfaz::DetallesLlamadasEmitidasPorElInternoXDeLaCentralA()
{
	std::cout << "\n";
	int interno = pedirInterno();
	int central = pedirCentral();
	bool emitioLlamadas = false;
	Interno* internoPedido =
	  obtenercentrales()->obtenerPunteroAlObjeto(central)->obtenerObjeto()->obtenerInterno(interno);

	std::cout << "\nDetalle de las llamadas emitidas por el interno " << interno << " de la central " << central
	          << ".\n\n";
	internoPedido->obtenerLlamadas()->iniciarCursorNodo();

	while (internoPedido->obtenerLlamadas()->avanzarCursorNodo()) {

		// me fijo si por lo menos realizo una llamada. Porque el nodo en la llamada puede estar creado solo con datos de
		// llamadas recibidas.
		if (internoPedido->obtenerLlamadas()->obtenerCursorNodo()->obtenerCantidadLlamadasHechas() > 0) {
			emitioLlamadas = true;
			std::cout << "Llamadas realizadas al interno "
			          << internoPedido->obtenerLlamadas()->obtenerCursorNodo()->obtenerReceptorLlamada() <<
			          " de la central "<< internoPedido->obtenerLlamadas()->obtenerCursorNodo()->obtenerOtraCentral() << ".\n";
			std::cout << "Cantidad de llamadas: "
			          << internoPedido->obtenerLlamadas()->obtenerCursorNodo()->obtenerCantidadLlamadasHechas() << ".\n";
			std::cout << "Duracion de las llamadas:"
			          << internoPedido->obtenerLlamadas()->obtenerCursorNodo()->obtenerDuracionLlamadasHechas() << ".\n";
			std::cout << "Cantidad de ocupados recibidos:"
			          << internoPedido->obtenerLlamadas()->obtenerCursorNodo()->obtenerCantidadOcupadosRecibidos() << ".\n\n";
		}
	}
	if (!emitioLlamadas) {
		std::cout << "Este interno no realizo llamadas.\n \n";
	}
}

void Interfaz::DetallesLlamadasRecibidasPorElInternoXDeLaCentralA()
{
	int interno = pedirInterno();
	int central = pedirCentral();
	std::cout<<"\n";
	bool recibioLlamadas = false;
	Interno* internoPedido =
	  obtenercentrales()->obtenerPunteroAlObjeto(central)->obtenerObjeto()->obtenerInterno(interno);

	std::cout << "Detalle de las llamadas recibidas por el interno " << interno << " de la central " << central << ".\n \n";
	internoPedido->obtenerLlamadas()->iniciarCursorNodo();

	while (internoPedido->obtenerLlamadas()->avanzarCursorNodo()) {
		// me fijo si por lo menos recibio una llamada. Porque el nodo en la llamada puede estar creado solo con datos de
		// llamadas realizadas.
		if (internoPedido->obtenerLlamadas()->obtenerCursorNodo()->obtenerCantidadLlamadasRecibidas() > 0) {
			recibioLlamadas = true;
			std::cout << "Llamadas recibidas del interno "
			          << internoPedido->obtenerLlamadas()->obtenerCursorNodo()->obtenerReceptorLlamada() <<
			          " de la central "<<internoPedido->obtenerLlamadas()->obtenerCursorNodo()->obtenerOtraCentral() << ".\n";
			std::cout << "Cantidad de llamadas: "
			          << internoPedido->obtenerLlamadas()->obtenerCursorNodo()->obtenerCantidadLlamadasRecibidas() << ".\n";
			std::cout << "Duracion de las llamadas:"
			          << internoPedido->obtenerLlamadas()->obtenerCursorNodo()->obtenerDuracionLlamadasRecibidas() << ".\n";
			std::cout << "Cantidad de ocupados dados:"
			          << internoPedido->obtenerLlamadas()->obtenerCursorNodo()->obtenerCantidadOcupadosDados() << ".\n";
			std::cout << "\n";
		}
	}
	if (!recibioLlamadas) {
		std::cout << "Este interno no recibio llamadas.\n";
	}
	std::cout<<"\n";
}

void Interfaz::DetalleDeLlamadasRealizadasPorXDeLaCentralAYRecibidasPorYDeLaCentralB()
{
	std::cout << "Emisor. \n";
	int emisor = pedirInterno();
	std::cout << "Central del emisor.\n";
	int numeroCentralEmisor = pedirCentral();
	std::cout << "\n";

	std::cout << "Receptor. \n";
	int receptor = pedirInterno();
	std::cout << "Central del receptor.\n";
	int numeroCentralReceptor = pedirCentral();
	std::cout << "\n";

	std::cout << "Detalles de llamadas realizadas por " << emisor << " de la central " << numeroCentralEmisor;
	std::cout << " y recibidas por " << receptor << " de la central " << numeroCentralReceptor << ".\n";

	Central* centralEmisor = obtenercentrales()->obtenerPunteroAlObjeto(numeroCentralEmisor)->obtenerObjeto();
	Lista<Llamada*>* llamadasEmisor = centralEmisor->obtenerInterno(emisor)->obtenerLlamadas();
	llamadasEmisor->iniciarCursorNodo();
	bool estaElReceptor = false;

	while (!estaElReceptor && llamadasEmisor->avanzarCursorNodo()) {

		if (llamadasEmisor->obtenerCursorNodo()->obtenerReceptorLlamada() == receptor) {
			estaElReceptor = true;
		}
	}
	// me aseguro de que, ademas de que exista un nodo con los datos de receptor, tenga datos de llamadas realizadas a el.
	if (estaElReceptor && (llamadasEmisor->obtenerCursorNodo()->obtenerCantidadLlamadasHechas() > 0)) {
		std::cout << "Llamadas realizadas:" << llamadasEmisor->obtenerCursorNodo()->obtenerCantidadLlamadasHechas()
		          << ".\n";
		std::cout << "Duracion de las llamadas:" << llamadasEmisor->obtenerCursorNodo()->obtenerDuracionLlamadasHechas()
		          << ".\n";
		std::cout << "Cantidad de ocupados recibidos:"
		          << llamadasEmisor->obtenerCursorNodo()->obtenerCantidadOcupadosRecibidos() << ".\n";
	} else {
		std::cout << "No existen llamadas entre estos internos.\n\n";
	}
}

void Interfaz::DetalleDeLlamadasRecibidasPorXDeLaCentralAYRealizadasPorYDeLaCentralB()
{
	std::cout << "Receptor. \n";
	int receptor = pedirInterno();
	std::cout << "Central del receptor.\n";
	int numeroCentralReceptor = pedirCentral();
	std::cout << "\n";

	std::cout << "Emisor. \n";
	int emisor = pedirInterno();
	std::cout << "Central del Emisor.\n";
	int numeroCentralEmisor = pedirCentral();
	std::cout << "\n";

	std::cout << "Detalles de llamadas recibidas por " << receptor << " de la central " << numeroCentralReceptor;
	std::cout << " y realizadas por " << emisor << " de la central " << numeroCentralEmisor << ".\n";

	Central* centralEmisor = obtenercentrales()->obtenerPunteroAlObjeto(numeroCentralEmisor)->obtenerObjeto();
	Lista<Llamada*>* llamadasEmisor = centralEmisor->obtenerInterno(emisor)->obtenerLlamadas();
	llamadasEmisor->iniciarCursorNodo();
	bool estaElReceptor = false;

	while (!estaElReceptor && llamadasEmisor->avanzarCursorNodo()) {

		if (llamadasEmisor->obtenerCursorNodo()->obtenerReceptorLlamada() == receptor) {
			estaElReceptor = true;
		}
	}
	// me aseguro de que, ademas de que exista un nodo con los datos de receptor, tenga datos de llamadas recibidas de el.
	if (estaElReceptor && (llamadasEmisor->obtenerCursorNodo()->obtenerCantidadLlamadasRecibidas() > 0)) {

		std::cout << "Llamadas recibidas:" << llamadasEmisor->obtenerCursorNodo()->obtenerCantidadLlamadasRecibidas()
		          << ".\n";
		std::cout << "Duracion de las llamadas:" << llamadasEmisor->obtenerCursorNodo()->obtenerDuracionLlamadasRecibidas()
		          << ".\n";
		std::cout << "Cantidad de ocupados recibidos:"
		          << llamadasEmisor->obtenerCursorNodo()->obtenerCantidadOcupadosDados() << ".\n";
	} else {
		std::cout << "No existen llamadas entre estos internos.\n\n";
	}
}
void Interfaz::crearVectorDeOrdenamiento(Central** &centralesOrdenadas, int &totalCentrales)
{
	Lista<Central*>* centrales = obtenercentrales();
	centrales->iniciarCursorNodo();
	totalCentrales = 0;
	int j = 0;
	while (centrales->avanzarCursorNodo()) {
		totalCentrales++;
	}
	centrales->iniciarCursorNodo();
	centralesOrdenadas = new Central* [totalCentrales];
	while (centrales->avanzarCursorNodo()) {
		centralesOrdenadas[j] = centrales->obtenerCursorNodo();
		j++;
	}
}
void Interfaz::centralesOrdenadasPorLlamadasAnuladas()
{
	int totalCentrales;
	Central** centralesOrdenadas;
	crearVectorDeOrdenamiento(centralesOrdenadas, totalCentrales);
	//Ordeno los punteros que inserte en el vector.
	for (int i = 0; i < totalCentrales - 1; i++) {
		for (int j = i + 1; j < totalCentrales ; j++) {
			if (centralesOrdenadas[i]->obtenerTotalDeLlamadasAnuladasDeInternos(centralesOrdenadas[i]->obtenerInternos()) <
			    centralesOrdenadas[j]->obtenerTotalDeLlamadasAnuladasDeInternos(centralesOrdenadas[j]->obtenerInternos())) {
				Central* centralTemporal = centralesOrdenadas[i];
				centralesOrdenadas[i] = centralesOrdenadas[j];
				centralesOrdenadas[j]= centralTemporal;
			}
		}
	}
	std::cout<<"Lista de centrales ordenadas decrecientemente por llamadas anuladas. \n\n";
	for (int i = 0; i < totalCentrales; i++) {
		std::cout<<i+1<<") Central numero:"<<centralesOrdenadas[i]->obtenerNumero()<<"\n";
		std::cout<<"   Total de llamadas anuladas:"<<centralesOrdenadas[i]->obtenerTotalDeLlamadasAnuladasDeInternos(centralesOrdenadas[i]->obtenerInternos())<<"\n\n";
	}

	delete[] centralesOrdenadas ;
}

void Interfaz::tratarOpcion(int opcion)
{
	bool continuar = true;
	while (continuar) {
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
			mostrarDetallesDeInternos();
			detallesLlamadasEntreInternoXDeLaCentralAYElInternoYDeLaCentralB();
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
			internoQueMasOcupadosRecibioPorCentralYGeneral();
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
			internoAlQueMasLeHablaronPorCentralYGeneral();
			realizarOtraConsulta(opcion, continuar);
			break;

		case 11:
			internoQueMasDioOcupadoPorCentralYGeneral();
			realizarOtraConsulta(opcion, continuar);
			break;

		case 12:
			mostrarDetallesDeInternos();
			DetallesLlamadasEmitidasPorElInternoXDeLaCentralA();
			realizarOtraConsulta(opcion, continuar);
			break;

		case 13:
			mostrarDetallesDeInternos();
			DetallesLlamadasRecibidasPorElInternoXDeLaCentralA();
			realizarOtraConsulta(opcion, continuar);
			break;

		case 14:
			mostrarDetallesDeInternos();
			DetalleDeLlamadasRealizadasPorXDeLaCentralAYRecibidasPorYDeLaCentralB();
			realizarOtraConsulta(opcion, continuar);
			break;

		case 15:
			mostrarDetallesDeInternos();
			DetalleDeLlamadasRecibidasPorXDeLaCentralAYRealizadasPorYDeLaCentralB();
			realizarOtraConsulta(opcion, continuar);
			break;

		case 16:
			centralesOrdenadasPorLlamadasAnuladas();
			realizarOtraConsulta(opcion, continuar);
			break;

		case 17:
			continuar = false;
			std::cout << "\n";
			std::cout << "Hasta luego. \n";
			break;
		}
	}
}
void Interfaz::realizarOtraConsulta(int& opcion, bool& continuar)
{
	char respuesta;
	std::cout << "Desea realizar otra consulta? [s/n]:";
	std::cin >> respuesta;

	if (respuesta == 's') {
		continuar = true;
		std::cout << "\n";
		mostrarMenu();
		opcion = pedirOpcionMenu();
	} else {
		continuar = false;
		std::cout << "\n";
		std::cout << "Hasta luego.\n \n";
	}
}
void Interfaz::iniciarPrograma()
{
	std::string ruta = pedirRuta();
	std::cout << "\n";
	std::cout << "La ruta es " << ruta << "\n\n";

	LectorArchivos* lectorArchivos = new LectorArchivos(ruta);
	this->cambiarPunteroALectorDeArchivos(lectorArchivos);

	std::string variableDeBusqueda = pedirAlgoritmoDeBusqueda();

	procesadorLlamada = new ProcesadorLlamada(lectorDeArchivos, variableDeBusqueda);
	procesadorLlamada->procesarLlamadas();

	this->iniciarlizarPunteroACentrales(procesadorLlamada);
	this->iniciarlizarPunteroAEnlaces(procesadorLlamada);

	std::cout << "Bienvenido al sistema de informacion de la central telefonica.\n \n";
	std::cout << "A continuacion de detalla el menu:\n\n";
	mostrarMenu();
	int opcion = pedirOpcionMenu();
	tratarOpcion(opcion);
	delete procesadorLlamada;
	delete lectorArchivos;
}

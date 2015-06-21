#include "ProcesadorLlamada.h"

ProcesadorLlamada::ProcesadorLlamada(LectorArchivos* lectorArchivosTemporal, std::string variableBusquedaTemporal)
{
	this->datosLlamada = NULL;
	this->centrales = new Lista<Central*>;
	this->enlaces = new Lista<Enlace*>;
	this->archivoLlamadas = lectorArchivosTemporal;
	this->recorridoLlamada = new Buscador(this->centrales);
	this->variableBusqueda = variableBusquedaTemporal;
}


void ProcesadorLlamada::buscaCentralMenorDistancia()
{
	this->recorridoLlamada->resetDatos();
	this->recorridoLlamada->encontrarCaminoPordistancia(this->datosLlamada->obtenerOrigen(), this->datosLlamada->obtenerDestino());
}


void ProcesadorLlamada::buscaCentralMenorPrecio()
{
	this->recorridoLlamada->resetDatos();
	this->recorridoLlamada->encontrarCaminoPorPrecio(this->datosLlamada->obtenerOrigen(), this->datosLlamada->obtenerDestino());
}

void ProcesadorLlamada::crearInterno(int internoNuevo, int central)
{
	this->centrales->obtenerPunteroAlObjeto( central )->obtenerObjeto()->crearInterno( internoNuevo );
}

Interno* ProcesadorLlamada::obtenerInterno(int internoAObtener, int central)
{
	return this->centrales->obtenerPunteroAlObjeto( central )->obtenerObjeto()->obtenerInterno( internoAObtener );
}

bool ProcesadorLlamada::chequearDisponibilidadRecorrido(Recorrido* enlacesDelRecorrido)
{
	bool caminoDisponible = true;
	Lista<Enlace*>* enlacesLlamada = enlacesDelRecorrido->obtenerEnlacesRecorridos() ;
	enlacesLlamada->iniciarCursorNodo();

	while (enlacesLlamada->avanzarCursorNodo() && caminoDisponible) {
		Enlace* enlaceActual = enlacesLlamada->obtenerCursorNodo();

		caminoDisponible = enlaceActual->chequearDisponibilidadCanales();
	}

	return caminoDisponible;
}

Recorrido* ProcesadorLlamada::obtenerMejorCamino(int centralOrigen, int centralDestino)
{
	return this->centrales->obtenerPunteroAlObjeto( centralOrigen )->obtenerObjeto()->obtenerRecorridoACentral( centralDestino ) ;
}

void ProcesadorLlamada::iniciarLlamada()
{
	// Veo si los internos existen o sino, los crea
	this->crearInterno( this->datosLlamada->obtenerEmisor() , this->datosLlamada->obtenerOrigen() );
	this->crearInterno( this->datosLlamada->obtenerReceptor() , this->datosLlamada->obtenerDestino() );

	//Obtengo punteros a cada interno
	Interno* emisor;
	Interno* receptor;

	emisor = this->obtenerInterno ( this->datosLlamada->obtenerEmisor() , this->datosLlamada->obtenerOrigen() );
	receptor = this->obtenerInterno ( this->datosLlamada->obtenerReceptor() , this->datosLlamada->obtenerDestino() );

	//Agrego la llamada a cada interno
	emisor->agregarLlamadaEmisor(this->datosLlamada->obtenerReceptor(), this->datosLlamada->obtenerHora(), this->datosLlamada->obtenerDestino(), this->recorridoLlamada->obtenerRuta(),
	                             this->recorridoLlamada->noEstaAnuladaLaLlamada(), this->recorridoLlamada->obtenerPrecioDeLaLlamada() );

	receptor->agregarLlamadaReceptor(this->datosLlamada->obtenerEmisor(), this->datosLlamada->obtenerHora(), this->datosLlamada->obtenerOrigen(), this->recorridoLlamada->obtenerRuta(),
	                                 this->recorridoLlamada->noEstaAnuladaLaLlamada(), this->recorridoLlamada->obtenerPrecioDeLaLlamada() );
	//Cambio la disponibilidad de los enlaces
	if(this->datosLlamada->obtenerOrigen() != this->datosLlamada->obtenerDestino()) {
		Lista<Enlace*>* enlacesRecorridos = emisor->devolverRecorridoLlamada(this->datosLlamada->obtenerReceptor() );

		enlacesRecorridos->iniciarCursorNodo();

		while( enlacesRecorridos->avanzarCursorNodo() )	{
			enlacesRecorridos->obtenerCursorNodo()->agregarLlamadaEnCurso();
		}
	}
}

void ProcesadorLlamada::iniciarLlamadaDijkstra()
{
	// Veo si los internos existen o sino, los crea
	this->crearInterno( this->datosLlamada->obtenerEmisor() , this->datosLlamada->obtenerOrigen() );
	this->crearInterno( this->datosLlamada->obtenerReceptor() , this->datosLlamada->obtenerDestino() );

	//Obtengo punteros a cada interno
	Interno* emisor;
	Interno* receptor;

	emisor = this->obtenerInterno ( this->datosLlamada->obtenerEmisor() , this->datosLlamada->obtenerOrigen() );
	receptor = this->obtenerInterno ( this->datosLlamada->obtenerReceptor() , this->datosLlamada->obtenerDestino() );

	/* Busco el mejor camino de la central origen a la central destino y veo si estan disponibles los enlaces
	 *  sii la llamada no es interna de la central
	 */
	if ( this->datosLlamada->obtenerOrigen() != this->datosLlamada->obtenerDestino() ) {
		Recorrido* mejorCamino = this->obtenerMejorCamino(this->datosLlamada->obtenerOrigen(), this->datosLlamada->obtenerDestino() );

		if ( this->chequearDisponibilidadRecorrido(mejorCamino) ) {
			mejorCamino->obtenerEnlacesRecorridos()->iniciarCursorNodo();

			while( mejorCamino->obtenerEnlacesRecorridos()->avanzarCursorNodo() )	{
				mejorCamino->obtenerEnlacesRecorridos()->obtenerCursorNodo()->agregarLlamadaEnCurso();
			}

			emisor->agregarLlamadaEmisor(this->datosLlamada->obtenerReceptor(), this->datosLlamada->obtenerHora(), this->datosLlamada->obtenerDestino(), mejorCamino->obtenerEnlacesRecorridos(),
			                             false, mejorCamino->obtenerPrecioRecorrido() );

			receptor->agregarLlamadaReceptor(this->datosLlamada->obtenerEmisor(), this->datosLlamada->obtenerHora(), this->datosLlamada->obtenerOrigen(), mejorCamino->obtenerEnlacesRecorridos(),
			                                 false, mejorCamino->obtenerPrecioRecorrido() );
		} else {
			//Llamo al buscador nuestro, que encuentra un camino si existiese, sino, se anula
			this->recorridoLlamada->resetDatos();
			this->recorridoLlamada->encontrarCaminoPorPrecio(this->datosLlamada->obtenerOrigen(), this->datosLlamada->obtenerDestino());


			//Agrego la llamada a cada interno
			emisor->agregarLlamadaEmisor(this->datosLlamada->obtenerReceptor(), this->datosLlamada->obtenerHora(), this->datosLlamada->obtenerDestino(), this->recorridoLlamada->obtenerRuta(),
			                             this->recorridoLlamada->noEstaAnuladaLaLlamada(), this->recorridoLlamada->obtenerPrecioDeLaLlamada() );

			receptor->agregarLlamadaReceptor(this->datosLlamada->obtenerEmisor(), this->datosLlamada->obtenerHora(), this->datosLlamada->obtenerOrigen(), this->recorridoLlamada->obtenerRuta(),
			                                 this->recorridoLlamada->noEstaAnuladaLaLlamada(), this->recorridoLlamada->obtenerPrecioDeLaLlamada());


		}
	} else {
		emisor->agregarLlamadaEmisor(this->datosLlamada->obtenerReceptor(), this->datosLlamada->obtenerHora(), this->datosLlamada->obtenerDestino(), this->recorridoLlamada->obtenerRuta(),
		                             this->recorridoLlamada->noEstaAnuladaLaLlamada(), this->recorridoLlamada->obtenerPrecioDeLaLlamada() );

		receptor->agregarLlamadaReceptor(this->datosLlamada->obtenerEmisor(), this->datosLlamada->obtenerHora(), this->datosLlamada->obtenerOrigen(), this->recorridoLlamada->obtenerRuta(),
		                                 this->recorridoLlamada->noEstaAnuladaLaLlamada(), this->recorridoLlamada->obtenerPrecioDeLaLlamada() );
	}
}



                                 void ProcesadorLlamada::finalizarLlamada()
{
	//Obtengo punteros a cada interno
	Interno* emisor;
	Interno* receptor;

	emisor = this->obtenerInterno ( this->datosLlamada->obtenerEmisor() , this->datosLlamada->obtenerOrigen() );
	receptor = this->obtenerInterno ( this->datosLlamada->obtenerReceptor() , this->datosLlamada->obtenerDestino() );

	// Termino la llamada en cada interno
	emisor->terminarLlamadaEmisor(this->datosLlamada->obtenerEmisor(), this->datosLlamada->obtenerHora() );
	receptor->terminarLlamadaReceptor(this->datosLlamada->obtenerReceptor(), this->datosLlamada->obtenerHora() );

	//Cambio disponibilidad de enlaces
	if(this->datosLlamada->obtenerOrigen() != this->datosLlamada->obtenerDestino()) {
		Lista<Enlace*>* enlacesRecorridos = emisor->devolverRecorridoLlamada(this->datosLlamada->obtenerReceptor() );
		enlacesRecorridos->iniciarCursorNodo();

		while( enlacesRecorridos->avanzarCursorNodo() )	{
			enlacesRecorridos->obtenerCursorNodo()->eliminarLlamadaEnCurso();
		}
	}
}


void ProcesadorLlamada::agregarCentral(int numeroCentral)
{
	this->centrales->iniciarCursorNodo();
	bool encontro=false;
	while ((this->centrales->avanzarCursorNodo()) && (! encontro)) {
		encontro= (numeroCentral == this->centrales->obtenerCursorNodo()->obtenerNumero()) ;
	}
	if (! encontro) {
		Central* nuevaCentral= new Central(numeroCentral) ;
		this->centrales->insertar(nuevaCentral);
	}
}


void ProcesadorLlamada::agregarEnlace(int numeroOrigen, int numeroDestino)
{
	this->enlaces->iniciarCursorNodo();
	bool encontro=false;
	while ((this->enlaces->avanzarCursorNodo()) && (! encontro)) {
		encontro= ( numeroOrigen == this->enlaces->obtenerCursorNodo()->obtenerOrigen()->obtenerNumero() )
		          &&
		          ( numeroDestino == this->enlaces->obtenerCursorNodo()->obtenerDestino()->obtenerNumero() ) ;
	}
	if (! encontro) {
		// Aca tener en cuenta que los atributos de this->datosLlamada siguen con los nombres como si fuera
		// una llamada, pero realmente es para una enlace y estan ordenados
		Enlace* nuevoEnlace = new Enlace(this->datosLlamada->obtenerOrigen(), this->datosLlamada->obtenerEmisor(),
		                                 this->datosLlamada->obtenerDestino(), this->datosLlamada->obtenerReceptor(),
		                                 this->datosLlamada->obtenerHora(), this->centrales);

		this->enlaces->insertar(nuevoEnlace);

		//Agrego el puntero al enlace a las centrales que corresponda
		this->centrales->iniciarCursorNodo();

		while ( this->centrales->avanzarCursorNodo() ) {
			Central* centralTemporal = this->centrales->obtenerCursorNodo();

			if (centralTemporal->obtenerNumero() == numeroDestino || centralTemporal->obtenerNumero() == numeroOrigen) {
				centralTemporal->agregarEnlace(nuevoEnlace);
			}

		}
	}
}


Lista<Central*>* ProcesadorLlamada::obtenerCentrales()
{
	return (this->centrales);
}


Lista<Enlace*>* ProcesadorLlamada::obtenerEnlaces()
{
	return (this->enlaces);
}

void ProcesadorLlamada::cargarCaminosEnCentrales()
{
	this->recorridoLlamada->Dijkstra(centrales);
}


void ProcesadorLlamada::procesarLlamadas()
{
	bool fueEnlaceLoAnterior = false;
	while ( archivoLlamadas->chequearLlamadas() ) {
		this->datosLlamada = archivoLlamadas->obtenerDatosLlamada();

		if ( this->datosLlamada->obtenerAccion() == "Inicio") {
			if (fueEnlaceLoAnterior && this->variableBusqueda == "Dijkstra")
				this->cargarCaminosEnCentrales();

			this->agregarCentral(this->datosLlamada->obtenerOrigen() );
			this->agregarCentral(this->datosLlamada->obtenerDestino() );

			if (this->variableBusqueda == "Distancia")
				this->buscaCentralMenorDistancia();
			else if (this->variableBusqueda == "Precio")
				this->buscaCentralMenorPrecio();
			else if (this->variableBusqueda == "Dijkstra")
				this->iniciarLlamadaDijkstra();


			this->iniciarLlamada();
			fueEnlaceLoAnterior = false;

		} else if ( this->datosLlamada->obtenerAccion() == "Fin") {
			this->finalizarLlamada();
			fueEnlaceLoAnterior = false;
		} else if (this->datosLlamada->obtenerAccion() == "Enlace") {
			this->agregarCentral(this->datosLlamada->obtenerOrigen() );
			this->agregarCentral(this->datosLlamada->obtenerEmisor() );

			agregarEnlace(this->datosLlamada->obtenerOrigen(), this->datosLlamada->obtenerEmisor());

			fueEnlaceLoAnterior = true;
		}
	}
}


ProcesadorLlamada::~ProcesadorLlamada()
{
	delete(this->enlaces);
	delete(this->centrales);
	delete(this->recorridoLlamada);
}

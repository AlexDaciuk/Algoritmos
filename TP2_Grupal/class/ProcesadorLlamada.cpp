#include "ProcesadorLlamada.h"

ProcesadorLlamada::ProcesadorLlamada()
{
	this->datosTemporal= NULL;
	this->recorridoTemporal= NULL;
	this->centrales = new Lista<Central>;
	this->enlaces = new Lista<Enlace>;
}

void ProcesadorLlamada::procesarLlamadas()
{
	while ( archivoLlamadas->chequearLLamada() ) {
		this->datosTemporal = archivoLlamadas->obtenerDatosLlamada();

		agregarCentral(this->datosTemporal->obtenerOrigen);
		agregarCentral(this->datosTemporal->obtenerDestino);

		if ( this->datosTemporal->accionTemporal == "Inicio") {
			// Aca va el tema con el buscador de caminos
			// recorridoTemporal = this->buscaCentral;
			this->iniciarLlamada();
		} else {
			if ( this->datosTemporal->accionTemporal == "Fin") {
				this->finalizarLlamada();
			} else {
				if ( this->datosTemporal->accionTemporal == "Enlace") {
					agregarEnlace(this->datosTemporal->obtenerOrigen(), this->datosTemporal->obtenerDestino());
				}
			}
		}
	}
}

void ProcesadorLlamada::iniciarLlamada();
{
	// Veo si los internos existen o sino, los crea
	this->centrales->crearInterno(this->datosTemporal->obtenerOrigen(), this->datosTemporal->obtenerEmisor());
	this->centrales->crearInterno(this->datosTemporal->obtenerDestino(), this->datosTemporal->obtenerReceptor());

	//Obtengo punteros a cada interno
	Internos* Emisor, Receptor;

	Emisor = this->centrales->obtenerInterno(this->datosTemporal->obtenerOrigen(), this->datosTemporal->obtenerEmisor() );
	Receptor = this->centrales->obtenerInterno(this->datosTemporal->obtenerDestino(), this->datosTemporal->obtenerReceptor() );

	//Agrego la llamada a cada interno
	Emisor->agregarLlamadaEmisor(this->datosTemporal->obtenerReceptor(), this->datosTemporal->obtenerHora(), recorridoTemporal);
	Receptor->agregarLlamadaReceptor(this->datosTemporal->obtenerEmisor(), this->datosTemporal->obtenerHora(), recorridoTemporal);

	//Cambio la disponibilidad de los enlaces
	Enlace* EnlaceTemporal = this->recorridoTemporal->obtenerRuta;

	/**
	 *  Esto hay que cambiarlo, usar un cursor dentro de la lista
	 * u otro metodo inclusive
	 * while ( recorridoTemporal->punteroARuta != NULL )
	 *{
	 *punteroEnlaceTemporal->agregarLlamadaEnCurso();
	 *
	 *punteroEnlaceTemporal = punteroEnlaceTemporal->obtenerSiguiente();
	 *}
	 */
}


void ProcesadorLlamada::finalizarLlamada()
{
	//Obtengo punteros a cada interno
	Internos* Emisor, Receptor;

	Emisor = this->centrales->obtenerInterno(this->datosTemporal->obtenerOrigen(), this->datosTemporal->obtenerEmisor());
	Receptor = this->centrales->obtenerInterno(this->datosTemporal->obtenerDestino(), this->datosTemporal->obtenerReceptor());


	// Termino la llamada en cada interno
	Emisor->terminarLlamadaEmisor(this->datosTemporal->obtenerEmisor(), this->datosTemporal->obtenerHora() );
	Receptor->terminarLlamadaReceptor(this->datosTemporals->obtenerReceptor(), this->datosTemporal->obtenerHora() );


	//Cambio disponibilidad de enlaces

};


void ProcesadorLlamada::agregarCentral(int numeroCentral)
{
	this->entrales->iniciarCursorNodo();
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
	this->enlaces->inicarCursorNodo();
	bool encontro=false;
	while ((this->enlaces->avanzarCursorNodo()) && (! encontro))) {
		encontro= (numeroOrigen==this->enlaces->obtenerCursorNodo()->obtenerOrigen())
		          &&
		          (numeroDestino==this->enlaces->obtenerCursorNodo()->obtenerDestino()) ;
	}
	if (! encontro) {
	// Aca tener en cuenta que los atributos de this->datosTemporal siguen con los nombres como si fuera
	// una llamada, pero realmente es para una central y estan ordenados
	Enlace* nuevoEnlace = new Enlace(numeroOrigen, numeroDestino, this->datosTemporal->obtenerDestino(),
	                                 this->datosTemporal->obtenerReceptor(), this->datosTemporal->obtenerHora());
		this->enlaces->insertar(nuevoEnlace);

		// Tengo que agregar a la lista de puntero de enlaces de cada central el puntero que corresponde
	}
}

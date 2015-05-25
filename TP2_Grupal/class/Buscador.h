#ifndef BUSCADOR_H
#define BUSCADOR_H

#ifndef NULL
#define NULL 0

#include "Lista.h"
#include "Enlace.h"
#include "Internos.h"
#include "Central.h"
#include "Spot.h"

/**
 * Esta clase se ocupará de encontrar el camino con la menor distacia
 * o con el precio mas bajo de una central a otra.
 * Modo de uso: Luego de crear el buscador, lo primero que se debe hacer es buscar el
 * camino, ya sea por precio o distancia, antes de pedirle cualquiera de las operaciones.
 */
class Buscador
{

private:
    Lista<Enlace*>* mejorCamino;

    Lista<Spot*>* rutaActual;

    Lista<Central*>* centralesTotales;

    int precioDeLaLlamada;

    int distanciaDeLaLlamada;
	
	int tipoDeBusqueda;

public:

    /**
     * Pre: se inicia una llamda entre un interno y otro de distintas centrales.
     * Se le da una lista con todas las centrales disponibles.
     */
    Buscador(Lista<Central*>* centrales);

    /**
     * Post: te otorga la ruta de enlaces que encontro.
     * Sera nula cuando la llamada fue interna de una central
     */
    Lista<Enlace*>* obtenerRuta();

    /**
     * Post: devuelve el precio de la llamada. De no haber hecho la busqueda devuelve 0
     */
    int obtenerPrecioDeLaLlamada();

    /**
     * Post: devuelve la distancia de la llamada. De no haber hecho la busqueda devuelve 0
     */
    int obtenerDistanciaDeLaLlamada();

    /**
     * Los siguientes metodos requieren de haber hecho la busqueda para que funcionen.
     */
	Central* obtenerCentralEmisora();
	
	Central* obtenerCentralReceptora();
	
	Interno* obtenerInternoEmisor(int emisor);
	
	Interno* obtenerInternoReceptor(int receptor);

    /**
     * Post: hace el algoritmo de busqueda por mejor precio
     */
    void encontrarCaminoPorPrecio(int centralEmisora, int centralReceptora);

    /**
     * Post: hace el algoritmo de busqueda por mejor distancia
     */
    void encontrarCaminoPordistancia(int centralEmisora, int centralReceptora);

    /**
     * Post: libera la memoria de los spots usados y la lista del mejor camino
     */
    ~Buscador();

private:

    /**
	* Post: indica si ya visite a la central en el camino ya hecho
	*/
    bool YaPasePorLaCentral(Central* central);

    /**
     * Post: indica si La llamada es entre dos numeros de la misma central
     */
    bool esLlamadaInterna(int centralEmisora, int centralReceptora);
	
    Interno* encontrarInternoEnLa(Central* central, int numeroDeInterno);

	/**
     * Fija el precio y distancia que encontro el Buscador.
     */
    void definirEstePrecioYDistancia();

	/**
     * Si hay mas caminos devuelve true, sino devuelve false
     */
    bool hayMasCaminos();

	/**
     * Desde una central inicia el algoritmo para moverse a otra. Si llego al final del camino guarda
	 * la informacion y establece el mejor camino, precio y distancia.
     */
    void avanzarBusquedaDesde(Central* centralActual, int buscoMejorValor, int precioActual, int centralReceptora);

    bool caminarEnlace(Central* centralActual, int centralReceptora);

    void caminarPorPrecio(Enlace* enlaceActual, Spot* spotActual, int centralReceptora);
	
	void caminarPorDistancia(Enlace* enlaceActual, Spot* spotActual, int centralReceptora);
	
	Lista<Enlace*>* definirEstaRuta();
	
	int obtenerTipoDeBusqueda();
	
	void establecerBusquedaPorPrecio();
	
	void establecerBusquedaPorDistancia();
	
	Central* encontrarLaCentral(int central);
};
#endif
#endif

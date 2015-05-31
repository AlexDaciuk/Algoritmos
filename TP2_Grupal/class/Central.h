#ifndef CENTRAL_H_
#define CENTRAL_H_

#ifndef NULL
#define NULL 0
#endif

#include "Lista.h"
#include "Enlace.h"
#include "Interno.h"

/**
 * Clase que maneja cada central
 */

class Interno;
class Enlace;

class Central
{
private:

	int numeroCentral;

	Lista<Interno*>* internos;
	// Puntero a la lista de punteros a los enlaces de la central
	Lista<Enlace*>* enlaces;

public:

	/**
	 * Constuctor de la clase
	 * Post: Va a quedar creada el nodo en la lista de centrales
	 */

	Central(int numeroCentralTemporal);


	/**
	 * Metodo que crea un interno dentro de la central, para usarse cuando entra una llamada de
	 * otra central y el interno en cuestion no existe
	 */

	void crearInterno(int numeroInterno);

	/**
	 * Precondicion: el interno debe existir.
   * postcondicion: devuelve el puntero al interno indicado de la lista de internos.
	 */

	Interno* obtenerInterno(int numeroInterno);

	/**
	 * Metodo que devuelve la lista de internos
	 */

	Lista<Interno*>* obtenerInternos();

	/**
	 * Metodo que devuelve la lista de enlaces
	 */

	Lista<Enlace*>* obtenerEnlaces();

	void agregarEnlace(Enlace* enlaceTemporal);

	/**
	 * Metodo que devuelve el numero de la central
	 */

	int obtenerNumero();
  /**
   * post: devuelve el total de llamadas anuladas de toda la lista de internos.
   */
  int obtenerTotalDeLlamadasAnuladasDeInternos(Lista<Interno*>* internos);

	/**
	 * destructor de Central
	 * */
	~Central();


};



#endif

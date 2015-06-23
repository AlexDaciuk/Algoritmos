#ifndef CENTRAL_H_
#define CENTRAL_H_

#ifndef NULL
#define NULL 0
#endif

#include "Lista.h"
#include "Enlace.h"
#include "Interno.h"

class Interno;
class Enlace;

/**
 * Clase que maneja cada central
 */

class Central
{
private:

	int numeroCentral;
	Lista<Interno*>* internos;
	Lista<Enlace*>* enlaces;

public:
	/**
	 * Constuctor de la clase
	 * Post: Va a quedar creada la central con su lista de internos y enlaces vacias
	 */
	Central(int numeroCentralTemporal);


	/**
	 * Metodo que crea un interno dentro de la central, si ya existe el interno, no hace nada
	 */
	void crearInterno(int numeroInterno);


	/**
	 * Precondicion: El interno debe existir.
	 * Postcondicion: Devuelve el puntero al interno solicitado.
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

	/**
	 * Metodo que agrega un enlace a la lista de enlaces de la central
	 */
	void agregarEnlace(Enlace* enlaceTemporal);
  
  /**
   * Precondicion: recibe un entero positivo.
   * postcondicion: devuelve verdadero si numero pasado pertenece a un interno
   * de la lista de internos.
   */
  bool existeElInterno(int numeroInterno);


	/**
	 * Metodo que devuelve el numero de la central
	 */
	int obtenerNumero();


	/**
	 * Devuelve el total de llamadas anuladas de toda la lista de internos.
	 */
	int obtenerTotalDeLlamadasAnuladasDeInternos(Lista<Interno*>* internos);


	/**
	 * Destructor de Central, libera el espacio pedido para la lista de enlaces y de internos
	 * */
	~Central();

};

#endif

#ifndef NODO_H_
#define NODO_H_

#ifndef NULL
#define NULL 0
#endif

/**
 * Clase que define a cada nodo de una lista simple
 *
 */

template<class T> class Nodo
{

private:

	T objeto;
	Nodo<T>* nodoSiguiente;
	Nodo<T>* nodoAnterior;

public:

	/**
	 * Pre: Se le debe pasar un objeto del tipo correspondiente al tipo que guarda el nodo.
	 * Post: El nodo se crea con un dato almacenado y sus punteros apuntando a null
	 */
	Nodo(T objeto) {

		this->objeto= objeto;
		this->nodoSiguiente= NULL;
		this->nodoAnterior= NULL;
	}


	/**
	 * Post: Cambia la dierccion del puntero que apunta al siguente nodo
	 */
	void cambiarNodoSiguiente(Nodo<T>* nodoSiguiente) {

		this->nodoSiguiente=nodoSiguiente;
	}


	/**
	 * Post: Cambia la direccion del puntero que apunta al nodo anterior
	 */
	void cambiarNodoAnterior(Nodo<T>* nodoAnteriorTemporal) {

		this->nodoAnterior=nodoAnteriorTemporal;
	}


	/**
	 * Pre: El objeto que se pasa tiene que ser el mismo que el del noto
	 * Post: El objeto original queda reemplazado por el nuevo
	 */
	void cambiarObjeto(T objeto) {

		this->objeto=objeto;
	}


	/**
	 * Post: Devuelve la direccion de memoria del proximo nodo en la lista
	 */
	Nodo<T>* obtenerSiguiente()  {

		return this->nodoSiguiente;
	}


	/**
	 * Post: Devuelve la direccion de memoria del nodo anterior en la lista
	 */
	Nodo<T>* obtenerAnterior()  {

		return this->nodoAnterior;
	}


	/**
	 * Post: Devuelve el objeto guardado en el nodo
	 */
	T obtenerObjeto()  {

		return this->objeto;
	}

};


#endif

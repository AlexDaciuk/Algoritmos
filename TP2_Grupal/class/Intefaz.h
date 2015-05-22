#include <string>
#include <iostream>

/**
 * Clase que maneja la interfaz e interaccion con el usuario
 * 
 * 
 */


class Interfaz {
private:
	
	
	
	
public:
	
	/**
	 * Metodo que va a iniciar el programa
	 */
	void iniciarPrograma();
	
	/**
	 * Metodo que va a mostrar el menu al usuario
	 */
	void menu();
	
	/**
	 * Metodo que va a pedir la opcion del menu al usuario
	 */
	int pedirOpcionMenu();
	
	/**
	 * Metodo que va a pedir numero de central al usuario
	 */
	int pedirCentral();
	
	/**
	 * Metodo que va a pedir numero de interno al usuario 
	 */
	int pedirInterno();
}

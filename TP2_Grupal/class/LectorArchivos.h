#include <string>
#include <sstream>

/**
 * Clase que se encarga de leer los archivos de texto con las 
 * llamadas a procesar
 */

class LectorArchivos
{
private:
  std::string rutaArchivo;
  DatosLlamada* datosLlamadaTmp;
  ifstream archivo;
  boolean hayLlamadas;
  
  
public:
  /**
   * Constructor de la clase LectorArchivos 
   * Post: Se crea la clase, queda cargada la ruta del txt y crea un nuevo objeto DatosLlamada vacio
   */
  
  LectorArchivos(std::string rutaArchivoTemporal);

  /**
   * Obtiene una llamada a la vez y la devuelve un puntero
   * al objeto con los datos
   */
 
  DatosLlamada* obtenerDatosLlamada();


  /**
   * Destructor
   * Cierra la apertura del archivo txt
   */
  
  ~LectorArchivos();
  
}

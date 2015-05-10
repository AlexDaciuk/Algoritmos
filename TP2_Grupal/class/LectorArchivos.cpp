#include <string>
#include <sstream>
#include "DatosLlamada.h"

LectorArchivos::LectorArchivos (std::string rutaArchivoTemporal)
{
  this->archivo.open( ruta.c_str(rutaArchivoTemporal) );
  
  this->datosLlamadasTmp = new DatosLlamada();

  this->hayLlamadas = true;
  
}


DatosLlamada* LectorArchivos::obtenerDatosLlamada()
{
  if (! archivo.eof() )
    {
      string accionTemporal, centralATemporal, internoATemporal, centralBTemporal, internoBTemporal, horaTemporal;
      
      getline(archivo, accionTemporal,' ');
            
      getline(archivo, centralATemporal,' ');
            
      getline(archivo, internoATemporal,' ');
                  
      getline(archivo, centralBTemporal,' ');
      
      getline(archivo, internoBTemporal,' ');
      
      getline(archivo, horaTemporal,'\n');
    }
  else
    {
      this->hayLlamadas = false;
    }

}


bool LectorArchivos::chequearLlamada()
{
  return (this->hayLlamada);
}


LectorArchivos::~LectorArchivos()
{
  
  delete this->datosLlamadasTmp;
  
}

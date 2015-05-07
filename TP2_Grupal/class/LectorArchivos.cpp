#include <string>
#include <sstream>


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


LectorArchivos::~LectorArchivos()
{
  
  delete this->datosLlamadasTmp;
  
}

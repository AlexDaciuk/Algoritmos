#include <string>
#include <sstream>

void DatosLlamada::cargarLlamada(std::string accionTemporal, std::string centralATemporal, std::string internoATemporal, std::string centralBTemporal, std::string internoBTemporal, std::string horaInicioTemporal)
{
  if (! accionTemporal.empty())
    {
      this->accion = accionTemporal;
      
      std::stringstream centralAStream(centralATemporal);
      centralAStream >> this->centralA;      

      std::stringstream internoAStream(internoATemporal);
      internoAStream >> this->internoA;
      
      std::stringstream centralBStream(centralBTemporal);
      centralBstream >> this->centralB;
    
      std::stringstream internoBStream(internoBTemporal);
      internoBStream >> this->internoB;  
        
      std::stringstream horaInicioStreamTemporal(horaInicioTemporal);
      horaInicioStreamTemporal >> this->horaInicio;
      
    }
}

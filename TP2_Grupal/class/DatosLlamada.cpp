#include <string>
#include <sstream>

void DatosLlamada::cargarLlamada(std::string accionTmp, std::string centralATmp, std::string internoATmp, std::string centralBTmp, std::string internoBTmp, std::string horaInicioTmp)
{
  if (! accionTmp.empty())
    {
      this->accion = accionTmp;
      
      std::stringstream centralAStream(centralATemporal);
      centralAStream >> this->centralA;      

      std::stringstream internoAStream(internoATemporal);
      internoAStream >> this->internoA;
      
      std::stringstream centralBStream(centralBTemporal);
      centralBstream >> this->centralB;
    
      std::stringstream internoBStream(internoBTemporal);
      internoBStream >> this->internoB;  
        
      std::stringstream horaInicioStreamTmp(horaInicioTmp);
      horaInicioStreamTmp >> this->horaInicio;
      
    }
}

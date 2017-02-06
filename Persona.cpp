#include "Persona.h"
#include <string>
#include <sstream>
#include <iostream>

Persona::Persona(string nombreEmpleado, int edadEmpleado): nombreEmpleado(nombreEmpleado),edadEmpleado(edadEmpleado){

}

string Persona::toString()const{
  stringstream ss;
  ss << "Nombre del Empleado: " << nombreEmpleado << "\n" << "Edad del Empleado: " << edadEmpleado << "\n";
  return ss.str();
}

bool Persona::equals(Object* other)const{
  if(dynamic_cast<Persona*>(other)){
    return false;
  }

    Persona* persona = dynamic_cast<Persona*>(other);
    return persona->nombreEmpleado == nombreEmpleado;
}

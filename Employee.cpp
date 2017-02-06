#include "Persona.h"
#include "Employee.h"
#include "Object.h"
#include <iostream>
#include <string>
#include <sstream>


Employee::Employee(string nombre, int edad, double salario):Persona(nombre, edad){
  this->salario = salario;
}

void Employee::setSalario(double salario){
  this->salario = salario;
}

double Employee::getSalario(){
  return salario;
}

void Employee::setIncremento(double incremento){

}

//toString de la clase empleado para demostrar su nombre, edad, y salario
string Employee::toString(){
  stringstream ss;
  ss << Persona::toString() << "Salario del empleado: " << salario << endl;
  return ss.str();
}

bool Employee::equals(Object* other){
    if(dynamic_cast<Employee*>(other))
      return false;
}

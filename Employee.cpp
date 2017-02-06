#include "Persona.h"
#include "Employee.h"
#include "Object.h"
#include <iostream>
#include <string>
#include <sstream>

Employee::Employee(){

}

Employee::Employee(string nombre, int edad, double pSalario):Persona(nombre, edad){
  salario = getSalario();
}

Employee::~Employee(){

}

void Employee::setSalario(double salario){
  salario = pSalario;
}

double Employee::getSalario(){
  return salario;
}

void Employee::setIncremento(double incremento){

}

//toString de la clase empleado para demostrar su nombre, edad, y salario
string Employee::toString(){
  stringstream ss;
  ss << Persona.toString() << "Salario del empleado: " << salario << endl;
  return ss.str();
}

bool Employee::equals(Object* other){
    if(!dynamic_cast<Empleado*>(other))
      return false;
}

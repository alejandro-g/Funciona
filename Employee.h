#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Persona.h"
#include "Object.h"
#include <string>
#include <sstream>

class Employee: public Persona{
protected:
  double salario;

public:
  Employee();
  Employee(string, int, double);
  ~Employee();
  void setSalario(double);
  double getSalario();
  void setIncremento(double);
  virtual string toString();
  virtual bool equals(Object*);
};
#endif

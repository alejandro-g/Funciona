#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include "Object.h"

class Persona: public Object{
protected:
  string nombreEmpleado;
  int edadEmpleado;

public:
  Persona(string,int);
  virtual string toString()const;
  virtual bool equals(Object*)const;
};
#endif

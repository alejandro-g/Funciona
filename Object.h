#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Object{
  public:
    Object();
    virtual ~Object();
    virtual string toString()const;
    virtual bool equals(Object*)const;
};
#endif

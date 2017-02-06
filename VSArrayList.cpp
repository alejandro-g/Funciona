#include "VSArrayList.h"
#include "ADTList.h"
#include <iostream>

//metodo encargado de insertar elementos en la lista
bool VSArrayList::insert(Object* element, int posicion){
  if(posicion < 0 || posicion > size){
    return false;
  }
  if(size == current_capacity){
    resize();
  }
  for (int i = size; i > posicion ; i--) {
    array[i] = array[i -1];
  }
  array[posicion] = element;
  size++;
  return true;
}

//metodo que se encarga de hacer modificaciones al size de la lista en cualquier caso de modificacion
void VSArrayList::resize(){
  Object** temporal = NULL;
  temporal = new Object*[current_capacity + delta];
  //for para la validacion de memoria
  for (int i = 0; i < current_capacity; i++) {
    temporal[i] = array[i];
  }
  delete[] array;
  array = temporal;
  current_capacity += delta;
}


VSArrayList::VSArrayList(int current_capacity){
  this-> current_capacity = current_capacity;
  delta = current_capacity;
  array = new Object* [current_capacity];
  if(!array){
    //cerr << "NO MEMORY LEFT" << endl;
    //exit(1);
  }
}

//destructor virtual de VSArrayList
VSArrayList::~VSArrayList(){
  for (int i = 0; i < size; i++) {
    if(array[i]){
      delete array[i];
    }
  }
  delete[] array;
}

VSArrayList::VSArrayList(int current_capacity, int delta){
  this-> current_capacity = current_capacity;
  this-> delta = delta;
}

Object* VSArrayList::first()const{
  return array[0];
}

Object* VSArrayList::last()const{
  return array[size - 1];
}

int VSArrayList::indexOf(Object* element)const{
  int temporal = 0;
  for (int i = 0; i < size; i++) {//recorrer el arreglo para conseguir objeto
    if(array[i] == element){
      temporal = i;
    }
  }
  return temporal;
}

Object* VSArrayList::get(int posicion)const{
  return array[posicion];
}

int VSArrayList::capacity()const{
  return current_capacity;
}

bool VSArrayList::isEmpty()const{
  if(size != 0){
    return false;
  }else{
    return true;
  }
}

bool VSArrayList::isFull()const{
  if(size == current_capacity){
    return true;
  }else{
    return false;
  }
}

Object* VSArrayList::remove(int posicion){
  Object* element = array[posicion];
  array[posicion] = NULL;
  delete array[posicion];

  for (int i = posicion; i < size; i++) {
    array[i] = array[i + 1];
  }
  array[size - 1] = NULL;
  delete array[size - 1];
  size--;
  return element;
}

void VSArrayList::clear(){
  for (int i = 0; i < size; i++) {
    if(array[i]){
      delete array[i];
      array[i] = NULL;
    }
  }
}

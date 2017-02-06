#ifndef VSARRAYLIST_H
#define VSARRAYLIST_H
#include "ADTList.h"

class VSArrayList : public ADTList{
private:
  int current_capacity;
  int delta;
  void resize();
  Object** array;

public:
  VSArrayList(int);
  VSArrayList(int,int);
  virtual ~VSArrayList();
  virtual bool insert(Object*, int);
  virtual Object* remove(int);
  virtual Object* first() const;
  virtual Object* last() const;
  virtual void clear();
  virtual int indexOf(Object*) const;
  virtual Object* get(int) const;
  virtual int capacity() const;
  virtual bool isEmpty() const;
  virtual bool isFull() const;
};
#endif

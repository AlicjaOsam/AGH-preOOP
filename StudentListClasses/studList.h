#include <iostream>
#pragma once

class StudList;

class Element {
  public:
  friend class StudList;
  Element(char* );
  ~Element();
  char* getName();
  void printName();
  private:
  char* _n;
  Element *_next;
};

class StudList {
  public:
  StudList(char* );
  ~StudList();
  void prepend(char* );
  void prepend(Element* );
  Element* getHead();
  Element* getTail();
  char* getName() const;
  bool isEmpty() const;
  void print() const;
  Element* getLast();
  void clearList();
  void removeLast();
  private:
  char *_name;
  Element* _head;
  Element* _tail;
};

char* mycopy (const char* string);

int mystrlen (const char* string);
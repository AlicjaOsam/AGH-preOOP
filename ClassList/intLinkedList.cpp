#include <iostream>
#include "intLinkedList.h"

using std::cout;
using std::endl;

IntLinkedList::IntLinkedList(){
  _head = NULL;
  _tail = NULL;
}

IntLinkedList::~IntLinkedList(){
  Element *tmp = _head;
  Element *x = NULL;
  while(tmp != NULL){
    x = tmp->_next;
    delete tmp;
    tmp = x;
  }
  cout<<"Destruktor: "<<(isEmpty() ? "Lista pusta" : "Lista nie jest pusta")<<endl;
}

int IntLinkedList::size(){
  int s = 0;
  Element *tmp = new Element;
  tmp = _head;
  while(_tail != tmp){
    s += 1;
    tmp = tmp->_next;
  }
  delete tmp;
  return s;
} 

bool IntLinkedList::isEmpty(){
  if(_head == NULL){
    return 1;
  }else return 0;
}

void IntLinkedList::print(){
  cout<<"[";
  Element *tmp = new Element;
  tmp = _head;
  while(_tail != tmp){
    if(tmp->_next == _tail){
      cout<<tmp->_value;
    }else cout<<tmp->_value<<", ";
    tmp = tmp->_next;
  }
  cout<<"]"<<endl;
  delete tmp;
}

void IntLinkedList::removeLast(){
  Element *tmp = new Element;
  tmp = _head;
  if(tmp){
    if(tmp->_next){
      while(tmp->_next->_next){
        tmp = tmp->_next;
      }
      delete tmp->_next;
      tmp->_next = NULL;
    }
    else{
        delete tmp;
        _head = NULL;
    }
  }
}

void IntLinkedList::prepend(int value){
  Element *tmp = new Element;
  tmp->_value = value;
  tmp->_next = _head;
  _head = tmp;
}

bool IntLinkedList::contains(int value){
  Element *tmp = new Element;
  tmp = _head;
  while(_tail != tmp){
    if(tmp->_value == value){
      return 1;
    }
    tmp = tmp->_next;
  }
  delete tmp;
  return 0;
}



void IntLinkedList::removeValue(int value){
  Element *tmp = new Element;
  tmp = _head;
  if(_head->_value == value){
    if(tmp){
      _head = tmp->_next;
      delete tmp;
    }
  }
  else{
    while(tmp->_next->_value != value){
      tmp = tmp->_next;
    }
    tmp->_next = tmp->_next->_next;
    delete tmp->_next;
  }
}

void IntLinkedList::addSorted(int value){
  prepend(value);
}


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
}

int IntLinkedList::size(){
  int s = 0;
  Element *tmp = _head;
  while(tmp){
    s += 1;
    tmp = tmp->_next;
  }
  return s;
} 

bool IntLinkedList::isEmpty(){
  if(_head == NULL){
    return 1;
  }else return 0;
}

void IntLinkedList::print(){
  cout<<"[";
  Element *tmp = _head;
  while(tmp){
    if(tmp == _tail){
      cout<<tmp->_value;
    }else cout<<tmp->_value<<", ";
    tmp = tmp->_next;
  }
  cout<<"]"<<endl;
}

void IntLinkedList::removeLast(){ 
  Element *tmp = _head;
  if(tmp){
    if(tmp->_next){
      while(tmp->_next->_next){
        tmp = tmp->_next;
      }
      _tail = tmp;
      delete tmp->_next;
      _tail->_next = NULL;
    }
    else{
        delete tmp;
        _head = NULL;
        _tail = NULL;
    }
  }
}

void IntLinkedList::prepend(int value){
  Element *tmp = new Element;
  tmp->_value = value;
  if(_head == NULL){
    _head = tmp;
    _head->_next = NULL;
    _tail = tmp;
  }
  else{
    tmp->_next = _head;
    _head = tmp;
  }
}

bool IntLinkedList::contains(int value){
  Element *tmp = _head;
  while(_tail != tmp){
    if(tmp->_value == value){
      return 1;
    }
    tmp = tmp->_next;
  }
  return 0;
}

void IntLinkedList::removeFirst(int value){
  Element *tmp = _head;
  if(tmp){
    _head = tmp->_next;
    delete tmp;
  }
  if(!_head){
    _tail = NULL;
  }
}

void IntLinkedList::removeValue(int value){
  Element *tmp = _head;
  Element *current;
  if(_head->_value == value){
    removeFirst(value);
  }
  else if(_tail->_value == value){
    removeLast();
  }
  else{
    while(tmp->_next){
      if(tmp->_next->_value == value){
        current = tmp->_next;
        tmp->_next = tmp->_next->_next;
        delete current;
      }
      tmp = tmp->_next;
    }
  }
}

void IntLinkedList::addback(int value){
  Element *tmp = _head;
  while(tmp->_next != NULL){
    tmp = tmp->_next;
  }
	tmp->_next = new Element;
  tmp->_next->_value = value;
  _tail = tmp->_next;
  tmp->_next->_next = NULL;	
}

void IntLinkedList::addSorted(int value){
  if(_head == NULL){
    prepend(value);
  }
  else if(_tail->_value <= value){
    addback(value);
  }
  else{
    prepend(value);
  }
}


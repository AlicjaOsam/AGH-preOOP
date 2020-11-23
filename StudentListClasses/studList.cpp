#include "studList.h"

Element::Element(char* name){
  _next = NULL;
  _n = mycopy(name);
}

Element::~Element(){
  std::cout<<"Destruktor Element: "<<_n<<std::endl;
  delete [] _n;
}

char* Element::getName(){
  return _n;
}

void Element::printName(){
  std::cout<<_n;
}

StudList::StudList(char* name){
  _head = NULL;
  _tail = NULL;
  _name = mycopy(name);
}

StudList::~StudList(){
  clearList();
  std::cout<<"Destruktor StudList: "<<_name<<std::endl;
  delete [] _name;
}

void StudList::prepend(char* n){
  Element *tmp = new Element(n);
  tmp->_next = _head;
  if (_head == NULL) {
    _tail = tmp;
    _tail->_next = NULL;
  }
  _head = tmp;
}

void StudList::prepend(Element *tmp){
  tmp->_next = _head;
  if (_head == NULL) {
    _tail = tmp;
    _tail->_next = NULL;
  }
  _head = tmp;
}

Element* StudList::getHead(){
  return _head;
}

Element* StudList::getTail(){
  return _tail;
}

char* StudList::getName() const{
  return _name;
}

bool StudList::isEmpty() const{
  if (_head == NULL) {
    return 1;
  }
  else{
    return 0;
  }
}

void StudList::print() const{
  std::cout<<_name<<" = "<<"[";
  Element *tmp = _head;
  while(tmp){
    if(tmp == _tail){
      std::cout<<tmp->_n;
    }else{
      std::cout<<tmp->_n<<" ";
    }
    tmp = tmp->_next;
  }
  std::cout<<"]"<<std::endl;
}

Element* StudList::getLast(){
  Element *tmp = _head;
  Element *x;
  if(tmp){
    if(tmp->_next){
      while(tmp->_next->_next){
        tmp = tmp->_next;
      }
      _tail = tmp;
      x = tmp->_next;
      _tail->_next = NULL;
      return x;
    }
    else{
      _head = NULL;
      _tail = NULL;
      x = tmp;
      return x;
    }
  }
}

void StudList::clearList(){
  Element *tmp = _head;
  Element *x = NULL;
    while(tmp != NULL){
    x = tmp->_next;
    delete tmp;
    tmp = x;
  }
  _head = NULL;
  _tail = NULL;
}

void StudList::removeLast(){
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

int mystrlen (const char* string){
  int i = 0;
  while(*(string+i) != '\0'){
    i++;
  }
  return i;
}

char* mycopy (const char* string){
  char *x;
  int j = mystrlen(string);
  x = new char[j];
  int i = 0;
  while(*(string+i) != '\0'){
    *(x+i) = *(string+i);
    i++;
  }
  return x;
}
#include <iostream>
#include <cstring>
#include "studList.h"

using std::cout;
using std::endl;

void initList(StudList* list, char* n){
  list->head = NULL;
  list->tail = NULL;
  int l = strlen(n)+1;
  char* sptr = new char[l];
  strcpy(sptr, n);
  list->name = (char*)sptr;
}

void prepend(StudList* list, char* n){
  Element *tmp = new Element;
  int l = strlen(n)+1;
  char* sptr = new char[l];
  strcpy(sptr, n);
  tmp->name = (char*)sptr;
  tmp->next = list->head;
  if(list->head == NULL){
    list->tail = tmp;
    list->tail->next = NULL;
  }
  list->head = tmp;
}

bool isEmpty(const StudList* list){
  if(list->head == NULL){
    return 1;
  }else return 0;
}

void print(const StudList* list){
  cout<<list->name<<" = "<<"[";
  Element *tmp = list->head;
  while(tmp){
    if(tmp == list->tail){
      cout<<tmp->name;
    }else{
      cout<<tmp->name<<" ";
    }
    tmp = tmp->next;
  }
  cout<<"]"<<endl;
}

void removeLast(StudList* list){
  Element *tmp = list->head;
  if(tmp){
    if(tmp->next){
      while(tmp->next->next){
        tmp = tmp->next;
      }
      list->tail = tmp;
      delete [] tmp->next->name;
      delete tmp->next;
      list->tail->next = NULL;
    }
    else{
      delete [] tmp->name;
      delete tmp;
      list->head = NULL;
      list->tail = NULL;
    }
  }
}

void clearList(StudList* list){
  Element *tmp = list->head;
  Element *x = NULL;
  while(tmp != NULL){
    x = tmp->next;
    delete [] tmp->name;
    delete tmp;
    tmp = x;
  }
  list->head = NULL;
  list->tail = NULL;
}

void removeList(StudList* list){
  clearList(list);
  cout<<"Kasowanie "<<list->name<<endl;
  delete [] list->name;
}
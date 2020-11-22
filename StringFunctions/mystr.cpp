#include <iostream>
#include "mystr.h"

void initMyString(MyString* mystring, char* string, char* sep){
  char* text = mycopy(string);
  mystring->next = text;
  mystring->begin = text;
  mystring->end = &text[mystrlen(text)];
  mystring->sep = sep;
}

char* mystrtok(MyString* mystring){
  char* tmp = mystring->next;
  char* begin = mystring->next;
  while(!findSep(*tmp, mystring->sep) && tmp != mystring->end){
    tmp++;
  }
  if(tmp == mystring->end){
    mystring->next = tmp;
    return begin;
  }
  *tmp = '\0';
  tmp++;
  while(findSep(*tmp, mystring->sep)){
    tmp++;
  }
  mystring->next = tmp;
  return begin;
}

char* mystrcat (char* x, char* y, char z){
  int a = mystrlen(x) + mystrlen(y) + 1;
  char *cat;
  cat = new char[a];
  int i = 0;
  while(*(x+i) != '\0'){
    *(cat+i) = *(x+i);
    i++;
  }
  *(cat+i) = z;
  i++;
  int j = 0;
  while(*(y+j) != '\0'){
    *(cat+i) = *(y+j);
    i++;
    j++;
  }
  return cat;
}

void addSep(MyString* mystring, char* sep){
  mystring->sep = sep;
}

void split2list(StudList* list, MyString* mystring){
  while(mystring->next != mystring->end){
    append(list, mystrtok(mystring));
  }
}

void removeMyString(MyString* mystring){
  delete [] mystring->begin;
}


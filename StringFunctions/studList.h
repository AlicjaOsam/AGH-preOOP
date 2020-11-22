#include <iostream>
#pragma once

struct Element {
  char* name;
  Element *next;
};

struct StudList {
  char *name;
  Element* head;
  Element* tail;
};

void initList (StudList* list,const char* name);

bool isEmpty (const StudList* list);

void append(StudList* list,const char* name);

void print(const StudList* list);

void removeFirst(StudList * l);

void clearList (StudList * l);

void removeList (StudList * l);

char* mycopy (const char* string);

int mystrlen (const char* string);

bool findSep(char, const char* string);
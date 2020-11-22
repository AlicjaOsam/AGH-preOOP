#include "studList.h"

struct MyString{
  char* begin;
  char* end;
  char* next;
  char* sep;
};

void initMyString(MyString*, char*, char* = NULL);

char* mystrtok(MyString* );

char* mystrcat (char* , char* , char = ' ');

void addSep(MyString* , char* );

void split2list(StudList* , MyString* );

void removeMyString(MyString* mystring);

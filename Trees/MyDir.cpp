#include <iostream>
#include "MyDir.h"

void initDir(MyDir& mydir, const std::string name){
  if(name.length()>10){
    std::cout<<"Za dluga nazwa "<<name<<std::endl;
  }
  else if(name.length()<1){
    std::cout<<"Za krotka nazwa"<<std::endl;
  }
  else{
    mydir.parent = NULL;
    mydir.number = 0;
    mydir.name = name;
  }
}

void printDir(MyDir& mydir, int deep){
  if(deep == 0){
    std::cout<<mydir.name<<std::endl;
  }
  if(mydir.number == 0){
    return;
  }
  for(int i=0; i<mydir.number; i++){
    for(int j=0; j<deep; j++){
      std::cout<<"   ";
    }
    if(mydir.children[i]->name != ""){
      std::cout<<"|__"<<mydir.children[i]->name<<std::endl;
    }
    printDir(*mydir.children[i], deep+1);
  }
}

MyDir* addDir(MyDir& mydir, const std::string name){
  MyDir *child = new MyDir;
  initDir(*child, name);
  child->parent = &mydir;
  mydir.children[mydir.number] = child;
  mydir.number += 1;
  return child;
}

MyDir* addDir(MyDir& mydir1, MyDir& mydir2){
  mydir2.parent = &mydir1;
  mydir1.children[mydir1.number] = &mydir2;
  mydir1.number += 1;
  return &mydir2;
}

void clearDir(MyDir* mydir){
  if(mydir->number == 0){
    delete mydir;
    return;
  }
  for(int i=0; i<mydir->number; i++){
  mydir->number -= 1;
  clearDir(mydir->children[i]);
  }
  if(mydir->number == 0){
    mydir->parent->number = 0;
  }
}
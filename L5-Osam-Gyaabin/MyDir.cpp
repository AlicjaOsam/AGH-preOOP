#include "MyDir.h"
#include <iostream>

void initDir(MyDir& md, char* s){
  md.up = NULL;
  md.child = NULL;
  md.n = 0;
  md.str = (char*)s;
  md.deep = 0;
}

void print(MyDir& md){
  int j = 0;
  while(j < md.n){
    for(int i=0; i<md.deep; i++){
      std::cout<<"  ";
    }
    std::cout<<"|__"<<md.child[j].str<<std::endl;
    print(md.child[j]);
    j++;
  }
}

void printDir(MyDir& md){
  std::cout<<md.str<<std::endl;
  if(md.n == 0){
    std::cout<<"Za krotka nazwa";
  }
  print(md);
}

MyDir* addDir(MyDir& md, char* s){
  if(md.deep == 0){
    md.deep += 1;
  }
  int l = 0;
  while(s[l] != '\0'){
    l++;
  }
  if(l > 10){
    std::cout<<"Za dluga nazwa: "<<s;
    return 0;
  }
  if(l == 0){
    return 0;
  }
  MyDir *tmp = new MyDir[md.n];
  for(int i=0; i<md.n; i++){
    tmp[i] = md.child[i];
  }
  md.n += 1;
  int a = md.n-1;
  delete [] md.child;
  md.child = new MyDir[md.n];
  md.child = tmp;
  md.child[a].up = &md;
  md.child[a].str = (char*)s;
  md.child->deep += 1;
  return md.child;
}

MyDir* addDir(MyDir& md, MyDir pmd){
  /*if(md.deep == 0){
    md.deep += 1;
  }*/
  md.n += 1;
  md.child = new MyDir[1];
  md.child = &pmd;
  md.child[0].up = &md;
  //md.child->deep += 1;
  return md.child;
}

void clear(MyDir& md){
  delete [] md.child;
  /*int j = 0;
  while(j < md.n){
    for(int i=0; i<md.deep; i++){
      std::cout<<"  ";
    }
    std::cout<<"|__"<<md.child[j].str<<std::endl;
    print(md.child[j]);
    j++;
  }*/
}

void clearDir(MyDir* md){
  //while()
}
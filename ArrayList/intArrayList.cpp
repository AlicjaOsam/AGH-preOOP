#include "intArrayList.h"
#include <iostream>

#define MaxTab 11

using std::cout;
using std::endl;

IntArrayList::IntArrayList(){
  _maxSize = MaxTab;
  _size = 0;
  _tab = new int[MaxTab];
}

IntArrayList::IntArrayList(int maxSize){
  _maxSize = maxSize;
  _size = 0;
  _tab = new int[maxSize];
}

IntArrayList::~IntArrayList(){
  _size = 0;
  delete [] _tab;
}

void IntArrayList::add(int a){
    if(_size < _maxSize){
        _tab[_size] = a;
    }
    _size += 1;
}

void IntArrayList::add(int *tab, int a){
    int rest = _maxSize - _size;
    rest += 1;
    int n = _size + a;
    int j = 0;
    if(rest > a){
        for(int i=_size; i<n; i++){
            _tab[i] = *(tab+j);
            j++;
            _size += 1;
        }
    }
}

void IntArrayList::add(int a, int b){
    if(_size < _maxSize){
        for(int i=_size; i>a; i--){
            _tab[i] = _tab[i-1];
        }
        _tab[a] = b;
    }
    _size += 1;
}

void IntArrayList::add(int a, bool b){
  add(a);
    if(b == true){
      int x, j;
     for(int i=1; i<_size; i++)
     {
        x = _tab[i];
        j = i-1;
        while(j>=0 && _tab[j]>x) {
          _tab[j+1] = _tab[j]; 
          --j;
        }
         _tab[j+1] = x;
     }   
    }
}

void IntArrayList::print(){
    cout<<"[";
    for(int i=0; i<_size-1; i++){
        cout<<_tab[i]<<", ";
    }
    cout<<_tab[_size-1]<<"]"<<endl;
}

int IntArrayList::find(int a){
    for(int i=0; i<_size; i++){
        if(_tab[i] == a){
            return i;
        }
    }
    return -1;
}

void IntArrayList::printFind(int a){
    int b = find(a);
    cout<<"Wartosc="<<a;
    if(b>0){
        cout<<"  Indeks="<<b<<endl;
    }
    else{
        cout<<"  Element nieznaleziony"<<endl;
    }
}

void IntArrayList::remove(int a){
  int c;
  for(int i=0; i<_size; i++){
    if(_tab[i] == a){
      c = i;
      break;
    }
  }
  _size -= 1;
  for(int i=c; i<_size; i++){
      _tab[i] = _tab[i+1];
  }
}

void IntArrayList::remove(int a, int b){
  int c;
  for(int i=0; i<_size; i++){
    if(_tab[i] == a){
      c = i;
      break;
    }
  }
  _size -= b;
  for(int i=c; i<_size; i++){
      _tab[i] = _tab[i+b];
  }
}
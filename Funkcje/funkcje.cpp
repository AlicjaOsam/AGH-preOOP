#include <iostream>
#include "funkcje.h"

using namespace std;

int silnia(int n){
  int x = n;
  if(x == 0){
    return 1;
  }
  if(x < 0){
    cout<<"brak rozwiazania ";
    return -1;
  }
  for(int i=1; i<n; i++){
    x *= i;
  }
  return x;
}

int silnia_rec(int n){
  int x = n;
  if(x < 0){
    cout<<"brak rozwiazania ";
    return -1;
  }
  if(x < 2){
    return 1;
  }
  else return x*silnia_rec(x-1);
}

void wypisz(double *a, int n){
  for(int i=0; i<n; i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
}

void powiel(double *a, double f, int n){
  for(int i=0; i<n; i++){
    a[i] *= f;
  }
}

double suma(double *a, const int n){
  double s = a[0];
  for(int i=1; i<n; i++){
    s += a[i];
  }
  return s;
}

double srednia(double *a, const int n){
  double sr = suma(a, n)/n;
  return sr;
}
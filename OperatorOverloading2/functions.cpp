#include <iostream>
#include "functions.h"

Linear::Linear(double a, double b){
  _a = a;
  _b = b;
}

Sin::Sin(double a, double b){
  _a = a;
  _b = b;
}

std::ostream &operator<<(std::ostream &o, const Linear &l){
  return o <<l._a<<"*x^2+"<<l._b<<"*x";
}
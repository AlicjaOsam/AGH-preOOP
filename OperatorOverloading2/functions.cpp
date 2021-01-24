#include "functions.h"

Linear::Linear(double a, double b){
  _a = a;
  _b = b;
}

double Linear::operator() (const double &x) const{
  return _a*x+_b;
}

double Sqrt::operator() (const double& x) const{
  return sqrt(x);
}

Sin::Sin(double a, double b){
  _a = a;
  _b = b;
}

double Sin::operator() (const double& x) const{
  return sin(_a*x+_b);
}

std::ostream &operator<<(std::ostream &o, const Linear &l){
  return o <<l._a<<"*x^2+"<<l._b<<"*x";
}
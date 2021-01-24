#include <iostream>
#include <cmath>
#include "Vector.h"

Vector::Vector(int n){
  _n = n;
  _v = new double[_n];
  for(int i=0; i<n; i++){
    _v[i] = 0;
  }
}

Vector::Vector(Vector& v){
  _n = v._n;
  _v = new double[_n];
  for(int i=0; i<_n; i++){
    _v[i] = std::move(v._v[i]);
  }
}

Vector::Vector(Vector&& v){
  _n = std::move(v._n);
  _v = new double[_n];
  for(int i=0; i<_n; i++){
    _v[i] = v._v[i];
  }
}

Vector::~Vector(){
  _n = 0;
  delete [] _v;
}

double& Vector::at(int a) const{
  return _v[a];
}

void Vector::print(std::string s) const{
  std::cout<<s<<"(";
  for(int i=0; i<_n-1; i++){
    std::cout<<_v[i]<<", ";
  }
  std::cout<<_v[_n-1]<<")"<<std::endl;
}

double Vector::dot(const Vector& v1, const Vector& v2){
  double d = 0;
  for(int i=0; i<v1._n; i++){
    d += v1.at(i)*v2.at(i);
  }
  return d;
}

Vector::operator double() const{
  return norm();
}

double Vector::norm() const{
  double n = 0;
  for(int i=0; i<_n; i++){
    n += _v[i]*_v[i];
  }
  return sqrt(n);
}

Vector Vector::sum(const Vector& v1, const Vector& v2){
  Vector v(v1._n);
  for(int i=0; i<v._n; i++){
    v.at(i) = v1.at(i) + v2.at(i);
  }
  return v;
}

Vector Vector::sum(const Vector& v1, int k){
  Vector v(v1._n);
  for(int i=0; i<v._n; i++){
    v.at(i) += k;
  }
  return sum(v, v1);
}
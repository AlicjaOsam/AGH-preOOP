#include <iostream>
#include <cmath>
#include "Vector2D.h"

Vector2D::~Vector2D(){
  count -= 1;
}

Vector2D::Vector2D(Vector2D &&v){
  count += 1;
  std::cout<<"--- przenoszenie "<<v._name<<"=("<<v._x<<", "<<v._y<<")"<<std::endl;
  _name = std::move(v._name);
  _x = std::move(v._x);
  _y = std::move(v._y);
  v._x = 0;
  v._y = 0;
}

Vector2D::Vector2D(const Vector2D &v){
  std::cout<<"--- kopiowanie "<<v._name<<"=("<<v._x<<", "<<v._y<<")"<<std::endl;
  count += 1;
  _name = v._name;
  _x = v._x;
  _y = v._y;
}

void Vector2D::print(std::string str) const{
  std::cout<<str<<_name<<"=("<<_x<<", "<<_y<<")"<<std::endl;
}

double Vector2D::dot(const Vector2D& v) const{
  return  _x*v._x+_y*v._y;
}

Vector2D Vector2D::add(const Vector2D& v) const{
  return  Vector2D("Vx", _x + v._x, _y + v._y);
}

Vector2D Vector2D::fromCarthesian(std::string name, double x, double y){
  return Vector2D(name, x, y);
}

Vector2D Vector2D::fromPolar(std::string name, double r, double phi){
  return Vector2D(name, r*cos(phi*M_PI/180), r*sin(phi*M_PI/180));
}

Vector2D Vector2D::fromCarthesian(double x, double y){
  return Vector2D("Vx", x, y);
}
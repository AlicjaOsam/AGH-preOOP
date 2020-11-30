#include <iostream>
#include "MapPoint.h"
#include "MapDist.h"
#include "cmath"

using namespace std;

MapPoint::MapPoint(){
}

MapPoint::MapPoint(const char* name, const double longitude, const double latitude){
  _name = (char*)name;
  _longitude = longitude;
  _latitude = latitude;
  if(longitude > 0){
    _directx = 'E';
  }else _directx = 'W';
  if(latitude > 0){
    _directy = 'N';
  }else _directy = 'S';
}

MapPoint::MapPoint(const char* name, double longitude, char directx, double latitude, char directy){
  _name = (char*)name;
  if(directx == 'W'){
    longitude = -longitude;
  }
  if(directy == 'S'){
    latitude = -latitude;
  }
  _longitude = longitude;
  _latitude = latitude;
  _directx = directx;
  _directy = directy;
}

void MapPoint::print() const{
  cout<<"Wspolrzedne dla "<<_name<<": ";
  if(_directx == 'W'){
    cout<<-_longitude;
  }else cout<<_longitude;
  cout<<_directx<<", ";
  if(_directy == 'S'){
    cout<<-_latitude;
  }else cout<<_latitude;
  cout<<_directy<<endl;
}

void MapPoint::movePoint(const double x, const double y){
  _longitude += x;
  _latitude += y;
  if(_longitude > 0){
    _directx = 'E';
  }else _directx = 'W';
  if(_latitude > 0){
    _directy = 'N';
  }else _directy = 'S';
}

char* MapPoint::getName() const{
  return _name;
}

MapPoint MapPoint::closestPlace(MapPoint* p1, MapPoint* p2){
  double a = _longitude - p1->_longitude;
  double b = _latitude - p1->_latitude;
  if(a < 0){
    a = -a;
  }
  if(b < 0){
    b = -b;
  }
  double c = _longitude - p2->_longitude;
  double d = _latitude - p2->_latitude;
  if(c < 0){
    c = -c;
  }
  if(d < 0){
    d = -d;
  }
  const double d1 = sqrt(a*a + b*b);
  const double d2 = sqrt(c*c + d*d);
  MapPoint point;
  if(d1 < d2){
    point._name = p1->_name;
  }else point._name = p2->_name;
  return point;
}

MapPoint inTheMiddle(MapPoint* p1, const MapPoint* p2, char* name){
  MapPoint point;
  point._name = (char*)name;
  point._longitude = (p1->_longitude + p2->_longitude)/2;
  point._latitude = (p1->_latitude + p2->_latitude)/2;
  if(point._longitude > 0){
    point._directx = 'E';
  }else point._directx = 'W';
  if(point._latitude > 0){
    point._directy = 'N';
  }else point._directy = 'S';
  return point;
}

MapPoint::~MapPoint(){
  cout<<"Usuwanie "<<_name<<endl;
}

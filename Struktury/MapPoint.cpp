#include <iostream>
#include "MapPoint.h"
#include "MapDist.h"

using namespace std;

MapPoint *construct(const char* n, const double x, const double y){//EOM edit const
  struct MapPoint *point = new MapPoint;
  point->name = (char*)n;
  point->longitude = x;
  point->latitude = y;
  if(x > 0){
    point->directx = 'E';
  }else point->directx = 'W';
  if(y > 0){
    point->directy = 'N';
  }else point->directy = 'S';
  return point;
}

MapPoint *construct(char* n, double x, char a, double y, char b){//EOM edit const
  struct MapPoint *point = new MapPoint;
  point->name = (char*)n;
  if(a == 'W'){
    x += 2*(-x);
  }
  if(b == 'S'){
    y += 2*(-y);
  }
  point->longitude = x;
  point->latitude = y;
  point->directx = a;
  point->directy = b;
  return point;
}

void print(const MapPoint *p){
  double x = p->longitude;
  double y = p->latitude;
  if(x < 0){
    x += 2*(-x);
  }
  if(y < 0){
    y += 2*(-y);
  }
  cout<<"Wspolrzedne dla "<<p->name<<": "<<x<<p->directx<<", "<<y<<p->directy<<endl;
}

void movePoint(MapPoint* p, const double n_x, const double n_y){
  p->longitude += n_x;
  p->latitude += n_y;
  if(p->longitude > 0){
    p->directx = 'E';
  }else p->directx = 'W';
  if(p->latitude > 0){
    p->directy = 'N';
  }else p->directy = 'S';
}

MapPoint inTheMiddle(MapPoint* p1, const MapPoint* p2, char* n){
  MapPoint point;
  point.name = n;
  point.longitude = (p1->longitude + p2->longitude)/2;
  point.latitude = (p1->latitude + p2->latitude)/2;
  if(point.longitude > 0){
    point.directx = 'E';
  }else point.directx = 'W';
  if(point.latitude > 0){
    point.directy = 'N';
  }else point.directy = 'S';
  return point;
}

char* getName(const MapPoint p){
  return p.name;
}

MapPoint closestPlace(MapPoint* p1, MapPoint* p2, MapPoint* p3){
  MapPoint point;
  const double d1 = angularDistance(distance(*p1, *p2));
  const double d2 = angularDistance(distance(*p1, *p3));
/*  const MapDist d1 = distance(p1, p2); //EOM tak nie można podstawić, jeśli już to const double d1 = angularDistance(distance(*p1, *p2));
  const MapDist d2 = distance(p1, p3);*/
  if(d1 < d2){
    point.name = p2->name;
  }else point.name = p3->name;
  return point;
}

void clear (MapPoint* p){
  cout<<"Usuwanie "<<p->name<<endl;
  delete p;
}//EOM edit
void clear (MapPoint* p1,MapPoint* p2,MapPoint* p3){
  clear(p1);
  clear(p2);
  clear(p3);
}//EOM edit

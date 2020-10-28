#include "MapDist.h"
#include "MapPoint.h"
#include "cmath"

MapDist distance(MapPoint p1, MapPoint p2){
  MapDist point;
  point.longitude = p1.longitude - p2.longitude;
  point.latitude = p1.latitude - p2.latitude;
  if(point.longitude < 0){
    point.longitude += 2*(-point.longitude);
  }
  if(point.latitude < 0){
    point.latitude += 2*(-point.latitude);
  }
  return point;
}

double angularDistance(const MapDist p){ 
  return sqrt(p.longitude*p.longitude + p.latitude*p.latitude);
}

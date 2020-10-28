#include "MapDist.h"
#include "MapPoint.h"
#include "cmath"

MapDist distance(MapPoint p1, MapPoint p2){
  MapDist point;
  point.longitude = p1.longitude - p2.longitude;
  point.latitude = p1.latitude - p2.latitude;
  return point;
}

double angularDistance(const MapDist p){ 
  return sqrt(p.longitude*p.longitude + p.latitude*p.latitude);
}

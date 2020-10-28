#include "MapDist.h"
#include "MapPoint.h"
#include "cmath"

MapDist distance(MapPoint p1, MapPoint p2){//EOM tu nie może być const bo tworzymy obiekt
  MapDist point;
  point.longitude = p1.longitude - p2.longitude;
  point.latitude = p1.latitude - p2.latitude;
  return point;
}

double angularDistance(const MapDist p){ //EOM EDIT const
  return sqrt(p.longitude*p.longitude + p.latitude*p.latitude);
}

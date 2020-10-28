#include "MapPoint.h"

struct MapDist{
  double longitude;
  double latitude;
}; 
MapDist distance(MapPoint, MapPoint);
double angularDistance(const MapDist);

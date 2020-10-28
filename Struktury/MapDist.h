#include "MapPoint.h"

struct MapDist{
  double longitude;
  double latitude;
}; //dlaczego tu nie definicji struktury?
MapDist distance(MapPoint, MapPoint);//EOM EDIT const
double angularDistance(const MapDist);//EOM EDIT const
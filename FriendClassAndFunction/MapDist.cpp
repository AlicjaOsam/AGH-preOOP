#include "MapDist.h"
#include "MapPoint.h"
#include "cmath"

MapDist::MapDist(){
}

MapDist::MapDist(MapPoint& p1, MapPoint& p2){
  _longi = p1._longitude - p2._longitude;
  _lati = p1._latitude - p2._latitude;
  if(_longi < 0){
    _longi = -_longi;
  }
  if(_lati < 0){
    _lati = -_lati;
  }
}

double MapDist::getlongitude() const{
  return _longi;
}

double MapDist::getlatitude() const{
  return _lati;
}

double MapDist::angularDistance() const{ 
  return sqrt(_longi*_longi + _lati*_lati);
}

MapDist distance(MapPoint& p1, MapPoint& p2){
  MapDist point;
  point._longi = p1._longitude - p2._longitude;
  point._lati = p1._latitude - p2._latitude;
  if(point._longi < 0){
    point._longi = -point._longi;
  }
  if(point._lati < 0){
    point._lati = -point._lati;
  }
  return point;
}


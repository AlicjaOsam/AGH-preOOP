#include "MapPoint.h"

class MapDist{
  public:
    MapDist();
    MapDist(MapPoint&, MapPoint&);
    friend MapDist distance(MapPoint& p1, MapPoint& p2);
    double getlongitude() const;
    double getlatitude() const;
    double angularDistance() const;
  private:
    double _longi;
    double _lati;
}; 

MapDist distance(MapPoint& p1, MapPoint& p2);

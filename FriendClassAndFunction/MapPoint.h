#pragma once

class MapDist;

class MapPoint{
  public:
    friend class MapDist;
    friend MapDist distance(MapPoint& , MapPoint& );
    MapPoint();
    MapPoint(const char* , const double , const double );
    MapPoint(const char* , double , char , double , char );
    ~MapPoint();
    void print() const;
    void movePoint(const double, const double);
    char* getName() const;
    friend MapPoint inTheMiddle(MapPoint* , const MapPoint*, char*);
    MapPoint closestPlace(MapPoint*, MapPoint*);
  private:
    char *_name;
    double _longitude;
    double _latitude;
    char _directx;
    char _directy;
}; 

MapPoint inTheMiddle(MapPoint* , const MapPoint*, char*);

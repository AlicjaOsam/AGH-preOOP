#pragma once

struct MapPoint{
  char *name;
  double longitude;
  double latitude;
  char directx;
  char directy;
}; 
MapPoint *construct(const char* , const double , const double);
MapPoint *construct(char* , double, char , double, char);
void print(const MapPoint*);
void movePoint(MapPoint* , const double, const double);
MapPoint inTheMiddle(MapPoint* , const MapPoint*, char*);
char* getName(const MapPoint);
MapPoint closestPlace(MapPoint*, MapPoint*, MapPoint*);
void clear (MapPoint*);
void clear (MapPoint*,MapPoint*,MapPoint*);

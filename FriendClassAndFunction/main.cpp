#include <iostream>
#include "MapPoint.h"
#include "MapDist.h"

int main() {
  const double longitude = 19.938333;
  const double latitude = 50.061389;
  MapPoint krakow("Krakow", longitude, latitude); //kierunki E N
  krakow.print();
  MapPoint* nyc = new MapPoint("Nowy Jork", 74.0059, 'W', 40.7127, 'N' );
  nyc->print();
  MapPoint sydney("Sydney", 151.102, -33.454); // kierunki E i S jak ujemna to S
  sydney.print();
  MapPoint* porto   = new MapPoint("Porto", 41.162142, 8.621953); // kierunki E i N
  const MapPoint& portugalCity = *porto;
  portugalCity.print();

  const double longitudeShift = 4.1234;
  const double latitudeShift = -25.987;
  std::cout << "*** Po przesunieciu ***\n";
  porto->movePoint (longitudeShift, latitudeShift);
  portugalCity.print();
  std::cout << "*** Po przesunieciu ***\n";
  porto->movePoint (-90.5710, 34.7300);
  portugalCity.print();

  const MapDist d = distance(*nyc, sydney);
  const MapDist d1 (*nyc, sydney); //to samo co distance
  std::cout <<"Odleglosci miedzy NYC i Sydney: \nRoznica dlugosci: " << d1.getlongitude() << "\nRoznica szerokosci: "<< d1.getlatitude() << "\nOdleglosc: "<<d.angularDistance() << std::endl;

  const MapPoint& cl = krakow.closestPlace(nyc, &sydney);
  std::cout << "Blizej Krakowa jest " << cl.getName() << std::endl;

  MapPoint mp = inTheMiddle(nyc, &sydney, "Kenia");
  mp.print();

  std::cout << "*** Czyszczenie ***\n";
  // Tu wywołują się destruktory
  delete nyc;
  delete porto;
}

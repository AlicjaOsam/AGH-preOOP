#include "point.h"

using namespace std;

int main() {

   Point krakow("Krakow",19.938333,50.0614),
         tarnow("Tarnow",20.9889,50.0139),
         poznan("Poznan",16.9211,52.4144),
         batorska("Wola Batorska",20.259722,50.0614),
         zielonki("Zielonki",19.938333,50.118611),
         nyc("Nowy Jork", -74.0059,40.7127),
         kopia(batorska),
         noname(23.0124,45.4523),pusty;

   pusty.fullPrint();
   noname.fullPrint();
   krakow.fullPrint();
   poznan.fullPrint();
   tarnow.fullPrint();
   nyc.fullPrint();
   zielonki.fullPrint();
   batorska.fullPrint();
   kopia.fullPrint();
   kopia.changeName("Nowa Batorska");
   kopia.move(-50,-30);
   kopia.fullPrint();
   Point nowy=std::move(kopia);
   nowy.fullPrint();
   kopia.fullPrint();

   cout<<"X="<<compareX(poznan,krakow)<<" Y="<<compareY(poznan,krakow)<<" XY="<<compareXY(poznan,krakow)<<endl;
   directions(poznan,krakow,compareX);
   directions(poznan,krakow,compareY);
   directions(poznan,krakow,compareXY);
   cout<<"X="<<compareX(tarnow,krakow)<<" Y="<<compareY(tarnow,krakow)<<" XY="<<compareXY(tarnow,krakow)<<endl;
   directions(tarnow,krakow,compareX);
   directions(tarnow,krakow,compareY);
   directions(tarnow,krakow,compareXY);
   cout<<"X="<<compareX(poznan,nyc)<<" Y="<<compareY(poznan,nyc)<<" XY="<<compareXY(poznan,nyc)<<endl;
   directions(poznan,nyc,compareX);
   directions(poznan,nyc,compareY);
   directions(poznan,nyc,compareXY);
   cout<<"X="<<compareX(nyc,krakow)<<" Y="<<compareY(nyc,krakow)<<" XY="<<compareXY(nyc,krakow)<<endl;
   directions(nyc,krakow, compareX);
   directions(nyc,krakow, compareY);
   directions(nyc,krakow, compareXY);
   cout<<"X="<<compareX(krakow,zielonki)<<" Y="<<compareY(krakow,zielonki)<<" XY="<<compareXY(krakow,zielonki)<<endl;
   directions(krakow,zielonki,compareX);
   directions(krakow,zielonki,compareY);
   directions(krakow,zielonki,compareXY);
   cout<<"X="<<compareX(krakow,batorska)<<" Y="<<compareY(krakow,batorska)<<" XY="<<compareXY(krakow,batorska)<<endl;
   directions(krakow,batorska,compareX);
   directions(krakow,batorska,compareY);
   directions(krakow,batorska,compareXY);
   directions(krakow,nowy,compareXY);
   return 0;
}
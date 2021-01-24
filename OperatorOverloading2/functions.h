#include <iostream>
#include <cmath>
#pragma once

//klasa reprezentująca funkcję liniową
class Linear{
  public:
    //operator <<
    friend std::ostream &operator<<(std::ostream &o, const Linear &l);
    //konstruktor
    Linear(double, double);
    //oprerator ()
    double operator() (const double& x) const;

  private:
    //a*x+b
    double _a;
    double _b;
};

class Sqrt{
  public:
    //operator ()
    double operator() (const double& x) const;
};

class Sin{
  public:
    //operator ()
    double operator() (const double& x) const;
    //konstruktor
    Sin(double, double);

  private:
    //sin(a*x+b)
    double _a;
    double _b;
};
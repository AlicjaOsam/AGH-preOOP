#include <iostream>
#include <cmath>
#pragma once

class FunctionVector;

class Linear{
  public:
    friend class functionVector;
    friend std::ostream &operator<<(std::ostream &o, const Linear &l);

    Linear(double, double);

    double operator() (double x){
      return _a*x+_b;
    }

  private:
    double _a;
    double _b;
};

class Sqrt{
  public:
    friend class functionVector;

    double operator() (double x) const{
      return sqrt(x);
    }
};

class Sin{
  public:
    friend class functionVector;

    double operator() (double x){
      return sin(_a*x+_b);
    }

    Sin(double, double);

  private:
    double _a;
    double _b;
};
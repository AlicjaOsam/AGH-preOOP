#include "functions.h"
#include <vector>
#include <functional>
#include <iostream>
#pragma once

class FunctionVector{
  public:
    //funkcja dodająca obiekt funkcyjny do wektora
    void insert(std::function<double(double)>);
    //funkcja zwracająca końcowy wynik obliczeń
    double calc(double);
    //operator [] zwracający wynik pośrednich obliczeń
    double operator[](const int);

  private:
    //wektor obiektów funkcyjnych
    std::vector <std::function<double(double)>> _v;
    //wektor wyników pośrednich obliczeń
    std::vector <double> _result;
};
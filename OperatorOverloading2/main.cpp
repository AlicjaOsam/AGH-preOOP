#include "functions.h"
#include "functionVector.h"
#include <iostream>
#define _USE_MATH_DEFINES

double my_abs(double x){
	return x>=0 ? x : -x;
}

int main ()
{  
  std::cout <<std::endl;
  Linear lin(-0.25, -1.);
  std::cout << "f(x) = " << lin << std::endl;
  const Sqrt squareroot;
  Sin sinus(M_PI, M_PI/3.);

  double x = 10;
  std::cout << "\n*** Wyniki pojedynczych funkcji dla x=10 *** \n" << std::endl;
  std::cout << "Sinus:\t\t" << sinus(x) << std::endl; 
  std::cout << "Pierwiastek:\t" << squareroot(x) << std::endl; 
  std::cout << "Funkcja liniowa: " << lin(x) << std::endl; 

  
  FunctionVector fs;
  fs.insert(sinus);
  fs.insert(squareroot);
  fs.insert(lin);
  fs.insert(my_abs);
  
  double result1 = fs.calc(x);
  double result2 = my_abs(lin(squareroot(sinus(x))));
  std::cout << "\n*** Obliczamy abs(-0.25*sqrt(sin(pi*x+pi/3))+1) *** \n" << std::endl;
  std::cout << "--- Dla x=10 :\t" << result1 << ", " << result2 << std::endl; 

  x = 0.5;
  std::cout << "--- Dla x=0.5 :\t" << fs.calc(x) << ", " << my_abs(lin(squareroot(sinus(x)))) << std::endl;

  std::cout << "\n*** Wyniki posrednie dla x=0.5: *** \n" << std::endl;
  double sinx = sinus(x);
  std::cout << "--- f1 = sin(pi*x+pi/3): " << sinx << ", " << fs[0] << std::endl; 
  std::cout << "--- f2 = sqr(f1):\t" << squareroot(sinx) << ", " << fs[1] << std::endl; 
  std::cout << "--- f3 = -0.25*f3+1:\t" << lin(squareroot(sinx)) << ", " << fs[2] << std::endl; 
  std::cout << "--- f4 = abs(f3):\t" << my_abs(lin(squareroot(sinx))) << ", " << fs[3] << std::endl; 
}
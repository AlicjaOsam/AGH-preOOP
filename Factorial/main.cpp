#include <iostream> 
#include <cmath>
#include "factorial.h"

using namespace std;

int main ()
{
  int i,abs_i;
  cout << "Enter an integer: ";
  cin >> i;
  cout << "You entered " << i << endl;
  abs_i=abs(i);
  cout << "Its absolute value is " << abs_i << ".\n";
  cout << "Factorial of number " << abs_i <<" is "<< factorial(abs_i) <<".\n";
  cout << "Factorial of absolute value " << abs_i <<" is "<< factorial_rec(abs_i) <<".\n";

  return 0;
}
 

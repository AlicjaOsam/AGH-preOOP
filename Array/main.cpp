#include <iostream>
#include "print.h"
#include "sum.h"
#include "max.h"
#include "average.h"
#include "arithmetic.h"
#include "median.h"

using namespace std;

int main () {
  int array_1[] = {2, 4, 6, 8, 10, 12, 14};
  int array_2[] = {1, 2, 4, 8, 16, 32};
  const int N1 = 7;
  const int N2 = 6;
  
  cout << "Array_1: ";
  print (array_1,N1);
  cout << "Sum array_1 = "  << sum(array_1,N1)<<endl;
  cout << "Average array_1 = "  << average(array_1,N1) << endl;
  cout << "Maximum array_1 = " << max(array_1,N1) << endl << endl;

  cout << "Array_2: ";
  print (array_2,N2);
  cout << "Sum array_2 = "  << sum(array_2,N2)<<endl;
  cout << "Average array_2 = "  << average(array_2,N2) << endl;
  cout << "Maximum array_2 = " << max(array_2,N2) << endl << endl;

  if (arithmetic(array_1,N1)) cout<<"Array_1 is arithmetic\n";
    else cout<<"Array_1 is not arithmetic\n";
  if (arithmetic(array_2,N1)) cout<<"Array_2 is arithmetic\n";
    else cout<<"Array_2 is not arithmetic\n";

  cout << "Median array_1 = "<<median(array_1, N1)<<endl;
  cout << "Median array_2 = "<<median(array_2, N2)<<endl;
  return 0;
}

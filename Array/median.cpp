#include "median.h"

int median(int *a, int n){
	int s;
	if(n % 2 != 0){
		return a[n/2];
	}
	else{
		s = a[n/2 -1]  +a[n/2];
		return s/2;
	}
}

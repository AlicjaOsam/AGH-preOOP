#include "average.h"

int average(int *a, int n){
	int s = sum(a, n);
	int avg = s/n;
	return avg;
}

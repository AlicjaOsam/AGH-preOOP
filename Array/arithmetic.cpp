#include "arithmetic.h"

int arithmetic(int *a, int n){
	int p = a[1] - a[0];
	int r;
	for(int i=1;i<n;i++){
		r = a[i+1] - a[i];
		if(r != p){
			return 0;
		}
	}
	return 1;
}

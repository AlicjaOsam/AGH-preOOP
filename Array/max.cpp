#include "max.h"

int max(int *a, int n){
	int m = a[0];
	for(int i=1;i<n;i++){
		if(a[i] > m){
			m = a[i];
		}
	}
	return m;
}

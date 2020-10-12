#include "factorial.h"

using namespace std;

int factorial(int n){
	int x = n;
	for(int i=1;i<n;i++){
		x *= i;
	}
	return x;
}

int factorial_rec(int n){
	int x = n;
	if(x < 2){
		return 1;
	}
	else return x*factorial_rec(x-1);
}

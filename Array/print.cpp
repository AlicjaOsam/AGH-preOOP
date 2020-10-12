#include <iostream>
#include "print.h"

using namespace std;

void print(int *a, int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

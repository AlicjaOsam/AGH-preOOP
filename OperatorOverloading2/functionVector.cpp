#include "functionVector.h"

void FunctionVector::insert(Linear l){
  tab1.push_back(l);
}

void FunctionVector::insert(Sqrt s){
  tab2.push_back(s);
}

void FunctionVector::insert(Sin s){
  tab3.push_back(s);
}

void FunctionVector::insert(double (*f)(double)){
  tab4.push_back(f);
}

double FunctionVector::calc(double x){
  if(tab.size() == 0){
    tab.push_back(tab3[0](x));
    tab.push_back(tab2[0](tab[0]));
    tab.push_back(tab1[0](tab[1]));
    tab.push_back(tab4[0](tab[2]));
  }
  else{
    tab[0] = (tab3[0](x));
    tab[1] = (tab2[0](tab[0]));
    tab[2] = (tab1[0](tab[1]));
    tab[3] = (tab4[0](tab[2]));
  }
  return tab[3];
}

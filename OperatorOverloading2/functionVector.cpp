#include "functionVector.h"

void FunctionVector::insert(std::function<double(double)> f){
  _v.push_back(f);
}

double FunctionVector::calc(double x){
  if(_v.size() == 0){
    return 0;
  }
  _result.clear();
  double count = _v[0](x);
  _result.push_back(count);
  for(int i=1; i<_v.size(); i++){
    count = _v[i](count);
    _result.push_back(count);
  }
  return count;   
}

double FunctionVector::operator[](const int x){
  return _result[x];
}
#include <iostream>
#include <cstring>
#include "pesel.h"

using namespace std;

bool PeselValidator(char* t_pesel, int* pesel){
  if(strlen(t_pesel) == 11){
    for(int i=0; i<11; i++){
      pesel[i] = (int)t_pesel[i] - 48;
    }
    if(!checkMonth(pesel)){
      return false;
    }
    if(getCtrlNumber(pesel) != pesel[10]){
      return false;
    }
    return true;
  }
  return false;
}

bool checkMonth(int *pesel){
  int c = pesel[2]*10 + pesel[3];
  if((c > 12 && c < 21) || (c > 32 && c < 41) || c > 52){
    return false;
  }
  return true;
}

void printPesel(int* pesel){
  for(int i=0; i<11; i++){
    cout<<pesel[i];
  }
}

int getCtrlNumber(int* pesel){
  int w[] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
  int ctrl = 0;
  for(int i=0; i<10; i++){
      ctrl += w[i] * pesel[i];
  }
  return ctrl%10;
}

char* sex(int* pesel){
  if(pesel[9]%2 == 0){
    return (char*)"Kobieta";
  }
  return (char*)"Mezczyzna";
}

int getDay(int* pesel){
  return pesel[4] * 10 + pesel[5];
}

int getMonth(int* pesel){
  int m = pesel[3];
  int s = pesel[2];
  if(s == 1 || s == 3 || s == 5){
    return m + 10;
  }
  return m;
}

int getYear(int* pesel){
  int m = pesel[2] * 10 + pesel[3];
  int s = pesel[2];
  if(s < 1){
    return pesel[0] * 10 + pesel[1] + 1900;
  }
  else if(s < 4){
    return pesel[0] * 10 + pesel[1] + 2000;
  }
  else{
    return pesel[0] * 10 + pesel[1] + 2100;
  }
}
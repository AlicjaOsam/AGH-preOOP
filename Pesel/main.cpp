#include <iostream>
#include "pesel.h"

int main() {
char* Tpesel[] ={(char*)"80022901235", 
                 (char*)"81022901232", 
                 (char*)"01251213366", 
                 (char*)"11323113335",
                 (char*)"04422956295",
                 (char*)"044229562",
                 (char*)"044229562957"};

int PESEL[11];
bool valid;
char *monthName[] = {0,(char*)" stycznia ",(char*)" lutego ", (char*)" marca ",
    (char*)" kwietnia ",(char*)" maja ",(char*)" czerwca ",
    (char*)" lipca ",(char*)" sierpnia ",(char*)" wrzesnia ",
    (char*)" pazdziernika ",(char*)" listopada ",(char*)" grudnia "};

for (int i=0; i < 7; ++i) {
  valid = PeselValidator(Tpesel[i], PESEL);
  if (valid) {
    std::cout << "PESEL: ";
    printPesel(PESEL);
    std::cout << " Suma kontrolna: " << getCtrlNumber(PESEL) << std::endl;
    std::cout << "Numer PESEL jest prawidlowy\n";
    std::cout << "Plec: " << sex(PESEL) << std::endl;
    std::cout << "Data urodzenia: " << getDay(PESEL) 
                                    << monthName[getMonth(PESEL)]
                                    << getYear(PESEL) << std::endl;

  }
  else {
    std::cout << "PESEL: "<< Tpesel[i];
    std::cout << " jest nieprawidlowy\n";
}
  std::cout << "-----------------------------------------\n";
}
  return 0;
}

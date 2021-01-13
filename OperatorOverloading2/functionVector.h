#include "functions.h"
#include <vector>

class FunctionVector{
  public:
    void insert(Linear);
    void insert(Sqrt);
    void insert(Sin);
    void insert(double (*)(double));
    double calc(double);

    const double & operator[](int x) const {
      return tab[x];
    }

  private:
    std::vector <Linear> tab1;
    std::vector <Sqrt> tab2;
    std::vector <Sin> tab3;
    std::vector <double (*)(double)> tab4;
    std::vector <double> tab;
};
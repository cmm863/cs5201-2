#include <iostream>
#include "term.h"

using namespace std;

int main()
{
  Term<float> t = Term<float>::Term(5.3, 4);
  cout << "Coefficient: " << t.getCoefficient() << endl;
  cout << "Degree: " << t.getDegree() << endl;
  return 0;
}
#include <iostream>
#include "term.h"
#include "polynomial_fnct.h"

using namespace std;

int main()
{
  Term<float> t = Term<float>::Term(5.3, 4);
  Term<float> x = Term<float>::Term(28, 5);
  Term<float> y = Term<float>::Term(30, 3);
  cout << "Coefficient: " << t.getCoefficient() << endl;
  cout << "Degree: " << t.getDegree() << endl;

  PolynomialFunction<float> pf;
  pf.appendTerm(t);
  pf.appendTerm(x);
  pf.appendTerm(y);
  cout << pf.debugString() << endl;
  return 0;
}
#include <iostream>
#include <fstream>
#include "term.h"
#include "polynomial_fnct.h"

using namespace std;

int main(int argc, char* argv[])
{
  if(argc < 2) {
    cout << "No file given." << endl;
    return 1;
  }

  string line;
  ifstream inputFile(argv[1]);

  getline(inputFile, line);
  cout << line << endl;
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
  cout << pf.getNumTerms() << endl;
  return 0;
}
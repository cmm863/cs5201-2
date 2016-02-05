#include <iostream>
#include <fstream>
#include <cstring>
#include "term.h"
#include "polynomial_fnct.h"

using namespace std;

int main(int argc, char* argv[])
{
  if(argc < 2) {
    cout << "No file given." << endl;
    return 1;
  }

  string numPolynomials, numTerms, coefficient, degree;
  ifstream inputFile(argv[1]);
  if(inputFile.is_open())
  {
    inputFile >> numPolynomials;
    cout << numPolynomials << endl;
    for(int i = 0; i < atoi(numPolynomials.c_str()); i++)
    {
      inputFile >> numTerms;
      cout << numTerms << endl;
      for(int j = 0; j < atoi(numTerms.c_str()); j++)
      {
        inputFile >> coefficient;
        cout << "Coefficient: " << coefficient << endl;
        inputFile >> degree;
        cout << "Degree: " << degree << endl;
      }
    }
  }
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
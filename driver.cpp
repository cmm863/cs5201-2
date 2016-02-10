#include <iostream>
#include <fstream>
#include "term.h"
#include "polynomial_fnct.h"

using namespace std;

int main(int argc, char* argv[])
{
  // If no file from arg commands
  if (argc < 2)
  {
    cout << "No file given." << endl;
    return 1;
  }

  Term<int> a = Term<int>::Term(3, 5);
  Term<int> b = Term<int>::Term(4, 5);
  cout << (a != b) << endl;
  cout << (a != a) << endl;
  a = a * 5;
  cout << "d: " << a.getDegree() << endl;
  cout << "c: " << a.getCoefficient() << endl;
  a *= 5;
  cout << "d: " << a.getDegree() << endl;
  cout << "c: " << a.getCoefficient() << endl;

  // Declare variables
  string numPolynomials, numTerms, coefficient, degree;
  ifstream inputFile(argv[1]);
  vector<PolynomialFunction<float> > polynomialVector;

  // Start going through file
  if (inputFile.is_open())
  {
    inputFile >> numPolynomials;

    // Create an array with each polynomial in it
    for(int i = 0; i < atoi(numPolynomials.c_str()); i++)
    {
      polynomialVector.push_back(PolynomialFunction<float>());
    }

    // For each polynomial
    for (int i = 0; i < atoi(numPolynomials.c_str()); i++)
    {
      polynomialVector[i] = PolynomialFunction<float>();
      inputFile >> numTerms;

      // For each term
      for (int j = 0; j < atoi(numTerms.c_str()); j++)
      {
        inputFile >> coefficient;
        inputFile >> degree;

        // Add term to polynomial
        polynomialVector[i].appendTerm(Term<float>::Term(stof(coefficient.c_str()), atoi(degree.c_str())));
      }
      // Print out polynomial so we're sure it loaded correctly
      cout << polynomialVector[i](1) << endl;
    }
    cout << (polynomialVector[0] != polynomialVector[1]) << endl;
    cout << (polynomialVector[1] != polynomialVector[2]) << endl;

  }
  else // If file isn't open
  {
    cout << "File failed to open: " << argv[1] << endl;
    return 1;
  }

  return 0;
}
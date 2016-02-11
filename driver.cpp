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
    }
    polynomialVector[0] += polynomialVector[1];
    cout << polynomialVector[0] << endl;
    cout << -polynomialVector[0] << endl;
    cout << polynomialVector[0](-1) << endl;
    cout << 4 * polynomialVector[2] << endl;
    cout << (~polynomialVector[3])(2) << endl;
  }
  else // If file isn't open
  {
    cout << "File failed to open: " << argv[1] << endl;
    return 1;
  }

  return 0;
}
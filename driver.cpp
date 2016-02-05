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
  PolynomialFunction<float> * polynomialArray;

  // Start going through file
  if (inputFile.is_open())
  {
    inputFile >> numPolynomials;

    // Create an array with each polynomial in it
    polynomialArray = new PolynomialFunction<float>[atoi(numPolynomials.c_str())];

    // For each polynomial
    for (int i = 0; i < atoi(numPolynomials.c_str()); i++)
    {
      polynomialArray[i] = PolynomialFunction<float>();
      inputFile >> numTerms;

      // For each term
      for (int j = 0; j < atoi(numTerms.c_str()); j++)
      {
        inputFile >> coefficient;
        inputFile >> degree;

        // Add term to polynomial
        polynomialArray[i].appendTerm(Term<float>::Term(stof(coefficient.c_str()), atoi(degree.c_str())));
      }

      // Print out polynomial so we're sure it loaded correctly
      cout << polynomialArray[i].getNumTerms() << endl;
      cout << polynomialArray[i].debugString() << endl;
    }

  }
  else // If file isn't open
  {
    cout << "File failed to open: " << argv[1] << endl;
    return 1;
  }

  return 0;
}
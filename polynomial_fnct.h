//
// Created by Connor McBride on 2/2/16.
//

#ifndef INC_2_POLYNOMIAL_FNCT_H
#define INC_2_POLYNOMIAL_FNCT_H

#include "term.h"
#include <map>
#include <vector>
#include <iostream>

using namespace std;

// Forward declarations for friend functions
template <typename T>
class PolynomialFunction;

template <typename T>
ostream& operator <<(ostream& out, const PolynomialFunction<T>& rhs);



template <typename T>
class PolynomialFunction
{
public:
  void appendTerm(Term<T> t);
  string debugString();
  unsigned long getNumTerms();
  PolynomialFunction& operator+=(const PolynomialFunction& rhs);
  const PolynomialFunction operator *(const long double c);
  const Term<T>& operator [](const int index);
  friend ostream& operator << <>(ostream& out, const PolynomialFunction<T>& rhs);
  const PolynomialFunction operator ~();
  const T operator ()(float c);
  bool operator ==(PolynomialFunction& rhs);
private:
  vector<Term<T> > m_terms;
};

#include "polynomial_fnct.hpp"
#endif //INC_2_POLYNOMIAL_FNCT_H

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

template <typename T>
class PolynomialFunction
{
public:
  void appendTerm(Term<T> t);
  string debugString();
  unsigned long getNumTerms();
private:
  map<char, Term<T> > m_terms;
};

#include "polynomial_fnct.hpp"
#endif //INC_2_POLYNOMIAL_FNCT_H

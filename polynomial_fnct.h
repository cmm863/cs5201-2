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
PolynomialFunction<T> operator +(const PolynomialFunction<T>& lhs, const PolynomialFunction<T>& rhs);

template <typename T>
PolynomialFunction<T> operator -(const PolynomialFunction<T>& rhs);

template <typename T>
PolynomialFunction<T> operator -(const PolynomialFunction<T>& lhs, const PolynomialFunction<T>& rhs);

template <typename T>
PolynomialFunction<T> operator *(const PolynomialFunction<T>& lhs, float c);

template <typename T>
PolynomialFunction<T> operator *(float c, const PolynomialFunction<T>& rhs);

template <typename T>
ostream& operator <<(ostream& out, const PolynomialFunction<T>& rhs);



template <typename T>
class PolynomialFunction
{
public:
  void appendTerm(Term<T> t);
  unsigned long getNumTerms() const;
  const Term<T>& operator [](const int index) const;
  const PolynomialFunction operator ~();
  const T operator ()(float c);
  bool operator ==(const PolynomialFunction& rhs) const;
  bool operator !=(const PolynomialFunction& rhs) const;
  friend PolynomialFunction operator + <>(const PolynomialFunction& lhs, const PolynomialFunction& rhs);
  friend PolynomialFunction operator - <>(const PolynomialFunction& rhs);
  friend PolynomialFunction operator - <>(const PolynomialFunction& lhs, const PolynomialFunction& rhs);
  friend PolynomialFunction operator * <>(float c, const PolynomialFunction& rhs);
  friend PolynomialFunction operator * <>(const PolynomialFunction& lhs, float c);
  friend ostream& operator << <>(ostream& out, const PolynomialFunction& rhs);
private:
  vector<Term<T> > m_terms;
};

#include "polynomial_fnct.hpp"
#endif //INC_2_POLYNOMIAL_FNCT_H

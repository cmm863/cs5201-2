//
// Created by Connor McBride on 2/2/16.
//

#ifndef INC_2_POLYNOMIAL_FNCT_HPP
#define INC_2_POLYNOMIAL_FNCT_HPP

#include <set>
#include "term.h"
#include "polynomial_fnct.h"

template <typename T>
void PolynomialFunction<T>::appendTerm(Term <T> t)
{
  for(auto i = m_terms.begin(); i != m_terms.end(); i++)
  {
    if(t.getDegree() < i->getDegree())
    {
      m_terms.insert(i, t);
      return;
    }
  }
  m_terms.push_back(t);
  return;
}

template <typename T>
string PolynomialFunction<T>::debugString()
{
  string ret = "";
  for(auto t : m_terms)
  {
    ret += "Coefficient: " + to_string(t.getCoefficient()) + "\n";
    ret += "Degree: " + to_string(t.getDegree()) + "\n";
  }
  return ret;
}

template <typename T>
unsigned long PolynomialFunction<T>::getNumTerms()
{
  return m_terms.size();
}

template <typename T>
PolynomialFunction<T>& PolynomialFunction<T>::operator+=(const PolynomialFunction<T> &rhs)
{
  set<int> degrees;

}


#endif //INC_2_POLYNOMIAL_FNCT_HPP

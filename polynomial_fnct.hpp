//
// Created by Connor McBride on 2/2/16.
//

#ifndef INC_2_POLYNOMIAL_FNCT_HPP
#define INC_2_POLYNOMIAL_FNCT_HPP

#include "term.h"
#include "polynomial_fnct.h"

template <typename T>
void PolynomialFunction<T>::appendTerm(Term <T> t)
{
  if(m_terms.find(t.getDegree()) == m_terms.end())
  {
    m_terms[t.getDegree()] = t;
  }
  else
  {
    cout << "TODO: Term + overload" << endl;
  }

  return;
}

template <typename T>
string PolynomialFunction<T>::debugString()
{
  vector<T> degrees;
  string ret;
  for(auto t : m_terms)
  {
    degrees.push_back(t.first);
  }

  std::sort(degrees.begin(), degrees.end(), std::greater<int>());

  for(auto d : degrees)
  {
    ret += "Coefficient: " + to_string(m_terms[d].getCoefficient()) + "\n";
    ret += "Degree: " + to_string(d) + "\n";
  }
  return ret;
}

template <typename T>
unsigned long PolynomialFunction<T>::getNumTerms()
{
  return m_terms.size();
}


#endif //INC_2_POLYNOMIAL_FNCT_HPP

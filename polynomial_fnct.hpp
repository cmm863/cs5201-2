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
  for(auto t : m_terms)
  {
    degrees.push_back(t.first);
  }

  std::sort(degrees.begin(), degrees.end(), std::greater<int>());

  for(auto d : degrees)
  {
    cout << "Degree: " << d << endl;
    cout << "Coefficient: " << m_terms[d].getCoefficient() << endl;
  }
  return "hi";
}

template <typename T>
int PolynomialFunction<T>::getNumTerms()
{
  return m_num_terms;
}


#endif //INC_2_POLYNOMIAL_FNCT_HPP

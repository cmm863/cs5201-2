//
// Created by Connor McBride on 2/2/16.
//
#include "term.h"

template <typename T>
Term<T>::Term()
{
  m_degree = 0;
}

template <typename T>
int Term<T>::getDegree() const
{
  return m_degree;
}

template <typename T>
T Term<T>::getCoefficient() const
{
  return m_coefficient;
}

template <typename T>
const Term<T> Term<T>::operator+(const Term<T> &rhs)
{
  return Term(this->getCoefficient() + rhs.getCoefficient(), this->getDegree());
}
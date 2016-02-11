//
// Created by Connor McBride on 2/2/16.
//
#include "term.h"
#include <cmath>
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
Term<T> operator +(const Term<T> &lhs, const Term<T> &rhs)
{
  return Term<T>(lhs.getCoefficient() + rhs.getCoefficient(), lhs.getDegree());
}

template <typename T>
Term<T> operator *(float c, const Term<T>& rhs)
{
  return Term<T>(rhs.getCoefficient() * c, rhs.getDegree());
}

template <typename T>
Term<T> operator *(const Term<T>& lhs, float c)
{
  return c * lhs;
}

template <typename T>
Term<T> Term<T>::operator*=(float c)
{
  this->m_coefficient = this->m_coefficient * c;
  return (*this);
}

template <typename T>
T Term<T>::operator()(float c)
{
  return this->getCoefficient() * (pow(c, this->getDegree()));
}

template <typename T>
bool Term<T>::operator==(const Term<T> &rhs) const
{
  return (this->getCoefficient() == rhs.getCoefficient()) && (this->getDegree() == rhs.getDegree());
}

template <typename T>
bool Term<T>::operator!=(const Term<T> &rhs) const
{
  return !((*this) == rhs);
}
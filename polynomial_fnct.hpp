//
// Created by Connor McBride on 2/2/16.
//

#ifndef INC_2_POLYNOMIAL_FNCT_HPP
#define INC_2_POLYNOMIAL_FNCT_HPP

#include <set>
#include "term.h"
#include "polynomial_fnct.h"

template <typename T>
PolynomialFunction<T>::PolynomialFunction()
{
}

template <typename T>
PolynomialFunction<T>::PolynomialFunction(T coefficient, int degree)
{
  this->appendTerm(Term<T>(coefficient, degree));
}

template <typename T>
PolynomialFunction<T>::PolynomialFunction(const PolynomialFunction<T>& other)
{
  for(int i = 0; i < other.getNumTerms(); i++)
  {
    this->appendTerm(other[i]);
  }
}

template <typename T>
PolynomialFunction<T>::~PolynomialFunction()
{
  this->m_terms.clear();
}

template <typename T>
void PolynomialFunction<T>::appendTerm(Term <T> t)
{
  for(auto i = m_terms.begin(); i != m_terms.end(); i++)
  {
    if(t.getDegree() > i->getDegree())
    {
      m_terms.insert(i, t);
      return;
    }
  }
  m_terms.push_back(t);
  return;
}

template <typename T>
unsigned long PolynomialFunction<T>::getNumTerms() const
{
  return m_terms.size();
}

template <typename T>
const Term<T>& PolynomialFunction<T>::operator [](const int index) const
{
  return m_terms[index];
}

template <typename T>
const T PolynomialFunction<T>::operator()(float c) const
{
  T ret = 0;
  for(auto t : m_terms)
  {
    ret += t(c);
  }
  return ret;
}

template <typename T>
bool PolynomialFunction<T>::operator==(const PolynomialFunction<T>& rhs) const
{
  if(this->m_terms.size() != rhs.getNumTerms())
  {
    return false;
  }
  for(int i = 0; i < rhs.getNumTerms(); i++)
  {
    if(this->m_terms[i] != rhs[i])
    {
      return false;
    }
  }
  return true;
}

template <typename T>
bool PolynomialFunction<T>::operator!=(const PolynomialFunction<T> &rhs) const
{
  return !((*this) == rhs);
}

template <typename T>
PolynomialFunction<T> PolynomialFunction<T>::operator +=(const PolynomialFunction<T> &rhs)
{
  *this = *this + rhs;
  return *this;
}

template <typename T>
PolynomialFunction<T> operator - (const PolynomialFunction<T>& rhs)
{
  return -1 * rhs;
}

template <typename T>
PolynomialFunction<T> operator ~(const PolynomialFunction<T>& rhs)
{
  PolynomialFunction<T> ret;
  int multiplier;
  for(int i = 0; i < rhs.getNumTerms(); i++)
  {
    if(rhs[i].getCoefficient() > 0)
    {
      multiplier = -1;
    }
    else
    {
      multiplier = 1;
    }
    ret.appendTerm(Term<T>(multiplier * rhs[i].getCoefficient(), rhs[i].getDegree()));
  }
  return ret;
}

template <typename T>
PolynomialFunction<T> operator + (const PolynomialFunction<T>& lhs, const PolynomialFunction<T>& rhs)
{
  PolynomialFunction<T> ret;

  auto leftIterator = lhs.m_terms.begin();
  auto rightIterator = rhs.m_terms.begin();
  auto leftEnd = lhs.m_terms.end();
  auto rightEnd = rhs.m_terms.end();
  while(leftIterator != leftEnd || rightIterator != rightEnd)
  {
    if(leftIterator == leftEnd)
    {
      while(rightIterator != rightEnd)
      {
        ret.appendTerm(*rightIterator);
        rightIterator++;
      }
    }
    else if(rightIterator == rightEnd)
    {
      while(leftIterator != leftEnd)
      {
        ret.appendTerm(*leftIterator);
        leftIterator++;
      }
    }
    else
    {
      if(leftIterator->getDegree() < rightIterator->getDegree())
      {
        ret.appendTerm(*leftIterator);
        leftIterator++;
      }
      else if(rightIterator->getDegree() < leftIterator->getDegree())
      {
        ret.appendTerm(*rightIterator);
        rightIterator++;
      }
      else
      {
        ret.appendTerm((*leftIterator + *rightIterator));
        rightIterator++;
        leftIterator++;
      }
    }
  }

  return ret;
}

template <typename T>
PolynomialFunction<T> operator - (const PolynomialFunction<T>& lhs, const PolynomialFunction<T>& rhs)
{
  return lhs + (-rhs);
}

template <typename T>
PolynomialFunction<T> operator * (float c, const PolynomialFunction<T>& rhs)
{
  PolynomialFunction<T> ret;

  for(int i = 0; i < rhs.getNumTerms(); i++)
  {
    ret.appendTerm(c * rhs[i]);
  }

  return ret;
}

template <typename T>
PolynomialFunction<T> operator *(const PolynomialFunction<T>& lhs, float c)
{
  return c * lhs;
}

template <typename T>
ostream& operator <<(ostream& out, const PolynomialFunction<T>& rhs)
{
  for(auto i = rhs.m_terms.begin(); i != rhs.m_terms.end(); i++)
  {
    if(i->getCoefficient() < 0)
    {
      if(i == rhs.m_terms.begin())
      {
        out << "-";
      }
      else
      {
        out << "- ";
      }
      out << (-1 * i->getCoefficient());
    }
    else if(i->getCoefficient() > 0)
    {
      if(i != rhs.m_terms.begin())
      {
        cout << "+ ";
      }
    }
    else
    {
      continue;
    }

    if(i->getDegree() > 0)
    {
      out << "x^" << i->getDegree() << " ";
    }
  }
  return out;
}


#endif //INC_2_POLYNOMIAL_FNCT_HPP

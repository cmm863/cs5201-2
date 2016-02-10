//
// Created by Connor McBride on 2/2/16.
//

#ifndef INC_2_TERM_H
#define INC_2_TERM_H

template <typename T>
class Term;

template <typename T>
Term<T> operator *(float c, const Term<T>& rhs);

template <typename T>
Term<T> operator *(const Term<T>& rhs, float c);

template <typename T>
Term<T> operator +(const Term<T>& lhs, const Term<T>& rhs);



template <typename T>
class Term
{
public:
  Term();
  Term(T m_coefficient, int m_degree) : m_coefficient(m_coefficient), m_degree(m_degree) { };

  int getDegree() const;
  T getCoefficient() const;
  friend Term operator + <>(const Term& lhs, const Term& rhs);
  friend Term operator * <>(float c, const Term& rhs);
  friend Term operator * <>(const Term& rhs, float c);
  Term operator *=(float c);
  T operator ()(float c);
  bool operator ==(const Term& rhs);
  bool operator !=(const Term& rhs);

private:
  int m_degree;
  T m_coefficient;
};

#include "term.hpp"

#endif //INC_2_TERM_H

//
// Created by Connor McBride on 2/2/16.
//

#ifndef INC_2_TERM_H
#define INC_2_TERM_H

template <typename T>
class Term
{
public:
  Term();
  Term(T m_coefficient, int m_degree) : m_coefficient(m_coefficient), m_degree(m_degree) { };

  int getDegree() const;
  T getCoefficient() const;
  const Term operator +(const Term& rhs);

private:
  int m_degree;
  T m_coefficient;
};

#include "term.hpp"

#endif //INC_2_TERM_H

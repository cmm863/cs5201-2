//
// Created by Connor McBride on 2/2/16.
//

#ifndef INC_2_TERM_H
#define INC_2_TERM_H

template <typename T>
class Term
{
public:
  Term(T m_coefficient, int m_degree) : m_coefficient(m_coefficient), m_degree(m_degree) { };

  int getDegree() const;
  T getCoefficient() const;

private:
  int m_degree;
  T m_coefficient;
};

#include "term.hpp"

#endif //INC_2_TERM_H

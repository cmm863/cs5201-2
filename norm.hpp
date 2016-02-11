//////////////////////////////////////////////////////////////////////
/// @file norm.hpp
/// @author Connor McBride
/// @brief Contains the norm class implementation information
//////////////////////////////////////////////////////////////////////

#ifndef NORM_HPP
#define NORM_HPP

#include "polynomial_fnct.h"
#include "norm.h"
#include <cmath>

template <typename T>
float Norm::operator ()(const PolynomialFunction<T> &pf) const
{
  float ret = 0;
  for(int i = 0; i < pf.getNumTerms(); i++)
  {
    ret += pow(pf[i].getCoefficient(), 2);
  }

  return sqrt(ret);
}

#endif //NORM_HPP

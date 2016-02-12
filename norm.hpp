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
float Norm::operator ()(const vector<PolynomialFunction<T> >& pfs) const
{
  float temp;
  float largest = 0;
  for(PolynomialFunction<T> pf : pfs)
  {
    temp = 0;
    for(unsigned long i = 0; i < pf.getNumTerms(); i++)
    {
      temp += pow(pf[i].getCoefficient(), 2);
    }
    temp = sqrt(temp);
    if(temp > largest)
    {
      largest = temp;
    }
  }


  return largest;
}

#endif //NORM_HPP

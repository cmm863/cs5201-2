//
// Created by Connor McBride on 2/10/16.
//

#ifndef INC_2_NORM_HPP
#define INC_2_NORM_HPP

#include "polynomial_fnct.h"
#include "norm.h"
#include <cmath>

template <typename T>
float Norm<T>::operator()(const PolynomialFunction<T> &pf)
{
  float ret = 0;
  for(int i = 0; i < pf.getNumTerms(); i++)
  {
    ret += pow(pf[i].getCoefficient(), 2);
  }

  return sqrt(ret);
}

#endif //INC_2_NORM_HPP
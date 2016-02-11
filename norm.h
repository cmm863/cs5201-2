//
// Created by Connor McBride on 2/10/16.
//

#ifndef INC_2_NORM_H
#define INC_2_NORM_H

#include "polynomial_fnct.h"

template <typename T>
class Norm
{
  public:
    float operator ()(const PolynomialFunction<T>& pf);
};

#include "norm.hpp"

#endif //INC_2_NORM_H

//////////////////////////////////////////////////////////////////////
/// @file norm.h
/// @author Connor McBride
/// @brief Contains the declaration information for the Norm class
//////////////////////////////////////////////////////////////////////

#ifndef INC_2_NORM_H
#define INC_2_NORM_H

#include "polynomial_fnct.h"


class Norm
{
  public:
    template <typename T>
    float operator ()(const PolynomialFunction<T>& pf) const;
};

#include "norm.hpp"

#endif //INC_2_NORM_H

#ifndef NORM_H
#define NORM_H

//////////////////////////////////////////////////////////////////////
/// @file norm.h
/// @author Connor McBride
/// @brief Contains the declaration information for the Norm class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class Norm
/// @brief Is a function class to implement the infinity Norm
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn float Norm::operator ()(const PolynomialFunction<T> &pf) const
/// @brief Overloads the () operator to act as a function class.
/// @pre The type of T should be resolvable to a float.
/// @post None
/// @param pf holds the reference of a PolynomialFunction with type T
/// @return Returns the infinity norm as described in homework description
//////////////////////////////////////////////////////////////////////

#include "polynomial_fnct.h"

class Norm
{
  public:
    template <typename T>
    float operator ()(const PolynomialFunction<T>& pf) const;
};

#include "norm.hpp"

#endif //NORM_H

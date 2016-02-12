//////////////////////////////////////////////////////////////////////
/// @file polynomial_fnct.h
/// @author Connor McBride
/// @brief Contains the declaration information for the PolynomialFunction class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class PolynomialFunction
/// @brief Is a template class that is a container of the Term class (monomials)
///     Peforms addition, subtraction, evaluation, and multiplication (of constants)
///     with other PolynomialFunctions.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn PolynomialFunction<T>::PolynomialFunction()
/// @brief Explicit definition of default constructor
/// @pre None.
/// @post A PolynomialFunction object of type T is instantiated
/// @return Returns PolynomialFunction object instantiated
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn PolynomialFunction<T>::PolynomialFunction(T coefficient, int degree)
/// @brief Overload of the constructor that takes in parameters for an initial monomial
/// @pre None.
/// @post A Term object of type T is instantiated with initial monomial
/// @param1 Is the coefficient for the monomial.
/// @param2 Is the degree of the monomial.
/// @return Returns PolynomialFunction object instantiated
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn PolynomialFunction<T>::PolynomialFunction(const PolynomialFunction<T>& other)
/// @brief Copy constructor constructor that takes in another PolynomialFunction and copies it.
/// @pre None.
/// @post A PolynomialFunction copy is instantiated.
/// @param1 PolynomialFunction to be copied.
/// @return Returns PolynomialFunction object instantiated with other's values.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn PolynomialFunction<T>::~PolynomialFunction()
/// @brief Overload of the destructor
/// @pre None.
/// @post All m_terms of the calling object are cleared.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn void PolynomialFunction<T>::appendTerm(Term <T> t)
/// @brief Adds the monomial to the calling object.
/// @pre None.
/// @post The Term passed is stored in the calling object.
/// @param1 The Term to be added to the calling polynomial.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn unsigned long PolynomialFunction<T>::getNumTerms() const
/// @brief Returns number of monomials in calling object.
/// @pre None.
/// @post None.
/// @return Number of monomials
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn const Term<T>& PolynomialFunction<T>::operator [](int index) const
/// @brief Returns a const reference of the term at given index.
/// @pre Index needs to be less than the number of terms.
/// @post None.
/// @param1 Index of the term to be returned.
/// @return Const reference of the monomial given.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn T PolynomialFunction<T>::operator ()(float c) const
/// @brief Overload of the () operator. Returns value of the polynomial at given c.
/// @pre T needs to be able to equate to 0 and have a += operator.
/// @post None.
/// @param1 Value to evaluate the calling object at.
/// @return Evaluated value of the calling object at c
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn bool PolynomialFunction<T>::operator ==(const PolynomialFunction<T>& rhs) const
/// @brief Overload of the == operater to return equivalence.
/// @pre Term needs to have a != operator.
/// @post None.
/// @param1 Polynomial function to determine equivalence.
/// @return Equivalence of calling object and passed rhs
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn bool PolynomialFunction<T>::operator!=(const PolynomialFunction<T> &rhs) const
/// @brief Overload of the != operater to determine non equivalence
/// @pre PolynomialFunciton needs to have == operator overloaded.
/// @post None.
/// @param1 Polynomial function to determine non equivalence
/// @return Non equivalence of calling object and passed rhs
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn PolynomialFunction<T>& PolynomialFunction<T>::operator +=(const PolynomialFunctoin<T> &rhs)
/// @brief Overload of the += operator that sets calling object to the addition of rhs
/// @pre PolynomialFunction needs to have + operator overloaded.
/// @post Calling object is set to the addition of it and rhs
/// @param1 Polynomial function to be added to the calling object
/// @return Reference to calling object after addition
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn friend PolynomialFunction<T> operator -(const PolynomialFunction<T>& rhs)
/// @brief Overload of the unary - operator that returns a copy of rhs with all coefficient
///     signs changed.
/// @pre PolynomialFunction needs to have * operator overloaded.
/// @post None.
/// @param1 Polynomial function to have it's signs changed.
/// @return Copy of rhs with signs for each coefficient inverted.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn friend PolynomialFunction<T> operator ~(const PolynomialFunction<T>& rhs)
/// @brief Overload of the unary ~ operator that sets all signs of coefficients to -
/// @pre T needs to have * operator overloaded and PolynomialFunction [] operator overloaded.
/// @post None.
/// @param1 Polynomial function passed to have its signs changed to -
/// @return Copy of rhs with signs for each coefficient inverted.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn friend PolynomialFunction<T> operator +(const PolynomialFunction<T>& lhs, const PolynomialFunction<T>& rhs)
/// @brief Adds two PolynomialFunctions together.
/// @pre Terms need to have + operator overloaded.
/// @post None.
/// @param1 Polynomial function 1 to be added
/// @param2 Polynomial function 2 to be added
/// @return Sum of lhs and rhs
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn friend PolynomialFunction<T> operator -(const PolynomialFunction<T>& lhs, const PolynomialFunction<T>& rhs)
/// @brief Subtracts rhs from lhs.
/// @pre PolynomialFunction needs to have + and unary - operator overloads.
/// @post None.
/// @param1 Polynomial function minuend
/// @param2 Polynomial function subtrahend
/// @return Difference of rhs from lhs
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn friend PolynomialFunction<T> operator *(float c, const PolynomialFunction<T>& rhs)
/// @brief Multiplies all terms in rhs by c
/// @pre Terms need to have * operator overloaded and PolynomialFunction needs to have [] operator overloaded.
/// @post None.
/// @param1 Multiple
/// @param2 Polynomial function to be multiplied
/// @return Product of c and rhs
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn friend PolynomialFunction<T> operator *(const PolynomialFunction<T>& lhs, float c)
/// @brief Multiplies all terms in lhs by c
/// @pre Terms need to have * operator overloaded and PolynomialFunction needs to have []
///     and * for (c, rhs) operator overloaded.
/// @post None.
/// @param1 Polynomial function to be multiplied
/// @param2 Multiplier
/// @return Product of c and rhsß
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn ostream& operator <<(ostream& out, const PolynomialFunction<T>& rhs)
/// @brief Outputs rhs to ostream.
/// @pre T needs to have * operator.
/// @post ostream is appended with information on rhs.
/// @param1 ostream operator to be changed.
/// @param2 Polynomial whose info is to be output.
/// @return ostream& with debug string for polynomial added to the stream.
//////////////////////////////////////////////////////////////////////

#ifndef POLYNOMIAL_FNCT_H
#define POLYNOMIAL_FNCT_H

#include "term.h"
#include <map>
#include <vector>
#include <iostream>

using namespace std;

// Forward declarations for friend functions
template <typename T>
class PolynomialFunction;

template <typename T>
PolynomialFunction<T> operator -(const PolynomialFunction<T>& rhs);

template <typename T>
PolynomialFunction<T> operator ~(const PolynomialFunction<T>& rhs);

template <typename T>
PolynomialFunction<T> operator +(const PolynomialFunction<T>& lhs, const PolynomialFunction<T>& rhs);

template <typename T>
PolynomialFunction<T> operator -(const PolynomialFunction<T>& lhs, const PolynomialFunction<T>& rhs);

template <typename T>
PolynomialFunction<T> operator *(const PolynomialFunction<T>& lhs, float c);

template <typename T>
PolynomialFunction<T> operator *(float c, const PolynomialFunction<T>& rhs);

template <typename T>
ostream& operator <<(ostream& out, const PolynomialFunction<T>& rhs);



template <typename T>
class PolynomialFunction
{
  public:
    PolynomialFunction();
    PolynomialFunction(T coefficient, int degree);
    PolynomialFunction(const PolynomialFunction& other);
    ~PolynomialFunction();
    void appendTerm(const Term<T> t);
    unsigned long getNumTerms() const;
    const Term<T>& operator [](int index) const;
    T operator ()(float c) const;
    bool operator ==(const PolynomialFunction& rhs) const;
    bool operator !=(const PolynomialFunction& rhs) const;
    PolynomialFunction& operator +=(const PolynomialFunction& rhs);
    friend PolynomialFunction operator - <>(const PolynomialFunction& rhs);
    friend PolynomialFunction operator ~ <>(const PolynomialFunction& rhs);
    friend PolynomialFunction operator + <>(const PolynomialFunction& lhs, const PolynomialFunction& rhs);
    friend PolynomialFunction operator - <>(const PolynomialFunction& lhs, const PolynomialFunction& rhs);
    friend PolynomialFunction operator * <>(float c, const PolynomialFunction& rhs);
    friend PolynomialFunction operator * <>(const PolynomialFunction& lhs, float c);
    friend ostream& operator << <>(ostream& out, const PolynomialFunction& rhs);
  private:
    vector<Term<T> > m_terms;
};

#include "polynomial_fnct.hpp"
#endif //POLYNOMIAL_FNCT_H

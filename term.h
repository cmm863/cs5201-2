#ifndef TERM_H
#define TERM_H

//////////////////////////////////////////////////////////////////////
/// @file term.h
/// @author Connor McBride
/// @brief Contains the declaration information for the Term class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class Term
/// @brief Is a template class where the coefficient is the typename T.
///     Contains the information, operations, and manipulations of a monomial.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Term<T>::Term()
/// @brief Explicit definition of the default constructor.
/// @pre None
/// @post A Term class of type T is instantiated with a default degree of 0
/// @return Returns Term object instantiated
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Term<T>::Term(T coefficient, int degree)
/// @brief Overload of the constructor that takes in all its arguments explicitly
/// @pre The type of T should be resolvable to a float.
/// @post A Term class of type T is instantiated with explicitly defined characters
/// @param1 Is the coefficient for the term.
/// @param2 Is the degree of the monomial.
/// @return Returns Term object instantiated
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn int Term<T>::getDegree() const
/// @brief Get function for m_degree.
/// @pre None.
/// @post None.
/// @return Returns m_degree of the called object.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn T Term<T>::getCoefficient() const
/// @brief Get function for m_coefficient.
/// @pre m_coefficient needs to be instantiated in the calling object.
/// @post None.
/// @return Returns m_coefficient of the called object.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Term<T> Term<T>::operator *=(float c)
/// @brief Overload of the *= operator for the Term class.
/// @pre T must have a defined * operator.
/// @post Sets calling object to returned value.
/// @param1 Is the constant to be multiplied against the term's coefficient.
/// @return Returns Term object called.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn T Term<T>::operator ()(float c) const
/// @brief Overload of the () operator that evaluates m_coefficient * c ^ m_degree
/// @pre T must have a defined * operator.
/// @post None.
/// @param1 Is the value to be evaluated.
/// @return Returns value of monomial at c.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn bool Term<T>::operator ==(const Term<T> &rhs) const
/// @brief Overload of the == operator that returns true if coefficients
///    and degrees of the calling object and the object passed are equal.
/// @pre T must have a defined == operator.
/// @post None.
/// @param1 Is the object that is tested for equivalency with the calling object.
/// @return Returns true or false based on equivalency.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn bool Term<T>::operator !=(const Term<T> &rhs) const
/// @brief Overload of the != operator that returns true if coefficients
///    and degrees of the calling object and the object passed are not equal.
/// @pre T must have a defined == operator and Term must have a defined == operator.
/// @post None.
/// @param1 Is the object that is tested for non equivalency with the calling object.
/// @return Returns true or false based on non equivalency.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn friend Term<T> operator *(float c, const Term<T> &rhs)
/// @brief Overload of the * operator that multiplies monomial by constant c.
/// @pre T must have a defined * operator.
/// @post New Term object is instantiated.
/// @param1 The constant that the monomial is to be multiplied by.
/// @param2 The monomial that is multiplied by the constant.
/// @return Returns new Term object of rhs with rhs.m_coefficient being multiplied by c.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn friend Term<T> operator *(const Term<T> &lhs, float c)
/// @brief Overload of the * operator that multiplies monomial by constant c.
/// @pre T must have a defined * operator. Term must have * operator defined where
///    c is on the left and Term is on the right.
/// @post New Term object is instantiated.
/// @param1 The monomial that is multiplied by the constant.
/// @param2 The constant that the monomial is to be multiplied by.
/// @return Returns new Term object of rhs with rhs.m_coefficient being multiplied by c.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn friend Term<T> operator +(const Term<T> &lhs, const Term<T> &rhs)
/// @brief Adds two terms together.
/// @pre T must have a defined + operator. Degrees of both lhs & rhs must be the same.
/// @post New Term object is instantiated.
/// @param1 The lefthand term.
/// @param2 The righthand term.
/// @return Returns new Term object of rhs with rhs.m_coefficient being
///    added to lhs.m_coefficient with the same degree as both lhs and rhs.
//////////////////////////////////////////////////////////////////////

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
  Term(T coefficient, int degree) : m_degree(degree), m_coefficient(coefficient){ };
  int getDegree() const;
  T getCoefficient() const;
  Term operator *=(float c);
  T operator ()(float c) const;
  bool operator ==(const Term& rhs) const;
  bool operator !=(const Term& rhs) const;
  friend Term operator * <>(float c, const Term& rhs);
  friend Term operator * <>(const Term& rhs, float c);
  friend Term operator + <>(const Term& lhs, const Term& rhs);

private:
  int m_degree;
  T m_coefficient;
};

#include "term.hpp"

#endif //TERM_H

/*!
\file Options.cpp

\brief Implementation of classes to represent an option an a put option.

We write out classes which will be used to store the coefficients and boundary
conditions in order to price options under the Black--Scholes equation. We
represent an option as an abstract class. Its methods will the overridden by the
put option class

\warning This code is also listed and fully explained in the book **Numerical
Methods in Finance with C++** by Maciej Capiński and Tomasz Zastawniak,
published in September 2012.

\author: Eduardo J. Sanchez (ejspeiro) - ejspeiro at gmail dot com
*/

#include <cmath>

#include "Options.h"

double Put::Payoff(double z) {

  if (K < z) {
    return 0.0;
  }
  return K - z;
}

double Put::UpperBdCond(BSModel* PtrModel, double t) {

  return 0.0;
}

double Put::LowerBdCond(BSModel* PtrModel, double t) {

  return K*exp(-PtrModel->r*(T - t));
}

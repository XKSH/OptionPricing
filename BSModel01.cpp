/*!
\file BSModel01.cpp

\brief Implementation of a class using the Box--Muller method for sample paths.

We start by showing how to generate samples of random variables with standard
normal distribution. In C++ we have at our disposal a function rand(), which
generates integer numbers, simulating a sequence of i.i.d. random variables,
uniformly distributed within the range from 0 to RAND_MAX. We can use the
Box–Muller method to produce the following recipe for generating sample paths.

\warning This code is also listed and fully explained in the book **Numerical
Methods in Finance with C++** by Maciej Capiński and Tomasz Zastawniak,
published in September 2012.

\author: Eduardo J. Sanchez (ejspeiro) - ejspeiro at gmail dot com
*/

#include "BSModel01.h"

#include <cmath>

const double pi = 4.0*atan(1.0);

double Gauss( ) {

  double U1 = (rand() + 1.0)/(RAND_MAX + 1.0);
  double U2 = (rand() + 1.0)/(RAND_MAX + 1.0);

  return sqrt(-2.0*log(U1))*cos(2.0*pi*U2);
}

void BSModel::GenerateSamplePath(double T, int m, SamplePath& S) {

  double St = S0;

  for(int k = 0; k < m; k++) {
    S[k] = St*exp((r - sigma*sigma*0.5)*(T/m) + sigma*sqrt(T/m)*Gauss());
    St = S[k];
  }
}

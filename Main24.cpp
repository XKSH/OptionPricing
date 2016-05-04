/*!
\file Main24.cpp

\brief Test the option pricing code based on the Black--Scholes model.

This file is the first driver file implementing a solution to the
Black--Scholes model, using a standard finite differences approach, on a nodal
grid to compute the price of a put option based on its maturity date, and based
on the value of its underlying asset.

\warning This code is also listed and fully explained in the book **Numerical
Methods in Finance with C++** by Maciej Capiński and Tomasz Zastawniak,
published in September 2012.

\author: Eduardo J. Sanchez (ejspeiro) - ejspeiro at gmail dot com
*/
/*!
\mainpage Introduction

A typical reason for studying parabolic partial differential equations in
finance is the Black--Scholes equation.

Let \f$ S(t) \f$ denote the price at time \f$ t \f$ of the underlying asset
under the Black--Scholes equation. Suppose that at time \f$ t \f$ the price of
a financial derivative \f$ H(t) \f$ can be expressed using a function \f$ u
\f$, defined as:
\f[
H(t) = u(t, S (t)).
\f]
If \f$ u \f$ is a \f$ C^{1,2} \f$ function on \f$ [0,T)\times \mathbb{R} \f$,
then the Black--Scholes equation can be used to solve for \f$ u \f$.

In this project, we study how to construct a minimal framework to encode the
mechanisms implementing a standard finite difference explicit method to solve
the time-dependent portion of the Black--Scholes equation. For the ''spatial''
component, we also use standard finite differences. We use a second-order of
numerical accuracy, and we use a nodal grid.

Future work includes comparing these results with actual data and also compare
these results with an approach based on mimetic finite differences.

\sa This code is also listed and fully explained in the book Numerical
Methods in Finance with C++ by Maciej Capiński and Tomasz Zastawniak,
published in September 2012.

\warning This code is a minimally-complete example intended for research and
modeling. This is not intended to be production code.

\page page_readme Read Me File

\verbinclude README.md

\page page_architectures Tested Architectures

The following architectures have provided a correct execution of this code:

\verbatim
1. Intel(R) Core(TM) i7-4600U CPU 2.10 GHz 4096 KB of cache and a stepping of 1.
   Linux 3.16.7-29-desktop #1 SMP PREEMPT (6be6a97) x86_64 GNU/Linux
   openSUSE 13.2 (Harlequin) (x86_64)
   gcc (SUSE Linux) 4.8.3 20140627 [gcc-4_8-branch revision 212064]
\endverbatim
*/

#include <iostream>

#include "BSModel01.h"
#include "Options.h"
#include "BSEq.h"
#include "ExplicitMethod.h"

int main() {

  double S0 = 100.0;
  double r = 0.05;
  double sigma = 0.2;

  BSModel Model(S0, r, sigma);

  double K = 100.0;
  double T = 1./12.;
  double zl = 0.0;
  double zu = 2.0*S0;

  Put EuropeanPut(K, T, zl, zu);

  BSEq BSPDE(&Model, &EuropeanPut);

  int imax = 3000;
  int jmax = 1000;

  ExplicitMethod Method(&BSPDE, imax, jmax);

  Method.SolvePDE( );

  cout << "Price =" << Method.v(0.0, S0) << endl;
}

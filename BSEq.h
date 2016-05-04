/*!
\file BSEq.h

\brief Defines a class representing the Black--Scholes equation.

A typical reason for studying parabolic partial differential equations in
finance is the Black–-Scholes equation.

Let \f$ S(t) \f$ denote the price at time \f$ t \f$ of the underlying asset
under the Black–-Scholes equation. Suppose that at time \f$ t \f$ the price of
a financial derivative \f$ H(t) \f$ can be expressed using a function \f$ u
\f$, defined as:
\f[
H(t) = u(t, S (t)).
\f]
If \f$ u \f$ is a \f$ C^{1,2} \f$ function on \f$ [0,T)\times \mathbb{R} \f$,
then the Black--Scholes equation can be used to solve for \f$ u \f$.

When \f$ u(t, S(t)) \f$ is the value of an option with expiry date \f$ T \f$
and payoff \f$ H(T) = h(S(T)) \f$, then \f$ u(T, S(T)) = h(S(T)) \f$, hence the
terminal condition is
\f[
u(T, z) = h(z).
\f]
The lower and upper boundary conditions depend on the type of the option we
wish to price. They can usually be derived from heuristic or arbitrage
arguments.

For example, for a **put option** with expiry date \f$ T \f$ and strike price
\f$ K \f$, if \f$ S(t) \f$ is high, then the option is practically worthless
since it is unlikely to be exercised. This means that we can consider a
sufficiently large \f$ z_u \f$ and set:
\f[
u(t, zu) = h^{put}_u(t) = 0.
\f]
Also, if \f$ S(t) \f$ is close to zero, then we can assume that we are almost
certain to exercise the put at expiry and obtain a payoff close to \f$ K \f$.
Considering a sufficiently small positive \f$ z_l \f$ we can therefore set:
\f[
u(t, zl) = h^{put}_l(t) = exp(-r(T - t))K.
\f]

\warning This code is also listed and fully explained in the book **Numerical
Methods in Finance with C++** by Maciej Capiński and Tomasz Zastawniak,
published in September 2012.

\author: Eduardo J. Sanchez (ejspeiro) - ejspeiro at gmail dot com
*/

#ifndef BSEq_h
#define BSEq_h

#include "BSModel01.h"
#include "Options.h"
#include "ParabPDE.h"

class BSEq: public ParabPDE {
  public:
    BSModel *PtrModel;
    Option *PtrOption;

    BSEq(BSModel* PtrModel_, Option* PtrOption_);

    double a(double t, double z);
    double b(double t, double z);
    double c(double t, double z);
    double d(double t, double z);

    double f(double z);
    double fl(double t);
    double fu(double t);
};

#endif

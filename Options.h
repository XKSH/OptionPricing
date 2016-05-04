/*!
\file Options.h

\brief Definition of classes to represent an option an a put option.

We write out classes which will be used to store the coefficients and boundary
conditions in order to price options under the Black--Scholes equation. We
represent an option as an abstract class. Its methods will the overridden by the
put option class.

\warning This code is also listed and fully explained in the book **Numerical
Methods in Finance with C++** by Maciej Capiński and Tomasz Zastawniak,
published in September 2012.

\author: Eduardo J. Sanchez (ejspeiro) - ejspeiro at gmail dot com
*/

#ifndef Option_h
#define Option_h

#include "BSModel01.h"

class Option {
  public:
    double T;
    double zl;
    double zu;

    virtual double Payoff(double z) = 0;
    virtual double UpperBdCond(BSModel* PtrModel, double t) = 0;
    virtual double LowerBdCond(BSModel* PtrModel, double t) = 0;
};

class Put: public Option {
  public:
    double K;

    Put(double K_, double T_, double zl_, double zu_) {
      K = K_;
      T = T_;
      zl = zl_;
      zu = zu_;
    }
    double Payoff(double z);
    double UpperBdCond(BSModel* PtrModel, double t);
    double LowerBdCond(BSModel* PtrModel, double t);
};

#endif

// A typical reason for studying parabolic partial differential equations in
// finance is the Black–-Scholes equation.

// Let S(t) denote the price at time t of the underlying asset under the
// Black–Scholes model. Suppose that at time t the price of a financial
// derivative H(t) can be expressed using a function u, defined as:
//
// H(t) = u(t, S (t)).
//
// If u is a C^{1,2} function on [0, T)xIR, then the Black-Scholes model can be
// used to solve for u.

// When u(t, S(t)) is the value of an option with expiry date T and payoff
// H(T) = h(S(T)), then u(T, S(T)) = h(S(T)), hence the terminal condition is
//
// u(T, z) = h(z).

// The lower and upper boundary conditions depend on the type of the option we
// wish to price. They can usually be derived from heuristic or arbitrage
// arguments.

// For example, for a put option with expiry date T and strike price K, if S(t)
// is high, then the option is practically worthless since it is unlikely to be
// exercised. This means that we can consider a sufficiently large zu and set:
//
// u(t, zu) = h^{put}_u(t) = 0.

// Also, if S(t) is close to zero, then we can assume that we are almost certain
// to exercise the put at expiry and obtain a payoff close to K. Considering a
// sufficiently small positive zl we can therefore set:
//
// u(t, zl) = h^{put}_l(t) = exp(-r(T - t))K.

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

  cout << "Price = " << Method.v(0.0, S0) << endl;
}

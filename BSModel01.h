/*!
\file BSModel01.h

\brief Definition of a class using the Box--Muller method for sample paths.

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

#ifndef BSModel01_h
#define BSModel01_h

#include <cstdlib>
#include <ctime>

#include <vector>

using namespace std;

typedef vector<double> SamplePath;

class BSModel {
  public:
    double S0;
    double r;
    double sigma;

    BSModel(double S0_, double r_, double sigma_) {

      S0 = S0_;
      r = r_;
      sigma = sigma_;
      srand(time(NULL));
    }

    void GenerateSamplePath(double T, int m, SamplePath& S);
};

#endif

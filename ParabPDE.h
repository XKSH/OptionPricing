/*!
\file ParabPDE.h

\brief Definition of a class for parabolic partial differential equations.

Let us consider the parabolic partial differential equation:
\f[
\frac{\partial v(x,t)}{\partial t} = a(x,t)\frac{\partial^2 v(x,t)}{\partial
x^2} + b(x,t)\frac{\partial v(x,t)}{\partial x} + c(x,t)v(x,t) + d(x,t).
\f]
We look for a solution to this equations for \f$(t, x) \in [0, T]\times [x_l,
x_u]\f$, with \f$ x_l, x_u \in \mathbb{R} \f$ and \f$ x_l < x_u \f$. To do so we
need to impose the following boundary conditions:
\f[
v(T,x) = f(x),
\f]
\f[
v(t,x_l) = f_l(t),
\f]
\f[
v(t, x_u) = f_u(t),
\f]
where \f$ f: [x_l, x_u] \longmapsto \mathbb{R} \f$ and \f$ f_l, f_u: [0, T]
\longmapsto \mathbb{R} \f$ are given functions. We refer to \f$ f \f$ as
the **terminal boundary condition**, to \f$ f_l \f$ as the **lower boundary
condition** and to \f$ f_u \f$ as the **upper boundary condition**.

\author: Eduardo J. Sanchez (ejspeiro) - ejspeiro at gmail dot com
*/

#ifndef ParabPDE_h
#define ParabPDE_h

class ParabPDE {

  public:
    double T;
    double xl;
    double xu;

    virtual double a(double t, double x) = 0;
    virtual double b(double t, double x) = 0;
    virtual double c(double t, double x) = 0;
    virtual double d(double t, double x) = 0;

    virtual double f(double x) = 0;
    virtual double fu(double t) = 0;
    virtual double fl(double t) = 0;
};

#endif

#ifndef cord_H
#define cord_H

#pragma
#include <Imagine/Graphics.h>
using namespace Imagine;
#include <Imagine/Images.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<iostream>
using namespace std;

class cord{
public:
    int x,y;


    cord operator+(cord b) ; // Sum
    cord operator-(cord b) ; // Difference
    double norm2 () ; // Euclide an norm
    double norminf();
    void normalize();
    cord operator*(int lambda) ; // Mult . scalar
    double operator*(cord v);
    double angle(cord v);// retourne l'angle entre a et v
};
class cord_double{

public:
    double x,y;
    cord_double operator+(cord_double b) ; // Sum
    cord_double operator-(cord_double b) ; // Difference
    double norm2 () ; // Euclide an norm
    cord_double operator*(double lambda) ; // Mult . scalar
    void normalize();
    double operator*(cord_double v);
    cord_double rotation(double angle);
};
#endif // cord_H

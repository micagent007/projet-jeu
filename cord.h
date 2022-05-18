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

struct cord{
    int x,y;
};

cord operator+(cord a , cord b ) ; // Sum
cord operator-(cord a , cord b ) ; // Difference
double norm2 ( cord a ) ; // Euclide an norm
double norminf(cord a);
cord operator*(cord a , int lambda) ; // Mult . scalar
cord operator*( double lambda , cord a ) ;// Mult . scalar
double scalar(cord u, cord v);
double angle(cord v , cord u);// retourne l'angle entre v et u

class cord_double{

public:
    double x,y;
    cord_double(double x,double y);

    cord_double operator+(cord_double b) ; // Sum
    cord_double operator-(cord_double b) ; // Difference
    double norm2 () ; // Euclide an norm
    cord_double operator*(double lambda) ; // Mult . scalar
    double operator*(cord_double v);
    cord_double rotation(double angle);
};
#endif // cord_H

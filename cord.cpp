#include <Imagine/Graphics.h>
using namespace Imagine;

#include <cmath>
#include <cstdlib>
#include <ctime>
#include<iostream>
using namespace std;
#include <Imagine/Images.h>
#include "cord.h"

cord cord::operator+(cord b ) {  // Sum
    cord V={x+b.x,y+b.y};
    return V;
}
cord cord::operator-(cord b ) { // Difference
    cord V={x-b.x,y-b.y};
    return V;
}
double cord::norm2 () {   // Euclide an norm
    double N=sqrt(pow(x,2)+pow(y,2));
    return N;
}
double cord::norminf(){
    return max(abs(x),abs(y));
}
cord cord::operator*(int lambda) {  // Mult . scalar
    cord V={lambda*x,lambda*y};
    return V;
}

double cord::operator*(cord v){
    return (x*v.x+y*v.y);
}
double cord::angle(cord v){
    double S=v.x*y-v.y*x;
    if (S>=0)
            return(acos(x*v.x+y*v.y)*1/(norm2()*v.norm2()));
    return(-acos(x*v.x+y*v.y)/(norm2()*v.norm2()));
}


cord_double cord_double::operator*(double lambda) {  // Mult . scalar
    cord_double V{x*lambda,y*lambda};
    return V;
}
cord_double cord_double::operator+(cord_double b ) {  // Sum
    cord_double V={x+b.x,y+b.y};
    return V;
}
cord_double cord_double::operator-(cord_double b ) { // Difference
    cord_double V={x-b.x,y-b.y};
    return V;
}
double cord_double::norm2 () {   // Euclidean norm
    double N=sqrt(pow(x,2)+pow(y,2));
    return N;
}
cord_double operator*( double lambda , cord_double a ) { // Mult . scalar
    return a*lambda;
}
double cord_double::operator*(cord_double v){
    return (x*v.x+y*v.y);
}

cord_double cord_double::rotation(double angle){
    cord_double V{x*cos(angle)-y*sin(angle),x*sin(angle)+y*cos(angle)};
    return V;
}

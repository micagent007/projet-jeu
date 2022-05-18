#include <Imagine/Graphics.h>
using namespace Imagine;

#include <cmath>
#include <cstdlib>
#include <ctime>
#include<iostream>
using namespace std;
#include <Imagine/Images.h>
#include "cord.h"

cord operator+(cord a , cord b ) {  // Sum
    cord V={a.x+b.x,a.y+b.y};
    return V;
}
cord operator-(cord a , cord b ) { // Difference
    cord V={a.x-b.x,a.y-b.y};
    return V;
}
double norm2 ( cord a ) {   // Euclide an norm
    double N=sqrt(pow(a.x,2)+pow(a.y,2));
    return N;
}
double norminf(cord a){
    return max(abs(a.x),abs(a.y));
}
cord operator*(cord a , int lambda) {  // Mult . scalar
    cord V={lambda*a.x,lambda*a.y};
    return V;
}
cord operator*( double lambda , cord a ) { // Mult . scalar
    return (operator*(a,lambda));
}
double scalar(cord u, cord v){
    return (u.x*v.x+u.y*v.y);
}
double angle(cord v , cord u){
    double S=v.x*u.y-v.y*u.x;
    if (S>=0)
            return(acos(scalar(u,v)*1/(norm2(u)*norm2(v))));
    return(-acos(scalar(u,v)/(norm2(u)*norm2(v))));
}
cord_double::cord_double(double x,double y){
    this->x=x;
    this->y=y;
}

cord_double cord_double::operator*(double lambda) {  // Mult . scalar
    cord_double V(x*lambda,y*lambda);
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
    cord_double V(x*cos(angle)-y*sin(angle),x*sin(angle)+y*cos(angle));
    return V;
}

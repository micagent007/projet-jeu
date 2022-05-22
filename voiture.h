#ifndef voiture_H
#define voiture_H

#include <Imagine/Graphics.h>
using namespace Imagine;
#include <iostream>
using namespace std;
#include "cord.h"
#include "obstacle.h"
const double dt = 0.01;
const int freqDisplay =10;
const int wvoiture=30,hvoiture=10,xvoiture=50;
const int h=700,w=400;
const int hFloor=h-4*hvoiture;
const int vmax=100 ;

#define square(a) (a)*(a)

class voiture{
public:
    cord Pos;
    cord_double vitesse;
    int t;// corespond au trajet parcourus par la voiture en x


    double hauteur(obstacle O,int n);
    void refresh_vitess(bool accelere);
    void refresh_pos();
    voiture();
    /*void jump(int to);
    bool jumping(int to);
    double altitude(int to);*/
};

int keyboard();
Event clicks();

#endif // voiture_H

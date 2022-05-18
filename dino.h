#ifndef DINO_H
#define DINO_H

#include <Imagine/Graphics.h>
using namespace Imagine;
#include <iostream>
using namespace std;

const double wDino=20,hDino=30,xDino=25;
const double h=5*hDino,w=512;
const double hFloor=h-hDino;
const double tJump=20,hJump=3*hDino;

#define square(a) (a)*(a)

class dino{
    int t;
public:
    dino();
    int jumptime(int to);
    void jumpset(int time,int to);
    void jump(int to);
    bool jumping(int to);
    double altitude(int to);

};

//class Ball{
//    int t;
//    int x;
//public:
//    Ball();
//};

//Ball::Ball(){
//    this->x=1000;
//    this->t=0;
//}

int keyboard();

#endif // DINO_H

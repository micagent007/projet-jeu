#ifndef RECORDER_H
#define RECORDER_H

#include "voiture.h"
#include "obstacle.h"
#include "cord.h"

class Recorder{

public:
    voiture T;
    /*void display(int to);
    void action(int to);*/
    void display_obstacle(obstacle O ,int score, int& to);
};


void home_screen(int score , int record);
bool wait_screen();

void rotat_rect(int x,int y,int w,int h,cord_double tangent,Color col);

#endif // RECORDER_H

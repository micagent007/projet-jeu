#ifndef RECORDER_H
#define RECORDER_H

#include "voiture.h"
#include "obstacle.h"

class Recorder{

public:
    voiture T;
    /*void display(int to);
    void action(int to);*/
    int display_obstacle(obstacle O);
};

#endif // RECORDER_H

#ifndef RECORDER_H
#define RECORDER_H

#include "dino.h"
#include "obstacle.h"

class Recorder{
    dino T;
public:
    void display(int to);
    void action(int to);
    int display_obstacle(int to, obstacle O);
};

#endif // RECORDER_H

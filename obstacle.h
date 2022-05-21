#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "cord.h"
const int nbre_obstacle=2;

class obstacle {
public:
    int taille;
     std::vector<cord> P;
     std::vector<cord_double> D;
     obstacle(int n);
     obstacle(int t,std::vector<cord>R,std::vector<cord_double> T);
     obstacle operator+(obstacle b ) ; // Sum
     obstacle operator-(obstacle b ) ; // Diff
};

#endif // OBSTACLE_H

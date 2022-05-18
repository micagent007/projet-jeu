#include "obstacle.h"
#include "dino.h"

obstacle::obstacle(int n){
    if (n==1){
        for (int k=0;k<=3*w;k++){
            cord O={k+xDino+wDino,hFloor-k};
            P.push_back(O);
            cord_double T={1,1};
            D.push_back(T);
        }

    }
}

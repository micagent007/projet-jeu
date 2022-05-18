#include "obstacle.h"
#include "dino.h"

obstacle::obstacle(int n){
    if (n==1){
        for (int k=0;k<=300;k++){
            cord O={k,k+hFloor};
            P.push_back(O);
            cord_double T={1,1};
            D.push_back(T);
        }

    }
}

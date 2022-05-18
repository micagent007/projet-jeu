#include "obstacle.h"
#include "dino.h"

obstacle::obstacle(int n){
    if (n==1){
        for (int k=0;k<=h;k++){
            cord O={k,k+hFloor};
            P.push_back(O);
        }

    }
}

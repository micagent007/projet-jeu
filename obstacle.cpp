#include "obstacle.h"
#include "dino.h"

obstacle::obstacle(int n){
    if (n==1){
        for (int k=0;k<=w;k++){
            cord O={k+xDino+wDino,int(hFloor-pow(k,1.4)/10)};
            P.push_back(O);
            cord_double T={1,1};
            D.push_back(T);
        }
            for (int k=0;k<=w;k++){
                cord O={w+xDino+wDino+k,int(hFloor-pow(w-k,1.4)/10)};
                P.push_back(O);
                cord_double T={1,1};
                D.push_back(T);
        }

    }
}

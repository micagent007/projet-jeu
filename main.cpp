#include "voiture.h"
#include "recorder.h"
#include "obstacle.h"


int main(){
    openWindow(w,h);
    Recorder R;
    obstacle Q(0);
    obstacle O(2);
    obstacle P(1);
    obstacle T=Q+O+P;
    R.display_obstacle(T);
    int x=0;
    while(true){
        if(keyboard()==' '){
            x=R.display_obstacle(T);
            if (T.taille-w/2<x){
                obstacle P(1+rand()%nbre_obstacle);
                T=T+P;
            }

        }

    }
    endGraphics();
    return 0;
}

#include "dino.h"
#include "recorder.h"
#include "obstacle.h"

int to=200;

int main(){
    openWindow(w,h);
    Recorder R;
    obstacle Q(0);
    obstacle O(2);
    obstacle P(1);
    obstacle T=Q+O+P;
    R.display_obstacle(to,T);
    int t=0;
    while(true){
        if(keyboard()==' '){
            t=R.display_obstacle(to,T);
            milliSleep(5);
            if (T.taille-w/2<t){
                obstacle P(1+rand()%nbre_obstacle);
                T=T+P;
            }

        }

    }
    endGraphics();
    return 0;
}

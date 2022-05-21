#include "voiture.h"
#include "recorder.h"
#include "obstacle.h"


int main(){
    openWindow(w,h);
    home_screen(10,180);
    Recorder R;
    obstacle Q(0);
    obstacle O(2);
    obstacle P(1);
    obstacle T=Q+O+P;
    R.display_obstacle(T);
    int x=0;
    int x1=0,x2=0;
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
//    obstacle T(0);
//    cord_double V={1,1},N={4,8},Q={1,-1};
//    V=V*(1/V.norm2()),N=N*(1/N.norm2()),Q=Q*(1/Q.norm2());
//    clearWindow();
//    rotat_rect(500,500,70,30,Q,RED);
//    click();
//    clearWindow();
//    rotat_rect(500,500,70,30,V,RED);

}

#include "voiture.h"
#include "recorder.h"
#include "obstacle.h"


int main(){
    openWindow(w,h);
//    Recorder R;
//    obstacle Q(0);
//    obstacle O(2);
//    obstacle P(1);
//    obstacle T=Q+O+P;
//    R.display_obstacle(T);
//    int x=0;
//    while(true){
//        if(keyboard()==' '){
//            x=R.display_obstacle(T);
//            if (T.taille-w/2<x){
//                obstacle P(1+rand()%nbre_obstacle);
//                T=T+P;
//            }

//        }

//    }
    cord_double V={-3,7};
    V=V*(1/V.norm2());
    rotat_rect(200,300,50,20,V,RED);
    V={20,3};
    V=V*(1/V.norm2());
    rotat_rect(300,300,50,20,V,RED);
    endGraphics();
    return 0;
}

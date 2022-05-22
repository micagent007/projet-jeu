#include "voiture.h"
#include "recorder.h"
#include "obstacle.h"

int score=0;
int record=0;
int main(){
    openWindow(w,h);
    while(true){
        Recorder R;
        obstacle Q(0);
        int i=1+rand()%nbre_obstacle;
        obstacle O(i);
        obstacle S=Q+O;
        Event e;
        bool stop=false;
        home_screen(score,record);
        score=0;
        R.display_obstacle(S,score);
        for(int timeStep=0; timeStep<100000*freqDisplay; timeStep++) {
            if ((timeStep%freqDisplay)==0){
                bool accelere=false;
                milliSleep(5);
                if(keyboard()==' '){// pour l'instant on fait ca mais apres la commande keyboard nous dira juste qu'il faut continuer a acceler dans la vitesse si elle n'est pas la alors la moto decelere mais il faudra afficher dans tous les cas
                    R.T.t+=vmax;
                    score=R.T.t/200;
                    R.display_obstacle(S,score);
                    if (S.taille-2*w<R.T.t){
                        i=1+rand()%nbre_obstacle;
                        obstacle Q(i);
                        S=S+Q;
                    }}}
            e=clicks();
            if (e.pix.x()>0 and e.pix.x()<=30 and e.pix.y()>=0 and e.pix.y()<=40){
                stop=!wait_screen();
                if (!stop)
                    R.display_obstacle(S,score);
                else{
                    if (record<score)
                        record=score;
                    break;
                }
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

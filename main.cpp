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
        obstacle O(1+rand()%nbre_obstacle);
        obstacle S=Q+O;
        Event e;
        bool stop=false;
        int to=0;
        home_screen(score,record);
        score=0;
        R.display_obstacle(S,score,to);
        for(int timeStep=0; timeStep<100000*freqDisplay; timeStep++) {
            if ((timeStep%freqDisplay)==0){
                milliSleep(5);
                if(keyboard()==' '){// pour l'instant on fait ca mais apres la commande keyboard nous dira juste qu'il faut continuer a acceler dans la vitesse si elle n'est pas la alors la moto decelere mais il faudra afficher dans tous les cas
                    R.T.t+=vmax;
                    score=R.T.t/200;
                    R.display_obstacle(S,score,to);
                    if (S.taille-2*w<R.T.t){
                        obstacle Q(1+rand()%nbre_obstacle);
                        S=S+Q;
                    }
                }

            }
            e=clicks();
            if (e.pix.x()>0 and e.pix.x()<=30 and e.pix.y()>=0 and e.pix.y()<=40){
                stop=!wait_screen();
                if (!stop)
                    R.display_obstacle(S,score,to);
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
}

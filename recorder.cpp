#include "recorder.h"
#include "obstacle.h"
#include "voiture.h"

/*void Recorder::display(int to){
    clearWindow();
    fillRect(xvoiture,hFloor-T.altitude(to),wvoiture,-hvoiture,GREEN);
    for(int i=0;i<50;i++){
        drawRect(0-(T.jumptime(to)%16)+i*17,hFloor,15,10,BLACK);
    }
    T.jumpset(T.jumptime(to)+1,to);
}*/

int Recorder::display_obstacle(obstacle O){
    clearWindow();
    fillRect(T.Pos.x,T.hauteur(O,T.t),wvoiture,-hvoiture,GREEN);
    int n=O.P.size()-1;
    for(int i=0;i<n;i++){
            drawLine(O.P[i].x-T.t%(O.taille),O.P[i].y,O.P[i+1].x-T.t%(O.taille),O.P[i+1].y,RED,2);

    }
    T.t=T.t+vmax;// a remplacer par T.vitesse.x quand la vitesse sera faite
    return(T.t);
}

void rotat_rect(int x,int y,int w,int h,cord_double tangent, Color col){
    drawLine(x,y,x+w*tangent.x,y+w*tangent.y,col,2);
    drawLine(x,y,x+h*tangent.y,y-h*tangent.x,col,2);
    drawLine(x+h*tangent.y,y-h*tangent.x,x+h*tangent.y+w*tangent.x,y-h*tangent.x+w*tangent.y,col,2);
    drawLine(x+w*tangent.x,y+w*tangent.y,x+h*tangent.y+w*tangent.x,y-h*tangent.x+w*tangent.y,col,2);
    return;
}

/*void Recorder::action(int to){
    if(keyboard()==' '){
        T.jump(to);
        //ici la condition de fin de saut est déjà dans présente dans la fonction jump
    }

}*/

#include "recorder.h"
#include "obstacle.h"

void Recorder::display(int to){
    clearWindow();
    fillRect(xDino,hFloor-T.altitude(to),wDino,-hDino,GREEN);
    for(int i=0;i<50;i++){
        drawRect(0-(T.jumptime(to)%16)+i*17,hFloor,15,10,BLACK);
    }
    T.jumpset(T.jumptime(to)+1,to);
}

void Recorder::display_obstacle(int to, obstacle O){
    clearWindow();
    fillRect(xDino,hFloor-T.altitude(to),wDino,-hDino,GREEN);
    int n=O.P.size();
    for(int i=0;i<=n-w+1;i++){
            drawRect(O.P[i].x-T.jumptime(to)%w,O.P[i].y-T.jumptime(to)%w,1,1,RED);

    }

}

void Recorder::action(int to){
    if(keyboard()==' '){
        T.jump(to);
        //ici la condition de fin de saut est déjà dans présente dans la fonction jump
    }

}

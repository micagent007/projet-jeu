#include "recorder.h"

void Recorder::display(int to){
    clearWindow();
    fillRect(xDino,hFloor-T.altitude(to),wDino,-hDino,GREEN);
    for(int i=0;i<50;i++){
        drawRect(0-(T.jumptime(to)%16)+i*17,hFloor,15,10,BLACK);
    }
    T.jumpset(T.jumptime(to)+1,to);
}

void Recorder::action(int to){
    if(keyboard()==' '){
        T.jump(to);
        //ici la condition de fin de saut est déjà dans présente dans la fonction jump
    }

}

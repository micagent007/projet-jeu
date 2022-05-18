#include "dino.h"

dino::dino(){
    t=0;
}

int dino::jumptime(int to){
    return t;
}

int dino::jumpset(int time,int to){
    t=time;
    return(t);
}

bool dino::jumping(int to){
    if(t>tJump or t<0)
        return  false;
    else
        return true;
}

void dino::jump(int to){
    if(this->jumping(to)==true){
        return;
    }
    else{
        t=0;
    }
}

double dino::altitude(int to){
    if(this->jumping(to)==false){
        return 0;
    }
    else {
        double h=hJump*(1-square(1-2*(to-this->t)/(tJump)));
        return h;
    }
}

int keyboard() {
    Event e;
    do {
        getEvent(0,e);
        if(e.type==EVT_KEY_ON)
            return e.key;
    } while(e.type!=EVT_NONE);
    return 0;
}

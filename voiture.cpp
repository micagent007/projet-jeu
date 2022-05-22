#include "voiture.h"

voiture::voiture(){
    Pos={xvoiture,hFloor};
    vitesse={0.,0.};
    t=0;
}

double voiture::hauteur(obstacle O,int t){
    int alt = O.P[t].y;
    return alt;
}

void voiture::refresh_vitess(bool accelere){ // a modif
    if (vitesse.x<vmax and accelere)
        vitesse.x+=1;
    if (vitesse.x>0 and !accelere)
        vitesse.x-=1;

}

void voiture::refresh_pos(){
    t+=vitesse.x;
}
/*bool voiture::jumping(int to){
    if(t>tJump or t<0)
        return  false;
    else
        return true;
}

void voiture::jump(int to){
    if(this->jumping(to)==true){
        return;
    }
    else{
        t=0;
    }
}

double voiture::altitude(int to){
    if(this->jumping(to)==false){
        return 0;
    }
    else {
        double h=hJump*(1-square(1-2*(to-this->t)/(tJump)));
        return h;
    }
}*/



int keyboard() {
    Event e;
    do {
        getEvent(0,e);
        if(e.type==EVT_KEY_ON)
            return e.key;
    } while(e.type!=EVT_NONE);
    return 0;
}

Event clicks(){
    Event e;
    do {
        getEvent(0,e);
        if(e.type==EVT_BUT_ON)
            return e;
    } while(e.type!=EVT_NONE);
    return(e);
}

#include "voiture.h"

voiture::voiture(){
    Pos={xvoiture,hFloor};
    vitesse={0.,0.};
    t=0;
}

double voiture::hauteur(obstacle O,int t){
    int saut=hFloor-max(0,O.P[t].x-200)*max(0,300-O.P[t].x)/10;
    int alt = O.P[t].y;
    return saut;
}

// je teste des trucs pour le saut
//bool voiture::is_jumping(obstacle O,int t){
//    if(this->hauteur(O,t)>O.P[t].y)
//        return true;
//    else
//        return false;
//}

void voiture::increase(int v){
    double N=vitesse.norm2();
    vitesse.normalize();
    vitesse.x=(N+v)*vitesse.x;
    vitesse.y=(N+v)*vitesse.y;
    return;
}

void voiture::refresh_vitess(bool accelere){ // a faire
    if (vitesse.norm2()<vmax and accelere)
        this->increase(1);
    if (vitesse.norm2()>1 and !accelere)
        this->increase(-1);
    return;
}

void voiture::refresh_pos(){// a faire
    t+=vitesse.x;
}

/*
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

#include "voiture.h"

voiture::voiture(){
    Pos={xvoiture,hFloor};
    vitesse={0.,0.};
    t=0;
    tangente={0.,0.};
}

bool collision (obstacle O){

};


double voiture::hauteur(obstacle O,int t){
    //double saut=hFloor-max(0,O.P[t].x-200)*max(0,300-O.P[t].x)/10;
    int alt = O.P[t].y;
    return alt;
}

double voiture::hauteur_jump(obstacle O, int t,int to){
    double alt = O.P[to].y-(9.81*pow(O.P[t].x-O.P[to].x,2))/(2*pow(this->vitesse.x,2))-(this->vitesse.y/this->vitesse.x)*(O.P[t].x-O.P[to].x);
    return alt;
}

bool voiture::is_jumping(obstacle O,int t,int to){
   if(this->hauteur_jump(O,t,to)<O.P[t].y)
        return true;
    else
        return false;
}

bool voiture::can_jump(obstacle O, int t){
    double alt=O.P[t].y-(9.81/(2*pow(this->vitesse.x,2)))+this->vitesse.y/this->vitesse.x;
    if(alt<O.P[t+1].y)
        return true;
    else
        return false;
}

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
    t+=vitesse.x*dt;
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

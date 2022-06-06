#include "recorder.h"
#include "obstacle.h"
#include "voiture.h"

void Recorder::display_obstacle(obstacle O,int score){
    clearWindow();
    setBackGround(AlphaColor(26, 42, 35 ));
    fillRect(10,10,8,30,WHITE);
    fillRect(20,10,8,30,WHITE);
    drawString(w/2-50,h/8,to_string(score),WHITE,50);
    int to=0;
    if(!T.is_jumping(O,T.t+xvoiture,to)){
        if(T.can_jump(O,T.t+xvoiture)){
            to=T.t;
            rotat_rect(T.Pos.x,T.hauteur_jump(O,T.t+xvoiture,to),wvoiture,hvoiture,O.D[T.t+xvoiture],GREEN);
            cout << "c" <<endl;
        }
        else {
            rotat_rect(T.Pos.x,T.hauteur(O,T.t+xvoiture),wvoiture,hvoiture,O.D[T.t+xvoiture],GREEN);
            cout << "b" <<endl;
        }
    }
    else {
        rotat_rect(T.Pos.x,min(T.hauteur(O,T.t+xvoiture),T.hauteur_jump(O,T.t+xvoiture,to)),wvoiture,hvoiture,O.D[T.t+xvoiture],GREEN);
        cout << "A" <<endl;
    }
    int n=O.P.size()-1;
    for(int i=0;i<=w;i++){
        drawLine(i,O.P[i+T.t].y,i+1,O.P[i+1+T.t].y,Color(249, 13, 253),2);
    }
    //cout << O.P[T.t+xvoiture].x << endl;
    return;
}

void rotat_rect(int x,int y,int w,int h,cord_double tangent, Color col){
    drawLine(x,y,x+w*tangent.x,y+w*tangent.y,col,2);
    drawLine(x,y,x+h*tangent.y,y-h*tangent.x,col,2);
    drawLine(x+h*tangent.y,y-h*tangent.x,x+h*tangent.y+w*tangent.x,y-h*tangent.x+w*tangent.y,RED,2);
    drawLine(x+w*tangent.x,y+w*tangent.y,x+h*tangent.y+w*tangent.x,y-h*tangent.x+w*tangent.y,col,2);
    return;
}



void home_screen(int score , int record){
    clearWindow();
    setBackGround(AlphaColor(26, 42, 35 ));
    drawString(w/6,h/5,"RIDER",AlphaColor(249, 13, 253),52);
    drawString(w/6+5,h/5,"RIDER",WHITE,50);
    drawString(w/6+10,h/5+h/6+20,"SCORE",WHITE,15);
    drawString(4*w/6-30,h/5+h/6+20,"RECORD",WHITE,15);
    drawString(w/6,h/5+h/8+20,to_string(score),WHITE,50);
    drawString(3*w/6+30,h/5+h/8+20,to_string(record),WHITE,50);
    fillCircle(w/2,2*h/3,120,WHITE);
    int xy[12];
    xy[0]=w/2+80,
            xy[1]=2*h/3,
            xy[2]=w/2-40,
            xy[3]=2*h/3-80*(sqrt(3)/2),
            xy[4]=w/2-40,
            xy[5]=2*h/3+80*(sqrt(3)/2);
    fillPoly(xy,3,AlphaColor(26, 42, 35 ));
    int x,y;
    getMouse(x,y);
    while(sqrt(pow(x-w/2,2)+pow(y-2*h/3,2))>120)
        getMouse(x,y);
}
bool wait_screen(){
    fillRect(w/8,h/4+40,6*w/8,200,BLACK);
    fillRect(w/8,h/4,6*w/8,40,AlphaColor(109, 112, 106));
    fillRect(w/8+25,h/2-90,5*w/8,40,WHITE);
    fillRect(w/8+25,h/2,5*w/8,40,WHITE);
    drawRect(w/8,h/4+40,6*w/8,200,WHITE);
    drawRect(w/8,h/4,6*w/8,40,WHITE);
    drawString(2*w/8+10,h/4+30,"Partie en pause",WHITE,15);
    drawString(w/8+90,h/2-60,"continuer",BLACK,15);
    drawString(w/8+65,h/2+30,"retour au menu",BLACK,15);

    int x,y;
    getMouse(x,y);
    while(!(x>=w/8+25 and x<=7*w/8 and y>=h/2-90 and y<=h/2-50) and !(x>=w/8+25 and x<=7*w/8 and y>=h/2 and y<=h/2+40))
        getMouse(x,y);
    if (x>=w/8+25 and x<=7*w/8 and y>=h/2-90 and y<=h/2-50)
        return(true);
    return(false);
}


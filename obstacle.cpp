#include "obstacle.h"
#include "voiture.h"


// T a faire sur tous les obstacles
obstacle::obstacle(int n){
    if (n==0){
        for (int k=0;k<=(w/2);k++){
            cord O={k+xvoiture+wvoiture,hFloor-k};
            P.push_back(O);
            cord_double T={1,-1};
            T.normalize();
            D.push_back(T);}
        for (int k=0;k<=(w/2);k++){
            cord O={w/2+xvoiture+wvoiture+k,hFloor-w/2+k};
            P.push_back(O);
            cord_double T={1,1};
            T.normalize();
            D.push_back(T);}
        taille=P[P.size()-1].x;

    }
    if (n==1){
        for (int k=0;k<=w;k++){
            cord O={k,int(hFloor-pow(k,1.4)/10)};
            P.push_back(O);
            cord_double T={1,-1.4*pow(k,0.4)/10};
            T.normalize();
            D.push_back(T);
        }
        for (int k=0;k<=w;k++){
            cord O={w+k,int(hFloor-pow(w-k,1.4)/10)};
            P.push_back(O);
            cord_double T={1,1.4*pow(k,0.4)/10};
            T.normalize();
            D.push_back(T);
        }
        taille=P[P.size()-1].x;

    }
    if (n==2){
        for (double k=0;k<=2*w;k++){
            cord O={int(k),int(hFloor-(h/3)*sin(((2*M_PI*k)/w)-M_PI/2)-h/3)};
            P.push_back(O);
            cord_double T={1,-(h/3)*(2*M_PI/w)*cos(((2*M_PI*k)/w)-M_PI/2)};
            T.normalize();
            D.push_back(T);
        }
        taille=P[P.size()-1].x;
    }
}
obstacle::obstacle(int t,std::vector<cord>R,std::vector<cord_double> T){
    taille=t;
    P=R;
    D=T;
};
obstacle obstacle:: operator+(obstacle b){// Sum
    int t=taille+b.taille;
    std::vector<cord> R=P;
    for (int k=0;k<b.P.size();k++)
        R.push_back({b.P[k].x+P[P.size()-1].x,b.P[k].y});
    std::vector<cord_double> T=D;
    for (int k=0;k<b.D.size();k++)
        T.push_back(b.D[k]);
    obstacle F={t,R,T};
    return(F);
} ;

obstacle obstacle:: operator-(obstacle b){// Sum
    int t=taille-b.taille;
    std::vector<cord> R;
    for (int k=b.P.size();k<P.size();k++)
        R.push_back({P[k].x+b.P[b.P.size()-1].x,P[k].y});
    std::vector<cord_double> T;
    for (int k=b.P.size();k<P.size();k++)
        T.push_back(D[k]);
    obstacle F={t,R,T};
    return(F);
} ;


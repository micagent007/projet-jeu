#include "obstacle.h"
#include "voiture.h"


// T a faire sur tous les obstacles
obstacle::obstacle(int n){
    if (n==0){
        for(int k=0;k<w/5;k++){//sol plat sur 1/5 de l'écran
            cord O={k,hFloor};
            P.push_back(O);
            cord_double T={1,0};
            T.normalize();
            D.push_back(T);}
        for (int k=w/5;k<=(3*w/5);k++){//affine croissante sur 2/5 de l'écran
            cord O={k,hFloor-k+w/5};
            P.push_back(O);
            cord_double T={1,-1};
            T.normalize();
            D.push_back(T);}
        for (int k=3*w/5;k<=w;k++){//affine décroissante sur 2/5 de l'écran
            cord O={k,hFloor+k-w};
            P.push_back(O);
            cord_double T={1,1};
            T.normalize();
            D.push_back(T);}
        taille=P[P.size()-1].x;

    }
    if (n==1){
        for(int k=0;k<w/10;k++){//sol plat sur 1/10 de l'écran
            cord O={k,hFloor};
            P.push_back(O);
            cord_double T={1,0};
            T.normalize();
            D.push_back(T);}

        for (int k=0;k<=w;k++){//courbe puissance croissant sur 1/2 de l'écran
            cord O={k+w/10,int(hFloor-pow(k,1.4)/10)};
            P.push_back(O);
            cord_double T={1,-1.4*pow(k,0.4)/10};
            T.normalize();
            D.push_back(T);
        }

        for(int k=0;k<w/10;k++){//sol plat sur 1/10 de l'écran
            cord O={21*w/10+k,hFloor};
            P.push_back(O);
            cord_double T={1,0};
            T.normalize();
            D.push_back(T);}

        for (int k=0;k<=w;k++){//courbe puissance décroissante sur 1/2 de l'écran
            cord O={11*w/10+k,int(hFloor-pow(w-k,1.4)/10)};
            P.push_back(O);
            cord_double T={1,1.4*pow(w-k,0.4)/10};
            T.normalize();
            D.push_back(T);
        }
        for(int k=0;k<w/10;k++){//sol plat sur 1/10 de l'écran
            cord O={21*w/10+k,hFloor};
            P.push_back(O);
            cord_double T={1,0};
            T.normalize();
            D.push_back(T);}

        taille=P[P.size()-1].x;

    }
    if (n==2){
        for(int k=0;k<w/10;k++){//sol plat sur 1/10 de l'écran
            cord O={k,hFloor};
            P.push_back(O);
            cord_double T={1,0};
            T.normalize();
            D.push_back(T);}
        for (int k=w/10;k<=3*w/10;k++){//affine croissante sur 1/5 de l'écran
            cord O={k,hFloor-2*k+2*w/10};
            P.push_back(O);
            cord_double T={1,-2};
            T.normalize();
            D.push_back(T);}
        for(int k=0;k<w/10;k++){//sol plat sur 1/10 de l'écran
            cord O={k+3*w/10,hFloor-4*w/10};
            P.push_back(O);
            cord_double T={1,0};
            T.normalize();
            D.push_back(T);}
        for (double k=0;k<=2*w;k++){//courbe sin sur 2 fois la largeur de l'écran
            cord O={int(k+4*w/10),hFloor-int((h/6)*sin(((2*M_PI*k)/w)-M_PI/2))-h/6-4*w/10};
            P.push_back(O);
            cord_double T={1,-(h/6)*(2*M_PI/w)*cos(((2*M_PI*k)/w)-M_PI/2)};
            T.normalize();
            D.push_back(T);
        }
        for(int k=0;k<w/10;k++){//sol plat sur 1/10 de l'écran
            cord O={k+24*w/10,hFloor-4*w/10};
            P.push_back(O);
            cord_double T={1,0};
            T.normalize();
            D.push_back(T);}
        for (int k=0;k<=2*w/10;k++){//affine croissante sur 1/5 de l'écran
            cord O={k+25*w/10,hFloor+2*k-4*w/10};
            P.push_back(O);
            cord_double T={1,2};
            T.normalize();
            D.push_back(T);}
        for(int k=0;k<w/10;k++){//sol plat sur 1/10 de l'écran
            cord O={k+27*w/10,hFloor};
            P.push_back(O);
            cord_double T={1,0};
            T.normalize();
            D.push_back(T);}
        taille=P[P.size()-1].x;
    }
    if (n==3){
        for(int k=0;k<w/10;k++){//sol plat sur 1/10 de l'écran
            cord O={k,hFloor};
            P.push_back(O);
            cord_double T={1,0};
            T.normalize();
            D.push_back(T);}
        for (int k=w/5;k<=3*w/5;k++){//affine croissante sur 2/5 de l'écran
            cord O={k,hFloor-2*k+2*w/5};
            P.push_back(O);
            cord_double T={1,-2};
            T.normalize();
            D.push_back(T);}
        for (int k=3*w/5;k<=4*w/5;k++){//cercle sur 1/5 de l'écran vers le haut
            cord O={k,hFloor-3*w/5-int(sqrt(pow((90 ),2)-pow((k-7*w/10),2)+w/5))};
            P.push_back(O);
            cord_double T={1,(k-7*w/10)/sqrt(pow((90 ),2)-pow((k-7*w/10),2))};
            T.normalize();
            D.push_back(T);}

        for (int k=0;k<=2*w/5;k++){//affine décroissante sur 1/5 de l'écran
            cord O={4*w/5+k,hFloor+k-4*w/5};
            P.push_back(O);
            cord_double T={1,1};
            T.normalize();
            D.push_back(T);}

        for (int k=3*w/5;k<=4*w/5;k++){//cercle sur 1/5 de l'écran vers le bas
            cord O={k+3*w/5,hFloor-3*w/5+int(sqrt(pow((90 ),2)-pow((k-7*w/10),2)+w/5))};
            P.push_back(O);
            cord_double T={1,-(k-7*w/10)/sqrt(pow((90 ),2)-pow((k-7*w/10),2))};
            T.normalize();
            D.push_back(T);}


        for (int k=0;k<=2*w/5;k++){//affine décroissante sur 1/5 de l'écran
            cord O={7*w/5+k,hFloor-k-2*w/5};
            P.push_back(O);
            cord_double T={1,-1};
            T.normalize();
            D.push_back(T);}

        for (int k=3*w/5;k<=4*w/5;k++){//cercle sur 1/5 de l'écran vers le haut
            cord O={k+6*w/5,hFloor-3*w/5-int(sqrt(pow((90 ),2)-pow((k-7*w/10),2)+w/5))};
            P.push_back(O);
            cord_double T={1,(k-7*w/10)/sqrt(pow((90 ),2)-pow((k-7*w/10),2))};
            T.normalize();
            D.push_back(T);}

        for (int k=w/5;k<=3*w/5;k++){//affine croissante sur 2/5 de l'écran
            cord O={k+9*w/5,hFloor-6*w/5+2*k};
            P.push_back(O);
            cord_double T={1,2};
            T.normalize();
            D.push_back(T);}

        for(int k=0;k<w/10;k++){//sol plat sur 1/10 de l'écran
            cord O={k+12*w/5,hFloor};
            P.push_back(O);
            cord_double T={1,0};
            T.normalize();
            D.push_back(T);}

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
    obstacle F(t,R,T);
    return(F);
} ;

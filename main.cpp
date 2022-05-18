#include "dino.h"
#include "recorder.h"

const int to=20;

int main(){
<<<<<<< HEAD
    openWindow(w,h);
    Recorder R;
    while(true){
        R.display(to);
        R.action(to);
        milliSleep(5);
=======
    openWindow(512,512);
    int x,y,x1=0,y1=0,x2=0,y2=0;
    getMouse(x,y);
    x1=x;
    y1=y;

    while (true){
        if (getMouse(x2,y2)==1){
            drawLine(x1,y1,x2,y2,RED);
            x1=x2;
            y1=y2;
        }
        else
            drawLine(x,y,x2,y2,RED);

>>>>>>> 1595784f6f3f69fd81c2158c9e8e807750989e80
    }
    endGraphics();
    return 0;
}

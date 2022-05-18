#include "dino.h"
#include "recorder.h"

const int to=20;

int main(){
    openWindow(w,h);
    Recorder R;
    while(true){
        R.display(to);
        R.action(to);
        milliSleep(5);
    }
    endGraphics();
    return 0;
}

#include "dino.h"
#include "recorder.h"

const int to=200;

int main(){
    openWindow(w,h);
    Recorder R;
    R.display(to);
    while(true){
        if(keyboard()==' '){
            R.display(to);
            milliSleep(5);
        }

    }
    endGraphics();
    return 0;
}

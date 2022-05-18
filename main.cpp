#include "dino.h"
#include "recorder.h"
#include "obstacle.h"

const int to=200;

int main(){
    openWindow(w,h);
    Recorder R;
    obstacle O(1);
    R.display_obstacle(to,O);
    while(true){
        if(keyboard()==' '){
            R.display_obstacle(to,O);
            milliSleep(5);
        }

    }
    endGraphics();
    return 0;
}

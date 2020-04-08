#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2_image/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include"Background.h"
#include"Ball.h"
#include"Bat.h"
#include<time.h>
//#include"Text.h"

#include"Player.h"
using namespace std;
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT=480;
int main(){
	//TTF_Init();
	Background bg;
	bg.run();
    bg.clean();
}

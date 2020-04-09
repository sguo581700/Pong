#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2_image/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include"Background.h"
#include"Ball.h"
#include"Bat.h"
#include<time.h>

#include"Player.h"
using namespace std;

int main(){
	Background bg;
	bg.run();
    bg.clean();
}



#ifndef BAT_H_
#define BAT_H_
#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2_image/SDL_image.h>
#include<string>
#include<SDL2/SDL_ttf.h>
#include "Background.h"
using namespace std;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
class Bat{
private:
	int bat_width;
	int bat_height;
	int bat_pos_x;
	int bat_pos_y;
	int bat_v_x = 40;
	int bat_v_y = 40;
public:
	Bat(){
		bat_width = SCREEN_WIDTH/10;
		bat_height= SCREEN_HEIGHT/60;
		bat_pos_x=(SCREEN_WIDTH-bat_width)/2;
		bat_pos_y=this->get_screen_height()-this->get_bat_height();
	}
	SDL_Rect*bat_rect(int x, int y){
		SDL_Rect*r=new SDL_Rect();
		r->x = x;
		r->y = y;
		r->w = bat_width;
		r->h = bat_height;
		return r;
	}

	void bat_move(clock_t x){
		bat_pos_x += bat_v_x/x;
		if(bat_pos_x<0||bat_pos_x+this->get_bat_width()>this->get_screen_width()){
			bat_pos_x-= bat_v_x/x;
		}
		bat_pos_y +=bat_v_y;
		if(bat_pos_y<0||bat_pos_y+this->get_bat_height()>this->get_screen_height()){
			bat_pos_y-= bat_v_y;
		}
	}
	void bat_handle_event(SDL_Event& e){
		if(e.type==SDL_KEYDOWN){
			if(e.key.keysym.sym==SDLK_LEFT){bat_pos_x -= bat_v_x; if(bat_pos_x<=0){bat_pos_x=0;}}
			else if(e.key.keysym.sym==SDLK_RIGHT){bat_pos_x += bat_v_x;if(bat_pos_x>=this->get_screen_width()-this->get_bat_width()){bat_pos_x=this->get_screen_width()-this->get_bat_width();}}
		}
	}
	int get_bat_width(){return bat_width;}
	int get_bat_height(){return bat_height;}
	int get_screen_width(){return SCREEN_WIDTH;}
	int get_screen_height(){return SCREEN_HEIGHT;}
	int get_bat_pos_x(){return bat_pos_x;}
	int get_bat_pos_y(){return bat_pos_y;}
};
#endif 


#ifndef BAT_H_
#define BAT_H_
#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<string>
#include<SDL2/SDL_ttf.h>
#include "Background.h"
using namespace std;
const double SCREEN_WIDTH = 800;
const double SCREEN_HEIGHT = 600;
class Bat{
private:
	double bat_width;
	double bat_height;
	double bat_pos_x;
	double bat_pos_y;
	double bat_v_y;
	double BAT_VEL =15;
	SDL_Rect*r=nullptr;

public:
	Bat(double x, double y){

		bat_width = SCREEN_WIDTH/60;
		bat_height= SCREEN_HEIGHT/8;
		bat_pos_x=x;
		bat_pos_y=y;
		bat_v_y=0;
		r=new SDL_Rect();
	}
	~Bat(){
		delete r;
	}
	SDL_Rect*bat_rect(double x, double y){
		this->r->x = x;
		this->r->y = y;
		this->r->w = bat_width;
		this->r->h = bat_height;
		return r;
	}

	
	void bat_R_handle_event(SDL_Event& e){
		if(e.type==SDL_KEYDOWN && e.key.repeat==0){
			if(e.key.keysym.sym==SDLK_UP){bat_v_y -= BAT_VEL; }
			else if(e.key.keysym.sym==SDLK_DOWN){bat_v_y += BAT_VEL;}
		}else if(e.type==SDL_KEYUP){
			if(e.key.keysym.sym==SDLK_UP){bat_v_y += BAT_VEL; }
			else if(e.key.keysym.sym==SDLK_DOWN){bat_v_y -= BAT_VEL;}
		}
	}
	void bat_L_handle_event(SDL_Event& e){
		if(e.type==SDL_KEYDOWN && e.key.repeat == 0){
			if(e.key.keysym.sym==SDLK_w){bat_v_y -= BAT_VEL; }
			else if(e.key.keysym.sym==SDLK_s){bat_v_y += BAT_VEL;}
		}else if(e.type==SDL_KEYUP){
			if(e.key.keysym.sym==SDLK_w){bat_v_y += BAT_VEL; }
			else if(e.key.keysym.sym==SDLK_s){bat_v_y -= BAT_VEL;}
		}
	}
	void bat_move(){
		bat_pos_y+=bat_v_y;
		if(bat_pos_y<=bat_width){bat_pos_y=bat_width;}
		if(bat_pos_y>=SCREEN_HEIGHT-bat_height-bat_width){bat_pos_y=SCREEN_HEIGHT-bat_height-bat_width;}
	}
	
	double get_bat_width(){return bat_width;}
	double get_bat_height(){return bat_height;}
	double get_screen_width(){return SCREEN_WIDTH;}
	double get_screen_height(){return SCREEN_HEIGHT;}
	double get_bat_pos_x(){return bat_pos_x;}
	double get_bat_pos_y(){return bat_pos_y;}
};
#endif 
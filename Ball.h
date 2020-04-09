#ifndef BALL_H_
#define BALL_H_
#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2_image/SDL_image.h>
#include<string>
#include<SDL2/SDL_ttf.h>
#include "Background.h"
#include "Bat.h"
#include <math.h>
using namespace std;

class Ball{
private:
	int ball_width;
	int ball_height;
	int ball_pos_x;
	int ball_pos_y;
	float ball_v_x = 0.2;
	float ball_v_y = 0.2;
	bool collision_detected = false;
public:
	Ball(){
		ball_width = SCREEN_WIDTH/100;
		ball_height= SCREEN_HEIGHT/100;
		ball_pos_x=SCREEN_WIDTH/2;
		ball_pos_y=0;
	}

	SDL_Rect*ball_rect(int x, int y){
		SDL_Rect*r=new SDL_Rect();
		r->x = x;
		r->y = y;
		r->w = ball_width;
		r->h = ball_height;
		return r;
	}
	void ball_move(Bat*bat, float dt, Player*player){
		ball_pos_y+=ball_v_y*dt;
		ball_pos_x+=ball_v_x*dt;
		if(ball_pos_x>this->get_screen_width()-this->get_ball_width()){
			velocityX_reversed();
		}
		if(ball_pos_x<0){
			velocityX_reset();
		}
		if(collision(bat)){
			player->set_score();
			velocityY_reversed();
		}else{
			if(ball_pos_y>this->get_screen_height()){
				player->lose_chances();
				this->reset_position();
			}
		}
		if(ball_pos_y<0){
				velocityY_reset();
		}

	}
	void reset_position(){ball_pos_x=SCREEN_WIDTH/2;
		ball_pos_y=0;}
	void velocityY_reversed(){ball_v_y=-ball_v_y;}
	void velocityX_reversed(){ball_v_x=-ball_v_x;}
	void velocityX_reset(){ball_v_x=abs(ball_v_x);}
	void velocityY_reset(){ball_v_y=abs(ball_v_y);}
	int get_ball_width(){return ball_width;}
	int get_ball_height(){return ball_height;}
	int get_screen_width(){return SCREEN_WIDTH;}
	int get_screen_height(){return SCREEN_HEIGHT;}
	int get_ball_pos_x(){return ball_pos_x;}
	int get_ball_pos_y(){return ball_pos_y;}
	bool collision(Bat*bat){
		if(this->get_ball_pos_x()>=bat->get_bat_pos_x() && this->get_ball_pos_x()<=(bat->get_bat_pos_x()+bat->get_bat_width())&&this->get_ball_pos_y()>=(this->get_screen_height()-bat->get_bat_height())){
			return collision_detected = true;
		}
		return collision_detected = false;
	}

};
#endif 
#ifndef BALL_H_
#define BALL_H_
#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<string>
#include<SDL2/SDL_ttf.h>
#include "Background.h"
#include "Bat.h"
#include <math.h>
using namespace std;

class Ball{
private:
	double ball_width;
	double ball_height;
	double ball_pos_x;
	double ball_pos_y;
	double ball_v_x = 0.4;
	double ball_v_y = 0.4;
	SDL_Rect*r =nullptr;
public:
	Ball(){
		ball_width = SCREEN_WIDTH/100;
		ball_height= ball_width;
		ball_pos_x=SCREEN_WIDTH/2;
		ball_pos_y=SCREEN_HEIGHT/2;
		r = new SDL_Rect();
	}
	~Ball(){
		delete r;
	}
	SDL_Rect*ball_rect(double x, double y){
		this->r->x = x;
		this->r->y = y;
		this->r->w = ball_width;
		this->r->h = ball_height;
		return r;
	}
	void ball_move(Bat*bat_R, Bat*bat_L, double dt, Player*player_one, Player*player_two){
		ball_pos_x+=ball_v_x*dt;
		ball_pos_y+=ball_v_y*dt;
		if(ball_pos_y>(SCREEN_HEIGHT-ball_height)){
			velocityY_reverse();
		}
		if(ball_pos_y>bat_L->get_bat_pos_y()-ball_height&& ball_pos_y<(bat_L->get_bat_pos_y()+bat_L->get_bat_height()-ball_height) && ball_pos_x<bat_L->get_bat_width()*4){
			if(ball_pos_y< (bat_L->get_bat_pos_y()+bat_L->get_bat_height()/2)){
				if(ball_v_y>0&&ball_v_x<0){
					velocityY_reverse();
					velocityX_reset();
				}
				if(ball_v_y<0&&ball_v_x<0){
					velocityX_reverse();
				}
				if(ball_v_x<0&&ball_v_y==0){velocityX_reverse();velocityY_reset(); velocityY_reverse();}
			}
			if(ball_pos_y==bat_L->get_bat_pos_y()+bat_L->get_bat_height()/2){straight_right();}
			if(ball_pos_y>(bat_L->get_bat_pos_y()+bat_L->get_bat_height()/2) ){
				if(ball_v_y>0&&ball_v_x<0){
					velocityX_reset();
					velocityY_reset();
				}
				if(ball_v_y<0&&ball_v_x<0){
					velocityX_reset();
				}
				if(ball_v_x<0&&ball_v_y==0){velocityX_reverse();velocityY_reset();}
			}
		}
		if(ball_pos_y>=bat_R->get_bat_pos_y()&&ball_pos_y<(bat_R->get_bat_pos_y()+bat_R->get_bat_height()-ball_height) && ball_pos_x>SCREEN_WIDTH-bat_R->get_bat_width()*4-ball_width){
			if(ball_pos_y<bat_R->get_bat_pos_y()+bat_R->get_bat_height()/2){
				if(ball_v_y>0&&ball_v_x>0){
					velocityY_reverse();
					velocityX_reverse();
				}
				if(ball_v_y<0&&ball_v_x>0){
					velocityX_reverse();
				}
				if(ball_v_x>0&&ball_v_y==0){velocityX_reset(); velocityY_reset(); velocityY_reverse();}
			}
			if(ball_pos_y==bat_R->get_bat_pos_y()+bat_R->get_bat_height()/2){straight_left();}
			if(ball_pos_y> (bat_R->get_bat_pos_y()+bat_R->get_bat_height()/2)){
				if(ball_v_y>0&&ball_v_x>0){
					velocityX_reverse();
				}
				if(ball_v_y<0&&ball_v_x>0){
					velocityX_reverse();
					velocityY_reset();
				}
				if(ball_v_x>0&&ball_v_y==0){velocityX_reset(); velocityY_reset();}
			}
		}
		if(ball_pos_x>SCREEN_WIDTH){ player_one->set_score();reset_position();}
		if(ball_pos_x<0){player_two->set_score();reset_position();}
		if(ball_pos_y<=0){
			velocityY_reverse();
		}
	}
	void reset_position(){ball_pos_y=SCREEN_HEIGHT/2;
		ball_pos_x=SCREEN_WIDTH/2;}
	void velocityY_reverse(){ball_v_y=-ball_v_y;}
	void velocityX_reverse(){ball_v_x=-ball_v_x;}
	void velocityX_reset(){ball_v_x=0.4;}
	void velocityY_reset(){ball_v_y=0.4;}
	void straight_right(){velocityX_reset(); ball_v_y=0;}
	void straight_left(){velocityX_reverse();ball_v_y=0;}
	double get_ball_width(){return ball_width;}
	double get_ball_height(){return ball_height;}
	double get_screen_width(){return SCREEN_WIDTH;}
	double get_screen_height(){return SCREEN_HEIGHT;}
	double get_ball_pos_x(){return ball_pos_x;}
	double get_ball_pos_y(){return ball_pos_y;}
};
#endif 
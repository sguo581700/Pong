
#ifndef GAMEENGINE_H_
#define GAMEENGINE_H_

#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include"Background.h"
#include"Ball.h"
#include"Bat.h"
#include<time.h>
#include"Player.h"
using namespace std;

class GameEngine{
private:
		Player*player_one=nullptr;
		Player*player_two=nullptr;
		Ball*ball = nullptr;
		Background*bg = nullptr;
		Bat*bat_R=nullptr;
		Bat*bat_L=nullptr;
		double t0;
		double t1;
		double dt;
		bool running=true;

public:
	GameEngine(){
		player_one = new Player();
		player_two = new Player();

		ball = new Ball();
		bg = new Background();
		bat_R = new Bat(SCREEN_WIDTH-(SCREEN_WIDTH/60)*4, (SCREEN_HEIGHT-SCREEN_HEIGHT/8)/2);
		bat_L = new Bat((SCREEN_WIDTH/60)*3,(SCREEN_HEIGHT-SCREEN_HEIGHT/8)/2);
	}
	~GameEngine(){
		delete player_one;
		delete player_two;
		delete ball;
		delete bg;
		delete bat_R;
	}

	void handle_event(SDL_Event& e){
    	while(SDL_PollEvent(&e)!=0){
			(e.type==SDL_QUIT)?running=false:true;
			bat_R->bat_R_handle_event(e);
			bat_L->bat_L_handle_event(e);
		}
    }
    void run(){
		SDL_Event e;	
		 t0 = SDL_GetTicks();
	 while(running){
			t1=SDL_GetTicks();
			dt=t1-t0;
			t0=t1;
			this->handle_event(e);
			bat_R->bat_move();
			bat_L->bat_move();
			ball->ball_move(bat_R, bat_L, dt, player_one, player_two);
			this->bg->draw(player_one, player_two, bat_R, bat_L, ball);
		}
    }
};

#endif
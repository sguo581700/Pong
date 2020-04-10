
#ifndef GAMEENGINE_H_
#define GAMEENGINE_H_

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

class GameEngine{
private:
		Player*player_one=nullptr;
		Ball*ball = nullptr;
		Background*bg = nullptr;
		int t0;
		int t1;
		int dt;
		clock_t pre_ticks;
		bool running=true;

public:
	GameEngine(){
		player_one = new Player();
		ball = new Ball();
		bg = new Background();
	}
	~GameEngine(){
		delete player_one;
		delete ball;
		delete bg;
	}

	void handle_event(SDL_Event& e){
    	while(SDL_PollEvent(&e)!=0){
			(e.type==SDL_QUIT)?running=false:true;
			this->player_one->get_bat()->bat_handle_event(e);
		}
    }
    void run(){
		SDL_Event e;	
		 t0 = SDL_GetTicks();
	 while(running){
			t1=SDL_GetTicks();
			dt=t1-t0;
			t0=t1;
			pre_ticks=clock();
			this->handle_event(e);
			this->ball->ball_move(this->player_one->get_bat(), dt, player_one);
			this->bg->draw(player_one, ball);
		}
    }

};

#endif
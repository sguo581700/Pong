#ifndef PLAYER_H_
#define PLAYER_H_
#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL_image.h>
#include "Bat.h"

using namespace std;
class Player{
private:
	string name;
	int lives;
	int scores;
    Bat*bat = nullptr;
 
public:
	Player(){
		lives=3;
		scores=0;
	    bat = new Bat();
	}
	string set_name(string name){this->name = name; return this->name;}
	int get_lives(){return lives;}
	int get_score(){return scores;}
	
	Bat*get_bat(){return bat;}
    
};

#endif

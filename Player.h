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
	int scores;
 
public:
	Player(){
		scores=0;
	}
	~Player(){
	}
	string set_name(string name){this->name = name; return this->name;}
	void set_score(){scores++;}
	int get_score(){return scores;}    
};

#endif

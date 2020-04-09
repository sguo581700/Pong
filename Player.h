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
	int chances;
	int scores;
    Bat*bat = nullptr;
 
public:
	Player(){
		chances=3;
		scores=0;
	    bat = new Bat();
	}
	string set_name(string name){this->name = name; return this->name;}
	void set_score(){scores++;}
	int get_chances(){return chances;}
	int get_score(){return scores;}
	void lose_chances(){chances--;}
	Bat*get_bat(){return bat;}
    
};

#endif

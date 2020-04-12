
#ifndef BACKGROUND_H_
#define BACKGROUND_H_
#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<string>
#include<SDL2/SDL_ttf.h>
#include "Player.h"
#include "Ball.h"
using namespace std;
class Background{
private:
	int screen_width;
	int screen_height;
	SDL_Window*window=NULL;
	SDL_Renderer*renderer=NULL;
	int text_width;
	int text_height;
	TTF_Font*font = NULL;
	SDL_Surface*text_surface = NULL;
	SDL_Texture*texture = NULL;
	
public:
	Background(){
		TTF_Init();
		screen_width=800;
		screen_height=600;
		window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
    	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    	font = TTF_OpenFont("/Library/Fonts/Comic Sans MS Bold.ttf",64);
		text_width = screen_width/10;
		text_height = screen_height/30;
		
	}

	~Background(){
		this->clean();
	}
	void render_text(int x, int y, string s){
			SDL_Rect r;
    		r.x=x;
    		r.y=y;  
			r.w=text_width;
			r.h=text_height;
			SDL_Color color = {0x00, 0x00, 0x00};
			text_surface = TTF_RenderText_Solid(font,s.c_str(),color);
			texture = SDL_CreateTextureFromSurface(renderer,text_surface);
			SDL_RenderCopy(renderer, texture, NULL, &r);
	}
	int get_screen_width(){return screen_width;}
	int get_screen_height(){return screen_height;}
    int get_text_width(){return text_width;}
    int get_text_height(){return text_height;}

    void draw(Player*player_one, Bat*bat, Ball*ball){
    	SDL_SetRenderDrawColor(renderer,0xff,0xff,0xff,0xff); 
		SDL_RenderClear(renderer);
		draw_text(player_one);
		//draw_bat_rect(player_one, player_one->get_bat()->get_bat_pos_x(), player_one->get_bat()->get_bat_pos_y());
		draw_bat_rect(bat, bat->get_bat_pos_x(), bat->get_bat_pos_y());

		draw_ball_rect(ball, ball->get_ball_pos_x(), ball->get_ball_pos_y());
		SDL_RenderPresent(renderer);
    }

    
    void draw_text(Player*player_one){
    	
    	//string s[]{"ONE","TWO","THREE","FOUR"};
    		string s="ONE";
    		this->render_text(0, 0, player_one->set_name(s)+"     ");
			this->render_text(0,this->get_text_height(), "scores:"+to_string(player_one->get_score())+"  ");
		/*for(int i=0; i<sizeof(s)/sizeof(string);++i){
			this->render_text(i*this->get_text_width(), 0, this->player_one->set_name(s[i])+"     ");
			this->render_text(i*this->get_text_width(),this->get_text_height(), "scores:"+to_string(this->player_one->get_score())+"  ");
		    }*/
		    this->render_text(this->get_screen_width()-this->get_text_width(),0, "chances: "+to_string(player_one->get_chances()));
		}
			
        clock_t get_fps(clock_t x){
    	return CLOCKS_PER_SEC/(clock()-x);
    }
    
    void draw_bat_rect(Bat*bat, int x, int y){
    	SDL_SetRenderDrawColor(renderer,0x00,0x00,0x00,0x00); 
		SDL_RenderDrawRect(renderer, bat->bat_rect(x,y));
		SDL_RenderFillRect(renderer, bat->bat_rect(x,y));
    }
    void draw_ball_rect(Ball*ball, int x, int y){
    	SDL_SetRenderDrawColor(renderer,0x00,0x00,0x00,0x00); 
    	SDL_RenderDrawRect(renderer, ball->ball_rect(x,y));
    	SDL_RenderFillRect(renderer, ball->ball_rect(x,y));
    }
	void clean(){
		TTF_CloseFont(font);
		font=NULL;
		SDL_FreeSurface(text_surface);
		text_surface=NULL;
		SDL_DestroyTexture(texture);
		texture=NULL;
		SDL_DestroyWindow(window);
		window = NULL;
		SDL_DestroyRenderer(renderer);
		renderer=NULL;
		TTF_Quit();
		IMG_Quit();
		SDL_Quit();
	}
};
#endif

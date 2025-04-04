#ifndef GAME_H
#define GAME_H
#include "main.h"
#include "ball.h"
#include "player.h"
#include "score.h"
#include "title.h"
#include "end.h"

typedef struct Game
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;
	SDL_Rect background_rect;
	SDL_Texture *background_texture;
	SDL_Texture *ball_image;
	SDL_Texture *player1;
	SDL_Texture *player2;
	Mix_Chunk *hit_sound;
	Ball_T *ball;
	Player_T *player;
	Score_T *score;
	Title_T *title;
	End_T *end;
	bool playing;
} Game_T;
bool game_new(Game_T **g);
void game_free(Game_T **g);
bool game_run(Game_T *g);
#endif

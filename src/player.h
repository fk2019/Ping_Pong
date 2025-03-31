#ifndef PLAYER_H
#define PLAYER_H
#include "game.h"

typedef struct Player
{
	//struct Player *next;
	SDL_Renderer *renderer;
	SDL_Texture *player_image;
	const Uint8 *keystate;
	SDL_Rect player1_rect;
	SDL_Rect player2_rect;
	SDL_Rect mid_line;
	SDL_Color color;
	double speed;
	double angle;
	bool is_p1;
} Player_T;
bool player_new(Player_T **player, SDL_Renderer *renderer, SDL_Texture *player_texture);
void player_free(Player_T **player);
void player_draw(Player_T *p);
void player_reset(Player_T *p);
void player_update(Player_T *p);

#endif

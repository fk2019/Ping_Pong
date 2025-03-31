#ifndef BALL_H
#define BALL_H
#include "game.h"
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#define MAX_BOUNCE_ANGLE 75 * M_PI / 180.0
#include "player.h"

typedef struct Ball
{
	SDL_Renderer *renderer;
	SDL_Texture *ball;
	SDL_Texture *ball_texture;
	Player_T *player;
	SDL_Rect ball_rect;
	SDL_Color color;
	double speed;
	double angle;
	double dy;
	double dx;
	double rad;
	int plane1;
	int plane2;
	int op;
	bool out;
	bool score1;
	bool score2;
	bool hit;
	bool playing;
} Ball_T;
bool ball_new(Ball_T **ball, SDL_Renderer *renderer, SDL_Texture *ball_texture);
void ball_free(Ball_T **ball);
void ball_draw(Ball_T *r);
void ball_reset(Ball_T *r);
void ball_update(Ball_T *r, Player_T *player);

#endif

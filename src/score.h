#ifndef SCORE_H
#define SCORE_H
#include "game.h"

typedef struct Score
{
        SDL_Renderer *renderer;
        SDL_Texture *image;
	SDL_Texture *image2;
	SDL_Texture *image3;
        SDL_Color color;
	SDL_Color color2;
        SDL_Rect rect;
	SDL_Rect rect2;
	SDL_Rect rect3;
        TTF_Font *font;
        Uint32 score;
	Uint32 score2;
	Uint32 game;
	Uint32 score_game;
	Uint32 score_game2;
	bool is_score1;
	bool is_score2;
	bool playing;
	bool new_game;

} Score_T;
bool score_new(Score_T **score, SDL_Renderer *renderer);
void score_free(Score_T **score);
bool score_reset(Score_T *s);
void score_draw(Score_T *s);
bool score_update(Score_T *s);
bool match_update(Score_T *s);
bool score_increment(Score_T *s, bool is_score2);
#endif

#ifndef SCORE_H
#define SCORE_H
#include "game.h"

typedef struct Score
{
        SDL_Renderer *renderer;
        SDL_Texture *score1_image;
	SDL_Texture *score2_image;
	SDL_Texture *game_image;
	SDL_Texture *win1_image;
	SDL_Texture *win2_image;
        SDL_Color color;
	SDL_Color color2;
        SDL_Rect score1_rect;
	SDL_Rect score2_rect;
	SDL_Rect game_rect;
	SDL_Rect win1_rect;
	SDL_Rect win2_rect;
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
	bool end_game;
	bool player1;
	bool player2;

} Score_T;
bool score_new(Score_T **score, SDL_Renderer *renderer);
void score_free(Score_T **score);
bool score_reset(Score_T *s);
void score_draw(Score_T *s);
bool score_update(Score_T *s);
bool match_update(Score_T *s);
bool match_reset(Score_T *s);
bool game_update(Score_T *s);
bool score_increment(Score_T *s, bool is_score2);
#endif

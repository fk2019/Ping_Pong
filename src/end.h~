#ifndef TITLE_H
#define TITLE_H
#include "game.h"

typedef struct Title
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
        Uint32 title;
	Uint32 title2;
	Uint32 game;
	Uint32 title_game;
	Uint32 title_game2;
	bool show_title;
	bool is_title2;
	bool playing;

} Title_T;
bool title_new(Title_T **title, SDL_Renderer *renderer);
void title_free(Title_T **title);
void title_reset(Title_T *t);
void title_draw(Title_T *t);
bool title_update(Title_T *t);
#endif

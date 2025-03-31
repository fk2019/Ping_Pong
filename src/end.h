#ifndef END_H
#define END_H
#include "game.h"

typedef struct End
{
        SDL_Renderer *renderer;
        SDL_Texture *image;
        SDL_Color color;
        SDL_Rect rect;
        TTF_Font *font;
        Uint32 end;
	bool show_end;
	bool is_end2;
	bool playing;
	bool player1;
	bool player2;

} End_T;
bool end_new(End_T **end, SDL_Renderer *renderer);
void end_free(End_T **end);
void end_reset(End_T *e);
void end_draw(End_T *e);
bool end_update(End_T *e);
#endif

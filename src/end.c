#include "game.h"
#include "end.h"

bool end_new(End_T **end, SDL_Renderer *renderer)
{
        *end = calloc(1, sizeof(End_T));
        if (*end == NULL)
        {
                fprintf(stderr, "Error in calloc of new end\n");
                return true;
        }
        End_T *e = *end;
        e->renderer = renderer;
        e->color = (SDL_Color){255, 255, 0, 200};
        e->font = TTF_OpenFont("fonts/freesansbold.ttf", FONT_SIZE);
        if (!e->font)
        {
                fprintf(stderr, "Error opening font: %s\n", TTF_GetError());
                return true;
        }
	e->rect.y = WINDOW_HEIGHT / 3;
	end_reset(e);
        return false;
}

void end_free(End_T **end)
{
        if (*end)
        {
                End_T *e = *end;
                TTF_CloseFont(e->font);
                e->font = NULL;
                SDL_DestroyTexture(e->image);
                e->image = NULL;
                e->renderer = NULL;
                free(e);
                e = NULL;
                *end = NULL;
        }
}

void end_reset(End_T *e)
{
	//e->show_end = true;
}

void end_draw(End_T *e)
{
	if (e->show_end)
	{
		e->rect.x = WINDOW_WIDTH / 2 - e->rect.w / 2;
		SDL_RenderCopy(e->renderer, e->image, NULL, &e->rect);
	}
}

bool end_update(End_T *e)
{
	int x = e->player1 ? 1 : 2;

        int length = snprintf(NULL, 0, "Player %d Wins!\n", x);
        char end_str[length];
        snprintf(end_str, (size_t)length, "Player %d Wins!\n", x);
        SDL_Surface *surface = TTF_RenderText_Blended(e->font, end_str, e->color);
        if (!surface)
        {
                fprintf(stderr, "Error creating surface: %s\n", TTF_GetError());
                return true;
        }
	e->rect.w = surface->w;
	e->rect.h = surface->h;

	e->image = SDL_CreateTextureFromSurface(e->renderer, surface);
	if (!e->image)
        {
                fprintf(stderr, "Error creating texture from surface: %s\n", SDL_GetError());
                return true;
        }
	return false;
}

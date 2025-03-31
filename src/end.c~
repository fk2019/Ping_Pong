#include "game.h"
#include "title.h"

bool title_new(Title_T **title, SDL_Renderer *renderer)
{
        *title = calloc(1, sizeof(Title_T));
        if (*title == NULL)
        {
                fprintf(stderr, "Error in calloc of new title\n");
                return true;
        }
        Title_T *t = *title;
        t->renderer = renderer;
        t->color = (SDL_Color){255, 255, 255, 150};
	t->color2 = (SDL_Color){255, 255, 0, 255};
        t->font = TTF_OpenFont("fonts/freesansbold.ttf", FONT_SIZE);
        if (!t->font)
        {
                fprintf(stderr, "Error opening font: %s\n", TTF_GetError());
                return true;
        }
	t->rect.y = WINDOW_HEIGHT / 2;
	title_reset(t);
        return false;
}

void title_free(Title_T **title)
{
        if (*title)
        {
                Title_T *t = *title;
                TTF_CloseFont(t->font);
                t->font = NULL;
                SDL_DestroyTexture(t->image);
                t->image = NULL;
                t->renderer = NULL;
                free(t);
                t = NULL;
                *title = NULL;
        }
}

void title_reset(Title_T *t)
{
	//t->show_title = true;
}

void title_draw(Title_T *t)
{
	if (t->show_title)
	{
		t->rect.x = t->rect.w / 2;
		SDL_RenderCopy(t->renderer, t->image, NULL, &t->rect);
	}
}

bool title_update(Title_T *t)
{
        int length = snprintf(NULL, 0, "Press Space Bar to Start New Game\n");
        char title_str[length];
        snprintf(title_str, (size_t)length, "Press Space Bar to Start New Game\n");
        SDL_Surface *surface = TTF_RenderText_Blended(t->font, title_str, t->color);
        if (!surface)
        {
                fprintf(stderr, "Error creating surface: %s\n", TTF_GetError());
                return true;
        }
	t->rect.w = surface->w;
	t->rect.h = surface->h;

	t->image = SDL_CreateTextureFromSurface(t->renderer, surface);
	if (!t->image)
        {
                fprintf(stderr, "Error creating texture from surface: %s\n", SDL_GetError());
                return true;
        }
	return false;
}

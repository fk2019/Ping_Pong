#include "game.h"
#include "score.h"

bool score_new(Score_T **score, SDL_Renderer *renderer)
{
        *score = calloc(1, sizeof(Score_T));
        if (*score == NULL)
        {
                fprintf(stderr, "Error in calloc of new score\n");
                return true;
        }
        Score_T *s = *score;
        s->renderer = renderer;
	s->game = 1;
        s->color = (SDL_Color){255, 255, 255, 150};
	s->color2 = (SDL_Color){255, 255, 0, 255};
        s->font = TTF_OpenFont("fonts/freesansbold.ttf", FONT_SIZE);
        if (!s->font)
        {
                fprintf(stderr, "Error opening font: %s\n", TTF_GetError());
                return true;
        }
	if (score_reset(s)) return true;
	s->playing = true;
        return false;
}

void score_free(Score_T **score)
{
        if (*score)
        {
                Score_T *s = *score;
                TTF_CloseFont(s->font);
                s->font = NULL;
                SDL_DestroyTexture(s->image);
                s->image = NULL;
		SDL_DestroyTexture(s->image2);
		s->image2 = NULL;
		SDL_DestroyTexture(s->image3);
		s->image3 = NULL;
                s->renderer = NULL;
                free(s);
                s = NULL;
                *score = NULL;
        }
}

bool score_reset(Score_T *s)
{
        s->score = 0;
	s->score2 = 0;
        if (score_update(s)) return true;
        return false;
}

void score_draw(Score_T *s)
{
	s->rect2.x = WINDOW_WIDTH - s->rect2.w - 10;
	s->rect3.x = WINDOW_WIDTH / 2;
        SDL_RenderCopy(s->renderer, s->image, NULL, &s->rect);
	SDL_RenderCopy(s->renderer, s->image2, NULL, &s->rect2);
	SDL_RenderCopy(s->renderer, s->image3, NULL, &s->rect3);
}

bool match_update(Score_T *s)
{
	int length = snprintf(NULL, 0, "Game: %d\n", s->game);
        char score_str[length];
        snprintf(score_str, (size_t)length, "Game: %d\n", s->game);
        SDL_Surface *surface = TTF_RenderText_Blended(s->font, score_str, s->color);
        if (!surface)
        {
                fprintf(stderr, "Error creating surface: %s\n", TTF_GetError());
                return true;
        }
	s->rect3.w = surface->w;
	s->rect3.h = surface->h;

	s->image3 = SDL_CreateTextureFromSurface(s->renderer, surface);
	if (!s->image3)
        {
                fprintf(stderr, "Error creating texture from surface: %s\n", SDL_GetError());
                return true;
        }
	return false;
}
bool score_update(Score_T *s)
{
        int length = snprintf(NULL, 0, "Score: %d\n", s->score);
        char score_str[length];
        snprintf(score_str, (size_t)length, "Score: %d\n", s->score);
        SDL_Surface *surface = TTF_RenderText_Blended(s->font, score_str, s->color);
        if (!surface)
        {
                fprintf(stderr, "Error creating surface: %s\n", TTF_GetError());
                return true;
        }
	s->rect.w = surface->w;
	s->rect.h = surface->h;

	s->image = SDL_CreateTextureFromSurface(s->renderer, surface);
	if (!s->image)
        {
                fprintf(stderr, "Error creating texture from surface: %s\n", SDL_GetError());
                return true;
        }
	//score 2
	int length2 = snprintf(NULL, 0, "Score: %d\n", s->score2);
        char score_str2[length];
        snprintf(score_str2, (size_t)length2, "Score: %d\n", s->score2);
        SDL_Surface *surface2 = TTF_RenderText_Blended(s->font, score_str2, s->color);
        if (!surface2)
        {
                fprintf(stderr, "Error creating surface2: %s\n", TTF_GetError());
                return true;
        }
	s->rect2.w = surface2->w;
	s->rect2.h = surface2->h;

	s->image2 = SDL_CreateTextureFromSurface(s->renderer, surface2);
	if (!s->image2)
        {
                fprintf(stderr, "Error creating texture from surface2: %s\n", SDL_GetError());
                return true;
        }
	return false;
}

bool score_increment(Score_T *s, bool is_score2)
{
	if (is_score2) s->score2++;
	else s->score++;
	if (match_update(s)) return true;
	if (score_update(s)) return true;
	if (s->score >= WINNING_POINTS || s->score2 >= WINNING_POINTS && abs(s->score - s->score2))
	{
		s->playing = false;
		s->new_game = true;
		if (s->score > s->score2)
		{
			s->score_game++;
		}
		else
		{
			s->score_game2++;
		}
		s->game++;
		score_reset(s);
	}
	if (s->playing) s->new_game = false;
	if (s->score_game == BEST_GAMES)
	{
		s->playing = false;
		printf("player 1 wins match\n");
	}
	if (s->score_game2 == BEST_GAMES)
	{
		s->playing = false;
		printf("player 2 wins match\n");
	}

}

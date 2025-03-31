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
                SDL_DestroyTexture(s->score1_image);
                s->score1_image = NULL;
		SDL_DestroyTexture(s->score2_image);
		s->score2_image = NULL;
		SDL_DestroyTexture(s->game_image);
		s->game_image = NULL;
		SDL_DestroyTexture(s->win1_image);
		s->win1_image = NULL;
		SDL_DestroyTexture(s->win2_image);
		s->win2_image = NULL;
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
bool match_reset(Score_T *s)
{
	s->game = 0;
	s->score_game = 0;
	s->score_game2 = 0;
	score_reset(s);
	if (match_update(s)) return true;
}
void score_draw(Score_T *s)
{
	s->score2_rect.x = WINDOW_WIDTH - s->score2_rect.w - 10;
	s->game_rect.x = (s->win1_rect.x + s->win1_rect.w + s->win2_rect.x)/2;
	s->win1_rect.x = s->score1_rect.w + 20;
	s->win2_rect.x = s->score2_rect.x - s->score2_rect.w - s->win2_rect.w / 2;
        SDL_RenderCopy(s->renderer, s->score1_image, NULL, &s->score1_rect);
	SDL_RenderCopy(s->renderer, s->score2_image, NULL, &s->score2_rect);
	SDL_RenderCopy(s->renderer, s->game_image, NULL, &s->game_rect);
	SDL_RenderCopy(s->renderer, s->win1_image, NULL, &s->win1_rect);
	SDL_RenderCopy(s->renderer, s->win2_image, NULL, &s->win2_rect);
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
	s->game_rect.w = surface->w;
	s->game_rect.h = surface->h;

	s->game_image = SDL_CreateTextureFromSurface(s->renderer, surface);
	if (!s->game_image)
        {
                fprintf(stderr, "Error creating texture from surface: %s\n", SDL_GetError());
                return true;
        }
	return false;
}

bool game_update(Score_T *s)
{
	//game1
	int length = snprintf(NULL, 0, "Won: %d/%d\n", s->score_game, MAX_GAMES);
        char score_str[length];
        snprintf(score_str, (size_t)length, "Won: %d/%d\n", s->score_game, MAX_GAMES);
        SDL_Surface *surface = TTF_RenderText_Blended(s->font, score_str, s->color);
        if (!surface)
        {
                fprintf(stderr, "Error creating surface: %s\n", TTF_GetError());
                return true;
        }
	s->win1_rect.w = surface->w;
	s->win1_rect.h = surface->h;

	s->win1_image = SDL_CreateTextureFromSurface(s->renderer, surface);
	if (!s->win1_image)
        {
                fprintf(stderr, "Error creating texture from surface: %s\n", SDL_GetError());
                return true;
        }
	//game2
	int length2 = snprintf(NULL, 0, "Won: %d/%d\n", s->score_game2, MAX_GAMES);
        char score_str2[length];
        snprintf(score_str2, (size_t)length2, "Won: %d/%d\n", s->score_game2, MAX_GAMES);
        SDL_Surface *surface2 = TTF_RenderText_Blended(s->font, score_str2, s->color);
        if (!surface2)
        {
                fprintf(stderr, "Error creating surface: %s\n", TTF_GetError());
                return true;
        }
	s->win2_rect.w = surface2->w;
	s->win2_rect.h = surface2->h;

	s->win2_image = SDL_CreateTextureFromSurface(s->renderer, surface2);
	if (!s->win2_image)
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
	s->score1_rect.w = surface->w;
	s->score1_rect.h = surface->h;

	s->score1_image = SDL_CreateTextureFromSurface(s->renderer, surface);
	if (!s->score1_image)
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
	s->score2_rect.w = surface2->w;
	s->score2_rect.h = surface2->h;

	s->score2_image = SDL_CreateTextureFromSurface(s->renderer, surface2);
	if (!s->score2_image)
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
	if (game_update(s)) return true;
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
	}
	if (s->playing) s->new_game = false;
	if (s->score_game == BEST_GAMES)
	{
		s->playing = false;
		s->game -= 1;
		s->end_game = true;
		s->new_game = true;
		s->player1 = true;
	}
	if (s->score_game2 == BEST_GAMES)
	{
		s->playing = false;
		s->game -= 1;
		s->end_game = true;
		s->new_game = true;
		s->player2 = true;
	}
}

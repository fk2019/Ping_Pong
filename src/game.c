#include "game.h"
#include "initialize.h"
#include "ball.h"
#include "player.h"
#include "score.h"
#include "title.h"

bool check_collision(Game_T *g);
bool handle_collision(Game_T *g, bool is_score2);

bool game_new(Game_T **game)
{
	*game = calloc(1, sizeof(Game_T));
	if (*game == NULL)
	{
		fprintf(stderr, "Error in calloc of new game.\n");
		return true;
	}
	Game_T *g = *game;

	if (game_initialize(g)) return true;
	if (ball_new(&g->ball,g->renderer, g->ball_image)) return true;
	if (player_new(&g->player, g->renderer, g->player1)) return true;
	if (score_new(&g->score, g->renderer)) return true;
	if (title_new(&g->title, g->renderer)) return true;
	g->playing = true;
	return false;
}

void game_free(Game_T **game)
{
	if (*game)
	{
		Game_T *g = *game;
		ball_free(&g->ball);
		player_free(&g->player);
		score_free(&g->score);
		title_free(&g->title);
		Mix_FreeChunk(g->hit_sound);
		g->hit_sound = NULL;
		SDL_DestroyTexture(g->player1);
		g->player = NULL;
		SDL_DestroyTexture(g->ball_image);
		g->ball_image = NULL;
		SDL_DestroyTexture(g->background_texture);
		g->background_texture = NULL;
		SDL_DestroyRenderer(g->renderer);
		g->renderer = NULL;
		SDL_DestroyWindow(g->window);
		g->window = NULL;

		Mix_CloseAudio();
		TTF_Quit();
		Mix_Quit();
		IMG_Quit();
		SDL_Quit();

		free(g);
		g = NULL;
		*game = NULL;
	}
}
bool handle_collision(Game_T *g, bool is_score2)
{
	ball_reset(g->ball);
	if (is_score2)
	{
		score_increment(g->score, true);
		g->ball->out = false;
		g->ball->score2 = false;
	} else
	{
		score_increment(g->score, false);
		g->ball->out = false;
		g->ball->score1 = false;
	}
	g->ball->playing = g->score->playing;
	if (g->score->new_game) g->title->show_title = true;
	return false;
}
bool check_collision(Game_T *g)
{
	if (g->ball->out && g->ball->score2)
	{
		if (handle_collision(g, true)) return true;
	}
	if (g->ball->out && g->ball->score1)
	{
		if (handle_collision(g, false)) return true;
	}
	if (g->ball->hit) Mix_PlayChannel(-1, g->hit_sound, 0);
	g->ball->hit = false;
	return false;
}
bool game_run(Game_T *g)
{
	while (1)
	{
		while (SDL_PollEvent(&g->event))
		{
			switch (g->event.type)
			{
			case SDL_QUIT:
				return false;
				break;
			case SDL_KEYDOWN:
				switch (g->event.key.keysym.scancode)
				{
				case SDL_SCANCODE_ESCAPE:
					return false;
					break;
				case SDL_SCANCODE_SPACE:
					g->score->playing = true;
					g->score->new_game = false;
					g->title->show_title = false;
					break;
				default:
					break;
				}
			default:
				break;
			}
		}
		match_update(g->score);
		if (g->score->playing)
		{
			ball_update(g->ball, g->player);
			score_update(g->score);
			player_update(g->player);
		}
		if (g->title->show_title)
		{
			title_update(g->title);
		}
		if (check_collision(g)) return true;
		SDL_RenderClear(g->renderer);
		SDL_RenderCopy(g->renderer, g->background_texture, NULL, &g->background_rect);
		player_draw(g->player);
		ball_draw(g->ball);
		score_draw(g->score);
		title_draw(g->title);
		SDL_RenderPresent(g->renderer);
		SDL_Delay(1000 / 60);
	}
}

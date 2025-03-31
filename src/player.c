#include "game.h"
#include "player.h"

bool player_new(Player_T **player, SDL_Renderer *renderer, SDL_Texture *image)
{
	*player = calloc(1, sizeof(Ball_T));
        if (*player == NULL)
        {
                fprintf(stderr, "Error in calloc of new player.\n");
                return true;
        }
	Player_T *p = *player;
	p->renderer = renderer;
	p->player_image = image;
	p->speed = 10;
	p->keystate = SDL_GetKeyboardState(NULL);
	if (SDL_QueryTexture(p->player_image, NULL, NULL, &p->player1_rect.w, &p->player1_rect.h))
	{
		fprintf(stderr, "Error in querying player texture: %s\n", SDL_GetError());
		return true;
	}
	p->player1_rect.w = 20;
	p->player1_rect.h = 150;
	p->player2_rect = p->player1_rect;
	p->mid_line.w = 1;
	p->mid_line.h = 0;
	p->mid_line.x = WINDOW_WIDTH / 2;
	p->mid_line.h = WINDOW_HEIGHT;
	player_reset(p);
	return false;
}

void player_reset(Player_T *p)
{
		p->player1_rect.y = 30;
		p->player2_rect.y = 30;
		p->player2_rect.x = WINDOW_WIDTH - p->player2_rect.w;
}

void player_update(Player_T *p)
{
	// player 1 movement
	if (p->keystate[SDL_SCANCODE_S])
	{
		p->player1_rect.y += p->speed;
			if (p->player1_rect.y + p->player1_rect.h >= WINDOW_HEIGHT)
		{
			p->player1_rect.y = WINDOW_HEIGHT - p->player1_rect.h;
		}
	}
	if (p->keystate[SDL_SCANCODE_W])
	{
		p->player1_rect.y -= p->speed;
			if (p->player1_rect.y <= 0)
		{
			p->player1_rect.y = 0;
		}
	}
	//player 2 mvmnt
	if (p->keystate[SDL_SCANCODE_DOWN])
	{
		p->player2_rect.y += p->speed;
			if (p->player2_rect.y + p->player2_rect.h >= WINDOW_HEIGHT)
		{
			p->player2_rect.y = WINDOW_HEIGHT - p->player2_rect.h;
		}
	}
	if (p->keystate[SDL_SCANCODE_UP])
	{
		p->player2_rect.y -= p->speed;
			if (p->player2_rect.y <= 0)
		{
			p->player2_rect.y = 0;
		}
	}
}

void player_draw(Player_T *p)
{
	SDL_RenderCopy(p->renderer, p->player_image, NULL, &p->player1_rect);
	SDL_RenderCopy(p->renderer, p->player_image, NULL, &p->player2_rect);
	SDL_RenderCopy(p->renderer, p->player_image, NULL, &p->mid_line);
}

void player_free(Player_T **player)
{
	if (*player)
	{
		(*player)->player_image = NULL;
		(*player)->renderer = NULL;
		free(*player);
		*player = NULL;
	}
}

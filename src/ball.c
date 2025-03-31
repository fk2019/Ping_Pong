#include "game.h"
#include "ball.h"

bool ball_new(Ball_T **ball, SDL_Renderer *renderer, SDL_Texture *ball_texture)
{
	 *ball = calloc(1, sizeof(Ball_T));
        if (*ball == NULL)
        {
                fprintf(stderr, "Error in calloc of new ball.\n");
                return true;
        }
        Ball_T *b = *ball;
	b->renderer = renderer;
	b->speed = 30;
	b->angle = 1;
	b->ball = ball_texture;
	b->plane1 = 180;
	b->plane2 = 360;
	b->op = -1;
	b->playing = true;

	if (SDL_QueryTexture(b->ball, NULL, NULL, &b->ball_rect.w, &b->ball_rect.h))
        {
                fprintf(stderr, "Error in querying ball texture: %s\n", SDL_GetError());
                return true;
        }

	b->ball_rect.w = 30;
	b->ball_rect.h = 30;
	ball_reset(b);
	return false;
}

void ball_reset(Ball_T *b)
{
	b->ball_rect.x = (WINDOW_WIDTH - b->ball_rect.w) / 2;
	b->ball_rect.y = 0; //(WINDOW_HEIGHT - b->ball_rect.h) / 2;
	if (b->score2)
	{
		b->op = 1;
		b->plane1 = 360;
		b->plane2 = 180;
	}
	if (b->score1)
	{
		b->op = -1;
		b->plane1 = 180;
		b->plane2 = 360;
	}

}

void ball_draw(Ball_T *b)
{
	SDL_RenderCopy(b->renderer, b->ball, NULL, &b->ball_rect);
}

void ball_free(Ball_T **ball)
{
	if (*ball)
	{
		Ball_T *b = *ball;
		SDL_DestroyTexture(b->ball);
		b->ball = NULL;
		b->renderer = NULL;
		free(b);
		b = NULL;
		*ball = NULL;
	}
}

void ball_update(Ball_T *b, Player_T *p)
{
	b->rad = b->angle * M_PI / 180;
	b->dx = b->speed * cos(b->rad);
	b->dy = b->speed * sin(b->rad);

	b->ball_rect.y += b->dy;
	b->ball_rect.x += b->op * b->dx;

	if (b->ball_rect.x <= p->player1_rect.x + p->player1_rect.w)
	{
		if (b->ball_rect.y + b->ball_rect.h / 2 >= p->player1_rect.y && b->ball_rect.y + b->ball_rect.h / 2 <= p->player1_rect.y + p->player1_rect.h)
		{
			double mid_player = p->player1_rect.y + (p->player1_rect.h / 2);
			double relative_intersect = mid_player - b->ball_rect.y;
			double normalized_intersect = relative_intersect / mid_player;
			if (b->ball_rect.y == 0)
			{
				b->angle = b->plane1 - (normalized_intersect * -20);
			} else	b->angle = b->plane1 - (normalized_intersect * 75);
			b->hit = true;
		} else {
			b->out = true;
			b->score2 = true;
			b->angle = 1;
		}
	}
	//player2
	if (b->ball_rect.x + b->ball_rect.w >= p->player2_rect.x)
	{
		if (b->ball_rect.y + b->ball_rect.h / 2 >= p->player2_rect.y && b->ball_rect.y + b->ball_rect.h / 2 <= p->player2_rect.y + p->player2_rect.h)
		{
			double mid_player = p->player2_rect.y + (p->player2_rect.h / 2);
			double relative_intersect = mid_player - b->ball_rect.y + b->ball_rect.w;
			double normalized_intersect = relative_intersect / mid_player;
			if (b->ball_rect.y == 0)
			{
				b->angle = b->plane2 - (normalized_intersect * -20);
			}
			else b->angle = b->plane2 - (normalized_intersect * 75);
			b->hit = true;
		} else {
			b->out = true;
			b->score1 = true;
			b->angle = 1;
		}
	}

	if (b->ball_rect.y <=0 || (b->ball_rect.y + b->ball_rect.h) >= WINDOW_HEIGHT)
	{
		b->angle = - b->angle;
	}
	//b->playing = s->playing;
	//printf("bplaying?: %d splaying: %d\n", b->playing, s->playing);

}

#include "initialize.h"

bool game_initialize(Game_T *g)
{
	// init sdl
	if (SDL_Init(SDL_FLAGS))
	{
		fprintf(stderr, "Error initializing SDL %s\n", SDL_GetError());
		return true;
	}
	// init img
	int img_init = IMG_Init(IMAGE_FLAGS);
	if ((img_init & IMAGE_FLAGS) != IMAGE_FLAGS)
	{
		fprintf(stderr, "Error initializing SDL image: %s\n", IMG_GetError());
		return true;
	}
	// init mixer
	int mix_init = Mix_Init(MIXER_FLAGS);
	if ((mix_init & MIXER_FLAGS) != MIXER_FLAGS)
	{
		fprintf(stderr, "Error initializing SDL mixer: %s\n", Mix_GetError());
		return true;
	}
	// open audio
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024))
	{
		fprintf(stderr, "Error opening audio: %s\n", Mix_GetError());
		return true;
	}
	// load hit sound
	g->hit_sound = Mix_LoadWAV("sounds/ball_sound.ogg");
        if (!g->hit_sound)
        {
                fprintf(stderr, "Error loading hit sound Chunk: %s\n", Mix_GetError());
                return true;
        }
	// create window
	g->window =  SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH,
                                 WINDOW_HEIGHT, 0);
	if (g->window == NULL)
	{
		fprintf(stderr, "Error Creating Window %s\n", SDL_GetError());
		return true;
	}
	// create renderer
	g->renderer = SDL_CreateRenderer(g->window, -1, SDL_RENDERER_ACCELERATED);
	if (g->renderer == NULL)
	{
		fprintf(stderr, "Error Creating Renderer %s\n", SDL_GetError());
		return true;
		}
	//init ball
	g->ball_image =  IMG_LoadTexture(g->renderer, "images/ball1.png");
        if (!g->ball_image)
        {
                fprintf(stderr, "Error loading ball texture: %s\n", IMG_GetError());
                return true;
        }
	//load bg
	g->background_texture =  IMG_LoadTexture(g->renderer, "images/table.png");
        if (!g->background_texture)
        {
                fprintf(stderr, "Error loading bg texture: %s\n", IMG_GetError());
                return true;
        }
	if (SDL_QueryTexture(g->background_texture, NULL, NULL, &g->background_rect.w, &g->background_rect.h))
        {
                fprintf(stderr, "Error in querying bg texture: %s\n", SDL_GetError());
                return true;
        }
	// init ttf
        if (TTF_Init())
        {
                fprintf(stderr, "Error initializing TTF %s\n", TTF_GetError());
                return true;
        }
	//init player1
	g->player1 =  IMG_LoadTexture(g->renderer, "images/player1.png");
        if (!g->player1)
        {
                fprintf(stderr, "Error loading player1 texture: %s\n", IMG_GetError());
                return true;
        }
	g->player2 =  IMG_LoadTexture(g->renderer, "images/player2.png");
        if (!g->player2)
        {
                fprintf(stderr, "Error loading player2 texture: %s\n", IMG_GetError());
                return true;
        }
	return false;
	// load png to surface (window icon)
	SDL_Surface *icon_surf = IMG_Load(WINDOW_ICON);
	if (icon_surf)
	{
		SDL_SetWindowIcon(g->window, icon_surf);
		SDL_FreeSurface(icon_surf);
		icon_surf = NULL;
	} else {
		fprintf(stderr, "Error loading icon_surf: %s\n", IMG_GetError());
		return true;
	}
	//hit sound
	
}

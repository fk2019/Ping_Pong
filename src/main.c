#include "main.h"
#include "game.h"
#undef main
int main(void)
{
	Game_T *g = NULL;
	if (game_new(&g) || game_run(g))
	{
		game_free(&g);
		return EXIT_FAILURE;
	}
	game_free(&g);
	return EXIT_SUCCESS;
}

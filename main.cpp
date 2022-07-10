#include "Game.hpp"


int main(int argc, char* argv[])
{	
	const int FPS{ 60 };
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart{ 0 };
	int frameTime{ 0 };

	Game* game = new Game();
	game->init();

	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->update();
		game->input();
		game->render();
		
		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();

	return 0;
}
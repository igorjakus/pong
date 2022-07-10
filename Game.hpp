#include <SDL2/SDL.h>
#include "Ball.hpp"
#include "Paddle.hpp"

class Game {

public:
	void init();
	void update();
	void input();
	void render();
	void clean();
	bool running();

private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;

	Paddle l_paddle;
	AI_Paddle r_paddle;
	Ball ball;
};

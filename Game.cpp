#include "Game.hpp"
#include "Settings.h"

void Game::init()
{
	// Setup window
	window = SDL_CreateWindow("Pong, @igorjakus", 
							  SDL_WINDOWPOS_CENTERED, 
							  SDL_WINDOWPOS_CENTERED, 
							  WIDTH, HEIGHT, 
		                      SDL_WINDOW_SHOWN);

	// Setup renderer
	renderer = SDL_CreateRenderer(window, -1, 0);

	// Now game is running
	isRunning = true;

	// Setup paddles
	l_paddle.init();
	r_paddle.init();

	// Setup ball
	ball.setup();
}

void Game::input()
{
	// In case of quit
	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT) { isRunning = false; }
	

	const Uint8* keystates = SDL_GetKeyboardState(NULL);

	// Move left paddle up/down
	if (keystates[SDL_SCANCODE_UP]) { l_paddle.move_up(); }
	if (keystates[SDL_SCANCODE_DOWN]) { l_paddle.move_down(); }

	// Serve
	if (!ball.isMoving()) {
		if (keystates[SDL_SCANCODE_SPACE]) {
			ball.serve(true);
		}
	}
}

void Game::update() {
	
	
	// Ball move
	ball.move();

	// If ball out of screen bring to ball back
	if (ball.outOfScreen()) {
		ball.setup();
	}

	// AI move
	r_paddle.moveAI(ball.y);

	// Bounce of the paddle
	if (SDL_HasIntersection(&ball, &l_paddle)) {
		ball.bounce(l_paddle.y, l_paddle.h, true);
	}
	else if (SDL_HasIntersection(&ball, &r_paddle)) {
		ball.bounce(r_paddle.y, r_paddle.h, false);
	}

	// Bounce off the wall
	ball.bounceWall();

	// Limit paddles movement
	l_paddle.limit_movement();
	r_paddle.limit_movement();
}

void Game::render()
{
	// Render background
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	// Render paddles
	SDL_RenderFillRect(renderer, &l_paddle);
	SDL_RenderFillRect(renderer, &r_paddle);

	// Render ball
	SDL_RenderFillRect(renderer, &ball);

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	// Cleanup before closing program
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Game::running()
{
	return isRunning;
}

#include <SDL2/SDL.h>
#include "Settings.hpp"


class Ball : public SDL_Rect {

public:
	void setup();
	void serve(bool isLeftSide);
	void move();

	void bounce(int paddleY, int paddleH, bool isLeft);
	void bounceWall();

	bool outOfScreen();
	bool isMoving();

private:
	int velX;
	int velY;
};
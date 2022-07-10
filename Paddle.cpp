#include "Paddle.hpp"

void Paddle::init()
{
	x = 32;
	w = 12;
	h = HEIGHT / 4;
	y = (HEIGHT / 2) - (h / 2);

}
void Paddle::limit_movement()
{
	if (y < 0) { y = 0; }
	if (y + h > HEIGHT) { y = HEIGHT - h; }
}

void Paddle::move_up() { y -= SPEED; }
void Paddle::move_down() { y += SPEED; }


void AI_Paddle::init()
{
	w = 12;
	h = HEIGHT / 4;
	y = (HEIGHT / 2) - (h / 2);
	x = WIDTH - w - 32;
}

void AI_Paddle::moveAI(int ballY)
{
	if (ballY < (y + (h / 2))) { y -= AI_SPEED; }
	if (ballY > (y + (h / 2))) { y += AI_SPEED; }
}
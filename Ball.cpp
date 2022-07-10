#include "Ball.hpp"
#include "random.hpp"

void Ball::setup()
{
	w = BALL_SIZE;
	h = BALL_SIZE;

	x = WIDTH / 2 - (w / 2);
	y = HEIGHT / 2 - (h / 2);

	velX = { 0 };
	velY = { 0 };
}

void Ball::serve(bool isLeftSide)
{
	using Random = effolkronium::random_static;

	// randomize velocity x
	velX = Random::get(4, 6);
	if (!isLeftSide) { velX *= -1; }

	// randomize velocity y
	velY = Random::get(2, 5);
}

void Ball::move() 
{
	x += velX;
	y += velY;
}

void Ball::bounce(int paddleY, int paddleH, bool isLeft)
{
	double rel = (paddleY + (paddleH / 2)) - (y + (h / 2));
	double norm = rel / (paddleH / 2);
	double bounce = norm * MAX_BOUNCE_ANGLE;
	
	// calculate x's velocity
	if (isLeft) { 
		velX = BALL_SPEED * cos(bounce); 
	}
	else {
		velX = -BALL_SPEED * cos(bounce); 
	}

	// calculate y's velocity
	velY = BALL_SPEED * -sin(bounce);
}

void Ball::bounceWall()
{
	if (y < 0 or y + h > HEIGHT)
	{
		velY *= -1;
	}
}

bool Ball::outOfScreen()
{
	return bool((x < 0) || (x + w > WIDTH));
}

bool Ball::isMoving()
{
	return bool(velX);
}
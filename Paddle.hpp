#include <SDL2/SDL.h>
#include "Settings.h"

class Paddle : public SDL_Rect {
	
public:
	void init();
	
	void limit_movement();

	void move_up();
	void move_down();
};

class AI_Paddle : public Paddle {

public:
	void init();
	void moveAI(int ballY);
};
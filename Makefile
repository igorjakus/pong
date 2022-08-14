all:
	g++ -mwindows -Isrc/Include -Lsrc/lib -o pong main.cpp Ball.cpp Game.cpp Paddle.cpp -lmingw32 -lSDL2main -lSDL2
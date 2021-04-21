#include "Game.h"


Game *gameInstance = nullptr;

int main(int argc, char* argv[]) {

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	gameInstance = new Game();
	gameInstance->init("Game Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	while (gameInstance->running())
	{
		//This gives how many milliseconds since we first init SDL
		frameStart = SDL_GetTicks();

		gameInstance->handleEvents();
		gameInstance->update();
		gameInstance->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	gameInstance->clean();

	return 0;
}
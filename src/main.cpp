#include <iostream>

#include "vec.h"

#include <SDL2/SDL.h>

struct GraphicsInfo
{
	std::string windowName;
	Dimension windowPos;
	Dimension windowSize;
	int windowFlags;
	int renderFlags; 
};

const GraphicsInfo info {
	.windowName  = "DSEngine",
	.windowPos   = Dimension(SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED),
	.windowSize  = Dimension(640, 480),
	.windowFlags = SDL_WINDOW_SHOWN,
	.renderFlags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
};

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;


bool initGraphics()
{
	window = SDL_CreateWindow(info.windowName.c_str(), info.windowPos.x, info.windowPos.y, 
		info.windowSize.x, info.windowSize.y, info.windowFlags);

	if(window == NULL) {
		std::cout << "Error: Could not create window\n";
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, info.renderFlags);

	if(renderer == NULL) {
		std::cout << "Error: Could not create renderer\n";
		return false;
	}
	return true;
}

void mainLoop()
{
	bool running = true;

	while(running) {
		SDL_Event event;
		while(SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT) {
				running = false;
			}
		}

		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}
}

int main(int argc, char** argv)
{
        if(!initGraphics()) {
        	std::cout << "Graphics could not be initialized\n";
        } else {
        	mainLoop();
        }
        return 0;
}











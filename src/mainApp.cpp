#include <iostream>
#include <SDL.h>

using namespace std;

int main() {

	// The size of the window
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL initialization failed" << endl;
		return 1;
	}

	// Create the window
	SDL_Window *window = SDL_CreateWindow("Particle Fire Simulation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		SDL_Quit();
		return 2;
	}

	// The application loop
	// Flag for the end of execution
	bool quit = false;
	// Event information
	SDL_Event event;

	while (!quit)
	{
		// Iterate over the events which happened and have to be processed
		while (SDL_PollEvent(&event))
		{
			// Get out of the loop when the SDL window is closed (SDL quit event)
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}

	// Destroy the SDL window
	SDL_DestroyWindow(window);
	// Quit SDL
	SDL_Quit();

	return 0;
}

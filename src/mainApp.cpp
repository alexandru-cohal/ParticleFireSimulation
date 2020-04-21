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
		cout << "Window creation failed" << endl;

		// Quit SDL
		SDL_Quit();

		return 2;
	}

	// Create the renderer
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	if (renderer == NULL)
	{
		cout << "Renderer creation failed" << endl;

		// Destroy the SDL window
		SDL_DestroyWindow(window);
		// Quit SDL
		SDL_Quit();

		return 3;
	}

	// Create the texture
	SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, WINDOW_WIDTH, WINDOW_HEIGHT);

	if (texture == NULL)
	{
		cout << "Texture creation failed" << endl;

		// Destroy the renderer
		SDL_DestroyRenderer(renderer);
		// Destroy the SDL window
		SDL_DestroyWindow(window);
		// Quit SDL
		SDL_Quit();

		return 4;
	}

	// Create the buffer (for the pixels' information)
	Uint32 *buffer = new Uint32[WINDOW_WIDTH * WINDOW_HEIGHT];

	// Set all the pixels to the white color
	memset(buffer, 0xFF, WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(Uint32));

	// Update the texture
	SDL_UpdateTexture(texture, NULL, buffer, WINDOW_WIDTH * sizeof(Uint32));

	// Rendering
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

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

	// Destroy the buffer (for the pixels' information)
	delete[] buffer;
	// Destroy the texture
	SDL_DestroyTexture(texture);
	// Destroy the renderer
	SDL_DestroyRenderer(renderer);
	// Destroy the SDL window
	SDL_DestroyWindow(window);
	// Quit SDL
	SDL_Quit();

	return 0;
}

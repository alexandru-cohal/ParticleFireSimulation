#include "Screen.h"

namespace particuleSimulator
{
	Screen::Screen():
		m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL)
	{
	}

	bool Screen::init()
	{
		// Initialize SDL
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			return false;
		}

		// Create the window
		m_window = SDL_CreateWindow("Particle Fire Simulation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

		if (m_window == NULL)
		{
			// Quit SDL
			SDL_Quit();

			return false;
		}

		// Create the renderer
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

		if (m_renderer == NULL)
		{
			// Destroy the SDL window
			SDL_DestroyWindow(m_window);
			// Quit SDL
			SDL_Quit();

			return false;
		}

		// Create the texture
		m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, WINDOW_WIDTH, WINDOW_HEIGHT);

		if (m_texture == NULL)
		{
			// Destroy the renderer
			SDL_DestroyRenderer(m_renderer);
			// Destroy the SDL window
			SDL_DestroyWindow(m_window);
			// Quit SDL
			SDL_Quit();

			return false;
		}

		// Create the buffer (for the pixels' information)
		m_buffer = new Uint32[WINDOW_WIDTH * WINDOW_HEIGHT];

		// Set all the pixels to the black color
		memset(m_buffer, 0, WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(Uint32));

		// Set all the pixels to the yellow color
		for (int index = 0; index < WINDOW_WIDTH * WINDOW_HEIGHT; index++)
		{
			m_buffer[index] = 0xFFFF00FF;
		}

		// Update the texture
		SDL_UpdateTexture(m_texture, NULL, m_buffer, WINDOW_WIDTH * sizeof(Uint32));

		// Rendering
		SDL_RenderClear(m_renderer);
		SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
		SDL_RenderPresent(m_renderer);

		return true;
	}

	bool Screen::processEvents()
	{
		// Event information
		SDL_Event event;

		// Iterate over the events which happened and have to be processed
		while (SDL_PollEvent(&event))
		{
			// Get out of the loop when the SDL window is closed (SDL quit event)
			if (event.type == SDL_QUIT)
			{
				return false;
			}
		}

		return true;
	}

	void Screen::close()
	{
		// Destroy the buffer (for the pixels' information)
		delete[] m_buffer;
		// Destroy the texture
		SDL_DestroyTexture(m_texture);
		// Destroy the renderer
		SDL_DestroyRenderer(m_renderer);
		// Destroy the SDL window
		SDL_DestroyWindow(m_window);
		// Quit SDL
		SDL_Quit();
	}
}

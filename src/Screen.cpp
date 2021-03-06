// The definition of the methods of the class used for:
// 1) screen rendering
// 2) interaction with the screen

#include "Screen.h"

namespace particuleSimulator
{
	Screen::Screen():
		m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL), m_bufferAux(NULL)
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

		// Create the buffers (for the pixels' information)
		m_buffer = new Uint32[WINDOW_WIDTH * WINDOW_HEIGHT];
		m_bufferAux = new Uint32[WINDOW_WIDTH * WINDOW_HEIGHT];

		// Set all the pixels to the black color
		memset(m_buffer, 0, WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(Uint32));
		memset(m_bufferAux, 0, WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(Uint32));

		return true;
	}

	void Screen::update()
	{
		// Update the texture
		SDL_UpdateTexture(m_texture, NULL, m_buffer, WINDOW_WIDTH * sizeof(Uint32));

		// Rendering
		SDL_RenderClear(m_renderer);
		SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
		SDL_RenderPresent(m_renderer);
	}

	void Screen::clear()
	{
		memset(m_buffer, 0, WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(Uint32));
		memset(m_bufferAux, 0, WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(Uint32));
	}

	void Screen::boxBlur()
	{
		// Swap the buffers
		Uint32 *temp;

		temp = m_buffer;
		m_buffer = m_bufferAux;
		m_bufferAux = temp;

		// Iterate over all the pixels
		for (int yMiddleBox = 0; yMiddleBox < WINDOW_HEIGHT; yMiddleBox++)
			for (int xMiddleBox = 0; xMiddleBox < WINDOW_WIDTH; xMiddleBox++)
			{
				int redSum = 0;
				int greenSum = 0;
				int blueSum = 0;

				// Iterate over the pixels of the selected pixel's surrounding 3 x 3 box
				for (int row = -1; row <= 1; row++)
					for (int col = -1; col <= 1; col++)
					{
						// The coordinates of the selected pixel from the box
						int xInBox = xMiddleBox + col;
						int yInBox = yMiddleBox + row;

						// Check if the pixel is in the window
						if (xInBox >=0 && xInBox < WINDOW_WIDTH)
							if (yInBox >=0 && yInBox < WINDOW_HEIGHT)
							{
								// Get the pixel's RGB values
								Uint32 color = m_bufferAux[yInBox * WINDOW_WIDTH + xInBox];

								Uint8 red = color >> 24;
								Uint8 green = color >> 16;
								Uint8 blue = color >> 8;

								// Add the RGB values to the total
								redSum += red;
								greenSum += green;
								blueSum += blue;
							}
					}

				// Calculate the average of the RGB values of the box's pixels
				Uint8 redAvg = redSum / 9;
				Uint8 greenAvg = greenSum / 9;
				Uint8 blueAvg = blueSum / 9;

				// Set the box average RGB value to the buffer for the selected pixel
				setPixel(xMiddleBox, yMiddleBox, redAvg, greenAvg, blueAvg);
			}
	}

	void Screen::setPixel(unsigned int x, unsigned int y, Uint8 red, Uint8 green, Uint8 blue)
	{
		// Check if the pixel's position is valid
		if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		{
			return;
		}

		// color = 0xRRGGBBAA, R - red, G - green, B - blue, A - alpha
		Uint32 color = (red << 24) + (green << 16) + (blue << 8) + 0xFF;

		m_buffer[y * WINDOW_WIDTH + x] = color;
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
		// Destroy the buffers (for the pixels' information)
		delete[] m_buffer;
		delete[] m_bufferAux;

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

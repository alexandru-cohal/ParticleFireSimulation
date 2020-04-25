#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace particuleSimulator
{
	class Screen
	{
	public:
		// The size of the window
		const static int WINDOW_WIDTH = 800;
		const static int WINDOW_HEIGHT = 600;

	private:
		SDL_Window *m_window;
		SDL_Renderer *m_renderer;
		SDL_Texture *m_texture;
		Uint32 *m_buffer;

	public:
		Screen();
		bool init();
		void update();
		void setPixel(unsigned int x, unsigned int y, Uint8 red, Uint8 green, Uint8 blue); // x - column, y - row
		bool processEvents();
		void close();
	};
}

#endif /* SCREEN_H_ */

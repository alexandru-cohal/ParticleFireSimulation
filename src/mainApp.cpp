#include <iostream>
#include <math.h>
#include <SDL.h>

#include "Screen.h"

using namespace std;
using namespace particuleSimulator;

int main()
{
	Screen screen;

	if (screen.init() == false)
	{
		cout << "Error in the initialization of the SDL" << endl;
	}

	// The application loop
	while (true)
	{
		// Generate the Red, Blue and Green values for the window's pixels
		int elapsedTime = SDL_GetTicks();
		unsigned char red = (unsigned char)((1 + sin(elapsedTime * 0.0001)) * 128);
		unsigned char green = (unsigned char)((1 + sin(elapsedTime * 0.0002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsedTime * 0.0003)) * 128);

		// Set all the window's pixels
		for (int y = 0; y < Screen::WINDOW_HEIGHT; y++)
			for (int x = 0; x < Screen::WINDOW_WIDTH; x++)
			{
				screen.setPixel(x, y, red, green, blue);
			}

		// Update the screen
		screen.update();

		// Check for events
		if (screen.processEvents() == false)
		{
			break;
		}
	}

	screen.close();

	return 0;
}

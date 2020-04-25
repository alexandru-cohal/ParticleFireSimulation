#include <iostream>
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
		// Set all the window's pixels to the purple color
		for (int y = 0; y < Screen::WINDOW_HEIGHT; y++)
			for (int x = 0; x < Screen::WINDOW_WIDTH; x++)
			{
				screen.setPixel(x, y, 128, 0, 255);
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

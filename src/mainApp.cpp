#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <SDL.h>

#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace particuleSimulator;

int main()
{
	// Initialize the random number generator
	srand(time(NULL));

	// The Screen object
	Screen screen;

	if (screen.init() == false)
	{
		cout << "Error in the initialization of the SDL" << endl;
	}

	// The Swarm object
	Swarm swarm;

	// The application loop
	while (true)
	{
		// Get the elapsed time
		int elapsedTime = SDL_GetTicks();

		// Update the position of the swarm's particles
		swarm.update(elapsedTime);

		// Get the particles of the swarm
		const Particle * const sParticles = swarm.getParticles();

		// Generate the Red, Blue and Green values for the particles
		unsigned char red = (unsigned char)((1 + sin(elapsedTime * 0.0001)) * 128);
		unsigned char green = (unsigned char)((1 + sin(elapsedTime * 0.0002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsedTime * 0.0003)) * 128);

		// Set the particles and their colors to the screen's buffer
		for (int i = 0; i < Swarm::NPARTICLES; i++)
		{
			Particle particle = sParticles[i];

			int x = (particle.m_x + 1) * (Screen::WINDOW_WIDTH / 2);
			int y = particle.m_y * (Screen::WINDOW_WIDTH / 2) + (Screen::WINDOW_HEIGHT / 2);

			screen.setPixel(x, y, red, green, blue);
		}

		// Apply the blur effect
		screen.boxBlur();

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

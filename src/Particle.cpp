#include "Particle.h"

#include <stdlib.h>
#include <math.h>

namespace particuleSimulator
{
	Particle::Particle(): m_x(0), m_y(0)
	{
		m_direction = (2 * M_PI * rand()) / RAND_MAX;
		m_speed = pow((0.05 * rand()) / RAND_MAX, 2);
	}

	void Particle::init()
	{
		m_x = 0;
		m_y = 0;
		m_direction = (2 * M_PI * rand()) / RAND_MAX;
		m_speed = pow((0.05 * rand()) / RAND_MAX, 2);
	}

	void Particle::update(int intervalTime)
	{
		// Modify the direction for having a "curly" effect
		m_direction += 0.001 * intervalTime;

		// Calculate the speed in x and y directions
		double xSpeed = m_speed * cos(m_direction);
		double ySpeed = m_speed * sin(m_direction);

		// Update the position based on the speed and the time interval between updates
		m_x += xSpeed * intervalTime;
		m_y += ySpeed * intervalTime;

		// If the particle goes outside of the window, reinitialize it in the middle of the window
		if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1)
		{
			init();
		}

		// Choose randomly if the particle will be moved in the middle of the window
		if (rand() < RAND_MAX / 1000)
		{
			init();
		}
	}
}

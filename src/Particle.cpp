#include "Particle.h"

#include <stdlib.h>
#include <math.h>

namespace particuleSimulator
{
	Particle::Particle(): m_x(0), m_y(0)
	{
		m_direction = (2 * M_PI * rand()) / RAND_MAX;
		m_speed = (0.001 * rand()) / RAND_MAX;
	}

	void Particle::update(int intervalTime)
	{
		// Calculate the speed in x and y directions
		double xSpeed = m_speed * cos(m_direction);
		double ySpeed = m_speed * sin(m_direction);

		// Update the position based on the speed and the time interval between updates
		m_x += xSpeed * intervalTime;
		m_y += ySpeed * intervalTime;
	}
}

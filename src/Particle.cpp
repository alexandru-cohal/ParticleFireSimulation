// The definition of the methods of the class used for:
// - manipulating a single particle

#include "Particle.h"

#include <math.h>

namespace particuleSimulator
{
	Particle::Particle(): m_x(0), m_y(0)
	{
		initSpeedAndDirection();
	}

	void Particle::respawn()
	{
		// Reinitialize the particle in the middle of the window and with the initial speed and direction
		m_x = 0;
		m_y = 0;
		initSpeedAndDirection();
	}

	void Particle::initSpeedAndDirection()
	{
		m_direction = (2 * M_PI * rand()) / RAND_MAX;
		m_speed = pow((SPEEDFACTOR * rand()) / RAND_MAX, 2);
	}

	void Particle::update(int intervalTime)
	{
		// Modify the direction for having a "curly" effect
		m_direction += DIRECTIONFACTOR * intervalTime;

		// Calculate the speed in x and y directions
		double xSpeed = m_speed * cos(m_direction);
		double ySpeed = m_speed * sin(m_direction);

		// Update the position based on the speed and the time interval between updates
		m_x += xSpeed * intervalTime;
		m_y += ySpeed * intervalTime;

		// If the particle goes outside of the window, reinitialize it in the middle of the window
		if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1)
		{
			respawn();
		}

		// Choose randomly if the particle will be reinitialized in the middle of the window
		if (rand() < RESPAWNRATE)
		{
			respawn();
		}
	}
}

#include "Particle.h"

#include <stdlib.h>

namespace particuleSimulator
{
	Particle::Particle()
	{
		m_x = ((2.0 * rand()) / RAND_MAX) - 1;
		m_y = ((2.0 * rand()) / RAND_MAX) - 1;
	}

	void Particle::update()
	{
		const double xSpeed = 0.01 * ((2.0 * rand()) / RAND_MAX - 1);
		const double ySpeed = 0.01 * ((2.0 * rand()) / RAND_MAX - 1);

		m_x += xSpeed;
		m_y += ySpeed;
	}
}

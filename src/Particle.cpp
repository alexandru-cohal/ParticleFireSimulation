#include "Particle.h"

#include <stdlib.h>

namespace particuleSimulator
{
	Particle::Particle()
	{
		m_x = ((2.0 * rand()) / RAND_MAX) - 1;
		m_y = ((2.0 * rand()) / RAND_MAX) - 1;

		m_xSpeed = 0.01 * ((2.0 * rand()) / RAND_MAX - 1);
		m_ySpeed = 0.01 * ((2.0 * rand()) / RAND_MAX - 1);
	}

	void Particle::update()
	{
		m_x += m_xSpeed;
		m_y += m_ySpeed;
	}
}

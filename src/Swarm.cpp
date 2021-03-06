// The definition of the methods of the class used for:
// - manipulating the swarm of multiple particles

#include "Swarm.h"

namespace particuleSimulator
{
	Swarm::Swarm(): lastElapsedTime(0)
	{
		m_pParticles = new Particle[NPARTICLES];
	}

	Swarm::~Swarm()
	{
		delete[] m_pParticles;
	}

	const Particle * const Swarm::getParticles()
	{
		return m_pParticles;
	}

	void Swarm::update(int elapsedTime)
	{
		// The update of the Swarm is done by updating all the Particles

		// Calculate the time interval between the previous update and the current one
		int intervalTime = elapsedTime - lastElapsedTime;

		// Update each particle
		for (int i = 0; i < Swarm::NPARTICLES; i++)
		{
			m_pParticles[i].update(intervalTime);
		}

		// Update the lastElapsedTime
		lastElapsedTime = elapsedTime;
	}
}

// The declaration of the class used for:
// - manipulating the swarm of multiple particles

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace particuleSimulator
{
	class Swarm
	{
	public:
		const static int NPARTICLES = 5000;

	private:
		Particle * m_pParticles;
		int lastElapsedTime;

	public:
		Swarm();
		~Swarm();
		const Particle * const getParticles();
		// getParticles() returns a constant pointer to a constant Particle in order to:
		// 1. not be able to change where the pointer points
		// 2. not be able to change what is pointed by the pointer
		void update(int elapsedTime);
	};
}

#endif /* SWARM_H_ */

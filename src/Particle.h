// The declaration of the class used for:
// - manipulating a single particle

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <stdlib.h>

namespace particuleSimulator
{
	class Particle
	{
	public:
		double m_x; // in the [-1, 1] interval
		double m_y; // in the [-1, 1] interval

		constexpr static double RVARIATIONFACTOR = 0.001;
		constexpr static double GVARIATIONFACTOR = 0.002;
		constexpr static double BVARIATIONFACTOR = 0.003;

	private:
		double m_speed;
		double m_direction; // the angle from the [0, 2*PI] radians interval

		constexpr static double RESPAWNRATE = RAND_MAX / 1000;
		constexpr static double SPEEDFACTOR = 0.05;
		constexpr static double DIRECTIONFACTOR = 0.001;

	public:
		Particle();
		void update(int intervalTime);

	private:
		void respawn();
		void initSpeedAndDirection();

	};
}

#endif /* PARTICLE_H_ */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace particuleSimulator
{
	class Particle
	{
	public:
		double m_x;
		double m_y;

	public:
		Particle();
		void update();
	};
}

#endif /* PARTICLE_H_ */

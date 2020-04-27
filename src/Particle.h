#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace particuleSimulator
{
	class Particle
	{
	public:
		double m_x;
		double m_y;
		double m_xSpeed;
		double m_ySpeed;

	public:
		Particle();
		void update();
	};
}

#endif /* PARTICLE_H_ */

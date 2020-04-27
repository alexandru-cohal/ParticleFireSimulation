#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace particuleSimulator
{
	class Particle
	{
	public:
		double m_x;
		double m_y;

	private:
		double m_speed;
		double m_direction;

	public:
		Particle();
		void update(int intervalTime);

	private:
		void init();
	};
}

#endif /* PARTICLE_H_ */

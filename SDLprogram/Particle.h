#pragma once

namespace terry {

	struct Particle {
		double m_x;
		double m_y;

	private:
		double m_speed;
		double m_directon;

	private:
		void init();
		
	public:
		Particle();
		virtual ~Particle();
		void update(int interval);
		
	};
}

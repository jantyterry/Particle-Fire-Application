
#include "Particle.h"
#include <stdlib.h>
#include <math.h>
#include "Screen.h"


namespace terry {

	Particle::Particle():m_x(0), m_y(0) {
		
		init();
		
	}

	void Particle::init() {
		m_x = 0;
		m_y = 0;
		m_directon = (2 * M_PI * rand()) / RAND_MAX;
		m_speed = (0.04 * rand()) / RAND_MAX;

		m_speed *= m_speed;
	}

	Particle::~Particle() {

	}


	void Particle::update(int interval) {

		m_directon += interval*0.0004;
		
		double x_speed = m_speed * cos(m_directon);
		double y_speed = m_speed * sin(m_directon);

		m_x += x_speed * interval;
		m_y += y_speed * interval;

		if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1) {
			init();
		}

		if (rand() < RAND_MAX / 100) {
			init();
		}

	}

}
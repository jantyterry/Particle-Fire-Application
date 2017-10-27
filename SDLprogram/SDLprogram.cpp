// SDLprogram.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <SDL.h>
#undef main
#include "Screen.h"
#include "Particle.h"
#include "Swarm.h"

using namespace std;

using namespace terry;


int main() {

	srand(time(NULL));

	Screen screen;

	if (screen.init() == false) {
		cout << "Error initualizing SDL" << endl;
	}

	Swarm swarm;

	while (true) {
		//Update particles
		//Draw particles

		int elapsed = SDL_GetTicks();

		//screen.clear();
		swarm.update(elapsed);

		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);


		const Particle * const pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particles = pParticles[i];

			int x = (particles.m_x + 1)*Screen::SCREEN_WIDTH/2;
			int y = particles.m_y * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGTH/2;

			screen.setPixel(x, y, red, green, blue);
		}


		screen.BoxBlur();

		//Draw the screen
		screen.update();


		//Check for messages/events - done by users

		if (screen.processEvent() == false) {
			break;
		}
	}



	screen.close();

    return 0;
}


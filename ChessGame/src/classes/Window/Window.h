#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include "../Game/Game.h"

class Window {
	public:
		Window(int width, int height, std::string windowName);
		~Window();

		void run();

	private:
		sf::RenderWindow window;
};

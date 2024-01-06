#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include <map>

#include "../Game/Game.h"

class Window {
	public:
		Window(int width, int height, std::string windowName);
		~Window();

		void run();

	private:
		const int8_t BOARD_SIZE = 8;
		const int SQUARE_SIZE = 60;

		sf::RenderWindow window;
		std::map<std::string, sf::Color> colors;

		void drawSquares();
};

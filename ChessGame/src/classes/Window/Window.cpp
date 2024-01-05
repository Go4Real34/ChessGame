#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Window.h"

Window::Window(int width, int height, std::string windowName) {
	this -> window.create(sf::VideoMode(width, height), windowName);
}

Window::~Window() {
}

void Window::run() {
	while (this -> window.isOpen()) {
		sf::Event event;
		if (window.waitEvent(event)) {
			if (event.type == sf::Event::Closed) {
				this -> window.close();
			}
		}

		this -> window.clear();
		this -> window.display();
	}
}

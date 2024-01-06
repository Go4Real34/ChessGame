#include "Window.h"

Window::Window(int width, int height, std::string windowName) {
	this -> window.create(sf::VideoMode(width, height), windowName);

	this -> colors = {
		{ "lightBrown", sf::Color(181, 136, 99)},
		{      "brown", sf::Color(240, 217, 181)},
		{      "green", sf::Color(205, 210, 106)}
	};

	this -> game = Game();
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
		
		this -> drawSquares();
		this -> drawPieces();

		this -> window.display();
	}
}


void Window::drawSquares() {
	for (int row = 0; row < this -> BOARD_SIZE; row++) {
		for (int column = 0; column < this -> BOARD_SIZE; column++) {
			sf::RectangleShape square(sf::Vector2f(this -> SQUARE_SIZE, this -> SQUARE_SIZE));
			square.setPosition(row * this -> SQUARE_SIZE, column * this -> SQUARE_SIZE);

			if ((row + column) % 2 == 0) {
				square.setFillColor(this -> colors["brown"]);
			} else {
				square.setFillColor(this -> colors["lightBrown"]);
			}

			this -> window.draw(square);
		}
	}
}

void Window::drawPieces() {
	Board currentBoard = this -> game.getCurrentBoard();

	for (int row = 0; row < this -> BOARD_SIZE; row++) {
		for (int column = 0; column < this -> BOARD_SIZE; column++) {
			Piece* piece = currentBoard.board[row][column];
			if (piece != nullptr) {
				sf::Sprite pieceSprite = piece -> getSprite();

				pieceSprite.setPosition(column * this -> SQUARE_SIZE, row * this -> SQUARE_SIZE);

				this -> window.draw(pieceSprite);
			}
		}
	}
}

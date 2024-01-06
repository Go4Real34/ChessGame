#include "Window.h"

Window::Window(int width, int height, std::string windowName) {
	this -> window.create(sf::VideoMode(width, height), windowName);

	this -> colors = {
		{ "lightBrown", sf::Color(181, 136, 99)},
		{      "brown", sf::Color(240, 217, 181)},
		{      "green", sf::Color(205, 210, 106)}
	};

	this -> game = Game();

	this -> isAPieceSelected = false;
	this -> selectedSquareRow = -1;
	this -> selectedSquareColumn = -1;
}

Window::~Window() {
}

void Window::run() {
	while (this -> window.isOpen()) {
		sf::Event event;
		if (window.waitEvent(event)) {
			switch (event.type) {
				case sf::Event::MouseButtonPressed: {
					if (event.mouseButton.button == sf::Mouse::Button::Left) {
						int mouseX = event.mouseButton.x;
						int mouseY = event.mouseButton.y;

						int8_t clickedRow = mouseY / this -> SQUARE_SIZE;
						int8_t clickedColumn = mouseX / this -> SQUARE_SIZE;

						Board currentBoard = this -> game.getCurrentBoard();
						Piece* clickedPiece = currentBoard.board[clickedRow][clickedColumn];
						if (clickedPiece == nullptr) {
							this -> resetSelectedPiece();
							break;
						}

						if (clickedPiece -> getIsWhite() != game.getCurrentTurn()) {
							this -> resetSelectedPiece();
							break;
						}

						if (!this -> isAPieceSelected) {
							this -> selectPiece(clickedRow, clickedColumn);
							break;
						}

						if (!(clickedRow == this -> selectedSquareRow && clickedColumn == this -> selectedSquareColumn)) {
							this -> selectPiece(clickedRow, clickedColumn);
							break;
						}

						this -> resetSelectedPiece();
						break;
					}
				}

				case sf::Event::Closed: {
					this -> window.close();
					break;
				}
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

			if (this -> isAPieceSelected) {
				if (row == this -> selectedSquareColumn && column == this -> selectedSquareRow) {
					square.setFillColor(this -> colors["green"]);
				}
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

void Window::selectPiece(int8_t clickedRow, int8_t clickedColumn) {
	this -> isAPieceSelected = true;
	this -> selectedSquareRow = clickedRow;
	this -> selectedSquareColumn = clickedColumn;
}

void Window::resetSelectedPiece() {
	this -> isAPieceSelected = false;
	this -> selectedSquareRow = -1;
	this -> selectedSquareColumn = -1;
}

#include "Window.h"

Window::Window(int width, int height, std::string windowName) {
	this -> window.create(sf::VideoMode(width, height), windowName);

	this -> colors = {
		{ "lightBrown", sf::Color(181, 136, 99)},
		{      "brown", sf::Color(240, 217, 181)},
		{      "green", sf::Color(205, 210, 106)},
		{        "red", sf::Color(191,  62,  42)}
	};

	this -> game = Game();

	this -> isAPieceSelected = false;
	this -> selectedSquareRow = -1;
	this -> selectedSquareColumn = -1;

	this -> isAMoveInProgress = false;
	this -> targetedSquareRow = -1;
	this -> targetedSquareColumn = -1;

	this -> doRecieveMoveInput = true;
}

Window::~Window() {
}

void Window::run() {
	while (this -> window.isOpen()) {
		sf::Event event;
		if (window.waitEvent(event)) {
			switch (event.type) {
				case sf::Event::MouseButtonPressed: {
					if (doRecieveMoveInput) {
						if (event.mouseButton.button == sf::Mouse::Button::Left) {
							int mouseX = event.mouseButton.x;
							int mouseY = event.mouseButton.y;

							int8_t clickedRow = mouseY / this -> SQUARE_SIZE;
							int8_t clickedColumn = mouseX / this -> SQUARE_SIZE;

							Board currentBoard = this -> game.getCurrentBoard();
							Piece* clickedPiece = currentBoard.board[clickedRow][clickedColumn];
						
							if (!this -> isAMoveInProgress) {
								if (clickedPiece == nullptr) {
									std::cout << "Invalid selection. There is no piece here." << std::endl;
									this -> resetSelectedSquares();
									break;
								}

								if (clickedPiece -> getIsWhite() != game.getCurrentTurn()) {
									std::cout << "Invalid selection. " << (this -> game.getCurrentTurn() ? "White" : "Black") << "'s turn." << std::endl;
									this -> resetSelectedSquares();
									break;
								}

								if (!this -> isAPieceSelected) {
									this -> selectSquare(clickedRow, clickedColumn);
									break;
								}

								if (!(clickedRow == this -> selectedSquareRow && clickedColumn == this -> selectedSquareColumn)) {
									this -> selectSquare(clickedRow, clickedColumn);
									break;
								}

								this -> resetSelectedSquares();
								break;
							} else {
								selectTargetedSquare(clickedRow, clickedColumn);

								Move move = Move(this -> selectedSquareRow, this -> selectedSquareColumn, 
												 this -> targetedSquareRow, this -> targetedSquareColumn);

								if (this -> selectedSquareRow == this -> targetedSquareRow && this -> selectedSquareColumn == this -> targetedSquareColumn) {
									this -> resetSelectedSquares();
									break;
								}

								if (this -> game.playMove(move)) {
									std::cout << "Move: " << "(" << (int) move.xCoordOld << ", " << (int) move.yCoordOld << ") -> (" << (int) move.xCoordNew << ", " << (int) move.yCoordNew << ")" << std::endl;
									if (this -> game.getIsGameFinished()) {
										std::cout << "Checkmate. " << (this -> game.getIsWinnerWhite() ? "White" : "Black") << " won." << std::endl;
										doRecieveMoveInput = false;
										break;
									}

									if (this -> game.getIsKingChecked()) {
										std::cout << "Check on " << (game.getIsCheckedKingWhite() ? "White" : "Black" )  << " King." << std::endl;
									}
									this -> game.skipToNextTurn();
								} else {
									if (this -> game.getIsKingChecked()) {
										std::cout << "Invalid move. This move won't save " << (game.getIsCheckedKingWhite() ? "White" : "Black" )  << " King from check." << std::endl;
									} else {
										std::cout << "Invalid move. This piece cannot move there." << std::endl;
									}
								}

								resetSelectedSquares();
								break;
							}
						} else if (event.mouseButton.button == sf::Mouse::Button::Right) {
							resetSelectedSquares();
						}
					}
					
					break;
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

			if (this -> game.getIsKingChecked()) {
				Coordination checkedKingCoordination = this -> game.getCheckedKingCoordinations();
				if (row == checkedKingCoordination.y && column == checkedKingCoordination.x) {
					square.setFillColor(this -> colors["red"]);
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

void Window::selectSquare(int8_t clickedRow, int8_t clickedColumn) {
	this -> isAPieceSelected = true;
	this -> isAMoveInProgress = true;
	this -> selectedSquareRow = clickedRow;
	this -> selectedSquareColumn = clickedColumn;
}

void Window::resetSelectedSquares() {
	this -> isAPieceSelected = false;
	this -> isAMoveInProgress = false;
	this -> selectedSquareRow = -1;
	this -> selectedSquareColumn = -1;
}

void Window::selectTargetedSquare(int8_t clickedRow, int8_t clickedColumn) {
	this -> isAMoveInProgress = false;
	this -> targetedSquareRow = clickedRow;
	this -> targetedSquareColumn = clickedColumn;
}

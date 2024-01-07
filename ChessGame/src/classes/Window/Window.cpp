#include "Window.h"

Window::Window() {
	this -> SQUARE_SIZE = float(this -> DEFAULT_SQUARE_SIZE);

	this -> window.create(sf::VideoMode(this -> DEFAULT_WINDOW_WIDTH, this -> DEFAULT_WINDOW_HEIGHT), "Chess");

	this -> colors = {
		{ "lightBrown", sf::Color(181, 136,  99)},
		{      "brown", sf::Color(240, 217, 181)},
		{      "green", sf::Color(170, 162,  58)},
		{ "lightGreen", sf::Color(205, 210, 106)},
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
					if (this -> doRecieveMoveInput) {
						this -> handleMouseEvent(event);
					}
					break;
				}

				case sf::Event::Resized: {
					this -> resizeWindow(event);
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
					square.setFillColor(this -> colors["lightGreen"]);
				}
			}

			if (this -> lastMove.xCoordOld != -1 && this -> lastMove.yCoordOld != -1 && this -> lastMove.xCoordNew != -1 && this -> lastMove.yCoordNew != -1) {
				if (row == this -> lastMove.yCoordOld && column == this -> lastMove.xCoordOld) {
					if ((this -> lastMove.xCoordOld + this -> lastMove.yCoordOld) % 2 == 0) {
						square.setFillColor(this -> colors["lightGreen"]);
					} else {
						square.setFillColor(this -> colors["green"]);
					}
				}

				if (row == this -> lastMove.yCoordNew && column == this -> lastMove.xCoordNew) {
					if ((this -> lastMove.xCoordNew + this -> lastMove.yCoordNew) % 2 == 0) {
						square.setFillColor(this -> colors["lightGreen"]);
					} else {
						square.setFillColor(this -> colors["green"]);
					}
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

	float resizeRatio = this -> SQUARE_SIZE / this -> DEFAULT_SQUARE_SIZE;

	for (int row = 0; row < this -> BOARD_SIZE; row++) {
		for (int column = 0; column < this -> BOARD_SIZE; column++) {
			Piece* piece = currentBoard.board[row][column];
			if (piece != nullptr) {
				sf::Sprite pieceSprite = piece -> getSprite();

				pieceSprite.setScale(resizeRatio, resizeRatio);
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

void Window::updateLastMove(Move move) {
	this -> lastMove = move;
}

void Window::handleMouseEvent(sf::Event event) {
	if (event.mouseButton.button == sf::Mouse::Button::Left) {
		this -> handleMouseLeftClickEvent(event);
	} else if (event.mouseButton.button == sf::Mouse::Button::Right) {
		this -> handleMouseRightClickEvent(event);
	}
}

void Window::handleMouseLeftClickEvent(sf::Event event) {
	int mouseX = event.mouseButton.x;
	int mouseY = event.mouseButton.y;

	sf::Vector2i pixelPosition = sf::Mouse::getPosition(this -> window);
	sf::Vector2f worldPosition = this -> window.mapPixelToCoords(pixelPosition);

	int8_t clickedRow = worldPosition.y / this -> SQUARE_SIZE;
	int8_t clickedColumn = worldPosition.x / this -> SQUARE_SIZE;

	Board currentBoard = this -> game.getCurrentBoard();
	Piece* clickedPiece = currentBoard.board[clickedRow][clickedColumn];
						
	if (!this -> isAMoveInProgress) {
		if (clickedPiece == nullptr) {
			std::cout << "Invalid selection. There is no piece here." << std::endl;
			this -> resetSelectedSquares();
			return;
		}

		if (clickedPiece -> getIsWhite() != this -> game.getCurrentTurn()) {
			std::cout << "Invalid selection. " << (this -> game.getCurrentTurn() ? "White" : "Black") << "'s turn." << std::endl;
			this -> resetSelectedSquares();
			return;
		}

		if (!this -> isAPieceSelected) {
			this -> selectSquare(clickedRow, clickedColumn);
			return;
		}

		if (!(clickedRow == this -> selectedSquareRow && clickedColumn == this -> selectedSquareColumn)) {
			this -> selectSquare(clickedRow, clickedColumn);
			return;
		}

		this -> resetSelectedSquares();
		return;
	}

	this -> selectTargetedSquare(clickedRow, clickedColumn);

	if (this -> selectedSquareRow == this -> targetedSquareRow && this -> selectedSquareColumn == this -> targetedSquareColumn) {
		this -> resetSelectedSquares();
		return;
	}

	Move move = Move(this -> selectedSquareRow, this -> selectedSquareColumn, 
						this -> targetedSquareRow, this -> targetedSquareColumn);

	if (!this -> game.playMove(move)) {
		if (this -> game.getIsKingChecked()) {
			std::cout << "Invalid move. This move won't save " << (this -> game.getIsCheckedKingWhite() ? "White" : "Black" )  << " King from check." << std::endl;
		} else {
			std::cout << "Invalid move. This piece cannot move there." << std::endl;
		}

		this -> resetSelectedSquares();
		return;
	}

	this -> updateLastMove(move);

	std::cout << "Move: " << "(" << (int) move.xCoordOld << ", " << (int) move.yCoordOld << ") -> (" << (int) move.xCoordNew << ", " << (int) move.yCoordNew << ")" << std::endl;
	if (this -> game.getIsGameFinished()) {
		std::cout << "Checkmate. " << (this -> game.getIsWinnerWhite() ? "White" : "Black") << " won." << std::endl;
		this -> doRecieveMoveInput = false;
		return;
	}

	if (this -> game.getIsKingChecked()) {
		std::cout << "Check on " << (game.getIsCheckedKingWhite() ? "White" : "Black" )  << " King." << std::endl;
	}
	

	this -> game.skipToNextTurn();
	return;
}

void Window::handleMouseRightClickEvent(sf::Event event) {
	this -> resetSelectedSquares();
	return;
}

void Window::resizeWindow(sf::Event event) {
	float newWidth = event.size.width;
	float newHeight = event.size.height;

	float originalBoardWidth = this -> BOARD_SIZE * this -> SQUARE_SIZE;
	float originalBoardHeight = this -> BOARD_SIZE * this -> SQUARE_SIZE;

	float widthRatio = newWidth / originalBoardWidth;
	float heightRatio = newHeight / originalBoardHeight;

	float scaleRatio = (widthRatio < heightRatio) ? widthRatio : heightRatio;

	float scaledBoardWidth = originalBoardWidth * scaleRatio;
	float scaledBoardHeight = originalBoardHeight * scaleRatio;

	float horizontalMargin = (newWidth - scaledBoardWidth) / 2.f;
	float verticalMargin = (newHeight - scaledBoardHeight) / 2.f;

	sf::FloatRect viewport(
		horizontalMargin / newWidth,
		verticalMargin / newHeight,
		(newWidth - 2 * horizontalMargin) / newWidth,
		(newHeight - 2 * verticalMargin) / newHeight
	);

	sf::View view(sf::FloatRect(0, 0, scaledBoardWidth, scaledBoardHeight));
	view.setViewport(viewport);
	this -> window.setView(view);

	this -> SQUARE_SIZE *= scaleRatio;
}

#include <SFML/Graphics.hpp>

#include "Bishop.h"

Bishop::Bishop(bool isWhite, int8_t XCoord, int8_t YCoord) {
	this -> isWhite = isWhite;
	this -> xCoord = XCoord;
	this -> yCoord = YCoord;

	sf::Texture texture;
	sf::IntRect blankPieceBackground;
	if (this -> isWhite) {
		texture.loadFromFile("./assets/textures/white_bishop.png", blankPieceBackground);
	} else {
		texture.loadFromFile("./assets/textures/black_bishop.png", blankPieceBackground);
	}
	this -> sprite.setTexture(texture, true);
}

Bishop::~Bishop() {
}

void Bishop::getPieceLegalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord){
	if (!isPieceBishop(board, xCoord, yCoord)) {
		return;
	}

	addBottomLeftDiagonalMoves(board, allMoves, xCoord, yCoord);
	addUpRightDiagonalMoves(board, allMoves, xCoord, yCoord);
	addUpLeftDiagonalMoves(board, allMoves, xCoord, yCoord);
	addBottomRightDiagonalMoves(board, allMoves, xCoord, yCoord);
}


bool Bishop::isPieceBishop(std::vector<std::vector<Piece*>>& board, int8_t XCoord, int8_t YCoord) {
	return dynamic_cast<Bishop*>(board[XCoord][YCoord]) != nullptr;
}

void Bishop::addBottomLeftDiagonalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
	int8_t offsetX = 0;
	int8_t offsetY = 0;
	while (true) {
		offsetX++;
		offsetY++;

		if (willBeAtBoundry(xCoord, offsetX, yCoord, offsetY)) {
			return;
		}

		if (isSquareEmpty(board, xCoord + offsetX, yCoord + offsetY)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + offsetX, yCoord + offsetY));
		} else {
			return;
		}
	}
}

bool Bishop::willBeAtBoundry(int8_t xCoord, int8_t offsetX, int8_t yCoord, int8_t offsetY) {
	return (willBeAtRightmostColumn(xCoord, offsetX) || willBeAtLeftmostColumn(xCoord, offsetX) || 
			willBeAtTopmostRow(yCoord, offsetY) || willBeAtBottommostRow(yCoord, offsetY));
}

bool Bishop::willBeAtRightmostColumn(int8_t xCoord, int8_t offsetX) {
	return (xCoord + offsetX > 7);
}

bool Bishop::willBeAtLeftmostColumn(int8_t xCoord, int8_t offsetX) {
	return (xCoord + offsetX < 0);
}

bool Bishop::willBeAtTopmostRow(int8_t yCoord, int8_t offsetY) {
	return (yCoord + offsetY > 7);
}

bool Bishop::willBeAtBottommostRow(int8_t yCoord, int8_t offsetY) {
	return (yCoord + offsetY < 0);
}

bool Bishop::isSquareEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	if (this -> isWhite) {
		return (dynamic_cast<Piece*>(board[xCoord][yCoord]) == nullptr || !(board[xCoord][yCoord] -> getIsWhite()));
	} else {
		return (dynamic_cast<Piece*>(board[xCoord][yCoord]) == nullptr || board[xCoord][yCoord] -> getIsWhite());
	}
}

void Bishop::addUpRightDiagonalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
	int8_t offsetX = 0;
	int8_t offsetY = 0;
	while (true) {
		offsetX++;
		offsetY++;

		if (willBeAtBoundry(xCoord, offsetX, yCoord, offsetY)) {
			return;
		}

		if (isSquareEmpty(board, xCoord + offsetX, yCoord + offsetY)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + offsetX, yCoord + offsetY));
		} else {
			break;
		}
	}
}

void Bishop::addUpLeftDiagonalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
	int8_t offsetX = 0;
	int8_t offsetY = 0;
	while (true) {
		offsetX++;
		offsetY++;
	
		if (willBeAtBoundry(xCoord, offsetX, yCoord, offsetY)) {
			return;
		}
	
		if (isSquareEmpty(board, xCoord + offsetX, yCoord + offsetY)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + offsetX, yCoord + offsetY));
		} else {
			break;
		}
	}
}

void Bishop::addBottomRightDiagonalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
	int8_t offsetX = 0;
	int8_t offsetY = 0;
	while (true) {
		offsetX++;
		offsetY++;
		
		if (willBeAtBoundry(xCoord, offsetX, yCoord, offsetY)) {
			return;
		}
		
		if (isSquareEmpty(board, xCoord + offsetX, yCoord + offsetY)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + offsetX, yCoord + offsetY));
		} else {
			break;
		}
	}
}

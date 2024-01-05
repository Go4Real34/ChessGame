#include <SFML/Graphics.hpp>

#include "Queen.h"

Queen::Queen(bool isWhite, int8_t XCoord, int8_t YCoord) : Piece(isWhite, XCoord, YCoord) {
	this -> isWhite = isWhite;
	this -> xCoord = XCoord;
	this -> yCoord = YCoord;

	sf::Texture texture;
	sf::IntRect blankPieceBackground;
	if (this -> isWhite) {
		texture.loadFromFile("./assets/textures/white_queen.png", blankPieceBackground);
	} else {
		texture.loadFromFile("./assets/textures/black_queen.png", blankPieceBackground);
	}
	this -> sprite.setTexture(texture, true);
}

Queen::~Queen() {
}

void Queen::getPieceLegalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
	if (!isPieceQueen(board, xCoord, yCoord)) {
		return;
	}

	addBottomLeftDiagonalMoves(board, allMoves, xCoord, yCoord);
	addUpRightDiagonalMoves(board, allMoves, xCoord, yCoord);
	addUpLeftDiagonalMoves(board, allMoves, xCoord, yCoord);
	addBottomRightDiagonalMoves(board, allMoves, xCoord, yCoord);
	addBottomMoves(board, allMoves, xCoord, yCoord);
	addTopMoves(board, allMoves, xCoord, yCoord);
	addLeftMoves(board, allMoves, xCoord, yCoord);
	addRightMoves(board, allMoves, xCoord, yCoord);
}


void Queen::addBottomLeftDiagonalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
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

bool Queen::isPieceQueen(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	return (dynamic_cast<Queen*>(board[xCoord][yCoord])) != nullptr;
}

bool Queen::willBeAtBoundry(int8_t xCoord, int8_t offsetX, int8_t yCoord, int8_t offsetY) {
	return (willBeAtRightmostColumn(xCoord, offsetX) || willBeAtLeftmostColumn(xCoord, offsetX) || 
			willBeAtTopmostRow(yCoord, offsetY) || willBeAtBottommostRow(yCoord, offsetY));
}

bool Queen::willBeAtRightmostColumn(int8_t xCoord, int8_t offsetX) {
	return (xCoord + offsetX > 7);
}

bool Queen::willBeAtLeftmostColumn(int8_t xCoord, int8_t offsetX) {
	return (xCoord + offsetX < 0);
}

bool Queen::willBeAtTopmostRow(int8_t yCoord, int8_t offsetY) {
	return (yCoord + offsetY > 7);
}

bool Queen::willBeAtBottommostRow(int8_t yCoord, int8_t offsetY) {
	return (yCoord + offsetY < 0);
}

bool Queen::isSquareEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	if (this -> isWhite) {
		return (dynamic_cast<Piece*>(board[xCoord][yCoord]) == nullptr || !(board[xCoord][yCoord] -> getIsWhite()));
	} else {
		return (dynamic_cast<Piece*>(board[xCoord][yCoord]) == nullptr || board[xCoord][yCoord] -> getIsWhite());
	}
}

void Queen::addUpRightDiagonalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
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

void Queen::addUpLeftDiagonalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
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

void Queen::addBottomRightDiagonalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
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

void Queen::addBottomMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
	int8_t offsetX = 0;
	int8_t offsetY = 0;
	while (true) {
		offsetX++;
	
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

void Queen::addTopMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
	int8_t offsetX = 0;
	int8_t offsetY = 0;
	while (true) {
		offsetX--;
		
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

void Queen::addLeftMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
	int8_t offsetX = 0;
	int8_t offsetY = 0;
	while (true) {
		offsetY--;
			
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

void Queen::addRightMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
	int8_t offsetX = 0;
	int8_t offsetY = 0;
	while (true) {
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

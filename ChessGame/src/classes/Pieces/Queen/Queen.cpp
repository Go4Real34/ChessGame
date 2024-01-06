#include <SFML/Graphics.hpp>

#include "Queen.h"

Queen::Queen(bool isWhite) {
	this -> isWhite = isWhite;

	if (this -> isWhite) {
		this ->  texture.loadFromFile("./assets/textures/white_queen.png", this -> blankPieceBackground);
	} else {
		this -> texture.loadFromFile("./assets/textures/black_queen.png", this -> blankPieceBackground);
	}
	this -> sprite.setTexture(texture, true);
}

Queen::~Queen() {
}

void Queen::getPieceLegalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
	if (!this -> isPieceQueen(board, xCoord, yCoord)) {
		return;
	}

	this -> addUpRightDiagonalMoves(board, allMoves, xCoord, yCoord);
	this -> addUpLeftDiagonalMoves(board, allMoves, xCoord, yCoord);
	this -> addBottomRightDiagonalMoves(board, allMoves, xCoord, yCoord);
	this -> addBottomLeftDiagonalMoves(board, allMoves, xCoord, yCoord);
	this -> addTopMoves(board, allMoves, xCoord, yCoord);
	this -> addBottomMoves(board, allMoves, xCoord, yCoord);
	this -> addRightMoves(board, allMoves, xCoord, yCoord);
	this -> addLeftMoves(board, allMoves, xCoord, yCoord);
}


bool Queen::isPieceQueen(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	return (dynamic_cast<Queen*>(board[xCoord][yCoord])) != nullptr;
}

void Queen::addUpRightDiagonalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
	int8_t offsetX = 0;
	int8_t offsetY = 0;
	while (true) {
		offsetX--;
		offsetY++;

		if (this -> willBeAtBoundry(xCoord, offsetX, yCoord, offsetY)) {
			return;
		}

		if (this -> isSquareEmpty(board, xCoord + offsetX, yCoord + offsetY)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + offsetX, yCoord + offsetY));
		} else {
			if (this -> isSquareIsContainingEnemyPiece(board, xCoord + offsetX, yCoord + offsetY)) {
				allMoves.push_back(Move(xCoord, yCoord, xCoord + offsetX, yCoord + offsetY));
			}
			return;
		}
	}
}

void Queen::addUpLeftDiagonalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
	int8_t offsetX = 0;
	int8_t offsetY = 0;
	while (true) {
		offsetX--;
		offsetY--;
	
		if (this -> willBeAtBoundry(xCoord, offsetX, yCoord, offsetY)) {
			return;
		}
	
		if (this -> isSquareEmpty(board, xCoord + offsetX, yCoord + offsetY)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + offsetX, yCoord + offsetY));
		} else {
			if (this -> isSquareIsContainingEnemyPiece(board, xCoord + offsetX, yCoord + offsetY)) {
				allMoves.push_back(Move(xCoord, yCoord, xCoord + offsetX, yCoord + offsetY));
			}
			return;
		}
	}
}

void Queen::addBottomRightDiagonalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
	int8_t offsetX = 0;
	int8_t offsetY = 0;
	while (true) {
		offsetX++;
		offsetY++;
		
		if (this -> willBeAtBoundry(xCoord, offsetX, yCoord, offsetY)) {
			return;
		}
		
		if (this -> isSquareEmpty(board, xCoord + offsetX, yCoord + offsetY)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + offsetX, yCoord + offsetY));
		} else {
			if (this -> isSquareIsContainingEnemyPiece(board, xCoord + offsetX, yCoord + offsetY)) {
				allMoves.push_back(Move(xCoord, yCoord, xCoord + offsetX, yCoord + offsetY));
			}
			return;
		}
	}
}

void Queen::addBottomLeftDiagonalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
	int8_t offsetX = 0;
	int8_t offsetY = 0;
	while (true) {
		offsetX++;
		offsetY--;

		if (this -> willBeAtBoundry(xCoord, offsetX, yCoord, offsetY)) {
			return;
		}

		if (this -> isSquareEmpty(board, xCoord + offsetX, yCoord + offsetY)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + offsetX, yCoord + offsetY));
		} else {
			if (this -> isSquareIsContainingEnemyPiece(board, xCoord + offsetX, yCoord + offsetY)) {
				allMoves.push_back(Move(xCoord, yCoord, xCoord + offsetX, yCoord + offsetY));
			}
			return;
		}
	}
}

void Queen::addTopMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
	int8_t offsetX = 0;
	int8_t offsetY = 0;
	while (true) {
		offsetX--;
		
		if (this -> willBeAtBoundry(xCoord, offsetX, yCoord, offsetY)) {
			return;
		}
		
		if (this -> isSquareEmpty(board, xCoord + offsetX, yCoord + offsetY)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + offsetX, yCoord + offsetY));
		} else {
			if (this -> isSquareIsContainingEnemyPiece(board, xCoord + offsetX, yCoord + offsetY)) {
				allMoves.push_back(Move(xCoord, yCoord, xCoord + offsetX, yCoord + offsetY));
			}
			return;
		}
	}
}

void Queen::addBottomMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
	int8_t offsetX = 0;
	int8_t offsetY = 0;
	while (true) {
		offsetX++;
	
		if (this -> willBeAtBoundry(xCoord, offsetX, yCoord, offsetY)) {
			return;
		}
	
		if (this -> isSquareEmpty(board, xCoord + offsetX, yCoord + offsetY)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + offsetX, yCoord + offsetY));
		} else {
			if (this -> isSquareIsContainingEnemyPiece(board, xCoord + offsetX, yCoord + offsetY)) {
				allMoves.push_back(Move(xCoord, yCoord, xCoord + offsetX, yCoord + offsetY));
			}
			return;
		}
	}
}

void Queen::addRightMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
	int8_t offsetX = 0;
	int8_t offsetY = 0;
	while (true) {
		offsetY++;
				
		if (this -> willBeAtBoundry(xCoord, offsetX, yCoord, offsetY)) {
			return;
		}
				
		if (this -> isSquareEmpty(board, xCoord + offsetX, yCoord + offsetY)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + offsetX, yCoord + offsetY));
		} else {
			if (this -> isSquareIsContainingEnemyPiece(board, xCoord + offsetX, yCoord + offsetY)) {
				allMoves.push_back(Move(xCoord, yCoord, xCoord + offsetX, yCoord + offsetY));
			}
			return;
		}
	}
}

void Queen::addLeftMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
	int8_t offsetX = 0;
	int8_t offsetY = 0;
	while (true) {
		offsetY--;
			
		if (this -> willBeAtBoundry(xCoord, offsetX, yCoord, offsetY)) {
			return;
		}
			
		if (this -> isSquareEmpty(board, xCoord + offsetX, yCoord + offsetY)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + offsetX, yCoord + offsetY));
		} else {
			if (this -> isSquareIsContainingEnemyPiece(board, xCoord + offsetX, yCoord + offsetY)) {
				allMoves.push_back(Move(xCoord, yCoord, xCoord + offsetX, yCoord + offsetY));
			}
			return;
		}
	}
}

bool Queen::isSquareEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	return dynamic_cast<Piece*>(board[xCoord][yCoord]) == nullptr;
}

bool Queen::isSquareIsContainingEnemyPiece(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	return board[xCoord][yCoord] -> getIsWhite() != this -> isWhite;
}

bool Queen::willBeAtBoundry(int8_t xCoord, int8_t offsetX, int8_t yCoord, int8_t offsetY) {
	return (this -> willBeAtRightmostColumn(yCoord, offsetY) || this -> willBeAtLeftmostColumn(yCoord, offsetY) || 
			this -> willBeAtTopmostRow(xCoord, offsetX) || this -> willBeAtBottommostRow(xCoord, offsetX));
}

bool Queen::willBeAtRightmostColumn(int8_t yCoord, int8_t offsetY) {
	return (yCoord + offsetY > 7);
}

bool Queen::willBeAtLeftmostColumn(int8_t yCoord, int8_t offsetY) {
	return (yCoord + offsetY < 0);
}

bool Queen::willBeAtTopmostRow(int8_t xCoord, int8_t offsetX) {
	return (xCoord + offsetX < 0);
}

bool Queen::willBeAtBottommostRow(int8_t xCoord, int8_t offsetX) {
	return (xCoord + offsetX > 7);
}

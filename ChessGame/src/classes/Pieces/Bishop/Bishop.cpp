#include <SFML/Graphics.hpp>

#include "Bishop.h"

Bishop::Bishop(bool isWhite) {
	this -> isWhite = isWhite;

	if (this -> isWhite) {
		this -> texture.loadFromFile("./assets/textures/white_bishop.png", this -> blankPieceBackground);
	} else {
		this -> texture.loadFromFile("./assets/textures/black_bishop.png", this -> blankPieceBackground);
	}
	this -> sprite.setTexture(texture, true);
}

Bishop::~Bishop() {
}

void Bishop::getPieceLegalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord){
	if (!this -> isPieceBishop(board, xCoord, yCoord)) {
		return;
	}

	this -> addUpRightDiagonalMoves(board, allMoves, xCoord, yCoord);
	this -> addUpLeftDiagonalMoves(board, allMoves, xCoord, yCoord);
	this -> addBottomRightDiagonalMoves(board, allMoves, xCoord, yCoord);
	this -> addBottomLeftDiagonalMoves(board, allMoves, xCoord, yCoord);
}


bool Bishop::isPieceBishop(std::vector<std::vector<Piece*>>& board, int8_t XCoord, int8_t YCoord) {
	return dynamic_cast<Bishop*>(board[XCoord][YCoord]) != nullptr;
}

void Bishop::addUpRightDiagonalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
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
			if (this -> isSquareContainingEnemyPiece(board, xCoord + offsetX, yCoord + offsetY)) {
				allMoves.push_back(Move(xCoord, yCoord, xCoord + offsetX, yCoord + offsetY));
			}
			return;
		}
	}
}

void Bishop::addUpLeftDiagonalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
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
			if (this -> isSquareContainingEnemyPiece(board, xCoord + offsetX, yCoord + offsetY)) {
				allMoves.push_back(Move(xCoord, yCoord, xCoord + offsetX, yCoord + offsetY));
			}
			return;
		}
	}
}

void Bishop::addBottomRightDiagonalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
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
			if (this -> isSquareContainingEnemyPiece(board, xCoord + offsetX, yCoord + offsetY)) {
				allMoves.push_back(Move(xCoord, yCoord, xCoord + offsetX, yCoord + offsetY));
			}
			return;
		}
	}
}

void Bishop::addBottomLeftDiagonalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
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
			if (this -> isSquareContainingEnemyPiece(board, xCoord + offsetX, yCoord + offsetY)) {
				allMoves.push_back(Move(xCoord, yCoord, xCoord + offsetX, yCoord + offsetY));
			}
			return;
		}
	}
}

bool Bishop::isSquareEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	return dynamic_cast<Piece*>(board[xCoord][yCoord]) == nullptr;
}

bool Bishop::isSquareContainingEnemyPiece(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	return board[xCoord][yCoord] -> getIsWhite() != this -> isWhite;
}

bool Bishop::willBeAtBoundry(int8_t xCoord, int8_t offsetX, int8_t yCoord, int8_t offsetY) {
	return (this -> willBeAtRightmostColumn(yCoord, offsetY) || this -> willBeAtLeftmostColumn(yCoord, offsetY) || 
			this -> willBeAtTopmostRow(xCoord, offsetX) || this -> willBeAtBottommostRow(xCoord, offsetX));
}

bool Bishop::willBeAtRightmostColumn(int8_t yCoord, int8_t offsetY) {
	return (yCoord + offsetY > 7);
}

bool Bishop::willBeAtLeftmostColumn(int8_t yCoord, int8_t offsetY) {
	return (yCoord + offsetY < 0);
}

bool Bishop::willBeAtTopmostRow(int8_t xCoord, int8_t offsetX) {
	return (xCoord + offsetX < 0);
}

bool Bishop::willBeAtBottommostRow(int8_t xCoord, int8_t offsetX) {
	return (xCoord + offsetX > 7);
}

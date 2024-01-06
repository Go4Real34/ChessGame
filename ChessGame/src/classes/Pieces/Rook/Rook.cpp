#include "Rook.h"

Rook::Rook(bool isWhite) {
	this -> isWhite = isWhite;

	if (this -> isWhite) {
		this -> texture.loadFromFile("./assets/textures/white_rook.png", this -> blankPieceBackground);
	} else {
		this -> texture.loadFromFile("./assets/textures/black_rook.png", this -> blankPieceBackground);
	}
	this -> sprite.setTexture(texture, true);
}

Rook::~Rook() {
}

void Rook::getPieceLegalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
	if (!this -> isPieceRook(board, xCoord, yCoord)) {
		return;
	}

	this -> addTopMoves(board, allMoves, xCoord, yCoord);
	this -> addBottomMoves(board, allMoves, xCoord, yCoord);
	this -> addRightMoves(board, allMoves, xCoord, yCoord);
	this -> addLeftMoves(board, allMoves, xCoord, yCoord);
}


bool Rook::isPieceRook(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	return (dynamic_cast<Rook*>(board[xCoord][yCoord])) != nullptr;
}

void Rook::addTopMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
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

void Rook::addBottomMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
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

void Rook::addRightMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
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

void Rook::addLeftMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
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

bool Rook::isSquareEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	return dynamic_cast<Piece*>(board[xCoord][yCoord]) == nullptr;
}

bool Rook::isSquareIsContainingEnemyPiece(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	return board[xCoord][yCoord] -> getIsWhite() != this -> isWhite;
}

bool Rook::willBeAtBoundry(int8_t xCoord, int8_t offsetX, int8_t yCoord, int8_t offsetY) {
	return (this -> willBeAtRightmostColumn(yCoord, offsetY) || this -> willBeAtLeftmostColumn(yCoord, offsetY) || 
			this -> willBeAtTopmostRow(xCoord, offsetX) || this -> willBeAtBottommostRow(xCoord, offsetX));
}

bool Rook::willBeAtRightmostColumn(int8_t yCoord, int8_t offsetY) {
	return (yCoord + offsetY > 7);
}

bool Rook::willBeAtLeftmostColumn(int8_t yCoord, int8_t offsetY) {
	return (yCoord + offsetY < 0);
}

bool Rook::willBeAtTopmostRow(int8_t xCoord, int8_t offsetX) {
	return (xCoord + offsetX < 0);
}

bool Rook::willBeAtBottommostRow(int8_t xCoord, int8_t offsetX) {
	return (xCoord + offsetX > 7);
}

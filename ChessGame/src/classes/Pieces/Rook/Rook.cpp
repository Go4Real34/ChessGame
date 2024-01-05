#include "Rook.h"

Rook::Rook(bool isWhite, int8_t XCoord, int8_t YCoord) {
	this -> isWhite = isWhite;
	this -> xCoord = XCoord;
	this -> yCoord = YCoord;

	sf::Texture texture;
	sf::IntRect blankPieceBackground;
	if (this -> isWhite) {
		texture.loadFromFile("./assets/textures/white_rook.png", blankPieceBackground);
	} else {
		texture.loadFromFile("./assets/textures/black_rook.png", blankPieceBackground);
	}
	this -> sprite.setTexture(texture, true);
}

Rook::~Rook() {
}

void Rook::getPieceLegalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
	if (!isPieceRook(board, xCoord, yCoord)) {
		return;
	}

	addBottomMoves(board, allMoves, xCoord, yCoord);
	addTopMoves(board, allMoves, xCoord, yCoord);
	addLeftMoves(board, allMoves, xCoord, yCoord);
	addRightMoves(board, allMoves, xCoord, yCoord);
}


bool isPieceRook(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	return (dynamic_cast<Rook*>(board[xCoord][yCoord]));
}

void Rook::addBottomMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
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

bool Rook::willBeAtBoundry(int8_t xCoord, int8_t offsetX, int8_t yCoord, int8_t offsetY) {
	return (willBeAtRightmostColumn(xCoord, offsetX) || willBeAtLeftmostColumn(xCoord, offsetX) || 
			willBeAtTopmostRow(yCoord, offsetY) || willBeAtBottommostRow(yCoord, offsetY));
}

bool Rook::willBeAtRightmostColumn(int8_t xCoord, int8_t offsetX) {
	return (xCoord + offsetX > 7);
}

bool Rook::willBeAtLeftmostColumn(int8_t xCoord, int8_t offsetX) {
	return (xCoord + offsetX < 0);
}

bool Rook::willBeAtTopmostRow(int8_t yCoord, int8_t offsetY) {
	return (yCoord + offsetY > 7);
}

bool Rook::willBeAtBottommostRow(int8_t yCoord, int8_t offsetY) {
	return (yCoord + offsetY < 0);
}

bool Rook::isSquareEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	if (this -> isWhite) {
		return (dynamic_cast<Piece*>(board[xCoord][yCoord]) == nullptr || !(board[xCoord][yCoord] -> getIsWhite()));
	} else {
		return (dynamic_cast<Piece*>(board[xCoord][yCoord]) == nullptr || board[xCoord][yCoord] -> getIsWhite());
	}
}

void Rook::addTopMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
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

void Rook::addLeftMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
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

void Rook::addRightMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
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

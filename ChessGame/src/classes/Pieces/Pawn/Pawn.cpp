#include <SFML/Graphics.hpp>

#include "Pawn.h"

Pawn::Pawn(bool IsWhite, int8_t XCoord, int8_t YCoord) {
	this -> isWhite = IsWhite;
	this -> xCoord = XCoord;
	this -> yCoord = YCoord;

	if (this -> isWhite) {
		this -> texture.loadFromFile("./assets/textures/white_pawn.png", this -> blankPieceBackground);
	} else {
		this -> texture.loadFromFile("./assets/textures/black_pawn.png", this -> blankPieceBackground);
	}
	this -> sprite.setTexture(texture, true);
};

Pawn::~Pawn() {
}

void Pawn::getPieceLegalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
	if (!isPiecePawn(board, xCoord, yCoord)) {
		return;
	}

	if (!isInVerticalBorder(yCoord)) {
		return;
	}

	if (isFrontEmpty(board, xCoord, yCoord)) {
		if (this -> isWhite) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord, yCoord - 1));
		} else {
			allMoves.push_back(Move(xCoord, yCoord, xCoord, yCoord + 1));
		}

		if (isAtStartingPosition(board, xCoord, yCoord)) {
			if (this -> isWhite) {
				allMoves.push_back(Move(xCoord, yCoord, xCoord, yCoord - 2));
			} else {
				allMoves.push_back(Move(xCoord, yCoord, xCoord, yCoord + 2));
			}
		}
	}

	if (isAtRightOfLeftBorder(yCoord)) {
		if (isEnemyPieceAtLeftDiagonal(board, xCoord, yCoord)) {
			if (this -> isWhite) {
				allMoves.push_back(Move(xCoord, yCoord, xCoord - 1, yCoord - 1));
			} else {
				allMoves.push_back(Move(xCoord, yCoord, xCoord - 1, yCoord + 1));
			}
		}
	}
	
	if (isAtLeftOfRightBorder(yCoord)) {
		if (isEnemyPieceAtRightDiagonal(board, xCoord, yCoord)) {
			if (this -> isWhite) {
				allMoves.push_back(Move(xCoord, yCoord, xCoord + 1, yCoord - 1));
			} else {
				allMoves.push_back(Move(xCoord, yCoord, xCoord + 1, yCoord + 1));
			}
		}
	}
}


bool Pawn::isPiecePawn(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	return dynamic_cast<Pawn*>(board[xCoord][yCoord]) != nullptr;
}

bool Pawn::isInVerticalBorder(int8_t yCoord) {
	if (this -> isWhite) {
		return yCoord > 0;
	} else {
		return yCoord < 7;
	}
}

bool Pawn::isFrontEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	if (this -> isWhite) {
		return dynamic_cast<Piece*>(board[xCoord][yCoord - 1]) == nullptr;
	} else {
		return dynamic_cast<Piece*>(board[xCoord][yCoord + 1]) == nullptr;
	}
}

bool Pawn::isAtStartingPosition(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	if (this -> isWhite) {
		return dynamic_cast<Piece*>(board[xCoord][yCoord - 2]) == nullptr && yCoord == 6;
	} else {
		return dynamic_cast<Piece*>(board[xCoord][yCoord + 2]) == nullptr && yCoord == 1;
	}
}

bool Pawn::isAtRightOfLeftBorder(int8_t xCoord) {
	return xCoord > 0;
}

bool Pawn::isEnemyPieceAtLeftDiagonal(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	if (this -> isWhite) {
		return (dynamic_cast<Piece*>(board[xCoord - 1][yCoord - 1]) != nullptr && !(board[xCoord - 1][yCoord - 1] -> getIsWhite()));
	} else {
		return (dynamic_cast<Piece*>(board[xCoord - 1][yCoord + 1]) != nullptr && board[xCoord - 1][yCoord + 1] -> getIsWhite());
	}
}

bool Pawn::isAtLeftOfRightBorder(int8_t xCoord) {
	return xCoord < 7;
}

bool Pawn::isEnemyPieceAtRightDiagonal(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	if (this -> isWhite) {
		return (dynamic_cast<Piece*>(board[xCoord + 1][yCoord - 1]) != nullptr && !(board[xCoord + 1][yCoord - 1] -> getIsWhite()));
	} else {
		return (dynamic_cast<Piece*>(board[xCoord + 1][yCoord + 1]) != nullptr && board[xCoord + 1][yCoord + 1] -> getIsWhite());
	}
}

#include <SFML/Graphics.hpp>

#include "Pawn.h"

Pawn::Pawn(bool IsWhite) {
	this -> isWhite = IsWhite;

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
	if (!this -> isPiecePawn(board, xCoord, yCoord)) {
		return;
	}

	if (!this -> isInVerticalBorder(xCoord)) {
		return;
	}

	if (this -> isFrontEmpty(board, xCoord, yCoord)) {
		if (this -> isWhite) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord - 1, yCoord));
		} else {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + 1, yCoord));
		}
	}

	if (this -> isTwoFrontEmpty(board, xCoord, yCoord)) {
		if (this -> isAtStartingPosition(board, xCoord, yCoord)) {
			if (this -> isWhite) {
				allMoves.push_back(Move(xCoord, yCoord, xCoord - 2, yCoord));
			} else {
				allMoves.push_back(Move(xCoord, yCoord, xCoord + 2, yCoord));
			}
		}
	}

	if (this -> isEnemyPieceAtLeftDiagonal(board, xCoord, yCoord)) {
		if (this -> isWhite) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord - 1, yCoord - 1));
		} else {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + 1, yCoord + 1));
		}
	}

	if (this -> isEnemyPieceAtRightDiagonal(board, xCoord, yCoord)) {
		if (this -> isWhite) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord - 1, yCoord + 1));
		} else {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + 1, yCoord - 1));
		}
	}
}


bool Pawn::isPiecePawn(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	return dynamic_cast<Pawn*>(board[xCoord][yCoord]) != nullptr;
}

bool Pawn::isInVerticalBorder(int8_t xCoord) {
	if (this -> isWhite) {
		return xCoord > 0;
	} else {
		return xCoord < 7;
	}
}

bool Pawn::isFrontEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	if (this -> isWhite) {
		return dynamic_cast<Piece*>(board[xCoord - 1][yCoord]) == nullptr;
	} else {
		return dynamic_cast<Piece*>(board[xCoord + 1][yCoord]) == nullptr;
	}
}

bool Pawn::isTwoFrontEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	if (this -> isWhite) {
 		return dynamic_cast<Piece*>(board[xCoord - 2][yCoord]) == nullptr;
	} else {
		return dynamic_cast<Piece*>(board[xCoord + 2][yCoord]) == nullptr;
	}
}

bool Pawn::isEnemyPieceAtRightDiagonal(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	if (this -> isWhite) {
		if (isAtLeftOfRightBorder(yCoord)) {
			return (dynamic_cast<Piece*>(board[xCoord - 1][yCoord + 1]) != nullptr && !(board[xCoord - 1][yCoord + 1] -> getIsWhite()));
		} else {
			return false;
		}
	} else {
		if (isAtRightOfLeftBorder(yCoord)) {
			return (dynamic_cast<Piece*>(board[xCoord + 1][yCoord - 1]) != nullptr && board[xCoord + 1][yCoord - 1] -> getIsWhite());
		} else {
			return false;
		}
	}
}

bool Pawn::isEnemyPieceAtLeftDiagonal(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	if (this -> isWhite) {
		if (this -> isAtRightOfLeftBorder(yCoord)) {
			return (dynamic_cast<Piece*>(board[xCoord - 1][yCoord - 1]) != nullptr && !(board[xCoord - 1][yCoord - 1] -> getIsWhite()));
		} else {
			return false;
		}
	} else {
		if (this -> isAtLeftOfRightBorder(yCoord)) {
			return (dynamic_cast<Piece*>(board[xCoord + 1][yCoord + 1]) != nullptr && board[xCoord + 1][yCoord + 1] -> getIsWhite());
		} else {
			return false;
		}
	}
}

bool Pawn::isAtStartingPosition(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	if (this -> isWhite) {
		return xCoord == 6;
	} else {
		return xCoord == 1;
	}
}

bool Pawn::isAtRightOfLeftBorder(int8_t yCoord) {
	return yCoord > 0;
}

bool Pawn::isAtLeftOfRightBorder(int8_t yCoord) {
	return yCoord < 7;
}

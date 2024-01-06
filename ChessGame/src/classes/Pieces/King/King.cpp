#include <SFML/Graphics.hpp>

#include "King.h"

King::King(bool isWhite) {
	this -> isWhite = isWhite;

	if (this -> isWhite) {
		this -> texture.loadFromFile("./assets/textures/white_king.png", this -> blankPieceBackground);
	} else {
		this -> texture.loadFromFile("./assets/textures/black_king.png", this -> blankPieceBackground);
	}
	this -> sprite.setTexture(texture, true);
}

King::~King() {
}

void King::getPieceLegalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
	if (!this -> isPieceKing(board, xCoord, yCoord)) {
		return;
	}

	if (this -> canMoveUp(xCoord)) {
		if (this -> isSquareEmpty(board, xCoord - 1, yCoord)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord - 1, yCoord));
		}
	}

	if (this -> canMoveDown(xCoord)) {
		if (this -> isSquareEmpty(board, xCoord + 1, yCoord)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + 1, yCoord));
		}
	}

	if (this -> canMoveRight(yCoord)) {
		if (this -> isSquareEmpty(board, xCoord, yCoord + 1)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord, yCoord + 1));
		}
	}

	if (this -> canMoveLeft(yCoord)) {
		if (this -> isSquareEmpty(board, xCoord, yCoord - 1)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord, yCoord - 1));
		}
	}

	if (this -> canMoveUpRightDiagonally(xCoord, yCoord)) {
		if (this -> isSquareEmpty(board, xCoord - 1, yCoord + 1)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord - 1, yCoord + 1));
		}
	}

	if (this -> canMoveUpLeftDiagonally(xCoord, yCoord)) {
		if (this -> isSquareEmpty(board, xCoord - 1, yCoord - 1)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord - 1, yCoord - 1));
		}
	}

	if (this -> canMoveDownRightDiagonally(xCoord, yCoord)) {
		if (this -> isSquareEmpty(board, xCoord + 1, yCoord + 1)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + 1, yCoord + 1));
		}
	}

	if (this -> canMoveDownLeftDiagonally(xCoord, yCoord)) {
		if (this -> isSquareEmpty(board, xCoord + 1, yCoord - 1)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + 1, yCoord - 1));
		}
	}
}

bool King::isPieceKing(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	return dynamic_cast<King*>(board[xCoord][yCoord]) != nullptr;
}

bool King::isSquareEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	return dynamic_cast<Piece*> (board[xCoord][yCoord]) == nullptr || board[xCoord][yCoord] -> getIsWhite() != this -> isWhite;
}

bool King::canMoveUpRightDiagonally(int8_t xCoord, int8_t yCoord) {
	return this -> canMoveUp(xCoord) && this -> canMoveRight(yCoord);
}

bool King::canMoveUpLeftDiagonally(int8_t xCoord, int8_t yCoord) {
	return this -> canMoveUp(xCoord) && this -> canMoveLeft(yCoord);
}

bool King::canMoveDownLeftDiagonally(int8_t xCoord, int8_t yCoord) {
	return this -> canMoveDown(xCoord) && this -> canMoveLeft(yCoord);
}

bool King::canMoveDownRightDiagonally(int8_t xCoord, int8_t yCoord) {
	return this -> canMoveDown(xCoord) && this -> canMoveRight(yCoord);
}

bool King::canMoveUp(int8_t xCoord) {
	return xCoord > 0;
}

bool King::canMoveRight(int8_t yCoord) {
	return yCoord < 7;
}

bool King::canMoveLeft(int8_t yCoord) {
	return yCoord > 0;
}

bool King::canMoveDown(int8_t xCoord) {
	return xCoord < 7;
}

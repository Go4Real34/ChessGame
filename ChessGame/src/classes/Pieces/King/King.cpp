#include <SFML/Graphics.hpp>

#include "King.h"

King::King(bool isWhite, int8_t XCoord, int8_t YCoord) {
	this -> isWhite = isWhite;
	this -> xCoord = XCoord;
	this -> yCoord = YCoord;

	sf::Texture texture;
	sf::IntRect blankPieceBackground;
	if (this -> isWhite) {
		texture.loadFromFile("./assets/textures/white_king.png", blankPieceBackground);
	} else {
		texture.loadFromFile("./assets/textures/black_king.png", blankPieceBackground);
	}
	this -> sprite.setTexture(texture, true);
}

King::~King() {
}

void King::getPieceLegalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
	if (!isPieceKing(board, xCoord, yCoord)) {
		return;
	}

	if (canMoveUp(board, xCoord)) {
		if (isSquareEmpty(board, xCoord - 1, yCoord)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord - 1, yCoord));
		}
	}

	if (canMoveUpRightDiagonally(board, xCoord, yCoord)) {
		if (isSquareEmpty(board, xCoord - 1, yCoord - 1)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord - 1, yCoord - 1));
		}
	}

	if (canMoveUpLeftDiagonally(board, xCoord, yCoord)) {
		if (isSquareEmpty(board, xCoord - 1, yCoord + 1)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord - 1, yCoord + 1));
		}
	}

	if (canMoveRight(board, yCoord)) {
		if (isSquareEmpty(board, xCoord, yCoord - 1)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord, yCoord - 1));
		}
	}

	if (canMoveLeft(board, yCoord)) {
		if (isSquareEmpty(board, xCoord, yCoord + 1)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord, yCoord + 1));
		}
	}

	if (canMoveDown(board, xCoord)) {
		if (isSquareEmpty(board, xCoord + 1, yCoord)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + 1, yCoord));
		}
	}

	if (canMoveDownLeftDiagonally(board, xCoord, yCoord)) {
		if (isSquareEmpty(board, xCoord + 1, yCoord + 1)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + 1, yCoord + 1));
		}
	}

	if (canMoveDownRightDiagonally(board, xCoord, yCoord)) {
		if (isSquareEmpty(board, xCoord + 1, yCoord - 1)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + 1, yCoord - 1));
		}
	}
}


bool King::isPieceKing(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	return dynamic_cast<King*>(board[xCoord][yCoord]) != nullptr;
}

bool King::canMoveUp(std::vector<std::vector<Piece*>>& board, int8_t xCoord) {
	return xCoord > 0;
}

bool King::isSquareEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	if (this -> isWhite) {
		return (dynamic_cast<Piece*> (board[xCoord][yCoord]) == nullptr) || !(board[xCoord][yCoord] -> getIsWhite());
	} else {
		return (dynamic_cast<Piece*> (board[xCoord][yCoord]) == nullptr) || (board[xCoord][yCoord] -> getIsWhite());
	}
}

bool King::canMoveUpRightDiagonally(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	return xCoord > 0 && yCoord > 0;
}

bool King::canMoveUpLeftDiagonally(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	return xCoord > 0 && yCoord < 7;
}

bool King::canMoveRight(std::vector<std::vector<Piece*>>& board, int8_t yCoord) {
	return yCoord > 0;
}

bool King::canMoveLeft(std::vector<std::vector<Piece*>>& board, int8_t yCoord) {
	return yCoord < 7;
}

bool King::canMoveDown(std::vector<std::vector<Piece*>>& board, int8_t xCoord) {
	return xCoord < 7;
}

bool King::canMoveDownLeftDiagonally(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	return xCoord < 7 && yCoord < 7;
}

bool King::canMoveDownRightDiagonally(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	return xCoord < 7 && yCoord > 0;
}

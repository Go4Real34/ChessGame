#include <SFML/Graphics.hpp>

#include "Knight.h"

Knight::Knight(bool isWhite) {
	this -> isWhite = isWhite;

	if (this -> isWhite) {
		this -> texture.loadFromFile("./assets/textures/white_knight.png", this -> blankPieceBackground);
	} else {
		this -> texture.loadFromFile("./assets/textures/black_knight.png", this -> blankPieceBackground);
	}
	this -> sprite.setTexture(texture, true);
}

Knight::~Knight() {
}

void Knight::getPieceLegalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) {
	if (!this -> isPieceKnight(board, xCoord, yCoord)) {
		return;
	}

	if (this -> canDoTwoUpOneRight(xCoord, yCoord)) {
		if (this -> canGoToSquare(board, xCoord - 2, yCoord + 1)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord - 2, yCoord + 1));
		}
	}

	if (this -> canDoTwoUpOneLeft(xCoord, yCoord)) {
		if (this -> canGoToSquare(board, xCoord - 2, yCoord - 1)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord - 2, yCoord - 1));
		}
	}

	if (this -> canDoTwoDownOneRight(xCoord, yCoord)) {
		if (this -> canGoToSquare(board, xCoord + 2, yCoord + 1)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + 2, yCoord + 1));
		}
	}

	if (this -> canDoTwoDownOneLeft(xCoord, yCoord)) {
		if (this -> canGoToSquare(board, xCoord + 2, yCoord - 1)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + 2, yCoord - 1));
		}
	}

	if (this -> canDoTwoLeftOneUp(xCoord, yCoord)) {
		if (this -> canGoToSquare(board, xCoord - 1, yCoord - 2)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord - 1, yCoord - 2));
		}
	}

	if (this -> canDoTwoLeftOneDown(xCoord, yCoord)) {
		if (this -> canGoToSquare(board, xCoord + 1, yCoord - 2)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + 1, yCoord - 2));
		}
	}

	if (this -> canDoTwoRightOneUp(xCoord, yCoord)) {
		if (this -> canGoToSquare(board, xCoord - 1, yCoord + 2)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord - 1, yCoord + 2));
		}
	}

	if (this -> canDoTwoRightOneDown(xCoord, yCoord)) {
		if (this -> canGoToSquare(board, xCoord + 1, yCoord + 2)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + 1, yCoord + 2));
		}
	}
}


bool Knight::isPieceKnight(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	return dynamic_cast<Knight*>(board[xCoord][yCoord]);
}

bool Knight::canGoToSquare(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	return this -> isSquareEmpty(board, xCoord, yCoord) || this -> isSquareContainingEnemyPiece(board, xCoord, yCoord);
}

bool Knight::isSquareEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	return dynamic_cast<Piece*>(board[xCoord][yCoord]) == nullptr;
}

bool Knight::isSquareContainingEnemyPiece(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	return board[xCoord][yCoord] -> getIsWhite() != this -> isWhite;
}

bool Knight::canDoTwoUpOneRight(int8_t xCoord, int8_t yCoord) {
	return (this -> isUnderTopTwoRows(xCoord) && this -> isAtLeftOfRightmostColumn(yCoord));
}

bool Knight::canDoTwoUpOneLeft(int8_t xCoord, int8_t yCoord) {
	return (this -> isUnderTopTwoRows(xCoord) && this -> isAtRightOfLeftmostColumn(yCoord));
}

bool Knight::canDoTwoDownOneRight(int8_t xCoord, int8_t yCoord) {
	return (this -> isOverBottomTwoRows(xCoord) && this -> isAtLeftOfRightmostColumn(yCoord));
}

bool Knight::canDoTwoDownOneLeft(int8_t xCoord, int8_t yCoord) {
	return (this -> isOverBottomTwoRows(xCoord) && this -> isAtRightOfLeftmostColumn(yCoord));
}

bool Knight::canDoTwoLeftOneUp(int8_t xCoord, int8_t yCoord) {
	return (this -> isUnderTopmostRow(xCoord) && this -> isAtRightOfTwoLeftmostColumns(yCoord));
}

bool Knight::canDoTwoLeftOneDown(int8_t xCoord, int8_t yCoord) {
	return (this -> isOverBottommostRow(xCoord) && this -> isAtRightOfTwoLeftmostColumns(yCoord));
}

bool Knight::canDoTwoRightOneUp(int8_t xCoord, int8_t yCoord) {
	return (this -> isUnderTopmostRow(xCoord) && this -> isAtLeftOfTwoRightmostColumns(yCoord));
}

bool Knight::canDoTwoRightOneDown(int8_t xCoord, int8_t yCoord) {
	return (this -> isOverBottommostRow(xCoord) && this -> isAtLeftOfTwoRightmostColumns(yCoord));
}

bool Knight::isUnderTopmostRow(int8_t xCoord) {
	return xCoord > 0;
}

bool Knight::isOverBottommostRow(int8_t xCoord) {
	return xCoord < 7;
}

bool Knight::isAtRightOfLeftmostColumn(int8_t yCoord) {
	return yCoord > 0;
}

bool Knight::isAtLeftOfRightmostColumn(int8_t yCoord) {
	return yCoord < 7;
}

bool Knight::isUnderTopTwoRows(int8_t xCoord) {
	return xCoord > 1;
}

bool Knight::isOverBottomTwoRows(int8_t xCoord) {
	return xCoord < 6;
}

bool Knight::isAtRightOfTwoLeftmostColumns(int8_t yCoord) {
	return yCoord > 1;
}

bool Knight::isAtLeftOfTwoRightmostColumns(int8_t yCoord) {
	return yCoord < 6;
}

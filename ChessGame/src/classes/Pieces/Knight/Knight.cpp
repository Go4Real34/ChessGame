#include <SFML/Graphics.hpp>

#include "Knight.h"

Knight::Knight(bool isWhite, int8_t XCoord, int8_t YCoord) {
	this -> isWhite = isWhite;
	this -> xCoord = XCoord;
	this -> yCoord = YCoord;

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
	if (!isPieceKnight(board, xCoord, yCoord)) {
		return;
	}

	if (canDoTwoUpOneLeft(xCoord, yCoord)) {
		if (isTwoUpOneLeftIsEmpty(board, xCoord, yCoord)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord - 1, yCoord + 2));
		}
	}

	if (canDoTwoUpOneRight(xCoord, yCoord)) {
		if (isTwoUpOneRightIsEmpty(board, xCoord, yCoord)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + 1, yCoord + 2));
		}
	}

	if (canDoTwoDownOneLeft(xCoord, yCoord)) {
		if (isTwoDownOneLeftIsEmpty(board, xCoord, yCoord)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord - 1, yCoord - 2));
		}
	}

	if (canDoTwoDownOneRight(xCoord, yCoord)) {
		if (isTwoDownOneRightIsEmpty(board, xCoord, yCoord)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + 1, yCoord - 2));
		}
	}

	if (canDoTwoLeftOneUp(xCoord, yCoord)) {
		if (isTwoLeftOneUpIsEmpty(board, xCoord, yCoord)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord - 2, yCoord + 1));
		}
	}

	if (canDoTwoLeftOneDown(xCoord, yCoord)) {
		if (isTwoLeftOneDownIsEmpty(board, xCoord, yCoord)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord - 2, yCoord - 1));
		}
	}

	if (canDoTwoRightOneUp(xCoord, yCoord)) {
		if (isTwoRightOneUpIsEmpty(board, xCoord, yCoord)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + 2, yCoord + 1));
		}
	}

	if (canDoTwoRightOneDown(xCoord, yCoord)) {
		if (isTwoRightOneDownIsEmpty(board, xCoord, yCoord)) {
			allMoves.push_back(Move(xCoord, yCoord, xCoord + 2, yCoord - 1));
		}
	}
}


bool Knight::isPieceKnight(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	return dynamic_cast<Knight*>(board[xCoord][yCoord]);
}

bool Knight::canDoTwoUpOneLeft(int8_t xCoord, int8_t yCoord) {
	return (isAtRightOfLeftmostColumn(xCoord) && isUnderTopTwoRows(yCoord));
}

bool Knight::isAtRightOfLeftmostColumn(int8_t xCoord) {
	return xCoord > 0;
}

bool Knight::isUnderTopTwoRows(int8_t yCoord) {
	return yCoord < 6;
}

bool Knight::isTwoUpOneLeftIsEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	if (this -> isWhite) {
		return (dynamic_cast<Piece*>(board[xCoord - 1][yCoord + 2]) == nullptr || !(board[xCoord - 1][yCoord + 2]) -> getIsWhite());
	} else {
		return (dynamic_cast<Piece*>(board[xCoord - 1][yCoord + 2]) == nullptr || board[xCoord - 1][yCoord + 2] -> getIsWhite());
	}
}

bool Knight::canDoTwoUpOneRight(int8_t xCoord, int8_t yCoord) {
	return (isAtLeftOfRightmostColumn(xCoord) && isUnderTopTwoRows(yCoord));
}

bool Knight::isAtLeftOfRightmostColumn(int8_t xCoord) {
	return xCoord < 7;
}

bool Knight::isTwoUpOneRightIsEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	if (this -> isWhite) {
		return (dynamic_cast<Piece*>(board[xCoord + 1][yCoord + 2]) == nullptr || !(board[xCoord + 1][yCoord + 2]) -> getIsWhite());
	} else {
		return (dynamic_cast<Piece*>(board[xCoord + 1][yCoord + 2]) == nullptr || board[xCoord + 1][yCoord + 2] -> getIsWhite());
	}
}

bool Knight::canDoTwoDownOneLeft(int8_t xCoord, int8_t yCoord) {
	return (isAtRightOfLeftmostColumn(xCoord) && isOverBottomTwoRows(yCoord));
}

bool Knight::isOverBottomTwoRows(int8_t yCoord) {
	return yCoord > 1;
}

bool Knight::isTwoDownOneLeftIsEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	if (this -> isWhite) {
		return (dynamic_cast<Piece*>(board[xCoord - 1][yCoord - 2]) == nullptr || !(board[xCoord - 1][yCoord - 2]) -> getIsWhite());
	} else {
		return (dynamic_cast<Piece*>(board[xCoord - 1][yCoord - 2]) == nullptr || board[xCoord - 1][yCoord - 2] -> getIsWhite());
	}
}

bool Knight::canDoTwoDownOneRight(int8_t xCoord, int8_t yCoord) {
	return (isAtLeftOfRightmostColumn(xCoord) && isOverBottomTwoRows(yCoord));
}

bool Knight::isTwoDownOneRightIsEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	if (this -> isWhite) {
		return (dynamic_cast<Piece*>(board[xCoord + 1][yCoord - 2]) == nullptr || !(board[xCoord + 1][yCoord - 2]) -> getIsWhite());
	} else {
		return (dynamic_cast<Piece*>(board[xCoord + 1][yCoord - 2]) == nullptr || board[xCoord + 1][yCoord - 2] -> getIsWhite());
	}
}

bool Knight::canDoTwoLeftOneUp(int8_t xCoord, int8_t yCoord) {
	return (isAtRightOfTwoLeftmostColumns(xCoord) && isUnderTopmostRow(yCoord));
}

bool Knight::isAtRightOfTwoLeftmostColumns(int8_t xCoord) {
	return xCoord > 1;
}

bool Knight::isUnderTopmostRow(int8_t yCoord) {
	return yCoord < 7;
}

bool Knight::isTwoLeftOneUpIsEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	if (this -> isWhite) {
		return (dynamic_cast<Piece*>(board[xCoord - 2][yCoord + 1]) == nullptr || !(board[xCoord - 2][yCoord + 1]) -> getIsWhite());
	} else {
		return (dynamic_cast<Piece*>(board[xCoord - 2][yCoord + 1]) == nullptr || board[xCoord - 2][yCoord + 1] -> getIsWhite());
	}
}

bool Knight::canDoTwoLeftOneDown(int8_t xCoord, int8_t yCoord) {
	return (isAtRightOfTwoLeftmostColumns(xCoord) && isOverBottommostRow(yCoord));
}

bool Knight::isOverBottommostRow(int8_t yCoord) {
	return yCoord > 0;
}

bool Knight::isTwoLeftOneDownIsEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	if (this -> isWhite) {
		return (dynamic_cast<Piece*>(board[xCoord - 2][yCoord - 1]) == nullptr || !(board[xCoord - 2][yCoord - 1]) -> getIsWhite());
	} else {
		return (dynamic_cast<Piece*>(board[xCoord - 2][yCoord - 1]) == nullptr || board[xCoord - 2][yCoord - 1] -> getIsWhite());
	}
}

bool Knight::canDoTwoRightOneUp(int8_t xCoord, int8_t yCoord) {
	return (isAtLeftOfTwoRightmostColumns(xCoord) && isUnderTopmostRow(yCoord));
}

bool Knight::isAtLeftOfTwoRightmostColumns(int8_t xCoord) {
	return xCoord < 6;
}

bool Knight::isTwoRightOneUpIsEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	if (this -> isWhite) {
		return (dynamic_cast<Piece*>(board[xCoord + 2][yCoord + 1]) == nullptr || !(board[xCoord + 2][yCoord + 1]) -> getIsWhite());
	} else {
		return (dynamic_cast<Piece*>(board[xCoord + 2][yCoord + 1]) == nullptr || board[xCoord + 2][yCoord + 1] -> getIsWhite());
	}
}

bool Knight::canDoTwoRightOneDown(int8_t xCoord, int8_t yCoord) {
	return (isAtLeftOfTwoRightmostColumns(xCoord) && isOverBottommostRow(yCoord));
}

bool Knight::isTwoRightOneDownIsEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord) {
	if (this -> isWhite) {
		return (dynamic_cast<Piece*>(board[xCoord + 2][yCoord - 1]) == nullptr || !(board[xCoord + 2][yCoord - 1]) -> getIsWhite());
	} else {
		return (dynamic_cast<Piece*>(board[xCoord + 2][yCoord - 1]) == nullptr || board[xCoord + 2][yCoord - 1] -> getIsWhite());
	}
}

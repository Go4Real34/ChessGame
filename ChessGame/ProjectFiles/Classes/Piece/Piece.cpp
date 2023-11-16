#include "Piece.h"

bool Piece::getIsWhiteColor() const {
	return this -> isWhiteColor;
}

std::vector<std::string> Piece::getPossibleMoves() const {
	return this -> possibleMoves;
}

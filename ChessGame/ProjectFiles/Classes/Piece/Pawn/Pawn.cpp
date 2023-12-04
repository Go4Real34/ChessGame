#include "Pawn.h"

Piece* Pawn::clone() const {
	return new Pawn(*this);
}

void Pawn::calculatePossibleMoves() {
	this -> possibleMoves.clear();
}

#include <iostream>
bool Pawn::isMovePossible(Board& board, std::string& move) {
	for (int i = 0; i < board.getBoardLength(); i++) {
		std::cout << move;
	}
	return true;
}
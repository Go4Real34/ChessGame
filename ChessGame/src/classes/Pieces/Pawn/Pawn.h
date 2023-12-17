#pragma once

#include "../Piece.h"

class Pawn : public Piece {
	public:
		Pawn(bool IsWhite, int8_t XCoord, int8_t YCoord);
		~Pawn();

		void getPieceLegalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord);
};

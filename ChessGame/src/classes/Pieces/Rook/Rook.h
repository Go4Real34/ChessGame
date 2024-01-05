#pragma once

#include "../Piece.h"

class Rook : public Piece {
	public:
		Rook(bool isWhite, int8_t XCoord, int8_t YCoord);
		~Rook();

		void getPieceLegalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) override;
};

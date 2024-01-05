#pragma once

#include "../Piece.h"

class Bishop : public Piece {
	public:
		Bishop(bool isWhite, int8_t XCoord, int8_t YCoord);
		~Bishop();

		void getPieceLegalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) override;
};

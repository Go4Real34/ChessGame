#pragma once

#include "../Piece.h"
#include "../../Board/Board.h"

class Pawn : public Piece {
	public:
		Pawn() = default;
		~Pawn() = default;

		virtual Piece* clone() const override;

		bool isMovePossible(Board& board, std::string& move);
		void calculatePossibleMoves() override;
	private:

};

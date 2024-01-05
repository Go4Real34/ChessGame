#pragma once

#include <iostream>
#include <vector>

#include "../../structs/Move/Move.h"
#include "../../structs/Board/Board.h"

#include "../Pieces/Pawn/Pawn.h"
#include "../Pieces/Knight/Knight.h"
#include "../Pieces/Bishop/Bishop.h"
#include "../Pieces/Rook/Rook.h"
#include "../Pieces/Queen/Queen.h"
#include "../Pieces/King/King.h"

class Game {
	public:
		Game();
		~Game();
		
		Board getCurrentBoard();
		bool playMove(Move move);
		void skipToNextTurn();

	private:
		bool isTurnWhites;
		Board currentBoard;
		std::vector<Board> boardHistory;

		std::vector<Move> calculateLegalMoves();
};

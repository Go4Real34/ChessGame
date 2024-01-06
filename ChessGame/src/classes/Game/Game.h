#pragma once

#include <iostream>
#include <vector>

#include "../../structs/Board/Board.h"
#include "../../structs/Coordination/Coordination.h"

#include "../Pieces/Piece.h"
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

		bool getCurrentTurn();

		bool getIsKingChecked();
		bool getIsCheckedKingWhite();
		Coordination getCheckedKingCoordinations();

		bool getIsGameFinished();
		bool getIsWinnerWhite();

	private:
		bool isTurnWhites;
		Board currentBoard;
		std::vector<Board> boardHistory;

		bool isKingChecked;
		bool isCheckedKingWhite;

		bool isGameFinished;
		bool isWinnerWhite;

		std::vector<Move> calculateLegalMoves(bool isWhiteCalculated);

		bool areMovesIdentical(Move move1, Move move2);

		void executeMove(Move move);

		bool checkForCheck(std::vector<Move> moves);
		bool isKingUnderAttack(Move move);

		bool isCheckmated();
};

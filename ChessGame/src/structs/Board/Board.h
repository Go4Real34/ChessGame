#pragma once

#include "../../classes/Pieces/Piece.h"

class Board {
	public:
		Piece* board[8][8];

		Board();
		~Board();
};

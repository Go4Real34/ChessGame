#pragma once

#include "../Board/Board.h"

class Game {
	public:
		Game();
		~Game();

		Board getBoard() const;

	private:
		Board board = Board();
};

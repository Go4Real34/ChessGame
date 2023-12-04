#pragma once

#include "../Tile/Tile.h"

class Board {
	private:
		static const uint8_t BOARD_LENGTH = 8;

	public:
		Board();
		~Board();

		uint8_t getBoardLength() const;
		
		struct BoardTile {
			Tile* tiles[BOARD_LENGTH][BOARD_LENGTH];
		};
		BoardTile getBoard() const;

	private:
		BoardTile board;
};

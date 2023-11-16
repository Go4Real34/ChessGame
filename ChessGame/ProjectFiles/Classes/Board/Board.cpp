#include "Board.h"

#include <iostream>

Board::Board() {
	for (int row = 0; row < BOARD_LENGTH; row++) {
		for (int column = 0; column < BOARD_LENGTH; column++) {
			board.tiles[row][column] = Tile();
		}
	}
}

Board::~Board() {
}

uint8_t Board::getBoardLength() const {
    return BOARD_LENGTH;
}

Board::BoardTile Board::getBoard() const {
	return this -> board;
}

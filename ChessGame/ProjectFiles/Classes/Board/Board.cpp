#include "Board.h"

#include "../Piece/Pawn/Pawn.h"
#include <iostream>

Board::Board() {
	for (int row = 0; row < BOARD_LENGTH; row++) {
		for (int column = 0; column < BOARD_LENGTH; column++) {
			Piece* pawn = new Pawn();
			bool thing = false;
			Tile* tile = new Tile(thing, pawn);
			board.tiles[row][column] = tile;
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

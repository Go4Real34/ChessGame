#include "Board.h"

Board::Board() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; ++j) {
			this -> board[i][j] = nullptr;
		}
	}
}

Board::~Board() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; ++j) {
			delete this -> board[i][j];
		}
	}
}

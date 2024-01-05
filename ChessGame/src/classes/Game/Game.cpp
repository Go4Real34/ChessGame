#include "Game.h"

Game::Game() {
	this -> isTurnWhites = true;
	
	for (int row = 0; row < 8; row++) {
		for (int column = 0; column < 8; column++) {
			this -> currentBoard.board[row][column] = nullptr;
		}
	}
	currentBoard.board[0][0] = new Rook(false, 0, 0);
	currentBoard.board[0][1] = new Knight(false, 0, 1);
	currentBoard.board[0][2] = new Bishop(false, 0, 2);
	currentBoard.board[0][3] = new King(false, 0, 3);
	currentBoard.board[0][4] = new Queen(false, 0, 4);
	currentBoard.board[0][5] = new Bishop(false, 0, 5);
	currentBoard.board[0][6] = new Knight(false, 0, 6);
	currentBoard.board[0][7] = new Rook(false, 0, 7);
	for (int i = 0; i < 8; ++i) {
		currentBoard.board[1][i] = new Pawn(false, 1, i);
	}
	currentBoard.board[7][0] = new Rook(true, 7, 0);
	currentBoard.board[7][1] = new Knight(true, 7, 1);
	currentBoard.board[7][2] = new Bishop(true, 7, 2);
	currentBoard.board[7][3] = new King(true, 7, 3);
	currentBoard.board[7][4] = new Queen(true, 7, 4);
	currentBoard.board[7][5] = new Bishop(true, 7, 5);
	currentBoard.board[7][6] = new Knight(true, 7, 6);
	currentBoard.board[7][7] = new Rook(true, 7, 7);
	for (int i = 0; i < 8; ++i) {
		currentBoard.board[6][i] = new Pawn(true, 6, i);
	}
}

Game::~Game() {
	for (int row = 0; row < 8; row++) {
		for (int column = 0; column < 8; column++) {
			delete this -> currentBoard.board[row][column];
		}
	}
}

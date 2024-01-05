#include "Game.h"

Game::Game() {
	this -> isTurnWhites = true;
	
	this -> currentBoard = Board();
	currentBoard.board[0][0] = new Rook(false, 0, 0);
	currentBoard.board[0][1] = new Knight(false, 0, 1);
	currentBoard.board[0][2] = new Bishop(false, 0, 2);
	currentBoard.board[0][3] = new King(false, 0, 3);
	currentBoard.board[0][4] = new Queen(false, 0, 4);
	currentBoard.board[0][5] = new Bishop(false, 0, 5);
	currentBoard.board[0][6] = new Knight(false, 0, 6);
	currentBoard.board[0][7] = new Rook(false, 0, 7);
	for (int column = 0; column < 8; column++) {
		currentBoard.board[1][column] = new Pawn(false, 1, column);
	}
	for (int column = 0; column < 8; column++) {
		currentBoard.board[6][column] = new Pawn(true, 6, column);
	}
	currentBoard.board[7][0] = new Rook(true, 7, 0);
	currentBoard.board[7][1] = new Knight(true, 7, 1);
	currentBoard.board[7][2] = new Bishop(true, 7, 2);
	currentBoard.board[7][3] = new King(true, 7, 3);
	currentBoard.board[7][4] = new Queen(true, 7, 4);
	currentBoard.board[7][5] = new Bishop(true, 7, 5);
	currentBoard.board[7][6] = new Knight(true, 7, 6);
	currentBoard.board[7][7] = new Rook(true, 7, 7);

	this -> boardHistory = std::vector<Board>();
}

Game::~Game() {
	this -> currentBoard.~Board();
}

Board Game::getCurrentBoard() {
	return this -> currentBoard;
}

bool Game::playMove(Move move) {
	std::vector<Move> allMoves = this -> calculateLegalMoves();

	for (int i = 0; i < allMoves.size(); i++) {
		Move temp = allMoves[i];
		if (areMovesIdentical(temp, move)) {
			executeMove(move);
			std::vector<Move> tempLegalMoves = this -> calculateLegalMoves();
			if (checkForCheck(tempLegalMoves)) {
				this -> currentBoard = this -> boardHistory[this -> boardHistory.size() - 1];
				return false;
			} else {
				this -> boardHistory.push_back(this -> currentBoard);
				return true;
			}
		}
	}
	return false;
}

void Game::skipToNextTurn() {
	this -> isTurnWhites = !this -> isTurnWhites;
}


std::vector<Move> Game::calculateLegalMoves() {
	std::vector<Move> allMoves;

	std::vector<std::vector<Piece*>> tempBoardStatus;
	for (int row = 0; row < 8; row++) {
		std::vector<Piece*> tempRow;
		for (int column = 0; column < 8; column++) {
			tempRow.push_back(this -> currentBoard.board[row][column]);
		}
		tempBoardStatus.push_back(tempRow);
	}

	for (int row = 0; row < 8; row++) {
		for (int column = 0; column < 8; column++) {
			if (this -> currentBoard.board[row][column] != nullptr) {
				this -> currentBoard.board[row][column] -> getPieceLegalMoves(tempBoardStatus, allMoves, row, column);
			}
		}
	}

	return allMoves;
}

bool Game::areMovesIdentical(Move move1, Move move2) {
	return (move1.xCoordOld == move2.xCoordOld && move1.yCoordOld == move2.yCoordOld && 
			move1.xCoordNew == move2.xCoordNew && move1.yCoordNew == move2.yCoordNew);
}

void Game::executeMove(Move move) {
	this -> currentBoard.board[move.xCoordNew][move.yCoordNew] = this -> currentBoard.board[move.xCoordOld][move.yCoordOld];
	this -> currentBoard.board[move.xCoordOld][move.yCoordOld] = nullptr;
}

bool Game::checkForCheck(std::vector<Move> moves) {
	for (int i = 0; i < moves.size(); i++) {
		Move temp = moves[i];
		if (isKingUnderAttack(temp)) {
			return true;
		}
	}
	return false;
}

bool Game::isKingUnderAttack(Move move) {
	return dynamic_cast<King*>(this -> currentBoard.board[move.xCoordNew][move.yCoordNew]) != nullptr;	
}

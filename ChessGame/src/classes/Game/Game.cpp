#include "Game.h"

Game::Game() {
	this -> isTurnWhites = true;
	
	this -> currentBoard = Board();
	currentBoard.board[0][0] = new Rook(false);
	currentBoard.board[0][1] = new Knight(false);
	currentBoard.board[0][2] = new Bishop(false);
	currentBoard.board[0][3] = new Queen(false);
	currentBoard.board[0][4] = new King(false);
	currentBoard.board[0][5] = new Bishop(false);
	currentBoard.board[0][6] = new Knight(false);
	currentBoard.board[0][7] = new Rook(false);
	for (int column = 0; column < 8; column++) {
		currentBoard.board[1][column] = new Pawn(false);	
	}
	for (int column = 0; column < 8; column++) {
		currentBoard.board[6][column] = new Pawn(true);	
	}
	currentBoard.board[7][0] = new Rook(true);
	currentBoard.board[7][1] = new Knight(true);
	currentBoard.board[7][2] = new Bishop(true);
	currentBoard.board[7][3] = new Queen(true);
	currentBoard.board[7][4] = new King(true);
	currentBoard.board[7][5] = new Bishop(true);
	currentBoard.board[7][6] = new Knight(true);
	currentBoard.board[7][7] = new Rook(true);

	this -> boardHistory = std::vector<Board>();

	this -> isKingChecked = false;

	this -> isCheckedKingWhite = false;
}

Game::~Game() {
}

Board Game::getCurrentBoard() {
	return this -> currentBoard;
}

bool Game::playMove(Move move) {
	std::vector<Move> allMoves = this -> calculateLegalMoves(this -> isTurnWhites);

	for (int i = 0; i < allMoves.size(); i++) {
		Move temp = allMoves[i];
		if (areMovesIdentical(temp, move)) {
			executeMove(move);
			std::vector<Move> tempLegalMovesForInvalidMoveOnCheck = this -> calculateLegalMoves(!this -> isTurnWhites);
			if (checkForCheck(tempLegalMovesForInvalidMoveOnCheck)) {
				this -> currentBoard = this -> boardHistory[this -> boardHistory.size() - 1];
				return false;
			} else {
				this -> boardHistory.push_back(this -> currentBoard);
				std::vector<Move> tempLegalMovesForCheckExists = this -> calculateLegalMoves(this -> isTurnWhites);
				if (checkForCheck(tempLegalMovesForCheckExists)) {
					this -> isKingChecked = true;
					this -> isCheckedKingWhite = !this -> isTurnWhites;
				} else {
					this -> isKingChecked = false;
				}
				return true;
			}
		}
	}
	return false;
}

void Game::skipToNextTurn() {
	this -> isTurnWhites = !this -> isTurnWhites;
}

bool Game::getCurrentTurn() {
	return this -> isTurnWhites;
}

bool Game::getIsKingChecked() {
	return this -> isKingChecked;
}

bool Game::getIsCheckedKingWhite() {
	return this -> isCheckedKingWhite;
}

Coordination Game::getCheckedKingCoordinations() {
	for (int row = 0; row < 8; row++) {
		for (int column = 0; column < 8; column++) {
			Piece* piece = this -> currentBoard.board[row][column];
			if (dynamic_cast<King*>(piece) != nullptr && piece -> getIsWhite() == this -> isCheckedKingWhite) {
				return Coordination(row, column);
			}
		}
	}
}


std::vector<Move> Game::calculateLegalMoves(bool isWhiteCalculated) {
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
			Piece* piece = this -> currentBoard.board[row][column];
			if (piece != nullptr && piece -> getIsWhite() == isWhiteCalculated) {
				piece -> getPieceLegalMoves(tempBoardStatus, allMoves, row, column);
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

#pragma once

#include "../Piece.h"

class Pawn : public Piece {
	public:
		Pawn(bool IsWhite, int8_t XCoord, int8_t YCoord);
		~Pawn();

		void getPieceLegalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) override;

	private:
		bool isPiecePawn(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);
		
		bool isInVerticalBorder(int8_t yCoord);
		
		bool isFrontEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);
		bool isAtStartingPosition(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);
		
		bool isAtRightOfLeftBorder(int8_t xCoord);
		bool isEnemyPieceAtLeftDiagonal(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);
		
		bool isAtLeftOfRightBorder(int8_t xCoord);
		bool isEnemyPieceAtRightDiagonal(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);
};

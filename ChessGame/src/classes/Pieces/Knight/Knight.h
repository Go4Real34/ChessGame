#pragma once

#include "../Piece.h"

class Knight : public Piece {
	public:
		Knight(bool isWhite);
		~Knight();

		void getPieceLegalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) override;

	private:
		bool isPieceKnight(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);
		
		bool canGoToSquare(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);
		
		bool isSquareEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);
		bool isSquareContainingEnemyPiece(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);
		
		bool canDoTwoUpOneRight(int8_t xCoord, int8_t yCoord);
		bool canDoTwoUpOneLeft(int8_t xCoord, int8_t yCoord);
		bool canDoTwoDownOneRight(int8_t xCoord, int8_t yCoord);
		bool canDoTwoDownOneLeft(int8_t xCoord, int8_t yCoord);
		bool canDoTwoLeftOneUp(int8_t xCoord, int8_t yCoord);
		bool canDoTwoLeftOneDown(int8_t xCoord, int8_t yCoord);
		bool canDoTwoRightOneUp(int8_t xCoord, int8_t yCoord);
		bool canDoTwoRightOneDown(int8_t xCoord, int8_t yCoord);

		bool isUnderTopmostRow(int8_t xCoord);
		bool isOverBottommostRow(int8_t xCoord);
		bool isAtRightOfLeftmostColumn(int8_t yCoord);
		bool isAtLeftOfRightmostColumn(int8_t yCoord);
		bool isUnderTopTwoRows(int8_t xCoord);
		bool isOverBottomTwoRows(int8_t xCoord);
		bool isAtRightOfTwoLeftmostColumns(int8_t yCoord);
		bool isAtLeftOfTwoRightmostColumns(int8_t yCoord);
};

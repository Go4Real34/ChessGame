#pragma once

#include "../Piece.h"

class Bishop : public Piece {
	public:
		Bishop(bool isWhite, int8_t XCoord, int8_t YCoord);
		~Bishop();

		void getPieceLegalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) override;

	private:
		bool isPieceBishop(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);

		void addBottomLeftDiagonalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord);
		bool willBeAtBoundry(int8_t xCoord, int8_t offsetX, int8_t yCoord, int8_t offsetY);
		bool willBeAtRightmostColumn(int8_t xCoord, int8_t offsetX);
		bool willBeAtLeftmostColumn(int8_t xCoord, int8_t offsetX);
		bool willBeAtTopmostRow(int8_t yCoord, int8_t offsetY);
		bool willBeAtBottommostRow(int8_t yCoord, int8_t offsetY);
		bool isSquareEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);

		void addUpRightDiagonalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord);
		
		void addUpLeftDiagonalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord);
		
		void addBottomRightDiagonalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord);
};

#pragma once

#include "../Piece.h"

class Rook : public Piece {
	public:
		Rook(bool isWhite, int8_t XCoord, int8_t YCoord);
		~Rook();

		void getPieceLegalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) override;

	private:
		bool isPieceRook(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);

		void addBottomMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord);
		bool willBeAtBoundry(int8_t xCoord, int8_t offsetX, int8_t yCoord, int8_t offsetY);
		bool willBeAtRightmostColumn(int8_t xCoord, int8_t offsetX);
		bool willBeAtLeftmostColumn(int8_t xCoord, int8_t offsetX);
		bool willBeAtTopmostRow(int8_t yCoord, int8_t offsetY);
		bool willBeAtBottommostRow(int8_t yCoord, int8_t offsetY);
		bool isSquareEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);

		void addTopMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord);
	
		void addLeftMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord);
	
		void addRightMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord);
};

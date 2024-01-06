#pragma once

#include "../Piece.h"

class King : public Piece {
	public:
		King(bool isWhite);
		~King();

		void getPieceLegalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) override;

	private:
		bool isPieceKing(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);

		bool isSquareEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);

		bool canMoveUpRightDiagonally(int8_t xCoord, int8_t yCoord);
		bool canMoveUpLeftDiagonally(int8_t xCoord, int8_t yCoord);
		bool canMoveDownRightDiagonally(int8_t xCoord, int8_t yCoord);
		bool canMoveDownLeftDiagonally(int8_t xCoord, int8_t yCoord);
		bool canMoveUp(int8_t xCoord);
		bool canMoveDown(int8_t xCoord);
		bool canMoveRight(int8_t yCoord);
		bool canMoveLeft(int8_t yCoord);
};

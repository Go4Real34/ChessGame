#pragma once

#include "../Piece.h"

class King : public Piece {
	public:
		King(bool isWhite, int8_t XCoord, int8_t YCoord);
		~King();

		void getPieceLegalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) override;

	private:
		bool isPieceKing(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);

		bool canMoveUp(std::vector<std::vector<Piece*>>& board, int8_t xCoord);
		bool isSquareEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);

		bool canMoveUpRightDiagonally(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);

		bool canMoveUpLeftDiagonally(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);

		bool canMoveRight(std::vector<std::vector<Piece*>>& board, int8_t yCoord);

		bool canMoveLeft(std::vector<std::vector<Piece*>>& board, int8_t yCoord);

		bool canMoveDown(std::vector<std::vector<Piece*>>& board, int8_t xCoord);

		bool canMoveDownLeftDiagonally(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);

		bool canMoveDownRightDiagonally(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);
};

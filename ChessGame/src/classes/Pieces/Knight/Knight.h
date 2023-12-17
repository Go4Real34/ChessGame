#pragma once

#include "../Piece.h"

class Knight : public Piece {
	public:
		Knight(bool isWhite, int8_t XCoord, int8_t YCoord);
		~Knight();

		void getPieceLegalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) override;

	private:
		bool isPieceKnight(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);

		bool canDoTwoUpOneLeft(int8_t xCoord, int8_t yCoord);
		bool isAtRightOfLeftmostColumn(int8_t xCoord);
		bool isUnderTopTwoRows(int8_t yCoord);
		bool isTwoUpOneLeftIsEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);

		bool canDoTwoUpOneRight(int8_t xCoord, int8_t yCoord);
		bool isAtLeftOfRightmostColumn(int8_t xCoord);
		bool isTwoUpOneRightIsEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);

		bool canDoTwoDownOneLeft(int8_t xCoord, int8_t yCoord);
		bool isOverBottomTwoRows(int8_t yCoord);
		bool isTwoDownOneLeftIsEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);

		bool canDoTwoDownOneRight(int8_t xCoord, int8_t yCoord);
		bool isTwoDownOneRightIsEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);

		bool canDoTwoLeftOneUp(int8_t xCoord, int8_t yCoord);
		bool isAtRightOfTwoLeftmostColumns(int8_t xCoord);
		bool isUnderTopmostRow(int8_t yCoord);
		bool isTwoLeftOneUpIsEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);

		bool canDoTwoLeftOneDown(int8_t xCoord, int8_t yCoord);
		bool isOverBottommostRow(int8_t yCoord);
		bool isTwoLeftOneDownIsEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);

		bool canDoTwoRightOneUp(int8_t xCoord, int8_t yCoord);
		bool isAtLeftOfTwoRightmostColumns(int8_t xCoord);
		bool isTwoRightOneUpIsEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);

		bool canDoTwoRightOneDown(int8_t xCoord, int8_t yCoord);
		bool isTwoRightOneDownIsEmpty(std::vector<std::vector<Piece*>>& board, int8_t xCoord, int8_t yCoord);
};

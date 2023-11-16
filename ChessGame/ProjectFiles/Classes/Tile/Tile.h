#pragma once

#include "../Piece/Piece.h"

class Tile {
	public:
		Tile(bool& IsBackgroundWhite, Piece& Piece);
		~Tile();

		bool getIsBackgroundWhite() const;
		Piece* getHeldPiece() const;

	private:
		bool isBackgroundWhite = false;
		Piece* heldPiece = nullptr;
};

#pragma once

#include "../Piece/Piece.h"

class Tile {
	public:
		Tile();
		Tile(bool& IsBackgroundWhite, Piece& HeldPiece);
		~Tile();

		bool getIsBackgroundWhite() const;
		Piece* getHeldPiece() const;

	private:
		bool isBackgroundWhite = false;
		Piece* heldPiece = nullptr;
};

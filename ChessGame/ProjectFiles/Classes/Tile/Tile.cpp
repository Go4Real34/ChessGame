#include "Tile.h"

Tile::Tile(bool& IsBackgroundWhite, Piece& HeldPiece) {
	this -> isBackgroundWhite = IsBackgroundWhite;
	this -> heldPiece = &HeldPiece;
}

Tile::~Tile() {
	delete this -> heldPiece;
}

bool Tile::getIsBackgroundWhite() const {
	return this -> isBackgroundWhite;
}

Piece* Tile::getHeldPiece() const {
	return this -> heldPiece;
}

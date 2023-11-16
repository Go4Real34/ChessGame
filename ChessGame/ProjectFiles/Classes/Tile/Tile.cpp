#include "Tile.h"

Tile::Tile() {
	this -> isBackgroundWhite = false;
	this -> heldPiece = nullptr;
}

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

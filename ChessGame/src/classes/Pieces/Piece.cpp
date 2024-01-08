#include "Piece.h"

sf::Texture	Piece::getTexture() {
	return this -> texture;
}

sf::IntRect Piece::getBlankPieceBackground() {
	return this -> blankPieceBackground;
}

sf::Sprite Piece::getSprite() {
	return this -> sprite;
}

bool Piece::getIsWhite() {
	return this -> isWhite;
}

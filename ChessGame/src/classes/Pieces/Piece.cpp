#include "Piece.h"

sf::Sprite Piece::getSprite() {
	return sprite;
}

bool Piece::getIsWhite() {
	return isWhite;
}

int8_t Piece::getXCoord() {
	return xCoord;
}

int8_t Piece::getYCoord() {
	return yCoord;
}

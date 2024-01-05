#include "Piece.h"

sf::Texture	Piece::getTexture() {
	return texture;
}

sf::IntRect Piece::getBlankPieceBackground() {
	return blankPieceBackground;
}

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

void Piece::setXCoord(int8_t xCoord) {
	this -> xCoord = xCoord;
}

void Piece::setYCoord(int8_t yCoord) {
	this -> yCoord = yCoord;
}

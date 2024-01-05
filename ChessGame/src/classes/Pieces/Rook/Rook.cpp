#include "Rook.h"

Rook::Rook(bool isWhite, int8_t XCoord, int8_t YCoord) {
	this -> isWhite = isWhite;
	this -> xCoord = XCoord;
	this -> yCoord = YCoord;

	sf::Texture texture;
	sf::IntRect blankPieceBackground;
	if (this -> isWhite) {
		texture.loadFromFile("./assets/textures/white_rook.png", blankPieceBackground);
	} else {
		texture.loadFromFile("./assets/textures/black_rook.png", blankPieceBackground);
	}
	this -> sprite.setTexture(texture, true);
}

Rook::~Rook() {
}

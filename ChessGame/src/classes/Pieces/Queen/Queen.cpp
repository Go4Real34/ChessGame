#include <SFML/Graphics.hpp>

#include "Queen.h"

Queen::Queen(bool isWhite, int8_t XCoord, int8_t YCoord) : Piece(isWhite, XCoord, YCoord) {
	this -> isWhite = isWhite;
	this -> xCoord = XCoord;
	this -> yCoord = YCoord;

	sf::Texture texture;
	sf::IntRect blankPieceBackground;
	if (this -> isWhite) {
		texture.loadFromFile("./assets/textures/white_queen.png", blankPieceBackground);
	} else {
		texture.loadFromFile("./assets/textures/black_queen.png", blankPieceBackground);
	}
	this -> sprite.setTexture(texture, true);
}

Queen::~Queen() {
}

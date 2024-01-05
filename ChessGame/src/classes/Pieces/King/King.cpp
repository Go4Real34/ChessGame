#include <SFML/Graphics.hpp>

#include "King.h"

King::King(bool isWhite, int8_t XCoord, int8_t YCoord) {
	this -> isWhite = isWhite;
	this -> xCoord = XCoord;
	this -> yCoord = YCoord;

	sf::Texture texture;
	sf::IntRect blankPieceBackground;
	if (this -> isWhite) {
		texture.loadFromFile("./assets/textures/white_king.png", blankPieceBackground);
	} else {
		texture.loadFromFile("./assets/textures/black_king.png", blankPieceBackground);
	}
	this -> sprite.setTexture(texture, true);
}

King::~King() {
}

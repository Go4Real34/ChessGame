#include <SFML/Graphics.hpp>

#include "Knight.h"

Knight::Knight(bool isWhite, int8_t XCoord, int8_t YCoord) {
	this -> isWhite = isWhite;
	this -> xCoord = XCoord;
	this -> yCoord = YCoord;

	sf::Texture texture;
	sf::IntRect blankPieceBackground;
	if (this -> isWhite) {
		texture.loadFromFile("./assets/textures/white_knight.png", blankPieceBackground);
	} else {
		texture.loadFromFile("./assets/textures/black_knight.png", blankPieceBackground);
	}
	this -> sprite.setTexture(texture, true);
}

Knight::~Knight() {
}

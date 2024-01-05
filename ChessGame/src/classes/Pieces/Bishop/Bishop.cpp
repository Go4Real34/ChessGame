#include <SFML/Graphics.hpp>

#include "Bishop.h"

Bishop::Bishop(bool isWhite, int8_t XCoord, int8_t YCoord) {
	this -> isWhite = isWhite;
	this -> xCoord = XCoord;
	this -> yCoord = YCoord;

	sf::Texture texture;
	sf::IntRect blankPieceBackground;
	if (this -> isWhite) {
		texture.loadFromFile("./assets/textures/white_bishop.png", blankPieceBackground);
	} else {
		texture.loadFromFile("./assets/textures/black_bishop.png", blankPieceBackground);
	}
	this -> sprite.setTexture(texture, true);
}

Bishop::~Bishop() {
}

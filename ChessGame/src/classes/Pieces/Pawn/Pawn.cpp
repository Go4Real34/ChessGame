#include <SFML/Graphics.hpp>

#include "Pawn.h"

Pawn::Pawn(bool IsWhite, int8_t XCoord, int8_t YCoord) {
	this -> isWhite = IsWhite;
	this -> xCoord = XCoord;
	this -> yCoord = YCoord;

	sf::Texture texture;
	sf::IntRect blankPieceBackground;
	if (this -> isWhite) {
		texture.loadFromFile("./assets/textures/white_pawn.png", blankPieceBackground);
	} else {
		texture.loadFromFile("./assets/textures/black_pawn.png", blankPieceBackground);
	}
	this -> sprite.setTexture(texture, true);
};

Pawn::~Pawn() {
}

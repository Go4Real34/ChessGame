#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "../../structs/Move/Move.h"

class Piece {
	public:
		Piece() = default;
		~Piece() = default;

		sf::Texture getTexture();
		sf::IntRect getBlankPieceBackground();
		sf::Sprite getSprite();
		bool getIsWhite();

		void setXCoord(int8_t xCoord);
		void setYCoord(int8_t yCoord);
		
		virtual void getPieceLegalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) = 0;
	
	protected:
		sf::Texture texture;
		sf::IntRect blankPieceBackground;
		sf::Sprite sprite;
		bool isWhite;
		int8_t xCoord;
		int8_t yCoord;
};

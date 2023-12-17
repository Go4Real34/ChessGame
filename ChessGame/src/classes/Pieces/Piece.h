#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "../../structs/Move/Move.h"

class Piece {
	public:
		Piece() = default;
		~Piece() = default;

		sf::Sprite getSprite();
		bool getIsWhite();
		int8_t getXCoord();
		int8_t getYCoord();
		
		virtual void getPieceLegalMoves(std::vector<std::vector<Piece*>>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) = 0;
	
	protected:
		sf::Sprite sprite;
		bool isWhite;
		int8_t xCoord;
		int8_t yCoord;
};

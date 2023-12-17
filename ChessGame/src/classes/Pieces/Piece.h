#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

class Piece {
	public:
		Piece() = default;
		~Piece() = default;
		
		struct Move {
			int8_t xCoordOld;
			int8_t xCoordNew;
			int8_t yCoordOld;
			int8_t yCoordNew;
		};

		sf::Sprite getSprite();
		bool getIsWhite();
		int8_t getXCoord();
		int8_t getYCoord();
		
		virtual void getPieceLegalMoves(std::vector<Move>& board, std::vector<Move>& allMoves, int8_t xCoord, int8_t yCoord) = 0;
	
	protected:
		sf::Sprite sprite;
		bool isWhite;
		int8_t xCoord;
		int8_t yCoord;
};

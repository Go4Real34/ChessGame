#pragma once

#include <string>
#include <vector>

class Piece {
	public:
		Piece() = default;
		virtual ~Piece() = default;

		bool getIsWhiteColor() const;
		std::vector<std::string> getPossibleMoves() const;
		
		virtual bool isMovePossible(std::string& move) = 0;
		virtual void calculatePossibleMoves() = 0;

	protected:
		bool isWhiteColor = false;
		std::vector<std::string> possibleMoves = {};
};

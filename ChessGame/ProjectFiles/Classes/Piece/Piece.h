#pragma once

#include <string>
#include <vector>

class Piece {
	public:
		Piece() = default;
		virtual ~Piece() = default;
		virtual Piece* clone() const = 0;

		bool getIsWhiteColor() const;
		std::vector<std::string> getPossibleMoves() const;
		
		virtual void calculatePossibleMoves() = 0;

	protected:
		bool isWhiteColor = false;
		std::vector<std::string> possibleMoves = {};
};

#pragma once

#include <iostream>

class Move {
	public:
		int8_t xCoordOld;
		int8_t yCoordOld;
		int8_t xCoordNew;
		int8_t yCoordNew;
		
		Move(int8_t xCoordOld, int8_t yCoordOld, int8_t xCoordNew, int8_t yCoordNew);
		~Move();
};

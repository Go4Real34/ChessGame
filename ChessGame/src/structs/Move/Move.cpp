#include "Move.h"

Move::Move(int8_t xCoordOld, int8_t yCoordOld, int8_t xCoordNew, int8_t yCoordNew) {
	this -> xCoordOld = xCoordOld;
	this -> yCoordOld = yCoordOld;
	this -> xCoordNew = xCoordNew;
	this -> yCoordNew = yCoordNew;
}

Move::~Move() {
}

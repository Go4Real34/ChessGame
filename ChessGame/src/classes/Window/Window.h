#pragma once

#include <map>

#include "../Game/Game.h"

class Window {
	public:
		Window(std::string windowName);
		~Window();

		void run();

	private:
		const int8_t BOARD_SIZE = 8;
		const int8_t DEFAULT_SQUARE_SIZE = 60;

		const int16_t DEFAULT_WINDOW_WIDTH = this -> BOARD_SIZE * this -> DEFAULT_SQUARE_SIZE;
		const int16_t DEFAULT_WINDOW_HEIGHT = this -> BOARD_SIZE * this -> DEFAULT_SQUARE_SIZE;
		
		float SQUARE_SIZE;

		sf::RenderWindow window;
		std::map<std::string, sf::Color> colors;
		
		Game game;

		bool isAPieceSelected;
		int8_t selectedSquareRow;
		int8_t selectedSquareColumn;

		bool isAMoveInProgress;
		int8_t targetedSquareRow;
		int8_t targetedSquareColumn;

		bool doRecieveMoveInput;

		void drawSquares();
		void drawPieces();

		void selectSquare(int8_t clickedRow, int8_t clickedColumn);
		void resetSelectedSquares();

		void selectTargetedSquare(int8_t clickedRow, int8_t clickedColumn);
		void resetTargetedSquare();
};

#pragma once

#include <map>

#include "../Game/Game.h"

class Window {
	public:
		Window(int width, int height, std::string windowName);
		~Window();

		void run();

	private:
		const int8_t BOARD_SIZE = 8;
		const int SQUARE_SIZE = 60;

		sf::RenderWindow window;
		std::map<std::string, sf::Color> colors;
		
		Game game;

		bool isAPieceSelected;
		int8_t selectedSquareRow;
		int8_t selectedSquareColumn;

		void drawSquares();
		void drawPieces();

		void selectPiece(int8_t clickedRow, int8_t clickedColumn);
		void resetSelectedPiece();
};

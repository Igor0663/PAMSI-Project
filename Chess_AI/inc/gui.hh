#ifndef GUI_HH
#define GUI_HH
#include <SFML/Graphics.hpp>
#include "chessboard.hh"

class GUI
{
	public:
		sf::Texture chessboard_tex;
		sf::Texture pieces_tex[2][6];
		sf::Vector2f board_offset;
		sf::Vector2f field_size;
		sf::RenderWindow& AppWin;
		GUI(sf::RenderWindow& win);
		void run();
		void draw_marker(int y, int x, sf::Color color, bool update = false);
		void display( const chessboard& board, const std::vector<piece>& pieces, const std::vector<std::pair<int, int> >& pos);
};


#endif

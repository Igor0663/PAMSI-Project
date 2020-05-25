#ifndef GUI_HH
#define GUI_HH
#include <SFML/Graphics.hpp>
#include "chessboard.hh"

class GUI
{
	public:
		sf::RenderWindow& AppWin;
		GUI(sf::RenderWindow& win);
		sf::Texture chessboard_tex;
		sf::Texture pieces_tex[2][6];
		sf::Vector2f board_offset;
		sf::Vector2f field_size;
		void run();
		void draw_scene();
		void display( const chessboard& board, const std::vector<piece>& pieces, const std::vector<std::pair<int, int> >& pos);
};


#endif

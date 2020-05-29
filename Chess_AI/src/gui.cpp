#include"gui.hh"

GUI::GUI(sf::RenderWindow& win): AppWin(win)
{
	this->AppWin.create(sf::VideoMode(512, 512,32), "Szachulce" );
	this->board_offset = sf::Vector2f(28,28);
	this->field_size = sf::Vector2f(57, 57); 
	this->chessboard_tex.loadFromFile("./graphics/chessboard.png");
	
	this->pieces_tex[0][0].loadFromFile("./graphics/pawn_white.png");
	this->pieces_tex[0][1].loadFromFile("./graphics/rook_white.png");
	this->pieces_tex[0][2].loadFromFile("./graphics/knight_white.png");
	this->pieces_tex[0][3].loadFromFile("./graphics/bishop_white.png");
	this->pieces_tex[0][4].loadFromFile("./graphics/queen_white.png");
	this->pieces_tex[0][5].loadFromFile("./graphics/king_white.png");

	this->pieces_tex[1][0].loadFromFile("./graphics/pawn_black.png");
	this->pieces_tex[1][1].loadFromFile("./graphics/rook_black.png");
	this->pieces_tex[1][2].loadFromFile("./graphics/knight_black.png");
	this->pieces_tex[1][3].loadFromFile("./graphics/bishop_black.png");
	this->pieces_tex[1][4].loadFromFile("./graphics/queen_black.png");
	this->pieces_tex[1][5].loadFromFile("./graphics/king_black.png");
}

void GUI::display(const chessboard& board, const std::vector<piece>& pieces, const std::vector<std::pair<int, int> >& pos)
{
	this->AppWin.clear();
	sf::Sprite sprite;
	sf::Vector2f cor(-2, -2);
	sprite.setTexture(this->chessboard_tex);
	this->AppWin.draw(sprite);
	
	for(unsigned int k = 0; k < pieces.size(); k++)
	{
		if(pos[k] == std::pair<int,int>(-1,-1))
			continue;
		int i, j;
		bool color;
		i = pos[k].first;
		j = pos[k].second;
		color = pieces[k].get_color();
		char mark = pieces[k].get_mark();
		switch(mark)
		{
			case 'p': sprite.setTexture(this->pieces_tex[color][0]); break;
			case 'r': sprite.setTexture(this->pieces_tex[color][1]); break;
			case 'n': sprite.setTexture(this->pieces_tex[color][2]); break;
			case 'b': sprite.setTexture(this->pieces_tex[color][3]); break;
			case 'q': sprite.setTexture(this->pieces_tex[color][4]); break;
			case 'k': sprite.setTexture(this->pieces_tex[color][5]); break;
		}

		sf::Vector2f pos(this->field_size.x * j, this->field_size.y * i);
		sprite.setPosition(this->board_offset + pos + cor);
		this->AppWin.draw(sprite);
	}	
	this->AppWin.display();
	return;
}

void GUI::draw_marker(int y, int x, sf::Color color, bool update)
{

	sf::Vector2f cor(3,3);
	sf::RectangleShape marker(this->field_size - cor);
	sf::Vector2f pos = this->board_offset + sf::Vector2f(x * this->field_size.x, this->field_size.y * y) + cor/float(2.0);

	marker.setPosition(pos);
	marker.setFillColor(sf::Color(0, 0, 0, 0));
	marker.setOutlineColor(color);
	marker.setOutlineThickness(2);
	this->AppWin.draw(marker);
	if(update)
		this->AppWin.display();
}

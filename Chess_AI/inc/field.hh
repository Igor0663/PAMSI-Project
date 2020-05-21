#ifndef FIELD_HH
#define FIELD_HH
#include"pieces.hh"

class field
{
	bool color;
	piece* placed_piece;
	public:
		field(bool color = 0 , piece* placed_piece = nullptr): color(color) , placed_piece(placed_piece){}
	piece* get_piece(){return this->placed_piece;}
	void set_piece(piece* p){this->placed_piece = p;}
	bool get_color(){return this->color;}
};

#endif

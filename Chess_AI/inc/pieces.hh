#ifndef PIECES_HH
#define PIECES_HH
#include<vector>
#include"move.hh"


class piece
{
	protected:
		char mark;
		bool color;
		int NoM; //number of moves
		std::vector<move> allowed_moves;
	public:
		int get_NoM() {return this->NoM; }
		void made_move(){this->NoM++;}
		void undo_move(){this->NoM--;}
		piece(bool color = 0): mark('x'), color(color), NoM(0) {}	
		char get_mark(){return this->mark;}
		bool get_color(){return this->color;}
		const std::vector<move>& get_moves(){return allowed_moves;  }
};

class pawn: public piece
{
	public:
		pawn(bool color);
};

class rook: public piece
{
	public:
		rook(bool color);
};

class knight: public piece
{
	public:
		knight(bool color);
};

class bishop: public piece
{
	public:
		bishop(bool color);
};

class queen: public piece
{
	public:
		queen(bool color);
};

class king: public piece
{
	public:
		king(bool color);
};
#endif

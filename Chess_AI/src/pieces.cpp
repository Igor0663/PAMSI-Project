#include"pieces.hh"
#define white 0
#define black 1

pawn::pawn(bool color): piece(color)
{
	this->mark = 'p'; 
	this->points = 100; 
	int v;
	if(color == white)
		v = -1;
	else
		v = 1;
	this->allowed_moves.push_back(move(0, v, 1, 0, 2));
	this->allowed_moves.push_back(move(-1, v, 1, 0, 1));
	this->allowed_moves.push_back(move(1, v, 1, 0, 1));
	this->allowed_moves.push_back(move(0, 2*v, 1, 1, 2));

}

rook::rook(bool color): piece(color)
{
	this->mark = 'r';
	this->points = 500;
	this->allowed_moves.push_back( move( 0,  1, INF));
	this->allowed_moves.push_back( move( 0, -1, INF));
	this->allowed_moves.push_back( move( 1,  0, INF));
	this->allowed_moves.push_back( move(-1,  0, INF));
}

knight::knight(bool color): piece(color)
{
	this->mark = 'n';
	this->points = 320;
	this->allowed_moves.push_back( move( 1,  2, 1));
	this->allowed_moves.push_back( move( 1, -2, 1));
	this->allowed_moves.push_back( move(-1,  2, 1));
	this->allowed_moves.push_back( move(-1, -2, 1));
	this->allowed_moves.push_back( move( 2,  1, 1));
	this->allowed_moves.push_back( move( 2, -1, 1));
	this->allowed_moves.push_back( move(-2,  1, 1));
	this->allowed_moves.push_back( move(-2, -1, 1));
}

bishop::bishop(bool color): piece(color)
{
	this->mark = 'b';
	this->points = 330;
	this->allowed_moves.push_back( move( 1,  1, INF));
	this->allowed_moves.push_back( move( 1, -1, INF));
	this->allowed_moves.push_back( move(-1,  1, INF));
	this->allowed_moves.push_back( move(-1, -1, INF));
}

queen::queen(bool color): piece(color)
{
	this->mark = 'q';
	this->points = 900;
	this->allowed_moves.push_back( move( 0,  1, INF));
	this->allowed_moves.push_back( move( 0, -1, INF));
	this->allowed_moves.push_back( move( 1,  0, INF));
	this->allowed_moves.push_back( move(-1,  0, INF));
	this->allowed_moves.push_back( move( 1,  1, INF));
	this->allowed_moves.push_back( move( 1, -1, INF));
	this->allowed_moves.push_back( move(-1,  1, INF));
	this->allowed_moves.push_back( move(-1, -1, INF));
}

king::king(bool color): piece(color)
{
	this->mark = 'k';
	this->points = 20000;
	this->allowed_moves.push_back( move( 0,  1, 1));
	this->allowed_moves.push_back( move( 0, -1, 1));
	this->allowed_moves.push_back( move( 1,  0, 1));
	this->allowed_moves.push_back( move(-1,  0, 1));
	this->allowed_moves.push_back( move( 1,  1, 1));
	this->allowed_moves.push_back( move( 1, -1, 1));
	this->allowed_moves.push_back( move(-1,  1, 1));
	this->allowed_moves.push_back( move(-1, -1, 1));
}

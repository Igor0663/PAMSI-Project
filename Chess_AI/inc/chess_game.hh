#ifndef CHESS_GAME_HH
#define CHESS_GAME_HH

#include"chessboard.hh"
#include<vector>
#include<stack>

struct pos_move{
	std::pair<int, int> from;
	std::pair<int, int> to;
	pos_move( std::pair<int, int> a, std::pair<int, int> b): from(a), to(b) {}
};

class chess_game{
		chessboard board;
		std::vector<piece> pieces;

		std::vector<piece*> wpieces;
		std::vector<piece*> bpieces;

		std::vector<piece*> wcaptured;
		std::vector<piece*> bcaptured;

		std::vector< std::vector<pos_move > > available_moves; 

		unsigned int white_score;
		unsigned int black_score;
		std::stack< std::pair< std::vector< pos_move >, int > > history;
		bool whose_turn;
		bool AI;
	public:
		chess_game();
		void display(){this->board.display(); }
		const std::vector< std::vector<pos_move > > & possible_moves(bool color);
		void check_castling(bool color);
		void make_move( std::vector<pos_move>& move);
		void turn();
		piece* get_piece( unsigned int i, unsigned int j);
};


#endif

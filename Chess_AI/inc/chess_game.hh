#ifndef CHESS_GAME_HH
#define CHESS_GAME_HH

#include"chessboard.hh"
#include<vector>
#include<stack>
#define black_won 1
#define white_won 0 
#define game_ongoing -1

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
		std::stack< std::vector< std::pair< pos_move, int> > > history;
		bool whose_turn;
		bool AI;
	public:
		int game_status;
		chess_game();
		void display(){this->board.display(); }
		const std::vector< std::vector<pos_move > > & possible_moves(bool color);
		void check_castling(bool color);
		void check_promotion(bool color);
		void make_move( const std::vector<pos_move>& move);
		void turn();
		piece* get_piece( unsigned int i, unsigned int j);
};


#endif

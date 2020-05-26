#ifndef CHESS_GAME_HH
#define CHESS_GAME_HH

#include"chessboard.hh"
#include"gui.hh"
#include<vector>
#include<stack>
#define black_won 1
#define white_won 0 
#define game_ongoing -1
#define max_depth 4
#define inf 100000

class chess_game{
		chessboard board;
		GUI gui;
		std::vector<piece> pieces;
		std::vector<std::pair<int, int> > pieces_pos;

		std::vector< std::vector<pos_move > > available_moves; 

		std::stack< std::vector< std::pair< pos_move, int> > > history;
		bool whose_turn;
		bool AI;
		int game_status;
		int pos_pts[6][8][8]; //0 - pawn, 1 - rook, 2 - knight, 3 - bishop, 4 - queen, 5 - king
	public:
		chess_game(sf::RenderWindow& win);
		void display(){this->board.display(); }
		const std::vector< std::vector<pos_move > > & possible_moves(bool color);
		void check_castling(bool color);
		void check_promotion(bool color);
		void make_move( const std::vector<pos_move>& move);
		int evaluate_board();
		void undo_move();
		int play();
		piece* get_piece( unsigned int i, unsigned int j);
		int get_game_status()const{return this->game_status;}
		int choose_promotion(bool color);
};


#endif

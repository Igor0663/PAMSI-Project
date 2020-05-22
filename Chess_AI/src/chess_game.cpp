#include"chess_game.hh"
#include<iostream>
#include<cctype>
#define white 0
#define black 1

chess_game::chess_game(): board(chessboard()), white_score(0), black_score(0), whose_turn(0), AI(0) 
{
	this->pieces.reserve(50);
	for(int i = 0;i < 8; i++)
	{
		this->pieces.push_back(pawn(black));
		this->board.add_piece(1, i, &(this->pieces.back()) );
	}
	this->pieces.push_back(rook(black));
	this->pieces.push_back(knight(black));
	this->pieces.push_back(bishop(black));
	this->pieces.push_back(queen(black));
	this->pieces.push_back(king(black));
	this->pieces.push_back(bishop(black));
	this->pieces.push_back(knight(black));
	this->pieces.push_back(rook(black));
	for(int j = 0; j < 8;j++)
		this->board.add_piece(0, j, &(this->pieces[8+j]));


	for(int i = 0;i < 8; i++)
	{
		this->pieces.push_back(pawn(white));
		this->board.add_piece(6, i, &(this->pieces.back()));
	}
	this->pieces.push_back(rook(white));
	this->pieces.push_back(knight(white));
	this->pieces.push_back(bishop(white));
	this->pieces.push_back(queen(white));
	this->pieces.push_back(king(white));
	this->pieces.push_back(bishop(white));
	this->pieces.push_back(knight(white));
	this->pieces.push_back(rook(white));
	for(int j = 0; j < 8;j++)
		this->board.add_piece(7, j, &(this->pieces[24+j]));
}

piece* chess_game::get_piece( unsigned int i, unsigned int j)
{
	return this->board.get_piece(i, j);
}

bool in_range( int what, int min, int max)
{
	if( max < min)
		std::swap( min, max);
	return( what <= max and what >= min);
}

void chess_game::check_castling(bool color)
{
	piece* R = nullptr;
	piece* K = nullptr;
	
	unsigned int row;
	if(color == white)
		row = 7;
	else if(color == black)
		row = 0;
	else
		std::cerr <<"color value is neither black nor white";
	K = this->board.get_piece(row, 4);
	
	if(K and K->get_mark() == 'k' and K->get_NoM() == 0)
	{
		R = this->board.get_piece(row, 0);
		if(R and R->get_color() == K->get_color())
			if(R-> get_mark() == 'r' and R->get_NoM() == 0)
			{
				if( !this->board.get_piece(row, 1) and !this->board.get_piece(row, 2) and !this->board.get_piece(row, 3) )
				{
					//long castling
					pos_move k({row, 4}, {row, 2});
					pos_move r({row, 0}, {row, 3});
					std::vector<pos_move> V = {k, r};
					this->available_moves.push_back(V);
				}
			}
		R = this->board.get_piece(row, 7);
		if(R and R->get_color() == K->get_color())
			if(R-> get_mark() == 'r' and R->get_NoM() == 0)
			{
				if( !this->board.get_piece(row, 6) and !this->board.get_piece(row, 5) )
				{
					//short castling
					pos_move k({row, 4}, {row, 6});
					pos_move r({row, 7}, {row, 5});
					std::vector<pos_move> V = {k, r};
					this->available_moves.push_back(V);
				}
			}
	}
	return;
}

void chess_game::check_promotion(bool color)
{
	int row;
	char marks[] = {'q', 'n', 'b', 'r'};
	std::vector< std::vector<pos_move> > promotions;

	if(color == white)
		row = 0;
	else if(color == black)
		row = 7;
	else
		std::cerr << "Color value is neither black nor white";

	for(int i = 0; i < (int)(this->available_moves.size()); i++)
	{
		auto mov = this->available_moves[i];
		piece* p = this->get_piece(mov[0].from.first, mov[0].from.second);
		if(p->get_mark() == 'p' and mov[0].to.first == row)
		{
			std::swap(this->available_moves[i], this->available_moves.back());
			this->available_moves.pop_back();
			promotions.push_back(mov);
			i--;
		}
	}
	for(unsigned int i = 0; i < promotions.size(); i++)
	{
		promotions[i].push_back({promotions[i][0].to,promotions[i][0].to });
		for(int j = 0; j < 4;j++)
		{
			promotions[i][1].promotion = marks[j];
			this->available_moves.push_back(promotions[i]);
		}
	}
	return;
}

const std::vector< std::vector<pos_move > >& chess_game::possible_moves(bool color)
{
	this->available_moves.clear();
	int next_v, next_h;
	for(int i = 0 ;i < 8; i++)
		for(int j = 0; j < 8;j++)
		{
			piece* p = this->board.get_piece(i, j);
			if(p and p->get_color() == color)
			{
				std::vector<move> m = p->get_moves();
				for(unsigned int k = 0;k < m.size();k++)
				{
					move mov = m[k];
					if( mov.only_first and p->get_NoM() > 0)
						continue;
					for(unsigned int l = 1; l <= mov.max_rep; l++)
					{
						next_v = i + l * mov.v_move;
						next_h = j + l * mov.h_move;
						if( in_range(next_v, 0, 7) and in_range(next_h, 0, 7) )
						{
							piece* n_p = this->board.get_piece(next_v, next_h);
							if(n_p)
							{
								if(n_p->get_color() == p->get_color())
									break;
								if(mov.type != 2)
								{
									pos_move m({i, j}, {next_v, next_h});
									std::vector<pos_move> V = {m};
									this->available_moves.push_back(V);
									break;
								}
							}
							else if( mov.type != 1)
							{
								pos_move m({i, j}, {next_v, next_h});
								std::vector<pos_move> V = {m};
								this->available_moves.push_back(V);
							}
						}
						else
							break;
					}	
				}
			}
		}

	this->check_castling(black);
	this->check_castling(white);
	this->check_promotion(black);
	this->check_promotion(white);
/*	for( int i = 0; i < this->available_moves.size(); i++)
	{
		auto kokos = this->available_moves[i];
		for(int j = 0; j < kokos.size();j++)
			std::cout<< "[(" << kokos[j].from.first << "," << kokos[j].from.second <<"),(" << kokos[j].to.first << "," << kokos[j].to.second <<")] ";
		std::cout << "\n";
	}
*/
	return this->available_moves;
}


void chess_game::make_move( const std::vector<pos_move>& move)
{
	std::vector< std::pair < pos_move, int> > H;
	for(unsigned int i = 0; i < move.size(); i++)
	{
		piece* p = this->get_piece( move[i].to.first, move[i].to.second );
		int ind = -1;
		if(p)
			ind = (p - &(this->pieces[0]));
		this->board.move_piece(move[i], this->pieces);
		H.push_back({move[i], ind});
	}
	this->history.push(H);
	return;
}

bool check_input(std::string S)
{
	if(S.size() != 2)
		return false;
	if(toupper(S[0]) < 'A' or toupper(S[0]) > 'H')
		return false;
	if(S[1] < '1' or S[1] > '8')
		return false;
	return true;
}

void chess_game::turn()
{
	std::string from, to;
	std::pair< int, int> a, b;
	this->possible_moves(this->whose_turn);
	bool good_move = false;
	if(this->whose_turn)
		std::cout << "Blacks' turn\n";
	else
		std::cout << "Whites' turn\n";
	while(!good_move)
	{
		std::cin >> from >> to;
		if( !check_input(from) or !check_input(to) )
		{
			std::cout << "Nie mozna wykonac takiego ruchu, sprobuj ponownie: \n";
			continue;
		}
		a = {  '8' - from[1], toupper(from[0]) -'A'};
		b = {  '8' - to[1], toupper(to[0]) - 'A'};
		for(unsigned int i = 0; i < this->available_moves.size(); i++)
			if(available_moves[i][0].from == a and available_moves[i][0].to == b)
			{
				if(available_moves[i].size() == 2 and available_moves[i][1].from == available_moves[i][1].to)
				{
					//promotion case
					char marks[] = {'q', 'n', 'b', 'r' };
					char input;
					bool check_input = false;
					std::cout << "Promotion available, choose promotion piece( q, n, b, r): ";
					do
					{
						std::cin >> input;
						for(int j = 0; j < 4; j++)
							if(input == marks[j])
								check_input = true;
						if(!check_input)
							std::cout << "Wrong input, try again: ";
					}while(!check_input);
				       	
					for(int j = 0; j < 4; j++)
						if(input == marks[j])
						{
							this->make_move(available_moves[i+j]);
							good_move = true;
							break;
						}
					break;	
				}
				else
				{
					this->make_move(available_moves[i]);
					good_move = true;
					break;
				}
			}
		if(!good_move)
			std::cout << "Nie mozna wykonac takiego ruchu, sprobuj ponownie: \n";
	}
	this->whose_turn = !this->whose_turn;
	return;
}

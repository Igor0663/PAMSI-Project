#include"chess_game.hh"
#include<iostream>
#include<cctype>
#include<algorithm>
#define white 0
#define black 1

chess_game::chess_game(sf::RenderWindow& win): board(chessboard()), gui(win), whose_turn(white), AI(0) 
{
	this->pieces.reserve(50);
	this->game_status = game_ongoing;
	for(int i = 0;i < 8; i++)
	{
		this->pieces.push_back(pawn(black));
		this->board.add_piece(1, i, &(this->pieces.back()) );
		this->pieces_pos.push_back({1,i});
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
	{
		this->board.add_piece(0, j, &(this->pieces[8+j]));
		this->pieces_pos.push_back({0,j});
	}


	for(int i = 0;i < 8; i++)
	{
		this->pieces.push_back(pawn(white));
		this->board.add_piece(6, i, &(this->pieces.back()));
		this->pieces_pos.push_back({6,i});
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
	{
		this->board.add_piece(7, j, &(this->pieces[24+j]));
		this->pieces_pos.push_back({7,j});
	}
	//pawn
	int array_pawn[8][8] = { { 0,  0,  0,  0,  0,  0,  0,  0},
			         {50, 50, 50, 50, 50, 50, 50, 50},
			    	 {10, 10, 20, 30, 30, 20, 10, 10},
 			    	 { 5,  5, 10, 25, 25, 10,  5,  5},
 			    	 { 0,  0,  0, 20, 20,  0,  0,  0},
			    	 { 5, -5,-10,  0,  0,-10, -5,  5},
 			    	 { 5, 10, 10,-20,-20, 10, 10,  5},
 			    	 { 0,  0,  0,  0,  0,  0,  0,  0} };
	for(unsigned int i = 0; i < 8; i++)
		for(unsigned int j = 0; j < 8;j++)
			this->pos_pts[0][i][j] = array_pawn[i][j];
	//rook
	int array_rook[8][8] = { { 0,  0,  0,  0,  0,  0,  0,  0},
			    	 { 5, 10, 10, 10, 10, 10, 10,  5},
			    	 {-5,  0,  0,  0,  0,  0,  0, -5},
 			    	 {-5,  0,  0,  0,  0,  0,  0, -5},
 			    	 {-5,  0,  0,  0,  0,  0,  0, -5},
			    	 {-5,  0,  0,  0,  0,  0,  0, -5},
 			    	 {-5,  0,  0,  0,  0,  0,  0, -5},
 			    	 { 0,  0,  0,  5,  5,  5,  0,  0} };
	for(unsigned int i = 0; i < 8; i++)
		for(unsigned int j = 0; j < 8;j++)
			this->pos_pts[1][i][j] = array_rook[i][j];
	//knight
	int array_knight[8][8] = { {-50,-40,-30,-30,-30,-30,-40,-50},
			     	   {-40,-20,  0,  0,  0,  0,-40,-20},
				   {-30,  0, 10, 15, 15, 10,  0,-30},
 			           {-30,  5, 15, 20, 20, 15,  5,-30},
 			           {-30,  0, 15, 20, 20, 15,  0,-30},
			           {-30,  5, 15, 15, 15, 10,  5,-30},
 			           {-40,-20,  0,  5,  5,  0,-20,-40},
 			           {-50,-40,-30,-30,-30,-30,-40,-50} };
	for(unsigned int i = 0; i < 8; i++)
		for(unsigned int j = 0; j < 8;j++)
			this->pos_pts[2][i][j] = array_knight[i][j];
	//bishop
	int array_bishop[8][8] = { {-20,-10,-10,-10,-10,-10,-10,-20},
			     	   {-10,  0,  0,  0,  0,  0,  0,-10},
			           {-10,  0,  5, 10, 10,  5,  0,-10},
 			           {-10,  5,  5, 10, 10,  5,  5,-10},
 			           {-10,  0, 10, 10, 10, 10,  0,-10},
			           {-10, 10, 10, 10, 10, 10, 10,-10},
 			           {-10,  5,  0,  0,  0,  0,  5,-10},
 			           {-20,-10,-10,-10,-10,-10,-10,-20} };
	for(unsigned int i = 0; i < 8; i++)
		for(unsigned int j = 0; j < 8;j++)
			this->pos_pts[3][i][j] = array_bishop[i][j];
	//queen
	int array_queen[8][8] = { {-20,-10,-10, -5, -5,-10,-10,-20},
			          {-10,  0,  0,  0,  0,  0,  0,-10},
			          {-10,  0,  5,  5,  5,  5,  0,-10},
 			          { -5,  0,  5,  5,  5,  5,  0, -5},
 			          {  0,  0,  5,  5,  5,  5,  0, -5},
			          {-10,  5,  5,  5,  5,  5,  0,-10},
 			          {-10,  0,  5,  0,  0,  0,  0,-10},
 			          {-20,-10,-10, -5, -5,-10,-10, 20} };
	for(unsigned int i = 0; i < 8; i++)
		for(unsigned int j = 0; j < 8;j++)
			this->pos_pts[4][i][j] = array_queen[i][j];
	//king
	int array_king[8][8] = { {-30,-40,-40,-50,-50,-40,-40,-30},
			         {-30,-40,-40,-50,-50,-40,-40,-30},
			         {-30,-40,-40,-50,-50,-40,-40,-30},
 			         {-30,-40,-40,-50,-50,-40,-40,-30},
 			         {-20,-30,-30,-40,-40,-30,-30,-20},
			         {-10,-20,-20,-20,-20,-20,-20,-10},
 			         { 20, 20, -5, -5, -5, -5, 20, 20},
 			         { 20, 20, 50,  0,  0, 10, 60, 20} };
	for(unsigned int i = 0; i < 8; i++)
		for(unsigned int j = 0; j < 8;j++)
			this->pos_pts[5][i][j] = array_king[i][j];
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
	char marks[] = {'q', 'r', 'b', 'n'};
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
	int next_v, next_h, i, j;
	for(unsigned int k = 0; k < this->pieces_pos.size();k++)
	{
		i = this->pieces_pos[k].first;
		j = this->pieces_pos[k].second;
		if( i == -1 and j == -1)
			continue;
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
							if( mov.h_move == 0 and mov.v_move == 2 and this->board.get_piece(i + 1, j ) )
								break;
							if( mov.h_move == 0 and mov.v_move == -2 and this->board.get_piece(i - 1, j ) )
								break;
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

	this->check_castling(color);
	this->check_promotion(color);
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
		{
			ind = (p - &(this->pieces[0]));
			int color = p->get_color();
			if(p->get_mark() == 'k')
				this->game_status = !color;
		}
		this->board.move_piece(move[i], this->pieces, this->pieces_pos);
		H.push_back({move[i], ind});

	}
	this->history.push(H);
	this->whose_turn = !this->whose_turn;
	return;
}


void chess_game::undo_move()
{
	if(this->history.empty())
		return;
	auto last_move = this->history.top();
	this->history.pop();
	for(int  i = (int)(last_move.size()) - 1; i >= 0; i--)
	{
		int ind = last_move[i].second;
		pos_move move = last_move[i].first;
		this->board.undo_move(move, ind, this->pieces, this->pieces_pos);
	}
	this->whose_turn = !this->whose_turn;
	this->game_status = game_ongoing;
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

int chess_game::evaluate_board()
{
	int eval = 0;// + : whites advantage, - : blacks advantage

	for(unsigned int i = 0; i < this->pieces.size(); i++)
	{
		std::pair<int, int> pos = this->pieces_pos[i];
		piece p = this->pieces[i];
		int color = p.get_color();
		int mark = p.get_mark();
		int ind;
		if(pos == std::pair<int, int>(-1, -1))
			continue;
		switch(mark)
		{
			case 'p': ind = 0; break;
			case 'r': ind = 1; break;
			case 'n': ind = 2; break;
			case 'b': ind = 3; break;
			case 'q': ind = 4; break;
			case 'k': ind = 5; break;
			default: std::cerr <<"Unknown piece type.\n";
		}
		if(color == black)
		{
			eval -= pos_pts[ind][7 - pos.second][7-pos.second];
			eval -= p.get_points();
		}
		else
		{
			eval += pos_pts[ind][pos.first][pos.second];
			eval += p.get_points();
		}
	}
	return eval;
}

int minimax(chess_game& game,int alpha, int beta, bool maximizing, int color, int depth)
{
	int result, move = 0;
	if(maximizing)
		result = -inf;
	else
		result = inf;
	int s = game.get_game_status();
	if( depth == max_depth or s != -1 )
		return game.evaluate_board();
	std::vector< std::vector< pos_move > > moves = game.possible_moves(color);
	for(unsigned int i = 0; i < moves.size();i++)
	{
		game.make_move(moves[i]);
		int new_res = minimax(game, alpha, beta, !maximizing, !color, depth + 1);
		if(maximizing)
		{
			if(new_res > result)
			{
				result = new_res;
				move = i;
			}
			alpha = std::max(new_res, alpha);
		}
		else
		{
			if(new_res < result)
			{
				result = new_res;
				move = i;
			}
			beta = std::min(new_res, beta);
		}
		game.undo_move();
		if(beta <= alpha)
			break;
	}
	if(depth == 0)
		return move;
	else
		return result;
}

int chess_game::choose_promotion(bool color)
{
	sf::Vector2f box_size(240, 60);
	sf::RectangleShape Sprite(box_size);
	sf::Vector2f box_offset = (sf::Vector2f(512, 512) - box_size)/(float)(2);
	sf::Vector2f next_figure(60, 0);
	
	Sprite.setPosition(box_offset);
	Sprite.setFillColor(sf::Color(180, 180, 180));
	this->gui.AppWin.draw(Sprite);
	
	sf::Sprite piece;
	int order[4] = { 4, 1, 3, 2};
	for(int i = 0; i < 4;i++)
	{
		piece.setTexture(this->gui.pieces_tex[color][order[i]]);
		piece.setPosition(box_offset + (float)(i) * next_figure);
		this->gui.AppWin.draw(piece);
	}
	this->gui.AppWin.display();
	
	int option = -2;
	while(option == -2)
	{
		sf::Event event;
		while(this->gui.AppWin.pollEvent(event))
		{
			if(event.type == sf::Event::MouseButtonPressed)  
			{
				int x = event.mouseButton.x;
				int y = event.mouseButton.y;
				if(event.mouseButton.button == sf::Mouse::Left)
				{
					if( in_range(y, box_offset.y, box_offset.y + box_size.y) and in_range(x,box_offset.x, box_offset.x + box_size.x) )
						option = (x - box_offset.x)/next_figure.x;
				}
				else if(event.mouseButton.button == sf::Mouse::Right)
					option = -1;
			}
		}
	}
	return option;
}


int chess_game::play()
{
	std::string from, to;
	std::pair< int, int> a ={-1, -1}, b = {-1, -1};

	this->possible_moves(this->whose_turn);
	while(this->gui.AppWin.isOpen())
	{
		if(this->game_status != -1)
		{
			this->gui.AppWin.close();
			return this->game_status;
		}
		if(this->whose_turn)
		{
			int ind = minimax(*this,-inf, inf, false, black, 0);
			this->possible_moves(this->whose_turn);
			this->make_move(this->available_moves[ind]);
		}
		sf::Event event;
		while(this->gui.AppWin.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
                 		this->gui.AppWin.close();
			if(event.type == sf::Event::MouseButtonPressed)
			{
				if(event.mouseButton.button == sf::Mouse::Left)
				{
					int row = (int)((event.mouseButton.y - this->gui.board_offset.y)/this->gui.field_size.y);
					int col = (int)((event.mouseButton.x - this->gui.board_offset.x)/this->gui.field_size.x);
					if( a == std::pair<int, int>(-1, -1))
						a = { row, col };
					else
					{
						b = { row, col };
						this->possible_moves(this->whose_turn);
						for(unsigned int i = 0; i < this->available_moves.size(); i++)
						{
							if(available_moves[i][0].from == a and available_moves[i][0].to == b)
							{
								if(available_moves[i].size() == 2 and available_moves[i][1].from == available_moves[i][1].to)
								{
									int choice = this->choose_promotion(this->whose_turn);
									if( in_range(choice, 0, 3))
										this->make_move(available_moves[i+choice]);
									break;
								}
								this->make_move(available_moves[i]);
								break;
							}
						}
						a = {-1, -1};
						b = {-1, -1};
					}
				}
			}
		}
		this->gui.display(this->board, this->pieces, this->pieces_pos);
	}
	return game_ongoing;
}

